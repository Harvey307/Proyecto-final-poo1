#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Personal {
private:
	int codigo;
	string nomPer;
public:
	Personal()
	{

	}
	Personal(int cod, string nper)
	{
		this->codigo = cod;
		this->nomPer = nper;
	}

	void setCodigo(int Codigo)
	{
		codigo = Codigo;
	}
	void setNom(string nper) {
		nomPer = nper;
	}

	int getCodigo()
	{
		return codigo;
	}
	string getNom() {
		return nomPer;
	}
};