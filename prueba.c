#include "prueba.h"
#include "pila.h"
#include "time.h"

int generarMazo(tPila* mazo,tCarta* mano1, tCarta* mano2, int inicio)
{
    srand(time(NULL));
    int pos,i;
        tCantidadXTipo cantidadPorTipo[]=
    {
        {6, "MAS_2"},
        {10, "MAS_1"},
        {8,"MENOS_1"},
        {6, "MENOS_2"},
        {6, "REPETIR"},
        {4, "ESPEJO"}
    };
    if(inicio==1)
    {
        for(i=0;i<3;i++)
        {
            pos=comparaCartas(&mano1->carta[i]);
            if(pos>=0 && pos<=5)
                cantidadPorTipo[pos].cantidad--;
        }
        for(i=0;i<3;i++)
        {
            pos=comparaCartas(&mano2->carta[i]);
            if(pos>=0 && pos<=5)
                cantidadPorTipo[pos].cantidad--;
        }
        i=0;
        while(i<34)
        {
            pos=rand()%6;
            if(cantidadPorTipo[pos].cantidad!=0)
            {
                apilar(mazo,cantidadPorTipo[pos].nCarta,sizeof(cantidadPorTipo[pos].nCarta));
                cantidadPorTipo[pos].cantidad--;
                i++;
            }

        }
    }
    else
    {
        while(i<40)
        {
            pos=rand()%6;
            if(cantidadPorTipo[pos].cantidad!=0)
            {
                apilar(mazo,cantidadPorTipo[pos].nCarta,sizeof(cantidadPorTipo[pos].nCarta));
                cantidadPorTipo[pos].cantidad--;
                i++;
            }

        }
    }
    return 0;
}
/*
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
*/
int comparaCartas(char * carta)
{
    if(strcmp(carta,"MAS_2"))
        return 0;
    if(strcmp(carta,"MAS_1"))
        return 1;
    if(strcmp(carta,"MENOS_1"))
        return 2;
    if(strcmp(carta,"MENOS_2"))
        return 3;
    if(strcmp(carta,"REPETIR"))
        return 4;
    if(strcmp(carta,"ESPEJO"))
        return 5;
    return -1;
}

int repartir(tPila* mazo,tCarta* cartas,int pos)
{
    desapilar(mazo,cartas[pos].carta,sizeof(tCarta));
    return 0;
}



