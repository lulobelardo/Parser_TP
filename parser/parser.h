#ifndef __PARSER_H__
#define __PARSER_H__

/*
 * parser.h: define los datos e implementa las funciones necesarias para el 
 * funcionamiento del analizador-sitáctico / parser.
*/

#include "../cola/cola.h"
#include "../diccionario/diccionario.h"
#include "../caracter/caracter.h"
#include "../archivos/archivos.h"
#include "../funciones/funciones.h"
#include <string.h> //strcat, strncat, strlen

#define LARGO_MAXIMO 131072 // Largo máximo permitido de una linea de entrada

/*
 * Tipo de dato que contiene el la linea de entrada corregida, la cantidad de 
 * ' ' agregados y todos los caracteres eliminados.
 */
typedef struct _LineaDeSalida {
  char * resultado;
  int contadorEspaciosAgregados;
  Cola errores;
} LineaDeSalida;

/*
 * Devuelve una LineaDeSalida nueva/vacía.
 */
LineaDeSalida lineaDeSalida_crear(size_t);

/*
 * Destruye la lineaDeSalida.
 */
void lineaDeSalida_destruir(LineaDeSalida);

/*
 * Toma el diccionario y la linea a analizar y retorna la lineaDeSalida, la 
 * cual contiene la linea corregida y los errores que tiene.
 */
LineaDeSalida parser_analizar_linea(Diccionario, char *);

/*
 * Toma los archivos abiertos y ejecuta el parser.
 * Crea el diccionario y luego ejecuta el analizador linea por linea.
 */
int parser(Archivos *);

/*
 * Toma una LineaDeSalida y un archivo de escritura y escribe la linea 
 * correctamente y sus errores. 
 */
LineaDeSalida imprimir_en_archivo(LineaDeSalida lineaSalida, FILE * archivo);

#endif /* __PARSER_H__ */