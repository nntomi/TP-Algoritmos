#ifndef PRUEBA_H_INCLUDED
#define PRUEBA_H_INCLUDED




typedef struct
{
    char carta[15];
}tCarta;

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


#endif // PRUEBA_H_INCLUDED
