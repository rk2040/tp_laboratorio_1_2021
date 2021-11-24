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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jugador.h"
#include "parser.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
    int indiceId;
    int indice;
    int from;
    int to;
    int id;
    int tamLinkedList;

    LinkedList* listaDeJugadores;
    LinkedList* listaDeJugadoresCopia;
    LinkedList* subListaDeJugadores;

    eJugador jugador;
    eJugador* auxJugador1;
    eJugador* auxJugador2;


    printf("========== Linked List ==========\n\n");

// 1- creo un nueva lista
    listaDeJugadores = ll_newLinkedList();

// 12- ll_isEmpty   veo si la lista esta vacia (antes de cargarla, para probar)
    printf("--- isEmpty ---\n");
    if(ll_isEmpty(listaDeJugadores))
    {
        printf("listaDeJugadores esta vacia. ll_isEmpty  devuelve 1 \n\n");
    }

// cargo la lista nueva
    printf("--- Cargo una Lista de jugadores de prueba ---\n");
    loadFromText("jugadores1.csv", listaDeJugadores);

    printf("\n\n");

// 2- ll_len  cantidad de elementos en la lista
    printf("La cantidad de jugadores en la lista es (ll_len): %d \n\n", ll_len(listaDeJugadores));


    mostrarJugadores(listaDeJugadores); // muestro lista antes de agregar
// 5- ll_add  agrego a la lista
    eJugador* nuevo1 = jugador_newParametrosChar("11", "campazzo", "base", "30", "1.78");
    eJugador* nuevo2 = jugador_newParametrosChar("12", "harden", "escolta", "32", "1.96");
    eJugador* nuevo3 = jugador_newParametrosChar("13", "aguero", "delantero", "33", "1.73");
    eJugador* nuevo4 = jugador_newParametrosChar("14", "messi", "delantero", "34", "1.70");

    ll_add(listaDeJugadores, nuevo1);
    ll_add(listaDeJugadores, nuevo2);
    ll_add(listaDeJugadores, nuevo3);
    ll_add(listaDeJugadores, nuevo4);

    printf("\n--- Lista Con los agregados ---\n");
    mostrarJugadores(listaDeJugadores); // muestro lista despues de agregar

// 8-  ll_remove  elimino un elemento de la lista
    ll_remove(listaDeJugadores, 6);    // saco a george

    printf("\nEl jugador george fue eliminado de la lista\n");
    printf("\n--- Lista Con george eliminado ---\n");
    mostrarJugadores(listaDeJugadores);

// 11-  ll_indexOf   indice de un elemento de la lista. Al primer elemento que encuentra en la lista de ese tipo (en este caso tipo   eJugador )
    indice = ll_indexOf(listaDeJugadores, nuevo1);

    if(indice >= 0)
    {
        printf("\nEl indice del elemento que retorno ll_indexOf es: %d \n", indice);

    // 6-  ll_get  puntero al elemento que le pasamos por indice
        mostrarJugador(ll_get(listaDeJugadores, indice));
    }

// 13- ll_push  desplaza los elementos de la liste y mete un elemente en medio de la lista en la posicion que le indicamos
    eJugador* nuevo5 = jugador_newParametrosChar("15","alvarez","delantero","21","1.72");
    ll_push(listaDeJugadores,12, nuevo5);
    printf("\n--- Lista Con la insersion de Juli Alvarez ---\n");
    mostrarJugadores(listaDeJugadores);

// 14- ll_pop  devuelve puntero al elemento de la lista del indice que le pasamos y lo elimina. (podemos copiarlo a una nueva variable del mismo tipo antes de que lo elimine)
    eJugador* nuevoCopiaPop = ll_pop(listaDeJugadores,7);
    printf("\nEl elemento eliminado es: %d \n", nuevoCopiaPop->id);
    printf("El elemento era: ");
    printf("\n");
    mostrarJugador(nuevoCopiaPop);
    printf("\n--- Lista Eliminando y copiando a %s ---\n", nuevoCopiaPop->nombre);
    mostrarJugadores(listaDeJugadores);

// 18- ll_clone  copio la lista en otra LinkedList
    listaDeJugadoresCopia = ll_clone(listaDeJugadores);
    printf("\n--- Lista Copiada/clonada ---\n");
    mostrarJugadores(listaDeJugadoresCopia);

// 15- ll_contains  verifica si un elemento esta en la lista (usar el retorno)
    if(ll_contains(listaDeJugadores, nuevo4))
    {
        printf("\n%s esta en la lista\n", nuevo4->nombre);
    }
    else
    {
        printf("\n%s no esta en la lista\n", nuevo4->nombre);
    }

// 16- ll_containsAll   verifica si una lista contiene todos los mismos elementos de otra lista
    if(ll_containsAll(listaDeJugadores, listaDeJugadoresCopia))
    {
        printf("\nLas listas contienen los mismos elementos\n");
    }
    else
    {
        printf("\nLas listas no contienen los mismos elementos\n");
    }

// 17- ll_sublist
    subListaDeJugadores = ll_subList(listaDeJugadores, 0,10);
    printf("\nSon jugadores de basket (ll_sublist)\n");
    mostrarJugadores(subListaDeJugadores);

// 19- ll_sort  ordena los elementos de la lista reciviendo los paramentros de la funcion de ordenamiento que queremos usar
    ll_sort(listaDeJugadores, jugador_ordenarPorAltura,1);
    printf("\n--- Lista ordenada por altura de menor a mayor (ll_sort) ---\n");
    mostrarJugadores(listaDeJugadores);

// 9-  ll_clear   borro todos los elementos de la lista
    if( !ll_isEmpty(listaDeJugadores))  // si la lista no esta vacia, la vacio
    {
        ll_clear(listaDeJugadores);
        printf("\nSe borraron todos los elementos de la lista\n");
    }

// 10- deleteLinkedList   elimino la lista LinkedList
    ll_deleteLinkedList(listaDeJugadores);
    printf("\nLista eliminada completamente\n");
/*
        startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort */

    return 0;
}

































