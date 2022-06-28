/*
 * informes.h
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */
#include "salon.h"
#include "juegos.h"
#include "arcade.h"

#ifndef INFORMES_H_
#define INFORMES_H_

void menuInformes(LinkedList* listaSalones, LinkedList* listaArcades, LinkedList* listaJuegos);

void informe_uno(LinkedList* listaSalones, LinkedList* listaArcades);
void informe_dos(LinkedList* listaSalones, LinkedList* listaArcades);
void informe_tres(LinkedList* listaSalones);
void  informe_cuatro(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos);
void informe_cinco(LinkedList* listaArcades, LinkedList* listaSalones, LinkedList* listaJuegos);
void informe_seis(LinkedList* listaSalones, LinkedList* listaArcades);
void informe_siete(LinkedList* listaArcades, LinkedList* listaJuegos);
void informe_siete(LinkedList* listaArcades, LinkedList* listaJuegos);

//************Printers************
int informe_dosPrintOneArcadeYSalon(Arcade* this, char salonNombre[]);
void informe_dosPieTabla(void);
void informe_dosEncbezadoTabla(void);
void informe_sieteEncabezado();
void informe_sietePie();
void informe_sietePrintOne(Juego* pJuego, Arcade* pArcade);
void informe_sietePrint(LinkedList* listaJuegos, LinkedList* listaArcadesMono);

//************Sorts************
void informe_siete_sortArcadeByJuegoName(LinkedList* listaJuegos, LinkedList* listaArcadesMono);

#endif /* INFORMES_H_ */
