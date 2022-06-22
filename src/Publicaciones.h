#ifndef EJERCICIOCONTODO_PUBLICACIONES_H
#define EJERCICIOCONTODO_PUBLICACIONES_H

typedef struct publicacion{
    int id;
    char *texto;
    struct publicacion *siguiente;
} Publicacion;

typedef struct categoria{
    int tam;
    int numCategoria;
    char *nombreCategoria;
    Publicacion *primera;
    struct categoria *siguienteCategoria;
} Categoria;

typedef struct tablaCategorias{
    int cantCategorias;
    Categoria *primera;
} TablaCategorias;

TablaCategorias *inicializarCategorias();
Categoria *crearCategoria(char *nombreCategoria, int numCategoria);
void agregarCategoria(TablaCategorias *tabla, Categoria *nueva);
Publicacion *crearPublicacion(int id, char *texto);
Categoria *obtenerCategoria(TablaCategorias *tabla, int numPagina);
void agregarPublicacion(Categoria *categoria, Publicacion *nueva);
void imprimirCategoria(Categoria *categoria);
void liberarCategoria(Categoria *categoria);
void liberarTablaCategorias(TablaCategorias *tabla);

#endif
