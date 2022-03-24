#include <stdio.h>
#include <string.h>

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

