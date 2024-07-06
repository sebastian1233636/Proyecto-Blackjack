#include "ListaMano.h"

ListaMano::ListaMano(){primero = nullptr;/*se inicializa orimero en null para que la lista inicie en vacio*/ }

ListaMano::~ListaMano(){
	//destructor de clase, elimina los nodos
	NodoM* aux = primero;
	while (aux != nullptr) {
		primero = primero->getSiguiente();
		delete aux;
		aux = primero;
	}
}

bool ListaMano::agregarCarta(Mazo* m){
	//toma el mazo por parametro y saca la ultima carta de este para luego agregarla
	//agrega la carta si el primero esta en vacio
	NodoM* aux = primero;
	if (primero == nullptr) {
		primero = new NodoM(m->tomarCarta(), nullptr);
	}
	//en caso de que no sea vacio recorre hasta que el siguiente de aux sea null y cunado se umple ese siguiente pasa a ser el nuevo nodo junto al nuevo elemento
	else {
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(new NodoM(m->tomarCarta(), nullptr));
	}
	return false;
}

bool ListaMano::agregarCartaCargada(Carta* m){
	//misma funcion que el agregar pero este recibe por parametro una carta
	NodoM* aux = primero;
	if (primero == nullptr) {
		primero = new NodoM(m, nullptr);
	}
	else {
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(new NodoM(m, nullptr));
		return true;
	}
	return false;
}

void ListaMano::limpiar(){
	//elimina la mano del jugador
	NodoM* aux = primero;
	while (aux != nullptr) {
		primero = aux->getSiguiente();
		delete aux;
		aux = primero;
	}
}

int ListaMano::getPuntos(){
	//recorre la mano del jugador, se trae los puntos y luego los suma 
	int punt = 0;
	NodoM* aux = primero;
	while (aux != nullptr) {
		punt = aux->getCarta()->getPuntos() + punt;
		aux = aux->getSiguiente();
	}
	//asigna el valor del as dependiendo de la mano del jugador, usa la funcion buscar As
	if (buscarAs() == true && (punt + 10) <= 21) {
		punt = punt + 10;
	}
	return punt;
}

bool ListaMano::buscarAs() {
	//recorre la lista y busca un As de acuerdo a su valor que es 1 y devuelve true si lo encontro
	NodoM* aux = primero;
	while (aux != NULL)
	{
		if (aux->getCarta()->getValor() == 1)
		{
			return true;
			break;
		}
		aux = aux->getSiguiente();
	}
	return false;
}

string ListaMano::ImprimirMano(){
	//Recorre la lista e imprime toda la mano del jugador 
	stringstream s;
	NodoM* aux = primero;
	while (aux != nullptr) {
		aux->getCarta()->imprimir_Carta();
		s << "\t";
		aux = aux->getSiguiente();

	}
	return s.str();
}

void ListaMano::voltearcarta(bool BoA) {
	//El metodo voltea la segunda carta de la mano del dealer
	NodoM* aux = primero->getSiguiente();
	aux->getCarta()->setBocaAbajo(BoA);
 

}


void ListaMano::guardarMano(ofstream& file){
	//recorre la lista crea un objeto ofstream usado para guardar para luego guardar los atributos de toda la mano del jugador y dealer
	NodoM* aux = primero;
	while (aux != nullptr) {
		file << aux->getCarta()->getValor() << "|";
		file << aux->getCarta()->getPalo() << "|";
		file << aux->getCarta()->getPuntos() << "|";
		file << aux->getCarta()->getBocaAbajo() << "\n";
		aux = aux->getSiguiente();
	}
}

void ListaMano::cargarMano(ifstream& file){
	Carta* aux = nullptr;
	Carta* aux2 = nullptr;

	string Memoria;
	string valor1;
	string palo1;
	string puntos1;

	bool bocaabajo1;

	while (getline(file, Memoria)) {//se guarda en la memoria el texto
		istringstream line{ Memoria };//lee todo lo que haya en una linea hasta el salto linea
		getline(line, valor1, '|');//con cada geline se toma lo que haya hasta el delimitador "|"
		getline(line, palo1, '|');
		getline(line, puntos1, '|');
		line >> bocaabajo1;
		aux2 = aux->cargarCarta(valor1, palo1, puntos1, bocaabajo1);//se le asigna a una variable auxiliar otra variable auxiliar la cual tiene la carta cargada del archivo 
		aux2->setBocaAbajo(false);//se voltea la carta para que se imprima de manera correcto
		agregarCartaCargada(aux2);//se agrega a la mano del jugador cuando se cargan los archivos
	}
}

void ListaMano::eliminarTercera()
{
	NodoM* aux = primero;
	if (aux->getSiguiente()->getSiguiente() != nullptr) {
		delete aux->getSiguiente()->getSiguiente();
	}
	else {
		cout << "";
	}
}
