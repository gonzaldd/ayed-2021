#include <fstream>
#include <algorithm>
#include "loadMembresia.h"

using namespace std;

std::string getIDDelUsuarioDeLaMembresia(Membresia* m){
    return m->id_usuario;
}

std::string getIDVino1DeLaMembresia(Membresia* m){
    return m->id_vino_1;
}

std::string getIDVino2DeLaMembresia(Membresia* m){
    return m->id_vino_2;
}

std::string getIDVino3DeLaMembresia(Membresia* m){
    return m->id_vino_3;
}

std::string getIDVino4DeLaMembresia(Membresia* m){
    return m->id_vino_4;
}

std::string getIDVino5DeLaMembresia(Membresia* m){
    return m->id_vino_5;
}

std::string getIDVino6DeLaMembresia(Membresia* m){
    return m->id_vino_6;
}

//Devuelve el año del primer nodo de la lista anidada
string getYearOfList(void *lista) {
    ELEMENTO innerList;
    obtenerElementoInicialDeLaLista((Lista*)lista, innerList);

    return ((Membresia*)innerList)->anio;
}

//Crea una nueva lista e inserta una membresia al final
Lista* createNewYearList(Membresia *membresia, Lista* lista) {
    Lista *listaAnio = crearLista();
    insertarElementoAlFinalDeLaLista(listaAnio, membresia);

    return listaAnio;
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

DatoRanking* findInList(Lista *lista, string id_vino) {
    DatoRanking *encontrado = 0;

    for(int i = 0; i < getCantidadDeElementosEnLaLista(lista) && !(bool)encontrado; i++){
        ELEMENTO voidElement;
        obtenerElementoDeLaLista(lista, i, voidElement);

        if(((DatoRanking*)voidElement)->id_vino.compare(id_vino) == 0)
            encontrado = (DatoRanking*)voidElement;
    }

    return encontrado;
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
            bool insertado = false;

            for(int i = 0; i < getCantidadDeElementosEnLaLista(lista) && !insertado; i++){
                ELEMENTO innerElemento;
                obtenerElementoDeLaLista(lista, i, innerElemento);

                if(membresia->anio.compare(getYearOfList((Lista*)innerElemento)) == 0){
                    Lista *innerList = (Lista*)innerElemento;
                    insertarElementoAlFinalDeLaLista(innerList, membresia);
                    insertado = true;
                }
            }

            if(!insertado) {
                Lista *yearList = createNewYearList(membresia, lista);
                insertarElementoAlFinalDeLaLista(lista, yearList);
            }
        }
    }
}

void showMembresiaList(Lista *listaMembresia) {
    for(int i = 0; i < getCantidadDeElementosEnLaLista(listaMembresia); i++) {
        ELEMENTO innerElemento;
        obtenerElementoDeLaLista(listaMembresia, i, innerElemento);
        Lista *innerList = (Lista*)innerElemento;

        cout << "Año: " << getYearOfList(innerList) << " Cantidad: " << getCantidadDeElementosEnLaLista(innerList) << endl;
        for(int x = 0; x < getCantidadDeElementosEnLaLista(innerList); x++) {
            ELEMENTO membresia;
            obtenerElementoDeLaLista(innerList, x, membresia);

            cout << ((Membresia*)membresia)->id_usuario << "\t";
            cout << ((Membresia*)membresia)->mes << "/" << ((Membresia*)membresia)->anio << "\t";
            cout << ((Membresia*)membresia)->id_vino_1 << "\t";
            cout << ((Membresia*)membresia)->id_vino_2 << "\t";
            cout << ((Membresia*)membresia)->id_vino_3 << "\t";
            cout << ((Membresia*)membresia)->id_vino_4 << "\t";
            cout << ((Membresia*)membresia)->id_vino_5 << "\t";
            cout << ((Membresia*)membresia)->id_vino_6 << endl;
        }
        cout << '\n';
    }
}

void rankingVinosUltimoAnio(Lista *listaAnioMembresias) {
    int maxYear = 0;
    Lista *listaRanking = crearLista();
    Lista *listaMembresias = NULL;


    for(int i = 0; i < getCantidadDeElementosEnLaLista(listaAnioMembresias); i++) {
        ELEMENTO innerList;
        obtenerElementoDeLaLista(listaAnioMembresias, i, innerList);

        if(stoi(getYearOfList(innerList)) > maxYear) {
            maxYear = stoi(getYearOfList(innerList));
            listaMembresias = (Lista*)innerList;
        }
    }

    cout << "Ranking de vinos (" << maxYear << ")" << endl;
    for(int i = 0; i < getCantidadDeElementosEnLaLista(listaMembresias); i++) {
        ELEMENTO membresia;
        obtenerElementoDeLaLista(listaMembresias, i, membresia);

        string idVinoArr[] = {
            ((Membresia*)membresia)->id_vino_1,
            ((Membresia*)membresia)->id_vino_2,
            ((Membresia*)membresia)->id_vino_3,
            ((Membresia*)membresia)->id_vino_4,
            ((Membresia*)membresia)->id_vino_5,
            ((Membresia*)membresia)->id_vino_6
        };

        for(int i = 0; i < 6; i++) {
            if(!findInList(listaRanking, idVinoArr[i])) {
                DatoRanking *vino = new DatoRanking();
                vino->id_vino = idVinoArr[i];
                vino->contador++;

                insertarElementoAlFinalDeLaLista(listaRanking, vino);
            } else {
                DatoRanking *vinoEnRanking = findInList(listaRanking, idVinoArr[i]);
                vinoEnRanking->contador++;
            }
        }
    }

    for(int i = 0; i < getCantidadDeElementosEnLaLista(listaRanking); i++) {
        ELEMENTO vino;
        obtenerElementoDeLaLista(listaRanking, i, vino);
        cout << ((DatoRanking*)vino)->id_vino << " " << ((DatoRanking*)vino)->contador << endl;
    }
}
