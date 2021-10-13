#ifndef ARCHIVOUSUARIO_H
#define ARCHIVOUSUARIO_H

/*
    PRE: La lista debe haber sido creada.
    POST: La lista tendra cargados los datos de los usuarios almacenados en el .txt.
*/
void cargarDatosDeUsuarioEnLaLista(const char*, Lista*&);

/*
    PRE:La lista debe haber sido creada.
    POST: Se muestra por consola los datos de todos los usuarios que hay en la lista.
*/
void mostrarDatosDeLosUsuariosEnLaLista(Lista*&);

#endif // !ARCHIVOUSUARIO_H
