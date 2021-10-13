#ifndef USUARIO_H
#define USUARIO_H

#include "Domicilio/domicilio.h"
#include "Nombre/nombre.h"

#ifndef LINEA
#define LINEA "--------------------------------------------------------------------------------------------------------------"
#endif // !LINEA

typedef struct {
    std::string sID;
    Nombre* enNombre;
    Domicilio* edDomicilio;
    int iEdad;
} Usuario;

/*------------------------------------------------------------------------Constructor------------------------------------------------------------------------
    PRE: El usuario no debe haber sido creado.
    POST: El usuaio queda creado.
*/
Usuario* crearUsuario(std::string sID, std::string sNombre, std::string sApellido, std::string sDireccion,
        std::string sLocalidad, std::string sProvincia, int iEdad);

/*-----------------------------------------------------------------------Mostrar todo------------------------------------------------------------------------
    PRE: El usuario debe haber sido creado.
    POST: Muestro los datos del usuario creado.
*/
void mostrarUsuario(Usuario*);

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------
/*
    PRE: El usuario debe haber sido creado.
    POST: El nombre del usuario es modificado por el dato ingresado en el nombre o el apellido segun se indique.
*/
void setNombreUsuario(Usuario*, std::string, void setDatoNombre(Nombre*, std::string));

/*
    PRE: El usuario debe haber sido creado.
    POST: El domicilio del usuario es modificado por el dato ingresado en la dirección, la localidad o la provincia segun se indique.
*/
void setDomicilioUsuario(Usuario*, std::string, void setDatoDomicilio(Domicilio*, std::string));

/*
    PRE: El usuario debe haber sido creado.
    POST: La edad del usuario es modificada por el dato ingresado.
*/
void setEdadUsuario(Usuario*, int);

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------
/*
    PRE: El usuario debe haber sido creado.
    POST: Devuelve el dato contenido en el ID del usuario.
*/
std::string getID(Usuario*);

/*
    PRE: El usuario debe haber sido creado.
    POST: Devuelve el dato contenido en el nombre o el apellido del usuario segun se indique.
*/
std::string getNombreUsuario(Usuario*, std::string getDatoNombre(Nombre*));

/*
    PRE: El usuario debe haber sido creado.
    POST: Devuelve el dato contenido en la dirección, la localidad o la provincia del usuario segun se indique.
*/
std::string getDomicilioUsuario(Usuario*, std::string getDatoDomicilio(Domicilio*));

/*
    PRE: El usuario debe haber sido creado.
    POST: Devuelve el dato contenido en la iEdad del usuario.
*/
int getEdadUsuario(Usuario*);

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------
/*
    PRE: El usuario debe haber sido creado.
    POST: El usuario es eliminado.
*/
void destruirUsuario(Usuario*);

#endif /* USUARIO_H */

