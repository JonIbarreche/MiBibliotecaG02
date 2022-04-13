#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Jerarquia/Usuario/usuario.h"
#include "../Jerarquia/Biblioteca/biblioteca.h"
#include "../Jerarquia/Socio/socio.h"
#include "../Jerarquia/Reserva/reserva.h"
#include "../Jerarquia/Libro/libro.h"

#include "../BD/BD.h"
#include "../BD/sqlite3.h"

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 5
#define MAX_INTENTOS 3

#define NUMERO_USUARIOS 1

int inicioAdmin() {
	char usuario[LONGITUD + 1];
	char clave[LONGITUD + 1];
	int intento = 0;
	int ingresa = 0;
	char caracter;
	int i = 0;
	int j = 0;

	/* Declaraci�n e inicializaci�n de arreglos de usuarios y claves */
	char usuarios[NUMERO_USUARIOS][LONGITUD + 1] = { "admin" };
	char claves[NUMERO_USUARIOS][LONGITUD + 1] = { "admin" };

	do {
		i = 0;
		//system("cls");
		printf("\n\t\t\tINICIO DE SESION\n");
		printf("\t\t\t---------------\n");
		printf("\n\tUSUARIO: ");
		gets(usuario);
		printf("\tCLAVE: ");
		while (caracter = getch())
		{
			if (caracter == TECLA_ENTER)
			{
				clave[i] = '\0';
				break;
			} else if (caracter == TECLA_BACKSPACE) {
				if (i > 0)
				{
					i--;
					printf("\b \b");
				}
			} else {
				if (i < LONGITUD)
				{
					printf("*");
					clave[i] = caracter;
					i++;
				}
			}
		}
		/* El usuario y clave debe coincidir con alguno de los que se encuentran en el array */
		for (j = 0; j < NUMERO_USUARIOS; ++j)
		{
			if (strcmp(usuario, usuarios[j]) == 0 && strcmp(clave, claves[j]) == 0)
			{
				ingresa = 1;
				break;
			}
		}
		if (ingresa == 0)
		{
			printf("\n\tUsuario y/o clave son incorrectos\n");
			intento++;
			getchar();
		}
	} while (intento < MAX_INTENTOS && ingresa == 0);
	if (ingresa == 1)
	{
		printf("\n\n\tBienvenido al Sistema\n");
		menuPrincipal();
	} else {
		printf("\n\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
	}
	return 0;
}

void menuPrincipal(sqlite3 *db, int result) {
	char op;

	do {
		printf("\t\nMENU PRINCIPAL\n");
		printf("================================\n\n");
		printf("1. Gestionar bibliotecas\n");
		printf("2. Gestionar usuarios\n");
		printf("3. Gestionar socios\n");
		printf("4. Gestionar reservas\n");
		printf("5. Gestionar libros\n");
		printf("6. Importar datos desde fichero\n");
		printf("7. Borrar base de datos\n");
		printf("8. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '8');

		switch (op) {
		case '1':
			gestionBibliotecas(db, result);
			break;
		case '2':
			gestionUsuarios(db, result);
			break;
		case '3':
			gestionSocios(db, result);
			break;
		case '4':
			gestionReservas(db, result);
			break;
		case '5':
			gestionLibros(db, result);
			break;
		case '6':
			printf("\t====================================\n");
			printf("\tEsta funcion no ha sido realizada.\n");
			printf("\t\tSentimos las molestias.\n");
			printf("\t====================================\n");
			menuPrincipal(db, result);
			break;
		case '7':
			borrarDatos(db, result);
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '8');
}

void gestionBibliotecas(sqlite3 *db, int result) {
	char str[50];
	char op, id, respuesta, respuestaChar;
	Biblioteca biblioteca;
	int respuestaInt;

	do {

		printf("\tGESTION DE BIBLIOTECA\n");
		printf("================================\n\n");
		printf("1. Visualizar bibliotecas\n");
		printf("2. Anadir biblioteca\n");
		printf("3. Modificar biblioteca \n");
		printf("4. Eliminar bibliotecas\n");
		printf("5. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirBiblioteca(db);
			break;
		case '2':
			printf("Escriba (en numero) el ID que le quiere asignar.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(biblioteca.idBiblioteca, str);

			printf("Escriba el nombre de la Biblioteca.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(biblioteca.nombre, str);

			printf("Escriba (en numero) el numero MAXIMO de aforo.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(biblioteca.aforo, str);

			printf("Escriba (Formato-> xx:xx-xx:xx) de cuando a cuando esta abierta.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(biblioteca.estado, str);

			printf("Escriba los generos que mas resaltan en esta Biblioteca (Formato -> ../../..).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(biblioteca.genero, str);

			printf("Escriba las instalaciones que tiene.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(biblioteca.instalacion, str);

			printf("Escriba el nombre del barrio en el que se encuentra.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(biblioteca.barrio, str);

			anadirBiblioteca(db, result, biblioteca);
			printf("La biblioteca anadida es la siguiente: \n");
			imprimirBibliotecas(db, biblioteca);

			printf("Biblioteca anadida con exito.\n");
			break;
		case '3':
//			imprimirBiblioteca(db);
//			printf("�Que biblioteca quiere modificar?\n");
//			printf("(DEBE SELECCIONAR EL ID DE LA BIBLIOTECA A MODIFICAR\n");
//			scanf("%c", &id);
//			fflush(stdout);
//			biblioteca = getBiblioteca(db, id);
//			printf("Datos de la biblioteca:\n");
//			printf("Si quiere modificarlos escriba: s, en caso contrario: n.\n");
//
//			printf("Nombre: %s", biblioteca.nombre);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo nombre\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					biblioteca.nombre = respuestaChar;
//					printf("Nombre cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Aforo: %s", biblioteca.aforo);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo aforo\n");
//					scanf("%s", &respuestaInt);
//					fflush(stdout);
//					biblioteca.aforo = respuestaInt;
//					printf("Aforo cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Estado: %s", biblioteca.estado);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo estado\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					biblioteca.estado = respuestaChar;
//					printf("Estado cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Genero: %s", biblioteca.genero);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo genero\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					biblioteca.genero = respuestaChar;
//					printf("Genero cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Instalacion: %s", biblioteca.instalacion);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca la nueva instalacion\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					biblioteca.instalacion = respuestaChar;
//					printf("Instalacion cambiada con exito\n");
//				case 'n':
//					break;
//			}
//
//			updateBiblioteca(db,biblioteca.idBiblioteca, biblioteca.nombre, biblioteca.aforo, biblioteca.estado, biblioteca.genero, biblioteca.instalacion, biblioteca.barrio);
			break;

		case '4':
			printf("�Que biblioteca quiere eliminar?\n");
			printf("(debe introducir el ID de la biblioteca)");
			scanf("%c", &id);
			fflush(stdout);

			eliminarBibliotecas(db, result, id);
			break;
		case '5':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void gestionUsuarios(sqlite3 *db, int result) {
	char str[20];
	char op, id, respuesta, respuestaChar;
	Usuario usuario;
	int respuestaInt;

	do {

		printf("\tGESTION DE USUARIOS\n");
		printf("================================\n\n");
		printf("1. Visualizar usuario\n");
		printf("2. Anadir usuario\n");
		printf("3. Modificar usuario \n");
		printf("4. Eliminar usuario\n");
		printf("5. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirUsuarios(db);
			break;

		case '2':
			printf("Escriba (en numero) el ID que le quiere asignar.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(usuario.idUsuario, str);

			printf("Escriba el nombre del Usuario.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(usuario.nombre, str);

			printf("Escriba el apellido del Usuario.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(usuario.apellido, str);

			printf("Escriba el nick que tendra el Usuario.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(usuario.nomUsuario, str);

			printf("Escriba la contrasena que tendra el Usuario.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(usuario.contrasenya, str);

			anadirUsuario(db, result, usuario);
			printf("El usuario anadido es el siguiente: \n");
			imprimirUsuario(db, usuario);

			printf("Usuario anadido con exito.\n");
			break;
		case '3':
//			imprimirUsuarios(db);
//			printf("�Que usuario quiere modificar?\n");
//			printf("(DEBE SELECCIONAR EL NICK DEL USUARIO A MODIFICAR\n");
//			scanf("%c", &id);
//			fflush(stdout);
//			usuario = getUsuario(db, id);
//			printf("Datos del usuario:\n");
//			printf("Si quiere modificarlos escriba: s, en caso contrario: n.\n");
//
//			printf("Nombre: %s", usuario.nombre);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo usuario\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					usuario.nombre = respuestaChar;
//					printf("Nombre cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Apellido: %s", usuario.apellido);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo apellido\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					usuario.apellido = respuestaChar;
//					printf("Apellido cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Nombre de usuario: %s", usuario.nomUsuario);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo nombre de usuario\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					usuario.nomUsuario = respuestaChar;
//					printf("Nombre de usuario cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Contrasenya: %s", usuario.contrasenya);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca la nueva contrasenya\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					usuario.contrasenya = respuestaChar;
//					printf("Contrasenya cambiada con exito\n");
//				case 'n':
//					break;
//			}
//
//			updateUsuario(db, usuario.idUsuario, usuario.nombre, usuario.apellido, usuario.nomUsuario, usuario.contrasenya);
			break;
		case '4':
			printf("�Que usuario quiere eliminar?\n");
			printf("(debe introducir el nick del usuario)");
			scanf("%c", &id);
			fflush(stdout);

			eliminarUsuario(db, result, id);
			break;
		case '5':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void gestionSocios(sqlite3 *db, int result) {
	char str[20];
	char op, dni, respuesta, respuestaChar;
	Socio socio;
	int respuestaInt;

	do {

		printf("\tGESTION DE SOCIOS\n");
		printf("================================\n\n");
		printf("1. Visualizar socio\n");
		printf("2. Anadir socio\n");
		printf("3. Modificar socio \n");
		printf("4. Eliminar socio\n");
		printf("5. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirSocios(db);
			break;
		case '2':
			printf("Escriba el nombre del Socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(socio.nombre, str);

			printf("Escriba el apellido del Socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(socio.apellido, str);

			printf("Escriba el DNI del Socio.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(socio.DNI, str);

			printf("Escriba el correo del Socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(socio.correo, str);

			printf("Escriba la residencia del Socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(socio.residencia, str);

			printf("Escriba el codigo postal del Socio.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(socio.codigoPostal, str);

			anadirSocio(db, result, socio);
			printf("El socio anadido es el siguiente: \n");
			imprimirSocio(db, socio);

			printf("Socio anadido con exito.\n");
			break;
		case '3':
//			imprimirSocios(db);
//			printf("�Que socio quiere modificar?\n");
//			printf("(DEBE SELECCIONAR EL DNI DEL USUARIO A MODIFICAR\n");
//			scanf("%c", &dni);
//			fflush(stdout);
//			socio = getSocio(db, dni);
//			printf("Datos del socio:\n");
//			printf("Si quiere modificarlos escriba: s, en caso contrario: n.\n");
//
//			printf("Nombre: %s", socio.nombre);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo nombre\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					socio.nombre = respuestaChar;
//					printf("Nombre cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Apellido: %s", socio.apellido);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo apellido\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					socio.apellido = respuestaChar;
//					printf("Apellido cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("DNI: %i", socio.DNI);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch (respuesta) {
//			case 's':
//				printf("Introduzca el nuevo DNI\n");
//				scanf("%s", &respuestaChar);
//				fflush(stdout);
//				socio.DNI = respuestaChar;
//				printf("DNI cambiado con exito\n");
//			case 'n':
//				break;
//			}
//
//
//			printf("Correo: %s", socio.correo);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo correo\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					socio.correo = respuestaChar;
//					printf("Correo cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Residencia: %s", socio.residencia);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca la nueva residencia\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					socio.residencia = respuestaChar;
//					printf("Residencia cambiada con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Codigo postal: %s", socio.codigoPostal);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo codigo postal\n");
//					scanf("%s", &respuestaInt);
//					fflush(stdout);
//					socio.codigoPostal = respuestaInt;
//					printf("Codigo postal cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			updateSocio(db, socio.nombre, socio.apellido, socio.DNI, socio.correo, socio.residencia, socio.codigoPostal);
			break;
		case '4':
			printf("�Que socio quiere eliminar?\n");
			printf("(debe introducir el DNI)");
			scanf("%c", &dni);
			fflush(stdout);

			eliminarSocio(db, result, dni);
			break;
		case '5':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void gestionReservas(sqlite3 *db, int result) {
	char str[20];
	char op, id, respuesta, respuestaChar;
	Reserva reserva;
	int respuestaInt;

	do {

		printf("\tGESTION DE RESERVAS\n");
		printf("================================\n\n");
		printf("1. Visualizar reserva\n");
		printf("2. Anadir reserva\n");
		printf("3. Modificar reserva \n");
		printf("4. Eliminar reserva\n");
		printf("5. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirReserva(db);
			break;
		case '2':
			printf("Escriba (en numero) el ID que le quiere asignar.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(reserva.idReserva, str);

			printf("Escriba el concepto de la Reserva.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(reserva.concepto, str);

			printf("Escriba la fecha en el que inicia la reserva (Formato -> xx/xx/xx).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(reserva.fechaInicio, str);

			printf("Escriba la fecha fin de la reserva (Formato -> xx/xx/xx).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(reserva.fechaFinal, str);

			printf("Escriba el nick Usuario del Usuario que hara la reserva.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(reserva.usuario.nomUsuario, str);

			printf("Escriba el ISBN del libro que reservara.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(reserva.libro.isbn, str);

			anadirReserva(db, result, reserva);
			printf("La reserva anadida es la siguiente: \n");
			imprimirReservas(db, reserva);

			printf("Reserva anadida con exito.\n");
			break;
		case '3':
//			imprimirReserva(db);
//			printf("�Que reserva quiere modificar?\n");
//			printf("(DEBE SELECCIONAR EL ID DE LA RESERVA A MODIFICAR\n");
//			scanf("%c", &id);
//			fflush(stdout);
//			reserva = getReserva(db, id);
//			printf("Datos de la reserva:\n");
//			printf("Si quiere modificarlos escriba: s, en caso contrario: n.\n");
//
//			printf("Concepto: %s", reserva.concepto);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo concepto\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					reserva.concepto = respuestaChar;
//					printf("Concepto cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Fecha inicio: %s", reserva.fechaInicio);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca la nueva fecha de inicio\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					reserva.fechaInicio = respuestaChar;
//					printf("Fecha inicio cambiada con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Fecha final: %s", reserva.fechaFinal);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca la nueva fecha final\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					reserva.fechaFinal = respuestaChar;
//					printf("Fecha final cambiada con exito\n");
//				case 'n':
//					break;
//			}
//
//			// FALTAN USUARIO Y LIBRO
//
//			updateReserva(db, reserva.idReserva, reserva.concepto, reserva.fechaInicio, reserva.fechaFinal, reserva.usuario.nomUsuario, reserva.libro.isbn);
			break;
		case '4':
			printf("�Que reserva quiere eliminar?\n");
			printf("(debe introducir el ID de la reserva)");
			scanf("%c", &id);
			fflush(stdout);

			eliminarReserva(db, result, id);
			break;
		case '5':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void gestionLibros(sqlite3 *db, int result) {
	char str[20];
	char op, id, respuesta, respuestaChar;
	Libro libro;
	int respuestaInt;

	do {

		printf("\tGESTION DE LIBROS\n");
		printf("================================\n\n");
		printf("1. Visualizar libro\n");
		printf("2. Anadir libro\n");
		printf("3. Modificar libro \n");
		printf("4. Eliminar libro\n");
		printf("5. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirLibros(db);
			break;

		case '2':
			printf("Escriba (en numero) el ID que le quiere asignar.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(libro.idLibro, str);

			printf("Escriba el ISBN del libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(libro.isbn, str);

			printf("Escriba el titulo del libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(libro.titulo, str);

			printf("Escriba el autor del libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(libro.autor, str);

			printf("Escriba el genero al cual pertenece el libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(libro.genero, str);

			printf("Escriba las paginas que tiene el libro.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(libro.paginas, str);

			anadirLibro(db, result, libro);
			printf("El libro anadido es el siguiente: \n");
			imprimirLibro(db, libro);

			printf("Libro anadido con exito.\n");
			break;
		case '3':
//			imprimirLibros(db);
//			printf("�Que libro quiere modificar?\n");
//			printf("(DEBE SELECCIONAR EL ISBN DEL LIBRO A MODIFICAR\n");
//			scanf("%c", &id);
//			fflush(stdout);
//			libro = getLibro(db, id);
//			printf("Datos del libro:\n");
//			printf("Si quiere modificarlos escriba: s, en caso contrario: n.\n");
//
//			printf("ISBN: %s", libro.isbn);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo ISBN\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					libro.isbn = respuestaChar;
//					printf("ISBN cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Titulo: %s", libro.titulo);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo titulo\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					libro.titulo = respuestaChar;
//					printf("Titulo cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Autor: %s", libro.autor);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo autor\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					libro.autor = respuestaChar;
//					printf("Autor cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Genero: %s", libro.genero);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo genero\n");
//					scanf("%s", &respuestaChar);
//					fflush(stdout);
//					libro.genero = respuestaChar;
//					printf("Genero cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			printf("Paginas: %s", libro.paginas);
//			scanf("%c", &respuesta);
//			fflush(stdout);
//
//			switch(respuesta){
//				case 's':
//					printf("Introduzca el nuevo numero de paginas\n");
//					scanf("%s", &respuestaInt);
//					fflush(stdout);
//					libro.paginas = respuestaInt;
//					printf("Numero de paginas cambiado con exito\n");
//				case 'n':
//					break;
//			}
//
//			modificarLibro(db, result, id, libro.idLibro, libro.isbn, libro.titulo, libro.autor, libro.genero, libro.paginas);
			break;
		case '4':
			printf("�Que libro quiere eliminar?\n");
			printf("(debe introducir el ISBN)");
			scanf("%c", &id);
			fflush(stdout);

			eliminarLibro(db, result, id);
			break;
		case '5':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void borrarDatos(sqlite3 *db, int result) {
	char op;

	do {

		printf("\tBORRAR DATOS\n");
		printf("================================\n\n");
		printf("1. Borrar todas las bibliotecas.\n");
		printf("2. Borrar todas los usuarios\n");
		printf("3. Borrar todas los socios \n");
		printf("4. Borrar todas las reservas\n");
		printf("5. Borrar todas los libros\n");
		printf("6. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '6');

		switch (op) {
		case '1':
			eliminarTodasBibliotecas(db, result);
			break;
		case '2':
			eliminarTodosUsuarios(db, result);
			break;
		case '3':
			eliminarTodosSocios(db, result);
			break;
		case '4':
			eliminarTodasReservas(db, result);
			break;
		case '5':
			eliminarTodosLibros(db, result);
			break;
		case '6':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '6');
}


