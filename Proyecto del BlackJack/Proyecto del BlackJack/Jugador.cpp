#include "Jugador.h"

Jugador::Jugador(string nom) : JugadorGenerico(nom){mano = new ListaMano();}

Jugador::~Jugador(){}

Carta* Jugador::pedirCarta(Mazo* n){return n->tomarCarta();}//toma la utlima carta del mazo

string Jugador::getNombre(){return nombre;}

ListaMano* Jugador::getMano(){return mano;}

bool Jugador::SePasa(JugadorGenerico* n){
	//evalua si los puntos del jugador se pasan 
	if (n->getMano()->getPuntos() > 21) {
		return true;
	}
	return false;
}

string Jugador::toString(){
	//imprime el nombre del jugadir
	stringstream s;

	s << "Jugador:" << nombre << endl;
	return s.str();
}

void Jugador::guardarJugadores(ofstream& file){file << nombre << '\n';}//Guarda el nombre del jugador

Jugador* Jugador::CargarJugador(string file){return new Jugador(file);}//crea y retorna un jugador


