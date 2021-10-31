#include <iostream>

#include "ED/lista.h"
#include "Usuario/usuario.h"
#include "Vinos/Vinos.h"
#include "loadMembresia.h"
#include "cargarArchivosEnLista.h"

#include "marketing.h"

void eliminarDatoUsuario(ELEMENTO);
void eliminarDatoVino(ELEMENTO);

int main(int argc, char** argv) {

    Lista* listaVinosUltimoAnio = 0;
    std::string opcion;

    Lista* lUsuarios = crearLista();
    cargarDatosDeUsuarioEnLaLista("Archivos/usuarios_test.txt", lUsuarios);

    Lista* lCatalogo = crearLista();
    cargarCatalogoDeVinosEnLaLista("Archivos/catalos_test.txt", lCatalogo);

    Lista* lMembresia = crearLista();
    readFileAndLoad("Archivos/elecion_test.txt", lMembresia);

    while(opcion.compare("0") != 0) {
        std::cout << "Ingrese una opción:" << std::endl;
        std::cout << "1. Mostrar usuarios" << std::endl;
        std::cout << "2. Mostrar catalogo de vinos" << std::endl;
        std::cout << "3. Mostrar membresias" << std::endl;
        std::cout << "4. Ranking de vinos del ultimo año" << std::endl;
        std::cout << "5. Ranking de bodegas del ultimo año" << std::endl;
        std::cout << "6. Ranking de varietales por grupo etario" << std::endl;
        std::cout << "0. Salir" << std::endl;

        getline(std::cin, opcion);
        if(opcion.compare("1") == 0) {
            std::cout << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t    Lista de usuarios\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
            mostrarElementosDeLaLista(lUsuarios, mostrarDatoUsuario);
        } else if(opcion.compare("2") == 0) {
            std::cout << std::endl << std::endl << std::endl << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t    Catálogo de vinos\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
            mostrarElementosDeLaLista(lCatalogo, mostrarDatoVino);
        } else if(opcion.compare("3") == 0) {
            std::cout << std::endl << std::endl << std::endl << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t\tMembresias\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
            showMembresiaList(lMembresia);
        } else if(opcion.compare("4") == 0) {
            listaVinosUltimoAnio = rankingVinosUltimoAnio(lMembresia, lCatalogo);
            std::cout << std::endl;
        } else if(opcion.compare("5") == 0) {
            if(listaVinosUltimoAnio == 0) {
                std::cout << "\nATENCION!!" << std::endl;
                std::cout << "Se debe ejecutar el ranking de vinos del ultimo año antes de poder ver los resultados\n" << std::endl;
            } else {
                rankingBodegasUltimoAnio(listaVinosUltimoAnio);
                std::cout << std::endl;
            }
        } else if(opcion.compare("6") == 0) {
            rankingVarietalesPorGrupoEtario(lMembresia, lUsuarios, lCatalogo);
        }
    }

    destruirListaYDatos(lUsuarios, eliminarDatoUsuario);
    destruirListaYDatos(lCatalogo, eliminarDatoVino);
    return EXIT_SUCCESS;
}

void eliminarDatoUsuario(ELEMENTO temp) {
    destruirUsuario((Usuario*) temp);
}

void eliminarDatoVino(ELEMENTO temp) {
    destructorVino((eVinos*) temp);
}
