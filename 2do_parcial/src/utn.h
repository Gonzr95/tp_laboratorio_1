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
#include <time.h>
#define OCUPADO 0
#define LIBRE 1

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos);
int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char min, char max, int reintentos);
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getCuit(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getMail(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getMailUser(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getPassword(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getMailV2(char* pResultado, int usuarioLength, int dominioLength, char* mensaje, char* mensajeError, int reintentos);
int utn_getDireccion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);


int myGets(char* string, int longitud);
int getFloat(float* pResultado);
int getInt(int* pResultado);
int getLetra(char* pResultado, int longitud);
int getNombre(char* pResultado, int length);
int getDescripcion(char* pResultado, int longitud);
int getCuit(char* pResultado, int longitud);
int getMail(char* pResultado, int longitud);
int setearDominioCorreo(char* pResultado, int longitudDominio);
int getMailUser(char* pResultado, int longitud);
int getPassword(char* pResultado, int longitud);
int getMailBox(char* pResultado, int userLongitud, int dominioLongitud);
int getDireccion(char* pResultado, int longitud);

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
int esAlfaNumerico(char* string, int longitud);
int esDireccion(char* string, int longitud);
int esTelefono(char* stringa);
int esCuit(char* string);
int esMail(char* string, int longitud);
int esMailUser(char* string, int longitud);
int esMailUserV2(char* string, int userLongitud, int dominioLongitud);

int calcularDescuento(float precio, float* precioCalculado, float descuento);
int calcularRecarga(float precio, float* precioCalculado, float recarga);
int calcularDiferenciaV2(float num1, float num2, char* mensaje, char*mensajeError, float* pDiferencia);
int utn_calcularPromedio(float* promedio, float dividendo, int divisor);

int validateExit_YN(char* message, char* errorMessage, int retries);
long int sumarSegundos(long int segundosASumar, long int horaActual);
void dinamitarNuevaLinea(char* hora, int length);
void escribirHoraStringActual(char* string, int stringLength);

void entreAca(void);
void DEBUG(void);
void ERROR(void);
void laCadenaTiene(char* cadena, int length);
void laCadenaEs(char* cadena);
void elEnteroEs(int entero);
void elFloatEs(double decimal);
int resizeArray(int** array, int* size, int newSize);

#endif /* UTN_H_ */
