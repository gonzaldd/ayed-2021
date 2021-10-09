#ifndef NODO_H
#define NODO_H

#ifndef  NO_ECONTRADO
#define NO_ENCONTRADO -1
#endif // ! NO_ECONTRADO

#ifndef LINEA
#define LINEA "--------------------------------------------------------------------------------------------------------------"
#endif // !LINEA

typedef void* ELEMENTO;

struct Nodo
{
	ELEMENTO dato;
	Nodo* siguiente;
};

void insertarAlInicio(Nodo*&, ELEMENTO);
void insertarAlFinal(Nodo*&, ELEMENTO);
void insertarElementoEnPosicion(Nodo* &, int iPosicion, ELEMENTO dato);
int buscarElemento(Nodo*, ELEMENTO);
void obtenerElemento(Nodo*, int iPosicion, ELEMENTO&);
void quitarElementoDelInicio(Nodo*&, ELEMENTO&);
void quitarElementoDePosicion(Nodo*&, int iPosicion, ELEMENTO &);

void vaciarLista(Nodo*&);
bool listaVacia(Nodo*);

#endif // !NODO_H
