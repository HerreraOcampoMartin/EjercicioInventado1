#include "Usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash (char *usuario){
    int suma = 0;

    for(int i = 0; i < strlen(usuario); i++){
        suma += usuario[i];
    }

    return suma % __B__;
}

ListaUsuarios *crearListaUsuarios(){
    ListaUsuarios *lista = (ListaUsuarios*) malloc(sizeof (ListaUsuarios));

    if(lista == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    lista->tam = 0;
    lista->primero = NULL;

    return lista;
}

void inicializarTabla(ListaUsuarios **tabla){
    for (int i = 0; i < __B__; i++) {
        tabla[i] = crearListaUsuarios();
    }
}

Usuario *crearUsuario(char *usuario, char *ciudad, int edad){
    Usuario *usu = (Usuario*) malloc(sizeof (Usuario));

    if(usu == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    usu->usuario = usuario;
    usu->ciudad = ciudad;
    usu->edad = edad;
    usu->siguiente = NULL;

    return usu;
}

void agregarUsuario(ListaUsuarios **tabla, Usuario *nuevo){
    int clase = hash(nuevo->usuario);
    nuevo->siguiente = tabla[clase]->primero;
    tabla[clase]->primero = nuevo;
    tabla[clase]->tam++;
}

void eliminarUsuario(ListaUsuarios **tabla, char *usuario){
    int clase = hash(usuario);

    Usuario *act = tabla[clase]->primero;
    Usuario *ant = act;

    while(act != NULL && strcmp(act->usuario, usuario) != 0){
        ant = act;
        act = act->siguiente;
    }

    if(act == NULL){
        return;
    }

    if(act == ant){
        tabla[clase]->primero = act->siguiente;
        free(act);
    }else {
        ant->siguiente = act->siguiente;
        free(act);
    }
    tabla[clase]->tam--;
}

void imprimirLista(ListaUsuarios **tabla, int numPagina){
    Usuario *aux = tabla[numPagina]->primero;

    if(aux == NULL){
        printf("Esta página está vacía.\n");
        return;
    }

    for(; aux != NULL; aux = aux->siguiente){
        printf("Usuario: %s - Ciudad: %s - Edad: %d\n", aux->usuario, aux->ciudad, aux->edad);
    }

    printf("\n");
}

void liberarLista(ListaUsuarios *lista){
    Usuario *act = lista->primero;

    while(act != NULL){
        Usuario *aux = act->siguiente;
        free(act);
        act = aux;
    }

    free(lista);
}

void liberarTabla(ListaUsuarios **tabla){
    for (int i = 0; i < __B__; i++) {
        liberarLista(tabla[i]);
    }
}