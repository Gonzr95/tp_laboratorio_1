/*
 * tp1Library.c
 *
 *  Created on: 4 abr. 2022
 *      Author: gonzalo.rodriguez
 */


#include "tp1.h"


/**
 * \brief: Calcula TODOS los costos DE UN SOLO VUELO
 * \param: precio: valor FLOAT de precio de vuelo
 * \param: kilometros: valor INT de kilometros
 * \param: precioBitcoin: valor BTC
 * \param: pPrecioDebito: puntero a direccion de memoria donde se almacenara el precioDebito calculado
 * \param: pPrecioCredito: puntero a direccion de memoria donde se almacenara el precioCredito calculado
 * \param: pPrecioBTC: puntero a direccion de memoria donde se almacenara el precioBTC calculado
 * \param: pPrecioUnitario: puntero a direccion de memoria donde se almacenara el precioUnitario calculado
 * \param: precioMinimo: valor minimo del precio del vuelo
 * \param: precioMaximo: valor maximo del precio del vuelo
 * \return: -1 ERROR  //  0 EXITO
 */
int calcularCostos(float precio, int kilometros, float precioBitcoin,
		float* pPrecioDebito, float* pPrecioCredito, float* pPrecioBTC,
		float* pPrecioUnitario, float precioMinimo, float precioMaximo)
{
	int retorno = -1; //ERROR
	if(precio >= precioMinimo && precio <= precioMaximo && pPrecioDebito != NULL && pPrecioCredito != NULL && pPrecioBTC != NULL && pPrecioUnitario != NULL)
	{
		*pPrecioDebito = precio - (precio * 0.10);
		*pPrecioCredito = precio + (precio * 0.25);
		*pPrecioBTC = precio / precioBitcoin;
		*pPrecioUnitario = precio / kilometros;
		retorno = 0; //EXITO
	}
	return retorno;
}

/**
 * \brief: calcula el precio con debito de determinado importe
 * \param: precio: recibe el precio a calcular
 * \param: precioMinimo: valida que el precio tenga sentido
 * \param: precioMaximo: valida que el precio tenga sentido
 * \param: *precioCalculado: puntero a direccion de memoria donde se guardara el resultado
 * \return: -1 ERROR  //  0 EXITO
 */
int calcularPrecioDebito(float precio, float precioMinimo, float precioMaximo, float* precioCalculado)
{
	int retorno = -1; //ERROR

	if(precio <= precioMaximo && precio >= precioMinimo && precioCalculado != NULL)
	{
		calcularDescuento(precio, precioCalculado, 10);
		//*precioCalculado = precio - (precio * 0.10);
		retorno = 0; //EXITO
	}
	return retorno;
}

/**
 * \brief: calcula el precio con credito de determinado importe
 * \param: precio: recibe el precio a calcular
 * \param: precioMinimo: valida que el precio tenga sentido
 * \param: precioMaximo: valida que el precio tenga sentido
 * \param: *precioCalculado: puntero a direccion de memoria donde se guardara el resultado
 * \return: -1 ERROR  //  0 EXITO
 */
int calcularPrecioCredito(float precio, float precioMinimo, float precioMaximo, float* precioCalculado)
{
	int retorno = -1; //ERROR
	if(precio >= precioMinimo && precio <= precioMaximo && precioCalculado != NULL)
	{
		calcularRecarga(precio, precioCalculado, 25);
		retorno = 0; //EXITO
	}
	return retorno;
}

/**
 * \brief: calcula el precio con bitcoin de determinado importe
 * \param: precio: recibe el precio a calcular
 * \param: precioMinimo: valida que el precio tenga sentido
 * \param: precioMaximo: valida que el precio tenga sentido
 * \param: *precioCalculado: puntero a direccion de memoria donde se guardara el resultado
 * \return: -1 ERROR  //  0 EXITO
 */
int calcularPrecioBitcoin(float precio, float precioMinimo, float precioMaximo, float* precioCalculado, float precioBitcoin)
{
	int retorno = -1; //ERROR
	if(precio >= precioMinimo && precio <= precioMaximo && precioCalculado != NULL)
	{
		*precioCalculado = precio / precioBitcoin;
		retorno = 0; //EXITO
	}
	return retorno;
}

/**
 * \brief: calcula el precio unitario de los KM
 * \param: precio: recibe el precio a calcular
 * \param: precioMinimo: valida que el precio tenga sentido
 * \param: precioMaximo: valida que el precio tenga sentido
 * \param: *precioCalculado: puntero a direccion de memoria donde se guardara el resultado
 * \return: -1 ERROR  //  0 EXITO
 */
