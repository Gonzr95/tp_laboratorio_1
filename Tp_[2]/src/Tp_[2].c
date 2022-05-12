/*
 ============================================================================
 Name        : Tp_[2].c
 Author      : Gonzalo Rodriguez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "passenger.h"

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int idAux;

	Passenger passenger[PASSENGER_LEN];
	pass_InitPassengers(passenger, PASSENGER_LEN);

	do
	{
		utn_getNumero(&opcion, "----Menú principal----\n"
				"1)Alta de pasajero\n"
				"2)Modificar pasajero\n"
				"3)Baja pasajero\n"
				"4)Informar\n"
				"5)Alta forzada\n"
				"6)Ordenar por apellido y tipo de pasajero\n"
				"7)Salir\n\n",
				"Error, revise las opciones\n", 1, 7, 2);
		switch(opcion)
		{
		case 1:
			//-------ALTA-------
			pass_altaPassengerV2(passenger, PASSENGER_LEN);
			break;
		case 2:
			//-------MODIFICACION-------
			pass_modifyPassenger(passenger, PASSENGER_LEN);
			break;
		case 3:
			//-------BAJA-------
			if(utn_getNumero(&idAux, "Ingrese el ID del pasajero que quiere dar de baja\n"
			,"ERROR\n", 1000, 3000, 2) == 0)
			{
				if(pass_removePassenger(passenger, PASSENGER_LEN, idAux) == 0)
				{
					printf("Se ha dado de baja correctamente\n");
				}
				else
				{
					printf("Hubo un error\n");
				}
			}
			else
			{
				printf("ERROR, vuelvo al menu\n");
			}
			break;
		case 4:
			//-------INFORMAR-------
			pass_printByStatus(passenger, PASSENGER_LEN, OCUPADO);
			break;
		case 5:
			//-------ALTA FORZADA-------
			pass_cargaForzada(passenger, PASSENGER_LEN);
			break;
		case 6:
			informes(passenger, PASSENGER_LEN);
		}
	}
	while(opcion != 7);

	return EXIT_SUCCESS;
}
