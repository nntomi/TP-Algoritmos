#ifndef PRUEBA_H_INCLUDED
#define PRUEBA_H_INCLUDED

#include "Pila.h"



typedef struct
{
    char carta[15];
}tCarta;
/*
typedef enum
{
    MAS2, //+2 puntos
    MAS1, // 1 punto
    MENOS1, //-1
    MENOS2, //-2
    REPETIR,
    ESPEJO
}tipoCarta;

typedef struct
{
    tipoCarta tipo;
}tCarta;

*/

typedef struct
{
    char nombre[30];
    int puntos;
    tCarta cartas[3];
}tJugador;

typedef struct
{
    int puntos;
    tCarta cartas[3];
    int dificultad;
}tMaquina;

typedef struct
{
    int cantidad;
    char nCarta[15];
}tCantidadXTipo;

int comparaCartas(char * carta);
int generarMazo(tPila* mazo,tCarta* mano1, tCarta* mano2,int inicio);
int repartir(tPila* mazo,tCarta* cartas,int pos);
int elegirCartaMedia(tJugador jugador, tMaquina maquina);
int elegirCartaDificil(tJugador jugador, tMaquina maquina,char UltimacartaJugador[]);
int buscarValor(int pos[], int valor);


//void aplicarCarta(tCarta * ,tJugador *,tMaquina *,int *repetirTurno);
//void devolverEfecto (tMaquina *,tCarta *);


#endif // PRUEBA_H_INCLUDED
