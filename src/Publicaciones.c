#include "Publicaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TablaCategorias *inicializarCategorias(){
    TablaCategorias *tabla = (TablaCategorias*) malloc(sizeof (TablaCategorias));

    if(tabla == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    tabla->primera = NULL;
    tabla->cantCategorias = 0;

    return tabla;
}

Categoria *crearCategoria(char *nombreCategoria, int numCategoria){
    Categoria *categoria = (Categoria*) malloc(sizeof (Categoria));

    if(categoria == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    categoria->primera = NULL;
    categoria->tam = 0;
    categoria->numCategoria = numCategoria;
    categoria->nombreCategoria = nombreCategoria;
    categoria->siguienteCategoria = NULL;

    return categoria;
}

void agregarCategoria(TablaCategorias *tabla, Categoria *nueva){
    nueva->siguienteCategoria = tabla->primera;
    tabla->primera = nueva;
    tabla->cantCategorias++;
}

Publicacion *crearPublicacion(int id, char *texto){
    Publicacion *publicacion = (Publicacion*) malloc(sizeof (Publicacion));

    if(publicacion == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    publicacion->siguiente = NULL;
    publicacion->texto = texto;
    publicacion->id = id;

    return publicacion;
}

Categoria *obtenerCategoria(TablaCategorias *tabla, int numPagina){
    Categoria *aux = tabla->primera;

    for(; aux != NULL; aux = aux->siguienteCategoria){
        if(aux->numCategoria == numPagina){
            break;
        }
    }

    return aux;
}

void agregarPublicacion(Categoria *categoria, Publicacion *nueva){
    nueva->siguiente = categoria->primera;
    categoria->primera = nueva;
    categoria->tam++;
}

void imprimirCategoria(Categoria *categoria){
    Publicacion *aux = categoria->primera;

    printf("\n%s:\n", categoria->nombreCategoria);
    if(aux == NULL){
        printf("Esta categoría está vacía ¯\\_(ツ)_/¯ .\n");
    }

    for (; aux != NULL; aux = aux->siguiente) {
        printf("Publicación %d:\n%s\n", aux->id, aux->texto);
    }
}

void liberarCategoria(Categoria *categoria){
    Publicacion *aux = categoria->primera;
    while(aux != NULL){
        Publicacion *sig = aux->siguiente;
        free(aux);
        aux = sig;
    }

    free(categoria);
}

void liberarTablaCategorias(TablaCategorias *tabla){
    Categoria *aux = tabla->primera;
    while(aux != NULL){
        Categoria *sig = aux->siguienteCategoria;
        liberarCategoria(aux);
        aux = sig;
    }

    free(tabla);
}
