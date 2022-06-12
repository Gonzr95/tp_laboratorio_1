/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"
#include "LinkedList.h"
static int passenger_BuscarUltimoIDCSV(char* path);
static int passenger_BuscarUltimoID(LinkedList* arrayPassajeros);
//--------------------Generador de ID's--------------
int pass_idAutoIncremental = 1000;
static int pass_generateID(LinkedList* arrayPassengers);
/// @fn int prod_generateID()
/// @brief genera un id en base a un contador
///
/// @return retorna el id
static int pass_generateID(LinkedList* arrayPassengers){
	int idAux1;
	idAux1 = passenger_BuscarUltimoID(arrayPassengers);
	int idAux2;
	idAux2 = passenger_BuscarUltimoIDCSV("D:\\Proyectos\\Eclipse\\Labo_1_2daParte\\eclipse_tp3_v4\\tp3_windows\\data.csv");
	if(idAux1 > idAux2) pass_idAutoIncremental = idAux1;
	else pass_idAutoIncremental = idAux2;

	return pass_idAutoIncremental++;
}
//--------------------Generador de ID's--------------

Passenger* Passenger_new(void){

	Passenger* pPassenger;
	pPassenger = (Passenger*)malloc(sizeof(Passenger) * 1 );

	if(pPassenger  != NULL){

		pPassenger->id = 0;
		pPassenger->nombre[0] = '\0';
		pPassenger->apellido[0] = '\0';
		pPassenger->precio = 0;
		pPassenger->tipoPasajero = 0;
		pPassenger->codigoVuelo[0] = '\0';
		pPassenger->isEmpty = 0;

		return pPassenger;
	}
	else{

		return pPassenger;
	}
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,int tipoPasajeroStr){
	Passenger* pPassenger;
	pPassenger = Passenger_new();


	return pPassenger;
}

void Passenger_delete(Passenger* this){

	if(this !=  NULL){

		free(this);
	}
}



//***************setters getters***************


