/*
 * Zonas.c
 *
 *  Created on: 17 may. 2022
 *      Author: pamel
 */

#include "Zonas.h"

int inicializarZona(Zonas* list, int len){

	int retorno;
	retorno=-1;

		if (list != NULL && len > 0) {
			for (int i = 0; i < len; i++) {
				list[i].isEmpty = 1;
				retorno=0;
			}
		}
	return retorno;
}

int generarIdZonas(){

	static int id = 100;

	id++;

	return id;

}

int buscarEspacioLibreZonas(Zonas* list, int len){

	int retorno;
	retorno = -1;

		if(list != NULL && len > 0){
			for(int i = 0; i < len; i++){

				if(list[i].isEmpty == 1){
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}

Zonas cargarUnaZona(int* retorno){

	Zonas unaZona;

	int flagCarga;
	flagCarga=0;
    int i=0;

	 unaZona.idZona=generarIdZonas();

	 unaZona.estado= PENDIENTE;
		if(pedirNumero(&unaZona.localidad[i],"Ingrese localidad a censar 1 (LANUS) 2 (LOMAS DE ZAMORA) 3 (AVELLANEDA) 4 (BANDFIELD) \n", "Error! dato invalido",1, 4, 2)== 0){

			flagCarga=1;
		}
		else{

			printf("Error no se pudo cargar localidad");
			flagCarga=0;
		}
		if(flagCarga != 0){
		if(pedirCaracteres(unaZona.cuadra.calleUno,"Ingrese la primer calle de la manzana a censar: \n",50)== 0 && flagCarga==1){
			if(pedirCaracteres(unaZona.cuadra.calleDos,"Ingrese la segunda calle de la manzana a censar: \n",50)== 0){
				if(pedirCaracteres(unaZona.cuadra.calleTres,"Ingrese la tercera calle de la manzana a censar: \n",50)== 0){
					if(pedirCaracteres(unaZona.cuadra.calleCuatro,"Ingrese la cuarta calle de la manzana a censar: \n",50)== 0){

						flagCarga=2;

					}
				}
			}
		}
		else{
			printf("Error no se pudo cargar cuadras");
			flagCarga=0;
		}

		if(flagCarga== 2){

			unaZona.isEmpty= 0;
			*retorno=0;

      }
	}
		else{
			printf("No se pudo cargar zona\n");
		}

 return unaZona;

}

void mostrarUnaZona(Zonas unaZona){

  int i=0;
	if (unaZona.isEmpty == 0){

		printf("%-4d %-4d %-4d %-10s %-17s %-15s %10s\n", unaZona.idZona, unaZona.estado, unaZona.localidad[i], unaZona.cuadra.calleUno,
					unaZona.cuadra.calleDos, unaZona.cuadra.calleTres, unaZona.cuadra.calleCuatro);

	}

}



/*int addCensitas(Censistas* list, int len, int id, char nombre[],char apellido[], int edad,int fechaDia, int fechaMes, int fechaAnio, char domicilio[], int domicilioNumero, int estado){

	int retorno;
	int espacioLibre;


	retorno = -1;

	if (list != NULL && nombre != NULL && apellido != NULL && domicilio!= NULL && len > 0){


	espacioLibre= buscarEspacioLibre(list, len);
	//printf("espacio libre %d \n", espacioLibre);

		if (espacioLibre != -1) {

		//	printf("espacio libre %d", espacioLibre);


			list[espacioLibre].isEmpty = 0;

			list[espacioLibre].idCensista= id;

			strncpy(list[espacioLibre].nombre, nombre, sizeof(list[espacioLibre].nombre));

			strncpy(list[espacioLibre].apellido, apellido, sizeof(list[espacioLibre].apellido));

			list[espacioLibre].edad= edad;

			list[espacioLibre].fecha.dia= fechaDia;

			list[espacioLibre].fecha.mes= fechaMes;

			list[espacioLibre].fecha.anio= fechaAnio;

			strncpy(list[espacioLibre].domicilio.calle, domicilio, sizeof(list[espacioLibre].domicilio.calle));

			list[espacioLibre].domicilio.numero= domicilioNumero;

			list[espacioLibre].estado=estado;

			mostrarUnCensista(list[espacioLibre]);

			retorno = 0;
		}
	}

	return retorno;
}*/
