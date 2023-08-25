#ifndef __ARCHIVOS_H__
#define __ARCHIVOS_H__

/*
 * archivos.h: Manejar la apertura y clausura de archivos.
*/

#include <stdio.h> // Manejo de archivos
#include <stdlib.h> // Manejo de memoria
#include <assert.h> // Chequeo de correcto asignamiento de memoria

/**
 * Tipo de dato contenedor de los archivos pasados como argumento.
 */
typedef struct _Archivos {
  FILE * diccionario, * entrada, * salida;
} Archivos;

/**
 * Abre los archivos [1]"r",[2]"r",[3]"w" y los devuelve.
 */
Archivos * archivos_abrir(char const * []);

/**
 * Cierra los archivos.
 */
void archivos_cerrar(Archivos *);

/**
 * Cierra archivo->diccionario.
 */
void archivos_cerrar_diccionario(Archivos *);

#endif /* __ARCHIVOS_H__ */