#include "Utilidades.h"

int conversion(string aux) {
	stringstream s(aux);
	int v;
	s >> v;
	return v;
}

bool conversionBool(string aux) {
	stringstream r(aux);
	int c;
	r >> c;
	return c;
}