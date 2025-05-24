#include "prueba.h"


void aplicarCarta(tCarta *carta,tJugador *jugador, tMaquina *maquina, int *repetirTurno)
{

    // aumentar contador de descartes y poner la carta???

    switch(carta->carta)
    {
    case MAS_DOS:
    jugador->puntos +=2;
        break;
    case MAS_UNO:
        jugador->puntos +=1;
        break;
    case MENOS_UNO:
        if(maquina->puntos >0)
        {
            maquina->puntos--;
        }
        break;
    case MENOS_DOS:
        if(maquina->puntos >0)
        {
            maquina->puntos--;
        }
        break;
        case REPETIR:
        *repetirTurno = 1;
        break;

        case ESPEJO:
            devolverEfecto(maquina,carta);
        break;
    default: printf("Carta invalida \n");


    }
}
void devolverEfecto(tMaquina *maquina, tCarta *carta)
{

    switch (carta->carta)
    {
        case MENOS_UNO:
        if(maquina->puntos >0)
        {
            maquina->puntos--;
        }
        break;
    case MENOS_DOS:
        if(maquina->puntos >0)
        {
            maquina->puntos--;
        }
        break;



    }


}

//int generarMazo(tCarta )
