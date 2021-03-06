/*
 * Censistas.c
 *
 *  Created on: 16 may. 2022
 *      Author: pamel
 */

#include "Censistas.h"

int inicializarCencista(Censistas* list, int len){

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

int generarId(){

	static int id = 1000;

	id++;

	return id;

}

int buscarEspacioLibre(Censistas* list, int len){

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

int buscarCensistaById(Censistas* list, int len,int id){

	int retorno;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0) {

		for (int i = 0; i < len; i++) {
			if (list[i].idCensista == id && list[i].isEmpty == 0){

			  retorno = i;
			  return retorno;
			}
		}
	}
	printf("retorno en func buscar censista by id %d", retorno);
	return retorno;
}

Censistas cargarUnCensista(int* retorno){

	Censistas unCensista;

	int flagCarga;
	flagCarga=0;


		unCensista.idCensista=generarId();

		if(pedirCaracteres(unCensista.nombre,"Ingrese el nombre: \n",50)== 0){

			flagCarga=1;
		}
		else{

			printf("Error no se pudo cargar nombre invalido");
			flagCarga=0;
		}
		if(flagCarga != 0){
		if(pedirCaracteres(unCensista.apellido,"Ingrese el apellido: \n",50)== 0 && flagCarga==1){

			flagCarga=2;
		}
		else{
			printf("Error no se pudo cargar apellido invalido");
			flagCarga=0;
		}
		if(pedirNumero(&unCensista.edad,"Ingrese la edad: \n", "Error! edad invalida: \n", 18, 59, 2)== 0 && flagCarga==2){

			flagCarga=3;
		}
		else{
			printf("Error no se pudo cargar edad");
			flagCarga=0;
		}
		if(pedirNumero(&unCensista.fecha.dia, "Ingrese dia de nacimiento: \n", "Error! dato invalido \n",1,31,2)== 0  && flagCarga==3){
			if(pedirNumero(&unCensista.fecha.mes, "Ingrese mes de nacimiento: \n","Error! dato invalido \n",1,12,2)== 0){
				if(pedirNumero(&unCensista.fecha.anio, "Ingrese anio de nacimiento : \n", "Error! dato invalido \n",1962, 2003,2)== 0){

					flagCarga=4;
			}
		 }
		}
		else{
			printf("Error no se pudo cargar fecha de nacimiento");
			flagCarga=0;
		}
		if(pedirCaracteres(unCensista.domicilio.calle, "Ingrese calle de cencista\n",50)== 0 && flagCarga==4){
			if(pedirNumero(&unCensista.domicilio.numero, "Ingrese la numeracion de su domicilio: \n", "Error! dato invalido \n",1,9999,2)== 0){
			flagCarga=5;
		 }
		}
		else{
			printf("Error no se pudo cargar domicilio");
			flagCarga=0;
		}
		if(pedirNumero(&unCensista.estado,"Ingrese estado 1(ACTIVO), 2(INACTIVO) 3 (LIBERADO) \n", "Error! OPCION invalida: \n", 1, 3, 2)== 0 && flagCarga==5){

					flagCarga=6;
		}
		else{
			printf("Error no se pudo cargar edad");
			flagCarga=0;
		}
		if(flagCarga== 6){

			unCensista.isEmpty= 0;
			*retorno=0;

			printf("se pudo cargar en funcion \n");
      }
	}
		else{
			printf("No se pudo cargar en censista \n");
		}

	//printPassenger(unPasajero);
 return unCensista;

}

void mostrarUnCensista(Censistas unCensista){

	char auxEstado[40];

	switch(unCensista.estado){

		case ACTIVO:
		strcpy(auxEstado, "ACTIVO");
		break;
		case INACTIVO:
		strcpy (auxEstado, "INACTIVO");
		break;
		case LIBERADO:
		strcpy(auxEstado, "LIBERADO");
		break;
	}

	if (unCensista.isEmpty == 0){

	printf("%-4d %-15s %-19s %-10d %d/%d/%d %10s %d %-10s\n", unCensista.idCensista,  unCensista.nombre, unCensista.apellido, unCensista.edad, unCensista.fecha.dia, unCensista.fecha.mes,unCensista.fecha.anio, unCensista.domicilio.calle,unCensista.domicilio.numero, auxEstado);

	}

}



int addCensitas(Censistas* list, int len, int id, char nombre[],char apellido[], int edad,int fechaDia, int fechaMes, int fechaAnio, char domicilio[], int domicilioNumero, int estado){

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
}

int modificarCensista(Censistas* list, int len, int id){

	int retorno;
	int indice;
	int opcion;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0)
	{
		indice = buscarCensistaById(list, len, id);

    	if (indice != -1){

    		 mostrarUnCensista(list[indice]);

    		 mostrarSubMenu();

    		 pedirNumero(&opcion, "Ingrese la opcion que desea modificar\n", "Error! la opcion ingresada es incorrecta \n",1, 6, 2);

    		 switch(opcion){

				 case 1:
					 if(pedirCaracteres(list[indice].nombre,"Ingrese el nuevo nombre: \n",50)== 0){

						 printf("El nuevo nombre fue cargado correctamente \n");

					 }
					 else{

						 printf("Error! no se pudo cargar nombre invalido \n");
					 }
				 break;
				 case 2:
					if(pedirCaracteres(list[indice].apellido,"Ingrese el nuevo apellido: \n",50)== 0){

						printf("El nuevo apellido fue cargado correctamente \n");
					}
					else{
						printf("Error! no se pudo cargar apellido invalido");
					}
				 break;
				 case 3:
					if(pedirNumero(&list[indice].edad,"Ingrese la nueva edad: \n", "Error! edad incorrecta: \n", 18, 59, 2)== 0){

						printf("La nueva edad fue cargada correctamente \n");
					}
					else{
						printf("Error! no se pudo cargar nueva edad\n");
					}
				 break;
				 case 4:
					if(pedirNumero(&list[indice].fecha.dia, "Ingrese nuevo dia de nacimiento \n", "Error! dato invalido", 1, 31,2)== 0){
						if(pedirNumero(&list[indice].fecha.mes, "Ingrese mes de nacimiento: \n","Error! dato invalido \n",1,12,2)== 0){
							if(pedirNumero(&list[indice].fecha.anio, "Ingrese anio de nacimiento : \n", "Error! dato invalido \n",1962, 2003,2)== 0){

											printf("La nueva fecha de nacimiento fue cargada correctamente");
							}
						 }
					}
					else{
						printf("Error no se pudo cargar nueva fecha de nacimiento\n");
					}
				 break;
				 case 5:
					if(pedirCaracteres(list[indice].domicilio.calle, "Ingrese su nuevo domicilio: \n", 50)== 0){
						if(pedirNumero(&list[indice].domicilio.numero, "Ingrese su numero de domicilio", "Error! dato invalido \n",1,9999,2)==0){

						printf("El nuevo domicilio fue cargado correctamente\n");
						}
					}
					else{
						printf("Error no se pudo cargar nuevo domicilio\n");
					}

				 break;
				 case 6:
					 if(pedirNumero(&list[indice].estado,"Ingrese estado 1(ACTIVO), 2(INACTIVO) 3 (LIBERADO) \n", "Error! OPCION invalida: \n", 1, 3, 2)== 0){
						 printf("El nuevo estado fue cargado correctamente\n");


						}
					else{
							printf("Error no se pudo cargar nuevo estado\n");
						}
				 break;
				 }
    		 mostrarUnCensista(list[indice]);

    		 retorno = 0;
    	}
	}
	 return retorno;
}





