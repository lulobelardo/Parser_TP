#include "archivos.h"

/**
 * Abre los archivos [1]"r",[2]"r",[3]"w" y los devuelve.
 */
Archivos * archivos_abrir(char const * argv[]) {
  Archivos * archivos = malloc(sizeof(Archivos));
  assert(archivos);

  archivos->diccionario = fopen(argv[1], "r");
  assert(archivos->diccionario);

  archivos->entrada = fopen(argv[2], "r");
  assert(archivos->entrada);

  archivos->salida = fopen(argv[3], "w");
  assert(archivos->salida);

  return archivos;
}

/**
 * Cierra los archivos.
 */
void archivos_cerrar(Archivos * archivos) {
  if (archivos->diccionario) {
    fclose(archivos->diccionario);
    archivos->diccionario = NULL;
  }
  if (archivos->entrada) {
    fclose(archivos->entrada);
    archivos->entrada = NULL;
  }
  if (archivos->salida) {
    fclose(archivos->salida);
    archivos->salida = NULL;
  }
}

/**
 * Cierra archivo->diccionario.
 */
void archivos_cerrar_diccionario(Archivos * archivos) {
  if (archivos->diccionario) {
    fclose(archivos->diccionario);
    archivos->diccionario = NULL;
  }
}