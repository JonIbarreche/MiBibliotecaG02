#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Jerarquia/Usuario/usuario.h"
#include "../Jerarquia/Biblioteca/biblioteca.h"
#include "../Jerarquia/Socio/socio.h"
#include "../Jerarquia/Reserva/reserva.h"
#include "../Jerarquia/Libro/libro.h"

/*
int inicioAdmin(int argc, const char **argv)
{
	char nombre[10];
	char p[10];
	char usuario[10] = "admin";
	char pass[10] = "admin";
	int n;

	if( strcmp(usuario , argv[1]) == 0)
	{
		printf("\t Usuario:\t%s\n",argv[1]);
		printf("\t Introduzca la contrasena.\n");
		printf("\t Contrasena:\t");
		scanf("%s",p);
		for(n = 0; n < 5; ++n)
		{
			if( strcmp( pass , p) == 0 )
			{
				printf("\n\n");
				printf("\t===============================\n");
				printf("\t ¡Administrador correctamente iniciado! \ n");
				printf("\t===============================\n");
				printf("\n\n");
				break;
			}

			else
			{
				printf("\n\t Vuelva a introducir la contrasena!\n");
				printf("\t Contrasena:\t");
				scanf("%s",p);
				if( strcmp( pass , p) == 0 )
				{
					printf("\n\n");
					printf("\t===============================\n");
					printf("\t ¡Administrador correctamente iniciado! \ n");
					printf("\t===============================\n");
					printf("\n\n");
					break;
				}
			}
		}
	}

	else if( strlen( argv[1] ) < 5)
	{
		printf("\t Usuario:\t%s\n",argv[1]);
	}

	else if( strcmp(usuario , argv[1]) != 0)
	{
		printf("\t Usuario:\t%s\n",argv[1]);
		printf("\t Vuelva a introducir la contrasena!\n");
	}
	return 0;
}

int menuInicio(void)
{
	char op;

	do {
		printf("\t================================\n");
		printf("\tGESTION DE BIBLIOTECAS DE BILBAO\n");
		printf("\t================================\n\n");
		printf("Bienvenido al programa de gestion de bibliotecas en Bilbao.\n\n");
		printf("1. Iniciar sesion\n");
		printf("2. Salir\n");

		do {
			scanf("%c\n", &op);
			fflush(stdin);
		} while (op < '1' || op > '2');

		switch (op) {
		case '1':
			inicioAdmin();
			break;
		default:
			printf("Valor no valido, vuelva a seleccionar una opcion");
			break;
		}
	} while(op != '2');

	return 0;
}
*/

void menuPrincipal(sqlite3 *db, int result)
{
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
			fflush(stdin);
		} while (op < '1' || op > '9');

		switch (op) {
		case '1':
			gestionBibliotecas(db);
			break;
		case '2':
			gestionUsuarios(db);
			break;
		case '3':
			gestionSocios(db);
			break;
		case '4':
			gestionReservas(db);
			break;
		case '5':
			gestionLibros(db);
			break;
		case '6':

			break;
		case '7':
			borrarDatos(db);
			break;
		default:
			printf("Vuelva a saleccionar una opcion");
			break;
		}
	} while (op != '8');
}

void gestionBibliotecas(sqlite3 *db, int result)
{
	char str[50];
	char op, id;
	Biblioteca biblioteca;

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
			fflush(stdin);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirBibliotecas(db, biblioteca);
			break;
		case '2':
			printf("Escriba (en numero) el ID que le quiere asignar.\n");
			scanf("%i", &str);
			fflush(stdin);
			strcpy(biblioteca.idBiblioteca, str);

			printf("Escriba el nombre de la Biblioteca.\n");
			scanf("%s", &str);
			fflush(stdin);
			strcpy(biblioteca.nombre, str);

			printf("Escriba (en numero) el numero MAXIMO de aforo.\n");
			scanf("%i", &str);
			fflush(stdin);
			strcpy(biblioteca.aforo, str);

			printf("Escriba (Formato-> xx:xx-xx:xx) de cuando a cuando esta abierta.\n");
			scanf("%s", &str);
			fflush(stdin);
			strcpy(biblioteca.estado, str);

			printf("Escriba los generos que mas resaltan en esta Biblioteca (Formato -> ../../..).\n");
			scanf("%s", &str);
			fflush(stdin);
			strcpy(biblioteca.genero, str);

			printf("Escriba las instalaciones que tiene.\n");
			scanf("%s", &str);
			fflush(stdin);
			strcpy(biblioteca.instalacion, str);

			printf("Escriba el nombre del barrio en el que se encuentra.\n");
			scanf("%s", &str);
			fflush(stdin);
			strcpy(biblioteca.barrio, str);

			anadirBiblioteca(db, result, biblioteca);
			imprimirBibliotecas(db, biblioteca);

			printf("Biblioteca anadida con exito.\n");
			break;
		case '3':

			break;
		case '4':
			printf("¿Que biblioteca quiere eliminar?\n");
			printf("(debe introducir el ID de la biblioteca)");
			scanf("%c", &id);
			fflush(stdin);

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

void gestionUsuarios(sqlite3 *db, int result)
{
	char str[20];
	char op, id;
	Usuario usuario;

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
			fflush(stdin);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirUsuario(db, usuario);
			break;

		case '2':

			break;
		case '3':

			break;
		case '4':
			printf("¿Que usuario quiere eliminar?\n");
			printf("(debe introducir el nick del usuario)");
			scanf("%c", &id);
			fflush(stdin);

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

void gestionSocios(sqlite3 *db, int result)
{
	char str[20];
	char op, id;
	Socio socio;

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
			fflush(stdin);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirSocio(db, socio);
			break;

		case '2':

			break;
		case '3':

			break;
		case '4':
			printf("¿Que socio quiere eliminar?\n");
			printf("(debe introducir el DNI)");
			scanf("%c", &id);
			fflush(stdin);

			eliminarSocio(db, result, id);
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

void gestionReservas(sqlite3 *db, int result)
{
	char str[20];
	char op, id;
	Reserva reserva;

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
			fflush(stdin);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirReservas(db, reserva);
			break;

		case '2':

			break;
		case '3':

			break;
		case '4':
			printf("¿Que reserva quiere eliminar?\n");
			printf("(debe introducir el ID de la reserva)");
			scanf("%c", &id);
			fflush(stdin);

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

void gestionLibros(sqlite3 *db, int result)
{
	char str[20];
	char op, id;
	Libro libro;

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
			fflush(stdin);
		} while (op < '1' || op > '5');

		switch (op) {
		case '1':
			imprimirLibro(db, libro);
			break;

		case '2':

			break;
		case '3':

			break;
		case '4':
			printf("¿Que libro quiere eliminar?\n");
			printf("(debe introducir el ISBN)");
			scanf("%c", &id);
			fflush(stdin);

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

void borrarDatos(sqlite3 *db, int result)
{
	char str[20];
	char op, id;
	Biblioteca biblioteca;
	Usuario ususario;
	Reserva reserva;
	Socio socio;
	Libro libro;

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
			fflush(stdin);
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


