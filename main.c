#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Menu/menu.h"
#include "BD/sqlite3.h"
#include "Jerarquia/Socio/socio.h"
#include "Jerarquia/Usuario/usuario.h"
#include "Jerarquia/Biblioteca/biblioteca.h"

int main(void)
{
	sqlite3 *db;

		int result = sqlite3_open("DB.db", &db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
		}

	menuPrincipal(db, result);

}
