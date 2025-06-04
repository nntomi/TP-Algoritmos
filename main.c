#include "prueba.h"
#include "pila.h"
#include "API.h"

int main()
{
    //resetearGrupo("limite"); //Descomentar en caso de querer hacer un DELETE de la API.
    char decision = ' ';
    do
    {
        printf("\n\n\t\t----------------Menu DoCe----------------\n\n");
        printf("\n\nOpciones\n\n");
        printf("[A] Jugar\n[B] Ver Ranking\n[C] Salir\n");

        do
        {
            printf("\nElija una de las opciones: ");
            scanf(" %c", &decision); // espacio antes de %c para consumir '\n' anterior
            decision = AMAYUS(decision);
        }
        while (decision != 'A' && decision != 'B' && decision != 'C');

        system("cls");

        switch (decision)
        {
        case 'A':
            printf("\n\n\t\t----------------Opciones de Dificultad----------------\n");
            printf("\n\n[A] Facil\n[B] Medio\n[C] Dificil\n");

            char dificultad;
            do
            {
                printf("\nElija una de las opciones: ");
                scanf(" %c", &dificultad);
                dificultad = AMAYUS(dificultad);
            }
            while (dificultad != 'A' && dificultad != 'B' && dificultad != 'C');

            if (dificultad == 'A')
                juego(elegirCartaFacil);
            else if (dificultad == 'B')
                juego(elegirCartaMedia);
            else
                juego(elegirCartaDificil);
            break;

        case 'B':
            verRanking();
            break;

        case 'C':
            printf("\n\tSe finalizo el juego. Hasta luego!\n");
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    while (decision != 'C');

    return 0;

}
