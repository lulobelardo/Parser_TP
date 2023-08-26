#include "parser.h"

/*
 * Devuelve una LineaDeSalida nueva/vacía.
 */
LineaDeSalida lineaDeSalida_crear(size_t largoLinea) {
  LineaDeSalida linea;
  linea.resultado = malloc(sizeof(char) * largoLinea * 2); // Caso máximo
  vaciar_cadena(linea.resultado);
  linea.contadorEspaciosAgregados = 0;
  linea.errores = cola_crear();
  return linea;
}

/*
 * Destruye La lineaDeSalida.
 */
void lineaDeSalida_destruir(LineaDeSalida linea) {
  free(linea.resultado);
  cola_destruir(linea.errores, (FuncionDestructora) caracter_destruir);
}

/*
 * Toma el diccionario y la linea a analizar y retorna la lineaDeSalida, la 
 * cual contiene la linea corregida y los errores que tiene.
 */
LineaDeSalida parser_analizar_linea(Diccionario diccionario, 
                                    char * lineaEntrada) {
  LineaDeSalida lineaSalida = lineaDeSalida_crear(strlen(lineaEntrada));

  // Indicador de si la el caracter es EOL
  int continuar = 1;

  // 'Checkpoint' que indica a donde regresar en caso de error 
  int bandera = -1; 

  // Indicador de si se continua leyendo en la subrama de una subpalabra válida
  int seguir = 0;

  // Indicador de si es válido poner un espacio según el contexto 
  int espacioValido = -1;

  // Variable donde se almacenan las letras mientras sean válidas
  char temp[strlen(lineaEntrada)];
  vaciar_cadena(temp);

  Diccionario nodoActual = diccionario;

  for (int i = 0; continuar; i++) {
    char letra = lineaEntrada[i]; // Simple asignacion de la letra
    
    // Obtiene el índice respectivo de la letra según el alfabeto existente
    int letraTraducida = validar_y_traducir_caracter(letra);

    // Si pertenece al ALFABETO y ademas tiene un subarbol
    if (arbol_pertenece_al_nodo(nodoActual, letraTraducida)) { 
      // Me desplazo en el arbol (Existe)
      nodoActual = arbol_desplazarse(nodoActual, letraTraducida);
      strncat(temp, &letra, 1); // Agrega la letra a temp

      // Si encontre una palabra (o subpalabra)
      if (nodoActual->esFinDePalabra) {
        // Si ya hay palabras, pongo un ' '
        if (!seguir && !cadena_es_vacia(lineaSalida.resultado)) {
          strcat(lineaSalida.resultado, " ");
          lineaSalida.contadorEspaciosAgregados++;
        }
        strcat(lineaSalida.resultado, temp); // Concateno la pal. al resultado
        seguir = 1; // Encontre una palabra, ahora busco si se extiende
        vaciar_cadena(temp);
        bandera = i; // A donde volver si no se extiene la palabra
        espacioValido = 1; // Es válido escribir un ' ' ahora
      } 
      // Si no hay bandera
      else if (bandera == -1)
        bandera = i; // Estoy empezando a leer, la pongo

    } else { // Si el caracter no pertenece a una palabra del diccionario
      
      // Analizador de errores, sólo si no estoy intentando extender la pal.
      if (!seguir) {
        // Si hay un espacio y es válido
        if (letra == ' ' && cadena_es_vacia(temp) && espacioValido == 1) {
          espacioValido = 0;
          lineaSalida.contadorEspaciosAgregados--;
        }
        // Si falló a mitad de palabra
        else if (!cadena_es_vacia(temp)) {
          lineaSalida.errores = cola_encolar(lineaSalida.errores, temp, 
                                             (FuncionCopia) caracter_copiar);
        } 
        // Si falló al comienzo de una palabra
        else if (!es_terminador(letra)) {
          lineaSalida.errores = cola_encolar(lineaSalida.errores, &letra, 
                                             (FuncionCopia) caracter_copiar);
        } 
        // Si es EOL e incorrectamente el usuario ingreso un espacio extra
        else if (espacioValido == 0) {
          lineaSalida.contadorEspaciosAgregados++;
          lineaSalida.errores = cola_encolar(lineaSalida.errores, " ", 
                                             (FuncionCopia) caracter_copiar);
        }       
      }

      // Funcionamiento del parser
      if (bandera != -1) { // Hay bandera?
        vaciar_cadena(temp); // Vacio buffer
        nodoActual = diccionario; // Reinicio al diccionario desde 0
        i = bandera; // Retorno a donde estaba antes de entrar en el subarbol 
        bandera = -1; // Borro bandera
        seguir = 0; // Si estaba intentando extener una palabra, ya no
      } else if (es_terminador(letra)) // EOL
        continuar = 0;
    }
  } 

  return lineaSalida;
}

/*
 * Toma los archivos abiertos y ejecuta el parser.
 * Crea el diccionario y luego ejecuta el analizador linea por linea.
 */
int parser(Archivos * archivos) { 
  Diccionario diccionario = diccionario_crear(archivos->diccionario);
  archivos_cerrar_diccionario(archivos);
  if (!diccionario) 
    return 1; // No admite errores en el diccionario

  char * lineaEntrada;
  while ((lineaEntrada = obtener_linea_de_archivo(LARGO_MAXIMO, 
                                                  archivos->entrada))) {
    LineaDeSalida lineaSalida = parser_analizar_linea(diccionario, 
                                                      lineaEntrada);

    lineaSalida = imprimir_en_archivo(lineaSalida, archivos->salida);
    
    lineaDeSalida_destruir(lineaSalida);
    free(lineaEntrada);
  }

  diccionario_destruir(diccionario);
  return 0;
}

/*
 * Toma una LineaDeSalida y un archivo de escritura y escribe la linea 
 * correctamente y sus errores. A medida que escribe los errores, los borra.
 */
LineaDeSalida imprimir_en_archivo(LineaDeSalida lineaSalida, FILE * archivo) {
  // Linea CORREGIDA
  fprintf(archivo, "%s", lineaSalida.resultado);

  // Errores
  if (lineaSalida.contadorEspaciosAgregados != 0 || 
      !cola_vacia(lineaSalida.errores)) {
    fprintf(archivo, " (Hubo errores)");

    // Espacios Agregados
    if (lineaSalida.contadorEspaciosAgregados != 0)
      fprintf(archivo, " (Se agregaron %d espacios)", 
                                        lineaSalida.contadorEspaciosAgregados);
    
    // Caracteres borrados
    if (!cola_vacia(lineaSalida.errores)) {
      fprintf(archivo, " (Caracteres borrados:");
      while (!cola_vacia(lineaSalida.errores)) {
        char * caracterBorrado = (char *) cola_inicio(lineaSalida.errores);
        fputc(' ', archivo);
        fputc('(', archivo);
        fputc(*caracterBorrado, archivo);
        fputc(')', archivo);
        lineaSalida.errores = cola_desencolar(lineaSalida.errores, 
                                      (FuncionDestructora) caracter_destruir);
      }
      fputc(')', archivo);
    }
  }
  fprintf(archivo, "\n");
  return lineaSalida;
}