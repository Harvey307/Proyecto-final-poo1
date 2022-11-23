#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Cliente {
private:
	int codigo;
	string nomape;
	//string ape;
	int dni;
	int ruc;
	string direccion;
	string razon_social;

public:
	Cliente() {
	}
	/*void setape(string ap)
	{
		ape = ap;
	}*/
	void setcodigo(int cod)
	{
		codigo = cod;
	}
	void setnomape(string nape) {
		nomape = nape;
	}
	void setdni(int ni) {
		dni = ni;
	}
	void setruc(int ruuc) {
		ruc = ruuc;
	}
	void setdirec(string direc) {
		direccion = direc;
	}
	/*string getape()
	{
		return ape;
	}*/
	int getcodigo()
	{
		return codigo;
	}
	string getnomape() {
		return nomape;
	}
	int getdni() {
		return dni;
	}
	int getruc() {
		return ruc;
	}
	string getdirec() {
		return direccion;
	}


};