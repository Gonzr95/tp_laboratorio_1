/*
 * informes.c
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */
#include "informes.h"
#include "salon.h"
#include "juegos.h"
#include "utn.h"

void menuInformes(LinkedList* listaSalones, LinkedList* listaArcades, LinkedList* listaJuegos)
{
	int opcion;
	do
	{
		utn_getNumero(&opcion, "***Menu informes***\n"
				"1)Listar salones con mas de 4 arcades\n"
				"2)Listar arcades para mas de 2 jugadores\n"
				"3)Listar info de salon solicitado\n"
				"4)Listar salones completos (4 plataforma, 3 laberinto, 5 aventura)\n"
				"5)Listar arcades de un determinado salon\n"
				"6)Imprimir salon con mas numero de arcades (ascendente segun ID de arcade)\n"
				"7)Imprimir arcades con sonido MONO y genero plataforma, ordenados por nombres de juegos\n"
				"0)Salir\n", "ERROR\n", 0, 10, 2);
		switch(opcion)
		{
		case 1:
			informe_uno(listaSalones, listaArcades);
			break;
		case 2:
			informe_dos(listaSalones, listaArcades);
			break;
		case 3:
			informe_tres(listaSalones);
			break;
		case 4:
			informe_cuatro(listaArcades, listaSalones, listaJuegos);
			break;
		case 5:
			informe_cinco(listaArcades, listaSalones, listaJuegos);
			break;
		case 6:
			informe_seis(listaSalones, listaArcades);
			break;
		case 7:
			informe_siete(listaArcades, listaJuegos);
			break;
		}

	}while(opcion != 0);
}

void informe_uno(LinkedList* listaSalones, LinkedList* listaArcades)
{
	if(listaArcades != NULL  &&  listaSalones !=  NULL)
	{
		LinkedList* listaArcadesCopy = ll_clone(listaArcades);
		ll_sort(listaArcadesCopy, Arcade_sortBySalonId, ASCENDENTE);
		Arcade* pArcadeAux;
		int flagHayQueImprimir=0;
		int contadorArcades = 1;
		int FK_SalonID;
		int i;
		int j;
		for(i=0; i<ll_len(listaArcadesCopy); i++)
		{
			pArcadeAux = ll_get(listaArcadesCopy, i);
			FK_SalonID = pArcadeAux->FK_salon;
			for(j=i+1; j<ll_len(listaArcades); j++)
			{
				pArcadeAux = ll_get(listaArcadesCopy, j);
				if(FK_SalonID == pArcadeAux->FK_salon)
				{
					contadorArcades++;
				}
				else break;
			}
			if(contadorArcades > 4)
			{
				int indexImprimir = Salon_findIndexById(listaSalones, FK_SalonID);
				if(flagHayQueImprimir == 0)
				{
					Salon_encbezadoTabla();
				}
				Salon* pSalon = ll_get(listaSalones, indexImprimir);
				Salon_printOne(pSalon);
				flagHayQueImprimir = 1;
			}
			contadorArcades = 1;
			i=j-1;
		}
		if(flagHayQueImprimir == 1) Salon_pieTabla();
		else printf("No hay Salones con mas de 4 arcades\n");
	}
}

void informe_dos(LinkedList* listaSalones, LinkedList* listaArcades)
{
	if(listaArcades != NULL  &&  listaSalones !=  NULL)
	{
		LinkedList* listaArcadesCopy = ll_clone(listaArcades);
		ll_sort(listaArcadesCopy, Arcade_sortByQTYjugadores, DESCENDENTE);
//		Arcade_printByStatus(listaArcadesCopy, 0);

		Arcade* pArcadeAux;
		int flagHayQueImprimir=0;

		int i;
		for(i=0; i<ll_len(listaArcadesCopy); i++)
		{
			pArcadeAux = ll_get(listaArcadesCopy, i);
			if(pArcadeAux->cantidadJugadores > 2)
			{
//				printf("Encontre un arcade para mas de 2 jugadores\n");
				if(flagHayQueImprimir == 0)
				{
					informe_dosEncbezadoTabla();
					flagHayQueImprimir = 1;
				}
				int indexSalon = Salon_findIndexById(listaSalones, pArcadeAux->FK_salon);
				Salon* pSalon = ll_get(listaSalones, indexSalon);
				informe_dosPrintOneArcadeYSalon(pArcadeAux, pSalon->nombre);

			}
		}
		if(flagHayQueImprimir == 1) informe_dosPieTabla();
		else printf("No hay Salones con mas de 4 arcades\n");
	}
}

