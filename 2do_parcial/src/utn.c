/*
 * utn.c
 *
 *  Created on: 27 ene. 2022
 *  Modificado: martes 12/04/2022
 *      Author: gonzalo.rodriguez
 */

#include "utn.h"
//-----------GETS---------

/**
 * \brief Solicita INT al usuario y lo retorna por referencia
 * \param pResultado: direccion de memoria donde se guardará el int
 * \param mensaje: mensaje que vera el usuario por consola
 * \param mensajeError mensaje que vera el usuario si se equivoca
 * \param min int minimo aceptado
 * \param max int maximo aceptado
 * \param reintentos cantidad de veces que se puede reintentar
 * \return     0 OK  /  -1 ERROR
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	int bufferInt; //Ingreso del user

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if( getInt(&bufferInt) == 0 &&
				bufferInt >= min &&
				bufferInt <= max)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita FLOAT al usuario y lo retorna por referencia
 * \param pResultado: direccion de memoria donde se guardará el FLOAT
 * \param mensaje: mensaje que vera el usuario por consola
 * \param mensajeError mensaje que vera el usuario si se equivoca
 * \param min FLOAT minimo aceptado
 * \param max FLOAT maximo aceptado
 * \param reintentos cantidad de veces que se puede reintentar
 * \return     0 OK  /  -1 ERROR
 */
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos)
{
	int retorno = -1;
	float bufferFloat; // ingreso del usuario

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if( getFloat(&bufferFloat) == 0 &&
				bufferFloat <= max &&
				bufferFloat >= min )
			{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
		return retorno;
	}
	return retorno;
}

/**
 * \brief Solicita CHAR al usuario y lo retorna por referencia
 * \param pResultado: direccion de memoria donde se guardará el CHAR
 * \param mensaje: mensaje que vera el usuario por consola
 * \param mensajeError mensaje que vera el usuario si se equivoca
 * \param min char minimo aceptado
 * \param max char maximo aceptado
 * \param reintentos cantidad de veces que se puede reintentar
 * \return     0 OK  /  -1 ERROR
 */
int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char min, char max, int reintentos)
{
	int retorno = -1;
	char bufferChar; //Ingreso del user
	char bufferCadena[2];


	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getLetra(bufferCadena, 2) == 0)
			{
				retorno = 0;

				//asignacion del string
				//strcpy(*pResultado,bufferChar);
				bufferChar = bufferCadena[0];
				*pResultado = bufferChar;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita NOMBRE al usuario y lo retorna por referencia
 * \param pResultado: direccion de memoria donde se guardará el NOMBRE
 * \param longitud: longitud maxima aceptada para el nombre
 * \param mensaje: mensaje que vera el usuario por consola
 * \param mensajeError mensaje que vera el usuario si se equivoca
 * \param reintentos cantidad de veces que se puede reintentar
 * \return     0 OK  /  -1 ERROR
 */
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[longitud];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getNombre(bufferChar, longitud) == 0)
			{
				retorno = 0;

				//asignacion del string
				//strcpy(*pResultado,bufferChar);
				strncpy(pResultado,bufferChar,longitud);
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita DESCRIPCION al usuario y lo retorna por referencia
 * \param pResultado: direccion de memoria donde se guardará la DESCRIPCION
 * \param longitud: longitud maxima aceptada para la descripcion
 * \param mensaje: mensaje que vera el usuario por consola
 * \param mensajeError mensaje que vera el usuario si se equivoca
 * \param min int minimo aceptado
 * \param max int maximo aceptado
 * \param reintentos cantidad de veces que se puede reintentar
 * \return     0 OK  /  -1 ERROR
 */
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[longitud];

	if(pResultado != NULL && longitud > 0 && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getDescripcion(bufferChar,longitud) == 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferChar,longitud);
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}

	return retorno;
}

int utn_getDireccion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[longitud];

	if(pResultado != NULL && longitud > 0 && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getDireccion(bufferChar,longitud) == 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferChar,longitud);
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}

	return retorno;
}

int utn_getCuit(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[longitud];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getCuit(bufferChar, longitud) == 0)
			{
				retorno = 0;
				strncpy(pResultado,bufferChar,longitud);
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}
	return retorno;
}


