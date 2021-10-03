#ifndef LOADMEMBRESIA_H_INCLUDED
#define LOADMEMBRESIA_H_INCLUDED
#include "Lista.h"
#include <iostream>

/*
  pre : lista fue creada con crearLista().
  post: Si el path es correcto, se leera linea a linea para extraer sus datos,
        creando una membresia por cada una y se la agregará a la lista.

  path : Ubicación del archivo.
  lista : lista donde se almacenaran los datos.
*/
void readFile(std::string path, Lista &lista);

/*
  pre : str debe contener los datos necesarios para cargar una membresia.
  post: Se limpia y separa str en cada uno de los datos para la membresia.

  str : Cadena a la cual se va a quitar espacios, tabs y luego separarla.
  del : Cadena que separa los datos de str.
  return Array[8] string con los datos de la membresia
*/
std::string* splitStrByChar(std::string str, std::string del);

#endif // LOADMEMBRESIA_H_INCLUDED
