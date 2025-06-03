# Hola # 


PRUEBAS

1) dificultad media: jugador = 0 puntos, 
resultado esperado: la maquina NO JUEGA cartas de restar puntos
2) Dificultad media: maquina = 8 puntos, resultado esperado: se suma puntos
3) Dificultad dificiL: jugador = 10 puntos, maquina usa repetir turno o sacar puntos 
4) Dificultad dificil: jugador usa carta negativa, maquina usa espejo (si la tiene)
5) Dificultad dificil: maquina, si tiene mas de una carta buena, prefiere repetir turno
6) ~~ dificultad facil: jugador 0 puntos, maquina juega restar puntos  ~~
7) dificultad facil: maquina = 8 puntos, resta puntos al jugador
8) dificultad facil: jugador usa carta mas_1 o mas_2, maquina usa carta espejo
9) ver rankings al iniciar el juego por primera vez --> []
10) ver rankings despues de que jueguen dos jugadores --> ganadores y el acumulado de victorias

| Descripción | Salida esperada | Salida obtenida |
| -           | -               | -               | 
|Se quiere comprobar que en la dificultad facil la maquina no distingue que cartas usar sin importar el puntaje del jugador. En este caso, la maquina posee 0 puntos.| Se espera que la maquina juegue cualquier carta cuando el jugador tenga 0 puntos | La salida obtenida fue un menos 1. ![Salida 1](pruebas/1.png) |
|Se quiere comprobar que en la dificultad facil la maquina no distingue que cartas usar sin importar el puntaje del jugador. En este caso, la maquina posee 8 puntos.| Se espera que la maquina juegue cualquier carta cuando esta tenga 8 puntos | La salida obtenida fue una carta negativa. ![Salida 2](pruebas/2.png) |
|Se quiere comprobar que en la dificultad facil la maquina no distingue que cartas usar sin importar la carta que el jugador haya jugado. En este caso, el jugador utiliza un mas 2.| Se espera que la maquina juegue cualquier carta. | La salida obtenida fue una carta espejo, algo que es ineficiente. ![Salida 3](pruebas/3.png) |


Maquina con 8 puntos resta puntos al jugador