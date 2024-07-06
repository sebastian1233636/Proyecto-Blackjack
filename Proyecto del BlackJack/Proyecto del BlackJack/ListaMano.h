#pragma once

#include"NodoM.h"
//clase mano, cada jugador posee una mano
class ListaMano{
private:

	NodoM* primero;

public:

	ListaMano();

	virtual~ListaMano();

	bool agregarCarta(Mazo*);

	bool agregarCartaCargada(Carta*);

	void limpiar();

	int getPuntos();

	bool buscarAs();

	string ImprimirMano();

	void voltearcarta(bool);

	void guardarMano(ofstream&);
	void cargarMano(ifstream&);
	void eliminarTercera();

};
