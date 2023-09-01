#ifndef __CARACTER_H__
#define __CARACTER_H__

/*
 * carceter.h define las funciones necesarias para manipular el tipo de dato 
 * interesado (char) en las colas genericas.
*/

#include <stdlib.h> // Manejo de memoria
#include <stdio.h> // Printf
#include <assert.h> // Chequeo de correcto asignamiento de memoria

/**
 * Libera la memoria del caracter. (FuncionDestructora).
 */
void caracter_destruir(char *);

/**
 * Copia el valor del puntero pasado en un nuevo puntero y lo retorna.
 * (FuncionCopia).
 */
char * caracter_copiar(char const *);

/*
 * Imprime el caracter en pantalla. (FuncionVisitante).
 */
void caracter_imprimir(char *);

#endif /* __CARACTER_H__ */