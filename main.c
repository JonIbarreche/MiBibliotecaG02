#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Menu/menu.h"
#include "BD/sqlite3.h"
#include "Jerarquia/Socio/socio.h"
#include "Jerarquia/Usuario/usuario.h"
#include "Jerarquia/Biblioteca/biblioteca.h"
#include "Jerarquia/Libro/libro.h"
#include "Jerarquia/Reserva/reserva.h"

int main(void)
{
	sqlite3 *db;

		int result = sqlite3_open("BD/DB.db", &db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
		}

	menuPrincipal(db, result);

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error closing database\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Database closed\n");
	return 0;
}
