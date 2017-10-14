## Sub-área 2. Programación Web ##

### Programación Web: ###
**Definición:** Se refiere al desarrollo de páginas y aplicaciones para una red publica (internet), o una red privada (intranet).

**Conceptos notables:**
  - **URL:** _Uniform Resource Locators_. Se le llama así a la secuencia de caracteres que sigue un estándar y que permite denominar recursos dentro del entorno de Internet para que puedan ser localizados.
  - **HTTP:** _Hypertext Transfer Protocol_. Protocolo de transferencia donde se utiliza un sistema mediante el cual se permite la transferencia de información entre diferentes servicios y los clientes que utilizan páginas web.
  - **HTTPS:** _HTTP Secure_. Protocolo de comunicación segura sobre la red.
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
      
      - **Global:** Todos los elementos en la página serán afectados por el estilo.
      
      Ejemplo 
      ```CSS
      * { //El selector global es definido por un '*'
        ...
      }
      ```
      
      - **Etiqueta:**  La regla relacionada a este selector será aplicada a todos los elementos de esta etiqueta.
      
      Ejemplo 
      ```CSS
      p { //Todos los <p> tendrán ese estilo
        ...
      }
      ```
      
      - **ID:** El ID de un elemento es un atributo único, por lo que podemos usarlo para aplicar una regla a exclusivamente ese elemento.
      
      Ejemplo 
      ```CSS
      #id { //Solo el elemento con el id "id" tendrá ese estilo
        ...
      }
      ```
      - **Clase:** La Clase de un elemento es un atributo que puede compartir con otros elementos, por lo que podemos usarlo para aplicar una regla a un grupo de elementos.
      
      Ejemplo 
      ```CSS
      .clase { //Solo los elementos con la clase "clase" tendrán ese estilo, sin importar que etiqueta sean
        ...
      }
      ```
      
       - **Atributo:** Cuando queremos seleccionar a todos los elementos que tengan un atributo en especifico.
      
      Ejemplo 
      ```CSS
      [atributo=valor] { //Solo los elementos con el atributo y el valor definido serán afectados la regla.
        ...
      }
      ```
      
      - **Padre:** Cuando queremos seleccionar a todos los elementos que tengan un elemento especifico como padre.
      
      Ejemplo 
      ```CSS
      div > p { //Solo los <p> que sean hijos directos de un <div>.
        ...
      }
      ```
      
      - **Pseudo-selector:** Selectores que se combinan con otros para situaciones especificas.
      
      Ejemplo 
      ```CSS
      a:active { //Solo los elementos <a> que estén con el cursor encima.
        ...
      }
      p:first-child { //Solo los elementos <p> que sean el primer hijo de su padre.
        ...
      }
      ```
  - **JavaScript:** Es un lenguaje de programación usado para dar funcionalidad a los documentos de HTML.
  - **JQuery:** Una librería de JavaScript diseñada para simplificar el escribir scripts para la interacción con el cliente.
  - **AJAX:** _Asynchronus JavaScript and XML_, una tecnología web que permite crear aplicaciones asincronas de Javascript, dando la capacidad de realizar peticiones al servidor sin intervenir con el comportamiento de la página.
  - **XML:** _Extensible Markup Language_, es un lenguaje de marcado que define una serie de reglas utilizadas para codificar documentos. Usado en programación web para transferir información.
  - **JSON:** _JavaScript Object Notation_, es un formato de archivo que es usado para definir una estructura de objetos con atributo-valor. Es usado como el formato común de información durante comunicación asíncrona entre el navegador y el servidor.
    
    Ejemplo
    ```JSON
      {
        "firstName": "John",
        "lastName": "Smith",
        "isAlive": true,
        "age": 25,
        "address": {
          "streetAddress": "21 2nd Street",
          "city": "New York",
          "state": "NY",
          "postalCode": "10021-3100"
        },
        "children": [],
        "spouse": null
      }
    ```
  - **Verbos HTTP:** 
    - **POST:(CREATE)** Crea una petición para enviar información al servidor, usado para crear nuevos elementos.
    - **GET:(READ)** Crea una petición solicitando una representación del recurso especificado. Las peticiones `GET` son para obtener información.
    - **PUT:(UPDATE)** Crea una petición para reemplazar información en el servidor, usado para actualizar elementos.
    - **DELETE:(DELETE)** Crea una petición para eliminar información en el servidor, usado para eliminar elementos.
  - **UI:** _User Interface_, termino usado para referirse al espacio en el que ocurren las interacciones entre el usuario y la máquina. En diseño web, se refiere al diseño visual que tiene la aplicación.
  - **UX:** _User Experience_, se refiere a la experiencia del usuario al usar la aplicación, esto no solo se refiere al aspecto visual, si no a la responsividad de la aplicación, manejo de errores, la facilidad y comodidad con la que un usuario puede utilizar la página web.
  
**Recursos Externos:**

- [Lista de Selectores de CSS - Sitio Web.](https://www.w3schools.com/cssref/css_selectors.asp)
