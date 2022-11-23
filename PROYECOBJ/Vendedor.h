#pragma once
#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Vendedor
{
private:
	int codigo;
	string usuario;
	string contrasena;

public:
	Vendedor() {

	}

	void setcodigo(int cod) {
		codigo = cod;
	}
	void setusuario(string user) {
		usuario = user;
	}
	void setcontra(string password) {
		contrasena = password;
	}

	int getcodigo() {
		return codigo;
	}
	string getusuario() {
		return usuario;
	}
	string getcontrasena() {
		return contrasena;
	}
};