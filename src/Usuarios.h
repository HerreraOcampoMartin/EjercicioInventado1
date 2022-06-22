#ifndef EJERCICIOCONTODO_USUARIOS_H
#define EJERCICIOCONTODO_USUARIOS_H
#define __B__ 128

typedef struct usuario{
    char *usuario;
    char *ciudad;
    int edad;
    struct usuario *siguiente;
} Usuario;

typedef struct listaUsuarios{
    int tam;
    Usuario *primero;
} ListaUsuarios;

void inicializarTabla(ListaUsuarios **tabla);
ListaUsuarios *crearListaUsuarios();
Usuario *crearUsuario(char *usuario, char *ciudad, int edad);
void agregarUsuario(ListaUsuarios **tabla, Usuario *nuevo);
void imprimirLista(ListaUsuarios **tabla, int numPagina);

void liberarLista(ListaUsuarios *lista);
void liberarTablaUsuarios(ListaUsuarios **tabla);


#endif
