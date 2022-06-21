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
void eliminarUsuario(ListaUsuarios **tabla, char *usuario);
void imprimirLista(ListaUsuarios **tabla, int numPagina);
int verificarQueUsuarioNoSeRepita(ListaUsuarios **tabla, char *nuevo);

void liberarLista(ListaUsuarios *lista);
void liberarTabla(ListaUsuarios **tabla);


#endif
