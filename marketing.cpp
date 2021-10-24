#include <iostream>

#include "ED/lista.h"
#include "loadMembresia.h"
#include "cargarArchivosEnLista.h"
#include "Usuario/usuario.h"
#include "Vinos/Vinos.h"

#include "marketing.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                  Ranking general de vinos del ultimo año
 --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    Ranking por bodegas del ultimo año
 --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                Ranking de varietales elegido por rango etario
 --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
struct DatoVarietalPorGrupoEtario {
    std::string sNombre_Del_Varietal;
    Lista* menoresDe30;
    Lista* entre30Y50;
    Lista* mayoresDe50;
};

//------------------------------------------------------------------------Constructor------------------------------------------------------------------------

/*
    PRE: El datoVarietalPorGrupoEtario no debe haber sido creado.
    POST: El datoVarietalPorGrupoEtario queda creado.
 */
DatoVarietalPorGrupoEtario* crearDatoDeVarietal(std::string sNombre_Del_Varietal) {
    DatoVarietalPorGrupoEtario* d = new DatoVarietalPorGrupoEtario();

    d->sNombre_Del_Varietal = sNombre_Del_Varietal;
    d->menoresDe30 = crearLista();
    d->entre30Y50 = crearLista();
    d->mayoresDe50 = crearLista();

    return d;
}

//---------------------------------------------------------------------------Getters---------------------------------------------------------------------------

/*
    PRE: El datoVarietalPorGrupoEtario debe haber sido creado.
    POST: Devuelve el dato del nombre del varietal.
 */
std::string getNombreDelVarietal(DatoVarietalPorGrupoEtario* d) {
    return d->sNombre_Del_Varietal;
}

/*
    PRE: El datoVarietalPorGrupoEtario debe haber sido creado.
    POST: Devuelve la lista de los menores de 30.
 */
Lista* getListaMenoresDe30(DatoVarietalPorGrupoEtario* d) {
    return d->menoresDe30;
}

/*
    PRE: El datoVarietalPorGrupoEtario debe haber sido creado.
    POST: Devuelve la lista de los de entre 30 y 50 inclusive.
 */
Lista* getListaEntre30Y50(DatoVarietalPorGrupoEtario* d) {
    return d->entre30Y50;
}

/*
    PRE: El datoVarietalPorGrupoEtario debe haber sido creado.
    POST: Devuelve la lista de los mayores de 50.
 */
Lista* getListaMayoresDe50(DatoVarietalPorGrupoEtario* d) {
    return d->mayoresDe50;
}

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------

/*
    PRE: El datoVarietalPorGrupoEtario debe haber sido creado.
    POST: El datoVarietalPorGrupoEtario es eliminado.
 */
void destruirDatoDeVarietal(DatoVarietalPorGrupoEtario* d) {
    vaciarLista(d->menoresDe30);
    delete d->menoresDe30;
    vaciarLista(d->entre30Y50);
    delete d->entre30Y50;
    vaciarLista(d->mayoresDe50);
    delete d->mayoresDe50;
    delete d;
}

//-------------------------------------------------------------------Funciones extras--------------------------------------------------------------------

/*
    PRE: Debe existir la lista de catalogos.
    POST: Devuelvo la lista de los varietales que existen en el catalogo.
 */
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

/*
    PRE: Indico el grupo etario del cliente, el varietal y el usuario con los que se debe operar.
    POST: Opero la lista del grupo etario que corresponda agregando el usuario que compro un X varietal si
 * es que el usuario no ha comprado previamente dicho varietal.
 */
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

/*
    PRE: Debe existir la lista de varietal, de usuarios, de calatogo, debe existir la membresia y debo indicar el vino que deseo obtener de los que existen.
    POST: Inserto cada vino comprado en el grupo etario que corresponda en base al comprador.
 */
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
        obtenerElementoDeLaLista(lVarietales, iContador3, varietal);
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

//------------------------------------------------------------Funciones de ordenar rankig------------------------------------------------------------

/*
    PRE: Debe existir la lista de los varietales y debo indicar 2 posicion a comparar.
    POST: Comparo los datos e indico si son mayores, menores e iguales.
 */
int compararMenoresDe30Anios(Lista* lVarietal, int iPosicion1, int iPosicion2) {
    int iResultado = IGUAL;
    ELEMENTO elemento1, elemento2;

    obtenerElementoDeLaLista(lVarietal, iPosicion1, elemento1);
    obtenerElementoDeLaLista(lVarietal, iPosicion2, elemento2);

    if (getCantidadDeElementosEnLaLista(getListaMenoresDe30((DatoVarietalPorGrupoEtario*) elemento1)) < getCantidadDeElementosEnLaLista(getListaMenoresDe30((DatoVarietalPorGrupoEtario*) elemento2))) {
        iResultado = MAYOR;
    } else
        iResultado = MENOR;

    return iResultado;
}

/*
    PRE: Debe existir la lista de los varietales y debo indicar 2 posicion a comparar.
    POST: Comparo los datos e indico si son mayores, menores e iguales.
 */
int compararEntre30Y50Anios(Lista* lVarietal, int iPosicion1, int iPosicion2) {
    int iResultado = IGUAL;
    ELEMENTO elemento1, elemento2;

    obtenerElementoDeLaLista(lVarietal, iPosicion1, elemento1);
    obtenerElementoDeLaLista(lVarietal, iPosicion2, elemento2);

    if (getCantidadDeElementosEnLaLista(getListaEntre30Y50((DatoVarietalPorGrupoEtario*) elemento1)) < getCantidadDeElementosEnLaLista(getListaEntre30Y50((DatoVarietalPorGrupoEtario*) elemento2))) {
        iResultado = MAYOR;
    } else
        iResultado = MENOR;

    return iResultado;
}

