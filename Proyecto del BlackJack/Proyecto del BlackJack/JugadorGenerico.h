#pragma once

#include"ListaMano.h"
#include"Mazo.h"



//CLASE ABSTRACTA LA CUAL HEREDA A CRUPIER Y A JUGADOR
class JugadorGenerico{
protected:

	string nombre;
	ListaMano* mano;

public:
	//constructor destructor y metodos virtual
	JugadorGenerico(string);

	virtual~JugadorGenerico();

	virtual Carta* pedirCarta(Mazo*) = 0;

	virtual string getNombre() = 0;	
	virtual ListaMano* getMano() = 0;

	virtual bool SePasa(JugadorGenerico*) = 0;

	virtual string toString() = 0;

	virtual void guardarJugadores(ofstream&) = 0;

};

