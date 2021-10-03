#include "Lista.h"
#include "loadMembresia.h"


using namespace std;

int main() {

    Lista listaMembresia;
    crearLista(listaMembresia, 0);

    readFile("elecion_test.txt", listaMembresia);

    return 0;
}

