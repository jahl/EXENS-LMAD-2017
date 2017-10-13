## Sub-área 1. Programación C++ ##

### Implementación de Algoritmos: ###
**Definición:** Es la realización de un algoritmo en forma de un programa, componente de software, o sistema computacional a través de programación.

**Conceptos notables:**
  - **Complejidad:** La complejidad de un algoritmo está determinado por la cantidad máxima de tiempo en la que un algoritmo podría tomar para una entrada de tamaño "n".
  
  Ejemplo:
  
  **Complejidad O(n):**
  Imaginemos que tenemos un arreglo de tamaño "n", el cual recorreremos con un ciclo for:
 ```javascript
  for(var i = 0; i < n; i++) {
      console.log(arr[i]);
  }
  ```
  Este algoritmo tiene una complejidad de O(n), ya que el tiempo de ejecución aumentará de manera líneal a la cantidad de elementos que el arreglo tenga.
  
  **Complejidad O(n2):**
  Imaginemos que tenemos una matriz de tamaño "NxN", la cual recorreremos con un ciclo for:
 ```javascript
  for(var i = 0; i < n; i++) {
    for(var j = 0; j <n; i++) {
      console.log(mat[i][j]);
     }
  }
  ```
  Este algoritmo tiene una complejidad de O(n2), ya que el tiempo de ejecución aumentará al cuadrado en base a la cantidad de elementos en la matriz.
  
  _Mientras más for's adentro de for's tengamos, el exponente de la complejidad irá subiendo._
  
  
  
  
