#ifndef MARKETING_H
#define MARKETING_H

struct DatoRanking {
    std::string id_vino;
    std::string etiqueta_vino;
    std::string nombre_bodega;
    int contador = 0;
};

/*
    PRE: Debe existir la lista de la membresia, de los usuarios y la lista del catalogo.
    POST: Devuelve por consola el ranking de los varietales por grupo etario.
*/
void rankingVarietalesPorGrupoEtario(Lista* lMembresia, Lista* lUsuario, Lista* lCatalogos);

/*
    PRE: Debe existir la lista de la membresia, la lista del catalogo y 1 variable de tipo int donde almacenar el año.
    POST: Retorna la lista de datos para los rankings.
*/
Lista* listaParaHacerLosRankings(Lista *listaAnioMembresias, Lista *listaVinos,  int &maxYear);

/*
    PRE: Debe existir la lista de los datos del ranking, funcion anterior, y las 2 variables de tipo int donde se almacenaron la cantidad de ventas y el año.
    POST: Muestra por consola el ranking de vinos del ultimo año.
*/
void rankingVinosUltimoAnio(Lista* listaRanking,  int maxYear);

/*
    PRE: Debe existir la lista de ranking de vinos del ultimo año y una varieble de tipo int que indique el año.
    POST: Muestra por consola el ranking de bodegas del ultimo año.
*/
void rankingBodegasUltimoAnio(Lista *listaRankingVinos, int maxYear);


#endif /* MARKETING_H */

