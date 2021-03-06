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
#include "Zonas.h"
#include "Informes.h"
#define LEN_CENSISTAS 10
#define LEN_ZONAS 50

int main(void) {
	setbuf(stdout,NULL);

	int opcionMenu;
	int validarMenu;
	int validarRetorno;
	int validarRetornoZonas;
	Censistas censistas[LEN_CENSISTAS];
	Censistas unCensista;
	Zonas zonas[LEN_ZONAS];
	Zonas unaZona;
	int retornoCensista;
	int retornoZona;
	int idModificar;
	int flagMenu;
	flagMenu=0;




	validarRetorno= inicializarCencista(censistas, LEN_CENSISTAS);
	validarRetornoZonas= inicializarZona(zonas,LEN_ZONAS);
	printf("Se pudo inicializar censistas %d\n",validarRetorno);
	printf("Se pudo inicializar zonas %d\n",validarRetornoZonas);

	do{
	printf("1. Cargar Censista \n");
	printf("2. Modificar Censista \n");
	printf("3. Dar de baja  Censista \n");
	printf("4. Cargar zona a Censar \n");
	printf("5. Asignar zona a Censar\n");
	printf("6. Cargar datos\n");
	printf("7. Mostrar Censista\n");
	printf("8. Mostrar zonas\n");
	printf("9. Carga forzada Censistas\n");
	printf("10. Carga forzada Zonas\n");
	printf("11. Informar censistas activos con zonas pendientes\n");
	printf("12. Informar censistas alfabeticamente\n");
	printf("13. Salir\n");

	validarMenu= pedirNumero(&opcionMenu, "Ingrese una opcion \n", "Error! Ingrese una opcion valida: \n",1, 13, 2);

	if(validarMenu== 0){
		switch(opcionMenu){
			case 1:
				unCensista=cargarUnCensista(&retornoCensista);
				if(retornoCensista==0){
					addCensitas(censistas, LEN_CENSISTAS, unCensista.idCensista, unCensista.nombre,unCensista.apellido, unCensista.edad, unCensista.fecha.dia, unCensista.fecha.mes ,unCensista.fecha.anio, unCensista.domicilio.calle, unCensista.domicilio.numero,unCensista.estado);
					flagMenu=1;
				}
				break;
			case 2:
				if(flagMenu==1 ||flagMenu==3){
				printCensistas(censistas, LEN_CENSISTAS);
				pedirNumero(&idModificar,"Ingrese el id del censista a modificar \n", "Error el id es invalido\n",1001,1200,2);
				modificarCensista(censistas, LEN_CENSISTAS, idModificar);
				}
				else{
					printf("Primero debe cargar un censista");
				}
				break;
			case 3:
				if(flagMenu==1 ||flagMenu==3){
				printCensistas(censistas, LEN_CENSISTAS);
				pedirNumero(&idModificar,"Ingrese el id del censista a dar de baja \n", "Error el id es invalido\n",1001,1200,2);
				darBajaCensista(censistas, LEN_CENSISTAS, idModificar);
				}
				else{
					printf("Primero debe cargar un censista");
				}
				break;
			case 4:
				unaZona= cargarUnaZona(&retornoZona);
				if(retornoZona==0){
					addZonas(zonas, LEN_ZONAS, unaZona.idZona, unaZona.idCensista, unaZona.estado, unaZona.localidad, unaZona.cuadra.calleUno, unaZona.cuadra.calleDos, unaZona.cuadra.calleTres, unaZona.cuadra.calleCuatro);
					flagMenu=2;
				}
				break;
			case 5:
				if(flagMenu==1  || flagMenu >=2 ){
				printCensistas(censistas, LEN_CENSISTAS);
				pedirNumero(&idModificar,"Ingrese el id del censista a asignar zona \n", "Error el id es invalido\n",1001,1200,2);
				if(buscarCensistaById(censistas, LEN_CENSISTAS, idModificar) != -1){
				if(asignarZona(zonas, LEN_ZONAS, idModificar)==0){
					printf("Se pudo cargar censista a zona6 \n");
					}
				  }
				}
				else{
					printf("Primero debe cargar un censista y una zona");
				}
				break;
			case 6:
				if(flagMenu==1  || flagMenu >=2 ){
				cargarCensados(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
				}
				else{
					printf("Primero debe cargar un censista y una zona");
				}
				break;
			case 7:
				if(flagMenu==1  || flagMenu >=2 ){
				printCensistas(censistas, LEN_CENSISTAS);
				}
				else{
					printf("Primero debe cargar un censista y una zona");
				}
				break;
			case 8:
				if(flagMenu==1  || flagMenu >=2 ){
				MostrarZonasConCensistas(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
				}
				else{
					printf("Primero debe cargar un censista y una zona");
				}
				break;
			case 9:
				cargaForzadaDeCensistas(censistas);
				 printCensistas(censistas, LEN_CENSISTAS);
				 flagMenu=3;
				break;
			case 10:
				cargaForzadaDeZonas(zonas);
				printZonas(zonas, LEN_ZONAS);
				flagMenu=4;
				break;
			case 11:
				informarCantidadCensita(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
				break;
			case 12:
				MostrarCensistasXZonas(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
				break;
			case 13:
				printf("Gracias \n");
				break;


		}
	}

	}while(opcionMenu != 11);

	return EXIT_SUCCESS;
}
