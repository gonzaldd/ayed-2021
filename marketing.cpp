#include <iostream>

#include "ED/lista.h"
#include "loadMembresia.h"
#include "cargarArchivosEnLista.h"
#include "Usuario/usuario.h"
#include "Vinos/Vinos.h"

#include "marketing.h"

DatoVarietalPorGrupoEtario* crearDatoDeVarietal(std::string sNombre_Del_Varietal) {
    DatoVarietalPorGrupoEtario* d = new DatoVarietalPorGrupoEtario();

    d->sNombre_Del_Varietal = sNombre_Del_Varietal;
    d->menoresDe30 = crearLista();
    d->entre30Y50 = crearLista();
    d->mayoresDe50 = crearLista();

    return d;
}

std::string getNombreDelVarietal(DatoVarietalPorGrupoEtario* d) {
    return d->sNombre_Del_Varietal;
}

Lista* getListaMenoresDe30(DatoVarietalPorGrupoEtario* d) {
    return d->menoresDe30;
}

Lista* getListaEntre30Y50(DatoVarietalPorGrupoEtario* d) {
    return d->entre30Y50;
}

Lista* getListaMayoresDe50(DatoVarietalPorGrupoEtario* d) {
    return d->mayoresDe50;
}

Lista* varietalesQueHay(Lista* lCatalogo) {
    Lista* lAux = crearLista();
    Lista* lVarietales = crearLista();
    ELEMENTO aux, temp;
    int iContador;
    bool bExiste;

    obtenerElementoInicialDeLaLista(lCatalogo, aux);
    insertarElementoAlFinalDeLaLista(lAux, (eVinos*) aux);

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lCatalogo); i++) {
        obtenerElementoDeLaLista(lCatalogo, i, aux);
        iContador = 0;
        bExiste = false;

        while (iContador < getCantidadDeElementosEnLaLista(lAux) && !bExiste) {
            obtenerElementoDeLaLista(lAux, iContador, temp);
            iContador++;

            if (getVarietal((eVinos*) aux) == getVarietal((eVinos*) temp))
                bExiste = true;
        }

        if (!bExiste)
            insertarElementoAlFinalDeLaLista(lAux, (eVinos*) aux);
    }

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lAux); i++) {
        obtenerElementoDeLaLista(lAux, i, aux);
        temp = crearDatoDeVarietal(getVarietal((eVinos*) aux));
        insertarElementoAlFinalDeLaLista(lVarietales, (DatoVarietalPorGrupoEtario*) temp);
    }

    vaciarLista(lAux);
    delete lAux;

    return lVarietales;
}

void insertarUsuarioEnLaListaDeSuGrupo(std::string sGrupo_Etario, DatoVarietalPorGrupoEtario* lVarietales, Usuario* usuario) {
    bool bUsuario_Existe = false;
    int iContador = 0;
    ELEMENTO temp;

    if (sGrupo_Etario == "menoresDe30") {
        Lista* lAux = getListaMenoresDe30(lVarietales);

        if (!listaEstaVacia(lAux)) {

            while (iContador < getCantidadDeElementosEnLaLista(lAux) && !bUsuario_Existe) {
                obtenerElementoDeLaLista(lAux, iContador, temp);
                iContador++;

                if (usuario == (Usuario*) temp)
                    bUsuario_Existe = true;
            }

            if (!bUsuario_Existe)
                insertarElementoAlFinalDeLaLista(lAux, (Usuario*) usuario);

        } else
            insertarElementoAlFinalDeLaLista(lAux, (Usuario*) usuario);

    } else if (sGrupo_Etario == "entre30Y50") {
        Lista* lAux = getListaEntre30Y50(lVarietales);

        if (!listaEstaVacia(lAux)) {

            while (iContador < getCantidadDeElementosEnLaLista(lAux) && !bUsuario_Existe) {
                obtenerElementoDeLaLista(lAux, iContador, temp);
                iContador++;

                if (usuario == (Usuario*) temp)
                    bUsuario_Existe = true;
            }

            if (!bUsuario_Existe)
                insertarElementoAlFinalDeLaLista(lAux, (Usuario*) usuario);

        } else
            insertarElementoAlFinalDeLaLista(lAux, (Usuario*) usuario);

    } else {
        Lista* lAux = getListaMayoresDe50(lVarietales);

        if (!listaEstaVacia(lAux)) {

            while (iContador < getCantidadDeElementosEnLaLista(lAux) && !bUsuario_Existe) {
                obtenerElementoDeLaLista(lAux, iContador, temp);
                iContador++;

                if (usuario == (Usuario*) temp)
                    bUsuario_Existe = true;
            }

            if (!bUsuario_Existe)
                insertarElementoAlFinalDeLaLista(lAux, (Usuario*) usuario);

        } else
            insertarElementoAlFinalDeLaLista(lAux, (Usuario*) usuario);
    }

}

