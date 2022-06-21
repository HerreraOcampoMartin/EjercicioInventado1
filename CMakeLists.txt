cmake_minimum_required(VERSION 3.22)
project(EjercicioConTodo C)

set(CMAKE_C_STANDARD 99)

add_executable(EjercicioConTodo main.c src/Usuarios.c src/Usuarios.h src/GenerarDatosAleatorios.c src/GenerarDatosAleatorios.h)
