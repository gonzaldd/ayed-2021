#include <iostream>
#include "Rankings.h"
#include "Lista.h"
#include "Vino.h"


using namespace std;

RankingVinos buscarVino(Lista lista,int idVino){
    Nodo aux=lista->inicio;
    int encontrado=0;
    while(aux!=NULL && encontrado==0){
        RankingVinos ranking=(RankingVinos) aux->dato;
        Vino vino=ranking->vino;
        if(vino->idVino==idVino){
            encontrado=1;
        }else{
            aux=aux->siguiente;
        }
    }
    if(encontrado==1){
        return (RankingVinos)aux->dato;
    }else{
        return NULL;
    }
}

Bodega buscarBodega(Lista lista,char nombre[50])
{
    Nodo aux=lista->inicio;
    int encontrado=0;
    while(aux!=NULL && encontrado==0)
    {
        Bodega bodega=(Bodega) aux->dato;
        if(strcmp(bodega->nombreBodega,nombre)==0)
        {
            encontrado=1;
        }
        else
        {
            aux=aux->siguiente;
        }
    }
    if(encontrado==1)
    {
        return (Bodega)aux->dato;
    }
    else
    {
        return NULL;
    }
}
