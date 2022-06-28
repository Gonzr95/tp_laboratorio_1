#include "linkedlist.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*) malloc (sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    	return this;
    }
    return NULL;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
   int ret = -1;//ERROR NULL this
   if(this != NULL)
   {
	   ret = this->size;
   }
   return ret;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		int i=0; //cuantas posiciones me muevo en la lista
		pNode = this->pFirstNode; //para 0 traigo el primero
		while(i != nodeIndex)
		{
			pNode = pNode->pNextNode;
			i++;
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
//Node* test_getNode(LinkedList* this, int nodeIndex)
//{
//	Node* pNode = NULL;
//	if(this != NULL)
//	{
//		if(nodeIndex >= 0 && nodeIndex < ll_len(this))
//		{
//			int i = 0; //cuantas posiciones me muevo en la lista
//			pNode = this->pFirstNode; //para 0 traigo el primero
//			while(i != nodeIndex)
//			{
//				pNode = pNode->pNextNode;
//				i++;
//			}
//		}
//	}
//
//
//
//    return pNode;
//}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node* nodeAux;
    int ret = -1;//ERROR this NULL
    if(this != NULL)
    {
    	if(nodeIndex <= ll_len(this) && nodeIndex >= 0)//verifico que el index sea algo comprendido dentro del ll_length
    	{
    		Node* newNode = (Node*) malloc(sizeof(Node));
    		if(newNode != NULL)
    		{
    			if(nodeIndex == 0)//añadir en i=0
    			{
    				newNode->pNextNode = this->pFirstNode;
					this->pFirstNode = newNode;
    			}
    			else
    			{
    				nodeAux = getNode(this,nodeIndex-1);//me guardo el anterior

    					newNode->pNextNode = nodeAux->pNextNode;
    					nodeAux->pNextNode=newNode;

    			}
    			newNode->pElement = pElement;
    			this->size++;
    			ret =  0;
    		}
    		else
    		{
    			ret = -1;//ERROR de malloc para Node
    		}
    	}
    	else
    	{
    		ret = -1;//ERROR Index = o mayor a la length de la lista
    	}
    }
    return ret;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
//int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
//{
//	Node* nodeAux;
//    int ret = -1;//ERROR this NULL
//    if(this != NULL)
//    {
//    	if(nodeIndex <= ll_len(this) && nodeIndex >= 0)//verifico que el index sea algo comprendido dentro del ll_length
//    	{
//    		Node* newNode = (Node*) malloc(sizeof(Node));
//    		if(newNode != NULL)
//    		{
//    			if(nodeIndex == 0)//añadir en i=0
//    			{
//    				newNode->pNextNode = this->pFirstNode;
//					this->pFirstNode = newNode;
//    			}
//    			else
//    			{
//    				nodeAux = getNode(this,nodeIndex-1);//me guardo el anterior
//					newNode->pNextNode = nodeAux->pNextNode;
//					nodeAux->pNextNode=newNode;
//    			}
//    			newNode->pElement = pElement;
//    			this->size++;
//    			ret =  0;
//    		}
//    		else
//    		{
//    			ret = -1;//ERROR de malloc para Node
//    		}
//    	}
//    	else
//    	{
//    		ret = -1;//ERROR Index = o mayor a la length de la lista
//    	}
//    }
//    return ret;
//}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int ret = -1;//ERROR this NULL
    if(this != NULL)
    {
    	if(addNode(this, ll_len(this), pElement) == 0) ret = 0;
    	else ret = -1;//ERROR de addNode
    }
    return ret;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* ret = NULL;
    if(this != NULL)
    {
    	Node* nodeAux;
    	nodeAux = getNode(this, index);
    	if(nodeAux != NULL) ret = nodeAux->pElement;
    }
    return ret;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int ret = -1;//ERROR linked NULL
    if(this != NULL)
    {
    	Node* nodeAux = getNode(this, index);
    	if(nodeAux != NULL)
    	{
        	nodeAux->pElement = pElement;
        	ret = 0;
    	}
    	else ret = -1;//ERROR nodeAux NULL
    }
    return ret;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int ret = -1;
    //solo voy a poder borrar algo si en la lista hay algo y el index no este fuera del size
    if(this != NULL && ll_len(this) > 0 && index < ll_len(this) && index >= 0)
    {
    	Node* nodeDelete = getNode(this, index);
    	Node* nodeAnterior;
    	if(ll_len(this) == 1)//si la lista tiene un solo elemento
		{
    		this->pFirstNode = NULL;
		}
    	else//si la lista tiene mas de un elemento
    	{
    		if(index == 0) this->pFirstNode = getNode(this, index+1);
    		else
    		{
    			nodeAnterior = getNode(this, index-1);
    			nodeAnterior->pNextNode = nodeDelete->pNextNode;
    		}
    	}
    	free(nodeDelete);
		this->size--;
		ret = 0;
    }
    return ret;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int ret = -1;//ERROR this NULL
    if(this != NULL)
    {
    	ret = 0;
    	/*
    	****** mas rebuscado*******
    	borro desde la ultima posicion para atras
    	for(int indexDelete = ll_len(this)-1; indexDelete == 0; indexDelete--)
    	{
    		ll_remove(this, indexDelete);
    	}
    	*/

//    	****** o menos rebuscado*******
    	for(int i = 0; i<ll_len(this); i++)
		{
			ll_remove(this, i);
		}

    }
    return ret;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int ret = -1;
    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
    		free(this);
    		ret = 0;
    	}
    }

    return ret;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int ret = -1;
    if(this != NULL)
    {
//    	Node* nodeAux;
    	void* elementoBuscado;
    	int i;
    	for(i=0; i<ll_len(this); i++)
    	{
//    		nodeAux = getNode(this, i);
//    		if(nodeAux != NULL && nodeAux->pElement == pElement)
//			{
//    			ret = i;
//    			break;
//			}
    		elementoBuscado = ll_get(this, i);
    		if(elementoBuscado == pElement)
    		{
    			ret = i;
    			break;
    		}
    	}
    }
    return ret;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 0;
    	if(this->size == 0) returnAux = 1;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if(addNode(this, index, pElement) == 0) returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL)
    {
    	returnAux = ll_get(this, index);
    	if(returnAux != NULL) ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux=0;
    	if(ll_indexOf(this, pElement) != -1) returnAux = 1;
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(int i=0; i<ll_len(this2); i++)
    	{
    		if(ll_contains(this, ll_get(this2, i)) != 1)
			{
    			returnAux = 0;
    			break;
			}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL && to<=ll_len(this) && from >= 0 && to>=from)//si los parametros estan OK corro
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
        	for(int i=0; i<to; i++)
        	{
        		ll_add(cloneArray, ll_get(this, i));
        	}
    	}

    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    if(this != NULL && pFunc != NULL && (order==0 || order==1))
    {
    	void* elementoComparacion1;
    	void* elementoComparacion2;
    	int linkedListLength = ll_len(this);
    	int flagSwap;
    	do
    	{
    		flagSwap = 0;
        	for(int i=0; i<linkedListLength-1; i++)
        	{
        		elementoComparacion1 = ll_get(this, i);
        		elementoComparacion2 = ll_get(this, i+1);
        		int resultadoComparacion = pFunc(elementoComparacion1, elementoComparacion2);
        		if(resultadoComparacion != 0)
        		{
        			switch(order)
					{
					case 1://********ASCENDENTE********
						if(resultadoComparacion > 0)//el elemento 1 es ***MAYOR*** que el 2
						{
							ll_set(this, i+1, elementoComparacion1);
							ll_set(this, i, elementoComparacion2);
							flagSwap = 1;
						}
					break;
					case 0://********DESCENDENTE********
						if(resultadoComparacion < 0)//el elemento 1 es ***MENOR*** que el 2
						{
							ll_set(this, i+1, elementoComparacion1);
							ll_set(this, i, elementoComparacion2);
							flagSwap = 1;
						}
					break;
					}
        		}
        	}
    	}while(flagSwap);
    	returnAux = 0;
    }
    return returnAux;
}
































































