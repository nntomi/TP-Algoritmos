
# Estrategia y Estructuras de Datos utilizadas en el Juego **DoCe**

## Estrategias del Juego

### Estrategia de la IA
Se implementaron distintos niveles de dificultad en la IA los cuales son:
- **Fácil**: La IA selecciona una carta aleatoria de las tres que tiene.
- **Medio**: La IA evita jugadas inefectivas, ya que no usa una carta de "sacar puntos" si el oponente tiene 0 puntos y prioriza cartas que suman puntos si está cerca de ganar (por ejemplo, si tiene 8 o 9 puntos).
- **Difícil**: La IA elige la mejor jugada disponible según el estado actual del juego. Si el jugador está cerca de ganar, prioriza cartas de “repetir turno” o “sacar puntos”. Usa carta espejo en caso de recibir una carta negativa del oponente

---

## Estructuras de Datos

### 1. **Pilas (Stacks)** - `Mazo de cartas`
- **Uso**: Se utilizo esta estructura de datos para mezclar y repartir las cartas de aleatoriamente e ir reponiendo las cartas que falten al jugador y la maquina en cada turno.
- **Justificación**: El uso de una pila puede representar de forma real un juego de cartas porque siempre se agarra una carta desde el tope.

### 2. **Estructuras (Structs)** --`Cartas, informe, jugador y maquina`
- **Uso**: Las cartas, el informe, el jugador y la maquina se modelaron como estructuras para su implementación.
- **Justificación**: Cada dato que tiene que ser representado y usado en el proyecto tiene un conjunto de datos que lo forman por eso es la forma mas adecuada de trabajarlos.
###	3. **Lista Enlazada** --`Archivo del informe`
- **Uso**: En el informe se usa una lista enlazada para tener los datos de cada turno.
- **Justificación**: Debido a que se puede recorrer puedo ir obteniendo los datos de cada jugada para luego crear el archivo de dicho informe.

### 4. **Uso de la API para el JSON** - `Ranking en línea`
-  Se utiliza la biblioteca **libcurl** para una API externa que guarda los rankings de cada jugador que ganó una partida con el uso del **POST** y que luego se pueden obtener esos datos con un **GET** para ver dicho Ranking.



