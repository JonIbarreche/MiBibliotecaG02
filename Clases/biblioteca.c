#include "biblioteca.h"

#include <stdio.h>
#include <stdlib.h>

void visualizarBiblioteca (Biblioteca* bibliotecas, int tamanyo){

	for (int i = 0; i < tamanyo ; i++){
		printf("ID: %s", (bibliotecas+ i)->idBiblioteca);
		printf("Nombre: %s", (bibliotecas+ i)->nombre);
		printf("Aforo: %s", (bibliotecas+ i)->aforo);
		printf("Estado: %s", (bibliotecas+ i)->estado);
		printf("Genero: %s", (bibliotecas+ i)->genero);
		printf("Instalacion: %s", (bibliotecas+ i)->instalacion);
		printf("Barrio: %s", (bibliotecas+ i)->barrio);
	}
}


