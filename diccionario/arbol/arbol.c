#include "arbol.h"

/**
 * Devuelve un nuevo nodo tal que esFinDePalabra = 0.
 */
ANodo * arbol_nodo_crear() {
  ANodo * nuevoNodo = malloc(sizeof(ANodo));
  assert(nuevoNodo);
  nuevoNodo->esFinDePalabra = 0;
  nuevoNodo->hijo = NULL;
  return nuevoNodo;
}

/**
 * Destruccion del arbol.
 */
void arbol_destruir(ANodo * nodo) {
  if (nodo == NULL)
    return;

  if (nodo->hijo) {
    for (int i = 0; i < LARGO_ALFABETO; i++)
      arbol_destruir(nodo->hijo[i]);
    free(nodo->hijo);
  }
  
  free(nodo);
}

/**
 * Determina si el nodo posee un hijo en el indice indicado.
 */
int arbol_pertenece_al_nodo(ANodo * nodo, int letra) {
  return (letra != -1 && nodo->hijo && nodo->hijo[letra]);
}

/**
 * Toma un nodo y se desplaza en el indice indicado, retornandolo. Si no existe, lo crea.
 */
ANodo * arbol_desplazarse(ANodo * nodo, int indice) {
  if (nodo->hijo == NULL) {
    nodo->hijo = malloc(sizeof(ANodo *) * LARGO_ALFABETO);
    assert(nodo->hijo);
    for (size_t i = 0; i < LARGO_ALFABETO; i++)
      nodo->hijo[i] = NULL;
    
  }
  if (nodo->hijo[indice] == NULL) {
    nodo->hijo[indice] = arbol_nodo_crear();
  }
  return nodo->hijo[indice];
}

/**
 * Toma dos nodos. Si el primero difiere del segundo, valida esFinDePalabra = 0 del primero. retorna el segundo.
 */
ANodo * arbol_validar_nodo(ANodo * nodo, ANodo * arbol) {
  if (nodo != arbol) {
    nodo->esFinDePalabra = 1;
  }
  return arbol;
}