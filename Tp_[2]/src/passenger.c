/*
 * passenger.c
 *
 *  Created on: 26 Apr 2022
 *      Author: gonzr
 */
#include "passenger.h"
#define PASSENGER_AUX_LEN 5


//--------------------Generador de ID's--------------
static int idAutoIncremental = 1000;
static int pass_generateID();
/// @fn int pass_generateID()
/// @brief genera un id en base a un contador
///
/// @return retorna el id
static int pass_generateID()
{
	return idAutoIncremental++;
}
//--------------------Generador de ID's--------------





/// @fn int prod_InitArray(Passenger array[], int length)
/// @brief Initiates the array changing the member isEmpty to 1 (TRUE)
///
/// @param array Pointer to array of passengers
/// @param length Length of the array
/// @return -1 length minor to one, -2 NULL pointer
int pass_InitPassengers(Passenger array[], int length)
{
	int ret = -1;
	int i;
	if(array != NULL)
	{
		if(length > 0)
		{
			ret = 0;
			for(i=0; i<length; i++)
			{
				array[i].isEmpty = 1;
			}
		}
		else
		{
			ret = -1; //length minor to one
		}
	}
	else
	{
		ret = -2; //NULL pointer
	}
	return ret;
}

/// @fn int pass_getEmptyIndex(Passenger* array, int length)
/// @brief	looks for an empty space in the array
///
/// @param array pointer to array
/// @param length array length
/// @return -1 no free space; -2 NULL array; -3 length minor to 1
int pass_getEmptyIndex(Passenger* array, int length)
{
	int ret = -1; //NO Space
	if(array != NULL)
	{
		if(length>0)
		{
			int i;
			for(i=0; i<length; i++)
			{
				if(array[i].isEmpty == LIBRE)
				{
					ret = i;
					break;
				}
			}
		}
		else
		{
			ret = -3; // ERROR, lenght menor a 1
		}
	}
	else
	{
		ret = -2; // ERROR, array es nulo
	}
	return ret;
}

/// @fn void pass_printOne(Passenger)
/// @brief prints just ONE Passenger
///
/// @param passenger pointer to
void pass_printOne(Passenger passenger)
{
//  16           16          04          19                  20                   18
//NOMBRE     apellido        ID    CODIGO DE VUELO    TIPO DE PASAJERO     ESTADO DE VUELO
	printf("|%-16s|%-16s|%4d|%-19s"
	,passenger.name,passenger.surname,passenger.id,passenger.flyCode);
	switch(passenger.passengerType)
	{
		char tipoPasajero[20];
		case 1:
			strncpy(tipoPasajero,"Clase turista",20);
			printf("|%-20s",tipoPasajero);
			break;
		case 2:
			strncpy(tipoPasajero,"Clase ejecutiva",20);
			printf("|%-20s",tipoPasajero);
			break;
		case 3:
			strncpy(tipoPasajero,"Clase premium",20);
			printf("|%-20s",tipoPasajero);
			break;
	}

	switch(passenger.flightStatus)
	{
		char estadoVuelo[18];
		case 0:
			strncpy(estadoVuelo,"INACTIVO",18);
			printf("|%-18s|\n",estadoVuelo);
			break;
		case 1:
			strncpy(estadoVuelo,"ACTIVO",18);
			printf("|%-18s|\n",estadoVuelo);
			break;
	}
}
void encabezadoTabla(void)
{

	printf("+----------------+----------------+----+-------------------+--------------------+------------------|\n");
	printf("|     NOMBRE     |    APELLIDO    | ID |  CODIGO DE VUELO  |  TIPO DE PASAJERO  | ESTADO DE VUELO  |\n");
	printf("+----------------+----------------+----+-------------------+--------------------+------------------|\n");
}
void pieTabla(void)
{
	printf("+----------------+----------------+----+-------------------+--------------------+------------------|\n");
}


