#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/* typedef struct{
	int idLibro;
	char titulo;
	char genero;
	char autor;
}Libro;
*/

typedef struct{
	int idBiblioteca;
	char nombre[10];
	int aforo[3];
	char estado[20];
	char genero[15];
	char instalacion[20];
	char barrio[15];
//	Libro libro;
}Biblioteca;

void visualizarBiblioteca (Biblioteca* bibliotecas, int tamanyo);

#endif /* BIBLIOTECA_H_ */
