/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include "utn.h"
#include "LinkedList.h"
#ifndef PASSENGER_H_
#define PASSENGER_H_
#define NOMBRE_LEN 15
#define ECONOMY_CLASS 1
#define FIRST_CLASS 2
#define EXECUTIVE_CLASS 3
#define EN_HORARIO 1
#define ATERRIZADO 2
#define DEMORADO 3
#define EN_VUELO 4

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int isEmpty;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,int tipoPasajeroStr);
Passenger* Passenger_newConParametrosTxt(char nombre[], char apellido[], char precio[], char tipoDePasajero[],
char codigoDeVuelo[], char id[], char isEmpty[]);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);
int Passenger_setIdTxt(Passenger* this,char id[]);


int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
int Passenger_setTipoPasajeroTxt(Passenger* this, char tipoDePasajero[]);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_setPrecioTxt(Passenger* this, char precio[]);


int Passenger_setIsEmptyTxt(Passenger* this, char isEmpty[]);

void Passenger_encbezadoTabla(void);
void Passenger_pieTabla(void);
int Passenger_printOne(Passenger* this);
int Passenger_printByStatus(LinkedList* passengersList, int status);





int Passenger_pedirDatos(Passenger* pPassenger, LinkedList* arrayPassengers);
int Passenger_alta(LinkedList* listaPasajeros);
int Passenger_findIndexById(LinkedList* passengerList, int id);
int Passenger_baja (LinkedList* passengerList);
Passenger* Passenger_modificador(Passenger* this);
int Passenger_modificar(LinkedList* passengerList);



int Passenger_parseFlightStatus(Passenger* this, char* flightStatus);
int Passenger_getFlightSatusParseado(Passenger* this,char* flightStatus);
int Passenger_parseTypePassenger(Passenger* this, char* typePassenger);
int Passenger_getTypePassengerParseado(Passenger* this,char* typePassenger);




void passenger_ordenarDescendentemente(LinkedList* pArrayListPassenger);
void passenger_ordenarAscendentemente(LinkedList* pArrayListPassenger);
void passenger_ordenar(LinkedList* pArrayListPassenger ,void(*pFuncion)(LinkedList*));

#endif /* PASSENGER_H_ */
