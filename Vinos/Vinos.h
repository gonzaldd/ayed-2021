#ifndef VINOS_H_INCLUDED
#define VINOS_H_INCLUDED

//declaro mi estructura
struct eVinos;
//declaro mi tipo de dato
typedef struct eVinos* Marca;
//constructor
Marca crearVino(int id, std::string bodega, std::string etiqueta, std::string varietal, std::string seg_vino, int anio, std::string terroir);
//imprimir objeto
void mostrarVino(eVinos* Marca);
//Vinos* marca(Vinos *marca)
//gets y setters

int getId(eVinos* vinos);
std::string getBodega(eVinos* vinos);
std::string getEtiqueta(eVinos* vinos);
std::string getVarietal(eVinos* vinos);
std::string getSeg_vino(eVinos* vinos);
int getAnio_cosecha(eVinos* vinos);
std::string getTerroir(eVinos* vinos);

void setBodega(std::string bodega, eVinos* vinos);
void setEtiqueta(std::string etiqueta, eVinos* vinos);
void setVarietal(std::string varietal, eVinos* vinos);
void setSeg_vino(std::string seg_vino, eVinos* vinos);
void setAnio_cosecha(int anio_cosecha, eVinos* vinos);
void setTerroir(std::string terroir, eVinos* vinos);

void destructorVino(eVinos* vinos);

//TODO:
//hacer get y setter de todos los atributo
//hacer un "Catalogo de vinos", esto es un archivo aparte
//hacer un constructor ( asigna un espacio de memoria para mi instancia )
//hacer un destructor
//
#endif // VINOS_H_INCLUDED
