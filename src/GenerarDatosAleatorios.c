#include "GenerarDatosAleatorios.h"
#include <stdlib.h>
#include <time.h>

#define __EDAD_MAX__ 99
#define __EDAD_MIN__ 18
#define __INICIO_CARACTERES__  97 // A partir de que número empiezan los caraceteres en la tabla ascii
// En este caso el 97 es 'a'
#define __FIN_CARACTERES__ 122 // 122 es 'z'

char *ciudades[] = {"Buenos Aires", "Rosario", "Mar del Plata", "Córdoba",
                    "Tucumán", "Bahía Blanca", "Tandil", "La Plata"};

void inicializarSRAND(){
    srand(time(0));
}

char *generarUsuario(){
    int longUsuario = 6, i;
    char *usuario = (char*) malloc(sizeof (char) * (longUsuario+1));

    for (i = 0; i < longUsuario; i++) {
        char letra = rand() % (__FIN_CARACTERES__ - __INICIO_CARACTERES__) + __INICIO_CARACTERES__;
        usuario[i] = letra;
    }

    usuario[i] = '\0';

    return usuario;
}

char *generarCiudad(){
    int cantCiudades = 8;
    int i = rand() % cantCiudades;
    return ciudades[i];
}

int generarEdad(){
    return rand() % (__EDAD_MAX__ - __EDAD_MIN__) + __EDAD_MIN__;
}