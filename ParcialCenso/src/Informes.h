/*
 * Informes.h
 *
 *  Created on: 18 may. 2022
 *      Author: pamel
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Censistas.h"
#include "Zonas.h"
/// @brief primero busco el indice de la primer zona con censista asignado devuelvo indice y id como referencia y lo guado en un auxiliar
/// muestro la zon encontrada y busco el indice en array de censistas del id encontrado // para cargarlo en indice censita, si el estado de la zona es pendiente, pido datos al usuario
/// y luego los muestro en misma funcion, cargo estado de zona como finalizado y estado de cennsista como liberado luego muestro la zon y muestro al censista
///
/// @param list zonas
/// @param len tamanio
/// @param arrayCensistas censistas
/// @param lenCensistas tamanio
/// @return 0 si se pudo cargar -1 sino
int cargarCensados(Zonas* list, int len, Censistas* arrayCensistas, int lenCensistas);
int MostrarZonasConCensistas(Zonas* list, int len, Censistas *arrayCensistas, int lenCensistas);
int buscarActivoXid(Censistas *arrayCensistas, int lenCensistas,int id);
int informarCantidadCensita(Zonas* list, int len, Censistas *arrayCensistas, int lenCensistas);
int ordenarAlfabeticamente(Censistas *arrayCensistas, int lenCensistas);
int ordenarAlfabeticamenteApellido(Censistas *arrayCensistas, int lenCensistas);
int MostrarCensistasXZonas(Zonas* list, int len, Censistas *arrayCensistas, int lenCensistas);

#endif /* INFORMES_H_ */
