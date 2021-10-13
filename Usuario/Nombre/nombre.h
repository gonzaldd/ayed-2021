#ifndef NOMBRE_H
#define NOMBRE_H

typedef struct {
    std::string sApellido;
    std::string sNombre;
} Nombre;

//-----------------------------------------------------------------------Constructor-----------------------------------------------------------------------
/*
    PRE: El nombre no debe haber sido creado.
    POST: El nombre queda creado.
*/
Nombre* crearNombre(std::string sApellido, std::string sNombre);

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------
/*
    PRE: El nombre debe haber sido creado.
    POST: El campo apellido pasa a contener el dato ingresado.
*/
void setApellido(Nombre*, std::string);

/*
    PRE: El nombre debe haber sido creado.
    POST: El campo nombre pasa a contener el dato ingresado.
*/
void setNombre(Nombre*, std::string);

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------
/*
    PRE: El nombre debe haber sido creado.
    POST: Devuelve el dato contenido en el campo apellido.
*/

std::string getApellido(Nombre*);

/*
    PRE: El nombre debe haber sido creado.
    POST: Devuelve el dato contenido en el campo nombre.
*/
std::string getNombre(Nombre*);

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------
/*
    PRE: El nombre debe haber sido creado.
    POST: El nombre es eliminado.
*/
void destruirNombre(Nombre*);


#endif /* NOMBRE_H */

