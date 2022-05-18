/*
 * Inputs.h
 *
 *  Created on: 16 may. 2022
 *      Author: pamel
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Censistas.h"
#include "Zonas.h"

/// @brief la funcion recibe la cadena que carga el usuario llamo a fgets para guardarlo en una cadena auxiliar
/// recorro la cadena aux hasta el enter y antes del mismo posicion le asigno el '\0' y copio la cadena auxiliar a la cadena recibida
///
/// @param cadena pasada por referencia
/// @param len tamanio
/// @return -1 sino pudo retornarla o 0 si pudo hacerlo
int myGets(char cadena[], int len);
/// @brief  recibe la cadena de pedir numero, llama a my gets y a es numerica y si ambas fuciones pudieron realizarce correctamente
/// convierte la cadena recibida en numero entero
///
/// @param pNumero recibido como referencia
/// @return -1 sino pudo retornarlo o 0 si pudo hacerlo
int pedirEntero(int* pNumero);
/// @brief recibe la cadena que le pasa pedir entero y la recorre analiza si la primer posicion es '-' y si son todos caracteres numericos del 0 al 9
///
/// @param cadena por referencia
/// @return  0 sino es numerico o 1 si lo es
int esNumerica(char cadena[]);
/// @brief recibe la cadena que le pasa pedir flotante y la recorre analiza si la primer posicion es '.' es invalido y si son todos caracteres numericos del 0 al 9, solo puede tener
/// '.'  en posicion diferente al 0
/// @param cadena por referencia
/// @return 0 sino es flotante o 1 si lo es
int esFlotante(char cadena[]);
/// @brief  recibe la cadena de pedir precio, llama a my gets y a es flotante y si ambas fuciones pudieron realizarce correctamente
/// convierte la cadena recibida en numero flotante
///
/// @param pNumero  por referencia
/// @return -1 sino pudo retornarlo o 0 si pudo hacerlo
int pedirFlotante(float* pNumero);
/// @brief pide un numero al usuario mostrando msg por pantalla  un min max un mensaje de error y le da una cantidad de reintentos
///
/// @param pNumero por referencia
/// @param mensaje cargo al momento de la llamada
/// @param error  cargo al momento de la llamada
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return -1 sino pudo retornarlo o 0 si pudo hacerlo
int pedirNumero(int* pNumero, char mensaje[], char error[], int minimo, int maximo, int reintentos);
/// @brief pide un numero flotante al usuario mostrando msg por pantalla  un min max un mensaje de error y le da una cantidad de reintentos
///
/// @param pPrecio por referencia
/// @param mensaje cargo al momento de la llamada
/// @param error cargo al momento de la llamada
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return -1 sino pudo retornarlo o 0 si pudo hacerlo
///
int pedirPrecio(float* pPrecio, char mensaje[], char error[], float minimo, float maximo, int reintentos);
/// @brief recorro la cadena que se pasa or referencia y se analiza si son solo letras
/// mayusculas y minusculas el  y el escio puede estar en un posicion diferente al indice 0
/// @param cadena
/// @return 0 sino son letras o 1 si lo es
int sonLetras(char cadena[]);
/// @brief pide cadena de string al usuario llama a son letras para verificarlos
///
/// @param cadena
/// @param mensaje cargo al momento de la llamada
/// @param len tamanio
/// @return-1 sino pudo retornarlo o 0 si pudo hacerlo
int pedirCaracteres(char cadena[],char mensaje[], int len);
void mostrarSubMenu();


#endif /* INPUTS_H_ */
