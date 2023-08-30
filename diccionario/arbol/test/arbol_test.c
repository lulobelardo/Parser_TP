#include "arbol_test.h"

void test_arbol() {
  ANodo * raiz = arbol_nodo_crear();
  assert(raiz);

  assert(arbol_pertenece_al_nodo(raiz, 5) == 0);

  ANodo * nodo = arbol_desplazarse(raiz, 5);

  assert(arbol_pertenece_al_nodo(raiz, 5));
  assert(arbol_pertenece_al_nodo(nodo, 5) == 0);

  nodo = arbol_validar_nodo(nodo, raiz);

  assert(nodo == raiz);
  assert(raiz->esFinDePalabra == 0);
  assert(raiz->hijo[5]->esFinDePalabra);

  nodo = arbol_desplazarse(raiz, 0);
  nodo = arbol_desplazarse(nodo, 8);
  nodo = arbol_desplazarse(nodo, 7);

  assert(nodo != raiz);
  assert(arbol_pertenece_al_nodo(raiz, 0));
  assert(arbol_pertenece_al_nodo(raiz->hijo[0], 8));
  assert(arbol_pertenece_al_nodo(raiz->hijo[0]->hijo[8], 7));
  assert(raiz->hijo[0]->hijo[8]->hijo == NULL);

  assert(arbol_desplazarse(raiz, 2) == raiz->hijo[2]);
  assert(arbol_desplazarse(nodo, 8) == nodo->hijo[8]);

  assert(nodo->hijo[8]->esFinDePalabra == 0);
  assert(raiz->hijo[2]->esFinDePalabra == 0);

  arbol_destruir(raiz);
}