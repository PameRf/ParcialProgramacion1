/*
 * Censistas.h
 *
 *  Created on: 16 may. 2022
 *      Author: pamel
 */

#ifndef CENSISTAS_H_
#define CENSISTAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

typedef struct{
	int dia;
	int mes;
	int anio;
}FechaNacimiento;

typedef struct{
	char calle[50];
	int numero;
}Direccion;

typedef struct{
	int id;
	char nombre[50];
	char apellido[50];
	int edad;
	FechaNacimiento fecha;
	Direccion domicilio;
	int isEmpty;
}Censistas;

int inicializarCencista(Censistas* list, int len);
int generarId();
int buscarEspacioLibre(Censistas* list, int len);
Censistas cargarUnCensista(int* retorno);
void mostrarUnCensista(Censistas unCensista);
int addCensitas(Censistas* list, int len, int id, char nombre[],char apellido[], int edad,int fechaDia, int fechaMes, int fechaAnio, char domicilio[], int domicilioNumero);
int modificarCensista(Censistas* list, int len, int id);

#endif /* CENSISTAS_H_ */
