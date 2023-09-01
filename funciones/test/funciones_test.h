#ifndef __FUNCIONES_TEST_H__
#define __FUNCIONES_TEST_H__

/*
 * Tests de funciones.h.
*/

#include "../funciones.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
 * Test de es_terminador.
 */
void test_es_terminador();

/*
 * Test de validar_y_traducir_caracter.
 */
void test_validar_y_traducir_caracter();

/*
 * Test de cadena_es_vacia.
 */
void test_cadena_es_vacia();

/*
 * Test de vaciar_cadena
 */
void test_vaciar_cadena();

/*
 * Test de obtener_linea_de_archivo.
 */
void test_obtener_linea_de_archivo();

/*
 * Llama a las funciones test_.
 */
void test_funciones();

#endif /* __FUNCIONES_TEST_H__ */