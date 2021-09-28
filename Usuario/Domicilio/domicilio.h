#ifndef DOMICILIO_H
#define DOMICILIO_H

typedef struct {
    std::string sProvincia;
    std::string sLocalidad;
    std::string sDireccion;
} Domicilio;

//-----------------------------------------------------------------------Constructor-----------------------------------------------------------------------
Domicilio* crearDomicilio(std::string sProvincia, std::string sLocalidad, std::string sDireccion);

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------
void setProvincia(Domicilio*, std::string);
void setLocalidad(Domicilio*, std::string);
void setDireccion(Domicilio*, std::string);

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------
std::string getProvincia(Domicilio*);
std::string getLocalidad(Domicilio*);
std::string getDireccion(Domicilio*);

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------
void destruirDomicilio(Domicilio*);

#endif /* DOMICILIO_H */

