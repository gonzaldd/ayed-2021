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
    std::cout << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t    Lista de usuarios\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
    Lista* lUsuarios = crearLista();
    cargarDatosDeUsuarioEnLaLista("Archivos/usuarios_test.txt", lUsuarios);
    mostrarElementosDeLaLista(lUsuarios, mostrarDatoUsuario);
    
    std::cout << std::endl << std::endl << std::endl << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t    Catálogo de vinos\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
    Lista* lCatalogo = crearLista();
    cargarCatalogoDeVinosEnLaLista("Archivos/catalos_test.txt", lCatalogo);
    mostrarElementosDeLaLista(lCatalogo, mostrarDatoVino);
    
    std::cout << std::endl << std::endl << std::endl << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t\tMembresias\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
    Lista* lMembresia = crearLista();
    readFileAndLoad("Archivos/elecion_test.txt", lMembresia);
    showMembresiaList(lMembresia);
    
    std::cout << std::endl << std::endl << std::endl << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t\tRANKINGS\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
    rankingVinosUltimoAnio(lMembresia);
    rankingVarietalesPorGrupoEtario(lMembresia, lUsuarios, lCatalogo);

    destruirListaYDatos(lUsuarios, eliminarDatoUsuario);
    destruirListaYDatos(lCatalogo, eliminarDatoVino);
    
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

void eliminarDatoUsuario(ELEMENTO temp){
    destruirUsuario((Usuario*) temp);
}

void eliminarDatoVino(ELEMENTO temp){
    destructorVino((eVinos*) temp);
}