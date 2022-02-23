#include "ListaLugares.h"


void buscar(const tListaLugares & lista, string nombre, int fin, int ini, int& pos)
{
	int mitad;
	mitad = (ini + fin) / 2;
	if (nombre == lista.lugares[mitad]->nombre)
	{
		pos = mitad;
	}
	else if (nombre < lista.lugares[mitad]->nombre)
	{
		buscar(lista, nombre, mitad - 1, ini, pos);
	}
	else
	{
		buscar(lista, nombre, fin, mitad + 1, pos);
	}
}

void liberar(tListaLugares & lista)
{
}
