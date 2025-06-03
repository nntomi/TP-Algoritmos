#include "Funciones_Juegos.h"
#include "pila.h"

int main()
{
    //resetearGrupo("limite");
    char decision;
    printf("----------------Menu DoCe----------------\n\n");
    printf("Opciones\n\n");
    printf("[A] Jugar\n[B] Ver Ranking\n[C] Salir\n");
    do
    {
        printf("\nElija una de las opciones:");
        scanf("%c",&decision);
        fflush(stdin);
        decision=AMAYUS(decision);
    }while(decision!='A' && decision!='B' && decision!= 'C');

    system("cls");
    switch(decision)
    {
        case 'A':
            decision=' ';
            printf("----------------Opciones de Dificultad----------------\n");
            printf("\n[A] Facil\n[B] Medio\n[C] Dificil\n");
            do
            {
                printf("\nElija una de las opciones:");
                scanf("%c",&decision);
                fflush(stdin);
                decision=AMAYUS(decision);
            }while(decision!='A' && decision!='B' && decision!= 'C');
            if(decision=='A')
                juego(elegirCartaFacil);
            else if(decision=='B')
                juego(elegirCartaMedia);
            else
                juego(elegirCartaDificil);
            break;

        case 'B':

             verRanking();
            break;

        case 'C':

            break;
    }

    return 0;
}
