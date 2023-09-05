#ifndef __PARSER_TEST_H__
#define __PARSER_TEST_H__

/*
 * Test de parser.h.
*/

#include "../parser.h"
#include <assert.h>

#define CANTIDAD_TEST 7

/*
 * Test de lineaDeSalida_crear.
 */
void test_lineaDeSalida_crear();

/*
 * Test de parser_analizar_linea.
 */
void test_parser_analizar_linea();

/*
 * Retorna si dos archivos coinciden.
 */
int archivos_coinciden(FILE *, FILE *);

/*
 * LLama a las funciones test_ y es test de parser.
 */
void test_parser();

#endif /* __PARSER_TEST_H__ */