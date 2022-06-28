/*
 * juegos.c
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */
#include "juegos.h"
#include "salon.h"
#include "utn.h"

//--------------------Generador de ID's--------------
int juego_idAutoIncremental = 1000;
static int juego_generateID(LinkedList* arrayJuegos);
static int juego_BuscarUltimoID(LinkedList* arrayJuegos);
/// @fn int prod_generateID()
/// @brief genera un id en base a un contador
///
/// @return retorna el id
static int juego_generateID(LinkedList* arrayJuegos){
	int idAux = juego_BuscarUltimoID(arrayJuegos);
	if(idAux >= 1000)
	{
		juego_idAutoIncremental = idAux;
	}
	return juego_idAutoIncremental++;
}

/// @brief Busca el ultimo id utilizado de Juegos
///
/// @param arrayJuegos puntero a linkedList de  Juegos
/// @return retorna el ultimo ID
static int juego_BuscarUltimoID(LinkedList* arrayJuegos)
{
	static int ret = -1;
	if(arrayJuegos != NULL)
	{
		Juego* juegoAux;
		for(int i=0; i<ll_len(arrayJuegos); i++)
		{
			juegoAux = ll_get(arrayJuegos, i);
			ret = juegoAux->id;
		}
		ret++;
	}
	return ret;
}
//--------------------Generador de ID's--------------


//************Constructores************
/// @brief reserva  espacio para Juego
///
/// @return retorna puntero a Juego
Juego* Juego_new(void){

	Juego*  pJuego;
	pJuego = (Juego* )malloc(sizeof(Juego) * 1 );

	if(pJuego  != NULL)
	{
		pJuego->id = 0;
		pJuego->nombre[0] =  '\0';
		pJuego->empresa[0] =  '\0';
		pJuego->genero[0] =  '\0';
		return pJuego;
	}
	else return pJuego;
}

/// @brief Elimina espacio previamente reservado para el puntero
///
/// @param this puntero a Juego
void Juego_delete(Juego* this){

	if(this !=  NULL){

		free(this);
	}
}


//************Getters************
Juego* Juego_getJuegoByID(LinkedList* pListaJuegos, int id)
{
	Juego* pJuego = NULL;
	for(int i=0; i<ll_len(pListaJuegos); i++)
	{
		pJuego = ll_get(pListaJuegos, i);
		if(pJuego->id == id) break;
		else pJuego = NULL;
	}
	return pJuego;
}


//************ABM************
/// @brief Despliega opciones para menu juegos
///
/// @param listaJuegos
void menuJuegos(LinkedList* listaJuegos)
{
	int opcion;
	do
	{
		utn_getNumero(&opcion, "***Menu juegos***\n"
				"1)Alta\n"
				"2)Baja (NO DISPONIBLE POR CONSIGNA TP, ESTA DESARROLLADO IGUAL)\n"
				"3)Modificacion (NO DISPONIBLE POR CONSIGNA TP, ESTA DESARROLLADO IGUAL)\n"
				"4)Impresion\n"
				"0)Salir\n", "ERROR\n", 0, 10, 2);
		switch(opcion)
		{
		case ALTA:
			Juego_alta(listaJuegos);
			break;
		case BAJA:
//			Juego_baja(listaJuegos);
			break;
		case MODIFICACION:
//			Juego_modificar(listaJuegos);
			break;
		case IMPRESION:
			Juego_printByStatus(listaJuegos, 0);
			break;
		}
	}while(opcion != 0);
}

int Juego_alta(LinkedList* listaJuegos)
{
	int ret = -1;//ERROR linked NULL
	if(listaJuegos != NULL)
	{
		Juego* pJuegoAux = Juego_new();
		if(pJuegoAux != NULL)
		{
			if(Juego_pedirDatos(pJuegoAux, listaJuegos) == 0)
			{
				ll_add(listaJuegos, pJuegoAux);
				printf("Carga exitosa\n\n");
				ret = 0;//SUCCESS;
			}
		}
	}
	return ret;
}

int Juego_pedirDatos(Juego* juegoAux, LinkedList* listaJuegos)
{
	int ret = -1; //ERROR null ppasenger
	if(juegoAux != NULL)
	{
//		pedido de datos
		if( utn_getDescripcion(juegoAux->nombre, JUEGO_NAME_LEN ,"Ingrese  el nombre del juego\n"
				, "ERROR\n", 2) == 0 &&

			utn_getDescripcion(juegoAux->empresa, EMPRESA_LEN ,"Ingrese  la empresa del juego\n"
							, "ERROR\n", 2) == 0 &&

			utn_getDescripcion(juegoAux->genero, GENERO_LEN ,"Ingrese el genero del juego\n"
							, "ERROR\n", 2) == 0)
		{

			juegoAux->id = juego_generateID(listaJuegos);
			Juego_encbezadoTabla();
			Juego_printOne(juegoAux);
			Juego_pieTabla();
			ret = 0;//SUCCESS

		}
		else ret = -2;//ERROR de pedido de datos
	}
	return ret;
}

