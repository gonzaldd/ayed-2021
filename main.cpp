#include "loadMembresia.h"


using namespace std;

int main() {

    Lista *listaMembresia = crearLista();

    readFileAndLoad("elecion_test.txt", listaMembresia);

    cout << "Cantidad de años insertados: " << getCantidadDeElementosEnLaLista(listaMembresia) << endl;

    Nodo *iterateList = (Nodo*)listaMembresia->inicio;
    while(iterateList) {
        cout << "\nAño: " << getInnerMembresia(iterateList)->anio << " Cantidad: " << getCantidadDeElementosEnLaLista((Lista*)iterateList->dato) << endl;
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
        iterateList = iterateList->siguiente;
    }

    return 0;
}

