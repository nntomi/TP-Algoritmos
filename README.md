# Juego de cartas DoCe
## Instrucciones de como jugar al juego
- Al iniciar el juego se abre un menú con diferentes opciones, en los cuales se encuentran las opciones de **jugar, ver ranking y salir**.

## Jugar 

- Para iniciar una partida se debe elegir una dificultad entre las cuales estan **facil, medio y dificil**.
- Una vez iniciada la partida se arranca con un total de **40 cartas** mezcladas aleatoriamente en el cual se irán repartiendo en el transcurso de la partida al jugador y a la maquina (CPU). Cada uno tendrá en su turno 3 cartas para jugar y cada uno de estos deben decidir cual es la mejor jugada para ganar. Una vez gastada una carta se repone y en caso de que no hayan mas cartas se mezclan nuevamente para seguir reponiendo.
- La condición para jugar es el que llegue primero a 12 puntos, una vez alcanzado ese puntaje por alguno de los dos se dará por finalizada la partida. En caso de que sea el jugador quien gane este tendrá su informe y se subirá a un ranking para ver todos los puntajes de anteriores juegos.
## Cartas 
- El juego consta de 40 cartas de juego y cada una tiene su propio efecto.
 - Efectos:
	 - **MAS_UNO:** El que juegue esta carta se le sumara un punto y hay disponible 6 cartas de este tipo.
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
## Aclaraciones
- La tabla de puntajes que aparece en la consola corresponde al inicio del turno, es decir, antes de que el jugador juegue una carta. Sin embargo, a la hora de que la maquina haga su movimiento, lo hace en base al puntaje parcial que se obtiene luego de la acción del jugador.
- La carta espejo puede ser aplicada una sola vez por turno. Por lo tanto, no puede aplicarse una carta espejo a otra carta espejo aplicada previamente. Si esto sucede, es una decisión poco productiva por parte del jugador o de la máquina, y no sumará ni restará puntos.
- Cuando alguien juega una carta negativa el puntaje no se ve actualizado hasta la siguiente ronda, hasta que el jugador o la maquina decida o no usar la carta espejo. Es decir, si la máquina juega una carta que reste puntos, el jugador en la siguiente ronda puede usar o no la carta espejo, en caso de que no lo haga en la posterior ronda a esa se aplicaran los efectos.
## Requisitos
Este proyecto funciona con curl, si no lo tiene, seguir estas instrucciones, en caso de ejecutarlo utilizando el IDE Codeblocks:

- Descargar curl desde: https://curl.se/windows (En caso de no usar Windows, https://curl.se/download.html).
- Descomprimir el zip y pasar esa carpeta a una ubicación segura.
- Agregar dentro de PATH (como variable de entorno) la ubicación a la carpeta “bin”.
- En Codeblocks: Settings > Compiler > Linker Settings: agregar ubicación a “lib\libcurl.dll.a”.
- En Codeblocks: Settings > Compiler > Search directories > Compiler y Resource compiler: agregar ubicación a “include”.
- En Codeblocks: Settings > Compiler > Search directories > Linker: agregar ubicación a “lib”.
