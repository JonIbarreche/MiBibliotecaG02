#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct{
	char nombre[20];
	char apellido[20];
	char nomUsuario[20];
	char contrasenya[20];
}Usuario;

//INICIO SESION//
void visualizarUsuario (Usuario*usuarios, int tamanyo);
int comprobarUsuario (char name [10], char pass [10], Usuario* usuarios, int tamanyo);
int inicioSesion(Usuario* usuarios);

//REGISTRARSE//
void registrarUsuario (Usuario* usuarios, int posicion);

#endif /* USUARIO_H_ */
