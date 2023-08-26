#include "diccionario.h"

/*
 * Devuelve un diccionario con las palabras contenidas en el archivo.
 * Lee letra por letra y 'almacena' las palabras en el diccionario.
 */
Diccionario diccionario_crear(FILE * archivoDiccionario) {
  Diccionario diccionario = arbol_nodo_crear();
  
  char letra;
  int letraTraducida, indicadorError = 0;
  Diccionario nodoActual = diccionario;
  do {
    letra = getc(archivoDiccionario);
    
    if (es_terminador(letra))
      nodoActual = arbol_validar_nodo(nodoActual, diccionario);
    else if ((letraTraducida = validar_y_traducir_caracter(letra)) != -1)
      nodoActual = arbol_desplazarse(nodoActual, letraTraducida);
    else {
      // Error, caracter invalido en el diccionario
      indicadorError = 1; // Sin esto, funciona igual hasta donde llegó
      letra = EOF; // Sin esto, lee todo el archivo igualmente
    }
  } while(letra != EOF);

  if (indicadorError) {
    arbol_destruir(diccionario);
    diccionario = NULL;
  }

  return diccionario;
}

/*
 * Destruye el diccionario.
 */
void diccionario_destruir(Diccionario diccionario) {
  arbol_destruir(diccionario);
}