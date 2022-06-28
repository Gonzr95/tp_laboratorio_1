/*
 * salon.h
 *
 *  Created on: 24 Jun 2022
 *      Author: gonzr
 */
#include "LinkedList.h"
#ifndef SALON_H_
#define SALON_H_
#define NOMBRE_LEN 50
#define DIRECCION_LEN 50
#define TIPO_LEN 20
#define SHOPPING 1
#define LOCAL 2
#define ALTA 1
#define BAJA 2
#define MODIFICACION 3
#define IMPRESION 4

typedef struct
{
	int id;
	char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	int tipo;
}Salon;

//************Constructores Destructores************
Salon* Salon_new();
Salon* Salon_newParametros(char* idStr,char* nombreStr, char* direccionStr, int tipoStr);
Salon* Salon_newConParametrosTxt(char nombre[], char direccion[], char tipo[]);
void Salon_delete(Salon* this);


//************Setters************
int Salon_setId(Salon* this,int id);
int Salon_setIdTxt(Salon* this, char id[]);
int Salon_setNombre(Salon* this,char* nombre);
int Salon_setDireccion(Salon* this,char* direccion);
int Salon_setTipoSalon(Salon* this,int tipoSalon);
int Salon_setTipoSalonTxt(Salon* this, char tipoSalon[]);

//************Getters************
int Salon_getId(Salon* this,int* id);
int Salon_getNombre(Salon* this,char* nombre);
int Salon_getDireccion(Salon* this,char* direccion);
int Salon_getTipo(Salon* this,int* tipo);
Salon* Salon_getSalonByID(LinkedList* pListaSalones, int id);

//************ABM************
void menuSalones(LinkedList* listaSalones, LinkedList* listaArcades);
int Salon_alta(LinkedList* listaSalones);
int Salon_pedirDatos(Salon* pSalon, LinkedList* arraySalones);
int Salon_modificar(LinkedList* listaSalones);
int Salon_findIndexById(LinkedList* listaSalones, int id);
Salon* Salon_modificador(Salon* this);
int Salon_baja (LinkedList* listaSalones, LinkedList* listaArcades);

//************Printers************
int Salon_printByStatus(LinkedList* salonList, int status);
int Salon_printOne(Salon* this);
void Salon_encbezadoTabla(void);
void Salon_pieTabla(void);
//************TOOLS************
int Salon_checkArcades(int salonID, LinkedList* listaArcades);


#endif /* SALON_H_ */
