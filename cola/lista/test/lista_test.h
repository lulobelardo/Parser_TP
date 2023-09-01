#ifndef __LISTA_TEST_H__
#define __LISTA_TEST_H__

/*
 * Tests de lista.h.
*/

#include "../lista.h"
#include "../../../caracter/caracter.h"
#include <assert.h>

/*
 * Test de lista_crear.
 */
void test_lista_crear();

/*
 * Test de lista_vacia.
 */
void test_lista_vacia();

/*
 * Test de lista_agregar_final.
 */
void test_lista_agregar_final();

/*
 * Llama a las funciones test_.
 */
void test_lista();

#endif /* __LISTA_TEST_H__ */