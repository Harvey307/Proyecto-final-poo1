#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include "Podructo.h"
#include <string>
using namespace std;
//casteo para no estar cambiado de tipo de variable y a pesar de que todos sean diferentes tipos se datos, puedan todos tener un mismo tipo de dato
using std::stoi;
class ProductoVector
{
private:
//         clase     nombre del vector
	vector<Producto> vectorProducto;

public:
	ProductoVector()
	{
		cargarDatosDelArchivoAlVector();
		vector<Producto> vectorProducto;
	}

	int getCorrelativo()
	{
		if (vectorProducto.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorProducto[vectorProducto.size() - 1].getCodigo() + 1;
		}
	}

	Producto get(int pos)
	{
		//obtiene la posicion requeridad
		return vectorProducto[pos];
	}
	//retorna el tamaño
	int rows()
	{
		//tamaño del arreglo inicia del pos 0
		return vectorProducto.size();
	}

	void agregar(Producto obj)
	{
		//agregas/meter obj al vector
		vectorProducto.push_back(obj);
	}

	bool modificarPrecio(Producto obj, float precio)

	{
		//un bool solo retorna un bool
		//buscas por el for, por ello esta el rows que es la cant
		for (int i = 0; i < rows(); i++)
		{
			//para encontrar el codigo 
			//el get(i) -> i vemndria a ser la poscicion
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorProducto[i].setPrecio(precio);
				//la posicion del precio
				return true;
			}
			//si cambio el false por el true no pasa nada, pero si cambia la condion 
			//en este caso si retorna un true es porque si existe
		} return false;
	}
	//si creas un obj tipo producto va a tener todo lo del producto.h
	Producto buscarPorCodigo(int codigo)
	{
		Producto objError;
		//
		objError.setCodigo(0);

		//se usa si quieres comparar un obj con un vector
		for (Producto x : vectorProducto)
			//el x toma la posicion del vector producto
			// El x es un objeto que toma los valores de los objetos del vector hasta encontrar lo requerido
			//tambien se puede crear obj dentro del for
		{
			if (codigo == x.getCodigo())
			{
				//retorna el valor o los valores
				return x;
			}
		}
		//y si no lo encuentra bota el error
		return objError;
	}

	//retorna la posicion del obj en el vector
	int getPostArray(Producto obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getNombre() == get(i).getNombre())
			{
				return i;
			}
		}
		//si piden que retorne algo y no es lo que pides, tiene que ser algo que puedas validar y este mal 
		return -1;
	}
	//el remove va de la mano con el grabr modificar
	//antes del grabar modificar usas el remove
	//eliminar
	void remove(Producto obj)
	{
		//erase,begin es funcion propia de la libreria vector
		vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));
		//lo de adentro es un parametro y el begin  apunta al primer elemnto y el getposarray es la posiccion obtenidad de la funcion
	}

	void grabarEnArchivo(Producto producto)
	{
		try
		{
			fstream archivoProducto;
			//el nombre del csv puede ser cualquiera
			//el ios::app es parte de varios ios que son metodos de acceso hacia varios archivos
			//el ios::app abre el archivo va a la ultima line correlativamente y agrega al csv
			archivoProducto.open("producto.csv", ios::app);
			//open funcion del fstream que crea el archivo
			if (archivoProducto.is_open())
				//is_open solo abre el archivo
			{
				//lo que va despues del << es lo que guarda en csv
				archivoProducto << producto.getCodigo() << ";" << producto.getNombre() << ";" << producto.getMarca() << ";" << producto.getTipo() << ";" << producto.getSubtipo() << ";" << producto.getPrecio() << ";" << endl;
				archivoProducto.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
		
	}

	void cargarDatosDelArchivoAlVector()
	{
		//es como inicializar 
		//Guarda todo lo del archivo en los vectores cada vez que inicia el programa y asi cada vez que cierras y vuelves a abrir  tenga todo guadado
		try
		{
			int i;
			//el size_t es el tamaño maximo en un obj
			size_t posi;//Cantidad maxima
			//variable que ayuda
			string linea;
			//arreglo de strings llamado temporal 
			//es una arreglo de 6 por la cant de variables
			string temporal[6];//en el archivo se guardan en columnas por ello -> Cantidad de columnas
			//fstream es para llamar un archivo y todo lo que tiene que ver con archivos
			fstream archivoProducto;
			//ios::in permite abrir el archivo sin modificar nada, solo permite visualizar y agarrar datos, no modificar
			archivoProducto.open("producto.csv", ios::in);
			//aca se abre
			if (archivoProducto.is_open())
			{
				//!archivoProducto.eof() es para verificar, leyendo fila por fila del archivo y si hay espacios en blanco salta un error
				while (!archivoProducto.eof())
				{
					//lee la linea inicialisada en 1 por correlativo
					while (getline(archivoProducto, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
							// find es de fstream y su funcion es encontrar
						{
							//corre hasta encontrar el ; y para
							temporal[i] = linea.substr(0, posi);
							//agarra el valor que esta antes del ;
							linea.erase(0, posi + 1);//la pos 0 lo agarra y lo pone el estring y elimina el dato por estar guardado y itera del siguiente que seria la pos 1
							//elimina el valor agarrado y el punto y coma
							i++;
						}
						//Asignando los valores al vector
						// para la busqueda
						//crea el obj producto1
						//claro creo un objeto y llenarlo si cumple, creo el objeto para llenar 
						Producto producto1;
						//setear los valores
						
					
						producto1.setCodigo(std::stoi(temporal[0]));// std::stoi convertir un string en int
						//al temporal 1 vendria la condicionalllll
						producto1.setNombre(temporal[1]);

						producto1.setMarca(temporal[2]);
						producto1.setTipo(temporal[3]);
						producto1.setSubtipo(temporal[4]);
						producto1.setPrecio(std::stof(temporal[5]));
						//vuelve a usar una funcion anterior
						agregar(producto1);
					}
				}
			}
			archivoProducto.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}
	void grabarModificarEliminarArchivo()
		//grabarmodificar mejorado
	{
		try {
			fstream archivoProductos;
			//primero el remove elimina del vector pero no del archivo
			// luego el ios::out lo elimina del archivo
			//el ios::out ;por ejemplo eliminas una linea, 20 por ejemplo, se olvida de la 20 y donde iba la 20 pone la 21
			//sino hay uno coge el siguente en su lugar
			archivoProductos.open("producto.csv", ios::out);
			if (archivoProductos.is_open())
			{
			//en el main ya primero setas y luego viene esto
				//y con el for le da un nuevo valor y lo traslada al archivo
				for (Producto x : vectorProducto)
				{
					archivoProductos << x.getCodigo() << ";" << x.getNombre() << ";" << x.getMarca() << ";" << x.getTipo() << ";" << x.getSubtipo() << ";" << x.getPrecio() << ";" << "\n";
				}
				
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}
};