int Passenger_setId(Passenger* this,int id)
{
	int ret = -1; //ERROR thiS NULL

	if(this != NULL)
	{
		if(id >= 1000)
		{
			this->id = id;
			ret = 0; //SUCCESS
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_setIdTxt(Passenger* this, char id[])
{
	int ret = -1; //ERROR thiS NULL

	if(this != NULL)
	{
		if(id != NULL)
		{
			this->id = atoi(id);
			ret = 0; //SUCCESS
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_getId(Passenger* this,int* id)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(id != NULL)
		{
			*id = this->id;
			ret = 0;//SUCCESS
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(nombre != NULL)
		{
			if(esNombre(nombre, NOMBRE_LEN) == 1)
			{
				strncpy(this->nombre,nombre,NOMBRE_LEN);

				ret = 0;//SUCCESS
			}
			else
			{
//				printf("El error de mierda venia por NOMBRE  LCDTM\n");
				ret = -3;//ERROR NO ES NOMBRE
			}
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(nombre != NULL)
		{
			if(esNombre(this->nombre, NOMBRE_LEN) == 1)
			{
				strncpy(nombre,this->nombre, NOMBRE_LEN);
				ret = 0;//SUCCESS
			}
			else
				ret = -3;//	ERROR no es nombre
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(apellido != NULL)
		{
			if(esNombre(apellido, NOMBRE_LEN) == 1)
			{

				strncpy(this->apellido,apellido,NOMBRE_LEN);
				ret = 0;//SUCCESS
			}
			else
			{
//				printf("El error de mierda venia por APELLIDO  LCDTM\n");
				ret = -3;//ERROR NO ES NOMBRE
			}
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(apellido != NULL)
		{
			if(esNombre(this->apellido, NOMBRE_LEN) == 1)
			{
				strncpy(apellido,this->apellido,NOMBRE_LEN);
				ret = 0;//SUCCESS
			}
			else
			{
				ret = -3;//ERROR NO ES NOMBRE
			}
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(codigoVuelo != NULL)
		{
			ret = 0;
			strncpy(this->codigoVuelo,codigoVuelo,10);
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(codigoVuelo != NULL)
		{
			ret = 0;
			strncpy(codigoVuelo,this->codigoVuelo,10);

		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}



int Passenger_getFlightSatusParseado(Passenger* this,char* flightStatus)
{
	int ret = -1;//ERROR
	if(this != NULL)
	{
		if(flightStatus != NULL)
		{
			if(Passenger_parseFlightStatus(this, flightStatus) == 0)
			{
				ret = 0; //SUCCESS
			}
			else
			{
				ret = -3;//ERROR
			}
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_getTypePassengerParseado(Passenger* this,char* typePassenger)
{
	int ret = -1;//ERROR
	if(this != NULL)
	{
		if(typePassenger != NULL)
		{
			if(Passenger_parseTypePassenger(this, typePassenger) == 0)
			{
				ret = 0;//SUCCESS
			}
			else
			{
				ret = -3;//ERROR
			}
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_parseFlightStatus(Passenger* this, char* flightStatus)
{
	int ret = -1;
	if(this != NULL)
	{
		if(flightStatus != NULL)
		{
			ret = 0;//SUCCESS
			switch(this->isEmpty)
			{
			case EN_HORARIO:
				strncpy(flightStatus,"En Horario",20);
				break;
			case ATERRIZADO:
				strncpy(flightStatus,"Aterrizado",20);
				break;
			case DEMORADO:
				strncpy(flightStatus,"Demorado",20);
				break;
			case EN_VUELO:
				strncpy(flightStatus,"En vuelo",20);
				break;
			}
		}
	}
	return ret;
}

int Passenger_parseTypePassenger(Passenger* this, char* typePassenger)
{
	int ret = -1;//ERROR this NULL
	if(this != NULL)
	{
		if(typePassenger != NULL)
		{
			ret = 0;
			switch(this->tipoPasajero)
				{
				case ECONOMY_CLASS:
					strncpy(typePassenger,"EconomyClass",20);
					break;
				case FIRST_CLASS:
					strncpy(typePassenger,"FirstClass",20);
					break;
				case EXECUTIVE_CLASS:
					strncpy(typePassenger,"ExecutiveClass",20);
					break;
				}
		}
		else
		{
			ret = -2;//ERROR type passenger NULL
		}
	}
	return ret;
}





int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		this->tipoPasajero = tipoPasajero;
		ret = 0;//SUCCESS
	}
	return ret;
}

int Passenger_setTipoPasajeroTxt(Passenger* this, char tipoDePasajero[])
{
	int ret = -1; //ERROR
	if(this != NULL)
	{
		if(tipoDePasajero != NULL)
		{

			if(strcmp(tipoDePasajero, "EconomyClass") == 0)
			{
				ret = 0;//SUCCESS
				this->tipoPasajero = ECONOMY_CLASS;
			}
			else
			{
				if(strcmp(tipoDePasajero, "FirstClass") == 0)
				{
					ret = 0;//SUCCESS
					this->tipoPasajero = FIRST_CLASS;
				}
				else
				{
					if(strcmp(tipoDePasajero, "ExecutiveClass") == 0)
					{
						ret = 0;//SUCCESS
						this->tipoPasajero = EXECUTIVE_CLASS;
					}
					else
					{
//						printf("No era ninguna de esas\n");
					}
				}

			}
//			this->tipoPasajero = atoi(tipoDePasajero);

		}
		else
		{
			ret = -2;//ERROR NULL
		}
	}
	return ret;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(tipoPasajero != NULL)
		{

			*tipoPasajero = this->tipoPasajero;
			ret = 0; //SUCCESS
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		this->precio = precio;
		ret = 0;//success
	}
	return ret;
}

int Passenger_setPrecioTxt(Passenger* this, char precio[])
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(precio != NULL)
		{

			this->precio = atof(precio);
			ret = 0;//success
		}
		else
		{
			ret = -2;//ERROR precio NULL
		}

	}
	return ret;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(precio != NULL)
		{
			ret = 0;
			*precio = this->precio;
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Passenger_setIsEmptyTxt(Passenger* this, char isEmpty[])
{
	int ret = -1; //ERROR thiS NULL

	if(this != NULL)
	{
		if(isEmpty != NULL)
		{
			if(strcmp(isEmpty, "En Horario") == 0)
			{
				ret = 0;//SUCCESS
				this->isEmpty = EN_HORARIO;
//				printf("[isEmpty] = %d\n",this->isEmpty);
			}
			else
			{

				if(strcmp(isEmpty, "Aterrizado") == 0)
				{
					ret = 0;//SUCCESS
					this->isEmpty = ATERRIZADO;
//					printf("[isEmpty] = %d\n",this->isEmpty);
				}
				else
				{
					if(strcmp(isEmpty, "Demorado") == 0)
					{
						ret = 0;//SUCCESS
						this->isEmpty = DEMORADO;
//						printf("[isEmpty] = %d\n",this->isEmpty);
					}
					else
					{
						if(strcmp(isEmpty, "En Vuelo") == 0)
						{
							ret = 0;
							this->isEmpty = EN_VUELO;
//							printf("[isEmpty] = %d\n",this->isEmpty);
						}
						else
						{
							laCadenaTiene(isEmpty, strlen(isEmpty));
//							printf("No era ninguna de esas ( Is Empty ) \n");
						}

					}
				}

			}
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

Passenger* Passenger_newConParametrosTxt(char nombre[], char apellido[], char precio[], char tipoDePasajero[], char codigoDeVuelo[], char id[], char isEmpty[])
{
	Passenger* pPassenger;
	pPassenger = Passenger_new();

	if(pPassenger != NULL)
	{

		if( Passenger_setApellido(pPassenger, apellido) != 0 ||
			Passenger_setNombre(pPassenger, nombre) != 0 ||
			Passenger_setPrecioTxt(pPassenger, precio) != 0 ||
			Passenger_setTipoPasajeroTxt(pPassenger, tipoDePasajero) != 0 ||
			Passenger_setCodigoVuelo(pPassenger, codigoDeVuelo) != 0 ||
			Passenger_setIdTxt(pPassenger, id) != 0 ||
			Passenger_setIsEmptyTxt(pPassenger, isEmpty) != 0)
		{
			Passenger_delete(pPassenger);
			pPassenger = NULL;
		}


	}

	return pPassenger;
}

int Passenger_alta(LinkedList* listaPasajeros)
{
	int ret = -1;//ERROR linked NULL
	if(listaPasajeros != NULL)
	{
		Passenger* passengerAux = Passenger_new();
		if(passengerAux != NULL)
		{
//			pido datos
			if(Passenger_pedirDatos(passengerAux, listaPasajeros) == 0)
			{
				ll_add(listaPasajeros, passengerAux);
				printf("Carga exitosa\n");
				ret = 0;//SUCCESS;
			}
		}
	}
	return ret;
}

int Passenger_pedirDatos(Passenger* pPassenger, LinkedList* arrayPassengers)
{
	int ret = -1; //ERROR null ppasenger
	if(pPassenger != NULL)
	{
//		pedido de datos
		if( utn_getNombre(pPassenger->nombre, NOMBRE_LEN, "Ingrese el nombre del pasajero\n", "ERROR\n", 2) == 0 &&
			utn_getNombre(pPassenger->apellido, NOMBRE_LEN, "Ingrese el apellido del pasajero\n", "RROR\n", 2) == 0 &&
			utn_getFloat(&pPassenger->precio, "Ingrse el precio\n", "ERROR\n", 10000, 1000000, 2) == 0 &&
			utn_getPassword(pPassenger->codigoVuelo, 7, "Ingrese el codigo de vuelo\n", "ERROR\n", 2) == 0 &&
			utn_getNumero(&pPassenger->tipoPasajero, "Presione:\n"
					"1)Para Economy Class\n"
					"2)Para First Class\n"
					"3)Para executive Class\n", "ERROR\n", 1, 3, 2) == 0 &&
			utn_getNumero(&pPassenger->isEmpty, "Presione:\n"
					"1)En horario\n"
					"2)Aterrizado\n"
					"3)Demorado\n"
					"4)En vuelo\n", "ERROR\n", 1, 4, 2) == 0)
		{

				pPassenger->id = pass_generateID(arrayPassengers);
				ret = 0;//SUCCESS
		}
		else
		{
			ret = -2;//ERROR de pedido de datos
		}

	}
	return ret;
}



void Passenger_encbezadoTabla(void)
{

	printf("+----+---------------+----------------+--------+-----------+-----------------+-----------------+\n");
	printf("| ID |     NOMBRE    |     APELLIDO   | PRECIO |  FLYCODE  |TIPO DE PASAJERO | ESTADO DE VUELO |\n");
	printf("+----+---------------+----------------+--------+-----------+-----------------+-----------------+\n");
}

void Passenger_pieTabla(void)
{
	printf("+----+---------------+----------------+--------+-----------+-----------------+-----------------+\n\n");
}

int Passenger_printOne(Passenger* this)
{
	int ret = -1; //error null this
	char clase[20];
	switch(this->tipoPasajero)
		{
		case ECONOMY_CLASS:
//			entreAca();
			strncpy(clase,"EconomyClass",20);
			break;
		case FIRST_CLASS:
//			entreAca();
			strncpy(clase,"FirstClass",20);
			break;
		case EXECUTIVE_CLASS:
//			entreAca();
			strncpy(clase,"ExecutiveClass",20);
			break;
		}


	char estado[20];
	switch(this->isEmpty)
	{
	case EN_HORARIO:
		strncpy(estado,"En Horario",20);
		break;
	case ATERRIZADO:
		strncpy(estado,"Aterrizado",20);
		break;
	case DEMORADO:
		strncpy(estado,"Demorado",20);
		break;
	case EN_VUELO:
		strncpy(estado,"En vuelo",20);
		break;

	}


	if(this != NULL)
	{
		printf("|%-4d|%-15s|%-16s|%-8.2f|%-11s|%-17s|%-17s|\n",
		this->id,this->nombre,this->apellido,this->precio,this->codigoVuelo,clase,estado);
//		printf("%s\n",clase);
//		printf("tipo de pasajero en int: %d\n",this->tipoPasajero);
//		printf("\n--El is empty es: %d--\n",this->isEmpty);
	}


	return ret;
}

int Passenger_printByStatus(LinkedList* passengersList, int status)
{
	int ret = -1;
	if(passengersList != NULL)
	{
		int linkedListLenght = ll_len(passengersList);
		if(linkedListLenght > 0)
		{
			Passenger_encbezadoTabla();
			for(int i=0; i<linkedListLenght; i++)
			{
				//traeme un puntero e imprimilo

				Passenger_printOne ( (Passenger*)ll_get( passengersList, i) );

			}
			Passenger_pieTabla();
		}
		else
		{
			ret = -2;//ERROR ll vacia
		}

	}

	return ret;
}

int Passenger_baja (LinkedList* passengerList)
{
	int ret = -1;//ERROR linked NULL
	if(passengerList != NULL)
	{
		Passenger* pPassengerBaja;
		int  idAux;
		if(utn_getNumero(&idAux, "Ingrese el ID del pasajero que desea dar de baja\n"
				, "ERROR\n", 1, 10000, 2) == 0)
		{
			int indexBaja;
			indexBaja = Passenger_findIndexById(passengerList, idAux);
			if(indexBaja >= 0)
			{
				pPassengerBaja = ll_pop(passengerList, indexBaja);
				if(pPassengerBaja != NULL)
				{
					Passenger_delete(pPassengerBaja);
					printf("El registro ha sido borrado de la Linked List y se le ha hecho un free al passenger\n");
					ret = 0;//SUCCESS
				}
				else
				{
					ret = -4;//ERROR de ll pop
				}
			}
			else
			{
				ret = -3;//ERROR de find index by id
			}
		}
		else
		{
			ret = -2;//ERROR utn_getNum
		}

	}
	return ret;
}

int Passenger_findIndexById(LinkedList* passengerList, int id)
{
	int ret =  -1;//ERROR linked NULL
	Passenger* passengerAux;
	if(passengerList != NULL)
	{
		for(int i=0; i<ll_len(passengerList); i++)
		{
			passengerAux = ll_get(passengerList, i);
			if(passengerAux->id == id)
			{
				ret = i;
				break;
			}
		}
		if(ret == -1)
		{
			ret = -2;//ERROR no encontre el ID que me dijiste
		}
	}
	return ret;
}


int Passenger_modificar(LinkedList* passengerList)
{
	int ret = -1;//ERROR null list
	if(passengerList != NULL)
	{
		int  idAux;
		if( utn_getNumero(&idAux, "Ingrese el ID del pasajero que desea modificar\n"
			,"ERROR\n", 1, 10000, 2) == 0)
		{
			int indexModificar;
			indexModificar = Passenger_findIndexById(passengerList, idAux);
			if(indexModificar >= 0)
			{
				Passenger* pPassengerModificar;
				pPassengerModificar = ll_get(passengerList, indexModificar);
				if(Passenger_modificador(pPassengerModificar) != NULL)
				{
					ret = 0;
					printf("Todo un exito\n");
				}
			}
			else
			{
				ret = -3;//ERROR de find index by id
			}
		}
		else
		{
			ret = -2;//ERROR de utn get num
		}
	}
	return ret;
}

Passenger* Passenger_modificador(Passenger* this)
{
	if(this != NULL)
	{
		Passenger passengerAux;
		passengerAux = *this;
		DEBUG();
		printf("El nombre del pasajero aux copiado es:%s\n",passengerAux.nombre);
		int opcion;
		do
		{
			utn_getNumero(&opcion, "Ingrese:"
					"1)Para modificar nombre\n"
					"2)Para modificar apellido\n"
					"3)Para modificar precio\n"
					"4)Para modificar tipo de pasajero\n"
					"5)Para modificar codigo de vuelo\n"
					"6)Para modificar estado de vuelo\n"
					"7)Guardar y salir\n"
					"0)Salir\n", "ERROR\n", 0, 7, 1);
			switch(opcion)
			{
			case 1:
				utn_getNombre(passengerAux.nombre, NOMBRE_LEN, "Ingrese el nuevo nombre\n"
						, "ERROR\n", 2);
				break;
			case 2:
				utn_getNombre(passengerAux.apellido, NOMBRE_LEN, "Ingrese el nuevo apellido\n"
						, "ERROR\n", 2);
				break;
			case 3:
				utn_getFloat(&passengerAux.precio, "Ingrese el nuevo precio\n"
						, "ERROR\n", 100, 100000, 2);
				break;
			case 4:
				utn_getNumero(&passengerAux.tipoPasajero, "Presione:\n"
									"1)Para Economy Class\n"
									"2)Para First Class\n"
									"3)Para executive Class\n", "ERROR\n", 1, 3, 2);
				break;
			case 5:
				utn_getPassword(passengerAux.codigoVuelo, 7, "Ingrese el nuevo codigo de vuelo\n"
						, "ERROR\n", 2);
				break;
			case 6:
				utn_getNumero(&passengerAux.isEmpty, "Presione para cambiar el estado a:\n"
						"1)En horario\n"
						"2)Aterrizado\n"
						"3)Demorado\n"
						"4)En vuelo\n", "ERROR\n", 1, 4, 2);
				break;
			case 7:
				printf("Estos son los nuevos datos cargados:\n");
				Passenger_encbezadoTabla();
				Passenger_printOne(&passengerAux);
				Passenger_pieTabla();

				if(validateExit_YN("Confirma? Y/N\n", "ERROR\n", 1) == 1)
				{
					*this = passengerAux;
					printf("Estos son los nuevos datos una vez guardados:\n");
					Passenger_encbezadoTabla();
					Passenger_printOne(&passengerAux);
					Passenger_pieTabla();
				}
				break;
			}
		}
		while(opcion != 0);
	}
	return this;
}

static int passenger_BuscarUltimoID(LinkedList* arrayPassajeros)
{
	static int ret = -1;
	if(arrayPassajeros != NULL)
	{
		Passenger* passengerAux;
		for(int i=0; i<ll_len(arrayPassajeros); i++)
		{
			passengerAux = ll_get(arrayPassajeros, i);
			ret = passengerAux->id;
		}
		ret++;
	}
	return ret;
}

static int passenger_BuscarUltimoIDCSV(char* path)
{

	FILE* pPassengersCSV;
	static int lastID;
	if(path != NULL)
	{
			pPassengersCSV = fopen(path,"r");
			if(pPassengersCSV != NULL)
			{
				do
				{
					lastID = 0;//SUCCESS pude leer el file

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
					if(fscanf(pPassengersCSV,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
							id,
							nombre,
							apellido,
							precio,
							codigoDeVuelo,
							tipoDePasajero,
							isEmpty
							) == 7)
					{
						lastID = atoi(id);
					}


				}
				while( !feof(pPassengersCSV));
				lastID++;

			}
			else
			{
				lastID = -3;//ERROR al abrir el archivo
			}

	}

    return lastID;
}






void passenger_ordenarAscendentemente(LinkedList* pArrayListPassenger)
{
	int ret = -1;//ERROR LinkedList NULL
	int flagSwap;
	if(pArrayListPassenger  != NULL)
	{

	ret = 0;//SUCCESS
	LinkedList* listaPasajerosCopy;
	listaPasajerosCopy = ll_clone(pArrayListPassenger);
	int length = ll_len(listaPasajerosCopy);
	do
	{
		flagSwap = 0;
		int i;
		//limite -1 para que no compare contra la nada
		for(i=0; i<length; i++)
		{
			Passenger*  pPass1;
			Passenger*  pPass2;

			pPass1 = (Passenger*)ll_get(listaPasajerosCopy, i);
			pPass2 = (Passenger*)ll_get(listaPasajerosCopy, i+1);

			if(pPass1 != NULL && pPass2 != NULL)
			{
				int auxiliarDeComparacion1;
				auxiliarDeComparacion1 = strncmp(pPass1->nombre,pPass2->nombre,NOMBRE_LEN);

				int auxiliarDeComparacion2;
				auxiliarDeComparacion2 = strncmp(pPass1->apellido,pPass2->apellido,NOMBRE_LEN);

				//orden alfanumerico ascendente

				if( auxiliarDeComparacion1 > 0 || (auxiliarDeComparacion1 == 0 && auxiliarDeComparacion2 > 0))
				{
					flagSwap = 1;

					ll_remove(pArrayListPassenger, i);
					ll_set(listaPasajerosCopy, i, pPass2);

					ll_remove(pArrayListPassenger, i+1);
					ll_set(listaPasajerosCopy, i+1, pPass1);

				}

			}

		}
		}
		while(flagSwap);

		Passenger_printByStatus(listaPasajerosCopy, 0);
		printf("OK imprimi la copia clonada y ordenada\n");
		printf("La lista clonada y ordenada tiene esta cantidad de elem");
		elEnteroEs(ll_len(listaPasajerosCopy));
		printf("borro la lista eh\n");
		ll_deleteLinkedList(listaPasajerosCopy);

	}
}


void passenger_ordenarDescendentemente(LinkedList* pArrayListPassenger)
{
	int ret = -1;//ERROR LinkedList NULL
	int flagSwap;
	if(pArrayListPassenger  != NULL)
	{

		ret = 0;//SUCCESS
		LinkedList* listaPasajerosCopy;
		listaPasajerosCopy = ll_clone(pArrayListPassenger);
		int length = ll_len(listaPasajerosCopy);
		do
		{
			flagSwap = 0;
			int i;
			//limite -1 para que no compare contra la nada
			for(i=0; i<length; i++)
			{
				Passenger*  pPass1;
				Passenger*  pPass2;

				pPass1 = (Passenger*)ll_get(listaPasajerosCopy, i);
				pPass2 = (Passenger*)ll_get(listaPasajerosCopy, i+1);

				if(pPass1 != NULL && pPass2 != NULL)
				{
					int auxiliarDeComparacion1;
					auxiliarDeComparacion1 = strncmp(pPass1->nombre,pPass2->nombre,NOMBRE_LEN);

					int auxiliarDeComparacion2;
					auxiliarDeComparacion2 = strncmp(pPass1->apellido,pPass2->apellido,NOMBRE_LEN);

					//orden alfanumerico ascendente

					if( auxiliarDeComparacion1 < 0 || (auxiliarDeComparacion1 == 0 && auxiliarDeComparacion2 < 0))
					{
						flagSwap = 1;

						ll_remove(pArrayListPassenger, i);
						ll_set(listaPasajerosCopy, i, pPass2);

						ll_remove(pArrayListPassenger, i+1);
						ll_set(listaPasajerosCopy, i+1, pPass1);

					}

				}

			}
		}
		while(flagSwap);

		Passenger_printByStatus(listaPasajerosCopy, 0);
		printf("OK imprimi la copia clonada y ordenada\n");
		printf("La lista clonada y ordenada tiene esta cantidad de elem");
		elEnteroEs(ll_len(listaPasajerosCopy));
		printf("borro la lista eh\n");
		ll_deleteLinkedList(listaPasajerosCopy);

	}
}


void passenger_ordenar(LinkedList* pArrayListPassenger ,void(*pFuncion)(LinkedList*))
{
	pFuncion(pArrayListPassenger);
}





