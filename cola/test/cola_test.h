#ifndef __COLA_TEST_H__
#define __COLA_TEST_H__

/*
 * Tests de cola.h.
*/

#include "../cola.h"
#include "../../caracter/caracter.h"
#include <assert.h>

/*
 * Test de cola_crear.
 */
void test_cola_crear();

/*
 * Test de cola_vacia.
 */
void test_cola_vacia();

/*
 * Test de cola_encolar.
 */
void test_cola_encolar();

/*
 * Test de cola_inicio.
 */
void test_cola_inicio();

/*
 * Test de cola_desencolar.
 */
void test_cola_desencolar();

/*
 * Llama a las funciones test_.
 */
void test_cola();

#endif /* __COLA_TEST_H__ */