int calcularPrecioUnitario(float precio, float* precioCalculado, float precioMinimo, float precioMaximo, int kilometros)
{
	int retorno = -1;//ERROR
	if(precio >= precioMinimo && precio <= precioMaximo && precioCalculado != NULL)
	{
		*precioCalculado = precio / kilometros;
	}
	return retorno;//EXITO
}


/**
 * \brief: imprime por consola TODOS los costos de un vuelo si tienen sentido
 * \param: precio: valor FLOAT de precio de vuelo
 * \param: precioDebito: variable que almacena dicho valor
 * \param: precioCredito: variable que almacena dicho valor
 * \param: precioBTC: variable que almacena dicho valor
 * \param: precioUnitario: variable que almacena dicho valor
 * \param: precioMinimo: valor minimo que puede tomar precio
 * \param: precioMaximo:  valor maximo que puede tomar precio
 * \return: -1 ERROR  //  0 EXITO
 */
int mostrarPrecio(float precio, float precioDebito, float precioCredito, float precioBTC, float precioUnitario, float precioMinimo, float precioMaximo, char* mensaje)
{
	int retorno = -1; //ERROR
	if(precioMinimo >= precioMinimo && precioMaximo <= precioMaximo)
	{
		printf("%s",mensaje);
		printf( "a) Precio con tarjeta de debito es: $%.2f\n"
				"b) Precio con tarjeta de credito es: $%.2f\n"
				"c) Precio pagando con Bitcoin es: %.8f BTC\n"
				"d) Precio unitario es: $%.2f\n\n"
				,precioDebito
				,precioCredito
				,precioBTC
				,precioUnitario);
		retorno = 0;//EXITO
	}
	return retorno;
}

/// @fn void mostrarPrecioV2(float, float, char*)
/// @brief muestra por consola precios con DOS DECIMALES junto a un mensaje
///
/// @param precioDeLatam
/// @param precioDeAerolineas
/// @param mensaje
void mostrarPrecioV2(float precioDeLatam, float precioDeAerolineas, char* mensaje)
{
	printf( "%s\n"
			"Latam: $%.2f\n"
			"Aerolineas: $%.2f\n\n"
			,mensaje
			,precioDeLatam
			,precioDeAerolineas);
}

/// @fn void mostrarPrecioV2(float, float, char*)
/// @brief muestra por consola precios con OCHO DECIMALES junto a un mensaje
///
/// @param precioDeLatam
/// @param precioDeAerolineas
/// @param mensaje
void mostrarPrecioV3(float precioDeLatam, float precioDeAerolineas, char* mensaje)
{
	printf( "%s\n"
			"Latam: %.8f btc\n"
			"Aerolineas: %.8f btc\n\n"
			,mensaje
			,precioDeLatam
			,precioDeAerolineas);
}

/// @fn void mostrarPrecioV4(float, float, float, float, float, float, float, float, float, float, int)
/// @brief Muestra por pantalla TODOS los valores de DOS vuelos
///
/// @param precioAero
/// @param precioDebitoAero
/// @param precioAeroCred
/// @param precioAeroBTC
/// @param precioAeroUnitario
/// @param precioLatam
/// @param precioDebitoLatam
/// @param precioLatamCred
/// @param precioLatamBTC
/// @param precioLatamUnitario
/// @param kilometros
void mostrarPrecioV4( float precioAero, float precioDebitoAero, float precioAeroCred, float precioAeroBTC, float precioAeroUnitario
					,float precioLatam, float precioDebitoLatam, float precioLatamCred, float precioLatamBTC, float precioLatamUnitario
					,int kilometros)
{
		printf( "KMs ingresados: %d\n\n"
				"Precio Aerolineas: $%.2f\n"
				"a) Precio con tarjeta de debito es: $%.2f\n"
				"b) Precio con tarjeta de credito es: $%.2f\n"
				"c) Precio pagando con Bitcoin es: %.8f BTC\n"
				"d) Precio unitario es: $%.2f\n\n"
				"Precio Latam: %.2f\n"
				"a) Precio con tarjeta de debito es: $%.2f\n"
				"b) Precio con tarjeta de credito es: $%.2f\n"
				"c) Precio pagando con Bitcoin es: %.8f BTC\n"
				"d) Precio unitario es: $%.2f\n\n"
				,kilometros
				,precioAero
				,precioDebitoAero
				,precioAeroCred
				,precioAeroBTC
				,precioAeroUnitario
				,precioLatam
				,precioDebitoLatam
				,precioLatamCred
				,precioLatamBTC
				,precioLatamUnitario
				);
}

