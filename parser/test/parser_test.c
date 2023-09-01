#include "parser_test.h"

/*
 * Test de lineaDeSalida_crear.
 */
void test_lineaDeSalida_crear() {
  LineaDeSalida linea = lineaDeSalida_crear(10);
  assert(linea.contadorEspaciosAgregados == 0);
  assert(cola_vacia(linea.errores));
  assert(cadena_es_vacia(linea.resultado));
  lineaDeSalida_destruir(linea);
}

/*
 * Test de parser_analizar_linea.
 */
void test_parser_analizar_linea() {
  FILE * fp = fopen("archivos_test/diccionarios/0.txt", "r");
  assert(fp);
  Diccionario diccionario = diccionario_crear(fp);
  assert(diccionario);
  fclose(fp);

  char linea[50] = "Quiendepositedolaresrecibiradolares";
  char lineaS[100] = "Quien deposite dolares recibira dolares";
  LineaDeSalida lineaDeSalida = parser_analizar_linea(diccionario, linea);
  assert(strcmp(lineaDeSalida.resultado, lineaS) == 0);
  assert(lineaDeSalida.contadorEspaciosAgregados == 4);
  assert(cola_vacia(lineaDeSalida.errores));
  lineaDeSalida_destruir(lineaDeSalida);

  sprintf(linea, "dolardolaresesdorecibequien ");
  sprintf(lineaS, "dolar dolares es quien");
  lineaDeSalida = parser_analizar_linea(diccionario, linea);
  assert(strcmp(lineaDeSalida.resultado, lineaS) == 0);
  assert(lineaDeSalida.contadorEspaciosAgregados == 4);
  assert(*(char*)lineaDeSalida.errores.primero->dato);
  assert(*(char*)lineaDeSalida.errores.primero->sig->dato == 'd');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->dato == 'o');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->dato == 'r');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->dato == 'e');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->dato == 'c');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->sig->dato == 'i');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->sig->sig->dato == 'b');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->sig->sig->sig->dato == 'e');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->sig->sig->sig->sig->dato == ' ');
  lineaDeSalida_destruir(lineaDeSalida);
}

/*
 * LLama a las funciones test_ y es test de parser.
 */
void test_parser() {
  test_lineaDeSalida_crear();
  test_parser_analizar_linea();
}