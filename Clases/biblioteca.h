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
	char nombre;
	int aforo;
	char estado;
	char genero;
	char instalacion;
	char barrio;
//	Libro libro;
}Biblioteca;

void visualizarBiblioteca (Biblioteca* bibliotecas, int tamanyo);

#endif /* BIBLIOTECA_H_ */
