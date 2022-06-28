/*
 * salon.c
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */

#include "salon.h"
#include "arcade.h"
#include "LinkedList.h"
//--------------------Generador de ID's--------------
int salon_idAutoIncremental = 1000;
static int salon_generateID(LinkedList* arraySalones);
static int salon_BuscarUltimoID(LinkedList* arraySalones);
/// @fn int prod_generateID()
/// @brief genera un id en base a un contador
///
/// @return retorna el id
static int salon_generateID(LinkedList* arraySalones){
	int idAux = salon_BuscarUltimoID(arraySalones);
	if(idAux >= 1000)
	{
		salon_idAutoIncremental = idAux;
	}
	return salon_idAutoIncremental++;
}

/// @brief Busca el ultimo id utilizado de salones
///
/// @param arraySalones puntero a linkedList de  salones
/// @return retorna el ultimo ID
static int salon_BuscarUltimoID(LinkedList* arraySalones)
{
	static int ret = -1;
	if(arraySalones != NULL)
	{
		Salon* salonAux;
		for(int i=0; i<ll_len(arraySalones); i++)
		{
			salonAux = ll_get(arraySalones, i);
			ret = salonAux->id;
		}
		ret++;
	}
	return ret;
}
//--------------------Generador de ID's--------------


//************Constructores Destructores************
/// @brief reserva  espacio para salon
///
/// @return retorna puntero a salon
Salon* Salon_new(void){

	Salon*  pSalon;
	pSalon = (Salon* )malloc(sizeof(Salon) * 1 );

	if(pSalon  != NULL)
	{
		pSalon->id = 0;
		pSalon->nombre[0] = '\0';
		pSalon->direccion[0] = '\0';
		pSalon->tipo = 0;
		return pSalon;
	}
	else return pSalon;
}
/// @brief Crea un salon nuevo en base a los parametros pasados
///
/// @param nombre nuevo nombre del salon
/// @param direccion nueva direccion del salon
/// @param tipo tipo de salon
/// @return retorna puntero
Salon* Salon_newConParametrosTxt(char nombre[], char direccion[], char tipo[]){
	Salon*  pSalon;
	pSalon = Salon_new();


	return pSalon;
}

/// @brief Elimina espacio previamente reservado para el puntero
///
/// @param this puntero a Arcade
void Salon_delete(Salon* this){

	if(this !=  NULL){

		free(this);
	}
}


//************Setters************
int Salon_setId(Salon* this,int id)
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

int Salon_setIdTxt(Salon* this, char id[])
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

