#ifndef CARGARARCHIVOSENLISTA_H
#define CARGARARCHIVOSENLISTA_H

/*
    PRE: La lista debe haber sido creada.
    POST: La lista tendra cargados los datos de los usuarios almacenados en el .txt.
*/
void cargarDatosDeUsuarioEnLaLista(const char*, Lista*);

/*
    PRE: Debe existir el elemento que se desea mostrar y debe ser un usuario.
    POST: Muestro un dato de la lista de tipo usuario segun la posicion de la lista.
*/
void mostrarDatoUsuario(ELEMENTO);

/*
    PRE: La lista debe haber sido creada.
    POST: La lista tendra cargados los datos de los vinos almacenados en el .txt.
*/
void cargarCatalogoDeVinosEnLaLista(const char*, Lista*);

/*
    PRE: Debe existir el elemento que se desea mostrar y debe ser un vino.
    POST: Muestro un dato de la lista de tipo vino segun la posicion de la lista.
*/
void mostrarDatoVino(ELEMENTO);

#endif /* CARGARARCHIVOSENLISTA_H */

