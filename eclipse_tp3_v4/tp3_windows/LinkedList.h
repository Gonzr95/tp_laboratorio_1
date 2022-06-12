/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
//Crea una nueva lista enlazada
LinkedList* ll_newLinkedList(void);

//devuelve la lenght de la ll
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//add un elemento a la lista. le pasamos un puntero y la lista de pasajeros creada con ll
//siempre le va a hacer add al final de la lista
int ll_add(LinkedList* this, void* pElement);


//me trae el puntero de algo (lo tengo que castear ya que es un *void)
void* ll_get(LinkedList* this, int index);

int ll_indexOf(LinkedList* this, void* pElement);

//setea un puntero en un index determinado de la lista, si tengo una lista de 10 elementos
//y quiero add en el index 16 no me deja. se tiene que pisar con otro elemento. si quiero add
//en el ultimo elemento puede hacer un ll_len - 1 y ahi piso
int ll_set(LinkedList* this, int index,void* pElement);

//remueve un determinado nodo. tmb hace que el anterior apunte al siguiente y el siguiente al
//anterior del removido. No remueve el elemento en si (BAJA LOGICA) baja el lenght de la ll
int ll_remove(LinkedList* this,int index);

//vacia la lista pero sigue estando es decir puedo seguir haciendo adds
int ll_clear(LinkedList* this);

//
int ll_deleteLinkedList(LinkedList* this);


//busqueda por id
/*
 * for hasta len de ll
 * {
 * 		pAux = (pass*) ll_get
 * 		if(id == pAux->id
 * 		{
 * 			index = ll_indexOf(lista, pAux)
 * 		}
 * }
 *
 */

//si la lista es vacia?
int ll_isEmpty(LinkedList* this);

//introduce un nodo con su emelemtno entre otro
//si mi lista tiene 4 elementos  y lo quiero meter en el 5 se puede, no el 6 por ej
//un uso copado seria para eliminar determinada referencia y al final decir OK se elimino tal cosa
int ll_push(LinkedList* this, int index, void* pElement);

//no devuelve el elemento y revienta el nodo
//si reviento el index 3 me quedo con el puntero que este index contenia y enlazo el index 2 con el 4
void* ll_pop(LinkedList* this,int index);

//retorna 1 si la lista contiene dicho elemento
int ll_contains(LinkedList* this, void* pElement);

//retorna 1 si la lista contiene tal lista
int ll_containsAll(LinkedList* this,LinkedList* this2);

//retorna una nueva sublista de ll desde un index hasta otro
LinkedList* ll_subList(LinkedList* this,int from,int to);

//copia una ll y retorna su copia
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);


















