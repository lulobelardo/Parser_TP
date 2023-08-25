#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

/*
 * diccionario.h: define e implementa el tipo de dato diccionario.
 * 
 * OBSERVACIONES: El archivo para crear el diccionario debe cumplir con cierto
 * formato: debe contener únicamente palabras contenidas unicamente por letras
 * del ALFABETO establecido, con su respectiva funcion biyectiva implementada.
 * Las palabras deben estar separadas una de otra por un salto de linea.
 * 
 * En este caso, las palabras no pueden contener ' ', '-', 'á', 'é', 'í', 'ó', 
 * 'ú', 'ü', 'ñ', ni ningún otro caracter que no pertenezca al ALFABETO
 * establecido. Además, permite pero no distingue mayúsculas/minúsculas.
*/

#include "./arbol/arbol.h"
#include "../funciones/funciones.h" // Biyección del alfabeto y terminadores
#include <stdio.h> // Manejo de archivos

/**
 * Tipo de dato que representa al diccionario (es un Trie).
 */
typedef ANodo * Diccionario;

/**
 * Devuelve un diccionario con las palabras contenidas en el archivo.
 */
Diccionario diccionario_crear(FILE *);

/**
 * Destruye el diccionario.
 */
void diccionario_destruir(Diccionario);

#endif /* __DICCIONARIO_H__ */