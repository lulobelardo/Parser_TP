#include "lista.h"

/**
 * Devuelve una lista vacía.
 */
Lista lista_crear() {
  Lista lista;
  lista.primero = NULL;
  lista.ultimo = NULL;
  return lista;
}

/**
 * Destruccion de la lista.
 */
void lista_destruir(Lista lista, FuncionDestructora destruir) {
  LNodo * nodoABorrar;
  while (lista.primero != NULL) {
    nodoABorrar = lista.primero;
    lista.primero = lista.primero->sig;
    destruir(nodoABorrar->dato);
    free(nodoABorrar);
  }
}

/**
 * Determina si la lista es vacía.
 */
int lista_vacia(Lista lista) {
  return lista.primero == NULL;
}

/**
 * Agrega un elemento al final de la lista.
 */
Lista lista_agregar_final(Lista lista, void * dato, FuncionCopia copiar) {
  LNodo * nuevoNodo = malloc(sizeof(LNodo));
  nuevoNodo->dato = copiar(dato);
  nuevoNodo->sig = NULL;

  if(lista_vacia(lista))
    lista.primero = nuevoNodo;
  else
    lista.ultimo->sig = nuevoNodo;

  lista.ultimo = nuevoNodo;
  return lista;
}

/**
 * Recorre la lista, utilizando la funcion pasada.
 */
void lista_recorrer(Lista lista, FuncionVisitante visitante) {
  for (LNodo * nodo = lista.primero; nodo != NULL; nodo = nodo->sig)
    visitante(nodo->dato);
}