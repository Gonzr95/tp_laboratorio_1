/*
 * arcade.h
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */

#ifndef ARCADE_H_
#include "juegos.h"
#define ARCADE_H_
#define NACIONALIDAD_LEN 20
#define MONO 1
#define STEREO 2
#define TIPO_SONIDO_LEN 10
#define JUGADORES_MIN 1
#define JUGADORES_MAX 4
#define FICHAS_MIN 10
#define FICHAS_MAX 50

typedef struct
{
	int id;
	char nacionalidad[NACIONALIDAD_LEN];
	int tipoSonido;
	int cantidadJugadores;
	int capacidadFichas;
	int FK_salon;
	int FK_juego;
}Arcade;

//************Constructores************
Arcade* Arcade_new(void);
void Arcade_delete(Arcade* this);


//************Getters************
int Arcade_getFK_SalonId(Arcade* this,int* id);
int Arcade_getId(Arcade* this,int* id);
int Arcade_getCantidadJugadores(Arcade* this,int* QTYjugadores);
Arcade* Arcade_getArcadeByID(LinkedList* pListaArcades, int id);
Arcade* Arcade_getArcadeByFK_salonID(LinkedList* pListaArcades, int FK_salon);

//************ABM************

void menuArcades(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos);
int Arcade_alta(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos);
int Arcade_pedirDatos(Arcade* arcadenAux, LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos);
int Arcade_baja (LinkedList* listaArcades, LinkedList* listaJuegos, LinkedList* listaSalones);
int Arcade_findIndexById(LinkedList* listaArcades, int id);
int Arcade_modificar(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos);
Arcade* Arcade_modificador(Arcade* this, LinkedList* listaSalones, LinkedList* listaJuegos);


//************Printers************
int Arcade_printOne(Arcade* this);
int Arcade_printByStatus(LinkedList* arcadeList, int status);
void Arcade_encbezadoTablaV3(void);
void Arcade_pieTablaV3(void);
int Arcade_printByStatusV3(LinkedList* arcadeList, LinkedList* listaJuegos);
int Arcade_printOneV3(Arcade* pArcade, Juego* pJuego);
int Arcade_printOneV2(Arcade* this, char* nombreSalon, char* nombreJuego);
int Arcade_printByStatusV2(LinkedList* arcadeList, LinkedList* listaJuegos, LinkedList* listaSalones);
void Arcade_encbezadoTablaV2(void);
void Arcade_pieTablaV2(void);
void Arcade_encbezadoTabla(void);
void Arcade_pieTabla(void);


//************Sorts************
int Arcade_sortBySalonId(void* pArcade1, void* pArcade2);
int Arcade_sortByQTYjugadores(void* pArcade1, void* pArcade2);
int Arcade_sortById(void* pArcade1, void* pArcade2);


#endif /* ARCADE_H_ */
