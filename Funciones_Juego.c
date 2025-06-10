#include "Funciones_Juego.h"
#include "pila.h"
#include "time.h"
#include "Lista_Dinamica.h"
#include "API.h"
int generarMazo(tPila* mazo,tCarta* mano1, tCarta* mano2, int inicio)
{
    srand(time(NULL));
    int pos;
    int i=0;
    tCantidadXTipo cantidadPorTipo[]=
    {
        {6, "MAS_2"},
        {10, "MAS_1"},
        {8,"MENOS_1"},
        {6, "MENOS_2"},
        {6, "REPETIR"},
        {4, "ESPEJO"}
    };
    if(inicio==1)
    {
        for(i=0; i<3; i++)
        {
            pos=comparaCartas(&mano1->carta[i]);
            if(pos>=0 && pos<=5)
                cantidadPorTipo[pos].cantidad--;
        }
        for(i=0; i<3; i++)
        {
            pos=comparaCartas(&mano2->carta[i]);
            if(pos>=0 && pos<=5)
                cantidadPorTipo[pos].cantidad--;
        }
        i=0;
        while(i<34)
        {
            pos=rand()%6;
            if(cantidadPorTipo[pos].cantidad!=0)
            {
                apilar(mazo,cantidadPorTipo[pos].nCarta,sizeof(cantidadPorTipo[pos].nCarta));
                cantidadPorTipo[pos].cantidad--;
                i++;
            }

        }
    }
    else
    {
        while(i<40)
        {
            pos=rand()%6;
            if(cantidadPorTipo[pos].cantidad!=0)
            {
                apilar(mazo,cantidadPorTipo[pos].nCarta,sizeof(cantidadPorTipo[pos].nCarta));
                cantidadPorTipo[pos].cantidad--;
                i++;
            }

        }
    }
    return 0;
}

int comparaCartas( const char * carta)
{
    if(strcmp(carta,"MAS_2")==0)
        return 0;
    if(strcmp(carta,"MAS_1")==0)
        return 1;
    if(strcmp(carta,"MENOS_1")==0)
        return 2;
    if(strcmp(carta,"MENOS_2")==0)
        return 3;
    if(strcmp(carta,"REPETIR")==0)
        return 4;
    if(strcmp(carta,"ESPEJO")==0)
        return 5;
    return CARTA_INVALIDA;
}

int repartir(tPila* mazo,tCarta* cartas,int pos)
{
    desapilar(mazo,cartas[pos].carta,sizeof(tCarta));
    return OK;
}

int elegirCartaFacil(const tJugador *jugador,const tMaquina *maquina,const char *UltimacartaJugador)
{
    return(rand()%3);
}

void aplicarEfecto(char *carta, int* puntos, int* puntosoponente, int *miturno,char *cartaoponente)
{
    if (strcmp(carta,"MAS_1") == 0)
        *puntos+=1;
    else if (strcmp(carta,"MAS_2") == 0)
        *puntos += 2;
    else if (strcmp(carta,"MENOS_1") == 0)
    {
        *puntosoponente-=1;
        if (*puntosoponente < 0)
            *puntosoponente = 0;
    }
    else if (strcmp(carta,"MENOS_2") == 0)
    {
        *puntosoponente-=2;
        if (*puntosoponente < 0)
            *puntosoponente = 0;
    }
    else if (strcmp(carta,"REPETIR") == 0)
        *miturno = 1;
}

int elegirCartaJugador(tCarta* cartas,char* cartajugada)
{
    int i,decision;
    printf("Cartas disponibles (seleccionar una):\n");
    for(i=0; i<3; i++)
    {
        printf("[%d] %s\n",i+1,cartas->carta);
        cartas+=1;
    }
    cartas-=3;

    do
    {
        printf("Decision:");
        scanf("%d",&decision);
        fflush(stdin);
    }
    while(decision<1 || decision>3);
    decision--;
    strcpy(cartajugada,cartas[decision].carta);
    return decision;

}

