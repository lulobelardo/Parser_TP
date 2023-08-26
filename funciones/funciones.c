#include "funciones.h"

/*
 * Devuelve si el caracter es un terminador en el contexto previamente 
 * establecido.
 */
int es_terminador(char letra) {
  return (letra == '\n' || letra == EOF || letra == '\0' || letra == 13);
}

/*
 * Devuelve la traducción / biyección del caracter pasado. Si es inválido 
 * retorna -1.
  0: A, 1: B, 2: C, 3: D, 4: E, 5: F, 6: G, 7: H, 8: I, 9: J, 10:K, 11:L, 12:M, 
  13:N, 14:O, 15:P, 16:Q, 17:R, 18:S, 19:T, 20:U, 21:V, 22:W, 23:X, 24:Y, 25:Z
 */
int validar_y_traducir_caracter(char letra) {
  if (!isalpha(letra))
    return -1;

  return toupper(letra) - 'A'; //((int) letra) - 65;
}

/*
 * Toma una cadena NO NULA Y Borra el contenido de la cadena (a nivel usuario), 
 * haciendola vacía.
 */
void vaciar_cadena(char * cadena) {
  assert(cadena);
  cadena[0] = '\0';
}

/*
 * Toma una cadena NO NULA y devuelve si esta vacía.
 */
int cadena_es_vacia(char * cadena) {
  assert(cadena);
  return (cadena[0] == '\0');
}

/*
 * Toma un LARGO_MAXIMO y un archivo.
 * Devuelve una cadena con los valores de la linea a donde apunta el archivo.
 * El objetivo de esta funcion es reemplazar fgets, evitando tener un límite
 * fijo de memoria y evitando crear variables con cantidad abultada de memoria, 
 * sabiendo que es un archivo de texto escrito por alguien y no va a tener 
 * demasiadas lineas.
 */
char * obtener_linea_de_archivo(size_t largoMaximo, FILE * archivo) {
  char * linea = malloc(sizeof(char));
  assert(linea);
  vaciar_cadena(linea);
  size_t largoActual = 0; // Largo de la linea

  size_t largoTentativo = LARGO_TENTATIVO;
  if (LARGO_TENTATIVO > largoMaximo)
    largoTentativo = largoMaximo;

  char temp[largoTentativo];
  size_t largoTemp = 0; // Largo la sublinea leída
  do {
    if (fgets(temp, largoTentativo, archivo)) {
      largoTemp = strlen(temp);
      linea = realloc(linea, largoActual + largoTemp + 1);
      assert(linea);

      strcat(linea, temp);
      largoActual += largoTemp;
    }
  } while (largoTemp == largoTentativo - 1 && largoActual < largoMaximo -
                                                            largoTentativo);
  
  if (cadena_es_vacia(linea)) {
    free(linea);
    return NULL;
  }
  return linea;
}