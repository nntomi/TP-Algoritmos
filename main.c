#include <stdio.h>
#include <stdlib.h>
#include "prueba.h"
#include "pila.h"

int main()
{
    int miturno=1;
    char cartaJugada[15];
    int turno=1;
    int i,decision;
    tJugador jugador;
    tMaquina maquina;
    tPila mazo;
    crearPila(&mazo);

    generarMazo(&mazo,jugador.cartas,maquina.cartas,0);
    for(i=0;i<3;i++)
        repartir(&mazo,jugador.cartas,i);
    for(i=0;i<3;i++)
        repartir(&mazo,maquina.cartas,i);

    while(jugador.puntos>=12 || maquina.puntos>=12)
    {
        printf("Turno:%d\n",turno);
        miturno=1;
        while(miturno==1 || strcmp(cartaJugada,"REPETIR")==0)
        {

            miturno=0;
            printf("Cartas disponibles (seleccionar una):\n");
            for(i=0;i<3;i++)
                printf("%s\n",jugador.cartas[i].carta);

            do{
                scanf("%d",&decision);
            }while(decision<1 || decision>3);

            fflush(stdin);
            strcpy(cartaJugada,jugador.cartas[decision-1].carta);
            printf("\n\nJugo la carta: %s\n\n",cartaJugada);

            desapilar(&mazo,jugador.cartas[decision-1].carta,sizeof(tCarta));
            if(pilaVacia(&mazo))
                generarMazo(&mazo,jugador.cartas,maquina.cartas,1);
        }

        miturno=1;
        while(miturno==1 || strcmp(cartaJugada,"REPETIR")==0)
        {

            miturno=0;

            printf("Decision de la maquina:\n");

            strcpy(cartaJugada,maquina.cartas[decision-1].carta);
            printf("\n\nJugo la carta: %s\n\n",cartaJugada);

            desapilar(&mazo,maquina.cartas[decision-1].carta,sizeof(tCarta));
            if(pilaVacia(&mazo))
                generarMazo(&mazo,jugador.cartas,maquina.cartas,1);
        }



        turno++;
    }

    return 0;
}
