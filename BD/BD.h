/*
 * BD.h
 *
 *  Created on: 2 abr. 2022
 *      Author: jonib
 */

#ifndef BD_BD_H_
#define BD_BD_H_
#include "Jerarquia/Usuario/usuario.h"
#include "Jerarquia/Socio/socio.h"
#include "Jerarquia/Reserva/reserva.h"
#include "Jerarquia/Libro/libro.h"
#include "Jerarquia/Biblioteca/biblioteca.h"
#include "sqlite3.h"

int insertUsuario(sqlite3 *db, int idUsuario, char nombre[], char apellido[], char nomUsuario[], char contrasenya[]);
Usuario getUsuario(int idUsuario);
int imprimirUsuarios(sqlite3 *db);
int deleteUsuario(sqlite3 *db);
int deleteAllUsuarios(sqlite3 *db);

#endif /* BD_BD_H_ */
