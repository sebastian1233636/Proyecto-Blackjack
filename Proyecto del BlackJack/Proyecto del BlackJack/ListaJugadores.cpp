#include "ListaJugadores.h"

ListaJugadores::ListaJugadores(){primero = nullptr;}

ListaJugadores::~ListaJugadores(){
	NodoJ* aux = primero;
	while (aux != nullptr) {
		primero = aux->getSiguiente();
		delete aux;
		aux = primero;
	}
}

NodoJ* ListaJugadores::getPrimero(){return primero;}

bool ListaJugadores::ingresarJugador(JugadorGenerico* n) {

	NodoJ* aux = primero;
	//si el primero esta vacio ingresa el nodo junto al jugador
	if (primero == nullptr) {
		primero = new NodoJ(n, nullptr);
		return true;
	}
	//si la lista no esta vacia recorre hasta que el siguiente sea null y mete el nodo junto al jugador
	if (primero != nullptr) {
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		//hace la verificacion de que si el nombre es repetido
		if (NombreRepetido(n) == true) {
			return false;
		}
		else {
			aux->setSiguiente(new NodoJ(n, nullptr));
			return true;
		}
	}
	return false;
}

bool ListaJugadores::EliminarJugador(string nom){

	NodoJ* aux = primero;
	NodoJ* anterior = nullptr;
	//si es el primero elimina el nodo y el jugador
	if (primero != nullptr && primero->getJugador()->getNombre() == nom) {
		NodoJ* actual = primero;
		primero = actual->getSiguiente();
		delete actual;
		return true;
	}
	//si no es el primero recorre la lista hasta encontrar una coincidencia, acomoda los enlaces y borra el Nodo deseado
	else {
		while (aux != nullptr && aux->getJugador()->getNombre() != nom) {
			anterior = aux;
			aux = aux->getSiguiente();
		}
		anterior->setSiguiente(aux->getSiguiente());
		delete aux;
		return true;
	}
	return false;
}

string ListaJugadores::mostrarPersonas(){
	//muestra las personas del juego
	stringstream s;
	NodoJ* aux = primero;
	while (aux != nullptr) {
		s << aux->getJugador()->toString() << endl;
		aux = aux->getSiguiente();
	}
	return s.str();
}

Jugador* ListaJugadores::RetornaJugador(int pos){
	//retorna el jugador que se requiera, se uso el dynamic cast por temas de polimorfismo y para mas facilidad
	NodoJ* aux = primero;
	while (aux != nullptr) {
		for (int i = 0; i <= pos; i++) {
			if (i == pos) {
				return dynamic_cast<Jugador*>(aux->getJugador());//cuando llega a la posicion deseada hace la conversion a jugador y lo retorna 
			}
			aux = aux->getSiguiente();
		}
	}
	return nullptr;
}

bool ListaJugadores::NombreRepetido(JugadorGenerico* n){
	//verifica si es repétido, si lo es retorna true, delo contrario false
	NodoJ* aux = primero;

	while (aux != nullptr) {
		if (n->getNombre() == aux->getJugador()->getNombre()) {
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
}

bool ListaJugadores::ListaVacia(){
	//ve si la lista esta vacia 
	if (primero == nullptr) {
		return true;
	}
	return false;
}

	void ListaJugadores::VaciarLista(){
		//elimina los elementos de toda la lista
		NodoJ* tmp;
		while (primero != nullptr) {
			tmp = primero;
			primero = primero->getSiguiente();
			delete tmp;
		}
}

void ListaJugadores::guardarLista(){

	ofstream file;
	NodoJ* aux = primero;
	file.open("../Jugadores.txt");//abre un archivo
	if (file.is_open()) {//verifica si se abrio bien
		while (aux != nullptr) {//recorre la lista
			aux->getJugador()->guardarJugadores(file);//llama al metodo para guardar el jugador en ese nodo
			aux = aux->getSiguiente();//pasa al siguiente nodo
		}
	}
	else {
		cout << "No se abrio el archivo" << endl;
	}
	file.close();//cierra el archivo
}

void ListaJugadores::cargarLista(){

	ifstream file;
	string tipo = "";
	file.open("../Jugadores.txt");//abre el arhivo
	if (file.is_open()) {//verifica si se abrio
		while (getline(file, tipo, '\n')) {//lee la primera linea 
			if (tipo == "CASA") {//si en la variable tipo se guardo CASA el objeto se carga como crupier y se almacena como tal
				JugadorGenerico* aux = Crupier::CargarDealer(tipo);
				if (aux->getNombre() != "") {//verifica si se cargo correctamente 
					ingresarJugador(aux);
				}
			}
			else {//si no es CASA se ingresa como jugador
				JugadorGenerico* aux2 = Jugador::CargarJugador(tipo);
				if (aux2->getNombre() != "") {//verifica si se cargo correctamente 
					ingresarJugador(aux2);//se ingresa 
				}
			}
		}
	}
	else {
		cout << "No se abrio el archivo" << endl;
	}
	file.close();//se cierra el archivo
}

void ListaJugadores::guardarManoJugadores() {

	NodoJ* aux = primero;

	ofstream file;
	string nombre;
	//para facilidad de recuperacion y separacion se crea un archivo por cada mano de jugador
	while (aux != nullptr) {//se crea un while para que avance hacie el sigiente jugador

		nombre = "../Mano" + aux->getJugador()->getNombre() + ".txt";//se crea el nombre del archivo junto con el nombre de cada jugador

		file.open(nombre);// se abre el archivo
		if (!file.is_open()) {
			std::cout << "Error al abrir el archivo...\n";
		}

		aux->getJugador()->getMano()->guardarMano(file);//se guarda la mano
		aux = aux->getSiguiente();// se pasa al siguiente jugador
		file.close();// se cierra el archivo
	}
}

void ListaJugadores::CargarManoJugadores(){
	//Mismo funcionamiento que la funcion guardar
	NodoJ* aux = primero;
	ifstream file;
	string nombre;
	while (aux != nullptr) {
		nombre = "../Mano" + aux->getJugador()->getNombre() + ".txt";


		file.open(nombre, ios::in);
		if (!file.is_open()) {
			std::cout << "Error al abrir el archivo...\n";
		}
		aux->getJugador()->getMano()->cargarMano(file);//en luigar de guardar se le carga la mano a cada jugador
		aux = aux->getSiguiente();
		file.close();
	}
}



int ListaJugadores::cantidadJugadores()
{
	//un contador el cual cada vez que se pase al siguiente nodo aumenta y al final lo retorna 
	NodoJ* aux = primero;
	int cont = 0;
	while (aux != nullptr) {
		cont++;
		aux = aux->getSiguiente();
	}
	return cont;
}

Crupier* ListaJugadores::RetornaDealer(string nom)
{
	//Busca y retorna el dealer, se usa dynamic cast
	NodoJ* aux = primero;
	while (aux != nullptr) {
		if (aux->getJugador()->getNombre() == nom) {
			return dynamic_cast<Crupier*>(aux->getJugador());// cuando encuentre el nombre de la casa, hace la conversion y retorna el dealer
		}
		else {
			aux = aux->getSiguiente();
		}
	}
	return nullptr;
}

