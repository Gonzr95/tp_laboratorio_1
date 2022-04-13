/*
 * utn.c
 *
 *  Created on: 4 abr. 2022
 *      Author: gonzalo.rodriguez
 */

#include "utn.h"

/**
 * \brief: Pide un INT y lo guarda en una variable int
 * \param: pResultado: puntero a direccion de memoria donde se almacenará el INT pedido
 * \param: mensaje: primer mensaje que verá el usuario
 * \param: mensajeError: mensaje que vera el usuario al ingresar un dato erroneo
 * \param: min: valor minimo aceptado para el INT
 * \param: max: valor maximo acepptado para el INT
 * \param: intentos: cantidad de vez que puede equivocarse el usuario
 * \return: -1 ERROR / 0 EXITO
 */
int utn_getINT(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int intentos)
{
	int retorno = -1; //ERROR
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && intentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= min && bufferInt <= max)
			{
				*pResultado = bufferInt;
				retorno=0; //EXITO
				break;
			}
			printf("%s",mensajeError);
			intentos--;
		}
		while(intentos >= 0);
	}
	return retorno;
}


/**
 * \brief: Pide un FLOAT y lo guarda en una variable FLOAT
 * \param: pResultado: puntero a direccion de memoria donde se almacenará el FLOAT pedido
 * \param: mensaje: primer mensaje que verá el usuario
 * \param: mensajeError: mensaje que vera el usuario al ingresar un dato erroneo
 * \param: min: valor minimo aceptado para el FLOAT
 * \param: max: valor maximo acepptado para el FLOAT
 * \param: intentos: cantidad de vez que puede equivocarse el usuario
 * \return: -1 ERROR / 0 EXITO
 */
int utn_getFLOAT(float* pResultado, char* mensaje, char* mensajeError, int min, int max, int intentos)
{
	int retorno = -1; //ERROR
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && intentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&bufferFloat);
			if(bufferFloat >= min && bufferFloat <= max)
			{
				*pResultado = bufferFloat;
				retorno=0; //EXITO
				break;
			}
			printf("%s",mensajeError);
			intentos--;
		}
		while(intentos >= 0);
	}
	return retorno;
}

/// @fn int calcularMayor(float, float, float*)
/// @brief revisa si alguno de los numeros es mayor que el otro y almacena el mayor en una direccion de memoria.
///
/// @pre
/// @post
/// @param num1 recibe el numero 1 a comparar
/// @param num2 recibe el numero 1 a comparar
/// @param pNumMayor direccion de memoria donde se almacenara el numero mayor
/// @param pNumMenor direccion de memoria donde se almacenara el numero menor
/// @param mensaje: mensaje que imprimiremos por pantalla si los numeros son iguales
/// @return  -1 ERROR  //  0 EXITO
int calcularMayor(float num1, float num2, float* pNumMayor, float* pNumMenor, char* mensaje)
{
	int retorno = -1; //ERROR NO HAY DIFERENCIA
	if(pNumMayor != NULL && pNumMenor != NULL)
	{
		if(num1 == num2)
		{
			printf("%s",mensaje);
		}
		else
		{
			if(num1 > num2)
			{
				*pNumMayor = num1;
				*pNumMenor = num2;
				retorno = 0; // EXITO hay num mayor y es el 1
			}
			else
			{
				*pNumMayor = num2; // EXITO hay num mayor y es el 2
				*pNumMenor = num1;
				retorno = 0;
			}
		}
	}
	return retorno;
}

/// @fn void calcularDiferencia(float, float, float*)
/// @brief Calcula la diferencia que hay entre FLOATMayor y FLOATMenor
///
/// @param numMayor
/// @param numMenor
/// @param pDiferencia
void calcularDiferencia(float numMayor, float numMenor, float* pDiferencia)
{
	if(pDiferencia != NULL)
	{
		*pDiferencia = numMayor - numMenor;
	}
}

int calcularDiferenciaV2(float num1, float num2, char* mensaje, char*mensajeError, float* pDiferencia)
{
	int retorno = -1;// ERROR POR PUNTERO O NO HAY DIFERENCIA
	float diferencia;
	if(mensaje != NULL && mensajeError != NULL)
	{
		if(num1 != num2)
		{
			retorno = 0; // Salio todo bien
			diferencia = num1 - num2;

			if(diferencia < 0)
			{
				diferencia = diferencia * -1;
			}
			*pDiferencia = diferencia;
			printf("%s%.2f\n\n",mensaje,diferencia);
		}
		else
		{
			printf("%s\n\n",mensajeError);
		}
	}
	return retorno;
}

/// @fn int calcularDescuento(float, float*, float)
/// @brief calcula el descuento
///
/// @param precio el precio base
/// @param precioCalculado puntero a direccion de memoria donde se guardara el resultado
/// @param descuento porcentaje de decuento
/// @return -1 ERROR  //  0 EXITO
int calcularDescuento(float precio, float* precioCalculado, float descuento)
{
	int retorno = -1;

	if(precioCalculado != NULL)
	{
		*precioCalculado = precio - (precio / 100 *descuento);
		retorno = 0;
	}
	return retorno;
}

/// @fn int calcularRecarga(float, float*, float)
/// @brief calcula la recarga
///
/// @param precio el precio base
/// @param precioCalculado puntero a direccion de memoria donde se guardara el resultado
/// @param recarga porcentaje de recarga
/// @return -1 ERROR  //  0 EXITO
int calcularRecarga(float precio, float* precioCalculado, float recarga)
{
	int retorno = -1;

	if(precioCalculado != NULL)
	{
		*precioCalculado = precio + (precio / 100 *recarga);
		retorno = 0;
	}
	return retorno;
}

