#ifndef MARKETING_H
#define MARKETING_H

struct GrupoEtario{
    std::string sNombre_Del_Grupo_Etario;
    int iEdad_Minima;
    int iEdad_Maxima;
    Lista* lIntegrantes;
};

struct DatoRankingVarietalesPorGrupoEtario{
    std::string sNombre_Del_Grupo_Etario;
    int iContador;
};

void rankingVarietalesPorGrupoEtario(Lista* lMembresia, Lista* lUsuario, Lista* lCatalogos);

Lista* varietalesQueHay(Lista* lCatalogo);

GrupoEtario* crearGrupoEtario(std::string, int iEdad_Minima, int iEdad_Maxima);
std::string nombreDelGrupoEtario(GrupoEtario*);
Lista* integrantesDelGrupoEtario(GrupoEtario*);

void usuariosPorGrupoEtario(Lista* lUsuarios, GrupoEtario* &lGrupos_Etario1, GrupoEtario* &lGrupos_Etario2, GrupoEtario* &lGrupos_Etario3);

void mostrarDatoMmebresiasXD(Lista*);

#endif /* MARKETING_H */

