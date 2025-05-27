#include <stdio.h>
#include <stdlib.h>
#include "prueba.h"
#include "pila.h"

int main()
{
    int miturno=1;
    char cartaJugada[15];
    int turno=1;
    int i, decision, pos;
    tJugador jugador;
    tMaquina maquina;
    tPila mazo;
    crearPila(&mazo);

    jugador.puntos=0;
    maquina.puntos=0;

    generarMazo(&mazo,jugador.cartas,maquina.cartas,0);
    for(i=0;i<3;i++)
        repartir(&mazo,jugador.cartas,i);
    for(i=0;i<3;i++)
        repartir(&mazo,maquina.cartas,i);


    while(jugador.puntos<12 && maquina.puntos<12)
    {
        printf("Turno:%d\n",turno);
        miturno=1;
        while(miturno==1 || strcmp(cartaJugada,"REPETIR")==0)
        {

            miturno=0;
            printf("Cartas disponibles (seleccionar una):\n");
            fflush(stdin);
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
            pos = elegirCartaMedia(jugador, maquina);
            //printf("NUMERO: %d\n", pos);

           // printf("CHEQUEO\n");

            printf("CARTAS DE LA MAQUINA \n");
            for(i=0; i<3; i++)
            {
                printf("%s \n", maquina.cartas[i].carta);
            }

            printf("Decision de la maquina:\n");
            fflush(stdout);

            strcpy(cartaJugada,maquina.cartas[pos].carta);
            printf("\nJugo la carta: %s\n\n",cartaJugada);

            desapilar(&mazo,maquina.cartas[pos].carta,sizeof(tCarta));
            if(pilaVacia(&mazo))
                generarMazo(&mazo,jugador.cartas,maquina.cartas,1);
        }

        turno++;
    }

    return 0;
}

//decisiones de la maquina de acuerdo a la dificultad
//carta espejo: de que manera --> if espejos --> if -1 --> if-2
// sumar y restar puntos
// ranking APIS
// interfaz grafica??

//evita jugadas inefectivsa
//no usa cartas de sacar puntos si el oponente tiene 0 puntos
//prioriza catas que suman puntos si esta cerca de ganar
//DIFICULTAD MEDIA

