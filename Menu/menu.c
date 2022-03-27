#include <stdio.h>
#include <string.h>
#include "../Jerarquia/Usuario/usuario.h"

int gestionBibliotecasBilbao(void)
{
	char str[5];
	int op;

	printf("\t================================\n");
	printf("\tGESTION DE BIBLIOTECAS DE BILBAO\n");
	printf("\t================================\n\n");
	printf("Bienvenido al programa de gestion de bibliotecas en Bilbao.\n\n");
	printf("1. Iniciar sesion\n");
	printf("2. Registrarse\n");
	printf("3. Salir\n");

	fflush(stdout);
	fgets(str, 5, stdin);
	sscanf(str, "%i", &op);

	return op;
}

int menuPrincipal(void)
{
	char str[5];
	int op;

	printf("\t\nMENU PRINCIPAL\n");
	printf("================================\n\n");
	printf("1. Gestionar bibliotecas\n");
	printf("2. Importar datos desde fichero\n");
	printf("3. Borrar base de datos\n");
	printf("4. Salir\n");

	fflush(stdout);
	fgets(str, 4, stdin);
	sscanf(str, "%i", &op);

	return op;
}

int gestionBibliotecas(void)
{
	char str[10];
	int op;

	printf("\tGESTION DE BIBLIOTECAS\n");
	printf("================================\n\n");
	printf("1. Visualizar bibliotecas\n");
	printf("2. Visualizar usuarios\n");
	printf("3. Visualizar socios\n");
	printf("4. Anyadir bibliotecas\n");
	printf("5. Modificar bibliotecas\n");
	printf("6. Eliminar bibliotecas\n");
	printf("7. Salir\n");

	fflush(stdout);
	fgets(str, 10, stdin);
	sscanf(str, "%i", &op);

	return op;
}

struct Usuario *inicioSesion(Usuario* usuario)
{
	char user[15];
	char contrasenya[15];

	printf("\tINICIO DE SESIÓN\n");
	printf("\t================================\n\n");
	printf("Introduzca los siguientes campos\n\n");
	printf("Usuario:\n");
	fflush(stdout);
	fflush(stdin);
	fgets(user, 15, stdin);
	printf("Contrasenya:\n");
	fflush(stdout);
	fflush(stdin);
	fgets(contrasenya, 15, stdin);

	if(user == usuario.nomUsuario && contrasenya == usuario.contrasenya)
		return usuario;
	else
		return null;
}

struct Usuario *registroUsuario(void)
{
	char nombre[15];
	char apellido[15];
	char usuario[15];
	char contrasenya[15];

	printf("\tREGISTRO DE USUARIO\n");
	printf("\t================================\n\n");
	printf("Introduzca los siguientes campos\n\n");
	printf("Nombre:\n");
	fflush(stdout);
	fflush(stdin);
	fgets(nombre, 15, stdin);
	printf("Apellido:\n");
	fflush(stdout);
	fflush(stdin);
	fgets(apellido, 15, stdin);
	printf("Usuario:\n");
	fflush(stdout);
	fflush(stdin);
	fgets(usuario, 15, stdin);
	printf("Contrasenya:\n");
	fflush(stdout);
	fflush(stdin);
	fgets(contrasenya, 15, stdin);

	struct Usuario user = {nombre, apellido, usuario, contrasenya};

	return user;
}