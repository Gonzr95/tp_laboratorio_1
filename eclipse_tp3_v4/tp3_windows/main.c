#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
char* PASSENGERS_CSV_DIR_LABURO ="C:\\Users\\gonzalo.rodriguez\\Desktop\\Gonza\\Workspace_3_2do_cuatri\\eclipse_tp3_v4\\tp3_windows\\data.csv";
char* PASSENGERS_CSV_TEST_LABURO ="C:\\Users\\gonzalo.rodriguez\\Desktop\\Gonza\\Workspace_3_2do_cuatri\\eclipse_tp3_v4\\tp3_windows\\test.csv";
char* PASSENGERS_BIN_TEST_LABURO ="C:\\Users\\gonzalo.rodriguez\\Desktop\\Gonza\\Workspace_3_2do_cuatri\\eclipse_tp3_v4\\tp3_windows\\test.bin";


char* PASSENGERS_CSV_DIR_CASA = "D:\\Proyectos\\Eclipse\\Labo_1_2daParte\\eclipse_tp3_v4\\tp3_windows\\data.csv";
char* PASSENGERS_CSV_TEST_CASA = "D:\\Proyectos\\Eclipse\\Labo_1_2daParte\\eclipse_tp3_v4\\tp3_windows\\test.csv";
char* PASSENGERS_BIN_TEST_CASA = "D:\\Proyectos\\Eclipse\\Labo_1_2daParte\\eclipse_tp3_v4\\tp3_windows\\test.bin";

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).***OK***
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).***OK***
     3. Alta de pasajero. ***OK***
     4. Modificar datos de pasajero. ***OK***
     5. Baja de pasajero. ***OK***
     6. Listar pasajeros. ***OK***
     7. Ordenar pasajeros ***OK***
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).***OK***
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).***OK***
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
//    A TENER EN CUENTA
//    hay un mal funcionamiento con respecto al ll_clone ya que como no la desarrolle y no esta documentada no se exactamente como funciona
//	al borrarla con la ll_delete tambien se borra la original.


    do{
    	utn_getNumero(&option, "1)Leer CSV\n"
    			"2)Leer BIN\n"
    			"3)Alta de pasajero\n"
    			"5)Baja de pasajero\n"
    			"4)Modificar pasajero\n"
    			"6)Listar pasajeros\n"
    			"7)Ordenar por orden de nombre y apellido\n"
    			"8)Guardar en modo CSV\n"
    			"9)Guardar en modo BIN\n"
    			"0)Salir\n", "ERROR\n", 0, 9, 2);

        switch(option)
        {
            case 1:
                controller_loadFromText(PASSENGERS_CSV_DIR_CASA,listaPasajeros);
                break;
            case 2:
            	controller_loadFromBinary(PASSENGERS_BIN_TEST_CASA, listaPasajeros);
            	break;
            case 3:
            	Passenger_alta(listaPasajeros);
            	break;
            case 4:
            	Passenger_modificar(listaPasajeros);
            	break;
            case 5:
            	Passenger_baja(listaPasajeros);
            	break;
            case 6:
            	Passenger_printByStatus(listaPasajeros, 0);
            	break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
            	break;
            case 8:
            	controller_saveAsText(PASSENGERS_CSV_TEST_CASA, listaPasajeros);
            	break;
            case 9:
            	controller_saveAsBinary(PASSENGERS_BIN_TEST_CASA, listaPasajeros);
            	break;


        }
    }while(option != 0);


    return 0;
}

