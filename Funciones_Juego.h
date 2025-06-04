#ifndef PRUEBA_H_INCLUDED
#define PRUEBA_H_INCLUDED

#include "Pila.h"
#include "Lista_Dinamica.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <curl/curl.h>
#define AMAYUS(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - 32) : (c))
#define CARTA_INVALIDA -1
#define MAX_URL 100
#define MAX_CODIGO 50

typedef struct
{
    char carta[15];
} tCarta;

typedef struct
{
    char nombre[30];
    int puntos;
    tCarta cartas[3];
} tJugador;

typedef struct
{
    char nombre[30];
    int puntos;
    tCarta cartas[3];
    int dificultad;
} tMaquina;

typedef struct
{
    int cantidad;
    char nCarta[15];
} tCantidadXTipo;

typedef struct
{
    int turno;
    char nombre[30];
    char carta[15];
    int puntos;
} tInforme;

int comparaCartas(char * carta);
int generarMazo(tPila* mazo,tCarta* mano1, tCarta* mano2,int inicio);
int repartir(tPila* mazo,tCarta* cartas,int pos);
void aplicarEfecto(char *carta, int* puntos, int* puntosoponente, int *miturno,char *cartaoponente);
int elegirCartaJugador(tCarta* cartas,char* cartajugada);
int elegirCartaFacil(tJugador *jugador, tMaquina *maquina,char *UltimacartaJugador);
int elegirCartaMedia(tJugador *jugador, tMaquina *maquina,char *UltimacartaJugador);
int elegirCartaDificil(tJugador *jugador,tMaquina *maquina,char *UltimacartaJugador);
int buscarValor(int *pos, int valor);
void juego(int dificultad(tJugador *jugador, tMaquina *maquina,char *UltimacartaJugador)); //Es generica para la elección de dificultad.
void muestraInforme(void * informe);
int generarInforme(tLista* informe,tJugador* jugador, tMaquina* maquina);
void Amayuscula_cad(char *cadena);
#endif // PRUEBA_H_INCLUDED
