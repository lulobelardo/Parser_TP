#include <stdio.h>
#include <stdlib.h>
#include "./archivos/archivos.h"
#include "./parser/parser.h"

/*
0: A, 1: B, 2: C, 3: D, 4: E, 5: F, 6: G, 7: H, 8: I, 9: J, 10:K, 11:L, 12:M, 
13:N, 14:O, 15:P, 16:Q, 17:R, 18:S, 19:T, 20:U, 21:V, 22:W, 23:X, 24:Y, 25:Z
*/

/*
  argv[0] := path
  argv[1] := Archivo Diccionario
  argv[2] := Archivo Entrada
  argv[3] := Archivo Salida
*/
int main(int argc, char const *argv[]) {
  if (argc != 4) {
    printf("Error: Archivos insuficientes. (Hay %d)\n", argc);
    return 1;
  }
  
  Archivos * archivos = archivos_abrir(argv);

  int errorCode = parser(archivos);

  if(errorCode == 1)
    printf("Error: El archivo diciconario contiene un formato invalido.\n");

  archivos_cerrar(archivos);
  free(archivos);
  archivos = NULL;

  return 0;
}
