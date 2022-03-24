#ifndef SOCIO_H_
#define SOCIO_H_

typedef struct{
	char nombre[20];
	char apellido[20];
	int DNI[9];
	char correo[20];
	char residencia[30];
	int codigoPostal[5];
}Socio;

//INICIO SESION//
void imprimirSocio (Socio* socios, int tamanyo);
int comprobarSocio (char nom [20], int dni[9],  int cp [10], Socio* socios, int tamanyo);

//REGISTRARSE//
void registrarSocio (Socio* socios, int posicion);

#endif /* SOCIO_H_ */