/// @fn int pass_printByStatus(Passenger*, int, int)
/// @brief prints data of the struct array by status of member isEmpty
///
/// @param list pointer to array
/// @param length array length
/// @param status value of the member isEmpty
/// @return -1 no match between status and search; -2 NULL array; -3 length minor to 1; 0 SUCCES
int pass_printByStatus(Passenger* list, int length, int status)
{
	int ret = -1; //no match

	if(list != NULL)
	{
		if(length > 0)
		{
			encabezadoTabla();

			int i;
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == status)
				{
					pass_printOne(list[i]);
					ret = 0;
				}
			}
			pieTabla();

		}
		else
		{
			ret = -3; //la longitud de la lista es menor a 1
		}
	}
	else
	{
		ret = -2; //La lista vino null
	}
	return ret;
}

/// @fn int pass_altaPassengerV2(Passenger*, int)
/// @brief Da de alta un pasajero en un lugar de la lista que se encuentre vacio
///
/// @param list puntero a array
/// @param length longitud del array
/// @return
int pass_altaPassengerV2(Passenger* list, int length)
{
	int ret = -1; //no FREE SPACE
	int emptyIndex;
	emptyIndex = pass_getEmptyIndex(list, length);
	Passenger aux;

	if(emptyIndex >= 0)
	{
		aux = pass_cargarPassenger();
		pass_addPassenger(list, length, aux.id, aux.name, aux.surname
		,aux.price, aux.passengerType, aux.flyCode);
	}
	return ret;
}


/// @fn int pass_addPassenger(Passenger*, int, int, char*, char*, float, int, char*)
/// @brief copies data from the Passenger AUX to the actual empty position of the list of passengers
///
/// @param list list of passengers
/// @param length length of the list
/// @param id pointer to AuxID
/// @param name pointer to AuxName
/// @param surname pointer to AuxSurname
/// @param price pointer to AuxPrice
/// @param typePassenger pointer to AuxTypePassenger
/// @param flycode pointer to AuxFlyCode
/// @return -1 no FREE SPACE // 0 SUCCES
int pass_addPassenger(Passenger* list, int length, int id, char* name, char* surname
				, float price, int typePassenger, char* flycode)
{
	int ret = -1; //no FREE SPACE
	int emptyIndex;
	emptyIndex = pass_getEmptyIndex(list, length);
	if(emptyIndex >= 0)
	{
		strncpy(list[emptyIndex].name,name,NAME_LEN);
		strncpy(list[emptyIndex].surname,surname,SURNAME_LEN);
		strncpy(list[emptyIndex].flyCode,flycode,FLYCODE_LEN);
		list[emptyIndex].id = id;
		list[emptyIndex].price = price;
		list[emptyIndex].passengerType = typePassenger;
		list[emptyIndex].isEmpty = OCUPADO;

		//list[emptyIndex].flyCode = flycode;
		//list[emptyIndex].name = name;
		//list[emptyIndex].surname = surname;

		// NOTAR QUE FALTA COPIAR FLIGHT STATUS ya que en los parametros que tenian la f(x)
		//que mostraban en el enunciado no estaba sligth status

		ret = 0;
	}
	return ret;
}

