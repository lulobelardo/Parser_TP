#include "lista_test.h"

/*
 * Test de lista_crear.
 */
void test_lista_crear() {
  Lista l = lista_crear();
  assert(l.primero == NULL);
  assert(l.ultimo == NULL);
}

/*
 * Test de lista_vacia.
 */
void test_lista_vacia() {
  Lista l = lista_crear();
  assert(lista_vacia(l));

  LNodo nodo;
  int a = 5;
  nodo.dato = (void *) &a;
  nodo.sig = NULL;
  l.primero = l.ultimo = &nodo;

  assert(lista_vacia(l) == 0);
}

/*
 * Test de lista_agregar_final.
 */
void test_lista_agregar_final() {
  Lista l = lista_crear();

  char a = 'A';
  l = lista_agregar_final(l, &a, (FuncionCopia) caracter_copiar);
  assert(*(char *)l.primero->dato == a);
  assert(*(char *)l.ultimo->dato == a);

  assert(l.primero->sig == NULL);
  
  a = 'B';
  l = lista_agregar_final(l, &a, (FuncionCopia) caracter_copiar);
  assert(*(char *)l.primero->dato == 'A');
  assert(*(char *)l.ultimo->dato == a);

  assert(l.primero->sig == l.ultimo);
  assert(l.ultimo->sig == NULL);

  a = 'C';
  l = lista_agregar_final(l, &a, (FuncionCopia) caracter_copiar);
  assert(*(char *)l.primero->dato == 'A');
  assert(*(char *)l.ultimo->dato == a);

  assert(l.primero->sig->sig == l.ultimo);
  assert(l.ultimo->sig == NULL);
}

/*
 * Test de las funciones test_.
 */
void test_lista() {
  test_lista_crear();
  test_lista_vacia();
  test_lista_agregar_final();
}