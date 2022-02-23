#include "listaCompradores.h"

void inicializar(tListaCompradores & lista)
{
	lista.cont = 0;
	lista.tam = INI;
	lista.compradores = new tComprador[lista.tam];
}

void insertar(tListaCompradores & lista, tComprador comprador, float precio)
{
	bool encontrado = false;
	int ind = 0;
	while (ind < lista.cont && !encontrado)
	{
		if (lista.compradores[ind].num == comprador.num)
		{
			lista.compradores[ind].importe += precio;
			encontrado = true;
		}
		ind++;
	}
	if (!encontrado)
	{
		if (lista.cont = lista.tam)
		{
			ampliar(lista);
		}
		lista.compradores[lista.cont] = comprador;
	}
}

bool buscar(const tListaCompradores& lista, long long int num, int & pos)
{
	bool encontrado = false;
	int ind = 0;

	while (ind < lista.cont && !encontrado)
	{
		if (lista.compradores[ind].num == num)
		{
			pos = ind;
			encontrado = true;
		}
		ind++;
	}

	return encontrado;
}

void mostrarC(const tListaCompradores & lista)
{
	cout << endl << "LISTA DE COMPRADORES:" << endl;
	for (int i = 0; i < lista.cont; i++)
	{
		cout << endl << "Id: " << setw(14) << right << lista.compradores[i].num << setw(30) << right << "Importe: " << lista.compradores[i].importe << endl;
	}
}


void liberar(tListaCompradores& lista)
{
	delete[] lista.compradores;
	lista.cont = 0;
	lista.tam = 0;
	lista.compradores = nullptr;
}

void ampliar(tListaCompradores& lista)
{
	tComprador * aux = lista.compradores;
	lista.tam *= 2;
	lista.compradores = new tComprador[lista.tam];
	for (int i = 0; i < lista.cont; i++)
	{
		lista.compradores[i] = aux[i];
	}
	delete[]aux;
}