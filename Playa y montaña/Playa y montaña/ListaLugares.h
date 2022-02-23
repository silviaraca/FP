#ifndef ListaLugares_h
#define ListaLuagres_h
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX = 100;

typedef struct tLugar
{
	string nombre;
	int precio;
};

typedef struct tListaLugares
{
	int cont;
	tLugar * lugares[MAX];
};

void buscar(const tListaLugares& lista, string nombre, int fin, int ini, int& pos);
void liberar(tListaLugares& lista);


#endif