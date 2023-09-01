#include "cola_test.h"

/*
 * Test de cola_crear.
 */
void test_cola_crear() {
  Cola c = cola_crear();
  assert(c.primero == NULL);
  assert(c.ultimo == NULL);
}

/*
 * Test de cola_vacia.
 */
void test_cola_vacia() {
  Cola c = cola_crear();
  assert(cola_vacia(c));

  LNodo nodo;
  nodo.dato = NULL;
  nodo.sig = NULL;
  c.primero = c.ultimo = &nodo;

  assert(cola_vacia(c) == 0);
}

/*
 * Test de cola_encolar.
 */
void test_cola_encolar() {
  Cola c = cola_crear();

  char a = 'a';
  c = cola_encolar(c, &a, (FuncionCopia) caracter_copiar);
  assert(*(char *)c.primero->dato == a);
  assert(*(char *)c.ultimo->dato == a);

  char b = 'b';
  c = cola_encolar(c, &b, (FuncionCopia) caracter_copiar);
  assert(*(char *)c.primero->dato == a);
  assert(*(char *)c.ultimo->dato == b);

  char d = 'd';
  c = cola_encolar(c, &d, (FuncionCopia) caracter_copiar);
  assert(*(char *)c.primero->dato == a);
  assert(*(char *)c.ultimo->dato == d);

  cola_destruir(c, (FuncionDestructora) caracter_destruir);
}

/*
 * Test de cola_inicio.
 */
void test_cola_inicio() {
  Cola c = cola_crear();
  assert(cola_inicio(c) == NULL);

  c = cola_encolar(c, "a", (FuncionCopia) caracter_copiar);

  assert(* (char *) cola_inicio(c) == 'a');

  c = cola_encolar(c, "b", (FuncionCopia) caracter_copiar);

  assert(* (char *) cola_inicio(c) == 'a');
  assert(* (char *) cola_inicio(c) == * (char *) c.primero->dato);

  cola_destruir(c, (FuncionDestructora) caracter_destruir);
}

/*
 * Test de cola_desencolar.
 */
void test_cola_desencolar() {
  Cola cola = cola_crear();
  assert(cola_vacia(cola));
  assert(cola_inicio(cola) == NULL);

  for (int i = 65; i < 91; i++) {
    cola = cola_encolar(cola, &i, (FuncionCopia) caracter_copiar);
    assert(cola_vacia(cola) == 0);
    assert((*(char *)cola_inicio(cola)) == 65);   
  }
  for (int i = 66; i < 91; i++) {
    cola_desencolar(cola, (FuncionDestructora) caracter_destruir);
    assert((*(char *)cola_inicio(cola)) == i);
  }

  assert(cola_vacia(cola));

  cola_destruir(cola, (FuncionDestructora) caracter_destruir);
}

/*
 * Llama a las funciones test_.
 */
void test_cola() {
  test_cola_crear();
  test_cola_vacia();
  test_cola_encolar();
  test_cola_inicio();
  test_cola_desencolar();
}