#include <fstream>
#include <algorithm>
#include "loadMembresia.h"

struct Membresia {
    std::string id_usuario;
    std::string mes;
    std::string anio;
    std::string id_vino_1;
    std::string id_vino_2;
    std::string id_vino_3;
    std::string id_vino_4;
    std::string id_vino_5;
    std::string id_vino_6;
};


void readFile(std::string path, Lista &lista) {
    std::ifstream archivo(path.c_str());
    std::string linea;

    while (getline(archivo, linea)) {
        std::string * valores = splitStrByChar(linea, "-");
        std::cout << valores[1] << "  " << valores[2] << std::endl;

        //todo:
        //crear membresia
        //meterla en la lista correspondiente
    };

}


//return [id_usuario, mes, anio, id_vino_1, id_vino2, ...]
std::string* splitStrByChar(std::string str, std::string del) {
    int start = 0;
    int end = str.find(del);
    int position = 0;
    //array que contiene los datos separados
    std::string* values = new std::string[9];

    //limpio los datos de espacios, tabs & ;
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ';'), str.end());

    //Separo los datos por el caracter del param del
    while (end != -1) {
        values[position] = str.substr(start, end - start);
        start = end + del.size();
        end = str.find(del, start);
        position++;
    }
    values[8] = str.substr(start, end - start);

    return values;
}

