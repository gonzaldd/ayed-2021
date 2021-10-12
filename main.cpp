#include "loadMembresia.h"


using namespace std;

int main() {

    Lista *listaMembresia = crearLista();

    readFileAndLoad("elecion_test.txt", listaMembresia);

    showMembresiaList(listaMembresia);

    return 0;
}

