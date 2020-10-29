/*----------------------------------*/
/*  Practica 6. José Luis Bellosta  */
/*----------------------------------*/

#pragma once
#include<iostream>
#include<stdlib.h>

class ListaContigua
{
	int *vector;
	int n;
	int capacidad;
	int incremento;

public:
	// Constructor. Crea una ListaContigua de tamaño 0
	// Complejidad temporal y espacial: O(1)
	ListaContigua(int incremento);

	// Devuelve un elemento de la ListaContigua
	// Parametro: la posicion del elemento
	// Retorno: el elemento encontrado en esa posicion
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Parametros:
	// - posicion: la posici�n del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tama�o actual de la ListaContigua
	// Retorno: numero actual de elementos de la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getN();

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: numero maximo que actualmente podria contener la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getCapacidad();

	// Inserta un nuevo elemento en una posicion de la lista, dejando primero un hueco para meterlo ahi
	// Los elementos que habia desde la posicion hasta el final de la ListaContigua se desplazaron una posicion a la derecha
	// Parametros:
	// - posicion: la posicion en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones: posicion en [0, n]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void insertar(int posicion, int nuevoValor);

	// Elimina un elemento en una posicion dada.
	// Los elementos que habia desde posicion+1 hasta el final de la ListaContigua se desplazaron una posicion a la izquierda
	// Parametros:
	// - posicion: la posicion del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el ultimo
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n), por memmove()
	void eliminar(int posicion);

	// Concatena una lista al final de la lista actual
	// Par�metro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondicion: listaAConcatenar!=NULL
	// Complejidad temporal: O(n+m), siendo m = listaAConcatenar.getN()
	// Complejidad espacial: O(n+m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaContigua *listaAConcatenar);

	// Busca la posicion de un elemento en la ListaContigua
	// Par�metro: el elemento a buscar
	// Retorno: posicion del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int buscar(int elementoABuscar);

	// Destructor. Libera memoria
	// Complejidad temporal y espacial: O(1)
	~ListaContigua();
};