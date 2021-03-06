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

			if(list[i].isEmpty==0){
			if(list[i].idCensista != -1){

			indiceCensista=buscarCensistaById(arrayCensistas,lenCensistas, list[i].idCensista);
			mostrarUnaZona(list[i]);
			mostrarNombreYapellidoCensista(arrayCensistas[indiceCensista]);
			retorno=0;
			}
			else if(list[i].idCensista == -1){
				mostrarUnaZona(list[i]);
				printf("No tiene censista asignado\n");
			}
		  }
		}
	}
 return retorno;
}

int informarCantidadCensita(Zonas* list, int len, Censistas *arrayCensistas, int lenCensistas){
    int retorno=-1;
    int contadorCensista=0;



    if(list != NULL && len > 0  && arrayCensistas != NULL && lenCensistas > 0)
    {
        for(int i=0; i<len; i++){

         if(list[i].estado == PENDIENTE && list[i].idCensista != -1){
        	 if(buscarActivoXid(arrayCensistas,lenCensistas,list[i].idCensista)==0){
        	 contadorCensista++;
        	 }
         }

      }
        printf("La cantidad de zonas en estado pendiente con censitas activos son %d \n",contadorCensista);
    }

    return retorno;
 }

int buscarActivoXid(Censistas *arrayCensistas, int lenCensistas,int id){

	int retorno=-1;
	int indice;


	if( arrayCensistas != NULL && lenCensistas > 0){
		indice=buscarCensistaById(arrayCensistas, lenCensistas, id);

	 if (indice != -1) {

			 if(arrayCensistas[indice].estado == ACTIVO){
				 retorno=0;
			 }
		}
     }
 return retorno;
}

int MostrarCensistasXZonas(Zonas* list, int len, Censistas *arrayCensistas, int lenCensistas){

	int retorno=-1;



    if(list != NULL && len > 0  && arrayCensistas != NULL && lenCensistas > 0){
        for(int i=0; i<len; i++){

         switch(list[i].localidad){

         case LANUS:
        	  ordenarAlfabeticamente(arrayCensistas,lenCensistas);
        	  printCensistas(arrayCensistas,lenCensistas);
        	 break;
          case LOMAS_DE_ZAMORA:
        	  ordenarAlfabeticamente(arrayCensistas,lenCensistas);
        	  printCensistas(arrayCensistas,lenCensistas);
              break;
         case AVELLANEDA:
        	 ordenarAlfabeticamente(arrayCensistas,lenCensistas);
        	 printCensistas(arrayCensistas,lenCensistas);
             break;
         case BANDFIELD:
        	 ordenarAlfabeticamente(arrayCensistas,lenCensistas);
        	 printCensistas(arrayCensistas,lenCensistas);
          break;

         }
        }
       }
    return retorno;
 }


int ordenarAlfabeticamente(Censistas *arrayCensistas, int lenCensistas){

	int retorno= -1;
	int ordenado;
	Censistas aux;
		do {
				ordenado = 1;
				lenCensistas--;
				for (int i = 0; i < lenCensistas; i++) {

					if (stricmp(arrayCensistas[i].nombre, arrayCensistas[i + 1].nombre)  < 0){
						aux = arrayCensistas[i];
						arrayCensistas[i] = arrayCensistas[i + 1];
						arrayCensistas[i + 1] = aux;
						ordenado = 0;
					}
					else if(arrayCensistas[i].nombre == arrayCensistas[i].nombre){

						 ordenarAlfabeticamenteApellido(arrayCensistas,  lenCensistas);
						ordenado = 0;
					}

				}
			} while (ordenado == 0);
			retorno = 0;
	return retorno;

}

int ordenarAlfabeticamenteApellido(Censistas *arrayCensistas, int lenCensistas){

	int retorno= -1;
	int ordenado;
	Censistas aux;
		do {
				ordenado = 1;
				lenCensistas--;
				for (int i = 0; i < lenCensistas; i++) {
					if (stricmp(arrayCensistas[i].apellido, arrayCensistas[i + 1].apellido)  < 0){
						aux = arrayCensistas[i];
						arrayCensistas[i] = arrayCensistas[i + 1];
						arrayCensistas[i + 1] = aux;
						ordenado = 0;
					}


				}
			} while (ordenado == 0);
			retorno = 0;
return retorno;

}



