#include "NodoM.h"

NodoM::NodoM(Carta* car, NodoM* sig) :carta(car), siguiente(sig){}

NodoM::~NodoM(){
	//si hay una carta la elimina
	if (carta != nullptr) {
		delete carta;
	}
}
//setters y getters de clase
Carta* NodoM::getCarta(){return carta;}

NodoM* NodoM::getSiguiente(){return siguiente;}

void NodoM::setCarta(Carta* c){carta = c;}

void NodoM::setSiguiente(NodoM* n){siguiente = n;}
