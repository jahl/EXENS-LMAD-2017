## Sub-área 2. Arte 3D ##

### Modelar, Animar, Texturizar: ###
**Conceptos notables:** 
  - **Modelar:** Para modelar se ocupa un turn-around o referencia para hacer el modelo, deben de estar en diferentes ángulos. Se de tener en cuenta la topología, si van a ser en quads o tris, la cantidad de vértices si debe ser un low-poly. El modelar es crear un objeto tridimensional digitalmente.
  - **Animar:** Para animar, es necesario que el modelo tenga un rig. Para el rigging, el modelo debe tener joints, que son articulaciones para el modelo. Los joints deben tener controladores, que éstos son los que permiten mover a los joints y que el animador pueda hacerle movimientos al modelo. Después viene el skinning, que esto consiste en que una vez que se mueva un controlador el modelo (skin) pueda moverse de la manera deseada.
La animación consiste en poner en la posición deseada al modelo, y crear keyframes. De igual manera que en la animación 2D, se siguen los principios y se puede trabajar en straight ahead o pose to pose, para crear los movimientos del modelo.
  - **Texturizar:** Del modelo se obtienen la UVs, que esto es poner la superficie 3D en una proyección 2D.
  Esto es la base para crear la textura del modelo. Se debe hacer también una prueba de escala con las UVs, usualmente se usa la textura de "checkers" para ver si los cuadros concuerdan, léase: partes pequeñas del modelo se deben de ver con cuadros pequeños. De no ser así, en el mapa de las UVs, esas partes se deben poner más chicas a comparación de las demás.
El mapa de UV tiene todas las caras del modelo, al tenerlas de esta manera, nos permite hacer una imagen en donde se coloque el color porque ya se sabe qué cara o partes del modelo es con las UVs. Una vez teniendo la textura, se crea un material colocando la imagen para el modelo.

