#include "lotes.h"

void mostrarLote(const tLotes& lote)
{
	cout << "Lote: " << setw(20) << left << lote.id << "Peso del lote: " << setw(55) << left << lote.peso << endl;
	cout << "Tipo: " << setw(20) << left << lote.tipo << "Precio de salida: " << setw(55) << left << lote.precio << endl;
}

void mostrarPrecio(const tLotes& lote)
{
	cout << "Lote: " << setw(20) << lote.id << "Comprador: " << lote.comprador << endl;
	cout << "Tipo: " << setw(20) << lote.tipo << "Precio de compra " << lote.precio << endl;
}

void modificarLote(tLotes& lote, string id, float precio)
{
	lote.id = id;
	lote.precio = precio;
}

bool operator<(const tLotes& lote1, const tLotes& lote2)
{
	bool menor = false;
	if (lote1.tipo < lote2.tipo)
	{
		menor = true;
	}
	else if(lote1.tipo == lote2.tipo)
	{
		if (lote1.id < lote2.id)
		{
			menor = true;
		}
	}
	return menor;
}

bool operator==(const tLotes& lote1, const tLotes& lote2)
{
	return lote1.id == lote2.id;
}