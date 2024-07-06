#pragma once

#include"JugadorGenerico.h"
#include"Jugador.h"
#include"Crupier.h"

class NodoJ{
private:

	JugadorGenerico* jugador;
	NodoJ* siguiente;

public:

	NodoJ(JugadorGenerico*, NodoJ*);

	virtual~NodoJ();

	JugadorGenerico* getJugador();
	NodoJ* getSiguiente();

	void setJugador(JugadorGenerico*);
	void setSiguiente(NodoJ*);

};

