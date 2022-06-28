/*
 * controller.c
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */
#include "salon.h"
#include "arcade.h"
#include "juegos.h"
#include "LinkedList.h"



/** \brief Guarda los datos de los salones en el archivo salones.csv (modo binario).
 *
 * \param path char*
 * \param pArraySalones LinkedList*
 * \return int
 *
 */
int controller_saveSalonesAsBinary(char* path , LinkedList* pArraySalones)
{
	int ret = -1;//ERROR path NULL
	if(path != NULL)
	{
		if(pArraySalones != NULL)
		{
			FILE* pSalonesBin = fopen(path,"wb");
			if(pSalonesBin != NULL)
			{
				Salon* pAux;

				int contador = 0;
//				int contadorExito = 0;
//				int contadorFail = 0;
				do
				{
					pAux = ll_get(pArraySalones,contador);

					fwrite(pAux,sizeof(Salon),1,pSalonesBin);
					contador++;
				}
				while(contador < ll_len(pArraySalones));
				printf("Guarde %d registros en forma binaria\n"
						"La ruta del archivo guardado es: %s\n\n",contador,path);
				fclose(pSalonesBin);
			}
			else ret = -3;//ERROR de fopen
		}
		else ret = -2;//ERROR parray NULL
	}
    return ret;
}

int controller_saveArcadesAsBinary(char* path , LinkedList* pArrayArcades)
{
	int ret = -1;//ERROR path NULL
	if(path != NULL)
	{
		if(pArrayArcades != NULL)
		{
			FILE* pArcadesBin = fopen(path,"wb");
			if(pArcadesBin != NULL)
			{
				Arcade* pAux;

				int contador = 0;
//				int contadorExito = 0;
//				int contadorFail = 0;
				do
				{
					pAux = ll_get(pArrayArcades,contador);

					fwrite(pAux,sizeof(Arcade),1,pArcadesBin);
					contador++;
				}
				while(contador < ll_len(pArrayArcades));
				printf("Guarde %d registros en forma binaria\n"
						"La ruta del archivo guardado es: %s\n\n",contador,path);
				fclose(pArcadesBin);
			}
			else ret = -3;//ERROR de fopen
		}
		else ret = -2;//ERROR parray NULL
	}
    return ret;
}

int controller_saveJuegosAsBinary(char* path , LinkedList* pArrayJuegos)
{
	int ret = -1;//ERROR path NULL
	if(path != NULL)
	{
		if(pArrayJuegos != NULL)
		{
			FILE* pJuegosBin = fopen(path,"wb");
			if(pJuegosBin != NULL)
			{
				Juego* pAux;

				int contador = 0;
//				int contadorExito = 0;
//				int contadorFail = 0;
				do
				{
					pAux = ll_get(pArrayJuegos,contador);

					fwrite(pAux,sizeof(Juego),1,pJuegosBin);
					contador++;
				}
				while(contador < ll_len(pArrayJuegos));
				printf("Guarde %d registros en forma binaria\n"
						"La ruta del archivo guardado es: %s\n\n",contador,path);
				fclose(pJuegosBin);
			}
			else ret = -3;//ERROR de fopen
		}
		else ret = -2;//ERROR parray NULL
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
int controller_loadSalonesFromBinary(char* path , LinkedList* pArraySalones)
{
	int ret = -1;//ERROR path
	if(path != NULL)
	{
		if(pArraySalones != NULL)
		{
			FILE* pSalonesBin = fopen(path, "r+b");
			if(pSalonesBin != NULL)
			{
				Salon* pSalonAux;
				int qty = 0;
				int contador = 0;
				do
				{
					pSalonAux = Salon_new();
					qty = fread(pSalonAux ,sizeof(Salon),1,pSalonesBin);
					if(qty == 1)
					{
						contador = contador + qty;
						ll_add(pArraySalones, pSalonAux);
					}
					else
					{
						Salon_delete(pSalonAux);
					}
				}
				while(qty == 1);
				printf("Se han cargado %d registros del archivo 'Salones.bin'\n",contador);
				fclose(pSalonesBin);
				ret = 0;//SUCCESS
			}
			else
			{
				ret = -3;//ERROR de fopen
				printf("Por favor asignar la ruta correcta al directorio del archivo de salones\n");
			}

		}
		else ret = -2;//ERROR linked list NULL
	}
    return ret;
}

int controller_loadArcadesFromBinary(char* path , LinkedList* pArrayArcades)
{
	int ret = -1;//ERROR path
	if(path != NULL)
	{
		if(pArrayArcades != NULL)
		{
			FILE* pArcadesBin = fopen(path, "r+b");
			if(pArcadesBin != NULL)
			{
				Arcade* pArcadeAux;
				int qty = 0;
				int contador = 0;
				do
				{
					pArcadeAux = Arcade_new();
					qty = fread(pArcadeAux ,sizeof(Arcade),1,pArcadesBin);
					if(qty == 1)
					{
						contador = contador + qty;
						ll_add(pArrayArcades, pArcadeAux);
					}
					else
					{
						Arcade_delete(pArcadeAux);
					}
				}
				while(qty == 1);
				printf("Se han cargado %d registros del archivo 'Arcades.bin'\n",contador);
				fclose(pArcadesBin);
				ret = 0;//SUCCESS
			}

			else
			{
				ret = -3;//ERROR de fopen
				printf("Por favor asignar la ruta correcta al directorio del archivo de Arcades\n");
			}
		}
		else ret = -2;//ERROR linked list NULL
	}
    return ret;
}

int controller_loadJuegosFromBinary(char* path , LinkedList* pArrayJuegos)
{

	int ret = -1;//ERROR path
	if(path != NULL)
	{
		if(pArrayJuegos != NULL)
		{
			FILE* pJuegosBin = fopen(path, "r+b");
			if(pJuegosBin != NULL)
			{
				Juego* pJuegoAux;
				int qty = 0;
				int contador = 0;

				do
				{
					pJuegoAux = Juego_new();
					qty = fread(pJuegoAux ,sizeof(Juego),1,pJuegosBin);
					if(qty == 1)
					{
						contador = contador + qty;
						ll_add(pArrayJuegos, pJuegoAux);
					}
					else
					{
						Juego_delete(pJuegoAux);
					}
				}
				while(qty == 1);
				printf("Se han cargado %d registros del archivo 'Juegos.bin'\n",contador);
				fclose(pJuegosBin);
				ret = 0;//SUCCESS
			}

			else
			{
				ret = -3;//ERROR de fopen
				printf("Por favor asignar la ruta correcta al directorio del archivo de Juegos\n");
			}
		}
		else ret = -2;//ERROR linked list NULL
	}
    return ret;
}
