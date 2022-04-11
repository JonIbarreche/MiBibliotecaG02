#include "libro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../BD/BD.h"
#include "../../BD/sqlite3.h"

void anadirLibro(sqlite3 *db, int result, Libro libro)
{
	result = insertLibro(db, libro.idLibro, libro.isbn, libro.titulo, libro.autor, libro.genero, libro.paginas);
	if(result != SQLITE_OK) {
		printf("Error al insertar el libro.\n");
		printf("%s%n", sqlite3_errmsg(db));
	}
}

void modificarLibro(sqlite3 *db, int result, int id, Libro libro)
{
	result = deleteLibros(db, id);
	if(result != SQLITE_OK)
	{
		printf("Error eliminando el libro.\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	result = insertLibro(db, libro.idLibro, libro.isbn, libro.titulo, libro.autor, libro.genero, libro.paginas);
	if(result != SQLITE_OK)
	{
		printf("Error al insertar el libro.\n");
		printf("%s%n", sqlite3_errmsg(db));
	}
}

void imprimirLibro(sqlite3 *db, Libro libro)
{
	printf("ID: %i\n", libro.idLibro);
	printf("ISBD: %s\n", libro.isbn);
	printf("TITULO: %s\n", libro.titulo);
	printf("AUTOR: %s\n", libro.autor);
	printf("GENERO: %s\n", libro.genero);
	printf("PAGINAS: %i\n", libro.paginas);
}

void eliminarLibro(sqlite3 *db, int result, int id)
{
	result = deleteLibros(db, id);
	if(result != SQLITE_OK)
	{
		printf("Error al eliminar el libro.\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}

void eliminarTodosLibros(sqlite3 *db, int result)
{
	result = deleteAllLibros(db);
	if(result != SQLITE_OK)
	{
		printf("Error al eliminar todos los libros.\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}
