#ifndef VINOS_H_INCLUDED
#define VINOS_H_INCLUDED

typedef struct {
    std::string id;
    std::string bodega;
    std::string etiqueta;
    std::string varietal;
    std::string seg_vino; //segmento del vino
    int anio_cosecha;
    std::string terroir; //es el tipo de tierra en la cual crece el vino
} eVinos;

/*------------------------------------------------------------------------Constructor------------------------------------------------------------------------
    PRE: El vino no debe haber sido creado.
    POST: El vino queda creado.
*/
eVinos* crearVino(std::string id, std::string bodega, std::string etiqueta, std::string varietal, std::string seg_vino, int anio, std::string terroir);

/*-----------------------------------------------------------------------Mostrar todo------------------------------------------------------------------------
    PRE: El vino debe haber sido creado.
    POST: Muestro los datos del vino creado.
*/
void mostrarVino(eVinos* Marca);

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------
/*
    PRE: El vino debe haber sido creado.
    POST: Devuelve el dato contenido en el ID del vino.
*/
std::string getId(eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: Devuelve el dato contenido en la bodega del vino.
*/
std::string getBodega(eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: Devuelve el dato contenido en la etiqueta del vino.
*/
std::string getEtiqueta(eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: Devuelve el dato contenido en el varietal del vino.
*/
std::string getVarietal(eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: Devuelve el dato contenido en el seg_vino del vino.
*/
std::string getSeg_vino(eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: Devuelve el dato contenido en el anio_cosecha del vino.
*/
int getAnio_cosecha(eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: Devuelve el dato contenido en el terroir del vino.
*/
std::string getTerroir(eVinos* vinos);

//---------------------------------------------------------------------------Setters----------------------------------------------------------------------------
/*
    PRE: El vino debe haber sido creado.
    POST: El nombre del vino es modificado por el dato ingresado en la bodega segun se indique.
*/
void setBodega(std::string bodega, eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: El nombre del vino es modificado por el dato ingresado en la etiqueta segun se indique.
*/
void setEtiqueta(std::string etiqueta, eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: El nombre del vino es modificado por el dato ingresado en el varietal segun se indique.
*/
void setVarietal(std::string varietal, eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: El nombre del vino es modificado por el dato ingresado en el seg_vino segun se indique.
*/
void setSeg_vino(std::string seg_vino, eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: El nombre del vino es modificado por el dato ingresado en el anio_cosecha segun se indique.
*/
void setAnio_cosecha(int anio_cosecha, eVinos* vinos);

/*
    PRE: El vino debe haber sido creado.
    POST: El nombre del vino es modificado por el dato ingresado en el terroir segun se indique.
*/
void setTerroir(std::string terroir, eVinos* vinos);

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------
/*
    PRE: El vino debe haber sido creado.
    POST: El vino es eliminado.
*/
void destructorVino(eVinos* vinos);

#endif // VINOS_H_INCLUDED
