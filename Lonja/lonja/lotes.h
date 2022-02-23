#ifndef lotes_h
#define lotes_h
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int TAM_MAX = 10;

typedef struct tLotes
{
	string id;
	string tipo;
	float precio;
	float peso;
	long long int comprador;
};

bool operator<(const tLotes& lote1, const tLotes& lote2);
bool operator==(const tLotes& lote1, const tLotes& lote2);
void mostrarLote(const tLotes& lote);
void mostrarPrecio(const tLotes& lote);
void modificarLote(tLotes& lote, string id, float precio);

#endif