/// @fn Passenger pass_cargarPassenger(void)
/// @brief carga los datos en un auxiliar y pregunta si desea cargar los datos
///ESTE ES EL QUE TENDRIA QUE CAMBIAR PARA EL EXAMEN
/// @return retorna un passenger de tipo auxiliar con id y isempty ya cargados si salio todo OK
Passenger pass_cargarPassenger (void)
{
	Passenger passengerAux;

	if( utn_getNombre(passengerAux.name, NAME_LEN, "Ingrese el nombre del pasajero\n", "ERROR\n", 2) == 0 &&
		utn_getNombre(passengerAux.surname, SURNAME_LEN, "Ingrese el apellido\n", "ERROR\n", 2) == 0 &&
		utn_getFoat(&passengerAux.price, "Ingrese el precio del vuelo\n", "ERROR\n", 10, 1000, 2) == 0 &&
		utn_getNombre(passengerAux.flyCode, FLYCODE_LEN, "Ingrese el codigo de vuelo de 10 chars\n", "ERROR\n", 2) == 0 &&
		utn_getNumero(&passengerAux.passengerType, "Ingrese el tipo de pasajero (0 - 5)\n", "ERROR\n", 0, 5, 2) == 0 &&
		utn_getNumero(&passengerAux.flightStatus, "Ingrese el estado del vuelo (0 - 5)\n", "ERROR\n", 0, 5, 2) == 0
		)
	{
		printf("Estos son los datos cargados:\n");
		pass_printOne(passengerAux);

		if(validateExit_YN("Confirma? Y/N\n", "ERROR, revise las opciones\n", 2) == 1)
		{
			passengerAux.id = pass_generateID();
			passengerAux.isEmpty = OCUPADO;
		}
	}
	else
	{
		printf("Hubo muchos errores, vuelvo al menu, saludos\n\n");
	}
	return passengerAux;
}


int pass_removePassenger(Passenger* list, int length, int id)
{
	int ret = -1;
	int indexBaja;


	indexBaja = pass_findPassengerById(list, length, id);

	if(indexBaja >= 0)
	{
		if(validateExit_YN("Estas seguro de dar de baja?? Y/N\n", "ERROR, revise opciones\n", 2) == 1)
		{
			list[indexBaja].isEmpty = LIBRE;
			ret = 0; //success
		}
	}
	else
	{
		ret = -3; // error al encontrar el index del ID
	}

	return ret;
}

/// @fn int pass_findPassengerById(Passenger*, int)
/// @brief pide el ID de un pasajero y retorna en que posicion del array se encuentra
///
/// @param list array de pasajeros
/// @param length longitud del mismo
/// @return el indice en el que se encuentra ese ID o errores
int pass_findPassengerById(Passenger* list, int length, int id)
{
	int ret = -1; // lista NULL

	if(list != NULL)
	{
		if(length > 0)
		{
			int i;
			for(i=0; i<length; i++)
			{
				if(id == list[i].id)
				{
					if(list[i].isEmpty == OCUPADO)
					{
						ret = i; // retorno el indice en el que se encuentra ese ID
						break;
					}
					else
					{
						ret = -5; //HUBO COINCIDENCIA PERO el pasajero no estaba ocupado
					}
				}
				else
				{
					ret = -4; //no hubo coincidencia entre el id ingresado y los que habia disponibles
				}
			}

		}
		else
		{
			ret = -2; // length menor a
		}
	}
	return ret;
}

int pass_modifyPassenger(Passenger* list, int length)
{
	int ret = -1; //error en print by status (validaciones de length y list)
	int indexModificacion;
	int idAux;
	Passenger passengerAux;

	//no hago validaciones de list o length por que ya las tiene printByStatus
	if(pass_printByStatus(list, length, OCUPADO) == 0)
	{
		if(utn_getNumero(&idAux, "Ingrese el ID del pasajero que desea modificar\n"
		,"ERROR\n", 1000, 3000, 2) == 0)
		{
			indexModificacion = pass_findPassengerById(list, length, idAux);
			if(indexModificacion >= 0)
			{
				passengerAux = list[indexModificacion];
				pass_passengerModifier(&passengerAux);
				if(validateExit_YN("Desea guardar los cambios? Y/N\n", "ERROR, revise las opciones\n", 2) == 1)
				{
					ret = 0;//se guardo el cambio
					list[indexModificacion] = passengerAux;
					printf("Los cambios han sido guardados\n");
				}
				else
				{
					//no guardo nada y salgo
				}
			}
			else
			{
				ret = -2; // error al obtener el numero
			}
		}
		else
		{
			ret = -3; //ERROR DE UTN GET NUM
		}

	}
	return ret;
}

