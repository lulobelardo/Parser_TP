#ifndef __ARBOL_TEST_H__
#define __ARBOL_TEST_H__

/*
 * Tests de arbol.h.
*/

#include "../arbol.h"
#include <assert.h>

/*
 * Test de arbol_nodo_crear. 
 */
void test_arbol_nodo_crear();

/*
 * Test de arbol_desplazarse. 
 */
void test_arbol_desplazarse();

/*
 * Test de arbol_pertenece_al_nodo. 
 */
void test_arbol_pertenece_al_nodo();

/*
 * Test de validar_nodo. 
 */
void test_arbol_validar_nodo();

/*
 * Llama a las funciones test_.
*/
void test_arbol();

#endif /* __ARBOL_TEST_H__ */