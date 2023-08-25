#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
CONVENCIONES:

SE OMITIRAN TODOS LOS CARACTERES INDEBIDOS NO PERTENCIENTES AL ABECEDARIO.

HOJA -> HOJA
HO.JA -> HOJA
hoJ;[;][;'65468]A -> HOJA


BANDERA: guarda a donde regresar en caso de fallar. luego de cada primer letra coincidente y luego de cada pertenece.
temp: contiene todo lo almacenado desde la ultima bandera (si seguir es 0, todo; si es 1, desde luego de la bandera)
ESPACIO. Se agrega despues de cada vez que seguir pasa de 1 a 0.
luego de cada PERTENCE se escribe en el file.

FALTA VER QUE PASA SI TERMINA LA LINEA (SE BUGEA SEGURO)

holax rey -> hola rey (Hubo errores. Caracteres borrados: x)
holarey -> hola rey (Hubo errores)
aholaf reyj -> hola rey (Hubo errores. Caracteres borrados: a, f, j, ' ')
holarrey (Hubo errores. Caracteres borrados: r)