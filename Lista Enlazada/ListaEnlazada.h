/*----------------------------------*/
/*  Practica 6. José Luis Bellosta  */
/*----------------------------------*/

#pragma once
#include "Nodo.h"

class ListaEnlazada
{
	Nodo *lista;

	int n;

	// Obtiene un nodo de la lista
	// Parametro: la posicion del nodo
	// Retorno: un puntero al nodo que esta en dicha posicion
	// Precondiciones: 
	// - la posicion debe estar en el intervalo [0, n-1]
	// - La lista no esta vacia (n>0)
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	Nodo * getNodo(int posicion);

public:
	// Constructor. Crea una lista de tamaño 0
	// Complejidad temporal y espacial: O(1)
	ListaEnlazada();

	// Devuelve un elemento de la lista en determinada posici�n
	// Parametro: la posicion del elemento
	// Retorno: una copia del elemento encontrado en esa posici�n
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la lista
	// Parametros:
	// - posicion: la posicion del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tamaño actual de la lista
	// Complejidad temporal y espacial: O(1)
	int getN();

	// Inserta un nuevo elemento en una posicion de la lista
	// Los elementos que habia desde la posicion hasta el final de la lista se desplazaron una posicion a la derecha
	// Parametros:
	// - posicion: la posicion en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones: posicion en [0, n]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void insertar(int posicion, int nuevoValor);

	// Elimina un elemento en una posicion dada.
	// Los elementos que habia desde posicion+1 hasta el final de la lista se desplazaron una posicion a la izquierda
	// Parametros:
	// - posicion: la posicion del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el ultimo
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void eliminar(int posicion);

	// Concatena una lista al final de la lista actual
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Parametro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondicion: listaAConcatenar != NULL
	// Complejidad temporal: O(m), siendo m = listaAConcatenar.getN()
	// Complejidad espacial: O(m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaEnlazada *listaAConcatenar);

	// Busca la posicion de un elemento en la ListaContigua
	// Parametro: el elemento a buscar
	// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int buscar(int elementoABuscar);

	// Destructor. Libera memoria
	// Complejidad temporal: O(n)
	~ListaEnlazada();
};