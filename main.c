#include "src/Usuarios.h"
#include "src/GenerarDatosAleatorios.h"
#include "src/Publicaciones.h"
#include "src/Cache.h"
#define __CANT_USUARIOS 500

int main() {
    inicializarSRAND();

    ListaUsuarios *tabla[__B__];
    inicializarTabla(tabla);

    for (int i = 0; i < __CANT_USUARIOS; i++) {
        char *u = generarTexto(6); // El usuario tiene una longitud de 6 caracteres
        char *c = generarCiudad();
        int e = generarEdad();
        agregarUsuario(tabla, crearUsuario(u, c, e));
    }

    imprimirLista(tabla, 10);

    TablaCategorias *categorias = inicializarCategorias();
    char *titulos[] = {"Categoría 0", "Categoría 1", "Categoría 2",
                       "Categoría 3", "Categoría 4", "Categoría 5"};

    int cantCategorias = 6, publicacionesPorCategoria = 10;
    for (int i = 0; i < cantCategorias; ++i) {
        Categoria *nueva = crearCategoria(titulos[i], i);
        for (int j = 0; j < publicacionesPorCategoria; ++j) {
            Publicacion *p = crearPublicacion(i*10 + j, generarTexto(20));
            agregarPublicacion(nueva, p);
        }

        agregarCategoria(categorias, nueva);
    }

    Cache *cache = crearCache(3);
    inicializarHashDeCache();

    Pagina *pag = solicitarPagina(categorias, cache, 2);
    imprimirCategoria(pag->puntero);
    pag = solicitarPagina(categorias, cache, 4);
    imprimirCategoria(pag->puntero);
    pag = solicitarPagina(categorias, cache, 1);
    imprimirCategoria(pag->puntero);
    pag = solicitarPagina(categorias, cache, 0);
    imprimirCategoria(pag->puntero);


    imprimirCache(cache);

    liberarCache(cache);
    liberarTablaUsuarios(tabla);
    liberarTablaCategorias(categorias);

    return 0;
}