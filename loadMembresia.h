#ifndef LOADMEMBRESIA_H_INCLUDED
#define LOADMEMBRESIA_H_INCLUDED
#include <iostream>
#include "ED/lista.h"
#include <string.h>

#ifndef CANT_SELECCION
#define CANT_SELECCION 6
#endif // !CANT_SELECCION

struct Membresia {
    std::string id_usuario;
    std::string mes;
    std::string anio;
    std::string id_vino_1;
    std::string id_vino_2;
    std::string id_vino_3;
    std::string id_vino_4;
    std::string id_vino_5;
    std::string id_vino_6;
};


std::string getIDDelUsuarioDeLaMembresia(Membresia*);
std::string getIDVinoDeLaMembresia(Membresia*, int);

/*
  pre : lista fue creada con crearLista().
  post: Si el path es correcto, se leera linea a linea para extraer sus datos,
        creando una membresia por cada una y se la agregará a la lista.

  path : Ubicación del archivo.
  lista : lista donde se almacenaran los datos.
*/
void readFileAndLoad(std::string path, Lista *lista);

/*
  pre : lista fue creada con crearLista().
  post: se muestra en pantalla el contenido de una lista de membresias.

  lista : lista donde se encuentran los datos cargados.
*/
void showMembresiaList(Lista *lista);

/*
    PRE: Deben existir la lista de membresias.
    POST: devuelve el año del primer nodo de la lista anidada.
 */
std::string getYearOfList(void *lista);

#endif // LOADMEMBRESIA_H_INCLUDED
