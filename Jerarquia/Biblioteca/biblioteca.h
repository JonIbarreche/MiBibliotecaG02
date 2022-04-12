#include "../../BD/sqlite3.h"

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
	char nombre[40];
	int aforo;
	char estado[20];
	char genero[15];
	char instalacion[20];
	char barrio[15];
}Biblioteca;

void anadirBiblioteca(sqlite3 *db, int result, Biblioteca biblioteca);
void modificarBiblioteca(sqlite3 *db, int result, int id, Biblioteca biblioteca);
void imprimirBibliotecas(sqlite3 *db, Biblioteca biblioteca);
void eliminarBibliotecas(sqlite3 *db, int result, int id);
void eliminarTodasBibliotecas(sqlite3 *db, int result);

#endif /* BIBLIOTECA_H_ */
