#include "prueba.h"
#include "pila.h"
#include "time.h"

int generarMazo(tPila* mazo,tCarta* mano1, tCarta* mano2, int inicio)
{
    srand(time(NULL));
    int pos,i = 0;
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
        for(i=0;i<3;i++)
        {
            pos=comparaCartas(&mano1->carta[i]);
            if(pos>=0 && pos<=5)
                cantidadPorTipo[pos].cantidad--;
        }
        for(i=0;i<3;i++)
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
/*
void aplicarCarta(tCarta *carta,tJugador *jugador, tMaquina *maquina, int *repetirTurno)
{

    // aumentar contador de descartes y poner la carta???

    switch(carta->carta)
    {
    case MAS_DOS:
    jugador->puntos +=2;
        break;
    case MAS_UNO:
        jugador->puntos +=1;
        break;
    case MENOS_UNO:
        if(maquina->puntos >0)
        {
            maquina->puntos--;
        }
        break;
    case MENOS_DOS:
        if(maquina->puntos >0)
        {
            maquina->puntos--;
        }
        break;
        case REPETIR:
        *repetirTurno = 1;
        break;

        case ESPEJO:
            devolverEfecto(maquina,carta);
        break;
    default: printf("Carta invalida \n");


    }
}
void devolverEfecto(tMaquina *maquina, tCarta *carta)
{

    switch (carta->carta)
    {
        case MENOS_UNO:
        if(maquina->puntos >0)
        {
            maquina->puntos--;
        }
        break;
    case MENOS_DOS:
        if(maquina->puntos >0)
        {
            maquina->puntos--;
        }
        break;



    }


}
*/
int comparaCartas(char * carta)
{
    if(strcmp(carta,"MAS_2") == 0 )
        return 0;
    if(strcmp(carta,"MAS_1") == 0)
        return 1;
    if(strcmp(carta,"MENOS_1")== 0)
        return 2;
    if(strcmp(carta,"MENOS_2")== 0)
        return 3;
    if(strcmp(carta,"REPETIR")== 0)
        return 4;
    if(strcmp(carta,"ESPEJO")== 0)
        return 5;
    return -1;
}

int repartir(tPila* mazo,tCarta* cartas,int pos)
{
    desapilar(mazo,cartas[pos].carta,sizeof(tCarta));
    return 0;
}


int elegirCartaMedia(tJugador jugador, tMaquina maquina)
{
    int i = 0, posCero, posUno, posDos;
    int pos[3] = {0};

   //printf("Decision de la maquina:\n");
    if(jugador.puntos == 0)
    {
        i = 0;
        while(i<3)
        {

            if(strcmpi(maquina.cartas[i].carta, "MENOS_1") == 0)
                pos[i] = 1;
            else
            {
                if (strcmpi(maquina.cartas[i].carta, "MENOS_2") == 0)
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
        if(maquina.puntos > 7)
        {
            while(i<3)
            {
                if(strcmpi(maquina.cartas[i].carta, "MAS_1") == 0)
                    pos[i] = 1;
                else
                {
                    if (strcmpi(maquina.cartas[i].carta, "MAS_2") == 0)
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

int buscarValor(int pos[], int valor)
{
    int i = 0;

    while(i < 3)
    {
        if(pos[i] == valor)
            return i;

        i++;
    }

    return -1;
}

// dificultad media

int elegirCartaDificil(tJugador jugador,tMaquina maquina,char UltimacartaJugador[])
{

    int i=0,posUno,posDos,posCero,pos[3]= {0,0,0},cartaBuena=0,vecBuenas[3]={0,0,0};


    while(i<3)
    {

        if(strcmp(maquina.cartas[i].carta,"ESPEJO")==0)

        {

            pos[i]=1;


        }



        if(strcmp(maquina.cartas[i].carta,"REPETIR")==0)
                {

                    pos[i]= 2;

                }


        if(strcmp(maquina.cartas[i].carta,"MAS_2")==0)
        {
            vecBuenas[cartaBuena++]=i;
            cartaBuena++;

        }

        if(strcmp(maquina.cartas[i].carta,"MAS_1")==0)
        {   vecBuenas[cartaBuena++]=i;
            cartaBuena++;
        }
    i++;
    }

    if(strcmp(UltimacartaJugador,"MENOS_1")==0 || strcmp(UltimacartaJugador,"MENOS_2")==0)
    {

        posCero = buscarValor(pos,1);
        if(posCero!=-1)
        {
            return posCero; //Uso carta ESPEJO.
        }
    }


    if(cartaBuena > 1 )
    {


        posUno = buscarValor(pos,2);
        if(posUno != -1)
        {

            return posUno; // Uso REPETIR carta.
        }
        }
    //for(i=0;i<3;i++)
    //{
    //    pos[i]=0;
    //}


        if(jugador.puntos>7)
        {
            i=0;
            while(i<3)
            {


                if(strcmp(maquina.cartas[i].carta,"REPETIR")==0)
                {

                    pos[i]= 1;

                }
                if(strcmp(maquina.cartas[i].carta,"MENOS_2")==0)
                {
                    pos[i]=2;
                }

                if(strcmp(maquina.cartas[i].carta,"MENOS_1")==0)
                {

                    pos[i]=3;

                }



                i++;

            }


            posCero = buscarValor(pos,1); //REPETIR.

            if(posCero != -1 )
            {
                return posCero;
            }

            posUno = buscarValor(pos,2); //MENOS_2.

            if(posUno != -1)
            {
                return posUno;
            }

            posDos = buscarValor(pos,3); //MENOS_1.

            if(posDos != -1)
            {
                return posDos;
            }


            }



if(cartaBuena>=1)
        {
            posUno = buscarValor(pos,2);
            if(posUno!=-1)
            {
                return posUno;
            }



            return vecBuenas[rand() % cartaBuena]; //Jugar alguna carta buena si no tengo otra opcion.

        }


     return rand()%3;
        //Jugar cualquiera si no encuentro nada.
    }
//Dificultad Dificil.

