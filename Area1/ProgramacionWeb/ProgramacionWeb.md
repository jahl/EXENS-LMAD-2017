## Sub-área 2. Programación Web ##

### Programación Web: ###
**Definición:** Se refiere al desarrollo de páginas y aplicaciones para una red publica (internet), o una red privada (intranet).

**Conceptos notables:**
  - **URL:** _Uniform Resourse Locators_. Se le llama así a la secuencia de caracteres que sigue un estándar y que permite denominar recursos dentro del entorno de Internet para que puedan ser localizados.
  - **HTTP:** _Hypertext Transfer Protocol_. Protocolo de transferencia donde se utiliza un sistema mediante el cual se permite la transferencia de información entre diferentes servicios y los clientes que utilizan páginas web.
  - **Servidor Web o Servidor HTTP:** Programa informático que procesa una aplicación del lado del servidor, realizando conexiones bidireccionales o unidireccionales y síncronas o asíncronas con el cliente y generando o cediendo una respuesta en cualquier lenguaje o Aplicación del lado del cliente. 
  - **Cliente:** Aplicación informática u ordenador que consume un servicio remoto en otro ordenador conocido como servidor, normalmente a través de una red de telecomunicaciones. También se puede definir un cliente es cualquier cosa (que no sea un servidor) que se conecta a un servidor.
  - **HTML:** _Hypertext Markup Language_, es el lenguaje de marcado estándar para definir la estructura semántica de páginas y aplicaciones web, en otras palabras, define qué elementos estarán en la página, y cuál será la relación entre los mismos. 
    **Markup:**
    - **Etiquetas:** Conocidas como _elements_, usualmente consisten de una etiqueta de apertura y otra de cierre, y sirven para definir un elemento de HTML en la página.
    
      Ejemplo:  
      ```HTML
      <p>Soy un parrafo!</p>
      ```
      
    - **Atributos:** La mayoría de las etiquetas de HTML pueden contener atributos dentro de ellas, las cuales definen caracteristicas de las mismas.
    
      Ejemplo:  
      ```HTML
      <p style="color:red">Soy un parrafo rojo!</p>
      ```
      
  - **CSS:** _Cascading Style Sheets_, es un lenguaje de estilo para definir la presentación de un documento de HTML, en otras palabras, define el aspecto que tendrán los elementos de HTML en la página.
    **CSS**
    - **Regla:** Una regla en CSS es un bloque de código que ayuda a definir un conjunto de atributos visuales para un elemento de HTML.
    
      Ejemplo:  
      ``` CSS
      p {  //La regla de estilo comienza por un selector
        color: red;   //Después, dentro de llaves se coloca 1 o más atributos en el formato ATRIBUTO:VALOR;
        font-size: 12px;
      }
      ```
      
    - **Selector:** Un identificador que CSS usa para saber a cual elemento(s) aplicar las reglas de estilo definidas.
      
      **Selectores**
      
      - *Global:* Todos los elementos en la página serán afectados por el estilo.
      
      Ejemplo 
      ```CSS
      * { //El selector global es definido por un '*'
        ...
      }
      ```
      
      - *Etiqueta:*  La regla relacionada a este selector será aplicada a todos los elementos de esta etiqueta.
      
      Ejemplo 
      ```CSS
      p { //Todos los <p> tendrán ese estilo
        ...
      }
      ```
      
      - *ID:* El ID de un elemento es un atributo único, por lo que podemos usarlo para aplicar una regla a exclusivamente ese elemento.
      
      Ejemplo 
      ```CSS
      #id { //Solo el elemento con el id "id" tendrá ese estilo
        ...
      }
      ```
      - *Clase:* La Clase de un elemento es un atributo que puede compartir con otros elementos, por lo que podemos usarlo para aplicar una regla a un grupo de elementos.
      
      Ejemplo 
      ```CSS
      .clase { //Solo los elementos con la clase "clase" tendrán ese estilo, sin importar que etiqueta sean
        ...
      }
      ```
      
       - *Atributo:* Cuando queremos seleccionar a todos los elementos que tengan un atributo en especifico.
      
      Ejemplo 
      ```CSS
      [atributo=valor] { //Solo los elementos con el atributo y el valor definido serán afectados la regla.
        ...
      }
      ```
      
      