void informe_tres(LinkedList* listaSalones)
{
	if(listaSalones != NULL)
	{
		Salon_printByStatus(listaSalones, 0);
		int idAux;
		if(utn_getNumero(&idAux, "Ingrese el ID del salon que desea ver la informacion\n", "ERROR\n", 1000, 10000, 2) == 0)
		{
			Salon* pSalon = Salon_getSalonByID(listaSalones, idAux);
			Salon_encbezadoTabla();
			Salon_printOne(pSalon);
			Salon_pieTabla();
		}
		else
		{
			printf("Error, vuelvo al menu\n");
		}
	}
}

	//************Printers************

int informe_dosPrintOneArcadeYSalon(Arcade* this, char salonNombre[])
{
	int ret = -1;

	if(this != NULL && salonNombre != NULL)
	{
		ret = 0;
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
		printf("|%-4d|%-17s|%-11s|%11d|%12d|%10d|%10d|%-15s|\n"
				,this->id
				,this->nacionalidad
				,tipo
				,this->cantidadJugadores
				,this->capacidadFichas
				,this->FK_salon
				,this->FK_juego
				,salonNombre);
	}
	return ret;
}

void informe_dosEncbezadoTabla(void)
{

	printf("+----+-----------------+-----------+-----------+------------+----------+----------+---------------+\n");
	printf("| ID |  NACIONALIDAD   |TIPO SONIDO| QTY JUGAD.| QTY FICHAS | ID SALON | ID JUEGO |  NOMBRE SALON |\n");
	printf("+----+-----------------+-----------+-----------+------------+----------+----------+---------------+\n");
}

void informe_dosPieTabla(void)
{
	printf("+----+-----------------+-----------+-----------+------------+----------+----------+---------------+\n");
}

void  informe_cuatro(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos)
{
	if(listaArcades != NULL && listaSalones != NULL && listaJuegos != NULL)
	{
		LinkedList* listaArcadesCopy = ll_clone(listaArcades);
		ll_sort(listaArcadesCopy, Arcade_sortBySalonId, ASCENDENTE);

//		DEBUG();
//		Arcade_printByStatus(listaArcadesCopy, 0);
//		Juego_printByStatus(listaJuegos, 0);
//		DEBUG();

		Arcade* pArcadeAux1;

		int plataforma = 0;
		int laberinto = 0;
		int aventura = 0;
		int salonCompleto = 0;
		int salonID;

		for(int i=0; i<ll_len(listaArcadesCopy); i++)
		{
			pArcadeAux1 = ll_get(listaArcadesCopy, i);
			if(pArcadeAux1->FK_salon != salonID)
			{
				plataforma = 0;
				laberinto = 0;
				aventura = 0;
				salonCompleto = 0;
			}
			salonID = pArcadeAux1->FK_salon;
			Juego* juegoAux = Juego_getJuegoByID(listaJuegos, pArcadeAux1->FK_juego);

			if(strncmp("Plataforma",juegoAux->genero,GENERO_LEN) == 0) plataforma++;
			if(strncmp("Laberinto",juegoAux->genero,GENERO_LEN) == 0) laberinto++;
			if(strncmp("Aventura",juegoAux->genero,GENERO_LEN) == 0) aventura++;
			if(plataforma >= 4 && laberinto >= 3 && aventura >= 5 && salonCompleto == 0)
			{
				salonCompleto = 1;
				Salon* salonCompleto = Salon_getSalonByID(listaSalones, pArcadeAux1->FK_salon);
				printf("El salon: %s esta completo\n",salonCompleto->nombre);
			}
		}
	}
}

