#include "diccionario.h"

/*
 * Devuelve un diccionario con las palabras contenidas en el archivo.
 */
Diccionario diccionario_crear(FILE * archivoDiccionario) {
  Diccionario diccionario = arbol_nodo_crear();
  
  char letra;
  int letraTraducida, indicadorError = 0;
  Diccionario nodoActual = diccionario;
  do {
    letra = getc(archivoDiccionario);
    
    if(es_terminador(letra))
      nodoActual = arbol_validar_nodo(nodoActual, diccionario);
    else if((letraTraducida = validar_y_traducir_caracter(letra)) != -1)
      nodoActual = arbol_desplazarse(nodoActual, letraTraducida);
    else {
      // Error, caracter invalido en el diccionario
      indicadorError = 1;
      
      letra = EOF;
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