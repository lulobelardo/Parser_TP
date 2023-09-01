CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -g

OBJS = parser.o diccionario.o archivos.o arbol.o lista.o cola.o caracter.o funciones.o

ejecutable: main.o $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

parser.o: parser/parser.c parser/parser.h
	$(CC) -c $< $(CFLAGS)

archivos.o: archivos/archivos.c archivos/archivos.h
	$(CC) -c $< $(CFLAGS)

arbol.o: diccionario/arbol/arbol.c diccionario/arbol/arbol.h
	$(CC) -c $< $(CFLAGS)

diccionario.o: diccionario/diccionario.c diccionario/diccionario.h
	$(CC) -c $< $(CFLAGS)

lista.o: cola/lista/lista.c cola/lista/lista.h
	$(CC) -c $< $(CFLAGS)

cola.o: cola/cola.c cola/cola.h
	$(CC) -c $< $(CFLAGS)	

caracter.o: caracter/caracter.c caracter/caracter.h
	$(CC) -c $< $(CFLAGS)

funciones.o: funciones/funciones.c funciones/funciones.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o

OBJS_TEST = parser_test.o diccionario_test.o arbol_test.o lista_test.o cola_test.o funciones_test.o

test: test.o $(OBJS) $(OBJS_TEST)
	$(CC) -o $@ $^ $(CFLAGS)

test.o: test.c
	$(CC) -c $< $(CFLAGS)

parser_test.o: parser/test/parser_test.c parser/test/parser_test.h
	$(CC) -c $< $(CFLAGS)

arbol_test.o: diccionario/arbol/test/arbol_test.c diccionario/arbol/test/arbol_test.h
	$(CC) -c $< $(CFLAGS)

diccionario_test.o: diccionario/test/diccionario_test.c diccionario/test/diccionario_test.h
	$(CC) -c $< $(CFLAGS)

lista_test.o: cola/lista/test/lista_test.c cola/lista/test/lista_test.h
	$(CC) -c $< $(CFLAGS)

cola_test.o: cola/test/cola_test.c cola/test/cola_test.h
	$(CC) -c $< $(CFLAGS)	

funciones_test.o: funciones/test/funciones_test.c funciones/test/funciones_test.h
	$(CC) -c $< $(CFLAGS)

.PHONY: clean