int utn_getMail(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char mailbox[longitud];
	char mailUser[15];
	char mailDomain[15];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getMailUser(mailUser, 15) == 0)
			{
				strncpy(mailbox,mailUser,15);
//				printf("Su mail hasta aca es: %s\n",mailbox);
				if(setearDominioCorreo(mailDomain, 15) == 0)
				{
					strncat(mailbox,mailDomain,longitud);
					strncpy(pResultado,mailbox,longitud);
					retorno = 0;
				}
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}
	return retorno;
}

int utn_getMailV2(char* pResultado, int usuarioLength, int dominioLength, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char mailbox[usuarioLength+dominioLength];
//	char mailUser[usuarioLength];
//	char mailDomain[dominioLength];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getMailBox(mailbox, usuarioLength, dominioLength) == 0){
				strncpy(pResultado,mailbox,usuarioLength+dominioLength);
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}
	return retorno;
}

int utn_getPassword(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar[longitud];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getPassword(bufferChar, longitud) == 0)
			{
				retorno = 0;

				//asignacion del string
				//strcpy(*pResultado,bufferChar);
				strncpy(pResultado,bufferChar,longitud);
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
		while(reintentos >= 0);
	}
	return retorno;
}

//-----------ARRAYS---------

/**
 * \brief inicializa un arrayINT con 1 valor
 * \pArray puntero del array float
 * \length del arrayINT
 * \param valorInicial el valor de todas las pos
 * \return retorna 0 exito   -1 para error
 */
int initArrayInt(int* pArray, int longitud, float valorInicial)
{
	int retorno = -1;
	if(pArray != NULL && longitud > 0)
	{
		retorno = 0;
		int i;
		for(i=0; i<longitud; i++)
		{
			pArray[i] = valorInicial;
		}
	}
	return retorno;
}

/**
 * \brief inicializa un array con 1 valor
 * \pArray puntero del array float
 * \length del array
 * \param valorInicial el valor de todas las pos
 * \return retorna 0 exito   -1 para error
 */
int initArrayFloat(float* pArray, int longitud, float valorInicial)
{
	int retorno = -1;
	if(pArray != NULL && longitud > 0)
	{
		retorno = 0;
		int i;
		for(i=0; i<longitud; i++)
		{
			pArray[i] = valorInicial;
		}
	}
	return retorno;
}

/**
 * \brief Imprime indice y contenido de arrayINT
 * \param pArray dirreccion de memoria del array
 * \param arrayLenght longitud del array
 * \return     0 OK  /  -1 ERROR
 */
int utn_printArrayINT(int* pArray, int arrayLenght)
{
	int retorno;
	retorno = -1;

	int i;

	if(pArray != NULL && arrayLenght >= 0)
	{
		retorno = 0;
		for(i=0; i<arrayLenght; i++)
		{
			printf("Indice: %d  Valor: %d\n",i,pArray[i]);
		}
	}
	return retorno;
}

/**
 * \brief Imprime indice y contenido de arrayFLOAT
 * \param pArray dirreccion de memoria del array
 * \param arrayLenght longitud del array
 * \return     0 OK  /  -1 ERROR
 */
int utn_printArrayFLOAT(float* pArray, int arrayLenght)
{
	int retorno;
	retorno = -1;

	int i;

	if(pArray != NULL && arrayLenght >= 0)
	{
		retorno = 0;
		for(i=0; i<arrayLenght; i++)
		{
			printf("Indice: %d  Valor: %.2f\n",i,pArray[i]);
		}
	}
	return retorno;
}

/**
 * \brief Ordena un arrayINT
 * \param pArray dirreccion de memoria del arrayINT
 * \param arrayLenght logitud del array
 * \return     X OK (N° DE ITERACIONES HASTA ORDENAR   /  -1 ERROR
 */
