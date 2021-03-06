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


	 unaZona.idZona=generarIdZonas();

	 unaZona.estado= PENDIENTE;

	 unaZona.idCensista=-1;
		if(pedirNumero(&unaZona.localidad,"Ingrese localidad a censar 1 (LANUS) 2 (LOMAS DE ZAMORA) 3 (AVELLANEDA) 4 (BANDFIELD) \n", "Error! dato invalido",1, 4, 2)== 0){

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

	char auxLocalidad[40];
	char auxEstado[40];

	switch(unaZona.localidad){

		case LANUS:
		strcpy(auxLocalidad, "LANUS");
		break;
		case LOMAS_DE_ZAMORA:
		strcpy (auxLocalidad, "LOMAS_DE_ZAMORA");
		break;
		case AVELLANEDA:
		strcpy(auxLocalidad, "AVELLANEDA");
		break;
		case BANDFIELD:
		strcpy(auxLocalidad, "BANDFIELD");
		break;
	}
	switch(unaZona.estado){

		case PENDIENTE:
		strcpy(auxEstado, "PENDIENTE");
		break;
		case FINALIZADO:
		strcpy (auxEstado, "FINALIZADO");
		break;
	}

	if (unaZona.isEmpty == 0){

		printf("%-4d %-15s %-4d %-18s %-15s %-17s %-15s %15s\n", unaZona.idZona, auxEstado, unaZona.idCensista, auxLocalidad, unaZona.cuadra.calleUno,
					unaZona.cuadra.calleDos, unaZona.cuadra.calleTres, unaZona.cuadra.calleCuatro);

	}

}


int addZonas(Zonas* list, int len, int id, int idCensista, int estado, int localidad,char calle1[], char calle2[], char calle3[], char calle4[]){

	int retorno;
	int espacioLibre;


	retorno = -1;

	if (list != NULL  && calle1 != NULL && calle2!= NULL && calle3!= NULL && calle4 != NULL  && len > 0){


	espacioLibre= buscarEspacioLibreZonas(list, len);

		if (espacioLibre != -1) {


			list[espacioLibre].isEmpty = 0;

			list[espacioLibre].idZona= id;

			list[espacioLibre].idCensista= idCensista;

			list[espacioLibre].estado= estado;

			list[espacioLibre].localidad=localidad;

			strncpy(list[espacioLibre].cuadra.calleUno, calle1, sizeof(list[espacioLibre].cuadra.calleUno));

			strncpy(list[espacioLibre].cuadra.calleDos, calle2, sizeof(list[espacioLibre].cuadra.calleDos));

			strncpy(list[espacioLibre].cuadra.calleTres, calle3, sizeof(list[espacioLibre].cuadra.calleTres));

			strncpy(list[espacioLibre].cuadra.calleCuatro, calle4, sizeof(list[espacioLibre].cuadra.calleCuatro));


			mostrarUnaZona(list[espacioLibre]);

			retorno = 0;
		}
	}
	return retorno;
}

int buscarZonaById(Zonas* list, int len,int id){

	int retorno;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0) {

		for (int i = 0; i < len; i++) {

			if (list[i].idZona == id && list[i].isEmpty == 0){

			  retorno = i;
			  return retorno;
			}
		}
	}
	return retorno;
}

int buscarZonaByIdLibre(Zonas* list, int len){

	int retorno;
		retorno = -1;

		if (list != NULL && len > 0 ) {

			for (int i = 0; i < len; i++) {

				if (list[i].idCensista == -1 && list[i].isEmpty == 0){

				  retorno = i;
				  return retorno;
				}
			}
		}
 return retorno;
}