void informe_cinco(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos)
{
	if(listaArcades != NULL && listaSalones != NULL)
	{
		int idSalon;
		char tipo[TIPO_LEN];
		int contadorArcades = 0;
		int flagHayArcades = 0;
		Salon_printByStatus(listaSalones, 0);
		utn_getNumero(&idSalon, "Ingrese el ID del salon que busca\n", "ERROR\n", 1000, 10000, 2);
		Salon* salonAux = Salon_getSalonByID(listaSalones, idSalon);
		if(salonAux != NULL)
		{
//			Salon_printOne(salonAux);
			Arcade* pArcadeAux;
			Juego* pJuegoAux;
			for(int i=0; i<ll_len(listaArcades); i++)
			{
				pArcadeAux = ll_get(listaArcades, i);
				if(pArcadeAux->FK_salon == salonAux->id)
				{
					contadorArcades++;
					if(flagHayArcades == 0)
					{

						printf("Salon: %s\n",salonAux->nombre);
						switch(salonAux->tipo)
						{
						case SHOPPING:
							strncpy(tipo,"Shopping",TIPO_LEN);
							break;
						case LOCAL:
							strncpy(tipo,"Local",TIPO_LEN);
							break;
						}
						printf("Tipo: %s\n",tipo);
						Juego_encbezadoTabla();
					}
					flagHayArcades = 1;
					pJuegoAux = Juego_getJuegoByID(listaJuegos, pArcadeAux->FK_juego);
//					printf("%d-Arcade nacionalidad: %s  con el juego: %s  pertenece al salon: %s\n",contadorArcades,pArcadeAux->nacionalidad,pJuegoAux->nombre,salonAux->nombre);
					Juego_printOne(pJuegoAux);
				}
				//arcades: datos junto con el nombre del juego que lo compone
				//salon: nombre y tipo.
			}
			if(flagHayArcades == 0) printf("Ese salon no tiene arcades\n");
			else
			{
				Juego_pieTabla();
				printf("****Total de arcades: %d****\n",contadorArcades);
			}

		}
	}
}

void informe_seis(LinkedList* listaSalones, LinkedList* listaArcades)
{
	if(listaArcades != NULL && listaSalones != NULL)
	{
		LinkedList* listaArcadesCopy = ll_clone(listaArcades);
		ll_sort(listaArcadesCopy, Arcade_sortBySalonId, DESCENDENTE);

		Arcade* pArcadeAux;
		LinkedList* arcadePrintList = ll_newLinkedList();
		int salonMaxArcadesID;
		int contadorArcades = 1;
		int max = 1;
		int FK_SalonID;
		int i;
		int j;

		for(i=0; i<ll_len(listaArcadesCopy); i++)
		{

			pArcadeAux = ll_get(listaArcadesCopy, i);
			FK_SalonID = pArcadeAux->FK_salon;
			for(j=i+1; j<ll_len(listaArcades); j++)
			{
				pArcadeAux = ll_get(listaArcadesCopy, j);
				if(FK_SalonID == pArcadeAux->FK_salon)
				{
					contadorArcades++;
				}
				else break;
			}
			if(contadorArcades >= max)
			{
				max = contadorArcades;
				salonMaxArcadesID = pArcadeAux->FK_salon;
			}
			contadorArcades = 1;
			i=j-1;
		}

		Salon* pSalon = Salon_getSalonByID(listaSalones, salonMaxArcadesID);
		printf("El salon con mas cantidad de arcades es: \n");
		Salon_encbezadoTabla();
		Salon_printOne(pSalon);
		Salon_pieTabla();
		printf("Tiene %d arcades\n",max);
//		Salon_printOne(pSalon);
		int k;
		for(k=0; k<ll_len(listaArcades); k++)
		{
			pArcadeAux = ll_get(listaArcades, k);
			if(pArcadeAux->FK_salon == salonMaxArcadesID)
			{

				ll_add(arcadePrintList, pArcadeAux);
			}
		}
		ll_sort(arcadePrintList, Arcade_sortById, ASCENDENTE);
		Arcade_printByStatus(arcadePrintList, 0);
	}
}

