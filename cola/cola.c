#include "cola.h"

/**
 * Devuelve una cola vacia.
 */
Cola cola_crear() {
  return lista_crear();
}

/**
 * Destruccion de la cola.
 */
void cola_destruir(Cola cola, FuncionDestructora destruir) {
  lista_destruir(cola, destruir);
}

/**
 * Determina si la cola es vacia.
 */
int cola_vacia(Cola cola) {
  return lista_vacia(cola);
}

/**
 * Devuelve el puntero al dato almacenado al comienzo de la cola.
 */
void * cola_inicio(Cola cola) {
  if (!cola_vacia(cola))
    return cola.primero->dato;

  return NULL;
}

/**
 * Agrega un elemento al final de la cola.
 */
Cola cola_encolar(Cola cola, void * dato, FuncionCopia copiar) {
  return lista_agregar_final(cola, dato, copiar);
}

/**
 * Elimina el primer elemento de la cola.
 */
Cola cola_desencolar(Cola cola, FuncionDestructora destruir) {
  if (cola_vacia(cola))
    return cola;

  LNodo * nodoABorrar = cola.primero;
  cola.primero = cola.primero->sig;
  if (cola.primero == NULL)
    cola.ultimo = NULL;
  destruir(nodoABorrar->dato);
  free(nodoABorrar);
  return cola;
}

/*
 * Imprime la cola.
 */
void cola_imprimir(Cola cola, FuncionVisitante visitante) {
  lista_recorrer(cola, visitante);
}