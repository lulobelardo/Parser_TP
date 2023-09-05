#include "diccionario_test.h"

/*
 * Test de diccionario_crear
 */
void test_diccionario_crear() {
  FILE * fp = NULL;

  fp = fopen("diccionario/test/archivos_test/1.txt", "r");
  assert(fp);

  assert(!diccionario_crear(fp));
  fclose(fp);

  fp = fopen("diccionario/test/archivos_test/2.txt", "r");
  assert(fp);

  Diccionario diccionario = diccionario_crear(fp);
  assert(diccionario);
  fclose(fp);
/*
  0: A, 1: B, 2: C, 3: D, 4: E, 5: F, 6: G, 7: H, 8: I, 9: J, 10:K, 11:L, 12:M, 
  13:N, 14:O, 15:P, 16:Q, 17:R, 18:S, 19:T, 20:U, 21:V, 22:W, 23:X, 24:Y, 25:Z
*/

  int a = 0;
  int b = 1;
  int c = 2;
  int d = 3;
  int e = 4;
  //int f = 5
  //int g = 6
  //int h = 7
  int i = 8;
  //int j = 9
  //int k = 10
  int l = 11;
  //int m = 12
  int n = 13;
  int o = 14;
  int p = 15;
  int q = 16;
  int r = 17;
  int s = 18;
  int t = 19;
  int u = 20;
  //int v = 21
  //int w = 22
  //int x = 23
  //int y = 24
  //int z = 25


  assert(diccionario->esFinDePalabra == 0);
  for (int i = 0; i < LARGO_ALFABETO; i++)
    if (i != 3 && i != 4 && i != 16 && i != 17)
      assert(diccionario->hijo[i] == NULL);

  // deposito
  assert(diccionario->hijo[d]->hijo[e]->hijo[p]->hijo[o]->hijo[s]->hijo[i]->hijo[t]->hijo[o]->esFinDePalabra);

  // dolar
  assert(diccionario->hijo[d]->hijo[o]->hijo[l]->hijo[a]->hijo[r]->esFinDePalabra);

  // dolares
  assert(diccionario->hijo[d]->hijo[o]->hijo[l]->hijo[a]->hijo[r]->hijo[e]->hijo[s]->esFinDePalabra);

  // es
  assert(diccionario->hijo[e]->hijo[s]->esFinDePalabra);

  // quien
  assert(diccionario->hijo[q]->hijo[u]->hijo[i]->hijo[e]->hijo[n]->esFinDePalabra);

  // recibira
  assert(diccionario->hijo[r]->hijo[e]->hijo[c]->hijo[i]->hijo[b]->hijo[i]->hijo[r]->hijo[a]->esFinDePalabra);

  // que (Existe qu_... [quien])
  assert(diccionario->hijo[q]->hijo[u]->hijo[e] == NULL);

  // esa (No Existe es_... [es])
  assert(diccionario->hijo[e]->hijo[s]->hijo == NULL);

  // do
  assert(diccionario->hijo[d]->hijo[o]->esFinDePalabra == 0);

  // auto (No Existe a_...)
  assert(diccionario->hijo[a] == NULL);

  diccionario_destruir(diccionario);
}

/*
 * LLama a las funciones test_
 */
void test_diccionario() {
  test_diccionario_crear();
}