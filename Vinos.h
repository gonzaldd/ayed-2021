#ifndef VINOS_H_INCLUDED
#define VINOS_H_INCLUDED
#include <string>
using namespace std;

//declaro im estructura
struct eVinos;
//declaro mi tipo de dato
typedef struct eVinos* Marca;
//constructor
Marca crearVino(int id, string bodega, string etiqueta, string varietal, string seg_vino, int anio, string terroir);
//imprimir objeto
void mostrarVino(eVinos* Marca);
//Vinos* marca(Vinos *marca)
//gets y setters

int getId(eVinos* vinos);
string getBodega(eVinos* vinos);
string getEtiqueta(eVinos* vinos);
string getVarietal(eVinos* vinos);
string getSeg_vino(eVinos* vinos);
int getAnio_cosecha(eVinos* vinos);
string getTerroir(eVinos* vinos);

void setId(int id, eVinos* vinos);
void setBodega(string bodega, eVinos* vinos);
void setEtiqueta(string etiqueta, eVinos* vinos);
void setVarietal(string varietal, eVinos* vinos);
void setSeg_vino(string seg_vino, eVinos* vinos);
void setAnio_cosecha(int anio_cosecha, eVinos* vinos);
void setTerroir(string terroir, eVinos* vinos);

void destructorVino(eVinos* vinos);

//TODO:
//hacer get y setter de todos los atributo
//hacer un "Catalogo de vinos", esto es un archivo aparte
//hacer un constructor ( asigna un espacio de memoria para mi instancia )
//hacer un destructor
//
#endif // VINOS_H_INCLUDED
