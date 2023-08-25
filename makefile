FLAGS = -Wall -Wextra -Werror -std=c99 -g

ejecutable: main.o parser.o diccionario.o archivos.o arbol.o lista.o cola.o caracter.o funciones.o
	$(CC) -o $@ $^ $(FLAGS)

main.o: main.c parser.o archivos.o
	$(CC) -c $< $(FLAGS)

parser.o: parser/parser.c parser/parser.h diccionario.o cola.o caracter.o archivos.o funciones.o
	$(CC) -c $< $(FLAGS)

archivos.o: archivos/archivos.c archivos/archivos.h
	$(CC) -c $< $(FLAGS)

arbol.o: diccionario/arbol/arbol.c diccionario/arbol/arbol.h
	$(CC) -c $< $(FLAGS)

diccionario.o: diccionario/diccionario.c diccionario/diccionario.h arbol.o funciones.o
	$(CC) -c $< $(FLAGS)

lista.o: cola/lista/lista.c cola/lista/lista.h
	$(CC) -c $< $(FLAGS)

cola.o: cola/cola.c cola/cola.h lista.o
	$(CC) -c $< $(FLAGS)	

caracter.o: caracter/caracter.c caracter/caracter.h
	$(CC) -c $< $(FLAGS)

funciones.o: funciones/funciones.c funciones/funciones.h
	$(CC) -c $< $(FLAGS)

clean:
	rm -f *.o

.PHONY = clean