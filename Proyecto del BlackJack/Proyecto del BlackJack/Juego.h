#pragma once
#include"Utilidades.h"
#include"ListaJugadores.h"

class Juego{
private:

	ListaJugadores* lista;
	Mazo* baraja;

public:

	Juego();

	virtual~Juego();

	void Jugar();

	bool Perder(JugadorGenerico*);

	string ganar(JugadorGenerico*, JugadorGenerico*);

};




