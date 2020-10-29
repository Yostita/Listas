/*----------------------------------*/
/*  Practica 6. José Luis Bellosta  */
/*----------------------------------*/

#include <iostream>
#include <stdlib.h>
#include"ListaEnlazada.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

Nodo * ListaEnlazada::getNodo(int posicion) {
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	Nodo *resultado = NULL; 
	resultado = lista;

	for (int i = 0; i < posicion; i++) {
		resultado = resultado->siguienteNodo;
	}

	return (resultado);
}

ListaEnlazada::ListaEnlazada() {
	lista = NULL;
	n = 0;
}

int ListaEnlazada::getValor(int posicion) {
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	Nodo *nodoResultado = getNodo(posicion);
	return (nodoResultado->elemento);
}

void ListaEnlazada::setValor(int posicion, int nuevoValor) {
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getN() {
	return (n);
}

void ListaEnlazada::insertar(int posicion, int nuevoValor) {
	assertdomjudge(posicion >= 0 && posicion <= n);

	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->elemento = nuevoValor;

	if (n == 0) {
		lista = nuevoNodo;
	}else {		
		if (posicion == 0) {
			nuevoNodo->siguienteNodo = getNodo(posicion);
			lista = nuevoNodo;
		}else {
			if (posicion == n) {
				getNodo(posicion - 1)->siguienteNodo = nuevoNodo;
			}else {
				nuevoNodo->siguienteNodo = getNodo(posicion);
				getNodo(posicion - 1)->siguienteNodo = nuevoNodo;
			}
		}
	} 

	n++;
}

void ListaEnlazada::eliminar(int posicion) {
	assertdomjudge(n > 0);
	assertdomjudge(posicion >= 0 && posicion <= n - 1);
	
	Nodo *nodoAEliminar = getNodo(posicion);

	if (n == 1) {
		lista = NULL;
	
	}else {
		if (posicion == 0) {
			lista = nodoAEliminar->siguienteNodo;
		}else {
			if (posicion == n) {
				getNodo(posicion - 1)->siguienteNodo = NULL;
			}else {
				getNodo(posicion - 1)->siguienteNodo = nodoAEliminar->siguienteNodo;
			}
		}		
	} 

	delete(nodoAEliminar);

	n--;
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar) {
	assertdomjudge(listaAConcatenar != NULL);

	int m = listaAConcatenar->getN();

	for (int i = 0; i < m; i++) {
		int elementoACopiar = listaAConcatenar->getValor(i);
		insertar(n, elementoACopiar);
	}
}

int ListaEnlazada::buscar(int elementoABuscar) {
	int posicion = 0; 
	bool encontrado = false; 

	while (!encontrado && posicion < n) {
		if (getValor(posicion) == elementoABuscar) {
			encontrado = true;
		}
		
		posicion++;
	}

	if (encontrado) return (posicion - 1);
	else return (-1);
}

ListaEnlazada::~ListaEnlazada() {
	while (n>0) eliminar(0);
}