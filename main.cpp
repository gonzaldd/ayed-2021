#include "loadMembresia.h"


using namespace std;

int main() {

    Lista *listaMembresia = crearLista();

    readFileAndLoad("elecion_test.txt", listaMembresia);

    cout << "Cantidad de años insertados: " << getCantidadDeElementosEnLaLista(listaMembresia) << endl;

    Nodo *iterateList = (Nodo*)listaMembresia->inicio;
    while(iterateList) {
        cout << "Año: " << getInnerMembresia(iterateList)->anio << " " << getCantidadDeElementosEnLaLista((Lista*)iterateList->dato) << endl;
        iterateList = iterateList->siguiente;
    }

    return 0;
}