int modificarZona(Zonas* list, int len, int id){

	int retorno;
	int indice;
	int opcion;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0)
	{
		indice = buscarZonaById(list, len, id);

    	if (indice != -1){

    		mostrarUnaZona(list[indice]);

    	    mostrarSubMenuZonas();

    		 pedirNumero(&opcion, "Ingrese la opcion que desea modificar\n", "Error! la opcion ingresada es incorrecta \n",1, 5, 2);

    		 switch(opcion){

				 case 1:
					 if(pedirNumero(&list[indice].localidad,"Ingrese la nueva localidad censar 1 (LANUS) 2 (LOMAS DE ZAMORA) 3 (AVELLANEDA) 4 (BANDFIELD) \n",
							 "Error! localidad incorrecta: \n", 1, 4, 2)== 0){

					 		printf("La nueva localidad fue cargada correctamente \n");
					 }
					 else{

						 printf("Error! no se pudo cargar localidad invalida \n");
					 }
				 break;
				 case 2:
					if(pedirCaracteres(list[indice].cuadra.calleUno,"Ingrese la nueva primera calle: \n",50)== 0){

						printf("La nueva calle fue cargado correctamente \n");
					}
					else{
						printf("Error! no se pudo cargar calle ");
					}
				 break;
				 case 3:
					if(pedirCaracteres(list[indice].cuadra.calleDos,"Ingrese la nueva segunda calle: \n",50)== 0){

						printf("La nueva calle fue cargado correctamente \n");
					}
					else{
						printf("Error! no se pudo cargar calle ");
					}
				 break;
				 case 4:
					 if(pedirCaracteres(list[indice].cuadra.calleTres,"Ingrese la nueva tercera calle: \n",50)== 0){

						printf("La nueva calle fue cargado correctamente \n");
					}
					else{
						printf("Error! no se pudo cargar calle ");
					}
				 break;
				 case 5:
					 if(pedirCaracteres(list[indice].cuadra.calleCuatro,"Ingrese la nueva cuarta calle: \n",50)== 0){

						printf("La nueva calle fue cargado correctamente \n");
					}
					else{
						printf("Error! no se pudo cargar calle ");
					}
				 break;
				 }
    		 mostrarUnaZona(list[indice]);
    		 retorno=0;
    	}
	}
	 return retorno;
}

int darBajaZona(Zonas* list, int len, int id){

	int retorno;
	int indice;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0) {

		indice =  buscarZonaById(list, len, id);

		if (indice != -1) {

			 mostrarUnaZona(list[indice]);

			if(list[indice].estado== FINALIZADO){

				printf("Nose puede darde baja porque esta FINALIZADO \n");
				 mostrarUnaZona(list[indice]);
			}
			else{
			list[indice].isEmpty = 1;
			 printf("Se dio de baja ZONA\n");
			retorno = 0;
			}
		}
	}
	return retorno;
}

int buscarZonaCargada(Zonas list[], int len){
	int retorno = -1;

		if(list != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == 0)
				{
					retorno = i;
					break;
				}
			}
		}
		printf("retorno en buscarzona cargada %d \n",retorno);
	return retorno;
}


int asignarZona(Zonas* list, int len, int idCencista){

	int retorno = -1;
	int indice;

	if (list != NULL  && len  > 0 && idCencista >0){
		printZonas(list, len);

		indice = buscarZonaByIdLibre(list, len);

		if (indice != -1){

			if(list[indice].estado == PENDIENTE && list[indice].isEmpty == 0){

				list[indice].idCensista=idCencista;
				mostrarUnaZona(list[indice]);
				retorno = 0;

			}
					else{
			    printf("No existe se pudo cargar censista a zona");
			}
		}
	}
	return retorno;
}


int buscarZonaByIdCensista(Zonas* list, int len, int* id){

	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {

		for (int i = 0; i < len; i++) {

			if (list[i].idCensista != -1 && list[i].isEmpty == 0){

			  retorno = i;
			  *id=list[i].idCensista;
			  return retorno;
			}
		}
	}
	return retorno;
}

int printZonas(Zonas* list, int len){

	int retorno;
	retorno=-1;

	if (list != NULL && len > 0){

		for(int i = 0; i < len; i++){

			mostrarUnaZona(list[i]);
			retorno=0;
		}

	}
 return retorno;
}

int cargaForzadaDeZonas(Zonas* list){

	int retorno;

	Zonas zonasAux[8] = {{101, 5, 1001, 1,{"Callao", "Martinez","Montevideo","Viamonte"}},
	           {102, 6, 1001, 2,{"Pavon", "Iberlucea","Carlos Tejedor","Maipu"}},
				{103, 5,1003, 3,{"Yrigoyen", "San Martin","Yerbal","Guido"}},
	            {104, 5, -1, 4,{"Magallanes", "Rosas","Colon","Hernandarias"}},
	            {105, 5, -1, 1,{"Potosi", "Diaz Velez","Medrano","Rivadavia"}},
	            {106, 5,1004,1,{"Maipu", "Corrientes","Lavalle","Sarmiento"}},
				{107, 5, -1, 3,{"dorrego", "Diaz ","Medrano","Rivadavia"}},
		        {108, 5,1004,2,{"flores", "Corrientes","avellaneda","Sarmiento"}}};
	retorno=-1;

	for(int i=0; i< 6; i++){

		list[i]= zonasAux[i];
		retorno=0;
	}
	return retorno;
}
