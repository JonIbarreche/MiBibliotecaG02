#ifndef RESERVA_H_
#define RESERVA_H_

typedef struct{
	char fechaInicio[8];
    char fechaFinal[8];
}Fecha;

typedef struct{
	char concepto[100];
    // Fecha fecha;
    // Usuario usuario;
    // Libro libro;
}Reserva;

void visualizarReservas(Reserva* reservas, int tamanyo);
void visualizarReserva(Reserva* reserva);

#endif