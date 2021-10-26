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
    int iCantidad_De_Ventas_Menores_De_30;
    int iCantidad_De_Ventas_Entre_30_Y_50;
    int iCantidad_De_Ventas_Mayores_De_50;
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
    d->iCantidad_De_Ventas_Menores_De_30 = 0;
    d->iCantidad_De_Ventas_Entre_30_Y_50 = 0;
    d->iCantidad_De_Ventas_Mayores_De_50 = 0;

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
    PRE: Debe existir el usuario y la lista del grupo etario, la cual no debe estar vacia.
    POST: Comparo si el usuario existe o no en la lista y si no esta en la lista lo incorporo.
 */
void insertarUsuarioEnLaListaDeSuGrupoSiNoEstaVaciaYNoExisteYaEnElla(Lista* lGrupo_Etario, Usuario* usuario) {
    bool bUsuario_Existe = false;
    int iContador = 0;
    ELEMENTO temp;

    while (iContador < getCantidadDeElementosEnLaLista(lGrupo_Etario) && !bUsuario_Existe) {
        obtenerElementoDeLaLista(lGrupo_Etario, iContador, temp);
        iContador++;

        if (usuario == (Usuario*) temp)
            bUsuario_Existe = true;
    }

    if (!bUsuario_Existe)
        insertarElementoAlFinalDeLaLista(lGrupo_Etario, (Usuario*) usuario);
}

/*
    PRE: Indico el grupo etario del cliente, el varietal y el usuario con los que se debe operar.
    POST: Opero la lista del grupo etario que corresponda agregando el usuario que compro un X varietal si es que el usuario no ha comprado previamente dicho varietal e incremento la cantidad de ventas del varietal en su grupo en 1.
 */
void insertarUsuarioEnLaListaDeSuGrupo(std::string sGrupo_Etario, DatoVarietalPorGrupoEtario* varietales, Usuario* usuario) {


    if (sGrupo_Etario == "menoresDe30") {
        varietales->iCantidad_De_Ventas_Menores_De_30++;

        if (!listaEstaVacia(varietales->menoresDe30)) {

            insertarUsuarioEnLaListaDeSuGrupoSiNoEstaVaciaYNoExisteYaEnElla(varietales->menoresDe30, usuario);

        } else
            insertarElementoAlFinalDeLaLista(varietales->menoresDe30, (Usuario*) usuario);

    } else if (sGrupo_Etario == "entre30Y50") {
        varietales->iCantidad_De_Ventas_Entre_30_Y_50++;

        if (!listaEstaVacia(varietales->entre30Y50)) {

            insertarUsuarioEnLaListaDeSuGrupoSiNoEstaVaciaYNoExisteYaEnElla(varietales->entre30Y50, usuario);

        } else
            insertarElementoAlFinalDeLaLista(varietales->entre30Y50, (Usuario*) usuario);

    } else {
        varietales->iCantidad_De_Ventas_Mayores_De_50++;
        
        if (!listaEstaVacia(varietales->mayoresDe50)) {

            insertarUsuarioEnLaListaDeSuGrupoSiNoEstaVaciaYNoExisteYaEnElla(varietales->mayoresDe50, usuario);

        } else
            insertarElementoAlFinalDeLaLista(varietales->mayoresDe50, (Usuario*) usuario);
    }

}

/*
    PRE: Debe existir la lista de varietal, de usuarios, de calatogo, debe existir la membresia y debo indicar el vino que deseo obtener de los que existen.
    POST: Inserto cada vino comprado en el grupo etario que corresponda en base al comprador.
 */
