#pragma once
#ifndef USUARIOS
#define USUARIOS
using namespace std;
#include <iostream>

class usuarios
{
private:
	string Numero_Telefono;
	int Saldo;


public:
	usuarios() {
		Numero_Telefono = "";
		this->Saldo = 0; 
	 }

	 usuarios(string a, int b);
	 void visualizar();
	 void recarga(usuarios * a);
	 void transferir(usuarios *a, usuarios *b);
	 void llamadaT(usuarios *a);
	 string retornarNumero();
};



#endif // !USUARIOS


