#pragma once

#include"JugadorGenerico.h"

//hereda de la clase JugadorGenerico
class Crupier :public JugadorGenerico{
public:
	
	Crupier(string);
	
	virtual~Crupier();

	Carta* volteaSegunda();

	virtual Carta* pedirCarta(Mazo*);

	//Metodos GET
	virtual string getNombre();	
	virtual ListaMano* getMano();
	
	virtual bool SePasa(JugadorGenerico*);

	virtual string toString();

    //Metodos relacionados con archivos
	virtual void guardarJugadores(ofstream&);
	static Crupier* CargarDealer(string);

};

