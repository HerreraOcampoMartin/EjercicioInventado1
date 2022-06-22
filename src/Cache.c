#include "Cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pagina *hash[__NUMERO_DE_PAGINAS__] = {};

Cache *crearCache(int capacidad){
    Cache *cache = (Cache*) malloc(sizeof (Cache));

    if(cache == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    cache->primera = NULL;
    cache->capacidad = capacidad;
    cache->tam = 0;

    return cache;
}

Pagina *crearPagina(TablaCategorias *tabla, int numPagina){
    Pagina *nueva = (Pagina*) malloc(sizeof (Pagina));

    if(nueva == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    // Busca la categoría y guarda el puntero a la misma para la caché.

    nueva->siguiente = NULL;
    nueva->anterior = NULL;
    nueva->numPagina = numPagina;
    nueva->puntero = obtenerCategoria(tabla, numPagina);

    return nueva;
}

Pagina *solicitarPagina(TablaCategorias *tabla, Cache *cache, int numPagina){
    Pagina *pagina = hash[numPagina];

    if(pagina == NULL){
        pagina = crearPagina(tabla, numPagina);
        if (cache->capacidad == cache->tam){
            eliminarUltimoElemento(cache);
        }
        apilar(cache, pagina);
    }else {
        if(cache->primera != pagina){
            pagina->anterior->siguiente = pagina->siguiente;
            if(pagina->siguiente != NULL){
                pagina->siguiente->anterior = pagina->anterior;
            }
            cache->tam--;
            apilar(cache, pagina);
        }
    }

    return pagina;
}

void apilar(Cache *cache, Pagina *pagAInsertar){
    if(cache->primera != NULL){
        cache->primera->anterior = pagAInsertar;
    }

    pagAInsertar->siguiente = cache->primera;
    cache->primera = pagAInsertar;
    hash[pagAInsertar->numPagina] = pagAInsertar;
    cache->tam++;
}

void eliminarUltimoElemento(Cache *cache){
    Pagina *aux = cache->primera;

    if(aux == NULL){
        return;
    }

    for(; aux->siguiente != NULL; aux = aux->siguiente){}

    if(aux->anterior != NULL){
        aux->anterior->siguiente = NULL;
    }
    hash[aux->numPagina] = NULL;
    free(aux);
}
void inicializarHashDeCache(){
    for (int i = 0; i < __NUMERO_DE_PAGINAS__; ++i) {
        hash[i] = NULL;
    }
}

void imprimirCache(Cache *cache){
    Pagina *aux = cache->primera;

    if(aux == NULL){
        printf("La caché está vacía.\n");
        return;
    }

    for (; aux != NULL; aux = aux->siguiente) {
        printf("* Pagina %d: %s\n", aux->numPagina, aux->puntero->nombreCategoria);
    }
    printf("\n");

}

void liberarCache(Cache *cache){
    Pagina *aux = cache->primera;

    while (aux != NULL){
        Pagina *sig = aux->siguiente;
        free(aux);
        aux = sig;
    }

    free(cache);
}
