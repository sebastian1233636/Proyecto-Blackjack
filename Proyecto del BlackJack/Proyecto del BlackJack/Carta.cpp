#include "Carta.h"

Carta::Carta(){
    valor = 0;
    palo = 0;
    puntos = 0;
    bocaAbajo = false;
}

Carta::Carta(int val, int pal, int point, bool BA) :valor(val), palo(pal), puntos(point), bocaAbajo(BA){}

Carta::~Carta(){}

int Carta::getValor(){return valor;}
int Carta::getPalo(){return palo;}
int Carta::getPuntos(){return puntos;}
bool Carta::getBocaAbajo(){return bocaAbajo;}

void Carta::setBocaAbajo(bool a){bocaAbajo = a;}

void Carta::Voltear(bool Bo){
    
    if (Bo == true) {
        bocaAbajo = true;
    }
    else {
        bocaAbajo = false;
    }
}

Carta* Carta::cargarCarta(string v, string pa, string pun, bool BA){
    //aqui se transforman los strings que recuperó el archivo a enteros y se decuelve la carta correspondiente
    int valor2 = conversion(v);
    int palo2 = conversion(pa);
    int puntos2 = conversion(pun);
    return new Carta(valor2, palo2, puntos2, BA);
}

void Carta::imprimir_Palo() {
    //IMPRIME EL PALO SEGUN EL NUMERO QUE CORREPONDA
    if (palo == 1){
        std::cout << "    Diamantes";
    }

    else if (palo == 2){
        std::cout << "    Espadas";
    }

    else if (palo == 3){
        std::cout << "   Treboles";
    }

    else if (palo == 4){
        std::cout << "   Corazones";
    }
}

void Carta::imprimir_Tipo(){
    //IMPRIME EL TIPO SEGUN EL NUMERO QUE CORRESPONDA PARA LAS CARTAS ESPECIALES, SI NO ENCUENTRA COINCIDENCIA DEVUELVE EL MISMO VALOR DE LA CARTA
    if (valor == 11){
        puntos = 10;
        std::cout << "J";
    }

    else if (valor == 12){
        puntos = 10;
        std::cout << "Q";
    }

    else if (valor == 13){
        puntos = 10;
        std::cout << "K";
    }

    else if (valor == 1){
        puntos = 1;
        std::cout << "As";
    }

    else{
        puntos = valor;
        std::cout << valor;
    }
}

void Carta::imprimir_Carta(){
    //SI EL ATRIBUTO BOCAABAJO ES FALSE IMPRIME LA CARTA, DE LO CONTRARIO IMPRIME ASTERICOS SIMULANDO UNA CARTA VOLTEADA
    if (bocaAbajo == false){
        cout << "-----------------" << endl;
        imprimir_Tipo();
        cout << endl;
        imprimir_Palo();
        cout << endl;
        cout << "\t\t";
        imprimir_Tipo();
        cout << endl;
        cout << "-----------------" << endl;
    }

    else{
        cout << "-----------------" << endl;
        cout << "*" << " " << endl;
        cout << endl;
        cout << " " << "   ********" << "" << endl;
        cout << endl;
        cout << " " << " " << "  \t\t*" << endl;
        cout << "-----------------" << endl;
    }
}