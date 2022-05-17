/*
 ============================================================================
 Name        : ParcialCenso.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Censistas.h"
#define LEN_CENSISTAS 10

int main(void) {
	setbuf(stdout,NULL);

	int opcionMenu;
	int validarMenu;
	int validarRetorno;
	Censistas censitas[LEN_CENSISTAS];
	Censistas unCensista;
	int retornoCensista;
	int idModificar;


	validarRetorno=inicializarCencista(censitas, LEN_CENSISTAS);

	printf("Se pudo inicializar %d\n",validarRetorno);

	do{
	printf("1. Cargar Censista \n");
	printf("2. Modificar Censista \n");
	printf("3. Dar de baja  Censista \n");
	printf("4. Cargar zona a Censar \n");
	printf("5. Asignar zona a Censar\n");
	printf("6. Cargar datos\n");
	printf("7. Mostrar Censista\n");
	printf("8. Mostrar zonas\n");
	printf("9. Salir\n");

	validarMenu= pedirNumero(&opcionMenu, "Ingrese una opcion \n", "Error! Ingrese una opcion valida: \n",1, 9, 2);

	if(validarMenu== 0){
		switch(opcionMenu){
			case 1:
				unCensista=cargarUnCensista(&retornoCensista);
				if(retornoCensista==0){
					addCensitas(censitas, LEN_CENSISTAS, unCensista.id, unCensista.nombre,unCensista.apellido, unCensista.edad, unCensista.fecha.dia, unCensista.fecha.mes ,unCensista.fecha.anio, unCensista.domicilio.calle, unCensista.domicilio.numero);
				}
				break;
			case 2:
				pedirNumero(&idModificar,"Ingrese el id del censista a modificar \n", "Error el id es invalido\n",1001,1200,2);
				modificarCensista(censitas, LEN_CENSISTAS, idModificar);
				break;
			case 3:
				printf("opcion 3 \n");
				break;
			case 4:
				printf("opcion 4 \n");
				break;
			case 5:
				printf("opcion 5 \n");
				break;
			case 6:
				printf("opcion 6 \n");
				break;
			case 7:
				printf("opcion 7 \n");
				break;
			case 8:
				printf("opcion 8 \n");
				break;
			case 9:
				printf("Gracias \n");
				break;


		}
	}

	}while(opcionMenu != 9);

	return EXIT_SUCCESS;
}
