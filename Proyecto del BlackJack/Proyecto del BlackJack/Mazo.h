#pragma once

#include"Carta.h"
//clase mazo de la cual se sacan las cartas
class Mazo{
private:

	Carta** VecCartas;
	int can;
	int tam;

public:

	Mazo();

	virtual~Mazo();

	void inicializar();

	void mostrarMazo();

	void eliminar(int);

	Carta* getCarta(int);

	void barajar();

	Carta* tomarCarta();

};

