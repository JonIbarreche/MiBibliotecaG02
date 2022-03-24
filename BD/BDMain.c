/*  #include <stdio.h>
#include "sqlite3.h"
#include <string.h>

	int main() {
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

	sqlite3_open("futbol.sqlite", &db);

	  --- INSERT ---
	char sql1[] = "insert into campeonatos (id, nombre, campeon) values (NULL, ?, ?)";
	char nombre[] = "Copa 2020-21";
	int campeon = 3;

	sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, campeon);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error insertando el campeonato\n");
	}else{
		printf("Campeonato %s(%i) insertado\n", nombre, campeon);
	}

	sqlite3_finalize(stmt);
	 --- INSERT (fin) ---

	 --- SELECT ---
	char sql2[] = "select c.nombre from campeonatos c, equipos e where c.campeon=e.id and e.nombre=?";
	char equipo[] = "F.C. Barcelona";

	sqlite3_prepare_v2(db, sql2, strlen(sql2), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, equipo, strlen(equipo), SQLITE_STATIC);

	printf("\n");
	printf("Mostrando campeonatos de %s:\n", equipo);
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("%s\n", (char*) sqlite3_column_text(stmt, 0));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);

	  --- SELECT (fin) ---

	sqlite3_close(db);

	return 0;
}
*/
