#include "../BD/sqlite3.h"

#ifndef MENU_MENU_H_
#define MENU_MENU_H_

void menuPrincipal(sqlite3 *db, int result);
void gestionBibliotecas(sqlite3 *db, int result);
void gestionUsuarios(sqlite3 *db, int result);
void gestionSocios(sqlite3 *db, int result);
void gestionReservas(sqlite3 *db, int result);
void gestionLibros(sqlite3 *db, int result);
void borrarDatos(sqlite3 *db, int result);


#endif /* MENU_MENU_H_ */
