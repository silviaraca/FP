#ifndef ListaOpciones_h
#define ListaOpciones_h
#include "ListaLugares.h"

const int INI = 3;

typedef struct tOpc
{
	tLugar * OpcPlaya;
	tLugar * OpcSierra;
};

typedef struct tListaOpc
{
	int cont;
	int tam = 0;
	tOpc * opciones;	
};

void liberar(tListaOpc& lista);
void nuevoViaje(tListaOpc& lista);
void ampliar(tListaOpc& lista);
#endif