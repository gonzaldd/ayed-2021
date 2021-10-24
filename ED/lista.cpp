#include <iostream>

#include "lista.h"

//-----------------------------------------------------------Constructor-------------------------------------------------------

Lista* crearLista() {
    Lista* l = new Lista();

    l->inicio = NULL;
    l->iTamanio_Lista = 0;

    return l;
}

//-------------------------------------------------------------Getter-----------------------------------------------------------

int getCantidadDeElementosEnLaLista(Lista* l) {
    return l->iTamanio_Lista;
}

//-----------------------------------------------------Funciones de la lista---------------------------------------------------

void vaciarLista(Lista*& l) {
    vaciarLista(l->inicio);
    l->iTamanio_Lista = 0;
}

bool listaEstaVacia(Lista* l) {
    return listaVacia(l->inicio);
}

int posicionElementoEnLaLista(Lista* l, ELEMENTO dato) {
    return buscarElemento(l->inicio, dato);
}

/*
    PRE: La lista debe haber sido creada.
    POST: Indica si la posicion indicada existe o no en la lista.
 */
bool existePosicion(Lista* l, int iPosicion) {
    return ((iPosicion >= 0) && (iPosicion < (l->iTamanio_Lista))) ? true : false;
}

void insertarElementoAlInicioDeLaLista(Lista*& l, ELEMENTO dato) {
    insertarAlInicio(l->inicio, dato);
    l->iTamanio_Lista++;
}

void insertarElementoALaLista(Lista*& l, int iPosicion, ELEMENTO dato) {
    if (existePosicion(l, iPosicion)) {
        insertarElementoEnPosicion(l->inicio, iPosicion, dato);
        l->iTamanio_Lista++;
    } else
        std::cout << "\nNo se puede cargar el dato en la posicion solicitada\n";
}

void insertarElementoAlFinalDeLaLista(Lista*& l, ELEMENTO dato) {
    insertarElementoEnPosicion(l->inicio, l->iTamanio_Lista, dato);
    l->iTamanio_Lista++;
}

void obtenerElementoInicialDeLaLista(Lista* l, ELEMENTO &dato) {
    obtenerElemento(l->inicio, 0, dato);
}

void obtenerElementoDeLaLista(Lista* &l, int iPosicion, ELEMENTO &dato) {
    if (existePosicion(l, iPosicion) && !listaEstaVacia(l)) {
        obtenerElemento(l->inicio, iPosicion, dato);
    } else {
        std::cout << "\nNo hay datos...\n";
        dato = NULL;
    }
}

void obtenerElementoFinalDeLaLista(Lista* &l, ELEMENTO &dato) {
    if (existePosicion(l, (l->iTamanio_Lista) - 1) && !listaEstaVacia(l)) {
        obtenerElemento(l->inicio, (l->iTamanio_Lista) - 1, dato);
    } else {
        std::cout << "\nNo hay datos...\n";
        dato = NULL;
    }
}

void eliminarElementoInicialDeLaLista(Lista*& l, ELEMENTO &dato) {
    if (!listaEstaVacia(l)) {
        quitarElementoDelInicio(l->inicio, dato);
        l->iTamanio_Lista--;
    } else {
        std::cout << "\nNo hay datos...\n";
        dato = NULL;
    }
}

void eliminarElementoDeLaLista(Lista*& l, int iPosicion, ELEMENTO &dato) {
    if (existePosicion(l, iPosicion) && !listaEstaVacia(l)) {
        quitarElementoDePosicion(l->inicio, iPosicion, dato);
        l->iTamanio_Lista--;
    } else {
        std::cout << "\nNo hay datos...\n";
        dato = NULL;
    }
}

void eliminarElementoFinalDeLaLista(Lista*& l, ELEMENTO &dato) {
    if (existePosicion(l, (l->iTamanio_Lista) - 1) && !listaEstaVacia(l)) {
        quitarElementoDePosicion(l->inicio, (l->iTamanio_Lista) - 1, dato);
        l->iTamanio_Lista--;
    } else {
        std::cout << "\nNo hay datos...\n";
        dato = NULL;
    }
}

void mostrarElementosDeLaLista(Lista* l, void mostrarDatos(Lista*, int)) {
    for (int i = 0; i < getCantidadDeElementosEnLaLista(l); i++) {
        mostrarDatos(l, i);
    }
}

void invertirElementos(Lista* lista, int iPosicion1, int iPosicion2) {
    if (iPosicion1 != iPosicion2 && existePosicion(lista, iPosicion1) && existePosicion(lista, iPosicion2)) {
        int iAux;

        if (iPosicion1 > iPosicion2) {
            iAux = iPosicion1;
            iPosicion1 = iPosicion2;
            iPosicion2 = iAux;
        }

        ELEMENTO elemento1, elemento2;

        obtenerElementoDeLaLista(lista, iPosicion1, elemento1);
        obtenerElementoDeLaLista(lista, iPosicion2, elemento2);

        insertarElementoALaLista(lista, iPosicion2, elemento1);
        insertarElementoALaLista(lista, iPosicion1, elemento2);

        eliminarElementoDeLaLista(lista, iPosicion1 + 1, elemento1);
        eliminarElementoDeLaLista(lista, iPosicion2 + 1, elemento2);
    }
}

void reordenarLista(Lista* lista, int comparar(Lista*, int iPosicion1, int iPosicion2)) {
    int iTamanio = getCantidadDeElementosEnLaLista(lista), iComparacion;

    for (int i = 0; i < iTamanio; i++) {

        for (int j = (i + 1); j < iTamanio; j++) {

            iComparacion = comparar(lista, i, j);
            if (iComparacion == MAYOR)
                invertirElementos(lista, i, j);

        }
    }
}

void destruirLista(Lista* l, void eliminarDatos(int, Lista*)){
    for (int i = 0; i < getCantidadDeElementosEnLaLista(l); i++) {
        eliminarDatos(i, l);
    }
    delete l;
}