/*
    PRE: Debe existir la lista de los varietales y debo indicar 2 posicion a comparar.
    POST: Comparo los datos e indico si son mayores, menores e iguales.
 */
int compararMayoresDe50Anios(Lista* lVarietal, int iPosicion1, int iPosicion2) {
    int iResultado = IGUAL;
    ELEMENTO elemento1, elemento2;

    obtenerElementoDeLaLista(lVarietal, iPosicion1, elemento1);
    obtenerElementoDeLaLista(lVarietal, iPosicion2, elemento2);

    if (getCantidadDeElementosEnLaLista(getListaMayoresDe50((DatoVarietalPorGrupoEtario*) elemento1)) < getCantidadDeElementosEnLaLista(getListaMayoresDe50((DatoVarietalPorGrupoEtario*) elemento2))) {
        iResultado = MAYOR;
    } else
        iResultado = MENOR;

    return iResultado;
}

//------------------------------------------------------------------------Mostrar datos---------------------------------------------------------------------

/*
    PRE: Debe existir la lista de los varietales y debo indicar la posicion a mostrar.
    POST: Imprimo los datos del varietal en dicho grupo etario.
 */
void menoresDe30Anios(Lista* lVarietal, int iPosicion) {
    ELEMENTO varietal;
    obtenerElementoDeLaLista(lVarietal, iPosicion, varietal);
    std::cout << getNombreDelVarietal((DatoVarietalPorGrupoEtario*) varietal) << ": " << getCantidadDeElementosEnLaLista(getListaMenoresDe30((DatoVarietalPorGrupoEtario*) varietal)) << std::endl;
}

/*
    PRE: Debe existir la lista de los varietales y debo indicar la posicion a mostrar.
    POST: Imprimo los datos del varietal en dicho grupo etario.
 */
void entre30Y50Anios(Lista* lVarietal, int iPosicion) {
    ELEMENTO varietal;
    obtenerElementoDeLaLista(lVarietal, iPosicion, varietal);
    std::cout << getNombreDelVarietal((DatoVarietalPorGrupoEtario*) varietal) << ": " << getCantidadDeElementosEnLaLista(getListaEntre30Y50((DatoVarietalPorGrupoEtario*) varietal)) << std::endl;
}

/*
    PRE: Debe existir la lista de los varietales y debo indicar la posicion a mostrar.
    POST: Imprimo los datos del varietal en dicho grupo etario.
 */
void mayoresDe50Anios(Lista* lVarietal, int iPosicion) {
    ELEMENTO varietal;
    obtenerElementoDeLaLista(lVarietal, iPosicion, varietal);
    std::cout << getNombreDelVarietal((DatoVarietalPorGrupoEtario*) varietal) << ": " << getCantidadDeElementosEnLaLista(getListaMayoresDe50((DatoVarietalPorGrupoEtario*) varietal)) << std::endl;
}

//------------------------------------------------------------------------Eliminar datos---------------------------------------------------------------------
/*
    PRE: Debe existir la lista de los varietales y debo indicar la posicion a eliminar.
    POST: Elimino el dato del varietal.
 */
void eliminarDatosDeVarietales(int iPosicion, Lista* lVarietales) {
    ELEMENTO temp;    
    eliminarElementoDeLaLista(lVarietales, iPosicion, temp);
    destruirDatoDeVarietal((DatoVarietalPorGrupoEtario*) temp);
}

//-------------------------------------------------------------------Funciones principal--------------------------------------------------------------------

void rankingVarietalesPorGrupoEtario(Lista* lMembresia, Lista* lUsuario, Lista* lCatalogos) {
    Lista* lVarietales = varietalesQueHay(lCatalogos);

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lMembresia); i++) {
        ELEMENTO innerElemento;
        obtenerElementoDeLaLista(lMembresia, i, innerElemento);
        Lista* innerList = (Lista*) innerElemento;

        for (int x = 0; x < getCantidadDeElementosEnLaLista(innerList); x++) {
            ELEMENTO membresia;
            obtenerElementoDeLaLista(innerList, x, membresia);

            identificarVarietalDelVino((Membresia*) membresia, getIDVino1DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*) membresia, getIDVino2DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*) membresia, getIDVino3DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*) membresia, getIDVino4DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*) membresia, getIDVino5DeLaMembresia, lUsuario, lCatalogos, lVarietales);
            identificarVarietalDelVino((Membresia*) membresia, getIDVino6DeLaMembresia, lUsuario, lCatalogos, lVarietales);
        }
    }

    std::cout << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\tVarietal por grupo etario menores de 30 años\n" << LINEA << std::endl << LINEA << std::endl;
    reordenarLista(lVarietales, compararMenoresDe30Anios);
    mostrarElementosDeLaLista(lVarietales, menoresDe30Anios);
    std::cout << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\tVarietal por grupo etario entre 30 y 50 años\n" << LINEA << std::endl << LINEA << std::endl;
    reordenarLista(lVarietales, compararEntre30Y50Anios);
    mostrarElementosDeLaLista(lVarietales, entre30Y50Anios);
    std::cout << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\tVarietal por grupo etario mayores de 50 años\n" << LINEA << std::endl << LINEA << std::endl;
    reordenarLista(lVarietales, compararMayoresDe50Anios);
    mostrarElementosDeLaLista(lVarietales, mayoresDe50Anios);

    destruirLista(lVarietales, eliminarDatosDeVarietales);
}