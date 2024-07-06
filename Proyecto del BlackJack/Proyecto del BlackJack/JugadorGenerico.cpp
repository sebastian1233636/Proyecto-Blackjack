#include "JugadorGenerico.h"

	JugadorGenerico::JugadorGenerico(string nom) :nombre(nom){mano = new ListaMano();/*Se crea el objeto y al mismo tiempo se crea y se le asocia un mano automaticamente*/ }

JugadorGenerico::~JugadorGenerico(){
	if (mano != nullptr) {
		delete mano;
	}
}

