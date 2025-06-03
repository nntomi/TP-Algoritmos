#include "Lista_Dinamica.h"

void crearLista(tLista *p)
{
    *p = NULL;
}

int Listavacia(const tLista *p)
{
    return *p == NULL;
}

int Listallena(const tLista *p, unsigned cantBytes)
{
    ttNodo *aux = (ttNodo*)malloc(sizeof(ttNodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);


    return aux==NULL || info == NULL;
}
void vaciarLista(tLista *p)
{
    while(*p)
    {
        ttNodo *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }


}
int ponerAlcomienzo(tLista *p, const void *d,unsigned cantBytes)
{

    ttNodo *nuevo;

    nuevo = (ttNodo*)malloc(sizeof(ttNodo));
    if(!nuevo)
    {
        free(nuevo);
        return 0;
    }
    nuevo->info = malloc(cantBytes);
    if(!nuevo->info)
    {
        free(nuevo->info);
        return 0;
    }

    memcpy(nuevo->info,d,cantBytes);
    nuevo->tamInfo = cantBytes;
    nuevo->sig = *p;
    *p = nuevo;

    return 1;

}
int sacarPrimeroLista(tLista *p, void *d,unsigned cantBytes)
{
    ttNodo *aux = *p;
    if(aux ==NULL)
    {
        return 0;
    }
    *p = aux->sig;
    memcpy(d,aux->info,MINIMO(cantBytes,aux->tamInfo));
    free(aux->info);
    free(aux);
    return 1;

}
int verPrimeroLista(tLista *p, void *d,unsigned cantBytes)
{
    if(*p == NULL)
    {
        return 0;
    }

    memcpy(d, (*p)->info,MINIMO(cantBytes,(*p)->tamInfo));

    return 1;


}

int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes)
{
    ttNodo *nuevo;
    while(*p)
    {
        p= &(*p)->sig;
    }
    if((nuevo=(ttNodo*)malloc(sizeof(ttNodo)))==NULL || (nuevo->info=malloc(cantBytes))==NULL)
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info,d,cantBytes);
    nuevo->tamInfo = cantBytes;
    nuevo->sig = NULL;
    *p = nuevo;
    return 1;

}
int sacarUltimoLista(tLista *p,void *d,unsigned cantBytes)
{
    if(*p == NULL)
    {
        return 0;
    }
    while((*p)->sig)
    {
        p = &(*p)->sig;
    }
    memcpy(d,(*p)->info,MINIMO (cantBytes,(*p)->tamInfo));
    free((*p)->info);
    free(*p);
    *p = NULL;

    return 1;
}

int cmp_int(void *a,void *b)
{

    return *(int*)b-*(int*)a;

}

int insertarordenadolista(tLista *lista,void *dato,unsigned cantBytes,int cmp(void*a,void*b))
{
    ttNodo *nuevo;

    while(*lista!=NULL && cmp((*lista)->info,dato)<0)
    {
        lista = &(*lista)->sig;
    }
    if(cmp((*lista)->info,dato)==0)
    {
        return 0; //No quiero duplicados
    }
    nuevo = (ttNodo*)malloc(sizeof(ttNodo));
    if(!nuevo)
    {
        free(nuevo);
        return 0;
    }
    nuevo->info = malloc(cantBytes);
    if(!nuevo->info)
    {
        free(nuevo->info);
        return 0;
    }
    memcpy(nuevo->info,dato,cantBytes);
    nuevo->tamInfo= cantBytes;
    nuevo->sig = *lista;
    *lista = nuevo;

    return 1;
}
/*int eliminardatolista(tLista *lista,void *dato,unsigned cantBytes,int cmp(void*a,void*b))
{
    ttNodo *nuevo;
    while(*lista!=NULL)
    {

        if(cmp(dato,(*lista)->info)==0)
        {

            free((*lista)->info);
            free(*lista);
            *lista = (*lista)->sig;


            return 1;

        }

        lista = &(*lista)->sig;

    }





    return 0; //No se encontro el dato.

}*/

void mmap(tLista* lista,void accion(void*a))
{
    while(*lista!=NULL)
    {
        accion((*lista)->info);
        lista=&(*lista)->sig;
    }
}

