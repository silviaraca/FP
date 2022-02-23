#include "listaCompradores.h"


int main()
{
	tListaLotes listaL;
	tListaCompradores listaC;
	long long int id;
	int ind = 0, aux = 0;
	float precio;
	bool encontrado = false;
	string nombre;

	inicializar(listaL);
	cargar(listaL);
	for (int i = 0; i < listaL.cont; i++)
	{
		cout << "El siguiente lote a subastar es: " << endl;
		mostrarLote(*listaL.lotes[i]);
		cout << "Introducir id del comprador: ";
		cin >> id;
		cout << endl << "Introduce nombre del comprador: ";
		cin >> nombre;
		cout << endl << "Introduce el precio de compra: ";
		cin >> precio;
		while (ind < listaC.cont && !encontrado)
		{
			if (id == listaC.compradores[ind].num)
			{
				encontrado = true;
				aux = ind;
			}
		}
		insertar(listaC, listaC.compradores[aux], precio);
		modificarLote(*listaL.lotes[i], nombre, precio);
	} 

	
	liberar(listaC);
	liberar(listaL);
	system("pause");
	return 0;
}