#include "archivos.h"

/**
 * Abre los archivos [1]"r",[2]"r",[3]"w" y los devuelve.
 * Si falla devuelve NULL;
 */
Archivos * archivos_abrir(char const * argv[]) {
  Archivos * archivos = malloc(sizeof(Archivos));
  assert(archivos);

  archivos->diccionario = fopen(argv[1], "r");
  if (!archivos->diccionario) {
    printf("Error: Archivo Diccionario inaccesible.\n");
    free(archivos);
    return NULL;
  }

  archivos->entrada = fopen(argv[2], "r");
  if (!archivos->entrada) {
    printf("Error: Archivo Entrada inaccesible.\n");
    fclose(archivos->diccionario);
    free(archivos);
    return NULL;
  }

  archivos->salida = fopen(argv[3], "w");
  if (!archivos->salida) {
    printf("Error: Archivo Salida no pudo crearse/abrirse.\n");
    fclose(archivos->diccionario);
    fclose(archivos->entrada);
    free(archivos);
    return NULL;
  }

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