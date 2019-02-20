#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include "usuarios.h"
#include <fstream>
#include "usuarios.cpp"


using namespace std;


int main(int argc, char const *argv[])
{
	ofstream fichero; 
	//mkdir("Log");
	char opcion;
	int n1tem = -1,n2tem = -1;
	string Ntem = "834", b;
	string enviatem, transtema, llamadatem;

	std::vector<usuarios> usuario;
	

	do{
	cout << "1-Crear Un Nuevo Usuario." << endl;
	cout << "2-Transferir." << endl;
	cout << "3-Hacer Una Llamada." << endl;
	cout << "4-Visualizar." << endl;
	cout << "5-Hacer Una Recarga." << endl;
	cout << "6-Salir." << endl;
		do
		{
			cout << "\n   Introduzca opci%cn (1-6): " << endl;
			cin >> &opcion;

		} while (opcion < '1' || opcion > '6');

		switch (opcion)
		{
		case '1':
			for (int i = 0; i < 7; i++)
			{
				b = std::to_string(rand() % 9);
				Ntem +=  b;
			}
			fichero.open(Ntem+".txt", ios::app);
			cout << "Nuevo Numero De Telefono:" << Ntem << " $100 Pesos De Saldo De Binvenida."<<endl;
			fichero << "Nuevo Numero De Telefono:" << Ntem << " $100 Pesos De Saldo De Binvenida." << endl;
			usuario.push_back(usuarios(Ntem, 100));
			fichero.close();
			Ntem = "834";
			break;

		case '2': 
			cout << "Numeros Existentes:" << usuario.size()<< endl;
			if(usuario.size() > 1){
			do
			{
				cout << "Ingrese El Numero Del Que Quiere Transferir" << endl;
				cin >> enviatem;
				cout << "Numero Ingresado: " << enviatem << endl;
				for (int i = 0; i <= usuario.size(); ++i) {
					if(i < usuario.size()){
					if (usuario.at(i).retornarNumero() == enviatem) {
						cout << "Numero Encontrado" << endl;
						n1tem = i;
					}
					}
					if (i == usuario.size() && n1tem == -1) {
						cout << "El numero No Existe" << endl;
					}
				}
			} while (n1tem == -1);
			do
			{
			cout << "Ingrese El Numero Al Que Quiere Transferir" << endl;
			cin >> transtema;
			cout << "Numero Ingresado: " << transtema << endl;
			for (int i = 0; i < usuario.size(); i++) {
				if (i < usuario.size()) {
					if (usuario.at(i).retornarNumero() == transtema) {
						cout << "Numero Encontrado" << endl;
						n2tem = i;
					}
				}
				if (i == usuario.size() && n2tem == -1) {
					cout << "El numero No Existe" << endl;
				}
			}
			} while (n2tem < -1);
			if(n1tem != -1 && n2tem != -1){
				cout << "Transferencia En Proceso....." << endl;
			usuario.at(n1tem).transferir(&usuario.at(n1tem),&usuario.at(n2tem));
			n1tem = -1;
			n2tem = -1;
			transtema = "";
			enviatem = "";
			}
			}
			else if (usuario.size() == 0) {
				cout << "No Existen Usuarios" << endl;
			}
			else {
				cout << "Solo Existe Un Usuario" << endl;
			}
			break;

		case '3':
			cout << "Numeros Existentes:" << usuario.size() << endl;
			if (usuario.size() > 0) {
				do
				{
					cout << "Ingrese El Numero Del Que Quiere Hacer La Llamada" << endl;
					cin >> llamadatem;
					for (int i = 0; i <= usuario.size(); ++i) {
						if (i < usuario.size()) {
							if (usuario.at(i).retornarNumero() == llamadatem) {
								cout << "Numero Encontrado" << endl;
								n1tem = i;
							}
						}
						if (i == usuario.size() && n1tem == -1) {
							cout << "El numero No Existe" << endl;
						}
					}
				} while (n1tem == -1);
				usuario.at(n1tem).llamadaT(&usuario.at(n1tem));
				n1tem = -1;
				llamadatem = "";
			}
			else {
				cout << "No Existen Usuarios" << endl;
			}
			break;

		case '4':
			if(usuario.size() > 0){
			cout << "Usuarios Existentens.." << endl;
			for (int i = 0; i < usuario.size(); i++)
			{
				cout << i+1 << " ";
				usuario.at(i).visualizar();
			}
			}
			else {
				cout << "No Existen Usuarios" << endl;
			}
			break;
		case '5':
			if (usuario.size() > 0) {
				do
				{
					cout << "Ingrese El Numero AL Que Desea Hacer La Recarga" << endl;
					cin >> llamadatem;
					for (int i = 0; i <= usuario.size(); ++i) {
						if (i < usuario.size()) {
							if (usuario.at(i).retornarNumero() == llamadatem) {
								cout << "Numero Encontrado" << endl;
								n1tem = i;
							}
						}
						if (i == usuario.size() && n1tem == -1) {
							cout << "El numero No Existe" << endl;
						}
					}
				} while (n1tem == -1);
				usuario.at(n1tem).recarga(&usuario.at(n1tem));
				n1tem = -1;
				llamadatem = "";
			}
			else {
				cout << "No Existen Usuarios" << endl;
			}
			break;
		}


	} while (opcion != '6');
	

		
	system("PAUSE");
	//getch();
	return 0;
}