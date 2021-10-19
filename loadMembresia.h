#ifndef LOADMEMBRESIA_H_INCLUDED
#define LOADMEMBRESIA_H_INCLUDED
#include <iostream>
#include "ED/lista.h"

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
std::string getIDVino1DeLaMembresia(Membresia*);
std::string getIDVino2DeLaMembresia(Membresia*);
std::string getIDVino3DeLaMembresia(Membresia*);
std::string getIDVino4DeLaMembresia(Membresia*);
std::string getIDVino5DeLaMembresia(Membresia*);
std::string getIDVino6DeLaMembresia(Membresia*);

struct DatoRanking {
    std::string id_vino;
    int contador = 0;
};


/*
  pre : lista fue creada con crearLista().
  post: Si el path es correcto, se leera linea a linea para extraer sus datos,
        creando una membresia por cada una y se la agregará a la lista.

  path : Ubicación del archivo.
  lista : lista donde se almacenaran los datos.
*/
void readFileAndLoad(std::string path, Lista *lista);

/*
  pre : str debe contener los datos necesarios para cargar una membresia.
  post: Se limpia y separa str en cada uno de los datos para la membresia.

  str : Cadena a la cual se va a quitar espacios, tabs y luego separarla.
  del : Cadena que separa los datos de str.
  return Array[8] string con los datos de la membresia
*/

void showMembresiaList(Lista *lista);

void rankingVinosUltimoAnio(Lista *listaAnioMembresias);

#endif // LOADMEMBRESIA_H_INCLUDED
