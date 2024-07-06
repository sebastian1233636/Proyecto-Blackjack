#include "Juego.h"

Juego::Juego(){
	//crea una baraja y una lista de jugadores automaticamente
	baraja = new Mazo();
	lista = new ListaJugadores();
}

Juego::~Juego(){
	if (lista != nullptr) {delete lista;}
	if (baraja != nullptr) {delete baraja;}
}

void Juego::Jugar() {
	//se crean e inicializan las variables necesarias para ejecutar el juego por completo
	Mazo* M1 = new Mazo();
	M1->inicializar();
	M1->barajar();
	string nick;
	int opx = 0;
	int canJ = 0;

	do {
		system("cls");
		cout << "                                                 ===========================\n";
		cout << "                                                 ||BIENVENIDO AL BLACKJACK|| " << "\t\t" << endl;
		cout << "                                                 ===========================\n\n\n";

		cout << "========================" << endl;
		cout << "[1]Juego Nuevo" << endl;
		cout << "[2]Cargar Partida" << endl;
		cout << "[3]Salir" << endl;
		cout << "========================" << endl;
		cout << "Ingresa una opcion: ";
		cin >> opx;

		switch (opx) {
		case 1: {
			//antes de iniciar con cualquier proceso de logica se limpia la lista de jugadores 
			lista->VaciarLista();
			system("cls");
			cout << "Digite la cantidad de jugadores que van a participar(MAXIMO:7):\n";
			cout << "Unicamente poner numeros del 1 al 7\n";
			cin >> canJ;
			if (canJ > 7 or canJ == 0) {
				system("cls");
				cout << "*******************ERROR!!*********************" << endl;
				cout << "El limite maximo de jugadores es 7. Por favor digite un numero menor" << endl;
				canJ = 0;
				system("pause");
			}
			for (int i = 0; i < canJ; i++) {//se crean y agregan los jugadores, despues se les reparte las 2 cartas para comenzar el juego
				cout << "Digite el nickname del Jugador " << i + 1 << ":";
				cin >> nick;
				JugadorGenerico* J1 = new Jugador(nick);
				lista->ingresarJugador(J1);
				for (int i = 0; i < 2; i++) {J1->getMano()->agregarCarta(M1);}
			}

			JugadorGenerico* dealer = new Crupier("CASA");//se crea y se agrega la casa junto con sus 2 cartas, la seguda carta se voltea mas adelante
			lista->ingresarJugador(dealer);
			for (int i = 0; i < 2; i++) {dealer->getMano()->agregarCarta(M1);}

			for (int j = 0; j < canJ; j++) {//aqui este for itera con la cantidad de jugadores que hay y les presenta las 4 opciones de juego
				char op;
				do {
					system("cls");
					/*aqui se muestran el jugador y el dealer como sio estuvieran de frente*/
					Jugador* JA = lista->RetornaJugador(j);
					cout << "\t\t\t" << dealer->getNombre() << "\n";
					dealer->getMano()->voltearcarta(true);
					cout << dealer->getMano()->ImprimirMano() << "\n";
					cout << "\t\t\t" << JA->getNombre() << "\n";
					cout << JA->getMano()->ImprimirMano() << "\n";
					cout << "Su puntaje actual es: " << JA->getMano()->getPuntos() << "\n\n";
					//Se evaluan los puntos del jugador para que pierda en caso de que su mano pase de 21
					if (JA->SePasa(JA) == true) {
						cout << "Se ha pasado de 21" << endl;
						op = 'P';
						system("pause");
					}
					else {
						cout << "(D)eme carta - (P)asar - (G)uardar Partida - (S)alir\n";
						cin >> op;//opcionesde de juego
					}
					switch (op) {
					case 'D': {
						cout << "----TOMAR CARTA----" << endl;
						JA->getMano()->agregarCarta(M1);
						system("cls");
						break;
					}
					case 'P': {
						system("cls");
						/*si el jugador pasa el dealer empieza a comer cartas hata tener 21 o pasarse*/
						cout << "\t\t\t" << dealer->getNombre() << "\n";
						dealer->getMano()->voltearcarta(false);
						if (dealer->getMano()->getPuntos() < 17) {dealer->getMano()->agregarCarta(M1);}
						dealer->getMano()->voltearcarta(false);
						cout << dealer->getMano()->ImprimirMano() << "\n";
						cout << JA->getNombre() << "\n";
						cout << JA->getMano()->ImprimirMano() << "\n";
						cout << ganar(JA, dealer) << endl;//se evelua quien de los 2 gana y se da el mensaje de despedida
						lista->EliminarJugador(JA->getNombre());
						cout << "----GRACIAS POR JUGAR----" << endl;
						system("pause");
						system("cls");
						cout << "----PASANDO DE TURNO----" << endl;
						//algoritmo para pasar de turnos, si no es nullptr pasa cambiando la jota del for de los turnos
						if (lista->RetornaJugador(j) != nullptr) {
							j = j + 1;

						}
						if (lista->RetornaJugador(j) == nullptr) {
							j = 0;
						}
						canJ--;
						if (j == canJ) {//si llega al jugador final, gane o pierda se eliminará el dealer ya que no quedarian jugadores
							system("cls");
							cout << "-------CERRANDO PARTIDA, PORFAVOR NO APAGUE EL PROGRAMA-------" << endl;
							lista->EliminarJugador(dealer->getNombre());
							op = 'S';
							cout << "Se esta cerrando la partida ya que no hay jugadores" << endl;
						}
						system("pause");
						break;
					}
					case 'G': {
						//guarda todos los datos de la partida
						system("cls");
						cout << "-------GUARDANDO PARTIDA, PORFAVOR NO APAGUE EL PROGRAMA-------" << endl;
						lista->guardarLista();
						lista->guardarManoJugadores();
						system("pause");
						break;
					}
					case 'S': {
						//en caso de que el jugador quiera salir la mano se eliminará
						JA->getMano()->limpiar();
						op = 'S';
						system("cls");
						cout << "----GRACIAS POR JUGAR----" << endl;
						system("pause");
						break;
					}
					}
				} while (op != 'S');
			}
			break;
		}
		case 2: {
			system("cls");
			lista->VaciarLista();
			cout << "------CARGAR PARTIDA------" << endl;
			cout << "Cargando la partida..." << endl;
			//carga los jugadores y sus respectivas manos de los archivos creados en guardar y se les da la opcion de jugar como se esplico arriba
			lista->cargarLista();
			lista->CargarManoJugadores();
			int canJ2 = lista->cantidadJugadores();
			for (int j = 0; j < lista->cantidadJugadores() - 1; j++) {
				char op;
				do {
					/*despues de haber cargado se ejecuta el juego con los jugadores y las manos correspondientes de manera normal*/
					system("cls");
					Crupier* dealer = lista->RetornaDealer("CASA");
					Jugador* JA = lista->RetornaJugador(j);
					cout << "\t\t\t" << dealer->getNombre() << "\n";
					dealer->getMano()->voltearcarta(false);
					cout << dealer->getMano()->ImprimirMano() << "\n";
					cout << "\t\t\t" << JA->getNombre() << "\n";
					cout << JA->getMano()->ImprimirMano() << "\n";
					cout << "Su puntaje actual es: " << JA->getMano()->getPuntos() << "\n\n";
					JA->SePasa(JA);
					if (JA->SePasa(JA) == true) {
						cout << "Se ha pasado de 21" << endl;
						op = 'P';
						system("pause");
					}
					else {
						cout << "(D)eme carta - (P)asar - (G)uardar Partida - (S)alir\n";
						cin >> op;
					}
					switch (op) {
					case 'D': {
						cout << "----TOMAR CARTA----" << endl;
						JA->getMano()->agregarCarta(M1);
						system("cls");
						break;
					}
					case 'P': {
						system("cls");
						cout << "\t\t\t" << dealer->getNombre() << "\n";
						dealer->getMano()->voltearcarta(true);
						if (dealer->getMano()->getPuntos() < 17) { dealer->getMano()->agregarCarta(M1); }
						dealer->getMano()->voltearcarta(false);
						cout << dealer->getMano()->ImprimirMano() << "\n";
						cout << JA->getNombre() << "\n";
						cout << JA->getMano()->ImprimirMano() << "\n";
						cout << ganar(JA, dealer) << endl;
						lista->EliminarJugador(JA->getNombre());
						cout << "----GRACIAS POR JUGAR----" << endl;
						system("pause");
						system("cls");
						cout << "----PASANDO DE TURNO----" << endl;
						if (lista->RetornaJugador(j) != nullptr) { j = j + 1; }
						if (lista->RetornaJugador(j) == nullptr) {j = 0;}
						canJ2--;
						if (j == canJ2 - 1) {
							system("cls");
							cout << "-------CERRANDO PARTIDA, PORFAVOR NO APAGUE EL PROGRAMA-------" << endl;
							lista->EliminarJugador(dealer->getNombre());
							op = 'S';
							cout << "Se esta cerrando la partida ya que no hay jugadores" << endl;
						}
						system("pause");
						break;
					}
					case 'G': {
						system("cls");
						cout << "-------GUARDANDO PARTIDA, PORFAVOR NO APAGUE EL PROGRAMA-------" << endl;
						lista->guardarLista();
						lista->guardarManoJugadores();
						system("pause");
						break;
					}
					case 'S': {
						JA->getMano()->limpiar();
						op = 'S';
						system("cls");
						cout << "----GRACIAS POR JUGAR----" << endl;
						system("pause");
						break;
					}
					}

				} while (op != 'S');
			}
			break;
		}
		case 3: {
			system("cls");
			cout << " ---Gracias por haber jugado---" << endl;
			cout << " Esperamos que se haya divertido\n\n";
			system("pause");
			opx = 3;
			break;
		    }
		default: {
			system("cls");
			cout << "---No se ha ingresado ninguno de los numeros correspondientes---\n";
			cout << "--------------------Gracias por haber jugado--------------------\n\n";
			opx = 3;
			break;
		}
		}
	} while (opx != 3);
}

string Juego::ganar(JugadorGenerico* n, JugadorGenerico* x){
	//examina las crtas del dealer y del jugador y define quine gana, pierde o si se empata
	if (Perder(x) == true) {
		stringstream s;
		s << "--Todos los jugadores han ganado--" << endl;
		s << "Ya que la casa se ha pasado de 21" << endl;
		return s.str();
	}
	if (Perder(n) == true) {return "Has perdido " + n->getNombre();}
	else {
		if (n->getMano()->getPuntos() > x->getMano()->getPuntos()) {return "Has ganado " + n->getNombre();}
		else if (n->getMano()->getPuntos() < x->getMano()->getPuntos()) {return "Ha ganado la casa ";}
		else {return "Han empatado ";}
	}
}

bool Juego::Perder(JugadorGenerico* n){
	//metodo que define la derrota usando el metodo sePasa()
	if (n->SePasa(n) == true) {return true;}
	return false;
}
