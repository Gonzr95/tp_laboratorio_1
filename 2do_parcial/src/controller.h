/*
 * controller.h
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_saveSalonesAsBinary(char* path , LinkedList* pArraySalones);
int controller_loadSalonesFromBinary(char* path , LinkedList* pArraySalones);

int controller_saveArcadesAsBinary(char* path , LinkedList* pArrayArcades);
int controller_loadArcadesFromBinary(char* path , LinkedList* pArrayArcades);

int controller_saveJuegosAsBinary(char* path , LinkedList* pArrayJuegos);
int controller_loadJuegosFromBinary(char* path , LinkedList* pArrayJuegos);

#endif /* CONTROLLER_H_ */