int utn_ordenarArrayIntMayoraMenor(int* pArray, int arrayLenght)
{
	int retorno = -1;
	int flagSwap;
	int i;
	int contador=0;
	int buffer;
	int limite;


	if(pArray != NULL && arrayLenght >= 0)
	{
		limite = arrayLenght-1;
		do
		{
			flagSwap=0;
			for(i=0; i<limite; i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			limite--;
		}
		while(flagSwap);
		retorno = contador;
	}
	return retorno;
}

/**
 * \brief Ordena un arrayINT
 * \param pArray dirreccion de memoria del arrayINT
 * \param arrayLenght logitud del array
 * \return     X OK (N° DE ITERACIONES HASTA ORDENAR   /  -1 ERROR
 */
int utn_ordenarArrayIntMenoraMayor(int* pArray, int arrayLenght)
{
	int retorno = -1;
	int flagSwap;
	int i;
	int contador=0;
	int buffer;
	int limite;


	if(pArray != NULL && arrayLenght >= 0)
	{
		limite = arrayLenght-1;
		do
		{
			flagSwap=0;
			for(i=0; i<limite; i++)
			{
				contador++;
				if(pArray[i] > pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			limite--;
		}
		while(flagSwap);
		retorno = contador;
	}
	return retorno;
}





//-------FUNCIONES PARA OBTENER COSAS---------

/**
 * \brief obtiene un string y corrobora que no se desborde buffer
 * \param string puntero donde se guardara el strign
 * \param longitud longitud que no quereos desbordar observar en los getFloat, int, nombre etc
 * \return 0 SUCCESS -1 ERROR
 */
int getString(char* string, int longitud)
{
	int retorno = -1;
	//aprender memoria dinamica
	char bufferString[4096];
	if(string != NULL && longitud > 0)
	{
		fflush(stdin);

		/**
		 * fgets lee todo hasta encontrar un \0 ENTER
		 * si el usuario ingresa AB
		 * fgets leera AB\n\0 y copiara AB\n
		 * por eso necesito poner un \0 en el \n
		 */
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			/**
			si el buffer es de 4 y el usuario ingresa HOLA
			en consola quedaria HOLA\n\0
			como el fgets lee hasta \0
			en la posicion anterior [3] ponemos un \0
			**/
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(bufferString[0] == '\0')
			{
				return -1;
			}
//			printf("%s\n",bufferString);
			/**
			si la longitud de la cadena a revisar es <= a la longitud deseada copiamos
			el contenido
			**/
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud-1)
			{
				/**
				 * copio uno mas de longitud para poder ponerle \0
				 */
				strncpy(string,bufferString,longitud);
				retorno = 0;
//				printf("%s\n",string);
			}

			else
			{
				printf("Hay caracteres de mas (GETSTRING)\n");
			}

		}
	}
	return retorno;
}

/**
 * \biref: obtiene un NOMBRE y verifica que no desborde buffer (20)
 * \param: pResultado es donde se alamacenara ese int
 * \return :   0 (exito) si almacenara un int   /    -1 para error
 */
int getLetra(char* pResultado, int longitud)
{
	int retorno = -1;
	//20 sera la maxima cantidad de caracteres que recibira nombre
	char buffer[longitud];
	if( pResultado != NULL &&
		getString(buffer, sizeof(buffer)) == 0 &&
		esSoloLetras(buffer))
		{
			//asignacion del string
			//strcpy(*pResultado,buffer);
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	return retorno;
}

/**
 * \biref: obtiene numero entero y verifica que no desborde buffer
 * \param: pResultado es donde se alamacenara ese int
 * \return :   0 (exito) si almacenara un int   /    -1 para error
 */
int getInt(int* pResultado)
{
	int retorno = -1;
	//10 numeros es la cantidad maxima que soporta int
	char buffer[10];
	if( pResultado != NULL &&
		getString(buffer, sizeof(buffer)) == 0 &&
		esInt(buffer, sizeof(buffer)))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	return retorno;
}

/**
 * \biref: obtiene numero FLOAT y verifica que no desborde buffer
 * \param: pResultado es donde se alamacenara ese float
 * \return :   0 (exito) si almacenara un float   /    -1 para error
 */
int getFloat(float* pResultado)
{
	int retorno = -1;
	//10 es la cantidad maxima que soporta float
	char buffer[10];

	if( pResultado != NULL &&
		getString(buffer, sizeof(buffer)) == 0 &&
		esFloat(buffer, sizeof(buffer)) == 1 )
	{
			*pResultado = atof(buffer);
			retorno = 0;
	}
	return retorno;
}

/**
 * \biref: obtiene un NOMBRE y verifica que no desborde buffer (20)
 * \param: pResultado es donde se alamacenara ese int
 * \return :   0 (exito) si almacenara un int   /    -1 para error
 */
int getNombre(char* pResultado, int longitud)
{
	int retorno = -1;
	//20 sera la maxima cantidad de caracteres que recibira nombre
	char buffer[longitud];
	if( pResultado != NULL &&
		getString(buffer, sizeof(buffer)) == 0 &&
		esNombre(buffer, sizeof(buffer)))
		{
			//asignacion del string
			//strcpy(*pResultado,buffer);
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	return retorno;
}

/**
 * \biref: obtiene una DESCRIPCION y verifica que no desborde buffer (200)
 * \param: pResultado es donde se alamacenara ese int
 * \return :   0 (exito) si almacenara un int   /    -1 para error
 */
int getDescripcion(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[longitud];
	if (pResultado != NULL &&
		getString(buffer, sizeof(buffer)) == 0)
	{
		strncpy(pResultado,buffer,longitud);
		retorno = 0;
	}
	return retorno;
}

int getDireccion(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[longitud];
	if (pResultado != NULL &&
		getString(buffer, sizeof(buffer)) == 0
		&& esDireccion(buffer, longitud) == 1)
	{
		strncpy(pResultado,buffer,longitud);
		retorno = 0;
	}
	return retorno;
}


int getCuit(char* pResultado, int longitud)
{
	int retorno = -1;
	//14 es la maxima cantidad de caracteres que debe tener un cuit
//	20-38705231-4\0
//	123456789012314 cantidad

	char buffer[longitud];//este es el dato a modificar si queremos que en las demas funcioens get tire error de longitud el get string
	if( pResultado != NULL &&
		getString(buffer, longitud) == 0 &&
		esCuit(buffer))
		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	return retorno;
}


int getMailUser(char* pResultado, int longitud)
{
	int retorno = -1;
	//14 es la maxima cantidad de caracteres que debe tener un cuit
	//	20-38705231-4\0
	//	123456789012314 cantidad

	char buffer[longitud];//este es el dato a modificar si queremos que en las demas funcioens get tire error de longitud el get string
	if( pResultado != NULL &&
	getString(buffer, longitud) == 0 &&
	esMailUser(buffer, longitud) == 1)
	{
		strncpy(pResultado,buffer,longitud);
		retorno = 0;
	}
	return retorno;
}

int getMailBox(char* pResultado, int userLongitud, int dominioLongitud)
{
	int retorno = -1;//ERROR NULL POINTER
	char buffer[userLongitud+dominioLongitud];
	if( pResultado != NULL){
		if( getString(buffer, userLongitud+dominioLongitud) == 0){
			if(esMailUserV2(buffer, userLongitud, dominioLongitud) == 1){
				strncpy(pResultado,buffer,userLongitud+dominioLongitud);
				retorno = 0;
			}else{
				retorno = -3;//ERROR en es mail
			}
		}else{
			retorno = -2;//ERROR en get string
		}
	}
	return retorno;
}

int getPassword(char* pResultado, int longitud)
{
	int retorno = -1;
	//20 sera la maxima cantidad de caracteres que recibira nombre
	char buffer[longitud];
	if( pResultado != NULL &&
		getString(buffer, sizeof(buffer)) == 0 &&
		esAlfaNumerico(buffer, sizeof(buffer)))
		{
			//asignacion del string
			//strcpy(*pResultado,buffer);
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	return retorno;
}


//-----------FUNCIONES DE VALIDACION---------

/**
 * \brief Recibe una cadena tipo char y determina si contiene solo numeros.
 * \param string cadena tipo char
 * \return 0 contiene mas que n°s   /    1 Solo n°s
 */
int esInt(char* string, int limite)
{
	int retorno;
	int i = 0;
	//printf("el array tiene datos\n");
	for(i=0; i<limite && string[i] !='\0'; i++)
	{
		if(i == 0 && (string[i] == '-' || string[i] == '+'))
		{
			continue;
		}
		if(string[i] < '0' || string[i] > '9')
		{
			//printf("El string tenia algo que no era n°.\n");
			retorno = 0;
			break;
		}
		else
		{
			//printf("El string tenia algo que no era n°.\n");
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * \brief verifica si la cadena char es float
 * \param string: cadena a verificar
 * \return = 1 para exito     0 para error
 */
int esFloat(char* string, int limite)
{
	int retorno = 1;
	int i = 0;
	int contadorPuntos = 0;

	if(string != NULL && strlen(string) > 0)
	{
		for(i=0; i<limite && string[i] != '\0'; i++)
		{
			if(string[0] == '\n')
			{
				retorno = 0;
				break;
			}
			if(i == 0 && (string[i] == '-' || string[i] == '+'))
			{
				continue;
			}
			if(string[i] < '0' || string[i] > '9')
			{
				if(string[i] == '.' && contadorPuntos < 1)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int setearDominioCorreo(char* pResultado, int longitudDominio)
{
	int retorno = -1;  //NULL char
	int opcion;

	if(pResultado != NULL)
	{
		if(utn_getNumero(&opcion, "Cual es el dominio? Oprima 1, 2 o 3\n"
				"1)hotmail.com\n"
				"2)outlook.com\n"
				"3)gmail.com\n"
				, "ERROR\n", 1, 3, 2) == 0)
		{
			switch(opcion)
			{
				//char dominio[15];
				case 1:
					strncpy(pResultado,"@hotmail.com",longitudDominio);
					break;
				case 2:
					strncpy(pResultado,"@outlook.com",longitudDominio);
					break;
				case 3:
					strncpy(pResultado,"@gmail.com",longitudDominio);
					break;
			}
			retorno = 0;//SUCCES
		}
		else
		{
			retorno = -2; //error de utn getnum
		}
	}
	return retorno;
}

/**
 * \brief verifica si la cadena char es un NOMBRE
 * \param string: cadena a verificar
 * \param: limite: la longitud maxima aceptada para el nombre
 * \return = 1 para exito     0 para error
 */
int esNombre(char* string, int limite)
{
	int retorno;
	int i = 0;
	for(i=0; i<limite && string[i] !='\0'; i++)
	{
		if( (string[i] < 'a' || string[i] > 'z') &&
			(string[i] < 'A' || string[i] > 'Z'))
		{
			//printf("El string tiene algo que no es a-z / A-Z\n");
			retorno = 0;
			break;
		}
		else
		{
			//printf("El string conenia solo letras min o mayus.\n");
			retorno = 1;
		}
	}
	return retorno;
}











//--------f(x) a revisar y actualizar---------

/**
 * \brief Recibe una cadena tipo char y determina si contiene solo letras y espacios.
 * \param string cadena tipo char
 * \return 0 contiene mas que chars y espacios   /    1 Solo chars y espacios
 */
int esSoloLetras(char* stringa)
{
	int retorno = 1;
	int i = 0;
	while(stringa[i] != '\0')
	{
		if((stringa[i] != ' ') && (stringa[i] < 'a' || stringa[i] > 'z') && (stringa[i] < 'A' || stringa[i] > 'Z'))
		{
			retorno = 0;
			break;
		}
		i++;
	}
	return retorno;
}

/**
 * \brief Recibe una cadena tipo char y determina si contiene solo caracteres alfanumericos ( A-Z 0-9 " " a-z)
 * \param string cadena tipo char
 * \return 0 contiene mas que alfanumericos   /    1 Solo alfanumericos
 */
int esAlfaNumerico(char* string, int longitud)
{
	int retorno = 1;
	int i = 0;
	while(string[i] != '\0')
	{
		if((string[i] != ' ') &&
			(string[i] < 'a' || string[i] > 'z') &&
			(string[i] < 'A' || string[i] > 'Z') &&
			(string[i] < '0' || string[i] > '9'))
		{
			retorno = 0;
			break;
		}
		i++;
	}
	return retorno;
}

int esDireccion(char* string, int longitud)
{
	int retorno = 1;
	int i = 0;
	int hayNumeros = 0;
	while(string[i] != '\0')
	{
		if((string[i] != ' ') &&
			(string[i] < 'a' || string[i] > 'z') &&
			(string[i] < 'A' || string[i] > 'Z') &&
			(string[i] < '0' || string[i] > '9'))
		{
			retorno = 0;
			break;
		}
		if(hayNumeros == 0 && (string[i] <='9' && string[i] >= '0') ) hayNumeros = 1;
		i++;
	}
	if(hayNumeros == 0) retorno = 0;

	return retorno;
}

/**
 * \brief revisa si la cadena esta compuesta por: SOLO NUMEROS o NUMEROS Y 1 GUION
 * \param stringa cadena tipo char a revisar
 * \return 0 si tiene algo mas aparte de eso   /   1 si es valido
 */
int esTelefono(char* stringa)
{
	int retorno = 1;
	int i = 0;
	int contadorGuinoes = 0;

	while(stringa[i] != '\0')
	{
		if((stringa[i] != ' ') && (stringa[i] < '0' || stringa[i] > '9') && (stringa[i] != '-'))
		{
			retorno = 0;
			break;
		}
		if(stringa[i] == '-')
		{
			contadorGuinoes++;
		}
		if(contadorGuinoes>1)
		{
			retorno = 0;
			break;
		}
		i++;
	}
	return retorno;
}

int esCuit(char* string)
{
	int retorno = 1;
	int i = 0;
	//--------ANALISIS 1RAS 2 POSICIONES
	for(i=0; i<2; i++)
	{
		if(string[i] < '0' || string[i] > '9')
		{
			printf("En las primeras 2 posiciones tenia algo que no era num\n");
			return 0;
		}
	}
	//--------ANALISIS 1ER GUION
	if(string[2] != '-')
	{
		printf("En la 3ra posicion tenia algo que no era el guion\n");
		return 0;
	}
	//--------ANALISIS DNI
	for(i=3; i<11; i++)
	{
		if(string[i] < '0' || string[i] > '9')
		{
			printf("De la posicion 3 en adelante tenia algo que no era num\n");
			return 0;
		}
	}
	//--------ANALISIS 1ER GUION
	if(string[11] != '-')
	{
		printf("En la 11na posicion tenia algo que no era el guion\n");
		return 0;
	}
	//--------ANALISIS ULTIMO NUMERO
	if(string[12] < '0' || string[12] > '9')
	{
		printf("En la ultima posicion tenia algo que no era num\n");
		return 0;
	}
	else
	{

		retorno = 1;
	}
	return retorno;
}


int esMailUser(char* string, int longitud)
{
	int retorno = 1;
	int i = 0;
	for(i=0; string[i] != '\0'; i++)
	{
		if( (string[i] < '0' || string[i] > '9') &&
			(string[i] < 'A' || string[i] > 'Z') &&
			(string[i] < 'a' || string[i] > 'z') &&
			(string[i] != '.' && string[i] != '_' && string[i] != '-') )
		{
			retorno = 0;
//			printf("Habia algo que no era numero o mayus o minus . - _\n");
			break;

		}
		else
		{
//			printf("Aca esta todo bien\n");
			continue;
		}
	}
	return retorno;
}

int esMailUserV2(char* string, int userLongitud, int dominioLongitud){
	int retorno = 1;
	int contadorArrobas = 0;
	for(int i=0; string[i] != '\0' && i<userLongitud+dominioLongitud; i++)
	{
		if( (string[i] < '0' || string[i] > '9') &&
			(string[i] < 'A' || string[i] > 'Z') &&
			(string[i] < 'a' || string[i] > 'z') &&
			(string[i] != '.' && string[i] != '_' && string[i] != '-') )
		{
			//5 es el minimo de length qe tiene que tener un user, pasarselo por parametro
			//asi no tenes que volver a entrar aca
			if(i>5 && string[i] == '@'){
				contadorArrobas++;
//				printf("Encontre un arroba\n");
				if(contadorArrobas>1){
					retorno = -1; //ERROR hay mas de un arroba
//					printf("Solo puede haber 1 solo arroba\n");
				}
			}
			else{
				retorno = 0;//ERROR LENGTH DE USER MUY CORTA
				contadorArrobas++;
//				printf("El nombre de usuario es demasiado corto, debe ser de 7 chars minimo\n");
				break;
			}
			break;
		}
		else{
			continue;
		}
	}
	if(contadorArrobas == 0 || contadorArrobas > 1){
		printf("no puede no tener arroba o tener 2\n");
	}
	return retorno;
}

/// @fn int calcularDescuento(float, float*, float)
/// @brief calcula el descuento
///
/// @param precio el precio base
/// @param precioCalculado puntero a direccion de memoria donde se guardara el resultado
/// @param descuento porcentaje de decuento
/// @return -1 ERROR  //  0 EXITO
int calcularDescuento(float precio, float* precioCalculado, float descuento)
{
	int retorno = -1;

	if(precioCalculado != NULL)
	{
		*precioCalculado = precio - (precio / 100 *descuento);
		retorno = 0;
	}
	return retorno;
}

/// @fn int calcularRecarga(float, float*, float)
/// @brief calcula la recarga de precio
///
/// @param precio el precio base
/// @param precioCalculado puntero a direccion de memoria donde se guardara el resultado
/// @param recarga porcentaje de recarga
/// @return -1 ERROR  //  0 EXITO
int calcularRecarga(float precio, float* precioCalculado, float recarga)
{
	int retorno = -1;

	if(precioCalculado != NULL)
	{
		*precioCalculado = precio + (precio / 100 *recarga);
		retorno = 0;
	}
	return retorno;
}


/// @fn int calcularDiferenciaV2(float, float, char*, char*, float*)
/// @brief calcula la diferencia entre 2 num e informa
///
/// @param num1 numero a restar
/// @param num2
/// @param mensaje Mensaje que vera el usuario si hay diferencia
/// @param mensajeError mensaje que vera el usuario sino la hay
/// @param pDiferencia puntero a direccion de memoria donde se almacenara la diferencia
/// @return
int calcularDiferenciaV2(float num1, float num2, char* mensaje, char*mensajeError, float* pDiferencia)
{
	int retorno = -1;// ERROR POR PUNTERO O NO HAY DIFERENCIA
	float diferencia;
	if(mensaje != NULL && mensajeError != NULL)
	{
		if(num1 != num2)
		{
			retorno = 0; // Salio todo bien
			diferencia = num1 - num2;

			if(diferencia < 0)
			{
				diferencia = diferencia * -1;
			}
			*pDiferencia = diferencia;
			printf("%s%.2f\n\n",mensaje,diferencia);
		}
		else
		{
			printf("%s\n\n",mensajeError);
		}
	}
	return retorno;
}

/// @fn int utn_calcularPromedio(float*, float, int)
/// @brief calcula el promedio de un set de numeros
///
/// @param promedio puntero a direccion de memoria donde se guardara el promedio
/// @param dividendo numero a dividir
/// @param divisor divisor xd
/// @return -1 puntero NULL // -2 divisor = 0 // 0 SUCCESS
int utn_calcularPromedio(float* promedio, float dividendo, int divisor)
{
	int ret = -1; //contador o divisor es 0

	if(divisor != 0)
	{
		if(divisor != 0)
		{
			ret = 0;
			*promedio = dividendo /divisor;
		}
		else
		{
			ret = -2;
		}
	}
	return ret;
}

/// @fn int validateExit_YN(char*, char*, int)
/// @brief pasa un mensaje para confirmar lo que estamos por hacer
///
/// @param menssage
/// @param errorMessage
/// @param retries cantidad de reintentos
/// @return 0 si el usuario no confirma, ****** 1 si el usuario confirma
int validateExit_YN(char* message, char* errorMessage, int retries)
{
	int ret = -1;
	char answer;
	do
	{
		utn_getCharacter(&answer, message, errorMessage, 65, 122, retries);
		answer = toupper(answer);
	}
	while(answer != 'Y' && answer != 'N');

	if(answer == 'Y')
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}
	return ret;
}


long int sumarSegundos(long int segundosASumar, long int horaActual)
{
	long int resultado;
	resultado = horaActual + segundosASumar;
	return resultado;
}

void dinamitarNuevaLinea(char* hora, int length)
{
	int i;
	for(i=0; i<length; i++)
	{
		if(hora[i]=='\n')
		{
			hora[i]='\0';
		}
	}
}

void escribirHoraStringActual(char* string, int stringLength)
{
	long int horaActual;
	horaActual = time(NULL);
	strncpy(string,ctime(&horaActual),stringLength);
	dinamitarNuevaLinea(string, stringLength);
}

void entreAca(void){
	printf("Entre aca\n");
}

void DEBUG(void){
	printf("[DEBUG]\n");
}

void ERROR(void){
	printf("[ERROR]\n");
}

void elEnteroEs(int entero){
	printf("-int: %d \n",entero);
}

void elFloatEs(double decimal){
	printf("-float: %f\n",decimal);
}

void laCadenaEs(char* cadena){
	printf("La cadena es: %s\n",cadena);
}

void laCadenaTiene(char* cadena, int length){
	printf("-La cadena tiene\n");
	for(int i=0; i<length; i++){
		printf("Index: [%d] ---> char: %c ---> int: %d\n",i,cadena[i],cadena[i]);
	}
}

int resizeArray(int** array, int* size, int newSize){
	//recibo el size como puntero porque lo voy a necesitar modificar
	int* arrayAux = NULL;
	int ret = -1
			;
	if( array != NULL && size != NULL && newSize >= 0 ){

		arrayAux =  (int*)realloc (*array, sizeof(int) * newSize);

		if( arrayAux != NULL ){

			*size = newSize;
			*array = arrayAux;
			ret = 0;
		}
	}
	return ret;
}





