#include "Tablero.h"

void iniciaTablero(tTablero tablero) {
	for (int fila = 0; fila < MAX_TAM; fila++) {
		for (int col = 0; col < MAX_TAM; col++) {
			iniciaCasilla(tablero[fila][col]);
		}
	}
}

bool cargarTablero(string nombreFichero, tTablero tablero) {
	ifstream fich;
	bool carga;
	string str;

	fich.open(nombreFichero);
	if (!fich.is_open()) {
		carga = false;
		cout << "Archivo no cargado" << endl;
	}
	else {
		carga = true;
		for (int i = 0; i < MAX_TAM; i++) {
			getline(fich, str);

			for (int j = 0; j < str.length(); j++) {
				
				rellenaCasilla(tablero[i][j], str[j], true);
				actualiza(tablero, i, j);				
			}
		}
	}
	fich.close();
	return carga;
}

void dibujarTablero(const tTablero tablero) {
	cout << "---------------------------\n";

}
//TERMINAR

bool ponerNum(tTablero tablero, int fila, int col, int c) {
	bool posible = false;
	
	if (tablero[fila][col].estado == VACIA && tablero[fila][col].c.valor[c - 1] == true) {
		posible = true;
		rellenaCasilla(tablero[fila][col], c, false);
		dibujaCasilla(tablero[fila][col]);
	}


	actualiza(tablero, fila, col);
	return posible;

}
bool borrarNum(tTablero tablero, int fila, int col) {
	bool posible = false;
	if (tablero[fila][col].estado == RELLENADA) {
		posible = true;
		annadeElemento(tablero[fila][col].c, tablero[fila][col].num);
		rellenaCasilla(tablero[fila][col], ' ', false);
	}

	actualiza(tablero, fila, col);
	return posible;
}
//REVISAR

bool tableroLleno(const tTablero tablero) {
	int fila = 0, columna = 0;
	bool lleno;

	while (fila < MAX_TAM && tablero[fila][columna].estado != VACIA) {
		while (columna < MAX_TAM && tablero[fila][columna].estado != VACIA) {
			columna++;
		}
		fila++;
	}
	if (tablero[fila][columna].estado == VACIA) {
		lleno = false;
	}
	else if (fila == MAX_TAM && columna == MAX_TAM) {
		lleno = true;
	}
	return lleno;
}

void mostrarPosibles(const tTablero tablero, int fila, int col) {
	cout << "Numeros posibles: ";
	for (int i = 0; i < 9; i++) {
		if (tablero[fila][col].c.valor[i] == true) {
			cout << i + 1 << ", ";
		}
	}
}

void rellenarSimples(tTablero tablero) {
	int numero, fila, col;
	bool valorUnico;
	tCasilla casilla;
	
	for (int i = 0; i < MAX_TAM; i++) {
		for (int j = 0; j < MAX_TAM; j++) {
			valorUnico = esSimple(casilla, numero); //quitar "casilla"
			if (valorUnico == true) {
				tablero[i][j].num = numero;
				fila = i;
				col = j;

				actualiza(tablero, fila, col);

			}
		}
	}

}

void actualiza(tTablero tablero, int fila, int col) {
	int x, y;
	
	for (int i = 0; i < MAX_TAM; i++) {
		borraElemento(tablero[fila][i].c, tablero[fila][col].num);
	}
	for (int i = 0; i < MAX_TAM; i++) {
		borraElemento(tablero[i][col].c, tablero[fila][col].num);
	}
		x = (col / 3) * 3;
		y = (fila / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			borraElemento(tablero[x + i][y + j].c, tablero[fila][col].num);
		}
	}
	
}