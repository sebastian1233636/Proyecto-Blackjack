#include"Juego.h"
//PROGRAMADORES: Anthony li Perera, Sebastián Álvarez Gómez, Wagner Barrantes Mora
int main() {
	srand(time(NULL));//Funcion para numeros aleatorios 
	Juego* A1 = new Juego();//Funcion que contiene toda la logica del juego
	A1->Jugar();//se ejetcuta El juego
	return 0;
}