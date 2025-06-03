# Instrucciones de como jugar al juego
- Al iniciar el juego se abre un menú con diferentes opciones, en los cuales se encuentran las opciones de **jugar, ver ranking y salir**.

## Jugar 

- Para iniciar una partida se debe elegir una dificultad entre las cuales estan **facil, medio y dificil**.
- Una vez iniciada la partida se arranca con un total de **40 cartas** mezcladas aleatoriamente en el cual se irán repartiendo en el transcurso de la partida al jugador y a la maquina (CPU). Cada uno tendrá en su turno 3 cartas para jugar y cada uno de estos deben decidir cual es la mejor jugada para ganar. Una vez gastada una carta se repone y en caso de que no hayan mas cartas se mezclan nuevamente para seguir reponiendo.
- La condición para jugar es el que llegue primero a 12 puntos, una vez alcanzado ese puntaje por alguno de los dos se dará por finalizada la partida. En caso de que sea el jugador quien gane este tendrá su informe y se subirá a un ranking para ver todos los puntajes de anteriores juegos.
## Cartas 
- El juego consta de 40 cartas de juego y cada una tiene su propio efecto.
 - Efectos:
	 - MAS_UNO: El que juegue esta carta se le sumara un punto y hay disponible 6 cartas de este tipo.
	 - **MAS_DOS:** El que juegue esta carta se le sumara dos puntos y hay disponible 10 cartas.
	 - **MENOS_UNO:** Se le resta un punto al contrincante y hay disponible 8 cartas.
	 - **MENOS_DOS:** Se le resta dos puntos al contrincante y hay disponible 6 cartas.
	 - **REPETIR:** Te permite repetir el turno inmediatamente y hay disponible 6 cartas.
	 - **ESPEJO:** Se anula un efecto negativo recibido anteriormente y se devuelve en el siguiente turno, y hay disponible 4 cartas.

## Ranking 
- Es una sección donde se puede ver los mejores puntajes y cantidad de partidas ganadas de cada jugador.
- Una vez finalizada una partida y en caso de que el jugador gane este almacenara su cantidad de partidas ganadas en el ranking.

## Configuraciones del juego
- En caso de querer modificar algún parámetro del juego en el código hay una función llamada **aplicarEfecto**, en el cual si quieres modificar la cantidad de puntos que se suman o se restan al usar alguna carta podes hacerlo. También, se encuentran las de dificultades que están programadas con cierta lógica para que la maquina actué de tal forma en determinada situación.
