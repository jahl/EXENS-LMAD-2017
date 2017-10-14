#ifndef _MSky_
#define _MSky_

class MSky
{
public:
	//Buffers y shaders que manejaran el uso de los shaders.
	ID3D11Buffer* VertexBuffer;
	ID3D11Buffer* IndexBuffer;
	ID3D11VertexShader* VS;
	ID3D11PixelShader* PS;
	ID3D10Blob* VS_Buffer;
	ID3D10Blob* PS_Buffer;
	ID3D11InputLayout* vertLayout;
	ID3D11Buffer* cbBuffer;
	ID3D11Buffer* cbBufferPS;

	//Mantiene la informacion del programa y del contexto a usar, ya que nos daran las funciones necesarias para crear el objeto del Skydome
	ID3D11Device* d3d11Device;
	ID3D11DeviceContext* d3d11DevCon;

	//Recursos que nos ayudan al manejo de la textura.
	ID3D11ShaderResourceView* Texture;
	ID3D11SamplerState* TextSamplerState;
	LPCWSTR text;
	ID3D11RasterizerState* noCull;

	//Matrices que nos representaran en donde se encuentra el objeto dentro de nuesto mundo.
	D3DXMATRIX World;
	D3DXMATRIX Temp;
	D3DXMATRIX rot;
	D3DXMATRIX trans;
	D3DXMATRIX scale;
	float yawPerFrame; //Rotación por frame

	//Componentes comunes de una esfera, nos determinara que tan "definida" queremos que se dibuje
	int Slices;
	int Stacks;
	float Radius;	

	//Esta variable nos dira cuantos vertices estamos usando en un quad,  que normalmente siempre son 6
	int numVertInTwoTriangleFaces;

	//Variable que nos servira de comunicacion con el shader, a traves de esta, le mandaremos los datos de nuestro objeto
	struct ConstantBuffer
	{
		D3DXMATRIX WorldViewProjection;
		D3DXMATRIX World;
		D3DXVECTOR3 CameraPos;
		float padding;
	} consBuff;
	
	//Igual que el anterior, pero esta se encargara especificamente del manejo de la luz.
	struct ConstantBufferPS
	{
		Light  light;
	} consBuffPS;


	//Estructura de un simple vertice, que contiene la 
	//Posicion del vertice (x, y, z)			En que parte del mundo esta el vertice
	//Posicion de la textura (u, v)				Que coordenadas de la textura tomaremos 
	//Direccion de la normal (nx,ny,nz) 		Es la direccion de que tanto pega la luz en ese vertice
	struct SimpleVertex
	{
		D3DXVECTOR3 pos;
		D3DXVECTOR2 tex;
		D3DXVECTOR3 normal;		
	};


	MSky(ID3D11Device *d3d11Device, ID3D11DeviceContext* d3d11DevCon, int Slices, int Stacks, float Radius, LPCWSTR text)
	{
		D3DXMatrixIdentity(&World);

		this->d3d11Device = d3d11Device;
		this->d3d11DevCon = d3d11DevCon;

		this->Slices = Slices;
		this->Stacks = Stacks;
		this->Radius = Radius;
		this->text = text;
		numVertInTwoTriangleFaces = 6;
		yawPerFrame = 0; //inicializamos rotación
		InitScene();

		//Esto indica el como vamos a dibujar nuestro objeto
		//En este caso D3D11_FILL_SOLID hara que cuando se dibuje el objeto, no haya huecos dentro del dibujo.
		//D3D11_CULL_BACK : le estamos diciendo que cuando dibuje un plano, no lo haga por la parte de enfrente del objeto, si no que dibuje lo de adentro.
		D3D11_RASTERIZER_DESC rastDesc;
		ZeroMemory(&rastDesc, sizeof(D3D11_RASTERIZER_DESC));
		rastDesc.FillMode = D3D11_FILL_SOLID;
		rastDesc.CullMode = D3D11_CULL_BACK;

		d3d11Device->CreateRasterizerState(&rastDesc, &noCull);

	}

