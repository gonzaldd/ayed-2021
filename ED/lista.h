#ifndef LISTA_H
#define LISTA_H

#include "Nodo/Nodo.h"

struct Lista {
    Nodo* inicio;
    int iTamanio_Lista;
};

//-----------------------------------------------------------Constructor-------------------------------------------------------
/*
    PRE: La lista no debe haber sido creada.
    POST: La lista queda creada y el tamanio de la lista queda seteado en 0.
*/
Lista* crearLista();

//-------------------------------------------------------------Getter-----------------------------------------------------------
/*
    PRE: La lista debe haber sido creada.
    POST: Devuelve el dato contenido en el iTamanio_Lista de la lista.
*/
int getCantidadDeElementosEnLaLista(Lista*);

//-----------------------------------------------------Funciones de la lista---------------------------------------------------
/*
    PRE: La lista debe haber sido creada.
    POST: La lista queda vacia y de tamanio 0.
*/
void vaciarLista(Lista*&);

/*
    PRE: La lista debe haber sido creada.
    POST: Indica si la lista tiene o no elementos que la conpongan.
*/
bool listaEstaVacia(Lista*);

/*
    PRE: La lista debe haber sido creada.
    POST: Busca un elemento en la lista y me indica en que posicion se encuetra.
*/
int posicionElementoEnLaLista(Lista*, ELEMENTO);

/*
    PRE: La lista debe haber sido creada.
    POST: Agrego al inicio de la lista 1 elemento.
*/
void insertarElementoAlInicioDeLaLista(Lista*&, ELEMENTO);

/*
    PRE: La lista debe haber sido creada.
    POST: Agrego 1 elemento a la lista en la posicion indicada si es que existe.
*/
void insertarElementoALaLista(Lista*&, int iPosicion, ELEMENTO);

/*
    PRE: La lista debe haber sido creada.
    POST: Agrego 1 elemento al final de la lista.
*/
void insertarElementoAlFinalDeLaLista(Lista*&, ELEMENTO);

/*
    PRE: La lista debe haber sido creada.
    POST: Almaceno en una variable el ELEMENTO que poseo en el inicio de la lista.
*/
void obtenerElementoInicialDeLaLista(Lista*, ELEMENTO&);

/*
    PRE: La lista debe haber sido creada.
    POST: Almaceno en una variable el ELEMENTO que poseo en una posicion indicada de la lista si es que existe.
*/
void obtenerElementoDeLaLista(Lista* &, int iPosicion, ELEMENTO&);

/*
    PRE: La lista debe haber sido creada.
    POST: Almaceno en una variable el ELEMENTO que poseo al final de la lista.
*/
void obtenerElementoFinalDeLaLista(Lista* &, ELEMENTO&);

/*
    PRE: La lista debe haber sido creada.
    POST: Remuevo y almaceno en una variable el ELEMENTO que poseo en el inicio de la lista.
*/
void eliminarElementoInicialDeLaLista(Lista*&, ELEMENTO&);

/*
    PRE: La lista debe haber sido creada.
    POST: Remuevo y almaceno en una variable el ELEMENTO que poseo en una posicion indicada de la lista si es que existe.
*/
void eliminarElementoDeLaLista(Lista*&, int iPosicion, ELEMENTO&);

/*
    PRE: La lista debe haber sido creada.
    POST: Remuevo y almaceno en una variable el ELEMENTO que poseo al final de la lista.
*/
void eliminarElementoFinalDeLaLista(Lista*&, ELEMENTO&);

#endif // !LISTA_H