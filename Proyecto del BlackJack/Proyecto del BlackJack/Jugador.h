#pragma once

#include"JugadorGenerico.h"


//hereda de la clase JugadorGenerico
class Jugador :public JugadorGenerico{
public:
	//metodos explicados en el cpp
	Jugador(string);

	virtual~Jugador();

	virtual Carta* pedirCarta(Mazo*);

	virtual string getNombre();	
	virtual ListaMano* getMano();

	virtual bool SePasa(JugadorGenerico*);

	virtual string toString();

	virtual void guardarJugadores(ofstream&);
	static Jugador* CargarJugador(string);
};
