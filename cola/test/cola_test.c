#include "cola_test.h"

void test_cola() {
  Cola cola = cola_crear();
  assert(cola_vacia(cola));
  assert(cola_inicio(cola) == NULL);

  char i = 'h';
  cola_encolar(cola, &i, (FuncionCopia) caracter_copiar);

  assert(cola_vacia(cola) != 0);

  assert((*(char *)cola_inicio(cola)) == i);

  cola = cola_desencolar(cola, (FuncionDestructora) caracter_destruir);

  assert(cola_vacia(cola));

  cola_destruir(cola, caracter_destruir);
}