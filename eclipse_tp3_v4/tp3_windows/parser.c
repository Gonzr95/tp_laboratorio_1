#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ret = -1;//ERROR PFILE NULL
	int contador = 0;
	int contadorExitosos = 0;
	int contadorErroneo = 0;
//	int arrayErroneos[1000];
//	int lastID;
	Passenger* passengerAux;
	if(pFile != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			do
			{
				ret = 0;//SUCCESS pude leer el file
				passengerAux = Passenger_new();
				char nombre[4096];
				char apellido[4096];
				char precio[4096];
				char id[4096];
				char tipoDePasajero[4096];
				char codigoDeVuelo[4096];
//				char statusFlight[256];
				char isEmpty[30];
				//Con el fgets puedo leer hasta encontrar la siguiente linea (\0)
				//luego voy separando los elemenots segun las comas
				//leer con formato es fscanf
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
						id,
						nombre,
						apellido,
						precio,
						codigoDeVuelo,
						tipoDePasajero,
						isEmpty
						) == 7)
				{
//					printf("%s, %s, %s, %s, %s, %s, %s\n"
//					,id,nombre,apellido, precio, codigoDeVuelo, tipoDePasajero, isEmpty);
					contador++;
					if( Passenger_setIdTxt(passengerAux, id) != 0 ||
						Passenger_setNombre(passengerAux, nombre)!= 0 ||
						Passenger_setApellido(passengerAux, apellido) != 0 ||
						Passenger_setPrecioTxt(passengerAux, precio) != 0 ||
						Passenger_setCodigoVuelo(passengerAux, codigoDeVuelo) != 0 ||
						Passenger_setTipoPasajeroTxt(passengerAux, tipoDePasajero) != 0 ||
						Passenger_setIsEmptyTxt(passengerAux, isEmpty) != 0 )
					{
//						arrayErroneos[contadorErroneo] = contador;
						contadorErroneo++;
					}
					else
					{
						ll_add(pArrayListPassenger, passengerAux);
						contadorExitosos++;

					}
					//guardar el ultimo ID en el ID autoincremental PREGUNTAR SOBRE ESTO
				}
				else
				{
					Passenger_delete(passengerAux);
					break; // ya no pude leer mas
				}
			}
			while( !feof(pFile));
			printf("\n\nSe han leido %d registros del archivo 'data.CSV'\n",contador);
			printf("Se han cargado %d registros de forma exitosa del archivo 'data.CSV'\n",contadorExitosos);
			printf("%d registros del archivo 'data.CSV' no hay podido ser cargados, revise los setters de nombre y apellido (puede que venga por ahi)\n",contadorErroneo);
		}
		else
		{
			ret = -2;//ERROR parrayListPassenger NULL
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
