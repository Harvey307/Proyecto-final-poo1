#pragma once
#include<iostream>
#include<vector>
#include<fstream>       
#include"Personal.h"
using namespace std;
using std::stoi;
class PersonalVector {
private:
	vector<Personal> vectorPersonal;

public:
	PersonalVector() {
		cargarDatosDelArchivoAlVector();
		vector<Personal> vectorPersonal;
	}

	int getCorrelativo()
	{
		if (vectorPersonal.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorPersonal[vectorPersonal.size() - 1].getCodigo() + 1;
		}
	}

	Personal get(int pos)
	{
		return vectorPersonal[pos];
	}

	int rows()
	{
		return vectorPersonal.size();
	}

	void agregar(Personal obj)
	{
		vectorPersonal.push_back(obj);
	}

	void grabarEnArchivo(Personal personal)
	{
		try
		{
			fstream archivoPersonal;
			archivoPersonal.open("personal.csv", ios::app);
			if (archivoPersonal.is_open())
			{
				archivoPersonal << personal.getCodigo() << ";" << personal.getNom() << ";" << endl;
				archivoPersonal.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
	}

	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i;
			size_t posi;//Cantidad maxima
			string linea;
			string temporal[2];//Cantidad de columnas
			fstream archivoPersonal;
			archivoPersonal.open("personal.csv", ios::in);
			if (archivoPersonal.is_open())
			{
				while (!archivoPersonal.eof())
				{
					while (getline(archivoPersonal, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;
						}
						//Asignando los valores al vector
						Personal personal1;
						personal1.setCodigo(std::stoi(temporal[0]));
						personal1.setNom(temporal[1]);

						agregar(personal1);
					}
				}
			}
			archivoPersonal.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}
	void grabarModificarEliminarArchivo()
	{
		try {
			fstream archivoPersonal;
			archivoPersonal.open("personal.csv", ios::out);
			if (archivoPersonal.is_open())
			{
				for (Personal x : vectorPersonal)
				{
					archivoPersonal << x.getCodigo() << ";" << x.getNom() << ";" << "\n";
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}
};
