/*
 * BD.h
 *
 *  Created on: 2 abr. 2022
 *      Author: jonib
 */

#ifndef BD_BD_H_
#define BD_BD_H_
#include "../Jerarquia/Usuario/usuario.h"
#include "../Jerarquia/Socio/socio.h"
#include "../Jerarquia/Reserva/reserva.h"
#include "../Jerarquia/Libro/libro.h"
#include "../Jerarquia/Biblioteca/biblioteca.h"
#include "sqlite3.h"

int insertUsuario(sqlite3 *db, int idUsuario, char nombre[], char apellido[], char nomUsuario[], char contrasenya[]);
int insertSocio(sqlite3 *db, char nombre[], char apellido[], int DNI, char correo[], char residencia[], char codigoPostal[]);
int insertLibro(sqlite3 *db, int idLibro, char isbn[], char titulo[], char autor[], char genero[], int paginas);
int insertBiblioteca(sqlite3 *db, int idBiblioteca, char nombre[], int aforo, char estado[], char genero[], char instalacion[], char barrio[]);
int insertReserva(sqlite3 *db, int idReserva, char concepto[], char fechaInicio[], char fechaFinal[], char nomUsuario[], char isbn[]);
int imprimirUsuarios(sqlite3 *db);
int imprimirSocios(sqlite3 *db);
int imprimirLibros(sqlite3 *db);
int imprimirBiblioteca(sqlite3 *db);
int imprimirReserva(sqlite3 *db);
int deleteUsuario(sqlite3 *db, char nomUsuario[]);
int deleteSocios(sqlite3 *db, int dni);
int deleteLibros(sqlite3 *db, char isbn[]);
int deleteBibliotecas(sqlite3 *db, int idBiblioteca);
int deleteReservas(sqlite3 *db, int idReserva);
int deleteAllUsuarios(sqlite3 *db);
int deleteAllSocios(sqlite3 *db);
int deleteAllLibros(sqlite3 *db);
int deleteAllBibliotecas(sqlite3 *db);
int deleteAllReservas(sqlite3 *db);
Usuario getUsuario(sqlite3 *db, int idUser);
Socio getSocio(sqlite3 *db, int dni);
Libro getLibro(sqlite3 *db, int idLibro);
Biblioteca getBiblioteca(sqlite3 *db, int idBiblioteca);
Reserva getReserva(sqlite3 *db, int idReserva);

#endif /* BD_BD_H_ */
