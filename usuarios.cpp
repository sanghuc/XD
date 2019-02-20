#include "usuarios.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


 usuarios::usuarios(string a, int b)
{
	Numero_Telefono = a;
	Saldo = b;
	
}

void usuarios::visualizar()
{
	cout << "Numero De Telefono: " << Numero_Telefono << " Su Saldo Es:$" << Saldo << endl;
}

void usuarios::recarga(usuarios *a) {
	int tem = -1;
	do{
	cout << "Cuanto Quiere Recargar" << endl;
	cin >> tem;
	if (tem == 0) {
		cout << "Ingrese Cuanto Desea Recargar Mayor De $0 PESOS" << endl;
	}
	} while (tem == -1);

	if (tem > 0) {
		a->Saldo += tem;
		cout << "Tu Nuevo Saldo Es De:" << a->Saldo << endl << endl;
			
	}

}

void usuarios::transferir(usuarios *a, usuarios *b) {
	int temtrans;
	ofstream fichero;
	if (a->Saldo > 0) {

		
		fichero.open(a->Numero_Telefono + ".txt", ios::app);
		cout << "Tiene saldo!! Si Puede transferir" << endl;
		fichero << "Tiene saldo!! Si Puede transferir" << endl;
		cout << "Cuanto Quiere Transferir" << endl;
		fichero  << "Cuanto Quiere Transferir" << endl;
		cin >> temtrans;
		if (temtrans > a->Saldo) {
			cout << "No Tiene Esa Cantidad De Saldo Para Transferir: Su Saldo Es De:$" << b->Saldo << endl;
			fichero << "No Tiene Esa Cantidad De Saldo Para Transferir: Su Saldo Es De:$" << b->Saldo << endl;
		}
		else {
			b->Saldo += temtrans;
			a->Saldo -= temtrans;
			cout << "Transferencia Completada!!" << "Su Saldo Restante Es De:$" << a->Saldo << endl;
			fichero << "Transferencia Completada!!" << "Su Saldo Restante Es De:$" << a->Saldo << endl;
		}
	}
	else {
		cout << "No tiene saldo!!" << endl;
		fichero << "No tiene saldo!!" << endl;
		
	}
	fichero.close();
}

void usuarios::llamadaT(usuarios *a) {
	ofstream fichero;
	string numerotem;
	if (a->Saldo > 0) {
		fichero.open( a->Numero_Telefono + "REGISTRO_LLAMADAS" +".txt", ios::app);
		cout << "Digite El Numero A Marcar" << endl;
		cin >> numerotem;
		fichero << "LLAMO A:" << numerotem  << endl;
		system("CLS");
		cout << "Llamada En Proceso!............................................" << endl;
		a->Saldo -= 1;
		cout << "FIN!! De La Llamada." << endl;
		cout << "Su Saldo Restante Es De:" << a->Saldo << endl << endl << endl;
		fichero << "Su Saldo Restante Es De:" << a->Saldo << endl ;
		fichero.close();
	}
}

string usuarios::retornarNumero()
{
	return Numero_Telefono;
}

