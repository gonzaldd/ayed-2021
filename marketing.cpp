#include <iostream>
#include <cstring> // para tener strcmp

#include "ED/lista.h"
#include "loadMembresia.h"
#include "cargarArchivosEnLista.h"
#include "Usuario/usuario.h"
#include "Vinos/Vinos.h"

#include "marketing.h"

//------------------------------------------------------------Funciones utiles a todo------------------------------------------------------------------

//Aca hay que colocar las funciones extras del 3er ranking que puedan ser utiles para los otros 2
//rankings

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


//------------------------------------------------------------Encontrar elementos------------------------------------------------------------------

/*
    PRE: Paso dos datos a la funcion del tipo vino, el primero es el que deseo buscar.
    POST: Devuelvo true si ambos datos son iguales.
 */
bool compararVarietalDelVino(ELEMENTO dato, ELEMENTO elemento) {
    return (getVarietal((eVinos*) dato) == getVarietal((eVinos*) elemento)) ? true : false;
}

/*
    PRE: Los dos datos deben ser de tipo usuario, el primero es el que deseo buscar.
    POST: Devuelvo true si ambos datos son iguales.
 */
bool compararUsuario(ELEMENTO dato, ELEMENTO elemento) {
    return ((Usuario*) dato == (Usuario*) elemento) ? true : false;
}

/*
    PRE: El primer ELEMENTO debe ser el id del vino y el segundo debe ser un vino, el primero es el que deseo buscar.
    POST: Devuelvo true si ambos datos son iguales.
 */
bool compararIDDelVinoConElDeLaMembresia(ELEMENTO dato, ELEMENTO elemento) {
    return ((int) dato == (int) getId((eVinos*) elemento)) ? true : false;
}

/*
    PRE: El primer ELEMENTO debe ser un const char y el segundo debe ser un usuario, el primero es el que deseo buscar.
    POST: Devuelvo true si ambos datos son iguales.
 */
bool compararIDDelUsuarioConElDeLaMembresia(ELEMENTO dato, ELEMENTO elemento) {
    return (strcmp((const char*) dato, (const char*) getID((Usuario*) elemento).c_str()) == IGUAL) ? true : false;
}

/*
    PRE: El primer ELEMENTO debe ser un vino y el segundo debe ser un DatoVarietalPorGrupoEtario, el primero es el que deseo buscar.
    POST: Devuelvo true si ambos datos son iguales.
 */
bool compararNombreDelVarietalDelVinoConElDelDatoGrupoEtario(ELEMENTO dato, ELEMENTO elemento) {
    return (getVarietal((eVinos*) dato) == ((DatoVarietalPorGrupoEtario*) elemento)->sNombre_Del_Varietal) ? true : false;
}

/*
    PRE: Debe existir la lista de catalogos.
    POST: Devuelvo la lista de los varietales que existen en el catalogo.
 */
Lista* varietalesQueHay(Lista* lCatalogo) {
    Lista* lAux = crearLista();
    Lista* lVarietales = crearLista();
    ELEMENTO vino;

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lCatalogo); i++) {
        obtenerElementoDeLaLista(lCatalogo, i, vino);

        if (buscarElementoEnLaLista(lAux, (eVinos*) vino, compararVarietalDelVino) == ELEMENTO_NO_ENCONTRADO)
            insertarElementoAlFinalDeLaLista(lAux, (eVinos*) vino);
        
    }

    ELEMENTO temp;
    for (int i = 0; i < getCantidadDeElementosEnLaLista(lAux); i++) {
        obtenerElementoDeLaLista(lAux, i, vino);
        temp = crearDatoDeVarietal(getVarietal((eVinos*) vino));
        insertarElementoAlFinalDeLaLista(lVarietales, (DatoVarietalPorGrupoEtario*) temp);
    }

    destruirLista(lAux);

    return lVarietales;
}

/*
    PRE: Debe existir el usuario y la lista del grupo etario.
    POST: Comparo si el usuario existe o no en la lista y si no esta en la lista lo incorporo.
 */
void insertarUsuarioEnLaListaDeSuGrupoSiNoExisteYaEnElla(Lista* lGrupo_Etario, Usuario* usuario) {
    if (buscarElementoEnLaLista(lGrupo_Etario, (Usuario*) usuario, compararUsuario) == ELEMENTO_NO_ENCONTRADO)
        insertarElementoAlFinalDeLaLista(lGrupo_Etario, (Usuario*) usuario);
}

/*
    PRE: Indico el grupo etario del cliente, el varietal y el usuario con el que se debe operar.
    POST: Opero la lista del grupo etario que corresponda agregando el usuario que compro un X varietal si es que el usuario no ha comprado previamente dicho varietal e incremento la cantidad de ventas del varietal en su grupo en 1.
 */
void insertarUsuarioEnLaListaDeSuGrupo(std::string sGrupo_Etario, DatoVarietalPorGrupoEtario* varietales, Usuario* usuario) {

    if (sGrupo_Etario == "menoresDe30") {
        
        varietales->iCantidad_De_Ventas_Menores_De_30++;
        insertarUsuarioEnLaListaDeSuGrupoSiNoExisteYaEnElla(varietales->menoresDe30, usuario);
    
    } else if (sGrupo_Etario == "entre30Y50") {
        
        varietales->iCantidad_De_Ventas_Entre_30_Y_50++;
        insertarUsuarioEnLaListaDeSuGrupoSiNoExisteYaEnElla(varietales->entre30Y50, usuario);
    
    } else {
        
        varietales->iCantidad_De_Ventas_Mayores_De_50++;
        insertarUsuarioEnLaListaDeSuGrupoSiNoExisteYaEnElla(varietales->mayoresDe50, usuario);
        
    }
    
}

/*
    PRE: Debe existir la lista de varietal, de usuarios, de calatogo, debe existir la membresia y debo indicar el vino que deseo obtener de los que existen.
    POST: Inserto cada vino comprado en el grupo etario que corresponda en base al comprador.
 */
void identificarVarietalDelVino(Membresia* membresia, int iNumero_De_Vino, Lista* lUsuario, Lista* lCatalogos, Lista* lVarietales) {
    ELEMENTO vino, usuario, varietal;
    
    obtenerElementoDeLaLista(lCatalogos, buscarElementoEnLaLista(lCatalogos, (int*)stoi(getIDVinoDeLaMembresia(membresia, iNumero_De_Vino)), compararIDDelVinoConElDeLaMembresia), vino);
    obtenerElementoDeLaLista(lUsuario, buscarElementoEnLaLista(lUsuario, (const char**)getIDDelUsuarioDeLaMembresia(membresia).c_str(), compararIDDelUsuarioConElDeLaMembresia), usuario);
    obtenerElementoDeLaLista(lVarietales, buscarElementoEnLaLista(lVarietales, vino, compararNombreDelVarietalDelVinoConElDelDatoGrupoEtario), varietal);

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