#include "arbol_test.h"

/*
 * Test de arbol_nodo_crear. 
 */
void test_arbol_nodo_crear() {
  ANodo * raiz = arbol_nodo_crear();
  assert(raiz);
  assert(raiz->esFinDePalabra == 0);
  assert(raiz->hijo == NULL);
  arbol_destruir(raiz);
}

/*
 * Test de arbol_desplazarse. 
 */
void test_arbol_desplazarse() {
  ANodo * raiz = arbol_nodo_crear();
  ANodo * nodo = arbol_desplazarse(raiz, 5);
  assert(nodo);
  assert(raiz->hijo[5] == nodo);
  assert(nodo->hijo == NULL);
  assert(nodo->esFinDePalabra == 0);

  ANodo * nodo2 = arbol_desplazarse(raiz, 5);
  assert(nodo == nodo2);

  assert(raiz->hijo[4] == NULL);
  arbol_destruir(raiz);
}

/*
 * Test de arbol_pertenece_al_nodo. 
 */
void test_arbol_pertenece_al_nodo() {
  ANodo * raiz = arbol_nodo_crear();
  assert(arbol_pertenece_al_nodo(raiz, 5) == 0);
  ANodo * nodo = arbol_desplazarse(raiz, 5);
  assert(arbol_pertenece_al_nodo(raiz, 5));
  assert(arbol_pertenece_al_nodo(nodo, 5) == 0);

  arbol_destruir(raiz);
}

/*
 * Test de validar_nodo. 
 */
void test_arbol_validar_nodo() {
  ANodo * raiz = arbol_nodo_crear();
  ANodo * nodo1 = arbol_desplazarse(raiz, 1);
  assert(nodo1->esFinDePalabra == 0);
  ANodo * nodo = arbol_validar_nodo(nodo1, raiz);
  assert(nodo1->esFinDePalabra == 1);
  assert(nodo == raiz);
  arbol_validar_nodo(nodo, raiz);
  assert(nodo->esFinDePalabra == 0);
  arbol_destruir(raiz);
}

/*
 * Llama a las funciones test_.
*/
void test_arbol() {
  test_arbol_nodo_crear();
  test_arbol_desplazarse();
  test_arbol_pertenece_al_nodo();
  test_arbol_validar_nodo();
}