#include "caracter.h"

/**
 * Libera la memoria del caracter. (FuncionDestructora).
 */
void caracter_destruir(char * caracter) {
  free(caracter);
}

/**
 * Copia el valor del puntero pasado en un nuevo puntero y lo retorna.
 * (FuncionCopia).
 */
char * caracter_copiar(char const * caracter) {
  char * resultado = malloc(sizeof(char));
  assert(resultado);
  (*resultado) = (*caracter);
  return resultado;
}

/*
 * Imprime el caracter en pantalla. (FuncionVisitante).
 */
void caracter_imprimir(char * caracter){
  printf("%c ", * caracter);
}