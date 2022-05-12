/*
 * passenger.h
 *
 *  Created on: 26 Apr 2022
 *      Author: gonzr
 */

#ifndef PASSENGER_H_
#include "utn.h"
#define PASSENGER_H_
#define NAME_LEN 51
#define SURNAME_LEN 51
#define FLYCODE_LEN 10
#define DESCRIPCION_LEN 200
#define LIBRE 1
#define OCUPADO 0
#define PASSENGER_LEN 2000

typedef struct
{
	int id;
	char name[NAME_LEN];
	char surname[SURNAME_LEN];
	float price;
	char flyCode[FLYCODE_LEN];
	int passengerType;
	int flightStatus;
	int isEmpty;
}Passenger;

int pass_InitPassengers(Passenger array[], int length);
int pass_getEmptyIndex(Passenger* array, int length);
int addPassengers(Passenger array[], int len, char* name, char* lastName, float price, int passengerType, char* flyCode);
int pass_printByStatus(Passenger* list, int length, int status);
Passenger pass_cargarPassenger (void);
int pass_findPassengerById(Passenger* list, int length, int id);
int pass_modifyPassenger(Passenger* list, int length);
void pass_passengerModifier(Passenger* aux);







int pass_addPassenger(Passenger* list, int length, int id, char* name, char* surname
				, float price, int typePassenger, char* flycode);
int pass_altaPassengerV2(Passenger* list, int length);
int pass_cargaForzada(Passenger* list, int length);
int pass_removePassenger(Passenger* list, int length, int id);
int pass_sortPassengers(Passenger* list, int length, int order);
int pass_ascendingBubbleSorting(Passenger* list, int length);
int pass_descendingBubbleSorting(Passenger* list, int length);
int pass_copyArray(Passenger* list, Passenger* listCopy, int length);
int pass_calcAveragePrice(float* pResultado, Passenger* list, int length);
int pass_calcTotalPrices(float* pResultado, Passenger* list, int length);
int pass_calcSuperiorAlPromedio(Passenger* list, int length, float promedio);



void encabezadoTabla(void);
void pieTabla(void);
void informes(Passenger* list, int length);


#endif /* PASSENGER_H_ */
