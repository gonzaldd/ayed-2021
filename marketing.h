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
    PRE: Debe existir la lista de la membresia y la lista del catalogo.
    POST: Muestra por consola el ranking de vinos del ultimo año y retorna la lista de dicho ranking.
*/
Lista* rankingVinosUltimoAnio(Lista *listaAnioMembresias, Lista *listaVinos);

/*
    PRE: Debe existir la lista de ranking de vinos del ultimo año.
    POST: Muestra por consola el ranking de bodegas del ultimo año.
*/
void rankingBodegasUltimoAnio(Lista *listaRankingVinos);


#endif /* MARKETING_H */

