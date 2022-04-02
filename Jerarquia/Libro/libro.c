#include "libro.h"

#include <stdio.h>
#include <stdlib.h>

void visualizarLibros(Libro* libros, int tamanyo){
	for (int i = 0; i < tamanyo ; i++){
        printf("================================");
        printf("----------- Libro %i -----------", i);
		printf("ISBN: %s", (libros+ i)->isbn);
		printf("Título: %s", (libros+ i)->titulo);
		printf("Autor: %s", (libros+ i)->autor);
		printf("Género: %s", (libros+ i)->genero);
        printf("Páginas: %i", (libros+ i)->paginas);
	}
}

void visualizarLibro(Libro* libro){
    printf("------------------------");
    printf("ISBN: %s", libro->isbn);
    printf("Título: %s", libro->titulo);
    printf("Autor: %s", libro->autor);
    printf("Género: %s", libro->genero);
    printf("Páginas: %i", libro->paginas);
}
