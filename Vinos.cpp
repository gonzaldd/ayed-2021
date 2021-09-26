#include "Vinos.h"
#include <iostream>

struct eVinos{
    int id;
    std::string bodega;
    string etiqueta;
    string varietal;
    string seg_vino;    //segmento del vino
    int anio_cosecha;
    string terroir;  //es el tipo de tierra en la cual crece el vino
};

typedef struct eVinos* Marca;

Marca crearVino(int id, string bodega, string etiqueta, string varietal, string seg_vino, int anio, string terroir){
    struct eVinos* marca = new eVinos();
    marca->id = id;
    marca->bodega = bodega;
    marca->etiqueta = etiqueta;
    marca->varietal = varietal;
    marca->seg_vino = seg_vino;
    marca->anio_cosecha = anio;
    marca-> terroir = terroir;
    return marca;
}

void mostrarVino(eVinos* Marca){
    int i = 0;
    cout << "Marca de Vino: " << getId(Marca) << getBodega(Marca)  << getEtiqueta(Marca)  << getVarietal(Marca)  << getSeg_vino(Marca)  << getAnio_cosecha(Marca)  << getAnio_cosecha(Marca)  << getTerroir(Marca)  << endl;
}

int getId(eVinos* vinos){
    return vinos->id;
};
string getBodega(eVinos* vinos){
    return vinos->bodega;
};
string getEtiqueta(eVinos* vinos){
    return vinos->etiqueta;
};
string getVarietal(eVinos* vinos){
    return vinos->varietal;
};
string getSeg_vino(eVinos* vinos){
    return vinos->seg_vino;
};
int getAnio_cosecha(eVinos*vinos){
    return vinos->anio_cosecha;
};
string getTerroir(eVinos* vinos){
    return vinos->terroir;
};

void setId(int id, eVinos* vinos){
    vinos->id = id;
};//
void setBodega(string bodega, eVinos* vinos){
    vinos->bodega = bodega;
};
void setEtiqueta(string etiqueta, eVinos* vinos){
    vinos->etiqueta = etiqueta;
};
void setVarietal(string varietal, eVinos* vinos){
    vinos->varietal = varietal;
};
void setSeg_vino(string seg_vino, eVinos* vinos){
    vinos->seg_vino = seg_vino;
};
void setAnio_cosecha(int anio_cosecha, eVinos* vinos){
    vinos->anio_cosecha = anio_cosecha;
};
void setTerroir(string terroir, eVinos* vinos){
    vinos->terroir= terroir;
};
void destructorVino(eVinos* vinos){
    delete vinos;
};





