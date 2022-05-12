/*
 * utn.h
 *
 *  Created on: 27 ene. 2022.
 *  Modificado: martes 12/04/2022
 *      Author: gonzalo.rodriguez
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos);
int utn_getFoat(float* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos);
int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char min, char max, int reintentos);
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

int myGets(char* string, int longitud);
int getFloat(float* pResultado);
int getFloat(float* pResultado);
int getInt(int* pResultado);
int getNombre(char* pResultado);
int getDescripcion(char* pResultado);

int inicializarArrayInt(int* pArray, int longitud, float valorInicial);
int initArrayFloat(float* pArray, int longitud, float valorInicial);

int utn_printArrayINT(int* pArray, int arrayLenght);
int utn_printArrayFLOAT(float* pArray, int arrayLenght);
int utn_ordenarArrayIntMayoraMenor(int* pArray, int arrayLenght);
int utn_ordenarArrayIntMenoraMayor(int* pArray, int arrayLenght);

int esNombre(char* string, int limite);
int esInt(char* string, int limite);
int esFloat(char* string, int limite);
int esSoloLetras(char* stringa);
int esAlfaNumerico(char* stringa);
int esTelefono(char* stringa);

int calcularDescuento(float precio, float* precioCalculado, float descuento);
int calcularRecarga(float precio, float* precioCalculado, float recarga);
int calcularDiferenciaV2(float num1, float num2, char* mensaje, char*mensajeError, float* pDiferencia);
int utn_calcularPromedio(float* promedio, float dividendo, int divisor);

int validateExit_YN(char* message, char* errorMessage, int retries);


#endif /* UTN_H_ */
