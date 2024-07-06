#pragma once
#include"Utilidades.h"

using namespace std;

//CLASE CARTA USADA NE EL JUEGO
class Carta{
private://ATRIBUTOS DE LA CLASE CARTA

	int valor;
	int palo;
	int puntos;
	bool bocaAbajo;

public:
	//COSNTRUCTOR Y DESTRUCTOR
	Carta();
	Carta(int, int, int, bool);

	virtual~Carta();
	//GETTERS
	int getValor();
	int getPalo();
	int getPuntos();
	bool getBocaAbajo();
	//SETTERS
	void setBocaAbajo(bool);
	//METODS PARA IMPRIMIR CADA ATRIBUTO DE LA CARTA 
	void imprimir_Palo();
	void imprimir_Tipo();
	void imprimir_Carta();

	void Voltear(bool);

	static Carta* cargarCarta(string, string, string, bool);//METODO NCESARIO PARA ARCHIVOS, CARGA UNA CARTA

};
