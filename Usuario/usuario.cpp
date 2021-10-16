#include <iostream>

#include "usuario.h"

//-------------------------------------------------------------------------Constructor------------------------------------------------------------------------

Usuario* crearUsuario(std::string sID, std::string sNombre, std::string sApellido, std::string sDireccion,
        std::string sLocalidad, std::string sProvincia, int iEdad) {
    Usuario* u = new Usuario();

    u->sID = sID;
    u->enNombre = crearNombre(sApellido, sNombre);
    u->edDomicilio = crearDomicilio(sProvincia, sLocalidad, sDireccion);
    setEdadUsuario(u, iEdad);

    return u;
}

//-----------------------------------------------------------------------Mostrar todo------------------------------------------------------------------------

void mostrarUsuario(Usuario* u) {
    std::cout << "ID: " << getID(u) << std::endl;
    std::cout << "\tNombre: " << getApellido(u->enNombre) << ", " << getNombre(u->enNombre) << std::endl;

    std::cout << "\tDomicilio: " << getDireccion(u->edDomicilio) << ", ";
    if (getProvincia(u->edDomicilio) == "CABA Buenos Aires" || getProvincia(u->edDomicilio) == "Ciudad Autónoma de Buenos Aires" || getProvincia(u->edDomicilio) == "CABA" || getProvincia(u->edDomicilio) == "Ciudad de Buenos Aires") {
        std::cout << getProvincia(u->edDomicilio) << std::endl;
    } else
        std::cout << getLocalidad(u->edDomicilio) << ", " << getProvincia(u->edDomicilio) << std::endl;

    std::cout << "\tEdad del usuario: " << getEdadUsuario(u) << std::endl;
    std::cout << LINEA << std::endl;
}

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------
void setNombreUsuario(Usuario* u, std::string sDatoAModificar, void setDatoNombre(Nombre*, std::string)) {
    setDatoNombre(u->enNombre, sDatoAModificar);
}

void setDomicilioUsuario(Usuario* u, std::string sDatoAModificar, void setDatoDomicilio(Domicilio*, std::string)) {
    setDatoDomicilio(u->edDomicilio, sDatoAModificar);
}

void setEdadUsuario(Usuario* u, int iEdad) {
    u->iEdad = iEdad;
}

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------

std::string getID(Usuario* u) {
    return u->sID;
}

std::string getNombreUsuario(Usuario* u, std::string getDatoNombre(Nombre*)) {
    return getDatoNombre(u->enNombre);
}

std::string getDomicilioUsuario(Usuario* u, std::string getDatoDomicilio(Domicilio*)) {
    return getDatoDomicilio(u->edDomicilio);
}

int getEdadUsuario(Usuario* u) {
    return u->iEdad;
}

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------

void destruirUsuario(Usuario* u) {
    destruirNombre(u->enNombre);
    destruirDomicilio(u->edDomicilio);
    delete u;
}