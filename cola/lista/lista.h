#ifndef __LISTA_H__
#define __LISTA_H__

/*
 * lista.h: define e implementa listas simplemente enlazadas para datos 
 * genéricos, con puntero al comienzo y al final.
*/

#include <stdlib.h> // Manejo de memoria

/**
 * Definicion de funciones para tipos de dato genéricos.
 */
typedef void (*FuncionDestructora)(void *);
typedef void *(*FuncionCopia)(void *);
typedef void (*FuncionVisitante)(void *);

/**
 * Tipo de dato representante de cada Nodo de una lista.
 */
typedef struct _LNodo {
  void * dato;
  struct _LNodo * sig;
} LNodo;

/**
 * Tipo de dato representante lista.
 */
typedef struct _Lista {
  LNodo * primero, * ultimo;
} Lista;

/**
 * Devuelve una lista vacía.
 */
Lista lista_crear();

/**
 * Destruccion de la lista.
 */
void lista_destruir(Lista, FuncionDestructora);

/**
 * Determina si la lista es vacía.
 */
int lista_vacia(Lista);

/**
 * Agrega un elemento al final de la lista.
 */
Lista lista_agregar_final(Lista, void *, FuncionCopia);

/**
 * Recorre de la lista, utilizando la funcion pasada.
 */
void lista_recorrer(Lista, FuncionVisitante);

#endif /* __LISTA_H__ */