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
  FILE * fp = fopen("parser/test/archivos_test/diccionarios/0.txt", "r");
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
  assert(strcmp(lineaDeSalida.resultado, lineaS) == 0); // solucionar
  assert(lineaDeSalida.contadorEspaciosAgregados == 3);
  assert(*(char*)lineaDeSalida.errores.primero->dato == 'd');
  assert(*(char*)lineaDeSalida.errores.primero->sig->dato == 'o');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->dato == 'r');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->dato == 'e');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->dato == 'c');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->dato == 'i');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->sig->dato == 'b');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->sig->sig->dato == 'e');
  assert(*(char*)lineaDeSalida.errores.primero->sig->sig->sig->sig->sig->sig->sig->sig->dato == ' ');
  lineaDeSalida_destruir(lineaDeSalida);
  diccionario_destruir(diccionario);
}

/*
 * Retorna si dos archivos coinciden.
 */
int archivos_coinciden(FILE *fp1, FILE *fp2)
{
  int continuar = 1;
  int indice = 1;
  while (continuar && !feof(fp1) && !feof(fp2)) {
    char c1, c2;
    c1 = fgetc(fp1);
    c2 = fgetc(fp2);

    continuar = (c1 == c2);
    if (!continuar) {
      printf("Los archivos difieren en el %d-esimo caracter(%c y %c)\n",
                                                         indice, c1, c2);
    }
    indice++;
  }
  return continuar;
}

/*
 * LLama a las funciones test_ y es test de parser.
 */
void test_parser() {
  test_lineaDeSalida_crear();
  test_parser_analizar_linea();
  char * argv[4];
  int testInvalidos = 0;
  for (int i = 0; i < CANTIDAD_TEST; i++) {
    argv[1] = malloc(sizeof(char) * 128); assert(argv[1]);
    argv[2] = malloc(sizeof(char) * 128); assert(argv[2]);
    argv[3] = malloc(sizeof(char) * 128); assert(argv[3]);
    argv[0] = malloc(sizeof(char) * 128); assert(argv[0]);
    sprintf(argv[1], "./parser/test/archivos_test/diccionarios/%d.txt", i);
    sprintf(argv[2], "./parser/test/archivos_test/entradas/%d.txt", i);
    sprintf(argv[3], "./parser/test/archivos_test/salidas/%d.txt", i);
    sprintf(argv[0], "./parser/test/archivos_test/salidasEsperadas/%d.txt", i);

    Archivos * archivos = archivos_abrir(argv);
    parser(archivos);
    archivos_cerrar(archivos);
    free(archivos);

    FILE * salida = fopen(argv[3], "r");
    assert(salida);
    FILE * salidaEsperada = fopen(argv[0], "r");
    assert(salidaEsperada);
    if(!archivos_coinciden(salida, salidaEsperada)) {
      printf("^Errores en test %d^\n", i);
      testInvalidos++;
    }
    fclose(salida);
    fclose(salidaEsperada);
    free(argv[0]);
    free(argv[1]);
    free(argv[2]);
    free(argv[3]);
  }
  assert(!testInvalidos);
}