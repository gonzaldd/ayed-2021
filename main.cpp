#include <iostream>
#include "Vinos.h"

using namespace std;
//void setId(int id, Vinos* vinos);
int main()
{   eVinos* marca;
    int id = 0, anio = 0;
    string bodega, etiqueta, seg_vino, terroir, varietal;
    cout << "Ingrese el id" << endl;
    cin >> id ;
    cout << "Ingrese el anio" << endl;
    cin >> anio ;
    cout << "Ingrese la bodega" << endl;
    cin >> bodega ;
    cout << "Ingrese la etiqueta" << endl;
    cin >> etiqueta ;
    cout << "Ingrese varietal" << endl;
    cin >> varietal ;
    cout << "Ingrese seg_vino" << endl;
    cin >> seg_vino ;
    cout << "Ingrese terroir" << endl;
    cin >> terroir ;
    //cout << id << endl;
    marca = crearVino(id, bodega, etiqueta, varietal, seg_vino, anio, terroir);
    mostrarVino(marca);

    return 0;
}
//std::cout << "texto" ;
//std::cin = variable o lo que sea donde quiero guardar el input
/*
    Vinos* marca;
    marca = constructor();
    setId(marca, variable donde guarde algo);
*/
