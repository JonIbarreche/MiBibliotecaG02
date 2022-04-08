#include "reserva.h"

#include <stdio.h>
#include <stdlib.h>

void visualizarReservas(Reserva* reservas, int tamanyo){
	for (int i = 0; i < tamanyo ; i++){
        printf("================================");
        printf("----------- Reserva %i -----------", i);
		printf("Concepto: %s", (reservas+ i)->concepto);
		// printf("Fecha: %s", (reservas+ i)->fecha);
		// printf("Usuario: %s", (reservas+ i)->usuario);
		// printf("Libro: %s", (reservas+ i)->libro);
	}

}

void visualizarReserva2(Reserva* reserva){
    printf("------------------------");
    printf("Concepto: %s", reserva->concepto);
    // printf("Fecha: %s", reserva->fecha);
    // printf("Usuario: %s", reserva->usuario);
    // printf("Libro: %s", reserva->libro);
}
