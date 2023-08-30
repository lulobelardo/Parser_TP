#include "funciones_test.h"

void test_es_terminador() {
  char letra = '\n';
  assert(es_terminador(letra));

  letra == EOF;
  assert(es_terminador(letra));

  letra == '\0';
  assert(es_terminador(letra));

  letra == 13;
  assert(es_terminador(letra));

  for (int i = 65; i < 91; i++) {
    assert(es_terminador(i));
    assert(es_terminador(i+32));
  }
}

void test_validar_y_traducir_caracter() {
  int i = 0;
  for (; i < 65; i++) {
    assert(validar_y_traducir_caracter(i) == -1);
  }
  for (; i < 91; i++) {
    assert(validar_y_traducir_caracter(i) == i - 65);
  }
  for (; i < 97; i++) {
    assert(validar_y_traducir_caracter(i) == -1);
  }
  for (; i < 123; i++) {
    assert(validar_y_traducir_caracter(i) == i - 97);
  }
  for (; i < 127; i++) {
    assert(validar_y_traducir_caracter(i) == -1);
  }
}

void test_cadena() {
  char str[10] = "Hola";
  assert(cadena_es_vacia(str) == 0);
  vaciar_cadena(str);
  assert(cadena_es_vacia(str));
}

void test_obtener_linea_de_archivo() {
  FILE * fp = fopen("/archivos_test/1.txt", "r");
  assert(fp);

  char str1[256], str2[256], str3[256], str4[256];
  fgets(str1, 256, fp);
  fgets(str2, 256, fp);
  fgets(str3, 256, fp);
  assert(fgets(str4, 256, fp) == NULL);

  fclose(fp);
  fp = fopen("/archivos_test/1.txt", "r");
  assert(fp);

  char * strr1, * strr2, * strr3, * strr4;

  strr1 = obtener_linea_de_archivo(256, fp);
  strr1 = obtener_linea_de_archivo(256, fp);
  strr1 = obtener_linea_de_archivo(256, fp);
  assert((strr4 = obtener_linea_de_archivo(256, fp)) == NULL);
  fclose(fp);

  assert(strcmp(str1, strr1) == 0);
  assert(strcmp(str2, strr2) == 0);
  assert(strcmp(str3, strr3) == 0);
  assert(strcmp(str4, strr4) == 0);

  free(strr1);
  free(strr2);
  free(strr3);
  free(strr4);
}

void test_funciones() {
  test_es_terminador();
  test_validar_y_traducir_caracter();
  test_cadena();
  test_obtener_linea_de_archivo();
}