	bool InitScene()
	{
		//Declaramos nuestro vertice que estaremos usando dentro del programa, ya que este mantendra toda la informacion que usara para dibujar.
		D3D11_INPUT_ELEMENT_DESC layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXTCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 20, D3D11_INPUT_PER_VERTEX_DATA, 0 }		
		};

		//Indicamos el tamaño de nuestro vertice
		UINT numElements = ARRAYSIZE(layout);

		//Compilamos los shaders
		HRESULT result;
		ID3D10Blob* errorMessage;
		errorMessage = 0;

		//Compilamos nuestro Shader e inicializamos nuestro buffer
		
		D3DX11CompileFromFile(L"vertexSky.vs", 0, 0, "VS", "vs_4_0", 0, 0, 0, &VS_Buffer, &errorMessage, 0);
		D3DX11CompileFromFile(L"pixelSky.ps", 0, 0, "PS", "ps_4_0", 0, 0, 0, &PS_Buffer, &errorMessage, 0);
		
		//Creamos los objetos del shader
		d3d11Device->CreateVertexShader(VS_Buffer->GetBufferPointer(), VS_Buffer->GetBufferSize(), NULL, &VS);
		d3d11Device->CreatePixelShader(PS_Buffer->GetBufferPointer(), PS_Buffer->GetBufferSize(), NULL, &PS);

		d3d11DevCon->VSSetShader(VS, 0, 0);
		d3d11DevCon->PSSetShader(PS, 0, 0);

		int index = 0;
		//sin() y cos() son funciones que trabajan en radianes asi que converitremos el valor que deseemos.
		const float phix = D3DX_PI * 2.0;
		const float thetax = D3DX_PI;

		
		SimpleVertex *vertex = new SimpleVertex[Slices * Stacks];

		for(int i = 0; i < Stacks; i++)
		{
			float y = (float) i/(Stacks-1);
			for(int j = 0; j < Slices; j++)
			{
				float x = (float) j/(Slices-1);

				//Lo que hacemos aqui es obtener las coordenadas de una esfera
				vertex[index].pos.x = Radius * sin(y*thetax) * cos(x*phix);
				vertex[index].pos.z = Radius * sin(y*thetax) * sin(x*phix);
				vertex[index].pos.y = Radius * cos(y*thetax);

				//Asignamos las texturas de manera proporcional al eje u tanto al eje v.
				vertex[index].tex = D3DXVECTOR2((float)j / (Slices - 1), (float)i / (Stacks - 1));

				float lenght = sqrt(pow(vertex[index].pos.x, 2) + pow(vertex[index].pos.y, 2) + pow(vertex[index].pos.z, 2));
				lenght=-lenght;
				vertex[index].normal = D3DXVECTOR3(vertex[index].pos.x / lenght, vertex[index].pos.y / lenght, vertex[index].pos.z / lenght);
					index++;
			}
		}

		//Inicializamos nuestro buffer de los vertices
		D3D11_BUFFER_DESC vertexBufferDesc;
		ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));

		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexBufferDesc.ByteWidth = sizeof(SimpleVertex)* (Slices * Stacks);
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.CPUAccessFlags = 0;
		vertexBufferDesc.MiscFlags = 0;

		D3D11_SUBRESOURCE_DATA vertexBufferData;

		ZeroMemory(&vertexBufferData, sizeof(vertexBufferData));
		vertexBufferData.pSysMem = vertex;
		d3d11Device->CreateBuffer(&vertexBufferDesc, &vertexBufferData, &VertexBuffer);

		//Creamos nuestra pantalla
		d3d11Device->CreateInputLayout(layout, numElements, VS_Buffer->GetBufferPointer(),
			VS_Buffer->GetBufferSize(), &vertLayout);

		//Pondremos nuestra pantalla que dibujará
		d3d11DevCon->IASetInputLayout(vertLayout);

		//Iniciamos la tipologia del objeto
		d3d11DevCon->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		DWORD *indices = new DWORD[Slices * Stacks * numVertInTwoTriangleFaces];
		index = 0;


		//Iniciamos los indices los cuales nos indicarán que indices forman un triangulo para dibujarlo.  Ya que nuestro sistema
		//dibuja por triangulos. Este metodo es mas eficiente para el sistema al momento de dibujar.
		for(int i=0; i < Stacks - 1; i++)
		{
			for(int j=0; j < Slices - 1; j++)
			{
				int index1 = (Slices *   i)   +   j; 
				int index2 = (Slices *   i)   + (j+1);
				int index3 = (Slices * (i+1)) +   j;
				int index4 = (Slices * (i+1)) + (j+1);

				indices[index++] = index1; //314
				indices[index++] = index3;
				indices[index++] = index4;

				indices[index++] = index1; //124
				indices[index++] = index4;
				indices[index++] = index2;
			}
		}

		//Añadimos nuestra textura a su buffer.
		D3DX11CreateShaderResourceViewFromFile(d3d11Device, text, NULL, NULL, &Texture, NULL);
		
		//Inicializamos nuestro buffer de los indices.
		D3D11_BUFFER_DESC indexBufferDesc;
		ZeroMemory(&indexBufferDesc, 
			sizeof(indexBufferDesc));

		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDesc.ByteWidth = sizeof(DWORD)* (Slices * Stacks) * numVertInTwoTriangleFaces;
		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.CPUAccessFlags = 0;
		indexBufferDesc.MiscFlags = 0;

		D3D11_SUBRESOURCE_DATA iinitData;
			
		iinitData.pSysMem = indices;
		d3d11Device->CreateBuffer(&indexBufferDesc, 
			&iinitData, 
			&IndexBuffer);		

		//Iniciamos la muestra de la textura el cual nos dira como manejaremos las texturas
		D3D11_SAMPLER_DESC sampDesc;
		ZeroMemory(&sampDesc, sizeof(sampDesc));
		sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		sampDesc.MinLOD = 0;
		sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

		d3d11Device->CreateSamplerState(&sampDesc, &TextSamplerState);

		//Iniciamos nuestros buffers de la conexion al shader

		D3D11_BUFFER_DESC cbbd;
		ZeroMemory(&cbbd, sizeof(D3D11_BUFFER_DESC));

		cbbd.Usage = D3D11_USAGE_DEFAULT;
		cbbd.ByteWidth = sizeof(ConstantBuffer);
		cbbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cbbd.CPUAccessFlags = 0;
		cbbd.MiscFlags = 0;

		d3d11Device->CreateBuffer(&cbbd, NULL, 
			&cbBuffer);

		D3D11_BUFFER_DESC cbbdps;
		ZeroMemory(&cbbdps, sizeof(D3D11_BUFFER_DESC));

		cbbdps.Usage = D3D11_USAGE_DEFAULT;
		cbbdps.ByteWidth = sizeof(ConstantBufferPS);
		cbbdps.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cbbdps.CPUAccessFlags = 0;
		cbbdps.MiscFlags = 0;

		d3d11Device->CreateBuffer(&cbbdps, NULL,
			&cbBufferPS);

		return true;
	}

	
	//aqui esta el update que se usa para updatear el cubo
	void UpdateScene(D3DXMATRIX World)
	{
		this->World = Temp; //Multiplicamos las matrices para la transformación
		D3DXMatrixIdentity(&Temp);
	}

	void DrawScene(D3DXMATRIX View, D3DXMATRIX Projection)
	{
		UINT stride = sizeof(SimpleVertex);
		UINT offset = 0;
		//Colocamos el buffer de indices
		d3d11DevCon->IASetIndexBuffer(IndexBuffer, DXGI_FORMAT_R32_UINT, 0);
		//Colocamos el buffer de vertices
		d3d11DevCon->IASetVertexBuffers(0, 1, &VertexBuffer, &stride, &offset);

		//Seteamos el pixel y vertex shader
		d3d11DevCon->VSSetShader(VS, 0, 0);
		d3d11DevCon->PSSetShader(PS, 0, 0);

		//Iniciamos nuestros componentes del shader
		consBuff.WorldViewProjection = World * View * Projection;
		consBuff.World = World;

		//Lo pasamos a nuestra variables de comunicacion al shader
		D3DXMatrixTranspose(&consBuff.WorldViewProjection, &consBuff.WorldViewProjection);
		D3DXMatrixTranspose(&consBuff.World, &consBuff.World);
		d3d11DevCon->UpdateSubresource(cbBuffer, 0, NULL, &consBuff, 0, 0);
		d3d11DevCon->VSSetConstantBuffers(0, 1, &cbBuffer);

		d3d11DevCon->PSSetShaderResources(0, 1, &Texture);
		
		d3d11DevCon->PSSetSamplers(0, 1, &TextSamplerState);		

		d3d11DevCon->UpdateSubresource(cbBufferPS, 0, NULL, &consBuffPS, 0, 0);
		d3d11DevCon->PSSetConstantBuffers(0, 1, &cbBufferPS);
		
		//La manera en com lo dibujaremos
		D3D11_RASTERIZER_DESC rastDesc2;
		ZeroMemory(&rastDesc2, sizeof(D3D11_RASTERIZER_DESC));
		rastDesc2.FillMode = D3D11_FILL_SOLID;
		rastDesc2.CullMode = D3D11_CULL_NONE;

		//Dibujamos nuestro modelo
		d3d11Device->CreateRasterizerState(&rastDesc2, &noCull);
		d3d11DevCon->RSSetState(noCull);
		d3d11DevCon->DrawIndexed((Slices * Stacks * numVertInTwoTriangleFaces), 0, 0);
	}
	//Funciones de transformación
	void Translate(float x, float y, float z)
	{
		D3DXMatrixTranslation(&trans, x, y, z);
		Temp = Temp * trans;
	}

	void Rotate(float pitch, float yaw, float roll)
	{
		D3DXMatrixRotationYawPitchRoll(&rot, D3DXToRadian(yaw), D3DXToRadian(pitch), D3DXToRadian(roll));
		Temp = Temp * rot;
	}

	void Scale(float sx, float sy, float sz)
	{
		D3DXMatrixScaling(&scale, sx, sy, sz);
		Temp = Temp * scale;
	}
};

#endif
