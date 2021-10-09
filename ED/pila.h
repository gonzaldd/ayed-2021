#ifndef PILA_H
#define PILA_H

#include "Nodo/Nodo.h"

struct Pila
{
	Nodo* inicio;
	int iTamanio_Pila;
};

//Crear pila:
Pila* crearPila();

//Getters:
int getCantidadDeElementosEnLaPila(Pila*);

//Funciones de la pila:
void vaciarPila(Pila*&);
bool pilaEstaVacia(Pila*);
int posicionElementoDeLaPila(Pila*, ELEMENTO);
void insertarElementoALaPila(Pila* &, ELEMENTO);
void obtenerElementoDeLaPila(Pila*, ELEMENTO &);
void eliminarElementoDeLaPila(Pila* &, ELEMENTO &);

#endif // !PILA_H
