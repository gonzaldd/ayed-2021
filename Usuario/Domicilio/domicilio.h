#ifndef DOMICILIO_H
#define DOMICILIO_H

typedef struct {
    std::string sProvincia;
    std::string sLocalidad;
    std::string sDireccion;
} Domicilio;

//-----------------------------------------------------------------------Constructor-----------------------------------------------------------------------
/*
    PRE: El domicilio no debe haber sido creado.
    POST: El domicilio queda creado.
*/
Domicilio* crearDomicilio(std::string sProvincia, std::string sLocalidad, std::string sDireccion);

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------
/*
    PRE: El domicilio debe haber sido creado.
    POST: El campo provincia pasa a contener el dato ingresado.
*/
void setProvincia(Domicilio*, std::string);

/*
    PRE: El domicilio debe haber sido creado.
    POST: El campo localidad pasa a contener el dato ingresado.
*/
void setLocalidad(Domicilio*, std::string);

/*
    PRE: El domicilio debe haber sido creado.
    POST: El campo dirección pasa a contener el dato ingresado.
*/
void setDireccion(Domicilio*, std::string);

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------
/*
    PRE: El domicilio debe haber sido creado.
    POST: Devuelve el dato contenido en el campo provincia.
*/
std::string getProvincia(Domicilio*);

/*
    PRE: El domicilio debe haber sido creado.
    POST: Devuelve el dato contenido en el campo localidad.
*/
std::string getLocalidad(Domicilio*);

/*
    PRE: El domicilio debe haber sido creado.
    POST: Devuelve el dato contenido en el campo dirección.
*/
std::string getDireccion(Domicilio*);

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------
/*
    PRE: El domicilio debe haber sido creado.
    POST: El domicilio es eliminado.
*/
void destruirDomicilio(Domicilio*);

#endif /* DOMICILIO_H */