void pass_passengerModifier(Passenger* aux)
{
	int memberToModify;
	do
	{
		if(utn_getNumero(&memberToModify, "Que campo desea modificar?\n"
		"1)Nombre\n"
		"2)Apellido\n"
		"3)Precio\n"
		"4)Codigo de vuelo\n"
		"5)Tipo de pasajero\n"
		"6)Ver modificaciones\n"
		"7)Salir y guardar\n"
		,"ERROR, revise las opciones\n", 1, 7, 2) == 0)
		{
			switch(memberToModify)
			{
			case 1:
				if(utn_getNombre(aux->name, NAME_LEN, "Ingrese el nuevo nombre\n"
				,"ERROR, reintente\n", 2) == 0)
				{
					printf("El nombre ha sido cambiado\n");
				}
				else
				{
					printf("Hubo un error, vuelvo al menu\n");
				}
				break;
			case 2:
				if(utn_getNombre(aux->surname, SURNAME_LEN, "Ingrese el nuevo apellido\n"
				,"ERROR, reintente\n", 2) == 0)
				{
					printf("El apellido ha sido cambiado\n");
				}
				else
				{
					printf("Hubo un error, vuelvo al menu\n");
				}
				break;
			case 3:
				if(utn_getFoat(&aux->price, "Ingrese el nuevo precio del vuelo\n"
				,"ERROR, reintente\n", 10, 1000, 2) == 0)
				{
					printf("El precio ha sido cambiado\n");
				}
				else
				{
					printf("Hubo un error, vuelvo al menu\n");
				}
				break;
			case 4:
				if(utn_getNombre(aux->flyCode, FLYCODE_LEN, "Ingrese el nuevo codigo de vuelo de 10 chars\n"
				,"ERROR\n", 2) == 0)
				{
					printf("El codigo de vuelo ha sido cambiado\n");
				}
				else
				{
					printf("Hubo un error, vuelvo al menu\n");
				}
				break;
			case 5:
				if(utn_getNumero(&aux->passengerType, "Ingrese el nuevo tipo de pasajero (0 - 5)\n"
				,"ERROR\n", 0, 5, 2) == 0)
				{
					printf("El tipo de pasajero ha sido cambiado\n");
				}
				else
				{
					printf("Hubo un error, vuelvo al menu\n");
				}
				break;
			case 6:
				pass_printOne(*aux);
				break;
			}
		}
	}while(memberToModify != 7);
}

int pass_cargaForzada(Passenger* list, int length)
{
	int ret = -1;
	Passenger passAux[PASSENGER_AUX_LEN];

	if(list != NULL)
	{
		if(length >0)
		{

			strncpy(passAux[0].name,"Gonzalo",NAME_LEN);
			strncpy(passAux[0].surname,"Rodriguez",SURNAME_LEN);
			strncpy(passAux[0].flyCode,"aaaaaaaaa",FLYCODE_LEN);
			passAux[0].id = 1000;
			passAux[0].price = 100;
			passAux[0].passengerType = 2;
			passAux[0].flightStatus = 0; //INACTIVO
			passAux[0].isEmpty = OCUPADO;

			strncpy(passAux[1].name,"Agostina",NAME_LEN);
			strncpy(passAux[1].surname,"Anguera",SURNAME_LEN);
			strncpy(passAux[1].flyCode,"bbbbbbbbb",FLYCODE_LEN);
			passAux[1].id = 1001;
			passAux[1].price = 101;
			passAux[1].passengerType = 1;
			passAux[1].flightStatus = 1;//ACTIVO
			passAux[1].isEmpty = OCUPADO;

			strncpy(passAux[2].name,"Ivan",NAME_LEN);
			strncpy(passAux[2].surname,"Sosa",SURNAME_LEN);
			strncpy(passAux[2].flyCode,"ccccccc",FLYCODE_LEN);
			passAux[2].id = 1002;
			passAux[2].price = 102;
			passAux[2].passengerType = 2;
			passAux[2].flightStatus = 0; //INACTIVO
			passAux[2].isEmpty = OCUPADO;

			strncpy(passAux[3].name,"Lautaro",NAME_LEN);
			strncpy(passAux[3].surname,"Walsh",SURNAME_LEN);
			strncpy(passAux[3].flyCode,"ddddddd",FLYCODE_LEN);
			passAux[3].id = 1003;
			passAux[3].price = 103;
			passAux[3].passengerType = 3;
			passAux[3].flightStatus = 0; //INACTIVO
			passAux[3].isEmpty = OCUPADO;

			strncpy(passAux[4].name,"Micaela",NAME_LEN);
			strncpy(passAux[4].surname,"Bogado",SURNAME_LEN);
			strncpy(passAux[4].flyCode,"eeeeeee",FLYCODE_LEN);
			passAux[4].id = 1004;
			passAux[4].price = 104;
			passAux[4].passengerType = 1;
			passAux[4].flightStatus = 1;//ACTIVO
			passAux[4].isEmpty = OCUPADO;

			int i;
			for(i=0; i<PASSENGER_AUX_LEN; i++)
			{
				list[i] = passAux[i];
			}
		}
		else
		{
			ret = -2; // LENGTH MENOR A 0
		}
	}

	return ret;
}

