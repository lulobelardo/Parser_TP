#include <stdio.h>
#include "parser/test/parser_test.h"

#include "cola/test/cola_test.h"
#include "cola/lista/test/lista_test.h"

#include "diccionario/arbol/test/arbol_test.h"
#include "diccionario/test/diccionario_test.h"

#include "funciones/test/funciones_test.h"

int main() {
  puts("Testeando funciones.h...");
  test_funciones();
  
  puts("Testeando lista.h...");
  test_lista();

  puts("Testeando cola.h...");
  test_cola();

  puts("Testeando arbol.h...");
  test_arbol();

  puts("Testeando diccionario.h...");
  test_diccionario();
  
  puts("Testeando parser.h...");
  test_parser();

  puts("\nTODOS LOS TESTS FUERON PASADOS\n");
  return 0;
}