void informe_siete(LinkedList* listaArcades, LinkedList* listaJuegos)
{
	if(listaArcades != NULL && listaJuegos != NULL)
	{
		LinkedList* listaArcadesNueva = ll_newLinkedList();
		for(int i = 0; i<ll_len(listaArcades); i++)
		{
			Arcade* pArcade = ll_get(listaArcades, i);
			Juego* pJuego = Juego_getJuegoByID(listaJuegos, pArcade->FK_juego);

			int genero = strncmp(pJuego->genero,"Plataforma",GENERO_LEN);

			if(pArcade->tipoSonido == MONO && genero == 0)
			{
				ll_add(listaArcadesNueva, pArcade);
			}
		}


		informe_siete_sortArcadeByJuegoName(listaJuegos, listaArcadesNueva);

		informe_sietePrint(listaJuegos, listaArcadesNueva);

	}
}

void informe_sietePrint(LinkedList* listaJuegos, LinkedList* listaArcadesMono)
{
	if(listaArcadesMono != NULL && listaJuegos != NULL && ll_len(listaArcadesMono)>0)
	{
		Arcade* pArcade;
		Juego* pJuego;
		informe_sieteEncabezado();

		for(int i=0; i<ll_len(listaArcadesMono); i++)
		{
			pArcade =  ll_get(listaArcadesMono, i);
			pJuego = Juego_getJuegoByID(listaJuegos, pArcade->FK_juego);
			informe_sietePrintOne(pJuego, pArcade);
		}
		informe_sietePie();
	}
	else
	{
		printf("No hay arcades que cumplan con los requisitos solicitados\n");
	}
}

void informe_sietePrintOne(Juego* pJuego, Arcade* pArcade)
{
	if(pJuego != NULL && pArcade != NULL)
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
		printf("|%-4d|%-17s|%-11s|%11d|%12d|%10d|%10d|%-14s|\n"
				,pArcade->id
				,pArcade->nacionalidad
				,tipo
				,pArcade->cantidadJugadores
				,pArcade->capacidadFichas
				,pArcade->FK_salon
				,pArcade->FK_juego
				,pJuego->nombre);
	}
}

void informe_sieteEncabezado()
{
	printf("+----+-----------------+-----------+-----------+------------+----------+----------+--------------+\n");
	printf("| ID |  NACIONALIDAD   |TIPO SONIDO| QTY JUGAD.| QTY FICHAS | ID SALON | ID JUEGO | NOMBRE JUEGO |\n");
	printf("+----+-----------------+-----------+-----------+------------+----------+----------+--------------+\n");
}

void informe_sietePie()
{
	printf("+----+-----------------+-----------+-----------+------------+----------+----------+--------------+\n");
}

void informe_siete_sortArcadeByJuegoName(LinkedList* listaJuegos, LinkedList* listaArcadesMono)
{
	if(listaArcadesMono != NULL && listaJuegos != NULL)
	{

		Arcade* pArcadeMono1;
		Arcade* pArcadeMono2;
		Juego* pJuegoPlataforma1;
		Juego* pJuegoPlataforma2;
		int listaLenght = ll_len(listaArcadesMono);

		int flagSwap;
		do
		{
			flagSwap = 0;
			for(int i=0; i<listaLenght-1; i++)
			{
				pArcadeMono1 = ll_get(listaArcadesMono, i);
				pJuegoPlataforma1 = Juego_getJuegoByID(listaJuegos, pArcadeMono1->FK_juego);

				pArcadeMono2 = ll_get(listaArcadesMono, i+1);
				pJuegoPlataforma2 = Juego_getJuegoByID(listaJuegos, pArcadeMono2->FK_juego);

				int resultadoComparasion;
				resultadoComparasion = strncmp(pJuegoPlataforma1->nombre,pJuegoPlataforma2->nombre,JUEGO_NAME_LEN);

				if(resultadoComparasion > 0)
				{
					ll_set(listaArcadesMono, i+1, pArcadeMono1);
					ll_set(listaArcadesMono, i, pArcadeMono2);
					flagSwap = 1;
				}
			}
		}while(flagSwap);


	}
}



























