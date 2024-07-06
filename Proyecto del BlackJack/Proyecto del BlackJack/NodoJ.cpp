#include "NodoJ.h"

NodoJ::NodoJ(JugadorGenerico* jug, NodoJ* sig) :jugador(jug), siguiente(sig){}

NodoJ::~NodoJ(){
	if (jugador != nullptr) {
		delete jugador;
	}
}

JugadorGenerico* NodoJ::getJugador(){return jugador;}

NodoJ* NodoJ::getSiguiente(){return siguiente;}

void NodoJ::setJugador(JugadorGenerico* j){jugador = j;}

void NodoJ::setSiguiente(NodoJ* n){siguiente = n;}
