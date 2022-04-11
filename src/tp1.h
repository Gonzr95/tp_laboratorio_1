/*
 * tp1Library.h
 *
 *  Created on: 4 abr. 2022
 *      Author: gonzalo.rodriguez
 */

#ifndef TP1LIBRARY_H_
#define TP1LIBRARY_H_
#include <stdio.h>
#include <stdlib.h>



int calcularCostos(  float precio, int kilometros, float precioBitcoin, float* pPrecioDebito, float* pPrecioCredito
					,float* pPrecioBTC, float* pPrecioUnitario, float precioMinimo, float precioMaximo);
int calcularPrecioDebito(float precio, float precioMinimo, float precioMaximo, float* precioCalculado);
int calcularPrecioCredito(float precio, float precioMinimo, float precioMaximo, float* precioCalculado);
int calcularPrecioBitcoin(float precio, float precioMinimo, float precioMaximo, float* precioCalculado, float precioBitcoin);
int calcularPrecioUnitario(float precio, float* precioCalculado, float precioMinimo, float precioMaximo, int kilometros);
int mostrarPrecio(float precio, float precioDebito, float precioCredito, float precioBTC, float precioUnitario, float precioMinimo, float precioMaximo, char* mensaje);
void mostrarPrecioV2(float precioDeLatam, float precioDeAerolineas, char* mensaje);
void mostrarPrecioV3(float precioDeLatam, float precioDeAerolineas, char* mensaje);
void mostrarPrecioV4( float precioAero, float precioDebitoAero, float precioAeroCred, float precioAeroBTC, float precioAeroUnitario
					,float precioLatam, float precioLatamAero, float precioLatamCred, float precioLatamBTC, float precioLatamUnitario
					,int kilometros);

#endif /* TP1LIBRARY_H_ */
