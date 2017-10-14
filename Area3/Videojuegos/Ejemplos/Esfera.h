void Esfera(Slices, Staks, Radio) {
  int index = 0;
	const float phix = D3DX_PI * 2.0;
	const float thetax = D3DX_PI;
  SimpleVertex *vertex = new SimpleVertex[Slices * Stacks];

	for (int i = 0; i < Stacks; i++) {
	  float y = (float)i / (Stacks - 1);
		for (int j = 0; j < Slices; j++) {
		  float x = (float)j / (Slices - 1);
	    vertex[index].pos.x = Radio * sin(y*thetax) * cos(x*phix);
			vertex[index].pos.z = Radio * sin(y*thetax) * sin(x*phix);
			vertex[index].pos.y = Radio * cos(y*thetax);
			index++;
	  }
	}
}