int Juego_baja (LinkedList* listaJuegos)
{
	int ret = -1;//ERROR linked NULL
	if(listaJuegos != NULL)
	{
		Juego* pJuegoBaja;
		Juego_printByStatus(listaJuegos, 0);
		int  idAux;
		if(utn_getNumero(&idAux, "Ingrese el ID del juego que desea dar de baja\n"
				, "ERROR\n", 1, 10000, 2) == 0)
		{
			int indexBaja;
			indexBaja = Juego_findIndexById(listaJuegos, idAux);
			if(indexBaja >= 0)
			{
				pJuegoBaja = ll_pop(listaJuegos, indexBaja);
				if(pJuegoBaja != NULL)
				{
					Juego_delete(pJuegoBaja);
					printf("El registro ha sido borrado de la Linked List y se le ha hecho un free al arcade\n");
					ret = 0;//SUCCESS
				}
				else ret = -4;//ERROR de ll pop
			}
			else ret = -3;//ERROR de find index by id
		}
		else ret = -2;//ERROR utn_getNum

	}
	return ret;
}

int Juego_findIndexById(LinkedList* listaJuegos, int id)
{
	int ret =  -1;//ERROR linked NULL
	Juego* JuegoAux;
	if(listaJuegos != NULL)
	{
		for(int i=0; i<ll_len(listaJuegos); i++)
		{
			JuegoAux = ll_get(listaJuegos, i);
			if(JuegoAux->id == id)
			{
				ret = i;
				break;
			}
		}
		if(ret == -1) ret = -2;//ERROR no encontre el ID que me dijiste
	}
	return ret;
}

int Juego_modificar(LinkedList* listaJuegos)
{
	int ret = -1;//ERROR null list
	if(listaJuegos != NULL)
	{
		int  idAux;
		Juego_printByStatus(listaJuegos, 0);
		if( utn_getNumero(&idAux, "Ingrese el ID del juego que desea modificar\n"
			,"ERROR\n", 1000, 10000, 2) == 0)
		{
			int indexModificar;
			indexModificar = Juego_findIndexById(listaJuegos, idAux);
			if(indexModificar >= 0)
			{
				Juego* pJuegoModificar;
				pJuegoModificar = ll_get(listaJuegos, indexModificar);
				if(Juego_modificador(pJuegoModificar) != NULL)
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

Juego* Juego_modificador(Juego* this)
{
	if(this != NULL)
	{
		Juego JuegoAux;
		JuegoAux = *this;
		int opcion;
		do
		{
			utn_getNumero(&opcion, "Ingrese:\n"
					"1)Para modificar nombre\n"
					"2)Para modificar empresa\n"
					"3)Para modificar genero\n"
					"4)Guardar y salir\n"
					"0)Salir\n", "ERROR\n", 0, 4, 1);
			switch(opcion)
			{
			case 1:
				utn_getDescripcion(JuegoAux.nombre, NOMBRE_LEN, "Ingrese el nuevo nombre\n"
						, "ERROR\n", 2);
				break;
			case 2:
				utn_getDescripcion(JuegoAux.empresa, EMPRESA_LEN, "Ingrese la nueva empresa\n"
						, "ERROR\n", 2);
				break;
			case 3:
				utn_getDescripcion(JuegoAux.genero, GENERO_LEN, "Ingrese el nuevo genero\n"
						, "ERROR\n", 2);
				break;
			case 4:
				printf("Estos son los nuevos datos cargados:\n");
				Juego_encbezadoTabla();
				Juego_printOne(&JuegoAux);
				Juego_pieTabla();

				if(validateExit_YN("Confirma? Y/N\n", "ERROR\n", 1) == 1)
				{
					*this = JuegoAux;
				}
				opcion = 0;
				break;
			}
		}
		while(opcion != 0);
	}
	return this;
}


//************Printers************

int Juego_printOne(Juego* this)
{
	int ret = -1;

	if(this != NULL)
	{
		printf("|%-4d|%-22s|%-26s|%-12s|\n"
				,this->id
				,this->nombre
				,this->empresa
				,this->genero);
	}

	return ret;
}

int Juego_printByStatus(LinkedList* juegoList, int status)
{
	int ret = -1;
	if(juegoList != NULL)
	{
		int linkedListLenght = ll_len(juegoList);
		if(linkedListLenght > 0)
		{
			Juego_encbezadoTabla();
			for(int i=0; i<linkedListLenght; i++)
			{
				Juego_printOne ( (Juego*)ll_get( juegoList, i) );

			}
			Juego_pieTabla();
		}
		else ret = -2;//ERROR ll vacia
	}

	return ret;
}

void Juego_encbezadoTabla(void)
{

	printf("+----+----------------------+--------------------------+------------+\n");
	printf("| ID |        NOMBRE        |         EMPRESA          |   GENERO   |\n");
	printf("+----+----------------------+--------------------------+------------+\n");
}

void Juego_pieTabla(void)
{
	printf("+----+----------------------+--------------------------+------------+\n");
}






















