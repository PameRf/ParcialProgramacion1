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
 	int localidad;
 	Cuadras cuadra;
	int isEmpty;
}Zonas;

/// @brief   inicializa las zonas colocando isEmpti en 1 (vacio)
///
/// @param list zonas
/// @param len  tamanio
/// @return  -1 si no se pudo inicializar y 0 si se pudo
int inicializarZona(Zonas* list, int len);
/// @brief genera el id censitas sumando sumando de a uno cada vezq se la llama guardando el valor anterior
/// inicializo en 100
///
/// @return el id generado
int generarIdZonas();
/// @brief recorre con un bucle y devuelve la poscion del indice del primer isEmpty vacio (en 1)
///
/// @param list
/// @param len
/// @return el numero de indice si encontro posicion libre o -1 sino
int buscarEspacioLibreZonas(Zonas* list, int len);
/// @brief carga una sola zona con todos sus datos se pasa como referencia un retorno
///  cargo id censista con valor ilogico -1
/// @param retorno -1 sino lo pudo cargar 0 si lo pudo
/// @return una zona
Zonas cargarUnaZona(int* retorno);
///  @brief Muestro todos los datos de la zona q paso como parametro
///
/// @param unaZona
void mostrarUnaZona(Zonas unaZona);
/// @brief se pasa todos los datos una zona cargado anteriormete en la funcion se llama a buscarEspacioLibreZonas la cual devuelve la primer
/// posicion libre para cargar al censista copiando los valores que paso como parametro
///
/// @param list
/// @param len
/// @param id
/// @param idCensista
/// @param estado
/// @param localidad
/// @param calle1
/// @param calle2
/// @param calle3
/// @param calle4
/// @return -1 sino lo pudo cargar y 0 si lo pudo hacer
int addZonas(Zonas* list, int len, int id, int idCensista, int estado, int localidad,char calle1[], char calle2[], char calle3[], char calle4[]);
/// @brief  se le pasa el id como parametro a buscar se recorre con un bucle y si lo encuentra
///  y la zona esta cargada devuelve el indice de donde lo encontro
///
/// @param list zonas
/// @param len tamanio
/// @param id
/// @return posicion de indice si lo encontro -1 sino
int buscarZonaById(Zonas* list, int len,int id);
/// @brief se pasa el numero de id de la zona a modificar muestro busco la ubicacion del indice llamando a funcion buscarZonaById, muestro submenu para q se elija la opcion a modificar
/// segun la opcion elegida se modifica el dato  con un mensaje si se pudo mdificar o no y mostrando a la censita zona
///
/// @param list zonas
/// @param len tamanio
/// @param id  q se pide anteriormente al usuario
/// @return  0 si se  pudo hacer de baja -1 sino
int modificarZona(Zonas* list, int len, int id);
/// @brief paso como parametro el id de la zona a modificar  q quiero dar de baja en la funcion llamo a buscarZonaById para q me devuelva
/// la ubicacion (indice) en caso de q la zona este finalizada indica q  no se podra dar de baja
///
/// @param list zonas
/// @param len tamanio
/// @param id  q se pide anteriormente al usuario
/// @return  0 si se  pudo dar de baja -1 sino
int darBajaZona(Zonas* list, int len, int id);
/// @brief recorro en un bucle y devuelvo el indice del primer isEmpti cargado (0)
///
/// @param list zonas
/// @param len tamanio
/// @return el indice de la posicion donde encontro cargado o -1 sino encontro pisicion cargada
int buscarZonaCargada(Zonas list[], int len);
/// @brief paso el id del censita que quiero asignar a la zona muestros las zonas cargadas, llamo a funcion buscarZonaByIdLibre que me devuelve
/// el primer indice donde encontro id censita en -1 y cargo al censita que pase como parametro a la zona, mostrando la zona con el id censita asignado
///
/// @param list zonas
/// @param len tamanio
/// @param idCencista q se pide anteriormente al usuario
/// @return  0 si se  pudo asignar de baja -1 sino
int asignarZona(Zonas* list, int len, int idCencista);
/// @brief recorre en un bucle la lista de zonas devolviendo el id como referencia y retornando el indice donde encontro la posicion cargada ya con el id del censita
///
/// @param list zonas
/// @param len tamanio
/// @param id
/// @return l indice de la posicion donde encontro id cargado o -1 sino lo  encontro
int buscarZonaByIdCensista(Zonas* list, int len, int * id);
/// @brief muestro todos las zonas cargadas llamando en un bucle a la funcion mostrarUnaZona
///
/// @param list zonas
/// @param len tamanio
/// @return  0 si se  pudo mostrar -1 sino
int printZonas(Zonas* list, int len);
/// @brief se cargan en el array 6 zonas con todos sus datos
///
/// @param list zonas
/// @return  si se  pudo cargar -1 sino
int cargaForzadaDeZonas(Zonas* list);
/// @brief recorre en un bucle y  devuelve la posicion del indice donde encontro el idCensista en valor ilogico -1
///
/// @param list zonas
/// @param len tamanio
/// @return el indice encontrado o -1 sino lo encontro
int buscarZonaByIdLibre(Zonas* list, int len);



#endif /* ZONAS_H_ */
