#include <stdio.h>
#include <stdlib.h>
#include "prueba.h"
#include "pila.h"

int main()
{
    int i;
    char carta[20];
    tJugador jugador;
    tMaquina maquina;
    tPila mazo;
    crearPila(&mazo);

    generarMazo(&mazo,jugador.cartas,maquina.cartas,0);
    for(i=0;i<3;i++)
        repartir(&mazo,jugador.cartas,i);
    for(i=0;i<3;i++)
        repartir(&mazo,maquina.cartas,i);

        i=0;
    while(!pilaVacia(&mazo))
    {
        desapilar(&mazo,carta,sizeof(carta));
        printf("%s\n",carta);
        i++;
    }

    printf("%d",i);

    return 0;
}
