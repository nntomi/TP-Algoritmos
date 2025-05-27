#include "Pila.h"

void crearPila(tPila *p)
{
    *p = NULL;
}

int pilaLlena(const tPila *p, unsigned cantBytes)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;

     //return 1; puede estar o no disponible no es necesario hacer lo anterior. Digo que esta disponible.
}

int apilar(tPila *p,const void *d, unsigned cantBytes)
{   tNodo *nue;
    if((nue = (tNodo *)malloc(sizeof(tNodo)))== NULL ||
       (nue->info = malloc (cantBytes))== NULL)
    { //Hacer la reserva de memoria afuera del if y luego comparar.
        free(nue);
        return 0;
    }
    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1;

}

int verTope (const tPila *p,void *d, unsigned cantBytes)
{
    if(*p==NULL)
    {
        return 0;
    }
    memcpy(d,(*p)->info,minimo(cantBytes,(*p)->tamInfo));
    return 1;
}

int pilaVacia(const tPila *p)
{
    return *p==NULL;
}

int desapilar(tPila *p,void *d,unsigned cantBytes)
{
    tNodo *aux = *p;

    if(aux == NULL)
    {
        return 0;
    }

    *p = aux->sig;
    memcpy(d,aux->info,minimo(cantBytes,aux ->tamInfo));
    free(aux->info);
    free(aux);
    return 1;
}

void vaciarPila(tPila *p)
{
    while(*p)
    {
        tNodo *aux = *p;

        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}