int pass_sortPassengers(Passenger* list, int length, int order)
{
	int ret = -1; //NULL LIST
	if(list != NULL)
	{
		if(length > 0)
		{

			switch(order)
			{
			//1 = UP     0 = DOWN
			case 1:
				if(pass_ascendingBubbleSorting(list, length) == 0)
				{
					printf("Se ha ordenado el array de forma ascendente\n");
					ret = 0;//SUCCESS
				}
				else
				{
					printf("Huno algun error\n");
					ret = -3; //fallo el ordenamiento ascendente
				}
				break;
			case 0:
				if(pass_descendingBubbleSorting(list, length) == 0)
				{
					printf("Se ha ordenado el array de forma descendente\n");
					ret = 0;//SUCCESS
				}
				else
				{
					printf("Huno algun error\n");
					ret = -4; //fallo el ordenamiento descendente
				}
				break;
			}
		}
		else
		{
			ret = -2; // LENGTH MENOR A 0
		}
	}
	return ret;
}

int pass_ascendingBubbleSorting(Passenger* list, int length)
{
	int ret = -1; //NULL LIST
	int flagSwap;
	int auxiliarDeComparacion;
	Passenger aux;
	Passenger arrayCopy[length];

	if(list != NULL)
	{
		if(length > 0)
		{
			if(pass_InitPassengers(arrayCopy, length) == 0)
			{
				if(pass_copyArray(list, arrayCopy, length) == 0)
				{
					do
					{
						flagSwap = 0;
						int i;
						//limite -1 para que no compare contra la nada
						for(i=0; i<length-1; i++)
						{
							//de todas formas es redundante porque solo copie lo que estaba ocupado
							//pregunto si esta vacio itero una vez mas asi no comparo de mas
							if(arrayCopy[i].isEmpty == 1 || arrayCopy[i+1].isEmpty == 1)
							{
								continue;
							}
							auxiliarDeComparacion = strncmp(arrayCopy[i].surname,arrayCopy[i+1].surname,SURNAME_LEN);
							//orden alfanumerico ascendente
							//si hay 2 pasajeros iguales ordena por tipo de pasajeros
							if( auxiliarDeComparacion > 0 ||
							(	auxiliarDeComparacion == 0 &&
								arrayCopy[i].passengerType > arrayCopy[i+1].passengerType))
							{
								flagSwap = 1;
								aux = arrayCopy[i];
								arrayCopy[i] = arrayCopy[i+1];
								arrayCopy[i+1] = aux;
							}
						}
					}
					while(flagSwap);
					if(pass_printByStatus(arrayCopy, length, OCUPADO) == 0)
					{
						ret = 0;//SUCCESS
					}
					else
					{
						ret = -5; //Fallo la impresion
					}
				}
				else
				{
					ret = -4; // fallo la copia del array
				}
			}
			else
			{
				ret = -3; //fallo la inicializacion
			}
		}
		else
		{
			ret = -2; //length minor to 0
		}
	}
	return ret;
}

