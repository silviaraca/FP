#ifndef listaCompradores_h
#define listaCompradores_h
#include "listaLonja.h"

const int INI = 5;

typedef struct tComprador
{
	long long int num;
	float importe;
};

typedef struct tListaCompradores
{
	int cont;
	int tam;
	tComprador * compradores;
};

void inicializar(tListaCompradores& lista);
void insertar(tListaCompradores& lista, tComprador comprador, tLotes precio);
bool buscar(const tListaCompradores& lista, long long int num, int& pos);
void mostrarC(const tListaCompradores& lista);
void liberar(tListaCompradores& lista);

#endif
