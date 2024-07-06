#include "Crupier.h"

Crupier::Crupier(string nom) :JugadorGenerico(nom){
	mano = new ListaMano();
}

Crupier::~Crupier(){}

Carta* Crupier::volteaSegunda(){return nullptr;}


//TODOS LOS METODOS TIENEN LA MISMA FUNCION QUE EN LA CLASE JUGADOR
Carta* Crupier::pedirCarta(Mazo* n){return n->tomarCarta();}

string Crupier::getNombre(){return nombre;}

ListaMano* Crupier::getMano(){
	return mano;
}

bool Crupier::SePasa(JugadorGenerico* n){
	if (n->getMano()->getPuntos() > 21) {
		return true;
	}
	return false;
}

string Crupier::toString(){
	stringstream s;
	s << "Dealer:" << nombre << endl;
	return s.str();
}

void Crupier::guardarJugadores(ofstream& file){
	file << nombre << '\n';
}

Crupier* Crupier::CargarDealer(string file){
	return new Crupier(file);//crea y retorna un objeto Crupier
}
