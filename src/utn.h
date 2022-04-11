/*
 * utn.h
 *
 *  Created on: 4 abr. 2022
 *      Author: gonzalo.rodriguez
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>



int utn_getINT(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int intentos);
int utn_getFLOAT(float* pResultado, char* mensaje, char* mensajeError, int min, int max, int intentos);
int calcularMayor(float num1, float num2, float* pNumMayor, float* pNumMenor, char* mensaje);
void calcularDiferencia(float numMayor, float numMenor, float* pDiferencia);


#endif /* UTN_H_ */
