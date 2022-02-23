#ifndef listaSudokus_h
#define listaSudokus_h	

#include "Juego.h"

const int MAX_SUDOKUS = 20;

typedef struct {
	tSudoku sudoku;
	int cont;
}tListaSudokus;

void creaListaVacia(tListaSudokus & lista);
bool cargar(tListaSudokus & lista);
void mostrar(const tListaSudokus & lista);


#endif