
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "BD.h"
#include "../Jerarquia/Usuario/usuario.h"
#include "../Jerarquia/Socio/socio.h"
#include "../Jerarquia/Reserva/reserva.h"
#include "../Jerarquia/Libro/libro.h"
#include "../Jerarquia/Biblioteca/biblioteca.h"

//Inserts
int insertUsuario(sqlite3 *db, int idUsuario, char nombre[], char apellido[], char nomUsuario[], char contrasenya[]){
	sqlite3_stmt *stmt;

	char sql[] = "insert into usuario (idUsuario, nombre, apellido, nomUsuario, contrasenya) values (NULL, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, apellido, strlen(apellido), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, nomUsuario, strlen(nomUsuario), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, contrasenya, strlen(contrasenya), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Usuario table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertSocio(sqlite3 *db, char nombre[], char apellido[], int DNI, char correo[], char residencia[], int codigoPostal){
	sqlite3_stmt *stmt;

	char sql[] = "insert into socio (nombre, apellido, DNI, correo, residencia, codigoPostal) values (?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, apellido, strlen(apellido), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, DNI, strlen(DNI), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, correo, strlen(correo), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, residencia, strlen(residencia), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, codigoPostal, strlen(codigoPostal), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Socio table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertLibro(sqlite3 *db, int idLibro, char isbn[], char titulo[], char autor[], char genero[], int paginas){
	sqlite3_stmt *stmt;

	char sql[] = "insert into libro (idLibro, isbn, titulo, autor, genero, paginas) values (NULL, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, isbn, strlen(isbn), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, titulo, strlen(titulo), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, autor, strlen(autor), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, genero, strlen(genero), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, paginas, strlen(paginas), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Libro table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertBiblioteca(sqlite3 *db, int idBiblioteca, char nombre[], int aforo, char estado[], char genero[], char instalacion[], char barrio[]){
	sqlite3_stmt *stmt;

	char sql[] = "insert into biblioteca (idBiblioteca, nombre, aforo, estado, genero, instalacion, barrio) values (NULL, ?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, aforo, strlen(aforo), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, estado, strlen(estado), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, genero, strlen(genero), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, instalacion, strlen(instalacion), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, barrio, strlen(barrio), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Biblioteca table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertReserva(sqlite3 *db, int idReserva, char concepto[], char fechaInicio[], char fechaFinal[], char nomUsuario[], char isbn[]){
	sqlite3_stmt *stmt;

	char sql[] = "insert into reserva (idReserva, concepto, fechaInicio, fechaFinal, nomUsuario, isbn) values (NULL, ?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, concepto, strlen(concepto), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, fechaInicio, strlen(fechaInicio), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, fechaFinal, strlen(fechaFinal), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, nomUsuario, strlen(nomUsuario), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, isbn, strlen(isbn), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into Reserva table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

////Updates
//
//int updateUsuario(sqlite3 *db, int idUsuario, char nombre[], char apellido[], char nomUsuario[], char contrasenya[]){
//	sqlite3_stmt *stmt;
//
//	char sql[] = "update usuario set nombre = ?, apellido = ?, nomUsuario = ?, contrasenya = ? where idUsuario = ?";
//	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
//	if (result != SQLITE_OK) {
//		printf("Error preparing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("SQL query prepared (UPDATE)\n");
//
//	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 2, apellido, strlen(apellido), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 3, nomUsuario, strlen(nomUsuario), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 4, contrasenya, strlen(contrasenya), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 5, idUsuario, strlen(idUsuario), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	result = sqlite3_step(stmt);
//	if (result != SQLITE_DONE) {
//		printf("Error updating new data into Usuario table\n");
//		return result;
//	}
//
//	result = sqlite3_finalize(stmt);
//	if (result != SQLITE_OK) {
//		printf("Error finalizing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("Prepared statement finalized (UPDATE)\n");
//
//	return SQLITE_OK;
//}
//
//int updateSocio(sqlite3 *db, char nombre[], char apellido[], int DNI, char correo[], char residencia[], int codigoPostal){
//	sqlite3_stmt *stmt;
//
//	char sql[] = "update socio nombre = ?, apellido = ?, correo = ?, residencia = ?, codigoPostal = ? where DNI = ?";
//	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
//	if (result != SQLITE_OK) {
//		printf("Error preparing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("SQL query prepared (UPDATE)\n");
//
//	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 2, apellido, strlen(apellido), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 3, DNI, strlen(DNI), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 4, correo, strlen(correo), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 5, residencia, strlen(residencia), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 6, codigoPostal, strlen(codigoPostal), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	result = sqlite3_step(stmt);
//	if (result != SQLITE_DONE) {
//		printf("Error updating new data into Socio table\n");
//		return result;
//	}
//
//	result = sqlite3_finalize(stmt);
//	if (result != SQLITE_OK) {
//		printf("Error finalizing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("Prepared statement finalized (UPDATE)\n");
//
//	return SQLITE_OK;
//}
//
//int updateLibro(sqlite3 *db, int idLibro, char isbn[], char titulo[], char autor[], char genero[], int paginas){
//	sqlite3_stmt *stmt;
//
//	char sql[] = "update libro isbn = ?, titulo = ?, autor = ?, genero = ?, paginas = ? where idLibro = ?";
//	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
//	if (result != SQLITE_OK) {
//		printf("Error preparing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("SQL query prepared (UPDATE)\n");
//
//	result = sqlite3_bind_text(stmt, 1, isbn, strlen(isbn), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 2, titulo, strlen(titulo), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 3, autor, strlen(autor), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 4, genero, strlen(genero), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 5, paginas, strlen(paginas), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 5, paginas, strlen(paginas), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 6, paginas, strlen(idLibro), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	result = sqlite3_step(stmt);
//	if (result != SQLITE_DONE) {
//		printf("Error updating new data into Libro table\n");
//		return result;
//	}
//
//	result = sqlite3_finalize(stmt);
//	if (result != SQLITE_OK) {
//		printf("Error finalizing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("Prepared statement finalized (UPDATE)\n");
//
//	return SQLITE_OK;
//}
//
//int updateBiblioteca(sqlite3 *db, int idBiblioteca, char nombre[], int aforo, char estado[], char genero[], char instalacion[], char barrio[]){
//	sqlite3_stmt *stmt;
//
//	char sql[] = "update into biblioteca nombre = ?, aforo = ?, estado = ?, genero = ?, instalacion = ?, barrio = ? where idBiblioteca = ?";
//	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
//	if (result != SQLITE_OK) {
//		printf("Error preparing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("SQL query prepared (UPDATE)\n");
//
//	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 2, aforo, strlen(aforo), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 3, estado, strlen(estado), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 4, genero, strlen(genero), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 5, instalacion, strlen(instalacion), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 6, barrio, strlen(barrio), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	result = sqlite3_bind_text(stmt, 7, idBiblioteca, strlen(idBiblioteca), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	result = sqlite3_step(stmt);
//	if (result != SQLITE_DONE) {
//		printf("Error updating new data into Biblioteca table\n");
//		return result;
//	}
//
//	result = sqlite3_finalize(stmt);
//	if (result != SQLITE_OK) {
//		printf("Error finalizing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("Prepared statement finalized (UPDATE)\n");
//
//	return SQLITE_OK;
//}
//
//int updateReserva(sqlite3 *db, int idReserva, char concepto[], char fechaInicio[], char fechaFinal[], char nomUsuario[], char isbn[]){
//	sqlite3_stmt *stmt;
//
//	char sql[] = "update reserva concepto = ?, fechaInicio = ?, fechaFinal = ?, nomUsuario = ?, isbn = ? where idReserva = ?";
//	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
//	if (result != SQLITE_OK) {
//		printf("Error preparing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("SQL query prepared (UPDATE)\n");
//
//	result = sqlite3_bind_text(stmt, 1, concepto, strlen(concepto), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 2, fechaInicio, strlen(fechaInicio), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 3, fechaFinal, strlen(fechaFinal), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 4, nomUsuario, strlen(nomUsuario), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//	result = sqlite3_bind_text(stmt, 5, isbn, strlen(isbn), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	result = sqlite3_bind_text(stmt, 6, idReserva, strlen(idReserva), SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	result = sqlite3_step(stmt);
//	if (result != SQLITE_DONE) {
//		printf("Error updating new data into Reserva table\n");
//		return result;
//	}
//
//	result = sqlite3_finalize(stmt);
//	if (result != SQLITE_OK) {
//		printf("Error finalizing statement (UPDATE)\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}
//
//	printf("Prepared statement finalized (UPDATE)\n");
//
//	return SQLITE_OK;
//}

//Getters
Usuario getUsuario(sqlite3 *db, int idUser) {
	sqlite3_stmt *stmt;
	Usuario u;

	char sql[] = "select idUsuario, nombre, apellido, nomUsuario, contrasenya from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	//Los atributos de Usuario que se recibirán
	int idUsuario;
	char nombre[20];
	char apellido[20];
	char nomUsuario[100];
	char contrasenya[100];

	printf("\n");
	printf("\n");
	printf("Recuperando usuario:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			idUsuario = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char*) sqlite3_column_text(stmt, 2));
			strcpy(nomUsuario, (char*) sqlite3_column_text(stmt, 3));
			strcpy(contrasenya, (char*) sqlite3_column_text(stmt, 4));
			if (idUser == idUsuario) {
				u.idUsuario = idUsuario;
				strcpy(u.nombre, nombre);
				strcpy(u.apellido, apellido);
				strcpy(u.nomUsuario, nomUsuario);
				strcpy(u.contrasenya, contrasenya);
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return u;
}

Socio getSocio(sqlite3 *db, int dni) {

	sqlite3_stmt *stmt;
	Socio s;

	char sql[] =
			"select nombre, apellido, DNI, correo, residencia, codigoPostal from socio";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	char nombre[20];
	char apellido[20];
	int DNI;
	char correo[20];
	char residencia[30];
	int codigoPostal;

	printf("\n");
	printf("\n");
	printf("Recuperando usuario:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 0));
			strcpy(apellido, (char*) sqlite3_column_text(stmt, 1));
			DNI = sqlite3_column_int(stmt, 2);
			strcpy(correo, (char*) sqlite3_column_text(stmt, 3));
			strcpy(residencia, (char*) sqlite3_column_text(stmt, 4));
			codigoPostal = sqlite3_column_int(stmt, 5);
			if (dni == DNI) {
				strcpy(s.nombre, nombre);
				strcpy(s.apellido, apellido);
				s.DNI = DNI;
				strcpy(s.correo, correo);
				strcpy(s.residencia, residencia);
				s.codigoPostal = codigoPostal;
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return s;
}

Libro getLibro(sqlite3 *db, int idLib){

	sqlite3_stmt *stmt;
	Libro l;

	char sql[] = "select idLibro, isbn, titulo, autor, genero, paginas from libro";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	int idLibro;
	char isbn[13];
	char titulo[20];
	char autor[20];
	char genero[20];
	int paginas;

	printf("\n");
	printf("\n");
	printf("Recuperando libro:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			idLibro = sqlite3_column_int(stmt, 0);
			strcpy(isbn, (char*) sqlite3_column_text(stmt, 1));
			strcpy(titulo, (char*) sqlite3_column_text(stmt, 2));
			strcpy(autor, (char*) sqlite3_column_text(stmt, 3));
			strcpy(genero, (char*) sqlite3_column_text(stmt, 4));
			paginas = sqlite3_column_int(stmt, 5);

			if (idLib == idLibro) {
				l.idLibro = idLibro;
				strcpy(l.isbn, isbn);
				strcpy(l.titulo, titulo);
				strcpy(l.autor, autor);
				strcpy(l.genero, genero);
				l.paginas = paginas;
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return l;

}

Biblioteca getBiblioteca(sqlite3 *db, int idBiblio){
	sqlite3_stmt *stmt;
	Biblioteca b;

	char sql[] = "select idBiblioteca, nombre, aforo, estado, genero, instalacion, barrio from biblioteca";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	int idBiblioteca;
	char nombre[40];
	int aforo;
	char estado[20];
	char genero[15];
	char instalacion[20];
	char barrio[15];

	printf("\n");
	printf("\n");
	printf("Recuperando biblioteca:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			idBiblioteca = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			aforo = sqlite3_column_int(stmt, 2);
			strcpy(estado, (char*) sqlite3_column_text(stmt, 3));
			strcpy(genero, (char*) sqlite3_column_text(stmt, 4));
			strcpy(instalacion, (char*) sqlite3_column_text(stmt, 5));
			strcpy(barrio, (char*) sqlite3_column_text(stmt, 6));
			if (idBiblio == idBiblioteca) {
				b.idBiblioteca = idBiblioteca;
				strcpy(b.nombre, nombre);
				b.aforo = aforo;
				strcpy(b.estado, estado);
				strcpy(b.genero, genero);
				strcpy(b.instalacion, instalacion);
				strcpy(b.barrio, barrio);
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return b;
}

Reserva getReserva(sqlite3 *db, int idRes){

	sqlite3_stmt *stmt;
	Reserva r;

	char sql[] = "select idReserva, concepto, fechaInicio, fechaFinal, nomUsuario, isbn from reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	int idReserva;
	char concepto[100];
	char fechaInicio[8];
	char fechaFinal[8];
	char nomUsuario[20];
	char isbn[13];

	printf("\n");
	printf("\n");
	printf("Recuperando biblioteca:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			idReserva = sqlite3_column_int(stmt, 0);
			strcpy(concepto, (char*) sqlite3_column_text(stmt, 1));
			strcpy(fechaInicio, (char*) sqlite3_column_text(stmt, 2));
			strcpy(fechaFinal, (char*) sqlite3_column_text(stmt, 3));
			strcpy(nomUsuario, (char*) sqlite3_column_text(stmt, 4));
			strcpy(isbn, (char*) sqlite3_column_text(stmt, 5));
			if (idRes == idReserva) {
				r.idReserva = idReserva;
				strcpy(r.concepto, concepto);
				strcpy(r.fechaInicio, fechaInicio);
				strcpy(r.fechaFinal, fechaFinal);
				strcpy(r.usuario.nomUsuario, nomUsuario);
				strcpy(r.libro.isbn, isbn);
			}
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	return r;

}


//Prints
int imprimirUsuarios(sqlite3 *db){

	sqlite3_stmt *stmt;

	char sql[] = "select idUsuario, nombre, apellido, nomUsuario, contrasenya from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int idUsuario;
	char nombre[20];
	char apellido[20];
	char nomUsuario[20];
	char contrasenya[20];

	printf("\n");
	printf("==================================\n");
	printf("Usuarios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			idUsuario = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));
			strcpy(nomUsuario, (char *) sqlite3_column_text(stmt, 3));
			strcpy(contrasenya, (char *) sqlite3_column_text(stmt, 4));
			printf("Id: %d Nombre: %s Apellido: %s Contrasenya: %s Nick: %s Contrasena: %s\n", idUsuario, nombre, apellido, nomUsuario, contrasenya);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int imprimirSocios(sqlite3 *db){

	sqlite3_stmt *stmt;

	char sql[] = "select * from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char nombre[20];
	char apellido[20];
	int dni[8];
	char correo[20];
	char residencia[30];
	int codigoPostal[5];

	printf("\n");
	printf("==================================\n");
	printf("Socios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 0));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 1));
			strcpy(dni, sqlite3_column_int(stmt, 2));
			strcpy(correo, (char *) sqlite3_column_text(stmt, 3));
			strcpy(residencia, (char *) sqlite3_column_text(stmt, 4));
			strcpy(codigoPostal, sqlite3_column_text(stmt, 5));
			printf("Nombre: %s Apellido: %s DNI: %i Correo: %s Residencia: %s Codigo postal: %i\n", nombre, apellido, dni, correo, residencia, codigoPostal);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int imprimirLibros(sqlite3 *db){

	sqlite3_stmt *stmt;

	char sql[] = "select idLibro, isbn, titulo, autor, genero, paginas from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int idLibro;
	char isbn[20];
	char titulo[20];
	char autor[20];
	char genero[20];
	char paginas[20];

	printf("\n");
	printf("==================================\n");
	printf("Usuarios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			idLibro = sqlite3_column_int(stmt, 0);
			strcpy(isbn, (char *) sqlite3_column_text(stmt, 1));
			strcpy(titulo, (char *) sqlite3_column_text(stmt, 2));
			strcpy(autor, (char *) sqlite3_column_text(stmt, 3));
			strcpy(genero, (char *) sqlite3_column_text(stmt, 4));
			strcpy(paginas, (char *) sqlite3_column_text(stmt, 4));
			printf("Id: %d Isbn: %s Título: %s Autor: %s Género: %s Páginas: %s\n", idLibro, isbn, titulo, autor, genero, paginas);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int imprimirBiblioteca(sqlite3 *db){

	sqlite3_stmt *stmt;

	char sql[] = "select idBiblioteca, nombre, aforo, estado, genero, instalacion, barrio from biblioteca";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int idBiblioteca;
	char nombre[10];
	char aforo[3];
	char estado[20];
	char genero[15];
	char instalacion[20];
	char barrio[15];

	printf("\n");
	printf("==================================\n");
	printf("Bibliotecas:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			idBiblioteca = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(aforo, (char *) sqlite3_column_text(stmt, 2));
			strcpy(estado, (char *) sqlite3_column_text(stmt, 3));
			strcpy(genero, (char *) sqlite3_column_text(stmt, 4));
			strcpy(instalacion, (char *) sqlite3_column_text(stmt, 5));
			strcpy(barrio, (char *) sqlite3_column_text(stmt, 6));
			printf("Id: %d Nombre: %s Aforo: %s Estado: %s Genero: %s Instalación: %s Barrio: %s\n", idBiblioteca, nombre, aforo, estado, genero, instalacion, barrio);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

int imprimirReserva(sqlite3 *db){

	sqlite3_stmt *stmt;

	char sql[] = "select idReserva, concepto, fechaInicio, fechaFinal, nomUsuario, isbn from reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int idReserva;
	char nombre[20];
	char concepto[100];
	char fechaInicio[8];
	char fechaFinal[8];
	char nomUsuario[20];
	char isbn[13];

	printf("\n");
	printf("==================================\n");
	printf("Reservas:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			idReserva = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(concepto, (char *) sqlite3_column_text(stmt, 2));
			strcpy(fechaInicio, (char *) sqlite3_column_text(stmt, 3));
			strcpy(fechaFinal, (char *) sqlite3_column_text(stmt, 4));
			strcpy(nomUsuario, (char *) sqlite3_column_text(stmt, 5));
			strcpy(isbn, (char *) sqlite3_column_text(stmt, 6));
			printf("Id: %d Nombre: %s Concepto: %s Fecha inicio: %s Fecha final: %s NomUsuario: %s Isbn: %s\n", idReserva, nombre, concepto, fechaInicio, fechaFinal, nomUsuario, isbn);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

//Deletes
int deleteUsuario(sqlite3 *db, char nomUsuario[]) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from usuario where nomUsuario = '?' ";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteSocios(sqlite3 *db, int dni) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from socio where DNI = '?' ";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteLibros(sqlite3 *db, char isbn[]) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from libro where isbn = '?' ";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteBibliotecas(sqlite3 *db, int idBiblioteca) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from biblioteca where idBiblioteca = '?' ";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteReservas(sqlite3 *db, int idReserva) {
	sqlite3_stmt *stmt;

	char sql[] = "delete from reserva where idReserva = '?' ";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

//Delete everything
int deleteAllUsuarios(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete * from usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllSocios(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete * from socio";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllLibros(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete * from libro";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllBibliotecas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete * from biblioteca";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}

int deleteAllReservas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "delete * from reserva";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}
