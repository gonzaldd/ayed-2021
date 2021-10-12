#include <fstream>
#include <algorithm>
#include "loadMembresia.h"

using namespace std;

//Devuelve Membresia de una lista anidada
Membresia* getInnerMembresia(Nodo *nodo) {
    Lista *innerList = (Lista*)nodo->dato;
    Membresia *firstMembresia = (Membresia*)innerList->inicio->dato;

    return firstMembresia;
}


//Crea una nueva lista e inserta una membresia al final
Lista* createNewYearList(Membresia *membresia, Lista* lista) {
    Lista *listaAnio = crearLista();
    insertarElementoAlFinalDeLaLista(listaAnio, membresia);

    return listaAnio;
}



void readFileAndLoad(std::string path, Lista *lista) {
    std::ifstream archivo(path.c_str());
    std::string linea;

    while (getline(archivo, linea)) {
        std::string *valores = splitStrByChar(linea, "-");

        //crear membresia
        Membresia *membresia = new Membresia();

        membresia->id_usuario = valores[0];
        membresia->mes = valores[1];
        membresia->anio = valores[2];
        membresia->id_vino_1 = valores[3];
        membresia->id_vino_2 = valores[4];
        membresia->id_vino_3 = valores[5];
        membresia->id_vino_4 = valores[6];
        membresia->id_vino_5 = valores[7];
        membresia->id_vino_6 = valores[8];

        if(listaEstaVacia(lista)) {
            Lista *yearList = createNewYearList(membresia, lista);
            insertarElementoAlFinalDeLaLista(lista, yearList);
        } else {
            Nodo *iterateList = (Nodo*)lista->inicio;
            bool insertado = false;

            while(iterateList && !insertado) {
                //Si coincide el año, se inserta en esa lista y sale del bucle
                if(membresia->anio.compare(getInnerMembresia(iterateList)->anio) == 0) {
                    Lista *innerList = (Lista*)iterateList->dato;
                    insertarElementoAlFinalDeLaLista(innerList, membresia);
                    insertado = true;
                }
                iterateList = iterateList->siguiente;
            }

            //Si no se produce un insert, crea una nueva lista para ese año y lo agrega a al listado de membresias
            if(!insertado) {
                Lista *yearList = createNewYearList(membresia, lista);
                insertarElementoAlFinalDeLaLista(lista, yearList);
            }
        }
    }
}


//return [id_usuario, mes, anio, id_vino_1, id_vino2, ...]
std::string* splitStrByChar(std::string str, std::string del) {
    int start;
    int endStr;
    int position = 0;
    //limpio los datos de espacios, tabs & ;
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ';'), str.end());

    start = 0;
    endStr = str.find(del);
    //array que contiene los datos separados
    std::string* values = new std::string[9];

    //Separo los datos por el caracter del param del
    while (endStr != -1) {
        values[position] = str.substr(start, endStr - start);
        start = endStr + del.size();
        endStr = str.find(del, start);
        position++;
    }
    values[8] = str.substr(start, endStr - start);

    /*for(int i = 0; i< 9; i++) {
        std::cout << values[i] << " " << std::endl;
        if(i == 9)
            cout << "" << endl;
    }*/

    return values;
}

void showMembresiaList(Lista *listaMembresia){
    Nodo *iterateList = (Nodo*)listaMembresia->inicio;
    while(iterateList) {
        cout << "Año: " << getInnerMembresia(iterateList)->anio << " Cantidad: " << getCantidadDeElementosEnLaLista((Lista*)iterateList->dato) << endl;
        Nodo *iterateInnerNode = (Nodo*)((Lista*)iterateList->dato)->inicio;

        cout << "user\t" << "fecha\t" << "vino1\t" << "vino2\t" << "vino3\t" << "vino4\t" << "vino5\t" << "vino6\t" << endl;
        while(iterateInnerNode) {
            Membresia *membresia = (Membresia*)iterateInnerNode->dato;

            cout << membresia->id_usuario << "\t";
            cout << membresia->mes << "/" << membresia->anio << "\t";
            cout << membresia->id_vino_1 << "\t";
            cout << membresia->id_vino_2 << "\t";
            cout << membresia->id_vino_3 << "\t";
            cout << membresia->id_vino_4 << "\t";
            cout << membresia->id_vino_5 << "\t";
            cout << membresia->id_vino_6 << endl;
            iterateInnerNode = iterateInnerNode->siguiente;
        }

        cout << '\n';
        iterateList = iterateList->siguiente;
    }
}
