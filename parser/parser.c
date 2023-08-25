#include "parser.h"

LineaSalida lineaSalida_crear(size_t largoLinea) {
  LineaSalida linea;
  linea.resultado = malloc(sizeof(char) * largoLinea * 2);
  vaciar_cadena(linea.resultado);
  linea.contadorEspaciosAgregados = 0;
  linea.errores = cola_crear();
  return linea;
}

void lineaSalida_destruir(LineaSalida linea) {
  free(linea.resultado);
  cola_destruir(linea.errores, (FuncionDestructora) caracter_destruir);
}

LineaSalida parser_analizar_linea(Diccionario diccionario, char * lineaEntrada) {
  LineaSalida lineaSalida = lineaSalida_crear(strlen(lineaEntrada));

  int continuar = 1;
  int bandera = -1;
  int seguir = 0;
  int espacioValido = -1;
  char temp[strlen(lineaEntrada)];
  vaciar_cadena(temp);

  Diccionario nodoActual = diccionario;
  for (int i = 0; continuar; i++) {
    char letra = lineaEntrada[i]; // Simple asignacion de la letra
    int letraTraducida = validar_y_traducir_caracter(letra); // Traduzco la letra
    
    if (arbol_pertenece_al_nodo(nodoActual, letraTraducida)){ // Si es A-Z y ademas tiene un subarbol
      nodoActual = arbol_desplazarse(nodoActual, letraTraducida); // Me desplazo en el arbol (rama que ya se que existe)
      strncat(temp, &letra, 1);
      if (nodoActual->esFinDePalabra) { // Encontre una palabra (si o si, puede extenderse)
        if(!seguir && !cadena_es_vacia(lineaSalida.resultado)) {
          strcat(lineaSalida.resultado, " ");
          lineaSalida.contadorEspaciosAgregados++;
        }
        strcat(lineaSalida.resultado, temp); // La copio en el resultado
        seguir = 1; // Encontre una palabra, ahora busco si se extiende
        vaciar_cadena(temp);
        bandera = i;
        espacioValido = 1;
      } else if(bandera == -1) // Si no hay bandera 
          bandera = i; // Estoy empezando a leer, la pongo

    } else { // Caracter no perteneciente a una palabra del diccionario
      if(!seguir) {
        if(letra == ' ' && cadena_es_vacia(temp) && espacioValido == 1) {
          espacioValido = 0;
          lineaSalida.contadorEspaciosAgregados--;
        } else if(!cadena_es_vacia(temp)) {
          lineaSalida.errores = cola_encolar(lineaSalida.errores, temp, (FuncionCopia) caracter_copiar);
        } else if(!es_terminador(letra)) {
          lineaSalida.errores = cola_encolar(lineaSalida.errores, &letra, (FuncionCopia) caracter_copiar);
        } else if(espacioValido == 0) {
          lineaSalida.contadorEspaciosAgregados++;
          lineaSalida.errores = cola_encolar(lineaSalida.errores, " ", (FuncionCopia) caracter_copiar);
        }
              
      }
      if(bandera != -1) { // Hay bandera?
        vaciar_cadena(temp); // Vacio buffer
        nodoActual = diccionario; // Retorno al diccionario para buscar palabras desde 0
        i = bandera; // Retorno a donde estaba antes de entrar en el subarbol 
        bandera = -1; // Borro bandera
        seguir = 0;
      } else if (es_terminador(letra))
          continuar = 0;
    }
    
  } 

  return lineaSalida;
}

int parser(Archivos * archivos) { 
  Diccionario diccionario = diccionario_crear(archivos->diccionario);
  archivos_cerrar_diccionario(archivos);
  if(!diccionario)
    return 1;
  
  //char lineaEntrada[LARGO_MAXIMO];
  //while(fgets(lineaEntrada, LARGO_MAXIMO, archivos->entrada)) {
  char * lineaEntrada;
  while((lineaEntrada = obtener_linea_de_archivo(LARGO_MAXIMO, archivos->entrada))) {
    LineaSalida lineaSalida = parser_analizar_linea(diccionario, lineaEntrada);

    lineaSalida = imprimir_en_archivo(lineaSalida, archivos->salida);
    
    lineaSalida_destruir(lineaSalida);
    free(lineaEntrada);
  }


  diccionario_destruir(diccionario);
  return 0;
}

LineaSalida imprimir_en_archivo(LineaSalida lineaSalida, FILE * archivo) {
  fprintf(archivo, "%s", lineaSalida.resultado);
  if(lineaSalida.contadorEspaciosAgregados != 0 || !cola_vacia(lineaSalida.errores)) {
    fprintf(archivo, " (Hubo errores)");
    if(lineaSalida.contadorEspaciosAgregados != 0)
      fprintf(archivo, " (Se agregaron %d espacios)", lineaSalida.contadorEspaciosAgregados);
    if(!cola_vacia(lineaSalida.errores)) {
      fprintf(archivo, " (Caracteres borrados:");
      while(!cola_vacia(lineaSalida.errores)) {
        char * caracterBorrado = (char *) cola_inicio(lineaSalida.errores);
        fputc(' ', archivo);
        fputc('(', archivo);
        fputc(*caracterBorrado, archivo);
        fputc(')', archivo);
        lineaSalida.errores = cola_desencolar(lineaSalida.errores, (FuncionDestructora) caracter_destruir);
      }
      fputc(')', archivo);
    }
  }
  fprintf(archivo, "\n");
  return lineaSalida;
}