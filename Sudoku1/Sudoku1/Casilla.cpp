#include "Casilla.h"


void iniciaCasilla(tCasilla & casilla) {

	casilla.estado = VACIA;
	cjto_lleno(casilla.c);
	casilla.num = 0;
}
void rellenaCasilla(tCasilla & casilla, char c, bool fija) {	
	if (c == ' ')
	{
		casilla.estado = VACIA;
	}
	else {
		if (fija == true)
		{
			cjto_vacio(casilla.c);
			casilla.estado = FIJA;
		}
		else
		{
			casilla.estado = RELLENADA;
			borraElemento(casilla.c, c-48);
		}
		casilla.num = c - 48;
	}

}
void dibujaCasilla(const tCasilla & casilla) {

	if (casilla.estado == FIJA) {
		colorFondo(1);
	}
	else if (casilla.estado == RELLENADA) {
		colorFondo(4);
	}
	else {
		colorFondo(0);
	}

	if (casilla.num == 0) {
		cout << " ";
	}
	else { cout << casilla.num; }
	

	colorFondo(0);
}
void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}
bool esSimple(const tCasilla & casilla, int & numero) {
	bool simple = false;
	
	while (casilla.estado == VACIA) {
		if (esUnitario(casilla.c, numero)) {
			simple = true;
			for (int i = 0; i < MAX; i++) {
				if (casilla.c.valor[i] == true) {
					numero = i + 1;
				}
			}
		}
	}
	return simple;
}
