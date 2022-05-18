/*
 * Informes.c
 *
 *  Created on: 18 may. 2022
 *      Author: pamel
 */
#include "Informes.h"

int cargarCensados(Zonas* list, int len, Censistas *arrayCensistas, int lenCensistas ){

	int retorno = -1;
	int indice;
	int censadosInsitu;
	int cantidadVirtual;
	int cantidadAusentes;
	int auxId;
	int indiceCensista;

	if (list != NULL  && len  > 0 && arrayCensistas !=NULL && lenCensistas >0){

		 indice= buscarZonaByIdCensista(list, len,&auxId);
		 mostrarUnaZona(list[indice]);
		 indiceCensista=buscarCensistaById(arrayCensistas,lenCensistas,auxId);


		if (indice != -1){

			if(list[indice].estado == PENDIENTE ){

				pedirNumero(&censadosInsitu, "Cargar cantidad de censados insitu", "Error dato invalido", 1, 2000, 2);
				pedirNumero(&cantidadVirtual, "Cargar cantidad de censados que completaron censo virtual", "Error dato invalido",1, 5000, 2);
				pedirNumero(&cantidadAusentes, "Cargar cantidad de ausentes", "Error dato invalido",1, 5000, 2);

				list[indice].estado= FINALIZADO;
				arrayCensistas[indiceCensista].estado= LIBERADO;
				retorno = 0;
				 mostrarUnaZona(list[indice]);
				 mostrarUnCensista(arrayCensistas[indiceCensista]);

			}
			else{
				printf("No existe se pudo cargar cantdad de censados");
			}
			if(censadosInsitu>0){
				printf("cantidad de censados insitu %d \n",censadosInsitu);
			}
			if(cantidadVirtual>0){
				printf("cantidad de censados virtual %d \n",cantidadVirtual);
			}
			if(cantidadAusentes> 0){
				printf("cantidad de ausentes %d \n",cantidadAusentes);
			}
		}
	}
 return retorno;
}


int MostrarZonasConCensistas(Zonas* list, int len, Censistas *arrayCensistas, int lenCensistas){

	int retorno;
	int indiceCensista;

	retorno=-1;

	if (list != NULL && len > 0){

		for(int i = 0; i < len; i++){

			if(list[i].idCensista != -1){

			indiceCensista=buscarCensistaById(arrayCensistas,lenCensistas, list[i].idCensista);
			mostrarUnaZona(list[i]);
			mostrarNombreYapellidoCensista(arrayCensistas[indiceCensista]);
			retorno=0;
			}
		}

	}
 return retorno;
}


