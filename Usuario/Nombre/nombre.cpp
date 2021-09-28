#include <iostream>

#include "nombre.h"

//-----------------------------------------------------------------------Constructor-----------------------------------------------------------------------

Nombre* crearNombre(std::string sApellido, std::string sNombre) {
    Nombre* n = new Nombre();

    setApellido(n, sApellido);
    setNombre(n, sNombre);

    return n;
}

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------

void setApellido(Nombre* n, std::string sApellido) {
    n->sApellido = sApellido;
}

void setNombre(Nombre* n, std::string sNombre) {
    n->sNombre = sNombre;
}

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------

std::string getApellido(Nombre* n) {
    return n->sApellido;
}

std::string getNombre(Nombre* n) {
    return n->sNombre;
}

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------

void destruirNombre(Nombre* n) {
    delete n;
}