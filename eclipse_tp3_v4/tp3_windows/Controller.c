#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1; //ERROR path null
	FILE* pPassengersCSV;
	if(path != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			pPassengersCSV = fopen(path,"r");
			if(pPassengersCSV != NULL)
			{
				//si el parser me devolvio 0 ahi recien tengo SUCCESS
				if(parser_PassengerFromText(pPassengersCSV, pArrayListPassenger) == 0)
				{
					ret = 0;//SUCCESS
				}
				else
				{
					ret = -4;//ERROR del parser
				}
			}
			else
			{
				ret = -3;//ERROR al abrir el archivo
			}
		}
		else
		{
			ret = -2;//lista de pasajeros nula
		}

	}

    return ret;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;//ERROR path
	if(path != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			FILE* pPassengerBin;
			pPassengerBin = fopen(path, "r+b");
			if(pPassengerBin != NULL)
			{
				Passenger* pPassengerAux;
				int qty = 0;
				int contador = 0;
				do
				{
					pPassengerAux = Passenger_new();
					qty = fread(pPassengerAux ,sizeof(Passenger),1,pPassengerBin);


					if(qty == 1)
					{
						contador = contador + qty;
						ll_add(pArrayListPassenger, pPassengerAux);
					}
					else
					{
						Passenger_delete(pPassengerAux);
					}
				}
				while(qty == 1);
				printf("Se han cargado %d registros del archivo 'Passengers.bin'\n",contador);
				fclose(pPassengerBin);
				ret = 0;//SUCCESS
			}
			else
			{
				ret = -3;//ERROR de fopen
			}
		}
		else
		{
			ret = -2;//ERROR linked list NULL
		}
	}
    return ret;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int ret = -1;//ERROR LinkedList NULL
	int flagSwap;
	if(pArrayListPassenger  != NULL)
	{


		int orden;
		if(utn_getNumero(&orden, "1)Ascendente\n2)Descendente\n3)Cancelar\n", "ERROR", 1, 3, 2) == 0)
		{
			switch(orden)
			{
			case 1:
				passenger_ordenar(pArrayListPassenger,passenger_ordenarAscendentemente);
				break;

			case 2:
				passenger_ordenar(pArrayListPassenger,passenger_ordenarDescendentemente);
				break;
			case 3:
			break;
			}
			ret = 0;//SUCCESS
		}
	}
    return ret;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;//NULL path
	if(path != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			FILE* pPassengerCSV;
			pPassengerCSV = fopen(path,"w");
			int contadorExitos = 0;
			int contador;
			int contadorErroneos = 0;
			if(pPassengerCSV != NULL)
			{
				int idAux;
				char nameAux[NOMBRE_LEN];
				char apellidoAux[NOMBRE_LEN];
				float precioAux;
				char flycodeAux [10];
				char typePassengerAux[20];
				char flightSatus[20];
				Passenger* pPassengerAux;

				for(contador=0; contador<ll_len(pArrayListPassenger); contador++)
				{
					pPassengerAux = ll_get(pArrayListPassenger, contador);

					if(	Passenger_getId(pPassengerAux, &idAux) == 0 &&
						Passenger_getNombre(pPassengerAux, nameAux) == 0 &&
						Passenger_getApellido(pPassengerAux, apellidoAux) == 0 &&
						Passenger_getPrecio(pPassengerAux, &precioAux) == 0 &&
						Passenger_getCodigoVuelo(pPassengerAux, flycodeAux) == 0 &&
						Passenger_getFlightSatusParseado(pPassengerAux, flightSatus) == 0 &&
						Passenger_getTypePassengerParseado(pPassengerAux, typePassengerAux) == 0)

					{
						contadorExitos++;
						if(contadorExitos == 1)
						{
							fprintf(pPassengerCSV,"id,name,surname,price,flycode,typePassenger,statusFlight\n");
						}
						fprintf(pPassengerCSV,"%d,%s,%s,%f,%s,%s,%s\n"
								,idAux,nameAux,apellidoAux,precioAux,flycodeAux,typePassengerAux,flightSatus);
					}

					else
					{
						contadorErroneos++;
					}


				}
				printf("Lei %d registros de la memoria\n",contador);
				if(contadorExitos > 0)
				{
					printf("Guarde con exito %d registros en forma CSV\n"
							"La ruta del archivo guardado es: %s\n",contadorExitos,path);
				}

				if(contadorErroneos>0)
				{
					printf("Hubo %d registros que tuvierorn errores y no fueron cargados, revise\n\n",contadorErroneos);
				}


				fclose(pPassengerCSV);
				ret = 0; //SUCCESS
			}
			else
			{
				ret = -3;//ERROR de fopen, revise ruta
			}
		}
		else
		{
			ret = -2;//ERROR linked list NULL
		}
	}
	return ret;;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret = -1;//ERROR path NULL
	if(path != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			FILE* pPassengerBin;
			pPassengerBin = fopen(path,"wb");
			if(pPassengerBin != NULL)
			{
				Passenger* pAux;
//				Passenger pAux2;
				int contador = 0;
//				int contadorExito = 0;
//				int contadorFail = 0;
				do
				{
					pAux = ll_get(pArrayListPassenger,contador);

					fwrite(pAux,sizeof(Passenger),1,pPassengerBin);
					contador++;
				}
				while(contador < ll_len(pArrayListPassenger));
				printf("Guarde %d registros en forma binaria\n"
						"La ruta del archivo guardado es: %s\n\n",contador,path);
				fclose(pPassengerBin);
			}
			else
			{
				ret = -3;//ERROR de fopen
			}
		}
		else
		{
			ret = -2;//ERROR parray NULL
		}
	}
    return ret;
}

