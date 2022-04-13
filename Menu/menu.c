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

void menuModificarBiblioteca(sqlite3 *db, int result) {
	char op, str[10];
	Biblioteca b;

	imprimirBiblioteca(db);
	printf("Que biblioteca quiere modificar:");
	scanf("%s", &str);
	fflush(stdout);

	b = getBiblioteca(db, str);
	eliminarBibliotecas(db, result, str);

	do {
		printf("\nMODIFICAR BIBLIOTECA\n");
		printf("================================\n\n");
		printf("1. Modificar nombre\n");
		printf("2. Modificar aforo\n");
		printf("3. Modificar horario \n");
		printf("4. Modificar genero\n");
		printf("5. Modificar instalacion\n");
		printf("6. Modificar barrio\n");
		printf("7. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '7');

		switch (op) {
		case '1':
			printf("Escriba el nuevo nombre de la biblioteca.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(b.nombre, str);
			anadirBiblioteca(db, result, b);

			gestionBibliotecas(db, result);
			break;

		case '2':
			printf("Escriba el nuevo aforo maximo de la biblioteca.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(b.aforo, str);
			anadirBiblioteca(db, result, b);

			gestionBibliotecas(db, result);
			break;
		case '3':
			printf(
					"Escriba el nuevo horario de la biblioteca (FORMATO XX:XX - XX:XX).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(b.estado, str);
			anadirBiblioteca(db, result, b);

			gestionBibliotecas(db, result);
			break;
		case '4':
			printf("Escriba el nuevo genero que tiene la biblioteca.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(b.genero, str);
			anadirBiblioteca(db, result, b);

			gestionBibliotecas(db, result);
			break;
		case '5':
			printf("Escriba la nueva instalacion que tiene la biblioteca.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(b.instalacion, str);
			anadirBiblioteca(db, result, b);

			gestionBibliotecas(db, result);
			break;
		case '6':
			printf(
					"Escriba el nuevo nombre del barrio en el que se encuentra la biblioteca.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(b.barrio, str);
			anadirBiblioteca(db, result, b);

			gestionBibliotecas(db, result);
			break;
		case '7':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '7');
}

void menuModificarUsuario(sqlite3 *db, int result) {
	char op, str[10];
	Usuario u;

	imprimirUsuarios(db);
	printf("Que usuario quiere modificar:");
	scanf("%s", &str);
	fflush(stdout);

	u = getUsuario(db, str);
	eliminarUsuario(db, result, str);

	do {
		printf("\nMODIFICAR USUARIO\n");
		printf("================================\n\n");
		printf("1. Modificar nombre\n");
		printf("2. Modificar apellido\n");
		printf("3. Modificar nick \n");
		printf("4. Modificar contrasenya\n");
		printf("5. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			printf("Escriba el nuevo nombre del usuario.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(u.nombre, str);
			anadirUsuario(db, result, u);

			gestionUsuarios(db, result);
			break;

		case '2':
			printf("Escriba el nuevo apellido del usuario.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(u.apellido, str);
			anadirUsuario(db, result, u);

			gestionUsuarios(db, result);
			break;
		case '3':
			printf("Escriba el nuevo nick del usuario.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(u.nomUsuario, str);
			anadirUsuario(db, result, u);

			gestionUsuarios(db, result);
			break;
		case '4':
			printf("Escriba la nueva contrasenya del usuario.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(u.contrasenya, str);
			anadirUsuario(db, result, u);

			gestionUsuarios(db, result);
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

void menuModificarSocio(sqlite3 *db, int result) {
	char op, str[10];
	Socio s;

	imprimirSocios(db);
	printf("Que socio quiere modificar:");
	scanf("%s", &str);
	fflush(stdout);

	s = getSocio(db, str);
	eliminarSocio(db, result, str);

	do {
		printf("\nMODIFICAR SOCIO\n");
		printf("================================\n\n");
		printf("1. Modificar nombre\n");
		printf("2. Modificar apellido\n");
		printf("3. Modificar DNI \n");
		printf("4. Modificar correo\n");
		printf("5. Modificar residencia\n");
		printf("6. Modificar codigo Postal\n");
		printf("7. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '7');

		switch (op) {
		case '1':
			printf("Escriba el nuevo nombre del socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(s.nombre, str);
			anadirSocio(db, result, s);

			gestionSocios(db, result);
			break;

		case '2':
			printf("Escriba el nuevo apellido del socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(s.apellido, str);
			anadirSocio(db, result, s);

			gestionSocios(db, result);
			break;
		case '3':
			printf("Escriba el nuevo DNI del socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(s.DNI, str);
			anadirSocio(db, result, s);

			gestionSocios(db, result);
			break;
		case '4':
			printf("Escriba el nuevo correo del socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(s.correo, str);
			anadirSocio(db, result, s);

			gestionSocios(db, result);
			break;
		case '5':
			printf("Escriba la nueva residencia del socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(s.residencia, str);
			anadirSocio(db, result, s);

			gestionSocios(db, result);
			break;
		case '6':
			printf("Escriba el nuevo codigo Postal del socio.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(s.codigoPostal, str);
			anadirSocio(db, result, s);

			gestionSocios(db, result);
			break;
		case '7':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '7');
}

void menuModificarReserva(sqlite3 *db, int result) {
	char op, str[10];
	Reserva r;

	imprimirReserva(db);
	printf("Que reserva quiere modificar:");
	scanf("%s", &str);
	fflush(stdout);

	r = getReserva(db, str);
	eliminarReserva(db, result, str);

	do {
		printf("\nMODIFICAR RESERVA\n");
		printf("================================\n\n");
		printf("1. Modificar concepto\n");
		printf("2. Modificar fecha inicio\n");
		printf("3. Modificar fecha fin \n");
		printf("4. Modificar usuario\n");
		printf("5. Modificar libro\n");
		printf("6. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '7');

		switch (op) {
		case '1':
			printf("Escriba el nuevo concepto de la reserva.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(r.concepto, str);
			anadirReserva(db, result, r);

			gestionReservas(db, result);
			break;

		case '2':
			printf(
					"Escriba la nueva fecha de inicio de la reserva (FORMATO XX/XX/XX).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(r.fechaInicio, str);
			anadirReserva(db, result, r);

			gestionReservas(db, result);
			break;
		case '3':
			printf(
					"Escriba la nueva fecha fin de la reserva (FORMATO XX/XX/XX).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(r.fechaFinal, str);
			anadirReserva(db, result, r);

			gestionReservas(db, result);
			break;
		case '4':
			printf(
					"Escriba el nuevo nick del usuario que ha hecho la reserva.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(r.usuario.nomUsuario, str);
			anadirReserva(db, result, r);

			gestionReservas(db, result);
			break;
		case '5':
			printf("Escriba el nuevo isbn del libro que se ha reservado.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(r.libro.isbn, str);
			anadirReserva(db, result, r);

			gestionReservas(db, result);
			break;
		case '7':
			//Volver
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '7');
}

void menuModificarLibro(sqlite3 *db, int result) {
	char op, str[10];
	Libro l;

	imprimirLibros(db);
	printf("Que libro quiere modificar:");
	scanf("%s", &str);
	fflush(stdout);

	l = getLibro(db, str);
	eliminarLibro(db, result, str);

	do {
		printf("\nMODIFICAR LIBRO\n");
		printf("================================\n\n");
		printf("1. Modificar ISBN\n");
		printf("2. Modificar titulo\n");
		printf("3. Modificar autor \n");
		printf("4. Modificar genero\n");
		printf("5. Modificar paginas\n");
		printf("6. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '6');

		switch (op) {
		case '1':
			printf("Escriba el nuevo isbn del libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(l.isbn, str);
			anadirLibro(db, result, l);

			gestionLibros(db, result);
			break;

		case '2':
			printf("Escriba el nuevo titulo del libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(l.titulo, str);
			anadirLibro(db, result, l);

			gestionLibros(db, result);
			break;
		case '3':
			printf("Escriba el nuevo autor del libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(l.genero, str);
			anadirLibro(db, result, l);

			gestionLibros(db, result);
			break;
		case '4':
			printf("Escriba la nueva genero del libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(l.genero, str);
			anadirLibro(db, result, l);

			gestionLibros(db, result);
			break;
		case '5':
			printf("Escriba el nuevo numero de paginas que tiene el libro.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(l.paginas, str);
			anadirLibro(db, result, l);

			menuPrincipal(db, result);
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

//--------------------------------------------------------------------------------------------------------------------------------------------

int inicioAdmin() {
	char usuario[LONGITUD + 1];
	char clave[LONGITUD + 1];
	int intento = 0;
	int ingresa = 0;
	char caracter;
	int i = 0;
	int j = 0;

	/* Declaraciï¿½n e inicializaciï¿½n de arreglos de usuarios y claves */
	char usuarios[NUMERO_USUARIOS][LONGITUD + 1] = { "admin" };
	char claves[NUMERO_USUARIOS][LONGITUD + 1] = { "admin" };

	do {
		i = 0;
		system("cls");
		printf("\n\t\t\tINICIO DE SESION\n");
		printf("\t\t\t---------------\n");
		printf("\n\tUSUARIO: ");
		gets(usuario);
		printf("\tCLAVE: ");
		while (caracter = getch()) {
			if (caracter == TECLA_ENTER) {
				clave[i] = '\0';
				break;
			} else if (caracter == TECLA_BACKSPACE) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}
			} else {
				if (i < LONGITUD) {
					printf("*");
					clave[i] = caracter;
					i++;
				}
			}
		}
		/* El usuario y clave debe coincidir con alguno de los que se encuentran en el array */
		for (j = 0; j < NUMERO_USUARIOS; ++j) {
			if (strcmp(usuario, usuarios[j]) == 0
					&& strcmp(clave, claves[j]) == 0) {
				ingresa = 1;
				break;
			}
		}
		if (ingresa == 0) {
			printf("\n\tUsuario y/o clave son incorrectos\n");
			intento++;
			getchar();
		}
	} while (intento < MAX_INTENTOS && ingresa == 0);
	if (ingresa == 1) {
		printf("\n\n\tBienvenido al Sistema\n\n");
		menuPrincipal();
	} else {
		printf(
				"\n\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
	}
	return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void menuPrincipal(sqlite3 *db, int result) {
	char op;

	do {
		printf("\n\tMENU PRINCIPAL\n");
		printf("================================\n\n");
		printf("1. Gestionar bibliotecas\n");
		printf("2. Gestionar usuarios\n");
		printf("3. Gestionar socios\n");
		printf("4. Gestionar reservas\n");
		printf("5. Gestionar libros\n");
		printf("6. Borrar base de datos\n");
		printf("7. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdout);
		} while (op < '1' || op > '7');

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
			borrarDatos(db, result);
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '7');
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void gestionBibliotecas(sqlite3 *db, int result) {
	char str[50];
	char op, id;
	Biblioteca biblioteca;

	do {
		system("cls");
		printf("\n\tGESTION DE BIBLIOTECA\n");
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
			printf("Escriba el nombre de la Biblioteca.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(biblioteca.nombre, str);

			printf("Escriba (en numero) el numero MAXIMO de aforo.\n");
			scanf("%i", &str);
			fflush(stdout);
			strcpy(biblioteca.aforo, str);

			printf(
					"Escriba de cuando a cuando esta abierta (FORMATO XX:XX - XX:XX).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(biblioteca.estado, str);

			printf("Escriba el genero que mas resalta en esta Biblioteca.\n");
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
			menuModificarBiblioteca(db, result);
			break;

		case '4':
			printf("¿Que biblioteca quiere eliminar?\n");
			printf("(debe introducir el ID de la biblioteca)");
			scanf("%c", &id);
			fflush(stdout);

			eliminarBibliotecas(db, result, id);
			break;
		case '5':
			system("cls");
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void gestionUsuarios(sqlite3 *db, int result) {
	char str[20];
	char op, id;
	Usuario usuario;

	do {
		system("cls");
		printf("\n\tGESTION DE USUARIOS\n");
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
			menuModificarUsuario(db, result);
			break;
		case '4':
			printf("¿Que usuario quiere eliminar?\n");
			printf("(debe introducir el nick del usuario)");
			scanf("%c", &id);
			fflush(stdout);

			eliminarUsuario(db, result, id);
			break;
		case '5':
			system("cls");
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void gestionSocios(sqlite3 *db, int result) {
	char str[20];
	char op, dni;
	Socio socio;

	do {
		system("cls");
		printf("\n\tGESTION DE SOCIOS\n");
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
			scanf("%s", &str);
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
			scanf("%s", &str);
			fflush(stdout);
			strcpy(socio.codigoPostal, str);

			anadirSocio(db, result, socio);
			printf("El socio anadido es el siguiente: \n");
			imprimirSocio(db, socio);

			printf("Socio anadido con exito.\n");
			break;
		case '3':
			menuModificarSocio(db, result);
			break;
		case '4':
			printf("¿Que socio quiere eliminar?\n");
			printf("(debe introducir el DNI)");
			scanf("%c", &dni);
			fflush(stdout);

			eliminarSocio(db, result, dni);
			break;
		case '5':
			system("cls");
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void gestionReservas(sqlite3 *db, int result) {
	char str[20];
	char op, id;
	Reserva reserva;

	do {
		system("cls");
		printf("\n\tGESTION DE RESERVAS\n");
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
			printf("Escriba el concepto de la Reserva.\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(reserva.concepto, str);

			printf(
					"Escriba la fecha en el que inicia la reserva (FORMATO XX/XX/XX).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(reserva.fechaInicio, str);

			printf("Escriba la fecha fin de la reserva (FORMATO XX/XX/XX).\n");
			scanf("%s", &str);
			fflush(stdout);
			strcpy(reserva.fechaFinal, str);

			printf(
					"Escriba el nick Usuario del Usuario que hara la reserva.\n");
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
			menuModificarReserva(db, result);
			break;
		case '4':
			printf("¿Que reserva quiere eliminar?\n");
			printf("(debe introducir el ID de la reserva)");
			scanf("%c", &id);
			fflush(stdout);

			eliminarReserva(db, result, id);
			break;
		case '5':
			system("cls");
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '5');
}

void gestionLibros(sqlite3 *db, int result) {
	char str[20];
	char op, id;
	Libro libro;

	do {
		system("cls");
		printf("\n\tGESTION DE LIBROS\n");
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
			menuModificarLibro(db, result);
			break;
		case '4':
			printf("¿Que libro quiere eliminar?\n");
			printf("(debe introducir el ISBN)");
			scanf("%c", &id);
			fflush(stdout);

			eliminarLibro(db, result, id);
			break;
		case '5':
			system("cls");
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
		system("cls");
		printf("\n\tBORRAR DATOS\n");
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
			system("cls");
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '6');
}

