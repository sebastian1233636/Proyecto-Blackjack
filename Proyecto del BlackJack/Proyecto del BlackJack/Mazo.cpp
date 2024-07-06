#include "Mazo.h"


Mazo::Mazo(){
	//se construye el vector de cartascon 52 espacios
	can = 0;
	tam = 52;
	VecCartas = new Carta * [tam];
	for (int i = 0; i < tam; i++) {
		VecCartas[i] = nullptr;
	}
}

Mazo::~Mazo(){
	//se destruye de manera correspondiente para evitar leaks de memoria
	for (int i = 0; i < can; i++) {
		delete VecCartas[i];
	}
	delete[] VecCartas;
}

void Mazo::inicializar() {
	
	if (can < tam) {//crea 52 cartas exactas
		for (int type = 1; type <= 4; type++) {//asigna un numero de acuerdo al for para los palos
			for (int num = 1; num <= 13; num++) {//asigna un numero para las cartas de cada palo
				VecCartas[can] = new Carta(num, type, 0, false);//en cada posicion del vector se crean cartas. se crean primero 13 de un tipo y luego del siguiente y asi sucesivamente 
				can++; //se mueve al siguiente espacio del vector
			}
		}
	}
}

void Mazo::mostrarMazo() {
	//muestra todo mazo
	for (int i = 0; i < can; i++) {
		if (getCarta(i) != nullptr) {
			getCarta(i)->imprimir_Carta();
		}
		else {
			cout << "" << endl;
		}
	}
}

void Mazo::eliminar(int i){
	//elimina una carta en una posicion especifica y luego hace el corrimiento
	if (i >= 0 && i < this->can) {
		delete this->VecCartas[i];

		for (int j = i; j < this->can; j++)
		{
			this->VecCartas[j] = this->VecCartas[j + 1];
		}
		this->can--;
	}
}

Carta* Mazo::getCarta(int i) {
	//retorna la carta en posicion especifica
	if (i > can) {
		return nullptr;
	}
	return *(VecCartas + i);
}

void Mazo::barajar(){random_shuffle(&VecCartas[0], &VecCartas[52]);}//funcion shuffle para barajar el mazom, requiere el primer y ultimo elemento del vector a revolver
//se requiere biblioteca algorithm y random

Carta* Mazo::tomarCarta(){
	//toma la ultima carta del mazo
	Carta* aux = nullptr;
	for (int i = 51; i >= 0; i--)
	{
		//toma la ultima carta del vector y pone el ultimo espacio en null para que en la siguiente se ignore ese espacio
		if (VecCartas[i] != nullptr) {
			aux = VecCartas[i];
			VecCartas[i] = nullptr;
			i = -2;
		}
	}
	return aux;
}
