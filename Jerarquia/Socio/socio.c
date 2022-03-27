#include "socio.h"

#include <stdio.h>
#include <stdlib.h>


void visualizarSocio (Socio* socios, int tamanyo){

	for (int i = 0; i < tamanyo ; i++){
		printf("Nombre: %s", (socios+ i)->nombre);
		printf("Apellido: %s", (socios+ i)->apellido);
		printf("DNI: %i", (socios+ i)->DNI);
		printf("Correo: %s", (socios+ i)->correo);
		printf("Residencia: %s", (socios+ i)->residencia);
		printf("Codigo Postal: %i", (socios+ i)->codigoPostal);
	}
}

int comprobarSocio (char nom[20], int dni [9], int cp [10], Socio* socios, int tamanyo){


	int cont = 0;
	for (int i = 0; i < tamanyo; i++){

		if((strncmp((socios+ i)->nombre, nom)) == 0){
			if ((strcmp((socios + i)->DNI, dni)) == 0){
				if((strcmp((socios + i)->codigoPostal, cp)) == 0){
				cont = 1;
				}
			}
		}
	}

	return cont;

}

void registrarSocio (Socio* socios, int posicion){

	char str[10];
	char nombre[10];
	char apellido[20];
	int dni[9];
	char correo[20];
	char residencia[30];
	int codigoPostal[5];
	int flag = 0;

	char salir;

	Socio socio;

	while (flag == 0){

		printf("\nREGISTRO DE NUEVO SOCIO\n");
		printf("============================\n");


		printf("NOMBRE:  ");
		fflush(stdout);
		fgets(str, 10, stdin);
		sscanf(str, "%s", &nombre);
		strcpy(socio.nombre, nombre);

		printf("APELLIDO:  ");
		fflush(stdout);
		fgets(str, 40, stdin);
		sscanf(str, "%s", &apellido);
		strcpy(socio.apellido, apellido);

		printf("DNI:  ");
		fflush(stdout);
		fgets(str, 40, stdin);
		sscanf(str, "%i", &dni);
		strcpy(socio.DNI, dni);

		printf("CORREO:  ");
		fflush(stdout);
		fgets(str, 10, stdin);
		sscanf(str, "%s", &correo);
		strcpy(socio.correo, correo);

		printf("RESIDENCIA:  ");
		fflush(stdout);
		fgets(str, 10, stdin);
		sscanf(str, "%s", &correo);
		strcpy(socio.correo, correo);

		printf("CODIGO POSTAL:  ");
		fflush(stdout);
		fgets(str, 10, stdin);
		sscanf(str, "%i", &codigoPostal);
		strcpy(socio.codigoPostal, codigoPostal);

		do {
			printf("Los datos que ha introducido son los siguientes: \n");
			printf("Nombre: %s\n, Apellido: %s\n, DNI: %i\n, Correo: %s\n, Residencia: %s\n, Codigo Postal: %i\n", nombre, apellido, dni, correo, residencia, codigoPostal);
			printf("¿Desea seguir adelante? (s/n)");
			fflush(stdin);
			scanf("%c", &salir);
		} while ((salir < 's') || (salir > 'S'));
	}
}
