#include <iostream>

#include "domicilio.h"

//-----------------------------------------------------------------------Constructor-----------------------------------------------------------------------

Domicilio* crearDomicilio(std::string sProvincia, std::string sLocalidad, std::string sDireccion) {
    Domicilio* d = new Domicilio();

    setProvincia(d, sProvincia);
    setLocalidad(d, sLocalidad);
    setDireccion(d, sDireccion);

    return d;
}

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------

void setProvincia(Domicilio* d, std::string sProvincia) {
    d->sProvincia = sProvincia;
}

void setLocalidad(Domicilio* d, std::string sLocalidad) {
    d->sLocalidad = sLocalidad;
}

void setDireccion(Domicilio* d, std::string sDireccion) {
    d->sDireccion = sDireccion;
}

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------

std::string getProvincia(Domicilio* d) {
    return d->sProvincia;
}

std::string getLocalidad(Domicilio* d) {
    return d->sLocalidad;
}

std::string getDireccion(Domicilio* d) {
    return d->sDireccion;
}

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------

void destruirDomicilio(Domicilio* d) {
    delete d;
}