void identificarVarietalDelVino(Membresia* membresia, std::string getIDVinoDeLaMembresia(Membresia* m), Lista* lUsuario, Lista* lCatalogos, Lista* &lVarietales) {
    int iContador = 0, iContador2 = 0, iContador3 = 0;
    bool bVino_Encontrado = false, bUsuario_Encontrado = false, bVarietal_Encontrado = false;
    ELEMENTO vino, usuario, varietal;

    while (iContador < getCantidadDeElementosEnLaLista(lCatalogos) && !bVino_Encontrado) {
        obtenerElementoDeLaLista(lCatalogos, iContador, vino);
        iContador++;

        if (stoi(getIDVinoDeLaMembresia(membresia)) == getId((eVinos*) vino))
            bVino_Encontrado = true;
    }

    while (iContador2 < getCantidadDeElementosEnLaLista(lUsuario) && !bUsuario_Encontrado) {
        obtenerElementoDeLaLista(lUsuario, iContador2, usuario);
        iContador2++;

        if (getID((Usuario*) usuario) == getIDDelUsuarioDeLaMembresia(membresia))
            bUsuario_Encontrado = true;
    }

    while (iContador3 < getCantidadDeElementosEnLaLista(lVarietales) && !bVarietal_Encontrado) {
        obtenerElementoDeLaLista(lVarietales, iContador++, varietal);
        iContador3++;

        if (getNombreDelVarietal((DatoVarietalPorGrupoEtario*) varietal) == getVarietal((eVinos*) vino))
            bVarietal_Encontrado = true;
    }

    if (getEdadUsuario((Usuario*) usuario) < 30)
        insertarUsuarioEnLaListaDeSuGrupo("menoresDe30", (DatoVarietalPorGrupoEtario*) varietal, (Usuario*) usuario);

    if (getEdadUsuario((Usuario*) usuario) >= 30 && getEdadUsuario((Usuario*) usuario) <= 50)
        insertarUsuarioEnLaListaDeSuGrupo("entre30Y50", (DatoVarietalPorGrupoEtario*) varietal, (Usuario*) usuario);

    if (getEdadUsuario((Usuario*) usuario) > 50)
        insertarUsuarioEnLaListaDeSuGrupo("mayoresDe50", (DatoVarietalPorGrupoEtario*) varietal, (Usuario*) usuario);
}

void menoresDe30Anios(Lista* lVarietal) {
    ELEMENTO varietal;

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lVarietal); i++) {
        obtenerElementoDeLaLista(lVarietal, i, varietal);

        std::cout << getNombreDelVarietal((DatoVarietalPorGrupoEtario*) varietal) << " - " << getCantidadDeElementosEnLaLista(getListaMenoresDe30((DatoVarietalPorGrupoEtario*) varietal)) << std::endl;
    }
}

void rankingVarietalesPorGrupoEtario(Lista* lMembresia, Lista* lUsuario, Lista* lCatalogos) {
    Lista* lVarietales = varietalesQueHay(lCatalogos);

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lMembresia); i++) {
        ELEMENTO innerElemento;
        obtenerElementoDeLaLista(lMembresia, i, innerElemento);
        Lista* innerList = (Lista*) innerElemento;

        for (int x = 0; x < getCantidadDeElementosEnLaLista(innerList); x++) {
            ELEMENTO membresia;
            obtenerElementoDeLaLista(innerList, x, membresia);

            identificarVarietalDelVino((Membresia*)membresia, getIDVino1DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*)membresia, getIDVino2DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*)membresia, getIDVino3DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*)membresia, getIDVino4DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*)membresia, getIDVino5DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*)membresia, getIDVino6DeLaMembresia, lUsuario, lCatalogos, lVarietales);
        }
    }

    menoresDe30Anios(lVarietales);
}