#ifndef __COLA_H__
#define __COLA_H__

/*
 * cola.h: define e implementa colas para datos genéricos.
*/

#include "./lista/lista.h"
#include <stdlib.h> // Manejo de memoria

typedef Lista Cola;

/**
 * Devuelve una cola vacia.
 */
Cola cola_crear();

/**
 * Destruccion de la cola.
 */
void cola_destruir(Cola, FuncionDestructora);

/**
 * Determina si la cola es vacia.
 */
int cola_vacia(Cola);

/**
 * Devuelve el puntero al dato almacenado al comienzo de la cola.
 */
void * cola_inicio(Cola);

/**
 * Agrega un elemento al final de la cola.
 */
Cola cola_encolar(Cola, void *, FuncionCopia);

/**
 * Elimina el primer elemento de la cola.
 */
Cola cola_desencolar(Cola, FuncionDestructora);

/**
 * Imprime la cola.
 */
void cola_imprimir(Cola, FuncionVisitante);

#endif /* __COLA_H__ */