int elegirCartaMedia(const tJugador *jugador,const tMaquina *maquina,const char *UltimacartaJugador)
{
    int i, posCero, posUno, posDos;
    int pos[3] = {0};

    if(jugador->puntos == 0)
    {
        i = 0;
        while(i<3)
        {

            if(strcmpi(maquina->cartas[i].carta, "MENOS_1") == 0)
                pos[i] = 1;
            else
            {
                if (strcmpi(maquina->cartas[i].carta, "MENOS_2") == 0)
                    pos[i] = 1;
            }
            i++;
        }

        if(pos[0] == 1 || pos[1] == 1 || pos[2] == 1)
        {
            posCero = buscarValor(pos, 0);
            if(posCero != -1) // juega el primer cero que encuentra --> 0 = cualquier carta que no es -1 o -2
            {
                return posCero;
            }
            else
                return 0;
        }

    }

    else
    {
        if(maquina->puntos > 7)
        {
            while(i<3)
            {
                if(strcmpi(maquina->cartas[i].carta, "MAS_1") == 0)
                    pos[i] = 1;
                else
                {
                    if (strcmpi(maquina->cartas[i].carta, "MAS_2") == 0)
                        pos[i] = 2;
                }
                i++;
            }

            posDos = buscarValor(pos, 2);
            if(posDos != -1)
                return posDos;

            else
            {
                posUno = buscarValor(pos, 1);
                if(posUno != -1)
                    return posUno;
                else
                    return 0;
            }

        }

        else
            return 0;
    }

    return 0;

}

int buscarValor(const int *pos, const int valor)
{
    int i = 0;

    while(i < 3)
    {
        if(*pos == valor)
            return i;

        pos++;
        i++;
    }

    return CARTA_INVALIDA;
}




int elegirCartaDificil(const tJugador *jugador,const tMaquina *maquina,const char *UltimacartaJugador)
{

    int i=0,posUno,posDos,posCero,pos[3]= {0,0,0},cartaBuena=0,jugadorataco=0;


    while(i<3)
    {

        if(strcmp(maquina->cartas[i].carta,"ESPEJO")==0)

        {
            pos[i]=1;

        }



        if(strcmp(maquina->cartas[i].carta,"REPETIR")==0)
        {
            pos[i]= 2;
        }

        if(strcmp(maquina->cartas[i].carta,"MAS_2")==0)
        {
            cartaBuena++;
        }

        if(strcmp(maquina->cartas[i].carta,"MAS_1")==0)
        {
            cartaBuena++;
        }
        i++;
    }

    if(strcmp(UltimacartaJugador,"MENOS_1")==0 || strcmp(UltimacartaJugador,"MENOS_2")==0)
    {
        jugadorataco=1;
        posCero = buscarValor(pos,1);
        if(posCero!=-1 && jugadorataco == 1)
        {
            return posCero; //Uso carta ESPEJO.
        }
        else
        {
            for(i=0; i<3; i++)
            {
                if(pos[i]==1)
                {
                    pos[i]=0;
                }  // Limpio el vector en cada posición porque no hay carta negativa.
            }
        }
    }

    if(cartaBuena > 1 )
    {
        posUno = buscarValor(pos,2);
        if(posUno != -1)
            return posUno; // Uso REPETIR carta.
    }

    for(i=0; i<3; i++)
        pos[i]=0; //Limpio el vector.

    if(jugador->puntos>7)
    {
        i=0;
        while(i<3)
        {

            if(strcmp(maquina->cartas[i].carta,"REPETIR")==0)
                pos[i]= 1;

            if(strcmp(maquina->cartas[i].carta,"MENOS_2")==0)
                pos[i]=2;

            if(strcmp(maquina->cartas[i].carta,"MENOS_1")==0)
                pos[i]=3;

            i++;
        }


        posCero = buscarValor(pos,1); //REPETIR.

        if(posCero != -1 )
            return posCero;

        posUno = buscarValor(pos,2); //MENOS_2.

        if(posUno != -1)
            return posUno;

        posDos = buscarValor(pos,3); //MENOS_1.

        if(posDos != -1)
            return posDos;

    }
    i=0;
    while(i<3) //Si llegue hasta aca y no tengo una jugada estrategica se suma cualquier punto.
    {
        if (strcmp(maquina->cartas[i].carta, "MAS_2") == 0 || strcmp(maquina->cartas[i].carta, "MAS_1") == 0)
            return i;
        i++;
    }

    return rand()%3;
    //Jugar cualquiera si no encuentro una jugada estrategica.
}

