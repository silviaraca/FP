#include <Windows.h>
#include <iostream>

#include "casilla.h"
using namespace std;

int main() {
	cout << "Test casilla" << endl;
	cout << "------------" << endl;
	tCasilla p1, p2, p3;
	iniciaCasilla(p1);
	iniciaCasilla(p2);
	iniciaCasilla(p3);
	rellenaCasilla(p1, '9', true);   //lectura desde fichero
	rellenaCasilla(p2, ' ', false);
	rellenaCasilla(p3, '1', false);
	rellenaCasilla(p2, ' ', true);

	dibujaCasilla(p1);
	dibujaCasilla(p2);
	dibujaCasilla(p3);

	cout << endl << endl;
	system("pause");
}