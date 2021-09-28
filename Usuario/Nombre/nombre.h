#ifndef NOMBRE_H
#define NOMBRE_H

typedef struct {
    std::string sApellido;
    std::string sNombre;
} Nombre;

//-----------------------------------------------------------------------Constructor-----------------------------------------------------------------------
Nombre* crearNombre(std::string sApellido, std::string sNombre);

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------
void setApellido(Nombre*, std::string);
void setNombre(Nombre*, std::string);

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------
std::string getApellido(Nombre*);
std::string getNombre(Nombre*);

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------
void destruirNombre(Nombre*);


#endif /* NOMBRE_H */

