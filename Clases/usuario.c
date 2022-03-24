#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>


void imprimirUsuario (Usuario* usuarios, int tamanyo){

	for (int i = 0; i < tamanyo ; i++){
		printf("Nombre: %s", (usuarios+ i)->nombre);
		printf("Apellido: %s", (usuarios+ i)->apellido);
		printf("Usuario: %s", (usuarios+ i)->nomUsuario);
		printf("Contrasenya: %s", (usuarios+ i)->contrasenya);
	}
}

int comprobarUsuario (char usu [10], char contr [10], Usuario* usuarios, int tamanyo){

	int cont = 0;
	for (int i = 0; i < tamanyo; i++){

		if((strncmp((usuarios+ i)->nomUsuario, usu)) == 0){
			if ((strcmp((usuarios + i)->contrasenya, contr)) == 0){
				cont = 1;
			}
		}
	}
	return cont;
}

int inicioSesion(Usuario* usuarios) {

	int cont = 0;

	char str[10];
	char nom[10];
	char contr[10];

	printf("\n\tINICIO DE SESION\n");
	printf("==================================================\n");

	printf("Usuario:  ");
	fflush(stdout);
	fgets(str, 10, stdin);
	sscanf(str, "%s", &nom);

	printf("Contrasenya:  ");
	fflush(stdout);
	fgets(str, 10, stdin);
	sscanf(str, "%s", &contr);

	cont = comprobarUsuario(nom, contr, usuarios, 100);

	return cont;
}

void registrarUsuario (Usuario* usuarios, int posicion){

	char str[10];
	char nombre[10];
	char apellido[20];
	char nomUsuario[20];
	char contrasenya[10];
	char contrasenyaComp[10];
	int flag = 0;

	Usuario usuario;

	while (flag == 0){

		printf("\nREGISTRO DE NUEVO USUARIO\n");
		printf("============================\n");

		printf("NOMBRE:  ");
		fflush(stdout);
		fgets(str, 10, stdin);
		sscanf(str, "%s", &nombre);
		strcpy(usuario.nombre, nombre);

		printf("APELLIDO:  ");
		fflush(stdout);
		fgets(str, 40, stdin);
		sscanf(str, "%s", &apellido);
		strcpy(usuario.apellido, apellido);

		printf("USUARIO:  ");
		fflush(stdout);
		fgets(str, 40, stdin);
		sscanf(str, "%s", &nomUsuario);
		strcpy(usuario.nomUsuario, nomUsuario);

		printf("CONTRASEÑA:  ");
		fflush(stdout);
		fgets(str, 10, stdin);
		sscanf(str, "%s", &contrasenya);

		printf("CONFIRMACION CONTRASEÑA:  ");
		fflush(stdout);
		fgets(str, 10, stdin);
		sscanf(str, "%s", &contrasenyaComp);

		if (strncmp(contrasenya, contrasenyaComp) == 0){
			strcpy(usuario.contrasenya, contrasenya);
			flag = 1;
			*(usuarios + posicion) = usuario;
			printf("=========================================================================\n");
			printf("--------------------CUENTA CREADA CORRECTAMENTE--------------------------\n\n");
			fflush(stdout);

		}else{
			printf("\nLas contraseñas no coinciden, porfavor intentelo de nuevo\n\n");
			fflush(stdout);
		}
	}
}



