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

//------------------------------------------------------------------------Destructor-------------------------------------------------------------------------

/*
    PRE: El datoVarietalPorGrupoEtario debe haber sido creado.
    POST: El datoVarietalPorGrupoEtario es eliminado.
 */
void destruirDatoDeVarietal(DatoVarietalPorGrupoEtario* d) {
    destruirLista(d->menoresDe30);
    destruirLista(d->entre30Y50);
    destruirLista(d->mayoresDe50);
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

    destruirLista(lAux);

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

        if (!listaEstaVacia(lVarietales->menoresDe30)) {

            while (iContador < getCantidadDeElementosEnLaLista(lVarietales->menoresDe30) && !bUsuario_Existe) {
                obtenerElementoDeLaLista(lVarietales->menoresDe30, iContador, temp);
                iContador++;

                if (usuario == (Usuario*) temp)
                    bUsuario_Existe = true;
            }

            if (!bUsuario_Existe)
                insertarElementoAlFinalDeLaLista(lVarietales->menoresDe30, (Usuario*) usuario);

        } else
            insertarElementoAlFinalDeLaLista(lVarietales->menoresDe30, (Usuario*) usuario);

    } else if (sGrupo_Etario == "entre30Y50") {

        if (!listaEstaVacia(lVarietales->entre30Y50)) {

            while (iContador < getCantidadDeElementosEnLaLista(lVarietales->entre30Y50) && !bUsuario_Existe) {
                obtenerElementoDeLaLista(lVarietales->entre30Y50, iContador, temp);
                iContador++;

                if (usuario == (Usuario*) temp)
                    bUsuario_Existe = true;
            }

            if (!bUsuario_Existe)
                insertarElementoAlFinalDeLaLista(lVarietales->entre30Y50, (Usuario*) usuario);

        } else
            insertarElementoAlFinalDeLaLista(lVarietales->entre30Y50, (Usuario*) usuario);

    } else {
        if (!listaEstaVacia(lVarietales->mayoresDe50)) {

            while (iContador < getCantidadDeElementosEnLaLista(lVarietales->mayoresDe50) && !bUsuario_Existe) {
                obtenerElementoDeLaLista(lVarietales->mayoresDe50, iContador, temp);
                iContador++;

                if (usuario == (Usuario*) temp)
                    bUsuario_Existe = true;
            }

            if (!bUsuario_Existe)
                insertarElementoAlFinalDeLaLista(lVarietales->mayoresDe50, (Usuario*) usuario);

        } else
            insertarElementoAlFinalDeLaLista(lVarietales->mayoresDe50, (Usuario*) usuario);
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

        if (((DatoVarietalPorGrupoEtario*) varietal)->sNombre_Del_Varietal == getVarietal((eVinos*) vino))
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
    ELEMENTO elemento1, elemento2;

    obtenerElementoDeLaLista(lVarietal, iPosicion1, elemento1);
    obtenerElementoDeLaLista(lVarietal, iPosicion2, elemento2);

    int iResultado;
    if (getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento1)->menoresDe30) < getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento2)->menoresDe30)) {
        iResultado = MENOR;
    } else if (getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento1)->menoresDe30) > getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento2)->menoresDe30)) {
        iResultado = MAYOR;
    } else
        iResultado = IGUAL;

    return iResultado;
}

/*
    PRE: Debe existir la lista de los varietales y debo indicar 2 posicion a comparar.
    POST: Comparo los datos e indico si son mayores, menores e iguales.
 */
int compararEntre30Y50Anios(Lista* lVarietal, int iPosicion1, int iPosicion2) {
    ELEMENTO elemento1, elemento2;

    obtenerElementoDeLaLista(lVarietal, iPosicion1, elemento1);
    obtenerElementoDeLaLista(lVarietal, iPosicion2, elemento2);

    int iResultado;
    if (getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento1)->entre30Y50) < getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento2)->entre30Y50)) {
        iResultado = MENOR;
    } else if (getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento1)->entre30Y50) > getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento2)->entre30Y50)) {
        iResultado = MAYOR;
    } else
        iResultado = IGUAL;

    return iResultado;
}

/*
    PRE: Debe existir la lista de los varietales y debo indicar 2 posicion a comparar.
    POST: Comparo los datos e indico si son mayores, menores e iguales.
 */
int compararMayoresDe50Anios(Lista* lVarietal, int iPosicion1, int iPosicion2) {
    ELEMENTO elemento1, elemento2;

    obtenerElementoDeLaLista(lVarietal, iPosicion1, elemento1);
    obtenerElementoDeLaLista(lVarietal, iPosicion2, elemento2);

    int iResultado;
    if (getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento1)->mayoresDe50) < getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento2)->mayoresDe50)) {
        iResultado = MENOR;
    } else if (getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento1)->mayoresDe50) > getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) elemento2)->mayoresDe50)) {
        iResultado = MAYOR;
    } else
        iResultado = IGUAL;

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
    std::cout << ((DatoVarietalPorGrupoEtario*) varietal)->sNombre_Del_Varietal << ": " << getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) varietal)->menoresDe30) << std::endl;
}

/*
    PRE: Debe existir la lista de los varietales y debo indicar la posicion a mostrar.
    POST: Imprimo los datos del varietal en dicho grupo etario.
 */
void entre30Y50Anios(Lista* lVarietal, int iPosicion) {
    ELEMENTO varietal;
    obtenerElementoDeLaLista(lVarietal, iPosicion, varietal);
    std::cout << ((DatoVarietalPorGrupoEtario*) varietal)->sNombre_Del_Varietal << ": " << getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) varietal)->entre30Y50) << std::endl;
}

/*
    PRE: Debe existir la lista de los varietales y debo indicar la posicion a mostrar.
    POST: Imprimo los datos del varietal en dicho grupo etario.
 */
void mayoresDe50Anios(Lista* lVarietal, int iPosicion) {
    ELEMENTO varietal;
    obtenerElementoDeLaLista(lVarietal, iPosicion, varietal);
    std::cout << ((DatoVarietalPorGrupoEtario*) varietal)->sNombre_Del_Varietal << ": " << getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) varietal)->mayoresDe50) << std::endl;
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
    reordenarLista(lVarietales, compararMenoresDe30Anios, descendente);
    mostrarElementosDeLaLista(lVarietales, menoresDe30Anios);
    std::cout << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\tVarietal por grupo etario entre 30 y 50 años\n" << LINEA << std::endl << LINEA << std::endl;
    reordenarLista(lVarietales, compararEntre30Y50Anios, descendente);
    mostrarElementosDeLaLista(lVarietales, entre30Y50Anios);
    std::cout << std::endl << LINEA << std::endl << LINEA << "\n\t\t\t\tVarietal por grupo etario mayores de 50 años\n" << LINEA << std::endl << LINEA << std::endl;
    reordenarLista(lVarietales, compararMayoresDe50Anios, descendente);
    mostrarElementosDeLaLista(lVarietales, mayoresDe50Anios);

    destruirListaYDatos(lVarietales, eliminarDatosDeVarietales);
}