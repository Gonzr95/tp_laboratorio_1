/*
 * juegos.h
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */
#include "LinkedList.h"
#ifndef JUEGOS_H_
#define JUEGOS_H_
#define JUEGO_NAME_LEN 30
#define EMPRESA_LEN 30
#define GENERO_LEN 30


typedef struct
{
	int id;
	char nombre[JUEGO_NAME_LEN];
	char empresa[EMPRESA_LEN];
	char genero[GENERO_LEN];
}Juego;

//************Constructores************
Juego* Juego_new(void);
void Juego_delete(Juego* this);

//************Getters************
Juego* Juego_getJuegoByID(LinkedList* pListaJuegos, int id);


//************ABM************
void menuJuegos(LinkedList* listaJuegos);
int Juego_alta(LinkedList* listaJuegos);
int Juego_pedirDatos(Juego* juegoAux, LinkedList* listaArcades);
int Juego_baja (LinkedList* listaJuegos);
int Juego_findIndexById(LinkedList* listaJuegos, int id);
int Juego_modificar(LinkedList* listaJuegos);


//************Printers************
int Juego_printByStatus(LinkedList* juegoList, int status);
void Juego_encbezadoTabla(void);
void Juego_pieTabla(void);
int Juego_printOne(Juego* this);
Juego* Juego_modificador(Juego* this);



#endif /* JUEGOS_H_ */
