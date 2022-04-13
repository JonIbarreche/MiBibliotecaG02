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

//void menuPrincipal(sqlite3 *db, int result);
//void gestionBibliotecas(sqlite3 *db, int result);
//void gestionUsuarios(sqlite3 *db, int result);
//void gestionSocios(sqlite3 *db, int result);
//void gestionReservas(sqlite3 *db, int result);
//void gestionLibros(sqlite3 *db, int result);
//void borrarDatos(sqlite3 *db, int result);

int main(void)
{
	//Usuario

	Usuario u;
	u.idUsuario = 0;
	strcpy(u.nombre, "Unai");
	strcpy(u.apellido, "Fernandez");
	strcpy(u.nomUsuario, "unaifj");
	strcpy(u.contrasenya, "1234");

	Usuario u2;
	u2.idUsuario = 1;
	strcpy(u2.nombre, "Jon");
	strcpy(u2.apellido, "Ibarretxe");
	strcpy(u2.nomUsuario, "jonibr");
	strcpy(u2.contrasenya, "123");

	Usuario u3;
	u3.idUsuario = 2;
	strcpy(u3.nombre, "Andrea");
	strcpy(u3.apellido, "Martinez");
	strcpy(u3.nomUsuario, "andream");
	strcpy(u3.contrasenya, "123");

	Usuario u4;
	u4.idUsuario = 3;
	strcpy(u4.nombre, "Samuel");
	strcpy(u4.apellido, "Martin");
	strcpy(u4.nomUsuario, "samuelunpiti");
	strcpy(u4.contrasenya, "123");

	Socio s;
	strcpy(s.nombre, "Iker");
	strcpy(s.apellido, "Jimenez");
	s.DNI = 0;
	strcpy(s.correo, "iker@gmail.com");
	strcpy(s.residencia, "Bilbao");
	s.codigoPostal = 10;

	Socio s1;
	strcpy(s1.nombre, "Ander");
	strcpy(s1.apellido, "Cortes");
	s1.DNI = 78397293;
	strcpy(s1.correo, "ander@gmail.com");
	strcpy(s1.residencia, "Bilbao");
	s1.codigoPostal = 11;

	Socio s2;
	strcpy(s2.nombre, "Ibai");
	strcpy(s2.apellido, "llanos");
	s2.DNI = 78777293;
	strcpy(s2.correo, "iker@gmail.com");
	strcpy(s2.residencia, "Bilbao");
	s2.codigoPostal = 12;

	Libro l;
	l.idLibro = 0;
	strcpy(l.isbn, "9923");
	strcpy(l.titulo, "Cien años");
	strcpy(l.autor, "Latifi");
	strcpy(l.genero, "Guerra");
	l.paginas = 150;

	Libro l1;
	l1.idLibro = 1;
	strcpy(l1.isbn, "8823");
	strcpy(l1.titulo, "Romancero");
	strcpy(l1.autor, "Alonso");
	strcpy(l1.genero, "Romance");
	l1.paginas = 260;

	Libro l2;
	l2.idLibro = 0;
	strcpy(l2.isbn, "7723");
	strcpy(l2.titulo, "Educacion");
	strcpy(l2.autor, "Samuel");
	strcpy(l2.genero, "Educativo");
	l2.paginas = 300;

	Biblioteca b;
	b.idBiblioteca = 0;
	strcpy(b.nombre, "Biblioteca Basurto");
	b.aforo = 300;
	strcpy(b.estado, "08:00 - 20:00");
	strcpy(b.genero, "Militar");
	strcpy(b.instalacion, "Zona Fumadores");
	strcpy(b.barrio, "Basurto");

	Biblioteca b1;
	b1.idBiblioteca = 1;
	strcpy(b1.nombre, "Biblioteca Indautxu");
	b1.aforo = 400;
	strcpy(b1.estado, "08:30 - 19:00");
	strcpy(b1.genero, "Arte");
	strcpy(b1.instalacion, "Sala Ordenadores");
	strcpy(b1.barrio, "Indautxu");

	Biblioteca b2;
	b2.idBiblioteca = 2;
	strcpy(b2.nombre, "Biblioteca Erandio");
	b2.aforo = 100;
	strcpy(b2.estado, "10:00 - 17:00");
	strcpy(b2.genero, "Urbano");
	strcpy(b2.instalacion, "Sala Estudio");
	strcpy(b2.barrio, "Erandio");

	Reserva r;
	r.idReserva = 0;
	strcpy(r.concepto, "Reserva Libro 1");
	strcpy(r.fechaInicio, "14/04/22");
	strcpy(r.fechaFinal, "14/05/22");
	strcpy(r.usuario.nomUsuario, "jonibr");
	strcpy(r.libro.isbn, "9923");

	Reserva r1;
	r1.idReserva = 1;
	strcpy(r1.concepto, "Reserva Libro 2");
	strcpy(r1.fechaInicio, "19/04/22");
	strcpy(r1.fechaFinal, "19/05/22");
	strcpy(r1.usuario.nomUsuario, "unaifj");
	strcpy(r1.libro.isbn, "8823");

	Reserva r2;
	r2.idReserva = 1;
	strcpy(r2.concepto, "Reserva Libro 3");
	strcpy(r2.fechaInicio, "25/04/22");
	strcpy(r2.fechaFinal, "28/05/22");
	strcpy(r2.usuario.nomUsuario, "andream");
	strcpy(r2.libro.isbn, "7723");

	sqlite3 *db;

		int result = sqlite3_open("BD/DB.db", &db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
		}


		eliminarTodosUsuarios(db, result);
		eliminarTodosSocios(db, result);
		eliminarTodosLibros(db, result);
		eliminarTodasBibliotecas(db, result);
		eliminarTodasReservas(db, result);


		anadirUsuario(db, result, u);
		anadirUsuario(db, result, u2);
		anadirUsuario(db, result, u3);
		anadirUsuario(db, result, u4);

		anadirSocio(db, result, s);
		anadirSocio(db, result, s1);
		anadirSocio(db, result, s2);

		anadirLibro(db, result, l);
		anadirLibro(db, result, l1);
		anadirLibro(db, result, l2);

		anadirBiblioteca(db, result, b);
		anadirBiblioteca(db, result, b1);
		anadirBiblioteca(db, result, b2);

		anadirReserva(db, result, r);
		anadirReserva(db, result, r1);
		anadirReserva(db, result, r2);


		imprimirUsuarios(db);
		imprimirSocios(db);
		imprimirLibros(db);
		imprimirBiblioteca(db);
		imprimirReserva(db);


		inicioAdmin();


	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error closing database\n");
		printf("%s\n", sqlite3_errmsg(db));
	}


	return 0;
}
