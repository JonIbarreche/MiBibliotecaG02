/*
 * logProyecto.c
 *
 *  Created on: 13 abr 2022
 *      Author: Unai
 */

#include "logProyecto.h"

void proyectoLog(char* msj) {
	fprintf(stderr, "%s\n", msj);
}
void proyectoWarning(char* msj) {
	char ch[300];
	sprintf(ch, "//!\\ %s //!\\", msj);
	proyectoLog(ch);
}
void proyectoError(char* msj) {
	char ch[300];
	sprintf(ch, "//!\\ %s //!\\", msj);
	proyectoLog(ch);

}

