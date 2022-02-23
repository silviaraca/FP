#include "ListaOpciones.h"

void liberar(tListaOpc & lista)
{
	delete[]lista.opciones;
	lista.tam = 0;
	lista.cont = 0;
	lista.opciones = nullptr;
}

void nuevoViaje(tListaOpc & lista)
{
	string playa, sierra;


	cout << "Elige una playa: ";
	cin >> playa;
	cout << endl << "Elige una sierra: ";
	cin >> sierra;
}

void ampliar(tListaOpc & lista)
{
}
