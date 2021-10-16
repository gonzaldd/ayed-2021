#include <iostream>

#include "ED/lista.h"
#include "loadMembresia.h"
#include "cargarArchivosEnLista.h"
#include "Usuario/usuario.h"
#include "Vinos/Vinos.h"

#include "marketing.h"

void rankingVarietalesPorGrupoEtario(Lista* lMembresia, Lista* lUsuario, Lista* lCatalogos){
    Lista* menoresDe30 = crearLista();
    Lista* entre30Y50 = crearLista();
    Lista* mayoresDe50 = crearLista();
    
}

Lista* varietalesQueHay(Lista* lCatalogo){
    Lista* lVarietales = crearLista();
    ELEMENTO aux, temp;
    int iCoincidencias;
    
    obtenerElementoInicialDeLaLista(lCatalogo, aux);
    
    insertarElementoAlFinalDeLaLista(lVarietales, (eVinos*)aux);
    
    for(int i=0; i<getCantidadDeElementosEnLaLista(lCatalogo); i++){
        obtenerElementoDeLaLista(lCatalogo, i, aux);
        
        for(int j=0; j<getCantidadDeElementosEnLaLista(lVarietales); j++){
            iCoincidencias = getCantidadDeElementosEnLaLista(lVarietales);
            obtenerElementoDeLaLista(lVarietales, j, temp);
            
            if( getVarietal((eVinos*)aux) != getVarietal((eVinos*)temp))
                iCoincidencias--;
            
            if(iCoincidencias == 0)
                insertarElementoAlFinalDeLaLista(lVarietales, (eVinos*)aux);
                
        }
        
    }
    
    return lVarietales;
}

GrupoEtario* crearGrupoEtario(std::string sNombre_Del_Grupo_Etario, int iEdad_Minima, int iEdad_Maxima) {
    GrupoEtario* g = new GrupoEtario();

    g->sNombre_Del_Grupo_Etario = sNombre_Del_Grupo_Etario;
    g->iEdad_Minima = iEdad_Minima;
    g->iEdad_Maxima = iEdad_Maxima;
    g->lIntegrantes = crearLista();

    return g;
}

std::string nombreDelGrupoEtario(GrupoEtario* g) {
    return g->sNombre_Del_Grupo_Etario;
}

Lista* integrantesDelGrupoEtario(GrupoEtario* g) {
    return g->lIntegrantes;
}

void usuariosPorGrupoEtario(Lista* lUsuarios, GrupoEtario* &lGrupos_Etario1, GrupoEtario* &lGrupos_Etario2, GrupoEtario* &lGrupos_Etario3) {
    ELEMENTO aux;
    int iEdad;
    int iID;

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lUsuarios); i++) {
        obtenerElementoDeLaLista(lUsuarios, i, aux);
        iEdad = getEdadUsuario((Usuario*) aux);
        iID = stoi(getID((Usuario*) aux));

        if (iEdad < lGrupos_Etario1->iEdad_Maxima && iEdad >= lGrupos_Etario1->iEdad_Minima)
            insertarElementoAlFinalDeLaLista(lGrupos_Etario1->lIntegrantes, (int*) iID);

        if (iEdad < lGrupos_Etario2->iEdad_Maxima && iEdad >= lGrupos_Etario2->iEdad_Minima)
            insertarElementoAlFinalDeLaLista(lGrupos_Etario2->lIntegrantes, (int*) iID);

        if (iEdad < lGrupos_Etario3->iEdad_Maxima && iEdad >= lGrupos_Etario3->iEdad_Minima)
            insertarElementoAlFinalDeLaLista(lGrupos_Etario3->lIntegrantes, (int*) iID);

    }
}

void mostrarDatoMmebresiasXD(Lista* lista) {
    Nodo *iterateList = (Nodo*) lista->inicio;
    Nodo *iterateInnerNode = (Nodo*) ((Lista*) iterateList->dato)->inicio;
    Membresia* membresia = (Membresia*) iterateInnerNode->dato;

    int iContador = 0;
    while (iterateInnerNode && iContador < 1) {
        Membresia *membresia = (Membresia*) iterateInnerNode->dato;

        std::cout << membresia->id_usuario << "\t";
        std::cout << membresia->mes << "/" << membresia->anio << "\t";
        std::cout << membresia->id_vino_1 << "\t";
        std::cout << membresia->id_vino_2 << "\t";
        std::cout << membresia->id_vino_3 << "\t";
        std::cout << membresia->id_vino_4 << "\t";
        std::cout << membresia->id_vino_5 << "\t";
        std::cout << membresia->id_vino_6 << std::endl;
        iterateInnerNode = iterateInnerNode->siguiente;
        iContador++;
    }
}