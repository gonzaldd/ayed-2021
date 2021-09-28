#ifndef USUARIO_H
#define USUARIO_H

#include "Domicilio/domicilio.h"
#include "Nombre/nombre.h"

#define LINEA "--------------------------------------------------------------------------------------------------------------"

typedef struct {
    std::string sID;
    Nombre* enNombre;
    Domicilio* edDomicilio;
    int iEdad;
} Usuario;

//------------------------------------------------------------------------Constructor------------------------------------------------------------------------
Usuario* crearUsuario(std::string sID, std::string sNombre, std::string sApellido, std::string sDireccion,
        std::string sLocalidad, std::string sProvincia, int iEdad);

//-----------------------------------------------------------------------Mostrar todo------------------------------------------------------------------------
void mostrarUsuario(Usuario*);

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------
void setNombreUsuario(Usuario*, std::string, void setDatoNombre(Nombre*, std::string));
void setDomicilioUsuario(Usuario*, std::string, void setDatoDomicilio(Domicilio*, std::string));
void setEdadUsuario(Usuario*, int);

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------
std::string getID(Usuario*);
std::string getNombreUsuario(Usuario*, std::string getDatoNombre(Nombre*));
std::string getDomicilioUsuario(Usuario*, std::string getDatoDomicilio(Domicilio*));
int getEdadUsuario(Usuario*);

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------
void destruirUsuario(Usuario*);

#endif /* USUARIO_H */

