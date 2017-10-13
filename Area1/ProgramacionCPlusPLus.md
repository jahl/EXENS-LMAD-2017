# Área I: Programación #

## Sub-área 1. Programación C++ ##

### Programación de Medio Nivel: ###
**Definición:** Un lenguaje de programación de medio nivel es uno que tiene una sintaxis y capacidades parecidas a las de un lenguaje de alto nivel, como son las clases y otras abstracciones; mientras que sigue manteniendo acceso directo a la comunicación con la máquina, permitiendo escribir partes del código en lenguajes de menor nivel, como *Assembly*.

**Uso:** Su uso común es para *Systems Programming* (Programación de Sistemas), cuya característica principal es hacer uso eficiente de los recursos de la máquina, ya sea porque el rendimiento es crítico (Game engines/Motores gráficos), o las mejoras pequeñas en rendimiento constituyen ganancias monetarias significativas. 

**Características:**
  - Los programas pueden operar en ambientes de pocos recursos.
  - Los programas son eficientes, usualmente con poco tiempo de compilación.
  - Los programas tienen acceso directo a la memoria y al flujo de control/control de flujo del programa. 
  - Los programas pueden tener partes escritas en lenguajes de bajo nivel.

**Conceptos notables:**
  - **Abstracción:** Añadir capas de funcionalidad que esconden partes más complejas del programa, con el fin de hacer un nivel complejidad estándar más sencillo para el programa.
  - **Flujo de control:** El orden en el cuál las instrucciones de un programa son llamadas, ejemplos de declaraciones de control de flujo son *if-else, for, cases, etc*.
 
### Implementación de Algoritmos: ###
**Definición:** Es la realización de un algoritmo en forma de un programa, componente de software, o sistema computacional a través de programación.


### Programación Estructurada: ###
**Definición:** Es un paradigma de programación con el objetivo de mejorar la claridad, calidad y tiempo de desarrolla de un programa computacional. 

**Características:**
  - Hace uso de _subritinas, estructuras de bloque, ciclos `for y while`_.
  - Evita el uso de saltos como `go to`, previniendo código que es difícil de mantener.
 
**Conceptos notables:**
  - **Estructura de control:** Instrucciones que permiten definir el control de flujo de un programa (`if-else, for`, etc).
  
    **Tipos de estructuras:**
    - **Sequencia:** Orden en que las instrucciones de un programa son ejecutadas (escribir una línea después de la otra).
    - **Seleccion:** Una o más instrucciones son ejecutadas dependiendo del estado del programa (`if-else`).
    - **Iteración:** Un bloque de código que es ejecutado hasta que el programa alcanza cierto estado (`while, repeat, for, do`)
    - **Recursión:** Un bloque de código es ejecutado repetidamente al llamarse a si mismo una y otra vez hasta que una condición de terminación es alcanzada.
    
  - **Subrutinas:** Unidades de código que pueden llamarse, como: funciones, procedimientos, metodos (_functions, methods, procedures_) en forma de una sola instrucción.
  - **Bloques:** Encapsulan varías instrucciones para que sean tratadas como una sola (`{}`, `BEGIN..END`).


### Programación Gráfica: ###
**Definición:** Programación gráfica, o _gráficas computacionales_, son un un campo de las ciencias computacionales que estudia los metodos para sintetizar y manipular contenido visual tanto en 2D como 3D. 

**Uso:** Las gráficas computacionales pueden dividirse en distintos campos, tales como:
  - Arte digital.
  - Efectos especiales.
  - Videojuegos.
  - Efectos visuales.
  - Animación.
  - Rendering.

**Conceptos notables:**
  - **Gráficas computacionales/CG:** Imagenes generadas por computadora, usualmente creadas por hardware y software especializado.
  - **Pixel:** Un punto de una imagen rasterizada, colocado en una cuadricula bidimensional. Usualmente contiene tres componentes para definir su color en formato _Red/Green/Blue_
  - **Primitivo:** Unidad básica con la que un sistema gráfico puede crear imagenes o modelos más complicados, ejemplos de esto serían triangulos o poligonos para renderizar una imagen en 3d.
  - **Rendering:** Es la generación de una imagen 2D en base a un modelo 3D.
  - **Ray tracing:** Es una técnica para definir el camino que sigue la luz, u otro objeto a través de los pixeles del plano de una imagen.
  - **Shading:** Es una técnica para crear la ilusión de profundidad en modelos 3D o ilustraciones al variar los niveles de obscuridad a través del uso de pedazos de código llamados _shaders_. 
  - **Texture mapping:** Es un método para añadir detalle o textura a una superficie, envolviendo el modelo o poligono con una imagen 2D.
  - **Multi-texturig:** El uso de más de 1 textura en 1 objeto.
  - **Procedural Texture:** Texturas creadas a base de algoritmos computacionales.
  - **Bitmap Textures:** Texturas creadas a partir de un programa de edición de imagenes, o una cámara digital.
  - **UV Mapping:** Técnica que consiste en definir las coordenadas sobre las que cierto punto de una textura será colocada sobre un objeto 3D. Se usan las letras `U` y `V` debido a que usualmente `X` y `Y` están reservadas para transformaciones.
  
