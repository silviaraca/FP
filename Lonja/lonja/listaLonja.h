#ifndef listaLonja_h
#define litaLonja_h
#include "lotes.h"

const int MAX_LOTES = 300;

typedef struct tListaLotes
{
	int cont;
	tLotes * lotes[MAX_LOTES];
};

void inicializar(tListaLotes& lista);
int numLotes(const tListaLotes& lista);
void insertar(tListaLotes& lista, tLotes lote);
void cargar(tListaLotes& lista);
bool buscar(const tListaLotes& lista, string id, string tipo, int& pos);
tLotes obtenerLote(const tListaLotes& lista, int pos);
void mostrar(const tListaLotes& lista);
void liberar(tListaLotes& lista);

#endif
