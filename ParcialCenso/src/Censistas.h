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
#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3


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
	int idCensista;
	char nombre[50];
	char apellido[50];
	int edad;
	FechaNacimiento fecha;
	Direccion domicilio;
	int estado;
	int isEmpty;
}Censistas;
/// @brief inicializa a los censistas colocando isEmpti en 1 (vacio)
///
/// @param list de cencistas
/// @param len taminio
/// @return -1 si no se pudo inicializar y 0 si se pudo
int inicializarCencista(Censistas* list, int len);
/// @brief genera el id censitas sumando sumando de a uno cada vezq se la llama guardando el valor anterior
/// inicializo el id en 1000
/// @return el numero de id
int generarId();
/// @brief recorre la lista y busca la primera posicion libre (isEmpty en 1)
///
/// @param list cencistas
/// @param len tamanio
/// @return el indice si encontro posicion libre y -1 sino la encontro
int buscarEspacioLibre(Censistas* list, int len);
/// @brief  recorre la lista y si encuentra el id que se pasa como parametro y el isEmpty esta cargado devuelve la posicion del indice
///
/// @param list cencistas
/// @param len tamanio
/// @param id paso como paramentro  (se le pide al usuario antes)
/// @return el indice de la posicion donde encontro el id o -1 sino lo encontro
int buscarCensistaById(Censistas* list, int len,int id);
/// @brief carga un solo censita con todos sus datos se pasa como referencia un retorno
///
/// @param retorno -1 si no lo pudo cargar y 0 si lo pudo hacer
/// @return un cencista
Censistas cargarUnCensista(int* retorno);
/// @brief Muestra todoslos datos del censista q se pasa como parametro
///
/// @param unCensista
void mostrarUnCensista(Censistas unCensista);
/// @brief se pasa todos los datos del censita cargado anteriormete en la funcion se llama a buscarEspacioLibre la cual devuelve la primer
/// posicion libre para cargar al censista copiando los valores que paso como parametro
///
/// @param list cencistas
/// @param len tamanio
/// @param idCensista
/// @param nombre
/// @param apellido
/// @param edad
/// @param fechaDia
/// @param fechaMes
/// @param fechaAnio
/// @param domicilio
/// @param domicilioNumero
/// @param estado
/// @return -1 sino lo pudo cargar y 0 si lo pudo hacer
int addCensitas(Censistas* list, int len, int idCensista, char nombre[],char apellido[], int edad,int fechaDia, int fechaMes, int fechaAnio, char domicilio[], int domicilioNumero, int estado);
/// @brief se pasa el numero de id del censista a modificar muestro al censista del id q pase, muestro submenu para q se elija la opcion a modificar
/// segun la opcion elegida se modifica el dato  con un mensaje si se pudo mdificar o no y mostrando aal censita luego
///
/// @param list censitas
/// @param len tamanio
/// @param id q se pide anteriormente al usuario
/// @return 0 si se pudo hacer y -1 sino
int modificarCensista(Censistas* list, int len, int id);
/// @brief  paso como parametro el id del censita q quiero dar de baja en la funcion llamo a buscarCensistaById para q me devuelva
/// la ubicacion (indice) en caso de q el censita este activo no se odra dar de baja y solo se pasara a estado inactivo
///
/// @param list censistas
/// @param len tamanio
/// @param id q paso por valor anteriormente pedido al usuario
/// @return 0 si se  pudo dar de baja -1 sino y muestra el mensaje si se paso a inactivo
int darBajaCensista(Censistas* list, int len, int id);
/// @brief muestro todos los censitas cargados llamando en un bucle a la funcion mostrarUnCensista
///
/// @param list censitas
/// @param len tamanio
/// @return 0 si se pudo mostrar y -1 sino
int printCensistas(Censistas* list, int len);
/// @brief Muestra solo el nombre y apellido del censista q se pasa como parametro
///
/// @param unCensista
void mostrarNombreYapellidoCensista(Censistas unCensista);
/// @brief se cargan en el array 6 censistas con todos sus datos
///
/// @param list censistas
/// @return 0 si se pudo cargar  y -1 sino
int cargaForzadaDeCensistas(Censistas* list);
#endif /* CENSISTAS_H_ */
