#include <iostream>

#include "pila.h"

//-----------------------------------------------------------Constructor-------------------------------------------------------
Pila* crearPila() {
	Pila* p = new Pila();

	p->inicio = NULL;
	p->iTamanio_Pila = 0;

	return p;
}

//-------------------------------------------------------------Getter-----------------------------------------------------------
int getCantidadDeElementosEnLaPila(Pila* pila) {
	return pila->iTamanio_Pila;
}

//-----------------------------------------------------Funciones de la pila---------------------------------------------------
void vaciarPila(Pila* &pila) {
	vaciarLista(pila->inicio);
	pila->iTamanio_Pila = 0;
}

bool pilaEstaVacia(Pila* pila) {
	return listaVacia(pila->inicio);
}

int posicionElementoDeLaPila(Pila* pila, ELEMENTO dato) {
	return buscarElemento(pila->inicio, dato);
}

void insertarElementoALaPila(Pila* &pila, ELEMENTO dato) {
	insertarAlInicio(pila->inicio, dato);
	pila->iTamanio_Pila++;
}

void obtenerElementoDeLaPila(Pila* pila, ELEMENTO &dato) {
	if (!pilaEstaVacia(pila)) {
		obtenerElemento(pila->inicio, 0, dato);
	}
}

void eliminarElementoDeLaPila(Pila* &pila, ELEMENTO &dato) {
	if (!pilaEstaVacia(pila)) {
		quitarElementoDelInicio(pila->inicio, dato);
		pila->iTamanio_Pila--;
	}
}