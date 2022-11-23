#include <iostream>
using namespace std;
class Admi
{
private:
	int codigo;
	string nomApe;

public:
	Admi()
	{

	}
	Admi(int cod, string nom)
	{
		this->codigo = cod;
		this->nomApe = nom;
	}
	void setCod(int cod)
	{
		this->codigo = cod;
	}
	void setNom(string nom)
	{
		this->nomApe = nom;
	}
	//get
	int getCod()
	{
		return codigo;
	}
	string getNomApe()
	{
		return nomApe;
	}
};
