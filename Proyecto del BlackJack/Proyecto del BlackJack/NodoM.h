#pragma once

#include"Mazo.h"
//clase nodo que forma parte de la lista enlazada de mano
class NodoM{
private:
	
	//objeto que almacena y apuntador al siguiente nodo
	Carta* carta;
	NodoM* siguiente;

public:

	NodoM(Carta*, NodoM*);

	virtual~NodoM();

	Carta* getCarta();
	NodoM* getSiguiente();

	void setCarta(Carta*);
	void setSiguiente(NodoM*);

};