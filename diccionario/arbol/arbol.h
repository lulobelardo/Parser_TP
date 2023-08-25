#ifndef __ARBOL_H__
#define __ARBOL_H__

/*
 * arbol.h: define e implementa arboles (Trie) con las funciones necesarias.
 * 
 * OBSERVACIÓNES: Si bien los nodos no almacenan ningun tipo de dato, el mismo 
 * queda implicito en el hecho de existir o no existir como hijo/subnodo de
 * su padre. Es decir, siguiendo la función (abc) para el abecedario inglés:

  0: A, 1: B, 2: C, 3: D, 4: E, 5: F, 6: G, 7: H, 8: I, 9: J, 10:K, 11:L, 12:M, 
  13:N, 14:O, 15:P, 16:Q, 17:R, 18:S, 19:T, 20:U, 21:V, 22:W, 23:X, 24:Y, 25:Z

 * Digasé, si nodo->hijo[@] existe, entonces nodo->hijo[@] != NULL y la 
 * biyeccion de @ es la letra perteneciente al Trie.
 * Además, si no existe nodo->hijo[@] para ningun valor, entonces 
 * nodo->hijo = NULL.
*/

#include <stdlib.h> // Manejo de memoria
#include <assert.h> // Chequeo de correcto asignamiento de memoria

#define LARGO_ALFABETO 26 // Cantidad de hijos por nodo

/**
 * Tipo de dato que representa cada nodo de un Trie.
 */
typedef struct _ANodo {
  struct _ANodo ** hijo; // hijo[LARGO_ALFABETO]
  int esFinDePalabra; // Indicador de si este nodo es el fin de una palabra.
} ANodo;

/**
 * Devuelve un nuevo nodo tal que esFinDePalabra = 0.
 */
ANodo * arbol_nodo_crear();

/**
 * Destruccion del arbol.
 */
void arbol_destruir(ANodo *);

/**
 * Determina si el nodo posee un hijo en el indice indicado.
 */
int arbol_pertenece_al_nodo(ANodo *, int);

/**
 * Toma un nodo y se desplaza en el indice indicado, retornandolo. Si no 
 * existe, lo crea.
 */
ANodo * arbol_desplazarse(ANodo *, int);

/**
 * Toma dos nodos. Si el primero difiere del segundo, valida esFinDePalabra = 0 
 * del primero. Retorna el segundo.
 */
ANodo * arbol_validar_nodo(ANodo *, ANodo *);

#endif /* __ARBOL_H__ */