/*
 ============================================================================
 Name        : Tp1_16-04-2022.c
 Author      : Gonzalo Rodriguez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include "tp1.h"
#define kmMIN 100 //hardcodeo el vuelo mas corto ofrecido por las aerolineas
#define kmMAX 19483 //vuelo comercial mas largo en el mundo

//a modo validacion se hardcodea un monto min y max de precios aceptados
#define precioMIN 10000
#define precioMAX 80000000

#define BTC_Value 4606954.55

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int kilometros;
	float latamPrecio;
	float aerolineasPrecio;
	float latamPrecioDebito;
	float aerolineasPrecioDebito;
	float latamPrecioCredito;
	float aerolineasPrecioCredito;
	float latamPrecioBTC;
	float aerolineasPrecioBTC;
	float latamPrecioUnitario;
	float aerolineasPrecioUnitario;
	float diferencia;
	int flagVueloCargado = 0;
	int flagVuelosCalculados = 0;


	do
	{
		if(!utn_getINT(&opcion, "--Ingrese una opcion--\n"
				"1)Para ingresar un vuelo y sus precios\n"
				"2)Para calcular los costos\n"
				"3)Para informar resultados\n"
				"4)Para carga forzada de datos\n"
				"5)Para salir\n"
				"----------------------------------------------\n"
				, "ERROR, revise las opciones disponibles\n"
				, 1, 6, 2))
		{
			switch(opcion)
			{
				//----INGRESO DE KILOMETROS----
				case 1:
					if(!utn_getINT(&kilometros, "Ingrese la cantidad de kilometros\n", "Debe haber algun error\n", kmMIN, kmMAX, 2))
					{
						//----INGRESO DE PRECIOS----
						if(utn_getFLOAT(&latamPrecio, "Ingrese el precio para el vuelo de Latam\n", "Debe haber algun error\n", precioMIN, precioMAX, 2) == -1)
						{
							printf("Hubo algun error, vuelvo al menu\n\n");
							break;
						}
						printf("El precio ingresado es: $%.2f\n",latamPrecio);
						if(utn_getFLOAT(&aerolineasPrecio, "Ingrese el precio para el vuelo de Aerolineas\n", "Debe haber algun error\n", precioMIN, precioMAX, 2) == -1)
						{
							printf("Hubo algun error, vuelvo al menu\n\n");
							break;
						}
						printf("El precio ingresado es: $%.2f\n",aerolineasPrecio);
						flagVueloCargado = 1;
						break;
					}
					printf("Hubo algun error, vuelvo al menu\n\n");
					break;


				//----CALCULO DE COSTOS SEGUN DESEA EL USUARIO----
				case 2:
					if(flagVueloCargado)
					{
						//---------CALCULO DE PRECIOS--------
						calcularCostos(latamPrecio, kilometros, BTC_Value, &latamPrecioDebito, &latamPrecioCredito, &latamPrecioBTC, &latamPrecioUnitario, precioMIN, precioMAX);
						calcularCostos(aerolineasPrecio, kilometros, BTC_Value, &aerolineasPrecioDebito, &aerolineasPrecioCredito, &aerolineasPrecioBTC, &aerolineasPrecioUnitario,precioMIN, precioMAX);

						//---------MOSTAR PRECIO UNITARIO-----
						mostrarPrecioV2(latamPrecioUnitario, aerolineasPrecioUnitario, "Precios unitarios\n");


						//---------DIFERENCIAS DE PRECIO-------
						/*
						if(calcularMayor(aerolineasPrecio, latamPrecio, &precioVueloCaro, &precioVueloBarato, "No hay diferencia de precios\n\n") == 0)
						{
							calcularDiferencia(precioVueloCaro, precioVueloBarato, &diferencia);
							printf("La diferencia de precio es de: $%.2f\n\n",diferencia);
						}
						*/

						calcularDiferenciaV2(aerolineasPrecioDebito, latamPrecioDebito, "La diferencia de precio es de: ", "No hay diferencia", &diferencia);
						flagVuelosCalculados = 1;
					}
					else
					{
						printf("No hay ningun vuelo cargado, vuelvo al menu\n");
					}
					break;


				//----INFORME DE RESULTADOS----
				case 3:
					if(flagVueloCargado)
					{
						if(flagVuelosCalculados)
						{
							mostrarPrecioV4(aerolineasPrecio, aerolineasPrecioDebito, aerolineasPrecioCredito, aerolineasPrecioBTC, aerolineasPrecioUnitario, latamPrecio, latamPrecioDebito, latamPrecioCredito, latamPrecioBTC, latamPrecioUnitario, kilometros);
							calcularDiferenciaV2(aerolineasPrecioDebito, latamPrecioDebito, "La diferencia de precio es de: ", "No hay diferencia", &diferencia);
						}
						else
						{
							printf("Error, no calculaste los precios, vuelvo al menu\n");
						}
					}
					else
					{
						printf("Error, no cargaste ningun vuelo, vuelvo al menu\n");
					}
					break;


				//--------CARGA FORZADA DE DATOS--------
				case 4:
					//----HARDCODEO DE DATOS----
					kilometros = 7090;
					aerolineasPrecio = 1335000.66;
					latamPrecio = 1350000.76;


					//----CALCULO DE IMPORTES----
					calcularCostos(latamPrecio, kilometros, BTC_Value, &latamPrecioDebito, &latamPrecioCredito, &latamPrecioBTC, &latamPrecioUnitario, precioMIN, precioMAX);
					calcularCostos(aerolineasPrecio, kilometros, BTC_Value, &aerolineasPrecioDebito, &aerolineasPrecioCredito, &aerolineasPrecioBTC, &aerolineasPrecioUnitario, precioMIN, precioMAX);


					//----INFORME DE RESULTADOS----
					mostrarPrecioV4(aerolineasPrecio, aerolineasPrecioDebito, aerolineasPrecioCredito, aerolineasPrecioBTC, aerolineasPrecioUnitario, latamPrecio, latamPrecioDebito, latamPrecioCredito, latamPrecioBTC, latamPrecioUnitario, kilometros);


					//---------DIFERENCIAS DE PRECIO-------
					calcularDiferenciaV2(aerolineasPrecioDebito, latamPrecioDebito, "La diferencia de precio es de: ", "No hay diferencia", &diferencia);
					break;
			}//------SWITCH------
		}
	}
	while(opcion != 5);
	return EXIT_SUCCESS;
}