void identificarVarietalDelVino(Membresia* membresia, int iNumero_De_Vino, Lista* lUsuario, Lista* lCatalogos, Lista* lVarietales) {
    int iContador = 0, iContador2 = 0, iContador3 = 0;
    bool bVino_Encontrado = false, bUsuario_Encontrado = false, bVarietal_Encontrado = false;
    ELEMENTO vino, usuario, varietal;

    while (iContador < getCantidadDeElementosEnLaLista(lCatalogos) && !bVino_Encontrado) {
        obtenerElementoDeLaLista(lCatalogos, iContador, vino);
        iContador++;

        if (stoi(getIDVinoDeLaMembresia(membresia, iNumero_De_Vino)) == getId((eVinos*) vino))
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

//------------------------------------------------------------Funciones de ordenar ranking------------------------------------------------------------

/*
    PRE: Deben existir los 2 elementos que deseo comparar.
    POST: Comparo los datos e indico si son mayores, menores e iguales.
 */
int compararMenoresDe30Anios(ELEMENTO elemento1, ELEMENTO elemento2) {
    int iResultado;
    if (((DatoVarietalPorGrupoEtario*) elemento1)->iCantidad_De_Ventas_Menores_De_30 < ((DatoVarietalPorGrupoEtario*) elemento2)->iCantidad_De_Ventas_Menores_De_30) {
        iResultado = MENOR;
    } else if (((DatoVarietalPorGrupoEtario*) elemento1)->iCantidad_De_Ventas_Menores_De_30 > ((DatoVarietalPorGrupoEtario*) elemento2)->iCantidad_De_Ventas_Menores_De_30) {
        iResultado = MAYOR;
    } else
        iResultado = IGUAL;

    return iResultado;
}

/*
    PRE: Deben existir los 2 elementos que deseo comparar.
    POST: Comparo los datos e indico si son mayores, menores e iguales.
 */
int compararEntre30Y50Anios(ELEMENTO elemento1, ELEMENTO elemento2) {
    int iResultado;
    if (((DatoVarietalPorGrupoEtario*) elemento1)->iCantidad_De_Ventas_Entre_30_Y_50 < ((DatoVarietalPorGrupoEtario*) elemento2)->iCantidad_De_Ventas_Entre_30_Y_50) {
        iResultado = MENOR;
    } else if (((DatoVarietalPorGrupoEtario*) elemento1)->iCantidad_De_Ventas_Entre_30_Y_50 > ((DatoVarietalPorGrupoEtario*) elemento2)->iCantidad_De_Ventas_Entre_30_Y_50) {
        iResultado = MAYOR;
    } else
        iResultado = IGUAL;

    return iResultado;
}

/*
    PRE: Deben existir los 2 elementos que deseo comparar.
    POST: Comparo los datos e indico si son mayores, menores e iguales.
 */
int compararMayoresDe50Anios(ELEMENTO elemento1, ELEMENTO elemento2) {
    int iResultado;
    if (((DatoVarietalPorGrupoEtario*) elemento1)->iCantidad_De_Ventas_Mayores_De_50 < ((DatoVarietalPorGrupoEtario*) elemento2)->iCantidad_De_Ventas_Mayores_De_50) {
        iResultado = MENOR;
    } else if (((DatoVarietalPorGrupoEtario*) elemento1)->iCantidad_De_Ventas_Mayores_De_50 > ((DatoVarietalPorGrupoEtario*) elemento2)->iCantidad_De_Ventas_Mayores_De_50) {
        iResultado = MAYOR;
    } else
        iResultado = IGUAL;

    return iResultado;
}

//------------------------------------------------------------------------Mostrar datos---------------------------------------------------------------------

/*
    PRE: Debe existir el elemento que deseo mostrar y debe ser un DatoVarietalPorGrupoEtario.
    POST: Imprimo los datos del varietal en dicho grupo etario.
 */
void menoresDe30Anios(ELEMENTO varietal) {
    std::cout << ((DatoVarietalPorGrupoEtario*) varietal)->sNombre_Del_Varietal << ": " << std::endl;
    std::cout << "\tCantidad de ventas: " << ((DatoVarietalPorGrupoEtario*) varietal)->iCantidad_De_Ventas_Menores_De_30 << std::endl;
    std::cout << "\tCantidad de personas: " << getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) varietal)->menoresDe30) << std::endl;
    std::cout << LINEA << std::endl;
}

/*
    PRE: Debe existir el elemento que deseo mostrar y debe ser un DatoVarietalPorGrupoEtario.
    POST: Imprimo los datos del varietal en dicho grupo etario.
 */
void entre30Y50Anios(ELEMENTO varietal) {
    std::cout << ((DatoVarietalPorGrupoEtario*) varietal)->sNombre_Del_Varietal << ": " << std::endl;
    std::cout << "\tCantidad de ventas: " << ((DatoVarietalPorGrupoEtario*) varietal)->iCantidad_De_Ventas_Entre_30_Y_50 << std::endl;
    std::cout << "\tCantidad de personas: " << getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) varietal)->entre30Y50) << std::endl;
    std::cout << LINEA << std::endl;
}

/*
    PRE: Debe existir el elemento que deseo mostrar y debe ser un DatoVarietalPorGrupoEtario.
    POST: Imprimo los datos del varietal en dicho grupo etario.
 */
void mayoresDe50Anios(ELEMENTO varietal) {
    std::cout << ((DatoVarietalPorGrupoEtario*) varietal)->sNombre_Del_Varietal << ": " << std::endl;
    std::cout << "\tCantidad de ventas: " << ((DatoVarietalPorGrupoEtario*) varietal)->iCantidad_De_Ventas_Mayores_De_50 << std::endl;
    std::cout << "\tCantidad de personas: " << getCantidadDeElementosEnLaLista(((DatoVarietalPorGrupoEtario*) varietal)->mayoresDe50) << std::endl;
    std::cout << LINEA << std::endl;
}

//------------------------------------------------------------------------Eliminar datos---------------------------------------------------------------------

/*
    PRE: Debe existir el ELEMENTO que deseo eliminar el cual debe ser un DatoVarietalPorGrupoEtario.
    POST: Elimino el dato del varietal.
 */
void eliminarDatosDeVarietales(ELEMENTO temp) {
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

            for (int j = 0; j < CANT_SELECCION; j++)
                identificarVarietalDelVino((Membresia*) membresia, j, lUsuario, lCatalogos, lVarietales);
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