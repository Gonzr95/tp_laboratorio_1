/*
 * arcade.c
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */
#include "salon.h"
#include "arcade.h"
#include "juegos.h"
#include "LinkedList.h"
//--------------------Generador de ID's--------------
int arcade_idAutoIncremental = 1000;
static int arcade_generateID(LinkedList* arrayArcades);
static int arcade_BuscarUltimoID(LinkedList* arrayArcades);
/// @fn int arcade_generateID()
/// @brief genera un id en base el  ultimo id utilizado
/// @param arrayArcades lista de arcades
/// @return retorna el id
static int arcade_generateID(LinkedList* arrayArcades){
	int idAux = arcade_BuscarUltimoID(arrayArcades);
	if(idAux >= 1000)
	{
		arcade_idAutoIncremental = idAux;
	}
	return arcade_idAutoIncremental++;
}

/// @brief Busca el ultimo id utilizado de arcades
///
/// @param arrayArcades puntero a linkedList de  arcades
/// @return retorna el ultimo ID
static int arcade_BuscarUltimoID(LinkedList* arrayArcades)
{
	static int ret = -1;
	if(arrayArcades != NULL)
	{
		Arcade* arcadeAux;
		for(int i=0; i<ll_len(arrayArcades); i++)
		{
			arcadeAux = ll_get(arrayArcades, i);
			ret = arcadeAux->id;
		}
		ret++;
	}
	return ret;
}
//--------------------Generador de ID's--------------


//************Constructores************
/// @brief reserva  espacio para Arcade
///
/// @return retorna puntero a Arcade
Arcade* Arcade_new(void){

	Arcade*  pArcade;
	pArcade = (Arcade* )malloc(sizeof(Arcade) * 1 );

	if(pArcade  != NULL)
	{
		pArcade->id = 0;
		pArcade->nacionalidad[0] = '\0';
		pArcade->tipoSonido = 0;
		pArcade->cantidadJugadores = 0;
		pArcade->capacidadFichas = 0;
		pArcade->FK_juego = 0;
		pArcade->FK_salon = 0;
		return pArcade;
	}
	else return pArcade;
}

/// @brief Elimina espacio previamente reservado para el puntero
///
/// @param this puntero a Arcade
void Arcade_delete(Arcade* this){

	if(this !=  NULL){

		free(this);
	}
}

/// @brief Despliega opciones para Arcades
///
/// @param listaArcades puntero  a ll
/// @param listaSalones puntero  a ll
/// @param listaJuegos puntero  a ll
void menuArcades(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos)
{
	int opcion;
	do
	{
		utn_getNumero(&opcion, "***Menu arcades***\n"
				"1)Alta\n"
				"2)Baja\n"
				"3)Modificacion\n"
				"4)Impresion\n"
				"0)Salir\n", "ERROR\n", 0, 10, 2);
		switch(opcion)
		{
		case ALTA:
			Arcade_alta(listaArcades, listaSalones, listaJuegos);
			break;
		case BAJA:
			Arcade_baja(listaArcades, listaJuegos, listaSalones);
			break;
		case MODIFICACION:
			Arcade_modificar(listaArcades, listaSalones, listaJuegos);
			break;
		case IMPRESION:
			Arcade_printByStatusV3(listaArcades, listaJuegos);
			break;
		}
	}while(opcion != 0);
}


