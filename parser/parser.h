#ifndef __PARSER_H__
#define __PARSER_H__

#include <string.h>
#include "../cola/cola.h"
#include "../diccionario/diccionario.h"
#include "../caracter/caracter.h"
#include "../archivos/archivos.h"
#include "../funciones/funciones.h"

#define LARGO_MAXIMO 131072

typedef struct _LineaSalida {
  char * resultado;
  int contadorEspaciosAgregados;
  Cola errores;
} LineaSalida;

LineaSalida lineaSalida_crear();

void lineaSalida_destruir(LineaSalida linea);

LineaSalida parser_analizar_linea(Diccionario diccionario, char * lineaEntrada);

int parser(Archivos *);

LineaSalida imprimir_en_archivo(LineaSalida lineaSalida, FILE * archivo);

#endif /* __PARSER_H__ */