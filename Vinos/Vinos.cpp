#include <iostream>

#include "Vinos.h"

using namespace std;

eVinos* crearVino(string id, string bodega, string etiqueta, string varietal, string seg_vino, int anio, string terroir){
    eVinos* marca = new eVinos();
    
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
    cout << "Vino ID: " << getId(Marca) << endl;
    cout << "\tEtiqueta: " << getEtiqueta(Marca) << endl;
    cout << "\tBodega: " << getBodega(Marca) << endl;
    cout << "\tSegmento del vino: " << getSeg_vino(Marca) << endl;
    cout << "\tVarietal: " << getVarietal(Marca) << endl;
    cout << "\tAño de cosecha: " << getAnio_cosecha(Marca) << endl;
    cout << "\tTerroir: " << getTerroir(Marca) << endl;
}

string getId(eVinos* vinos){
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