//************Getters************
int Arcade_getFK_SalonId(Arcade* this,int* id)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(id != NULL)
		{

			*id = this->FK_salon;
			ret = 0;//SUCCESS

		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Arcade_getCantidadJugadores(Arcade* this,int* QTYjugadores)
{
	int ret = -1; //ERROR

	if(this != NULL)
	{
		if(QTYjugadores != NULL)
		{
			*QTYjugadores = this->cantidadJugadores;
			ret = 0;//SUCCESS
		}
		else
		{
			ret = -2;//ERROR
		}
	}
	return ret;
}

int Arcade_getId(Arcade* this,int* id)
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

Arcade* Arcade_getArcadeByID(LinkedList* pListaArcades, int id)
{
	Arcade* pArcade = NULL;
	for(int i=0; i<ll_len(pListaArcades); i++)
	{
		pArcade = ll_get(pListaArcades, i);
		if(pArcade->id == id) break;
		else pArcade = NULL;
	}
	return pArcade;
}

Arcade* Arcade_getArcadeByFK_salonID(LinkedList* pListaArcades, int FK_salon)
{
	Arcade* pArcade = NULL;
	for(int i=0; i<ll_len(pListaArcades); i++)
	{
		pArcade = ll_get(pListaArcades, i);
		if(pArcade->FK_salon == FK_salon) break;
		else pArcade = NULL;
	}
	return pArcade;
}


//************ABM************
int Arcade_alta(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos)
{
	int ret = -1;//ERROR linked NULL
	int respesta;
	respesta = validateExit_YN("**ATENCION**\n"
			"Debera tener dado de alta el juego que contendra el arcade.\n"
			"De lo contrario no podra proceder con el alta del arcade\n"
			"Desea continuar? Y/N\n"
			, "ERROR\n", 2);
	if(listaArcades != NULL && respesta == 1)
	{
		Arcade* arcadenAux = Arcade_new();
		if(arcadenAux != NULL)
		{
			if(Arcade_pedirDatos(arcadenAux, listaArcades, listaSalones, listaJuegos) == 0)
			{
				ll_add(listaArcades, arcadenAux);
				printf("Carga exitosa\n\n");
				ret = 0;//SUCCESS;
			}
			else Arcade_delete(arcadenAux);
		}
	}
	return ret;
}

int Arcade_pedirDatos(Arcade* arcadenAux, LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos)
{
	int ret = -1; //ERROR null ppasenger
	if(arcadenAux != NULL)
	{
//		pedido de datos
		if( utn_getNombre(arcadenAux->nacionalidad, NACIONALIDAD_LEN, "Ingrese la nacionalidad\n"
			, "ERROR\n", 2) == 0 &&

			utn_getNumero(&arcadenAux->tipoSonido, "Ingrese:\n"
					"1)Para sonido Mono\n"
					"2)Para sonido Stereo\n", "ERROR\n", 1, 2, 2) == 0 &&

			utn_getNumero(&arcadenAux->cantidadJugadores, "Indique la cantidad de jugadores (entre 1 Y 4)\n"
			, "ERROR\n", JUGADORES_MIN, JUGADORES_MAX, 2) == 0 &&

			utn_getNumero(&arcadenAux->capacidadFichas, "Indique la cantidad de fichas disponibles (entre 10 y 50)\n"
			, "ERROR\n", FICHAS_MIN, FICHAS_MAX, 2) == 0)

		{
			Salon_printByStatus(listaSalones, 0);
			utn_getNumero(&arcadenAux->FK_salon, "Ingrese el ID del salon al que pertenece el nuevo arcade\n"
			, "ERROR\n", 1000, 10000, 2);

			if(Salon_findIndexById(listaSalones, arcadenAux->FK_salon) >= 0)
			{
				Juego_printByStatus(listaJuegos, 0);

				utn_getNumero(&arcadenAux->FK_juego, "Ingrese el ID del juego que contiene el nuevo arcade\n"
				, "ERROR\n", 1000, 10000, 2);

				if(Juego_findIndexById(listaJuegos, arcadenAux->FK_juego) >= 0)
				{
					arcadenAux->id = arcade_generateID(listaArcades);
					Arcade_encbezadoTabla();
					Arcade_printOne(arcadenAux);
					Arcade_pieTabla();
					ret = 0;//SUCCESS
				}
				else printf("Ese ID de   juego no existe\n");

			}
			else printf("Ese ID de salon no existe\n");
		}
		else ret = -2;//ERROR de pedido de datos
	}
	return ret;
}

int Arcade_baja (LinkedList* listaArcades, LinkedList* listaJuegos, LinkedList* listaSalones)
{
	int ret = -1;//ERROR linked NULL
	if(listaArcades != NULL && listaJuegos != NULL && listaSalones != NULL)
	{
		Arcade* pArcadeBaja;
		Arcade_printByStatusV2(listaArcades, listaJuegos, listaSalones);
		int  idAux;
		if(utn_getNumero(&idAux, "Ingrese el ID del arcade que desea dar de baja\n"
				, "ERROR\n", 1, 10000, 2) == 0)
		{
			int indexBaja;
			indexBaja = Arcade_findIndexById(listaArcades, idAux);
			if(indexBaja >= 0)
			{
				printf("Esta por eliminar el siguiente arcade\n");
				pArcadeBaja = ll_get(listaArcades, indexBaja);
				Salon* pSalon = Salon_getSalonByID(listaSalones, pArcadeBaja->FK_salon);
				Juego* pJuego = Juego_getJuegoByID(listaJuegos, pArcadeBaja->FK_juego);
				Arcade_encbezadoTablaV2();
				Arcade_printOneV2(pArcadeBaja, pSalon->nombre, pJuego->nombre);
				Arcade_pieTablaV2();
				int rta = validateExit_YN("Confirme la baja Y/N\n", "ERROR\n", 2);
				if(rta == 1)
				{
					pArcadeBaja = ll_pop(listaArcades, indexBaja);
					if(pArcadeBaja != NULL)
					{
						Arcade_delete(pArcadeBaja);
						printf("El registro ha sido borrado de la Linked List y se le ha hecho un free al arcade\n");
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

int Arcade_findIndexById(LinkedList* listaArcades, int id)
{
	int ret =  -1;//ERROR linked NULL
	Arcade* arcadeAux;
	if(listaArcades != NULL)
	{
		for(int i=0; i<ll_len(listaArcades); i++)
		{
			arcadeAux = ll_get(listaArcades, i);
			if(arcadeAux->id == id)
			{
				ret = i;
				break;
			}
		}
		if(ret == -1) ret = -2;//ERROR no encontre el ID que me dijiste
	}
	return ret;
}

int Arcade_modificar(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos)
{
	int ret = -1;//ERROR null list
	if(listaArcades != NULL)
	{
		int  idAux;
		Arcade_printByStatus(listaArcades, 0);
		if( utn_getNumero(&idAux, "Ingrese el ID del arcade que desea modificar\n"
			,"ERROR\n", 1, 10000, 2) == 0)
		{
			int indexModificar;
			indexModificar = Arcade_findIndexById(listaArcades, idAux);
			if(indexModificar >= 0)
			{
				Arcade* pArcadeModificar;
				pArcadeModificar = ll_get(listaArcades, indexModificar);
				if(Arcade_modificador(pArcadeModificar, listaSalones, listaJuegos) != NULL)
				{
					ret = 0;
				}
			}
			else
			{
				printf("ERROR, id fuera de rango\n");
				ret = -3;//ERROR de find index by id
			}
		}
		else ret = -2;//ERROR de utn get num
	}
	return ret;
}

Arcade* Arcade_modificador(Arcade* this, LinkedList* listaSalones, LinkedList* listaJuegos)
{
	if(this != NULL)
	{
		Arcade arcadeAux;
		arcadeAux = *this;
		int opcion;
		do
		{
			utn_getNumero(&opcion, "Ingrese:\n"
					"1)Para modificar Nacionalidad (NO DISPONIBLE POR CONSIGNA TP, ESTA DESARROLLADO IGUAL)\n"
					"2)Para modificar tipo de sonido (NO DISPONIBLE POR CONSIGNA TP, ESTA DESARROLLADO IGUAL)\n"
					"3)Para modificar cantidad de jugadores\n"
					"4)Para modificar capacidad de fichas (NO DISPONIBLE POR CONSIGNA TP, ESTA DESARROLLADO IGUAL)\n"
					"5)Para modificar salon al que pertenece (NO DISPONIBLE POR CONSIGNA TP, ESTA DESARROLLADO IGUAL)\n"
					"6)Para modificar juego que contiene\n"
					"7)Guardar y salir\n"
					"0)Salir\n", "ERROR\n", 0, 7, 1);
//			int idAux;
			switch(opcion)
			{
			case 1:
//				utn_getNombre(arcadeAux.nacionalidad, NACIONALIDAD_LEN, "Ingrese la nueva nacionalidad\n"
//						, "ERROR\n", 2);
				break;
			case 2:
//				utn_getNumero(&arcadeAux.tipoSonido, "1)Mono\n2)Stereo\n", "ERROR\n", 1, 2, 2);
				break;
			case 3:
				utn_getNumero(&arcadeAux.cantidadJugadores, "Ingrese la nueva cantidad de jugadores (1-4)\n"
						, "ERROR\n", JUGADORES_MIN, JUGADORES_MAX, 2);
				break;
			case 4:
//				utn_getNumero(&arcadeAux.capacidadFichas, "Ingrese la nueva capacidad de fichas\n"
//						, "ERROR\n", FICHAS_MIN, FICHAS_MAX, 2);
				break;
			case 5:

//				Salon_printByStatus(listaSalones, 0);
//
//				utn_getNumero(&idAux, "Ingrese el nuevo salon al que pertenece\n"
//				, "ERROR\n", 1000, 10000, 2);
//
//				if(Salon_findIndexById(listaSalones, idAux) >= 0) arcadeAux.FK_salon = idAux;
//				else printf("ERROR, ese ID es invalido\n");

				break;
			case 6:
				Juego_printByStatus(listaJuegos, 0);
				int idJuego;
				if(utn_getNumero(&idJuego, "Ingrese el ID del juego nuevo que contendra el arcade\n"
					, "ERROR\n", 1000, 10000, 2) == 0)
				{
					Juego* pJuego = Juego_getJuegoByID(listaJuegos, idJuego);
					if(pJuego != NULL)
					{
						if(pJuego->id == arcadeAux.FK_juego) printf("Ese es el juego que ya tenia cargado\n");
						else
						{
							arcadeAux.FK_juego = idJuego;
							printf("Ahora el arcade contiene el juego: %s\n",pJuego->nombre);
						}
					}
					else printf("ID invalido\n");
				}
				break;
			case 7:
				printf("Estos son los nuevos datos cargados:\n");
				Arcade_encbezadoTabla();
				Arcade_printOne(&arcadeAux);
				Arcade_pieTabla();

				if(validateExit_YN("Confirma? Y/N\n", "ERROR\n", 1) == 1)
				{
					*this = arcadeAux;
					printf("Se ha modificado el Arcade\n");
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

int Arcade_printOne(Arcade* this)
{
	int ret = -1;

	if(this != NULL)
	{
		char tipo[TIPO_SONIDO_LEN];
		switch(this->tipoSonido)
		{
		case MONO:
			strncpy(tipo,"MONO",TIPO_SONIDO_LEN);
			break;
		case STEREO:
			strncpy(tipo,"STEREO",TIPO_SONIDO_LEN);
			break;
		}

		printf("|%-4d|%-17s|%-11s|%11d|%12d|%10d|%10d|\n"
				,this->id
				,this->nacionalidad
				,tipo
				,this->cantidadJugadores
				,this->capacidadFichas
				,this->FK_salon
				,this->FK_juego);
	}

	return ret;
}

int Arcade_printByStatus(LinkedList* arcadeList, int status)
{
	int ret = -1;
	if(arcadeList != NULL)
	{
		int linkedListLenght = ll_len(arcadeList);
		if(linkedListLenght > 0)
		{
			Arcade_encbezadoTabla();
			for(int i=0; i<linkedListLenght; i++)
			{
				Arcade_printOne ( (Arcade*)ll_get( arcadeList, i) );

			}
			Arcade_pieTabla();
		}
		else ret = -2;//ERROR ll vacia
	}

	return ret;
}

int Arcade_printOneV3(Arcade* pArcade, Juego* pJuego)
{
	int ret = -1;

	if(pArcade != NULL && pJuego != NULL)
	{
		char tipo[TIPO_SONIDO_LEN];
		switch(pArcade->tipoSonido)
		{
		case MONO:
			strncpy(tipo,"MONO",TIPO_SONIDO_LEN);
			break;
		case STEREO:
			strncpy(tipo,"STEREO",TIPO_SONIDO_LEN);
			break;
		}

		printf("|%-4d|%-17s|%-11s|%11d|%12d|%-24s|%-12s|\n"
				,pArcade->id
				,pArcade->nacionalidad
				,tipo
				,pArcade->cantidadJugadores
				,pArcade->capacidadFichas
				,pJuego->nombre
				,pJuego->genero);
	}

	return ret;
}

int Arcade_printOneV2(Arcade* this, char* nombreSalon, char* nombreJuego)
{
	int ret = -1;

	if(this != NULL)
	{
		char tipo[TIPO_SONIDO_LEN];
		switch(this->tipoSonido)
		{
		case MONO:
			strncpy(tipo,"MONO",TIPO_SONIDO_LEN);
			break;
		case STEREO:
			strncpy(tipo,"STEREO",TIPO_SONIDO_LEN);
			break;
		}

		printf("|%-4d|%-17s|%-11s|%11d|%12d|%-10s|%-24s|\n"
				,this->id
				,this->nacionalidad
				,tipo
				,this->cantidadJugadores
				,this->capacidadFichas
				,nombreSalon
				,nombreJuego);
	}

	return ret;
}

int Arcade_printByStatusV3(LinkedList* arcadeList, LinkedList* listaJuegos)
{
	int ret = -1;
	if(arcadeList != NULL)
	{
		int linkedListLenght = ll_len(arcadeList);
		if(linkedListLenght > 0)
		{
			Arcade_encbezadoTablaV3();
			for(int i=0; i<linkedListLenght; i++)
			{
				Arcade* pArcade = ll_get(arcadeList, i);
				Juego* pJuego = Juego_getJuegoByID(listaJuegos, pArcade->FK_juego);
				Arcade_printOneV3(pArcade, pJuego);
			}
			Arcade_pieTablaV3();
		}
		else ret = -2;//ERROR ll vacia
	}

	return ret;
}

int Arcade_printByStatusV2(LinkedList* arcadeList, LinkedList* listaJuegos, LinkedList* listaSalones)
{
	int ret = -1;
	if(arcadeList != NULL)
	{
		int linkedListLenght = ll_len(arcadeList);
		if(linkedListLenght > 0)
		{
			Arcade_encbezadoTablaV2();
			for(int i=0; i<linkedListLenght; i++)
			{
				Arcade* pArcade = ll_get(arcadeList, i);
				Juego* pJuego = Juego_getJuegoByID(listaJuegos, pArcade->FK_juego);
				Salon* pSalon = Salon_getSalonByID(listaSalones, pArcade->FK_salon);
				Arcade_printOneV2(pArcade, pSalon->nombre, pJuego->nombre);
			}
			Arcade_pieTablaV2();
		}
		else ret = -2;//ERROR ll vacia
	}

	return ret;
}

void Arcade_encbezadoTablaV3(void)
{

	printf("+----+-----------------+-----------+-----------+------------+------------------------+------------+\n");
	printf("| ID |  NACIONALIDAD   |TIPO SONIDO| QTY JUGAD.| QTY FICHAS |         JUEGO          |   GENERO   |\n");
	printf("+----+-----------------+-----------+-----------+------------+------------------------+------------+\n");
}

void Arcade_pieTablaV3(void)
{
	printf("+----+-----------------+-----------+-----------+------------+------------------------+------------+\n");
}

void Arcade_encbezadoTablaV2(void)
{

	printf("+----+-----------------+-----------+-----------+------------+----------+------------------------+\n");
	printf("| ID |  NACIONALIDAD   |TIPO SONIDO| QTY JUGAD.| QTY FICHAS |   SALON  |         JUEGO          |\n");
	printf("+----+-----------------+-----------+-----------+------------+----------+------------------------+\n");
}

void Arcade_pieTablaV2(void)
{
	printf("+----+-----------------+-----------+-----------+------------+----------+------------------------+\n");
}

void Arcade_encbezadoTabla(void)
{

	printf("+----+-----------------+-----------+-----------+------------+----------+----------+\n");
	printf("| ID |  NACIONALIDAD   |TIPO SONIDO| QTY JUGAD.| QTY FICHAS | ID SALON | ID JUEGO |\n");
	printf("+----+-----------------+-----------+-----------+------------+----------+----------+\n");
}

void Arcade_pieTabla(void)
{
	printf("+----+-----------------+-----------+-----------+------------+----------+----------+\n");
}


//************Sorts************
int Arcade_sortByQTYjugadores(void* pArcade1, void* pArcade2)
{
	int ret = 0;
	int qtyJugadores1;
	int qtyJugadores2;

	Arcade_getCantidadJugadores(pArcade1, &qtyJugadores1);
	Arcade_getCantidadJugadores(pArcade2, &qtyJugadores2);

	if(qtyJugadores1 > qtyJugadores2)
	{
		ret = 1;
	}
	if(qtyJugadores1 < qtyJugadores2)
	{
		ret = -1;
	}


	return ret;
}

int Arcade_sortBySalonId(void* pArcade1, void* pArcade2)
{
	int ret = 0;
	int FK_salonID1;
	int FK_salonID2;

	Arcade_getFK_SalonId(pArcade1, &FK_salonID1);
	Arcade_getFK_SalonId(pArcade2, &FK_salonID2);

	if(FK_salonID1 > FK_salonID2) ret = 1;

	if(FK_salonID1 < FK_salonID2) ret = -1;

	return ret;
}

int Arcade_sortById(void* pArcade1, void* pArcade2)
{
	int ret = 0;
	int ID1;
	int ID2;

	Arcade_getId(pArcade1, &ID1);
	Arcade_getId(pArcade2, &ID2);

	if(ID1 > ID2) ret = 1;

	if(ID1 < ID2) ret = -1;

	return ret;
}













