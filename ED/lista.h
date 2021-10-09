#ifndef LISTA_H
#define LISTA_H

#include "Nodo/Nodo.h"

struct Lista
{
	Nodo* inicio;
	int iTamanio_Lista;
};

Lista* crearLista();

int getCantidadDeElementosEnLaLista(Lista*);

//Funciones de la lista:
void vaciarLista(Lista*&);
bool listaEstaVacia(Lista*);
int posicionElementoEnLaLista(Lista*, ELEMENTO);

void insertarElementoAlInicioDeLaLista(Lista*&, ELEMENTO);
void insertarElementoALaLista(Lista*&, int iPosicion, ELEMENTO);
void insertarElementoAlFinalDeLaLista(Lista*&, ELEMENTO);

void obtenerElementoInicialDeLaLista(Lista*, ELEMENTO&);
void obtenerElementoDeLaLista(Lista* &, int iPosicion, ELEMENTO&);
void obtenerElementoFinalDeLaLista(Lista* &, ELEMENTO&);

void eliminarElementoInicialDeLaLista(Lista*&, ELEMENTO&);
void eliminarElementoDeLaLista(Lista*&, int iPosicion, ELEMENTO&);
void eliminarElementoFinalDeLaLista(Lista*&, ELEMENTO&);

#endif // !LISTA_H