int darBajaCensista(Censistas* list, int len, int id){

	int retorno;
	int indice;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0) {

		indice =  buscarCensistaById(list, len, id);

		if (indice != -1) {

			mostrarUnCensista(list[indice]);

			if(list[indice].estado== ACTIVO){

				list[indice].estado= INACTIVO;
				printf("Nose puede darde baja porque esta ACTIVO pasa a estado Inactivo\n");
				mostrarUnCensista(list[indice]);
			}
			else{
			list[indice].isEmpty = 1;
			 printf("Se dio de baja censista\n");
			retorno = 0;
			}
		}
	}
	return retorno;
}

int printCensistas(Censistas* list, int len){

	int retorno;
	retorno=-1;

	if (list != NULL && len > 0){

		for(int i = 0; i < len; i++){

			mostrarUnCensista(list[i]);
			retorno=0;
		}

	}
 return retorno;
}

void mostrarNombreYapellidoCensista(Censistas unCensista){


	if (unCensista.isEmpty == 0){

	printf("%-15s %-19s \n", unCensista.nombre, unCensista.apellido);

	}

}

int cargaForzadaDeCensistas(Censistas* list){

	int retorno;

	Censistas censistaAux[6] = {{1001, "Juan", "Martinez",34, {23,2,1997},{"Montevideo",1433}, 1},
	           {1002, "Roberto", "Gomez", 25, {4 ,3 ,1995},{"Diaz Velez",1346}, 2},
				{1003, "Ezequiel", "Freire", 36, {28, 4, 1987},{"Viamonte",1568}, 1},
	            {1004, "Dario", "Gomez",28, {14, 12, 1993},{"Callao",2345}, 1},
	            {1005, "Jose", "Romano",20, {22, 3, 1989},{"Talcahuano",2366}, 2},
	            {1006, "Laura", "Torres", 23, {4, 10, 1995},{"San Martin",1340}, 2}};
	retorno=-1;

	for(int i=0; i< 6; i++){

		list[i]= censistaAux[i];
		retorno=0;
	}
	return retorno;
}


