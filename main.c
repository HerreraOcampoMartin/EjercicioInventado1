#include "src/Usuarios.h"
#include "src/GenerarDatosAleatorios.h"
#define __CANT_USUARIOS 500

int main() {
    inicializarSRAND();

    ListaUsuarios *tabla[__B__];

    inicializarTabla(tabla);

    for (int i = 0; i < __CANT_USUARIOS; i++) {
        char *u = generarUsuario();
        char *c = generarCiudad();
        int e = generarEdad();
        agregarUsuario(tabla, crearUsuario(u, c, e));
    }

    imprimirLista(tabla, 10);

    liberarTabla(tabla);

    return 0;
}
