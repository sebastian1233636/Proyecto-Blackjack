#pragma once

#include"NodoJ.h"

class ListaJugadores{
private:

	NodoJ* primero;

public:

	ListaJugadores();

	virtual~ListaJugadores();

	NodoJ* getPrimero();
	//ingresa jugadores
	bool ingresarJugador(JugadorGenerico*);
	//elimina jugadores	
	bool EliminarJugador(string);
	//muestra todos los jugadores
	string mostrarPersonas();
	//retorna un jugador en una posicion especifica
	Jugador* RetornaJugador(int);
	//verifica si hay nombre repetido
	bool NombreRepetido(JugadorGenerico*);
	//metodos que verifican si la lista esta vacia y que la limpian
	bool ListaVacia();
	void VaciarLista();
	//metodos para guardar y cargar en archivos
	void guardarLista();
	void cargarLista();

	void guardarManoJugadores();
	void CargarManoJugadores();
	

	int cantidadJugadores();
	Crupier* RetornaDealer(string);

};
