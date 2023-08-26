#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

/*
 * funciones.h: define funciones extras necesarias para el funcionamiento en 
 * conjunto del programa.
*/

#include <stdio.h> // Manejo de archivos
#include <assert.h> // Chequeo de correcto asignamiento de memoria y argumentos
#include <stdlib.h> // Manejo de memoria
#include <ctype.h> // toupper, isaplha
#include <string.h> // strlen, strcat, strncat

#define LARGO_TENTATIVO 128

/*
 * Devuelve si el caracter es un terminador en el contexto previamente 
 * establecido.
 */
int es_terminador(char);

/*
 * Devuelve la traducción / biyección del caracter pasado. Si es inválido 
 * retorna -1.
  0: A, 1: B, 2: C, 3: D, 4: E, 5: F, 6: G, 7: H, 8: I, 9: J, 10:K, 11:L, 12:M, 
  13:N, 14:O, 15:P, 16:Q, 17:R, 18:S, 19:T, 20:U, 21:V, 22:W, 23:X, 24:Y, 25:Z
 */
int validar_y_traducir_caracter(char);

/*
 * Toma una cadena NO NULA Y Borra el contenido de la cadena (a nivel usuario), 
 * haciendola vacía.
 */
void vaciar_cadena(char *);

/*
 * Toma una cadena NO NULA y devuelve si esta vacía.
 */
int cadena_es_vacia(char *);

/*
 * Toma un LARGO_MAXIMO y un archivo.
 * Devuelve una cadena con los valores de la linea a donde apunta el archivo.
 * El objetivo de esta funcion es reemplazar fgets, evitando tener un límite
 * fijo de memoria y evitando crear variables con cantidad abultada de memoria, 
 * sabiendo que es un archivo de texto escrito por alguien y no va a tener 
 * demasiadas lineas.
 */
char * obtener_linea_de_archivo(size_t, FILE *);

#endif /* __FUNCIONES_H__ */