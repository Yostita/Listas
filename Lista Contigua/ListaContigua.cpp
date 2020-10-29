/*----------------------------------*/
/*  Practica 6. José Luis Bellosta  */
/*----------------------------------*/

#include <iostream>
#include <stdlib.h>
#include "cstdlib" 
#include "cstring"
#include"ListaContigua.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

ListaContigua::ListaContigua(int incremento) {
	vector = NULL; 
	n = 0;
	capacidad = 0;
	this->incremento = incremento;
}

int ListaContigua::getValor(int posicion) {
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	return (vector[posicion]);
}

void ListaContigua::setValor(int posicion, int nuevoValor) {
	assertdomjudge(posicion >= 0 && posicion <= n - 1);
	vector[posicion] = nuevoValor;
}

int ListaContigua::getN() {
	return (n);
}

int ListaContigua::getCapacidad() {
	return (capacidad);
}

void ListaContigua::insertar(int posicion, int nuevoValor) {
	assertdomjudge(posicion >= 0 && posicion <= n);

	if (n == capacidad) {
		vector = (int*)realloc(vector, sizeof(int)*(capacidad + incremento));
		capacidad += incremento;
	}

	memmove(&vector[posicion + 1], &vector[posicion], sizeof(int)*(n - posicion));

	n++;
	setValor(posicion, nuevoValor);
}

void ListaContigua::eliminar(int posicion) {
	assertdomjudge(posicion >= 0 && posicion <= n - 1);

	memmove(&vector[posicion], &vector[posicion + 1], sizeof(int)*(n - posicion - 1));
	n--;

	if (capacidad - n == 2 * incremento) {
		vector = (int*)realloc(vector, sizeof(int)*(capacidad - incremento));
		capacidad -= incremento;
	}
}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar) {
	assertdomjudge(listaAConcatenar != NULL);

	int m = listaAConcatenar->getN();

	vector = (int*)realloc(vector, sizeof(int)*(capacidad + m));
	capacidad += m;

	for (int i = 0; i < m; i++) {
		insertar(n, listaAConcatenar->getValor(i));
	}
}

int ListaContigua::buscar(int elementoABuscar) {
	int posicion = 0;
	bool encontrado = false; 

	while (!encontrado && posicion < n) {
		if (vector[posicion] == elementoABuscar) encontrado = true;
		posicion++;
	}

	if (encontrado) return (posicion - 1);
	else return (-1);
}

ListaContigua::~ListaContigua() {
	free(vector);
}
