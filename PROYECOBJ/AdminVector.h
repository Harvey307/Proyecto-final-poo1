#include <iostream>
#include <fstream>
#include <vector>
#include"Admin.h"
#include <string>
using namespace std;
class AdmiVector
{
private:
	vector<Admi> vectorAdmi;
public:
	~AdmiVector() {

	}
	AdmiVector()
	{
		CargarDatosDelArchivoAlVector();
	}
	void Agregar(Admi obj)
	{
		vectorAdmi.push_back(obj);
	}
	Admi Obtener(int pos)
	{
		return vectorAdmi[pos];
	}
	int Size()
	{
		return vectorAdmi.size();
	}
	//Correlativo del numero
	int GetCorrelativo()
	{
		if (Size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorAdmi[Size() - 1].getCod() + 1;
		}
	}


	void GrabarEnArchivo(Admi obj)
	{
		try
		{
			fstream archivoAdmi;
			archivoAdmi.open("Adminitradores.csv", ios::app);
			if (archivoAdmi.is_open())
			{
				archivoAdmi << obj.getNomApe() << endl;
				archivoAdmi.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo :) ";
		}
	}
	void GrabarModificarEnArchivo()
	{
		try
		{
			fstream archivoAdmi;
			archivoAdmi.open("Administradores.csv", ios::out);
			if (archivoAdmi.is_open())
			{
				for (Admi x : vectorAdmi)
				{
					archivoAdmi << x.getNomApe() << endl;
				}
				archivoAdmi.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo :( ";
		}
	}

	int GetPosicion(Admi obj)
	{
		for (int i = 0; i < vectorAdmi.size(); i++) {
			if (obj.getNomApe() == vectorAdmi[i].getNomApe()) {
				return i;
			}
		}
		return -1;
	}

	void Eliminar(Admi obj)
	{
		vectorAdmi.erase(vectorAdmi.begin() + GetPosicion(obj));

	}
	void CargarDatosDelArchivoAlVector()
	{

		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[1];
			fstream	archivoAdmi;
			archivoAdmi.open("Adminitradores.csv", ios::in);
			if (archivoAdmi.is_open())
			{
				while (!archivoAdmi.eof())
				{
					while (getline(archivoAdmi, linea))
					{
						i = 0;

						while ((posi = linea.find(";")) != string::npos)
						{

							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;
						}
						Admi Admin1;
						Admin1.setCod(std::stoi(temporal[0]));
						Admin1.setNom(temporal[1]);

						Agregar(Admin1);
					}
				}
			}
			archivoAdmi.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo :o ";
		}
	}
};
