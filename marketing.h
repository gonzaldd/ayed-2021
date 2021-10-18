#ifndef MARKETING_H
#define MARKETING_H

struct DatoVarietalPorGrupoEtario{
    std::string sNombre_Del_Varietal;
    Lista* menoresDe30;
    Lista* entre30Y50;
    Lista* mayoresDe50;
};

//DatoVarietalPorGrupoEtario* crearDatoDeVarietal(std::string sNombre_Del_Varietal);
//std::string getNombreDelVarietal(DatoVarietalPorGrupoEtario*);

//void insertarUsuarioEnLaListaDeSuGrupo(std::string sGrupo_Etario, DatoVarietalPorGrupoEtario* lVarietales, Usuario* usuario);
void rankingVarietalesPorGrupoEtario(Lista* lMembresia, Lista* lUsuario, Lista* lCatalogos);
//void identificarVarietalDelVino(Membresia* membresia, std::string getIDVinoDeLaMembresia(Membresia* m), Lista* lUsuario, Lista* lCatalogos, Lista* &lVarietales);

//Lista* varietalesQueHay(Lista* lCatalogo);

#endif /* MARKETING_H */

