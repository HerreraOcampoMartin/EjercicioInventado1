#ifndef EJERCICIOCONTODO_CACHE_H
#define EJERCICIOCONTODO_CACHE_H

#include "Publicaciones.h"

#define __NUMERO_DE_PAGINAS__ 128

typedef struct pagina{
    int numPagina;
    Categoria *puntero;
    struct pagina *siguiente;
    struct pagina *anterior;
} Pagina;

typedef struct cache{
    Pagina *primera;
    int tam;
    int capacidad;
} Cache;

Cache *crearCache(int capacidad);
Pagina *crearPagina(TablaCategorias *tabla, int numPagina);
Pagina *solicitarPagina(TablaCategorias *tabla, Cache *cache, int numPagina);
void apilar(Cache *cache, Pagina *pagAInsertar);
void eliminarUltimoElemento(Cache *cache);
void inicializarHashDeCache();
void imprimirCache(Cache *cache);
void liberarCache(Cache *cache);

#endif
