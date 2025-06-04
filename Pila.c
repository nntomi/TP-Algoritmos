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

}

int apilar(tPila *p,const void *d, unsigned cantBytes)
{
    tNodo *nue;
    if((nue = (tNodo *)malloc(sizeof(tNodo)))== NULL ||
            (nue->info = malloc (cantBytes))== NULL)
    {
        free(nue);
        return ERROR;
    }
    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return OK;

}

int verTope (const tPila *p,void *d, unsigned cantBytes)
{
    if(*p==NULL)
    {
        return PILA_VACIA;
    }
    memcpy(d,(*p)->info,minimo(cantBytes,(*p)->tamInfo));
    return OK;
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
        return PILA_VACIA;
    }

    *p = aux->sig;
    memcpy(d,aux->info,minimo(cantBytes,aux ->tamInfo));
    free(aux->info);
    free(aux);
    return OK;
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

