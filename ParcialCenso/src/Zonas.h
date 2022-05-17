/*
 * Zonas.h
 *
 *  Created on: 17 may. 2022
 *      Author: pamel
 */

#ifndef ZONAS_H_
#define ZONAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Censistas.h"
#define LANUS 1
#define LOMAS_DE_ZAMORA 2
#define AVELLANEDA 3
#define BANDFIELD 4

#define PENDIENTE 5
#define FINALIZADO 6

typedef struct {
	char calleUno[50];
    char calleDos[50];
    char calleTres[50];
    char calleCuatro[50];
}Cuadras;

typedef struct {
    int idZona;
    int estado;
	int idCensista; // FK
 	int localidad[4];
 	Cuadras cuadra;
	int isEmpty;
}Zonas;

int inicializarZona(Zonas* list, int len);
int generarIdZonas();
int buscarEspacioLibreZonas(Zonas* list, int len);
Zonas cargarUnaZona(int* retorno);
void mostrarUnaZona(Zonas unaZona);

#endif /* ZONAS_H_ */