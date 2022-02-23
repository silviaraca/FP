#include "listaLonja.h"

void inicializar(tListaLotes& lista)
{
	lista.cont = 0;
}

int numLotes(const tListaLotes & lista)
{
	return lista.cont;
}

void insertar(tListaLotes & lista, tLotes lote)
{
	bool encontrado = false, ok = false, ok2 = false;
	int aux = 0, ind = 0;
	if (lista.cont == 0)
	{
		lista.lotes[0] = new tLotes();
		*lista.lotes[0] = lote;
		lista.cont++;
	}
	else
	{
		while (!encontrado && !ok)
		{
			for (int i = 0; i < lista.cont; i++)
			{
				if (*lista.lotes[i] == lote)
				{
					encontrado = true;
				}
			}
			ok = true;
		}
		if (!encontrado)
		{
			while(ind < lista.cont && !ok2)
			{
				if (operator<(lote, *lista.lotes[ind]))
				{
					for (int j = lista.cont - 1; j >= ind; j--)
					{
						lista.lotes[j + 1] = new tLotes();
						*lista.lotes[j + 1] = *lista.lotes[j];
						ok2 = true;
					}
					*lista.lotes[ind] = lote;
				}
				ind++;
			}
			if (!ok2)
			{
				lista.lotes[lista.cont] = new tLotes();
				*lista.lotes[lista.cont] = lote;
			}
			lista.cont++;
		}
	}

}

void cargar(tListaLotes & lista)
{
	ifstream fich;
	tLotes lote;
	int ind = 0;

	fich.open("lista.txt");
	if (fich.is_open())
	{
		do
		{
			fich >> lote.id;
			fich >> lote.tipo;
			fich >> lote.peso;
			fich >> lote.precio;

			insertar(lista, lote);

		} while (!fich.eof());

	}
	else
	{
		cout << "Archivo no cargado" << endl;
	}

}

bool buscar(const tListaLotes& lista, string id, string tipo, int & pos)
{
	bool encontrado = false;
	int ind = 0;

	while (!encontrado && ind < lista.cont)
	{
		if (id == lista.lotes[ind]->id)
		{
			if (tipo == lista.lotes[ind]->tipo)
			{
				encontrado = true;
				pos = ind;
			}
		}
		ind++;
	}

	return encontrado;
}

tLotes obtenerLote(const tListaLotes& lista, int pos)
{
	return *lista.lotes[pos];
}

void mostrar(const tListaLotes & lista)
{
	for (int i = 0; i < lista.cont; i++)
	{
		mostrarLote(*lista.lotes[i]);
		//mostrarPrecio(*lista.lotes[i]);
		cout << endl;
	}
}

void liberar(tListaLotes & lista)
{
	for (int i = 0; i < lista.cont; i++)
	{
		delete lista.lotes[i];
		lista.lotes[i] = nullptr;
	}
	lista.cont = 0;
}