void juego(int dificultad(const tJugador *jugador, const tMaquina *maquina,const char *UltimacartaJugador))
{
    int miturno=1;
    char cartaJugada[15]="";
    char cartaMaquina[15]="";
    int turno=1;
    int i,decision;
    tJugador jugador;
    tMaquina maquina;
    tPila mazo;
    tLista informe;
    tInforme registroInf;

    crearPila(&mazo);
    crearLista(&informe);

    jugador.puntos=0;
    maquina.puntos=0;
    printf("Introduzca su nombre:");
    scanf("%s",jugador.nombre);
    Amayuscula_cad(jugador.nombre);
    strcpy(maquina.nombre,"Maquina");

    generarMazo(&mazo,jugador.cartas,maquina.cartas,0);
    for(i=0; i<3; i++)
        repartir(&mazo,jugador.cartas,i);
    for(i=0; i<3; i++)
        repartir(&mazo,maquina.cartas,i);

    while(jugador.puntos<12 && maquina.puntos<12)
    {
        system("cls");
        printf("Turno:%d\n",turno);
        printf("Tus Puntos:%d\t\t\t",jugador.puntos);

        printf("Puntos Maquina:%d\n",maquina.puntos);
        miturno=1;
        while(miturno==1)
        {
            miturno=0;
            if(strcmp(cartaMaquina,"MENOS_1")==0 || strcmp(cartaMaquina,"MENOS_2")==0)
            {
                printf("Te han tirado una carta negativa, utiliza una carta ESPEJO si la tienes.\n");
                decision=elegirCartaJugador(jugador.cartas,cartaJugada);
                if(strcmp(cartaJugada,"ESPEJO")==0)
                    aplicarEfecto(cartaMaquina,&jugador.puntos,&maquina.puntos,&miturno,"");
                else
                {
                    aplicarEfecto(cartaMaquina, &maquina.puntos, &jugador.puntos, &miturno, "");
                    if(strcmp(cartaJugada, "MENOS_1") != 0 && strcmp(cartaJugada, "MENOS_2") != 0)
                        aplicarEfecto(cartaJugada,&jugador.puntos,&maquina.puntos,&miturno,"");
                }
            }
            else
            {
                decision=elegirCartaJugador(jugador.cartas,cartaJugada);
                if(strcmp(cartaJugada,"MENOS_1") != 0 && strcmp(cartaJugada,"MENOS_2") != 0)
                    aplicarEfecto(cartaJugada,&jugador.puntos,&maquina.puntos,&miturno,"");
            }


            printf("\n\nJugo la carta: %s\n\n",cartaJugada);

            registroInf.turno=turno;
            strcpy(registroInf.carta,cartaJugada);
            registroInf.puntos=jugador.puntos;
            strcpy(registroInf.nombre,jugador.nombre);

            ponerAlFinal(&informe,&registroInf,sizeof(registroInf));

            repartir(&mazo,jugador.cartas,decision);
            if(pilaVacia(&mazo))
                generarMazo(&mazo,jugador.cartas,maquina.cartas,1);
        }

        miturno=1;
        while(miturno==1 && jugador.puntos<12)
        {
            miturno=0;

            if(strcmp(cartaJugada,"MENOS_1")==0 || strcmp(cartaJugada,"MENOS_2")==0)
            {
                decision=dificultad(&jugador,&maquina,cartaJugada);
                strcpy(cartaMaquina,maquina.cartas[decision].carta);
                if(strcmp(cartaMaquina,"ESPEJO")==0)
                    aplicarEfecto(cartaJugada,&maquina.puntos,&jugador.puntos,&miturno,"");
                else
                {
                    aplicarEfecto(cartaJugada, &jugador.puntos, &maquina.puntos, &miturno, "");
                    if (strcmp(cartaMaquina, "MENOS_1") != 0 && strcmp(cartaMaquina, "MENOS_2") != 0)
                        aplicarEfecto(cartaMaquina,&maquina.puntos,&jugador.puntos,&miturno,"");
                }
            }
            else
            {
                decision=dificultad(&jugador,&maquina,cartaJugada);
                strcpy(cartaMaquina,maquina.cartas[decision].carta);
                if (strcmp(cartaMaquina, "MENOS_1") != 0 && strcmp(cartaMaquina, "MENOS_2") != 0)
                    aplicarEfecto(cartaMaquina,&maquina.puntos,&jugador.puntos,&miturno,"");
            }
            printf("Decision de la maquina:\n");
            printf("Jugo la carta: %s\n\n",cartaMaquina);

            registroInf.turno=turno;
            strcpy(registroInf.carta,cartaMaquina);
            registroInf.puntos=maquina.puntos;
            strcpy(registroInf.nombre,maquina.nombre);

            ponerAlFinal(&informe,&registroInf,sizeof(registroInf));

            repartir(&mazo,maquina.cartas,decision);
            if(pilaVacia(&mazo))
                generarMazo(&mazo,jugador.cartas,maquina.cartas,1);
        }
        system("pause");
        turno++;
    }


    if(jugador.puntos>=12)
    {
        printf("Ganador: %s.\n",jugador.nombre);
        guardarRanking("limite",jugador.nombre,1);
    }
    else
    {
        guardarRanking("limite",jugador.nombre,0);
        printf("La maquina gano.\n");
    }
    system("cls");
    printf("\n\n---------Resumen del Juego---------\n\n\n");
    mmap(&informe,muestraInforme);
    generarInforme(&informe,&jugador,&maquina);


}