int Salon_setNombre(Salon* this,char* nombre)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(nombre != NULL)
		{
			if(esAlfaNumerico(nombre, NOMBRE_LEN) == 1)
			{
				strncpy(this->nombre,nombre,NOMBRE_LEN);

				ret = 0;//SUCCESS
			}
			else
			{
				ret = -3;
			}
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Salon_setDireccion(Salon* this,char* direccion)
{

	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(direccion != NULL)
		{
			if(esAlfaNumerico(direccion, DIRECCION_LEN) == 1)
			{
				strncpy(this->direccion,direccion,DIRECCION_LEN);
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

int Salon_setTipoSalon(Salon* this,int tipoSalon)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		this->tipo = tipoSalon;
		ret = 0;//SUCCESS
	}
	return ret;
}

int Salon_setTipoSalonTxt(Salon* this, char tipoSalon[])
{
	int ret = -1; //ERROR
	if(this != NULL)
	{
		if(tipoSalon != NULL)
		{

			if(strcmp(tipoSalon, "Shopping") == 0)
			{
				ret = 0;//SUCCESS
				this->tipo = SHOPPING;
			}
			else
			{
				if(strcmp(tipoSalon, "Local") == 0)
				{
					ret = 0;//SUCCESS
					this->tipo = LOCAL;
				}
				else
				{
					printf("No era ninguna de esas\n");
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



//************Getters************
int Salon_getNombre(Salon* this,char* nombre)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(nombre != NULL)
		{
			if(esAlfaNumerico(this->nombre, NOMBRE_LEN) == 1)
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

int Salon_getId(Salon* this,int* id)
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

int Salon_getDireccion(Salon* this,char* direccion)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(direccion != NULL)
		{
			if(esAlfaNumerico(this->direccion, DIRECCION_LEN) == 1)
			{
				strncpy(direccion,this->direccion,DIRECCION_LEN);
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

int Salon_getTipo(Salon* this,int* tipo)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(tipo != NULL)
		{

			*tipo = this->tipo;
			ret = 0; //SUCCESS
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

Salon* Salon_getSalonByID(LinkedList* pListaSalones, int id)
{
	Salon* pSalon = NULL;
	if(pListaSalones != NULL)
	{
		for(int i=0; i<ll_len(pListaSalones); i++)
		{
			pSalon = ll_get(pListaSalones, i);
			if(pSalon->id == id) break;
			else pSalon = NULL;
		}
	}

	return pSalon;
}

//************ABM************
int Salon_alta(LinkedList* listaSalones)
{
	int ret = -1;//ERROR linked NULL
	if(listaSalones != NULL)
	{
		Salon* SalonAux = Salon_new();
		if(SalonAux != NULL)
		{
			if(Salon_pedirDatos(SalonAux, listaSalones) == 0)
			{
				ll_add(listaSalones, SalonAux);
				printf("Carga exitosa\n\n");
				ret = 0;//SUCCESS;
			}
		}
	}
	return ret;
}

int Salon_pedirDatos(Salon* pSalon, LinkedList* arraySalones)
{
	int ret = -1; //ERROR null ppasenger
	if(pSalon != NULL)
	{
//		pedido de datos
		if( utn_getDescripcion(pSalon->nombre, NOMBRE_LEN, "Ingrese el nombre del salon\n", "ERROR\n", 2) == 0 &&
			utn_getDireccion(pSalon->direccion, DIRECCION_LEN, "Ingrese la direccion\n", "ERROR\n", 2) == 0 &&
			utn_getNumero(&pSalon->tipo, "Presione:\n"
					"1)Para Shopping\n"
					"2)Para Local\n"
					,"ERROR\n", 1, 2, 2) == 0)
		{
			pSalon->id = salon_generateID(arraySalones);
			Salon_encbezadoTabla();
			Salon_printOne(pSalon);
			Salon_pieTabla();
			ret = 0;//SUCCESS
		}
		else ret = -2;//ERROR de pedido de datos
	}
	return ret;
}

void menuSalones(LinkedList* listaSalones, LinkedList* listaArcades)
{
	int opcion;
	do
	{
		utn_getNumero(&opcion, "***Menu salones***\n"
				"1)Alta\n"
				"2)Baja\n"
				"3)Modificacion (NO DISPONIBLE POR CONSIGNA TP, ESTA DESARROLLADO IGUAL)\n"
				"4)Impresion\n"
				"0)Salir\n", "ERROR\n", 0, 10, 2);
		switch(opcion)
		{
		case ALTA:
			Salon_alta(listaSalones);
			break;
		case BAJA:
			Salon_baja(listaSalones, listaArcades);
			break;
		case MODIFICACION:
//			Salon_modificar(listaSalones);
			break;
		case IMPRESION:
			Salon_printByStatus(listaSalones, 0);
			break;

		}

	}while(opcion != 0);
}

int Salon_modificar(LinkedList* listaSalones)
{
	int ret = -1;//ERROR null list
	if(listaSalones != NULL)
	{
		int  idAux;
		Salon_printByStatus(listaSalones, 0);
		if( utn_getNumero(&idAux, "Ingrese el ID del salon que desea modificar\n"
			,"ERROR\n", 1, 10000, 2) == 0)
		{
			int indexModificar;
			indexModificar = Salon_findIndexById(listaSalones, idAux);
			if(indexModificar >= 0)
			{
				Salon* pSalonModificar;
				pSalonModificar = ll_get(listaSalones, indexModificar);
				if(Salon_modificador(pSalonModificar) != NULL)
				{
					ret = 0;
					printf("Todo un exito\n");
				}
			}
			else ret = -3;//ERROR de find index by id
		}
		else ret = -2;//ERROR de utn get num
	}
	return ret;
}

Salon* Salon_modificador(Salon* this)
{
	if(this != NULL)
	{
		Salon salonAux;
		salonAux = *this;
		int opcion;
		do
		{
			utn_getNumero(&opcion, "Ingrese:\n"
					"1)Para modificar nombre\n"
					"2)Para modificar direccion\n"
					"3)Para modificar tipo\n"
					"4)Guardar y salir\n"
					"0)Salir\n", "ERROR\n", 0, 4, 1);
			switch(opcion)
			{
			case 1:
				utn_getDescripcion(salonAux.nombre, NOMBRE_LEN, "Ingrese el nuevo nombre\n"
						, "ERROR\n", 2);
				break;
			case 2:
				utn_getDescripcion(salonAux.direccion, DIRECCION_LEN, "Ingrese la nueva direccion\n"
						, "ERROR\n", 2);
				break;
			case 3:
				utn_getNumero(&salonAux.tipo, "Presione para cambiar el estado a:\n"
						"1)Shopping\n"
						"2)Local\n"
						, "ERROR\n", 1, 2, 2);
				break;
			case 4:
				printf("Estos son los nuevos datos cargados:\n");
				Salon_encbezadoTabla();
				Salon_printOne(&salonAux);
				Salon_pieTabla();

				if(validateExit_YN("Confirma? Y/N\n", "ERROR\n", 1) == 1)
				{
					*this = salonAux;
				}
				opcion = 0;
				break;
			}
		}
		while(opcion != 0);
	}
	return this;
}

int Salon_findIndexById(LinkedList* listaSalones, int id)
{
	int ret =  -1;//ERROR linked NULL
	Salon* salonAux;
	if(listaSalones != NULL)
	{
		for(int i=0; i<ll_len(listaSalones); i++)
		{
			salonAux = ll_get(listaSalones, i);
			if(salonAux->id == id)
			{
				ret = i;
				break;
			}
		}
		if(ret == -1) ret = -2;//ERROR no encontre el ID que me dijiste
	}
	return ret;
}

int Salon_baja (LinkedList* listaSalones, LinkedList* listaArcades)
{
	int ret = -1;//ERROR linked NULL
	if(listaSalones != NULL)
	{
		Salon* pSalonBaja;
		Salon_printByStatus(listaSalones, 0);
		int  idAux;
		if(utn_getNumero(&idAux, "Ingrese el ID del salon que desea dar de baja\n"
				, "ERROR\n", 1, 10000, 2) == 0)
		{
			int indexBaja;
			indexBaja = Salon_findIndexById(listaSalones, idAux);
			if(indexBaja >= 0)
			{
				pSalonBaja = ll_pop(listaSalones, indexBaja);
				if(pSalonBaja != NULL)
				{
					if(Salon_checkArcades(pSalonBaja->id, listaArcades) == 0)
					{
						printf("El registro del salon %s ha sido borrado de la Linked List y se le ha hecho un free()\n",pSalonBaja->nombre);
						Salon_delete(pSalonBaja);
						ret = 0;//SUCCESS
					}
				}
				else ret = -4;//ERROR de ll pop
			}
			else ret = -3;//ERROR de find index by id
		}
		else ret = -2;//ERROR utn_getNum

	}
	return ret;
}


//************Printers************

int Salon_printOne(Salon* this)
{
	int ret = -1;

	if(this != NULL)
	{
		char tipo[TIPO_LEN];
		switch(this->tipo)
		{
		case SHOPPING:
			strncpy(tipo,"Shopping",TIPO_LEN);
			break;
		case LOCAL:
			strncpy(tipo,"Local",TIPO_LEN);
			break;
		}

		printf("|%-4d|%-15s|%-29s|%-12s|\n"
				,this->id,this->nombre,this->direccion,tipo);
		ret = 0;
	}

	return ret;
}

int Salon_printByStatus(LinkedList* salonList, int status)
{
	int ret = -1;
	if(salonList != NULL)
	{
		int linkedListLenght = ll_len(salonList);
		if(linkedListLenght > 0)
		{
			Salon_encbezadoTabla();
			for(int i=0; i<linkedListLenght; i++)
			{
				Salon_printOne ( (Salon*)ll_get( salonList, i) );
				ret = 0;

			}
			Salon_pieTabla();
		}
		else ret = -2;//ERROR ll vacia
	}

	return ret;
}

void Salon_encbezadoTabla(void)
{

	printf("+----+---------------+-----------------------------+------------+\n");
	printf("| ID |     NOMBRE    |          DIRECCION          |    TIPO    |\n");
	printf("+----+---------------+-----------------------------+------------+\n");
}

void Salon_pieTabla(void)
{
	printf("+----+---------------+-----------------------------+------------+\n");
}


//************TOOLS************
int Salon_checkArcades(int salonID, LinkedList* listaArcades)
{
	int ret = -1;//ERROR lists nulls
	if(listaArcades != NULL && salonID >= 1000)
	{
		ret = 0;
		Arcade* pArcade;
		int  arcadeListLenght = ll_len(listaArcades);
		int i;
		for(i=0; i<arcadeListLenght; i++)
		{
			pArcade = ll_get(listaArcades, i);
			if(pArcade != NULL && pArcade->FK_salon == salonID)
			{
				printf("Se ha eliminado el arcade ID: %d\n",pArcade->id);
				ll_remove(listaArcades, i);
				i--;
			}
		}
	}
	return ret;
}






