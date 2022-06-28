/*
 ============================================================================
 Name        : 2do_parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "utn.h"
#include "LinkedList.h"
#include "salon.h"
#include "arcade.h"
#include "juegos.h"
#include "controller.h"
#include "informes.h"

#define SALONES 1
#define ARCADES 2
#define JUEGOS 3
#define INFORMES 4

char* SALON_BIN_CASA = "D:\\Proyectos\\Eclipse\\Labo_1_2daParte\\2do_parcial\\src\\salones.bin";
char* ARCADE_BIN_CASA = "D:\\Proyectos\\Eclipse\\Labo_1_2daParte\\2do_parcial\\src\\arcades.bin";
char* JUEGOS_BIN_CASA = "D:\\Proyectos\\Eclipse\\Labo_1_2daParte\\2do_parcial\\src\\juegos.bin";

char* SALON_BIN_LABURO = "C:\\Users\\gonzalo.rodriguez\\Desktop\\Gonza\\Workspace_3_2do_cuatri\\2do_parcial\\src\\salones.bin";
char* ARCADE_BIN_LABURO = "C:\\Users\\gonzalo.rodriguez\\Desktop\\Gonza\\Workspace_3_2do_cuatri\\2do_parcial\\src\\arcades.bin";
char* JUEGOS_BIN_LABURO = "C:\\Users\\gonzalo.rodriguez\\Desktop\\Gonza\\Workspace_3_2do_cuatri\\2do_parcial\\src\\juegos.bin";


int main(void)
{
	setbuf(stdout,NULL);
	LinkedList* listaSalones = ll_newLinkedList();
	LinkedList* listaArcades = ll_newLinkedList();
	LinkedList* listaJuegos = ll_newLinkedList();
	controller_loadSalonesFromBinary(SALON_BIN_CASA, listaSalones);
	controller_loadArcadesFromBinary(ARCADE_BIN_CASA, listaArcades);
	controller_loadJuegosFromBinary(JUEGOS_BIN_CASA, listaJuegos);

	int menu;
	do
	{
		utn_getNumero(&menu, "\n\n****Menu principal****\n"
				"1)Submenu salon\n"
				"2)Submenu arcades\n"
				"3)Submenu juegos\n"
				"4)Submenu informes\n"
				"0)Salir\n", "ERROR\n", 0, 10, 2);
		switch(menu)
		{
		case SALONES:
			menuSalones(listaSalones, listaArcades);
			break;

		case ARCADES:
			menuArcades(listaArcades, listaSalones, listaJuegos);
			break;

		case JUEGOS:
			menuJuegos(listaJuegos);
			break;

		case INFORMES:
			menuInformes(listaSalones, listaArcades, listaJuegos);
			break;
		}


	}while(menu != 0);

	if(validateExit_YN("Desea guardar los cambios? Y/N\n", "ERROR\n", 1) == 1)
	{
		controller_saveSalonesAsBinary(SALON_BIN_CASA, listaSalones);
		controller_saveArcadesAsBinary(ARCADE_BIN_CASA, listaArcades);
		controller_saveJuegosAsBinary(JUEGOS_BIN_CASA, listaJuegos);
	}


	return EXIT_SUCCESS;
}