void muestraInforme(void * informe)
{
    tInforme* inf=(tInforme*)informe;
    printf("Turno:%d\n",inf->turno);
    printf("Nombre:%s\n",inf->nombre);
    printf("Carta Jugada:%s\n",inf->carta);
    printf("Puntos Actuales:%d\n",inf->puntos);
    printf("\n\n");
}

int generarInforme(tLista* informe,tJugador* jugador, tMaquina* maquina)
{
    FILE* fp;
    tInforme *inf;
    char narch[60];

    time_t tiempo_actual = time(NULL);
    struct tm *tiempo_local = localtime(&tiempo_actual);
    strftime(narch, sizeof(narch),"informe-juego_%Y-%m-%d-%H-%M.txt", tiempo_local);

    fp=fopen(narch,"wt");
    if(fp==NULL)
    {
        printf("No se pudo generar informe.");
        return ERROR;
    }
    if(jugador->puntos>=12)
        fprintf(fp,"Ganador:%s\n\n",jugador->nombre);
    else
        fprintf(fp,"Ganador:%s\n\n",maquina->nombre);

    fprintf(fp,"Puntaje Final Jugador %s:%d\n",jugador->nombre,jugador->puntos);
    fprintf(fp,"Puntaje Final Maquina:%d\n\n",maquina->puntos);
    fprintf(fp,"\n\n---------Resumen del Juego---------\n\n\n");

    while(*informe!=NULL)
    {
        inf=(tInforme*)((*informe)->info);
        fprintf(fp,"Turno:%d\n",inf->turno);
        fprintf(fp,"Nombre:%s\n",inf->nombre);
        fprintf(fp,"Carta Jugada:%s\n",inf->carta);
        fprintf(fp,"Puntos Actuales:%d\n",inf->puntos);
        fprintf(fp,"\n\n");
        informe=&(*informe)->sig;
    }

    fclose(fp);
    return OK;
}
void Amayuscula_cad(char *cadena)
{
    while (*cadena) {
        if (*cadena >= 'a' && *cadena <= 'z') {
            *cadena = *cadena - ('a' - 'A');
        }
        cadena++;
    }
}
