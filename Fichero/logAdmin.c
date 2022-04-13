/*
 * logAdmin.c
 *
 *  Created on: 13 abr 2022
 *      Author: Unai
 */
#include <stdio.h>

#include "logAdmin.h"
#include "../Jerarquia/Usuario/usuario.h"

void adminTxt(Usuario u){
	FILE *f;

		f=fopen("Fichero/admin.txt","a");
		if(f!=NULL){
			fprintf(f,"Usuario: %s\t Contrasenya: %s\n",u.nomUsuario,u.contrasenya);
			fclose(f);
		}
}
