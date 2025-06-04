#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define minimo(a, b) ((a) < (b) ? (a) : (b))
#define OK 1
#define ERROR 0
#define PILA_VACIA 0
typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;

}tNodo;
typedef tNodo *tPila;

void crearPila(tPila *p);
int pilaLlena(const tPila *,unsigned);
int apilar(tPila *,const void *,unsigned);
int verTope(const tPila *p,void *d,unsigned);
int desapilar(tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);
int pilaVacia(const tPila *p);

#endif // PILA_H_INCLUDED