int pass_descendingBubbleSorting(Passenger* list, int length)
{
	int ret = -1; //NULL LIST
	int flagSwap;
	int auxiliarDeComparacion;
	Passenger aux;
	Passenger arrayCopy[length];

	if(list != NULL)
	{
		if(length > 0)
		{
			if(pass_InitPassengers(arrayCopy, length) == 0)
			{
				if(pass_copyArray(list, arrayCopy, length) == 0)
				{
					do
					{
						flagSwap = 0;
						int i;
						//limite -1 para que no compare contra la nada
						for(i=0; i<length-1; i++)
						{

							//pregunto si esta vacio itero una vez mas asi no comparo de mas
							//de todas formas es redundante porque solo copie lo que estaba ocupado
							if(arrayCopy[i].isEmpty == 1 || arrayCopy[i+1].isEmpty == 1)
							{
								continue;
							}
							auxiliarDeComparacion = strncmp(arrayCopy[i].surname,arrayCopy[i+1].surname,SURNAME_LEN);
							//orden alfanumerico ascendente
							//si hay 2 pasajeros iguales ordena por tipo de pasajeros
							if( auxiliarDeComparacion < 0 ||
							(	auxiliarDeComparacion == 0 &&
								arrayCopy[i].passengerType < arrayCopy[i+1].passengerType))
							{
								flagSwap = 1;
								aux = arrayCopy[i];
								arrayCopy[i] = arrayCopy[i+1];
								arrayCopy[i+1] = aux;
							}
						}
					}
					while(flagSwap);
					if(pass_printByStatus(arrayCopy, length, OCUPADO) == 0)
					{
						ret = 0;//SUCCESS
					}
					else
					{
						ret = -5; //Fallo la impresion
					}
				}
				else
				{
					ret = -4; // fallo la copia del array
				}
			}
			else
			{
				ret = -3; //fallo la inicializacion
			}
		}
		else
		{
			ret = -2; //length minor to 0
		}
	}
	return ret;
}

/// @fn int pass_copyArray(Passenger*, Passenger*, int)
/// @brief toma un array de struct y lo copia en un auxiliar
///
/// @param list puntero al array original
/// @param listCopy puntero al array de copia
/// @param length longitud de los array
/// @return -1 NULL list / -2 length invalida / 0 SUCCESS
int pass_copyArray(Passenger* list, Passenger* listCopy, int length)
{
	int ret = -1; //NULL LIST
	int i;

	if(list != NULL)
	{
		if(length > 0)
		{
			ret = 0; //SUCCES
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == OCUPADO)
				{
					listCopy[i] = list[i];
				}
			}
		}
		else
		{
			ret = -2;//longitud menor a 0
		}
	}
	return ret;
}

/// @fn int pass_calAveragePrice(float*, Passenger*, int)
/// @brief acumula los precios de los vuelos de los pasajeros y calcula un promedio
///
/// @param pResultado
/// @param list
/// @param length
/// @return -1 pResultado NULL // -2 lista NULL // -3 length incorrecta // -4 ERROR de la funcion utn get num
/// 0 SUCCESS
int pass_calcAveragePrice(float* pResultado, Passenger* list, int length)
{
	int ret = -1;// puntero NULL de pResultado
	int contador = 0;
	int acumulador = 0;
	int i;

	if(pResultado != NULL)
	{
		if(list != NULL)
		{
			if(length > 0)
			{
				for(i=0; i<length; i++)
				{
					if(list[i].isEmpty == 0)
					{
						acumulador = acumulador + list[i].price;
						contador++;
					}
				}
				if(utn_calcularPromedio(pResultado, acumulador, contador) == 0)
				{
					ret = 0;
				}
				else
				{
					ret = -4; //ERROR de la funcion utn get num
				}
			}
			else
			{
				ret = -3; //length incorrecta
			}
		}
		else
		{
			ret = -2; // lista NUL
		}
	}
	return ret;
}


