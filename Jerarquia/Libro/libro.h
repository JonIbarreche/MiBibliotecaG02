#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct{
	int idLibro;
	char isbn[13];
	char titulo[20];
	char autor[20];
	char genero[20];
	int paginas[4];
}Libro;

void visualizarLibros(Libro* libros, int tamanyo);
void visualizarLibro(Libro* libro);

#endif
