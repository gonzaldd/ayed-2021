#include <iostream>
#include <algorithm>

#include "Usuario/usuario.h"
#include "Vinos/Vinos.h"
#include "loadMembresia.h"
#include "cargarArchivosEnLista.h"
#include "ED/lista.h"
#include "marketing.h"

int main(int argc, char** argv) {
    std::cout << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t    Lista de usuarios\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
    Lista* lUsuarios = crearLista();
    cargarDatosDeUsuarioEnLaLista("Archivos/usuarios_test.txt", lUsuarios);
    mostrarDatosDeLosUsuariosEnLaLista(lUsuarios);
    
    std::cout << std::endl << std::endl << std::endl << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t    Catálogo de vinos\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
    Lista* lCatalogo = crearLista();
    cargarCatalogoDeVinosEnLaLista("Archivos/catalos_test.txt", lCatalogo);
    mostrarCatalogoDeVinos(lCatalogo);
    
    std::cout << std::endl << std::endl << std::endl << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t\tMembresias\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
    Lista* lMembresia = crearLista();
    readFileAndLoad("Archivos/elecion_test.txt", lMembresia);
    showMembresiaList(lMembresia);
    
    std::cout << std::endl << std::endl << std::endl << LINEA << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\t\t\tRANKINGS\n" << LINEA << std::endl << LINEA << std::endl << LINEA << std::endl;
    //rankingVarietalesPorGrupoEtario(lMembresia, lUsuarios, lCatalogo);
    
    Lista* n = varietalesQueHay(lCatalogo);
    ELEMENTO aux;
    for(int i=0; i<getCantidadDeElementosEnLaLista(n); i++){
        obtenerElementoDeLaLista(n, i, aux);
        mostrarVino((eVinos*)aux);
    }
    
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

