### Programación grafica en web: ###

- **OPENGL ES:** variante simplificada de la API gráfica OpenGL diseñada para dispositivos integrados tales como teléfonos móviles, PDAs y
consolas de videojuegos. API para gráficos oficial en Symbian OS3 y la plataforma para dispositivos móviles Android.
- **WebGL:** especificación estándar que está siendo desarrollada actualmente para mostrar gráficos en 3D en navegadores web. especificación estándar que está siendo desarrollada actualmente para mostrar gráficos en 3D en navegadores web. 
Carece de las rutinas matemáticas de vectores y matrices eliminadas en OpenGL 3.0. Esta funcionalidad debe ser proporcionada por el usuario en el espacio de código JavaScript.
    - **Canvas:** Región dónde es posible dibujar. Elemento HTML incorporado en HTML5 que permite la generación de gráficos dinámicamente por medio del scripting. Permite generar gráficos estáticos y animaciones en 2D y 3D. 
    - **Librerías de apoyo:** 
      - **GlMatrix:** Librería externa que permite trabajar con las operaciones de matriz y vectores para WebGL (OpenGL ES).
      - **Three.js:** Librería para simplificar el uso de WebGL y además ayuda en la creación de complejas animaciones 3D.
      
- **Ejemplos:** 
    - **Preparación del renderizado 3D:**
    
        Creación del canvas
      ```HTML
       <body onload="start()">
         <canvas id="glcanvas" width="640" height="480">
             Tu navegador parece no soportar el elemento Canvas.
         </canvas>
       </body 
      ```
        Preparación del contexto
      ```javaScript
        var gl; // Una variable global para el contexto WebGL
        function start() {
          var canvas = document.getElementById("glcanvas");

          gl = initWebGL(canvas);      // Inicializar el contexto GL
  
          // Solo continuar si WebGL esta disponible y trabajando
          if (gl) {
              gl.clearColor(0.0, 0.0, 0.0, 1.0);                      // Establecer el color base en negro, totalmente opaco
              gl.enable(gl.DEPTH_TEST);                               // Habilitar prueba de profundidad
              gl.depthFunc(gl.LEQUAL);                                // Objetos cercanos opacan objetos lejanos
              gl.clear(gl.COLOR_BUFFER_BIT|gl.DEPTH_BUFFER_BIT);      // Limpiar el buffer de color asi como el de profundidad
          }
        }
      ```
