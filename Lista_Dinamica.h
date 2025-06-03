#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(x,y) ((x) < (y) ? (x) : (y))

typedef struct ssNodo
{
    void *info;
    unsigned tamInfo;
    struct ssNodo *sig;

} ttNodo;

typedef ttNodo *tLista;


void crearLista(tLista *p);
int Listavacia(const tLista *p);
int Listallena(const tLista *p, unsigned cantBytes);
void vaciarLista(tLista *p);
int ponerAlcomienzo(tLista *p, const void *d,unsigned cantBytes);
int sacarPrimeroLista(tLista *p, void *d,unsigned cantBytes);
int verPrimeroLista(tLista *p, void *d,unsigned cantBytes);
int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes);
int sacarUltimoLista(tLista *p,void *d,unsigned cantBytes);
void mmap(tLista* lista,void accion(void*a));

int cmp_int(void *a,void*b);
int insertarordenadolista(tLista *lista,void *dato,unsigned cantBytes,int cmp(void*,void*));
int eliminardatolista(tLista *lista, void *dato,unsigned cantBytes,int cmp(void*,void*));
#endif // PILA_DINAMICA_H_INCLUDED
