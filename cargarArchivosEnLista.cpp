#include <iostream>
#include <fstream>

#include "Usuario/usuario.h"
#include "Vinos/Vinos.h"
#include "ED/lista.h"

#include "cargarArchivosEnLista.h"

void cargarDatosDeUsuarioEnLaLista(const char* sNombre_Archivo, Lista* &lista) {
    std::ifstream Lectura;
    Lectura.open(sNombre_Archivo, std::ios::in);

    if (Lectura.is_open()) {
        std::string sLector;
        bool bCapital;
        std::string sID, sNombre, sApellido, sDireccion, sLocalidad, sProvincia, sEdad;

        Lectura >> sLector; //ID o eof

        while (!Lectura.eof()) {
            bCapital = false;
            sID = sLector;

            Lectura >> sLector; // guion

            Lectura >> sNombre;
            Lectura >> sApellido;

            Lectura >> sLector; // guion

            Lectura >> sDireccion;

            while ((sDireccion.substr(sDireccion.length() - 1)).find(",")) {
                Lectura >> sLector;
                sDireccion += " " + sLector;
            }
            sDireccion = sDireccion.substr(0, sDireccion.length() - 1);

            Lectura >> sLocalidad;

            while ((sLocalidad.substr(sLocalidad.length() - 1)).find(",") && !bCapital) {
                Lectura >> sLector;

                if (sLector != "-") {
                    sLocalidad += " " + sLector;
                } else
                    bCapital = true;

            }

            if (!bCapital) {
                sLocalidad = sLocalidad.substr(0, sLocalidad.length() - 1);

                Lectura >> sProvincia;
                Lectura >> sLector;


                while (sLector.find("-")) {
                    sProvincia += " " + sLector;
                    Lectura >> sLector;
                }

            } else {
                sProvincia = sLocalidad;
            }

            Lectura >> sEdad;
            Lectura >> sLector;

            ELEMENTO u = crearUsuario(sID, sNombre, sApellido, sDireccion, sLocalidad, sProvincia, stoi(sEdad));
            insertarElementoAlFinalDeLaLista(lista, (Usuario*) u);

            Lectura >> sLector; //ID o eof
        }

        Lectura.close();
    } else
        std::cout << "\nError al abir el archivo" << std::endl;
}

void mostrarDatosDeLosUsuariosEnLaLista(Lista* &lista) {
    ELEMENTO u;

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lista); i++) {
        obtenerElementoDeLaLista(lista, i, u);
        mostrarUsuario((Usuario*) u);
    }

}

void cargarCatalogoDeVinosEnLaLista(const char* sNombre_Archivo, Lista* &lista) {
    std::ifstream Lectura;
    Lectura.open(sNombre_Archivo, std::ios::in);

    if (Lectura.is_open()) {
        std::string sLector;
        std::string sID, sEtiqueta, sBodega, sSegmento, sVarietal, sAnio, sTerroir;

        Lectura >> sLector; //ID o eof

        while (!Lectura.eof()) {
            sID = sLector;

            Lectura >> sLector; // guion

            sEtiqueta = "a";
            Lectura >> sLector;
            while (sLector != "-") {
                sEtiqueta += " " + sLector;
                Lectura >> sLector;
            }
            sEtiqueta = sEtiqueta.substr(2, sEtiqueta.length());

            sBodega = "a";
            Lectura >> sLector;
            while (sLector != "-") {
                sBodega += " " + sLector;
                Lectura >> sLector;
            }
            sBodega = sBodega.substr(2, sBodega.length());

            Lectura >> sSegmento;
            Lectura >> sLector; // guion

            sVarietal = "a";
            Lectura >> sLector;
            while (sLector != "-") {
                sVarietal += " " + sLector;
                Lectura >> sLector;
            }
            sVarietal = sVarietal.substr(2, sVarietal.length());

            Lectura >> sAnio;
            Lectura >> sLector; // guion

            sTerroir = "a";
            Lectura >> sLector;
            while (sLector != ";") {
                sTerroir += " " + sLector;
                Lectura >> sLector;
            }
            sTerroir = sTerroir.substr(2, sTerroir.length());

            ELEMENTO v = crearVino(stoi(sID), sBodega, sEtiqueta, sVarietal, sSegmento, stoi(sAnio), sTerroir);
            insertarElementoAlFinalDeLaLista(lista, (eVinos*) v);

            Lectura >> sLector; //ID o eof
        }

        Lectura.close();
    } else
        std::cout << "\nError al abir el archivo" << std::endl;
}

void mostrarCatalogoDeVinos(Lista* &lista) {
    ELEMENTO v;

    for (int i = 0; i < getCantidadDeElementosEnLaLista(lista); i++) {
        obtenerElementoDeLaLista(lista, i, v);
        mostrarVino((eVinos*) v);
        std::cout << LINEA << std::endl;
    }
    
}