/// @fn int pass_calcTotalPrices(float*, Passenger*, int)
/// @brief acumula los precios de los vuelos de los pasajeros y suma sus valores
///
/// @param pResultado puntero a direccion de memoria se almacenara el resultado
/// @param list array de struct
/// @param length longitud del array
/// @return -1 pResultado NULL // -2 lista NULL // -3 length incorrecta //
/// 0 SUCCESS
int pass_calcTotalPrices(float* pResultado, Passenger* list, int length)
{
	int ret = -1;// puntero NULL de pResultado
	int acumulador = 0;
	int i;

	if(pResultado != NULL)
	{
		if(list != NULL)
		{
			if(length > 0)
			{
				for(i=0; i<length; i++)
				{
					if(list[i].isEmpty == 0)
					{
						acumulador = acumulador + list[i].price;

					}
				}
				*pResultado = acumulador;
				ret = 0;

			}
			else
			{
				ret = -3; //length incorrecta
			}
		}
		else
		{
			ret = -2; // lista NUL
		}
	}
	return ret;
}
/// @fn int pass_calcSuperiorAlPromedio(Passenger*, int, float, float)
/// @brief calcula cuantos pasajeros superan el precio del promedio de pasajes
///
/// @param list lista a analizar
/// @param length longitud de la lista
/// @param promedio promedio de pasajes
/// @return -1 error, lista nula / -2 error de length / <0 SUCCES
int pass_calcSuperiorAlPromedio(Passenger* list, int length, float promedio)
{
	int ret = -1; //error NULL ARRAY
	int contador = 0;
	int i;
	if(list != NULL)
	{
		if(length>0)
		{

			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == 0 && (list[i].price > promedio))
				{
					contador++;
				}
			}
			ret = contador; //SUCCES
		}
		else
		{
			ret = -2; //ERROR DE LENGTH
		}
	}
	return ret;
}


void informes(Passenger* list, int length)
{
	pass_printByStatus(list, PASSENGER_LEN, OCUPADO);

	//-------ORDENAR POR APELLIDO Y TIPO-------
	int orden;
	if(utn_getNumero(&orden, "Ingrese '1' para ordenar alfabeticamente de forma ascendente, o '0' para descendente\n"
	,"ERROR\n", 0, 1, 2) == 0)
	{
		pass_sortPassengers(list, PASSENGER_LEN, orden);
	}
	else
	{
		printf("No se puede ordenar\n");
	}



	//-------CALCULO DEL TOTAL DE PRECIOS -------
	float total;
	pass_calcTotalPrices(&total, list, length);
	if(total>0)
	{
		printf("El total de los precios es de: %f\n",total);
	}



	//-------CALCULO DEL PROMEDIO DE PRECIOS -------
	float promedio;
	pass_calcAveragePrice(&promedio,list,length);
	if(promedio>0)
	{
		printf("El promedio de precios es de: %f\n",promedio);
	}

	//-------CALCULO DEL PRECIOS SUPERIORES AL PROMEDIO -------
	int contadorPreciosSperioresAlPromedio;
	contadorPreciosSperioresAlPromedio = pass_calcSuperiorAlPromedio(list, length, promedio);
	if(contadorPreciosSperioresAlPromedio >= 0)
	{
		printf("La cantidad de vuelos con precio superior al promedio es de: %d\n\n",contadorPreciosSperioresAlPromedio);
	}
	else
	{
		//
	}
}











