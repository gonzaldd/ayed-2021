/*#ifndef RANKINGS_H_INCLUDED
#define RANKINGS_H_INCLUDED
#include "Vino.h"
#include "Lista.h"

struct RankingsStruct{
    int posicion;
    int cantidadV;
    Vino vino;
};
typedef struct RankingsStruct* Rankings;

void rankingPorVinos (Lista  membresia,Lista vinos);

Rankings buscarVino(Lista lista,int idVino);

//Estructura que guarda el nombre de una bodega y la lista de vinos que contiene

typedef struct BodegaStruct{
    char nombreBodega[50];
    int cant;
}*Bodega;

//Función que crea una lista de bodegas.
//Faltaria leer catalogo.txt

void lstBodegas(Lista catalogo, Lista info);

Bodega buscarBodega(Lista lista,char nombre[50]);
#endif*/
