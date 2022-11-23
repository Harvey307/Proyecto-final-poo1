#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<stdlib.h>
#include <conio.h>
#include"ClienteVector.h"
#include"ProductoVector.h"
#include"VendedorVector.h"
#include"FacturaDetalleVector.h"
#include"FacturaVector.h"
#include"PersonalVector.h"
#include"AdminVector.h"
#include<windows.h>
#include<string.h>
//se crean obj de los vectores para el main
VendedorVector vendedorVector;
ClienteVector clienteVector;
ProductoVector productoVector;
FacturaDetalleVector facturadetalleVector;
FacturaVector facturaVector;
PersonalVector personalvector;
AdmiVector adminvector;

using namespace std;

//RECORDAR getch(); es un system("pause") pero no pone presiona algo para continuar


//aca se declara el usr para el main como global 
string usr;

void InterfazPrincipal();
void Interfaz1();
void Interfaz2(string &usr);
void Interfaz3();
void Interfaz4();
void Interfaz5();
void SistemaGeneral();
void SistemaProducto();
void SistemaVentas();
void SistemaCliente();
void ModificarProductos();
void Sistema2(string usr);
void Sistema3();
void Sistema4();
void Sistema5();
void Sistema6();
void Busqueda_tipo();
void busqueda1();
void busqueda2();
void busqueda3();
void busqueda4();
void busqueda5();
void Cliente1();
void Cliente2();
void Cliente3();
void Cliente4();
void Ventas1();
void Ventas3();
void ModificarEstado();
void Ordenamiento_Precio();
void recuadro(int xs, int ys, int xi, int yi);
void gotoxy(int x, int y);
void Busquedapaventa();
void busqueda11();
void busqueda22();
void busqueda33();
void busqueda44();
void busqueda55();


int main() 
{
	//lo normal es col= 120 lines 30
	system("mode con: cols=120 lines=25");
	//       xs,ys,xi,yi 
	//recuadro (42,1,67,3);
	system("color 70");
	InterfazPrincipal();
}
void gotoxy(int x, int y)
{
	HANDLE Manipulator;
	COORD Coordenadas;
	Manipulator = GetStdHandle(STD_OUTPUT_HANDLE);
	Coordenadas.X = x;
	Coordenadas.Y = y;
	SetConsoleCursorPosition(Manipulator, Coordenadas);
}

void InterfazPrincipal()
{
	int opc;
	//en el gotoxy el (x,y) , x= columnas y y=filas
	gotoxy(50, 2);cout << "VENTA MAS" << endl;
	recuadro(42, 1, 67, 3);//cuadro de bievenido
	recuadro(40, 4, 71, 13);//cuadro del menu
	
	gotoxy(43, 6);cout << " [1] Login" << endl;
	//gotoxy(43, 7);cout << " [2] Cliente" << endl;
	gotoxy(43, 7);cout << " [2] Salir" << endl;
	gotoxy(43, 8);cout << " \n";
	gotoxy(43, 9);cout << " Ingrese una opcion(1-3): "; cin >> opc;
	

	switch (opc)
	{
	case 1: system("cls"); Interfaz1();
	
	
	case 2: system("cls"); 
		gotoxy(50, 8);cout << endl << "******Gracias por su visita******" << endl;
		break;
	}
}
/*void centrarTexto(char texto, int y)
{

	int longitud = strlen(texto); 
	gotoxy(120 - (longitud / 2), y);
	cout<<texto;
}*/

void recuadro(int xs, int ys, int xi, int yi)
{
	int i;
	for (i = xs; i <= xi; i++)
	{
		gotoxy(i, ys); cout << "\304";
		gotoxy(i, yi); cout << "\304";
	}
	for (i = ys; i <= yi; i++)
	{
		gotoxy(xs, i); cout << "\263";
		gotoxy(xi, i); cout << "\263";
	}
	gotoxy(xs, ys); printf("%c", 218);
	gotoxy(xi, yi); printf("%c", 217);
	gotoxy(xi, ys); printf("%c", 191);
	gotoxy(xs, yi); printf("%c", 192);



	
}
void Interfaz1()
{
	int opcion = 0;
	recuadro(42, 1, 67, 3);
	gotoxy(36, 2); cout << " 		BIENVENIDO			" << endl;
	
	recuadro(36, 4, 75, 13);//cuadro para lo de abajo
	gotoxy(39, 5);cout << "[1]  Ingresar a la plataforma" << endl;
	gotoxy(39, 6);cout << "[2]  Agregar un nuevo usuario" << endl;
	gotoxy(39, 7);cout << "[3]  Eliminar un usuario existente" << endl;
	gotoxy(39, 8);cout << "[4]  Listar los usuarios" << endl;
	gotoxy(39, 9);cout << "[5]  Salir" << endl;
	gotoxy(39, 10);cout << endl;
	gotoxy(39, 11);cout << "Ingrese una de las opciones: ";
	cin >> opcion;
	
	
	switch (opcion) {
	case 1:system("cls"); Interfaz2(usr);
		break;
	case 2:system("cls"); Interfaz3();
		break;
	case 3:system("cls"); Interfaz4();
		break;
	case 4:system("cls"); Interfaz5();
	case 5:system("cls"); InterfazPrincipal();
		break;
	}
}

//INICIO DEL SISTEMA 
void Interfaz2(string &usr)
{   
	//entrar al sistema y poner ususario y contraseña

	string user;
	string password;
	recuadro(43, 1, 63, 3);//cuadro de bievenido
	//recuadro(40, 4, 71, 13);//cuadro menu
	recuadro(33, 4, 77, 13);//cuadro menu
	gotoxy(38,2);cout << " 		BIENVENIDO			" << endl;
	gotoxy(43, 5); cout << endl;
	gotoxy(43, 6);cout << "Ingrese su usuario: ";cin >> user;
	gotoxy(43, 7); cout << endl;
	gotoxy(43, 8);cout << "Ingrese su clave: ";
	//encriptacion
	char caracter;
	caracter = _getch();
	password = "";
	//encripacion 
	while (caracter != 13) // Enter en ASCII
	{
		if (caracter != 8) // Backspace en ASCII
		{
			password.push_back(caracter);
			cout << "*";
		}
		else {
			if (password.length() > 0) {
				cout << "\b \b";
				password.pop_back(); // Borra el Ãºltimo caracter
			}

		}
		caracter = _getch();
	}
	//busca por codigo del usuario
	Vendedor vende = vendedorVector.buscarPorUsuario(user);
	//si la contraseña coincide
	if (password == vende.getcontrasena())
	{
		cout << " " << endl;
		//ACAAAA BARRA DE PROGRESO
		system("cls");
		 gotoxy(39, 7); cout << "Bienvenido a esta plataforma!" << endl;
		//aca se igualan el global y user declarado en la funcion
		usr = user;
		//problema
		_getch();
		system("cls");
		//primera forma de barra de progreso
		//for (int i = 1; i < 20; i++)
	// {

			gotoxy(39, 8); cout << "Ingresando al sistema general" << endl;

        //segunda forma de barra de progreso
		/*	gotoxy(39, 9); cout << "-----------------------------------------" << endl;

			for (int j = 0; j < i; j++)
			{  
			gotoxy(39, 10);cout << "X"; 
			//gotoxy(39, 11); cout << "----------------------------------------" << endl;
			//Sleep(35);
			}
			_getch();
			//gotoxy(39, 11); cout << "---------------------------------------" << endl;
			system("cls");
		}
		//barra de progreso con caracteres
		/*for (int i = 3; i <= 76; i++)
		{
			//solo falta encontrar el ascii para la barra de progreso
			gotoxy(36, 10); cout<<".";
		}
		for (int i = 3; i <=76; i++) 
		{

			gotoxy(36, 10); cout<<"x"; 
			
			//Sleep(20);
		}*/
		
	
		gotoxy(39, 9);system("pause");
		system("cls");
		
		SistemaGeneral();
		// tipo de vendedor


		
		
	}
	else//sino
	{
		gotoxy(36, 8);cout << "El usuario y/o password no son correctos" << endl;
		gotoxy(36, 9); _getch();
		system("cls");
		Interfaz2(usr);
		//Interfaz1();
	}
}
//CLASES Y CREAR UN USUARIO Y CONTRASEÑA
void Interfaz3()
{
	//declaraciones de variable

    string user;
	int cod;
	string password;
	//agregamos lo que pidio el profe tipo de persona
	//tipo de persona
	int opc;
	gotoxy(43,5 ); cout << "Ingrese el tipo de personal:"<<endl;
	gotoxy(43,6); cout << "[1] Personal"<<endl;
	gotoxy(43,7); cout << "[2] Administrador" << endl;
	gotoxy(43,8); cout << "Ingrese un tipo de personal: ";
	cin >> opc;
	//AVANCE FINAL para que guarde el personal y el administrador en el csv
	if (opc == 1)
	{
		_getch();
		int cod;
		string nper;
		cod = personalvector.getCorrelativo();
		gotoxy(43, 9); cout << "Codigo:" << cod << endl;
		cin.ignore();
		gotoxy(43, 10); cout << "Nombres y Apellidos (los mismo que se pondran en el usuario): ";
		getline(cin, nper);
		cin.ignore();
		//se guarda en personal
		Personal objAlu(cod, nper); // Se creo el objeto de tipo alumno /
		personalvector.agregar(objAlu);

		personalvector.grabarEnArchivo(objAlu); // grabar en el archivo /
		
	}
	else if (opc == 2)
	{
		_getch();
		int cod;
		string nper;
		cod = adminvector.GetCorrelativo();
		gotoxy(43, 9); cout << "Codigo:" << cod << endl;
		cin.ignore();
		gotoxy(43, 10); cout << "Nombres y Apellidos: ";
		getline(cin, nper);
		cin.ignore();
		//se guarda en administrador
		//se crea un objeto del vector Admi para guardar 
		Admi objAlu(cod, nper); // Se creo el objeto de tipo alumno /
		adminvector.Agregar(objAlu);

		adminvector.GrabarEnArchivo(objAlu); // grabar en el archivo /
		
	}
	_getch();
	system("cls");
	//CREACION DE UN NUEVO USUARIO
	gotoxy(43, 5); cout << "Creacion de un nuevo usuario" << endl;
	//cod es el correlativo
	cod = vendedorVector.getCorrelativo();
	gotoxy(43, 6); cout << " CODIGO ID --> " << cod << endl;

	gotoxy(43, 7); cout << "Ingresa tu nombre de usuario: ";
	cin >> user;
	gotoxy(43, 8); cout << endl;

	gotoxy(43, 9); cout << "Ingresa una clave(numeros y letras): ";
	cin.ignore();
	//el buffer lo reseta la consola
	//getline(cin, password);

	char caracter;
	caracter = _getch();
	password = "";
	//encripacion y guardado
	while (caracter != 13) // Enter en ASCII
	{
		if (caracter != 8) // Backspace en ASCII
		{
			//para llenar datos
			password.push_back(caracter);
			cout << "*";

		}
		else {
			if (password.length() > 0) {
				cout << "\b \b";
				password.pop_back(); // Borra el Ãºltimo caracter
			}

		}
		caracter = _getch();
			
	}
	//aca se van al archivo y se convierte en privado y se puede usar
	Vendedor vendedor1;
	vendedor1.setcodigo(cod);
	vendedor1.setusuario(user);
	vendedor1.setcontra(password);

	vendedorVector.agregar(vendedor1);
	vendedorVector.grabarEnArchivo(vendedor1);

	system("cls");
	Interfaz1();
}
//ELIMINAR USUARIO
void Interfaz4()
{
	//Aca se elimina usuario
	string user;
	string rpta;
	cout << "Elija el ususario a eliminar:"<<endl;
	for (int i = 0; i < vendedorVector.rows(); i++)
	{
		cout << vendedorVector.get(i).getcodigo() << "-" << vendedorVector.get(i).getusuario() << "-" << vendedorVector.get(i).getcontrasena() << "\n";
	}

	//cout << "			Eliminar usuario		" << endl;
	cout << " Nombre del usuario a eliminar: ";
	cin >> user;
	//ACA EL (usaer) no puede ser string?
	//aca cramos un objeto en el vector
	Vendedor objeliminar = vendedorVector.buscarPorUsuario(user);
	//aca elimine el != 0, por user
	if (objeliminar.getusuario() == user )
	{
		vendedorVector.remove(objeliminar);
		vendedorVector.grabarModificarEliminarArchivo();
		cout << "¡Registro Eliminado Satisfactoriamente!" << endl;
	}
	else
	{
		cout << " No se encontro el registro!\n" << endl;
	}
	system("pause");
	system("cls");
	Interfaz1();
}

void Interfaz5()
{
	for (int i = 0; i < vendedorVector.rows(); i++)
	{
		cout << vendedorVector.get(i).getcodigo() << "-" << vendedorVector.get(i).getusuario() << "-" << vendedorVector.get(i).getcontrasena() << "\n";
	}
	system("pause");
	system("cls");
	Interfaz1();
}
//sistema general
void SistemaGeneral()
{
	int opc;
	recuadro(43, 1, 63, 3);//cuadro de bievenido
	recuadro(40, 4, 71, 13);//cuadro menu
	gotoxy(44, 2); cout << "   SISTEMA GENERAL" << endl;
	gotoxy(43, 5); cout << "[1]  Productos" << endl;
	gotoxy(43, 6); cout << "[2]  Ventas" << endl;
	gotoxy(43, 7); cout << "[3]  Clientes" << endl;
	gotoxy(43, 8); cout << "[4]  Salir" << endl;
	gotoxy(43, 9); cout << " \n";
	gotoxy(43, 11); cout << " Ingrese una opcion: ";
	cin >> opc;
	switch (opc) {
	case 1:system("cls"); SistemaProducto(); break;
	case 2:system("cls"); SistemaVentas(); break;
	case 3:system("cls"); SistemaCliente(); break;
	case 4:system("cls"); InterfazPrincipal(); break;
	}
}
void SistemaProducto() {
	int opc;
	recuadro(43, 1, 68, 3);//cuadro de bievenido
	recuadro(40, 4, 76, 13);//cuadro menu
	gotoxy(44, 2); cout << "   SISTEMA DE PRODUCTOS" << endl;
	gotoxy(43, 5); cout << " [1] Ingresar un nuevo producto" << endl;
	gotoxy(43, 6); cout << " [2] Modificar producto" << endl;
	gotoxy(43, 7); cout << " [3] Eliminar producto" << endl;
	gotoxy(43, 8); cout << " [4] Buscar producto" << endl;
	gotoxy(43, 9); cout << " [5] Listar productos" << endl;
	gotoxy(43, 10); cout << " [6] Salir" << endl;
	gotoxy(43, 11); cout << " \n";
	gotoxy(43, 12); cout << " Ingrese una opcion: ";	cin >> opc;

	switch (opc) {
	case 1:system("cls"); Sistema3(); break;
	case 2:system("cls"); ModificarProductos(); break;
	case 3:system("cls"); Sistema4(); break;
	case 4:system("cls"); Sistema5(); break;//cambie el busqueda tipo(); por esto para mejorar
	case 5:system("cls"); Sistema6(); break;
	case 6:system("cls"); SistemaGeneral(); break;
	}
}

void SistemaVentas() {
	int opciones;
	recuadro(45, 1, 68, 3);//cuadro de bievenido
	recuadro(40, 4, 81, 13);//cuadro menu
	gotoxy(48, 2); cout << "SISTEMA DE VENTAS" << endl;
	gotoxy(43, 5); cout << "[1]  Realizar una venta " << endl;
	gotoxy(43, 6); cout << "[2]  Buscar factura/boleta por codigo" << endl;
	gotoxy(43, 7); cout << "[3]  Modificar estado de venta" << endl;
	gotoxy(43, 8); cout << "[4]  Listar facturas/boletas emitadas" << endl;
	gotoxy(43, 9); cout << "[5]  Salir" << endl;
	gotoxy(43, 10); cout << "Ingrese una opcion: ";
	cin >> opciones;
	switch (opciones) {
	case 1:system("cls"); Sistema2(usr); break;
	case 2:system("cls"); Ventas1(); break;
	case 3:system("cls"); ModificarEstado(); break;
	case 4:system("cls"); Ventas3(); break;
	case 5:system("cls"); SistemaGeneral(); break;
	}
}

void ModificarProductos()
{
	cout << "		MODIFICAR PRECIO - PRODUCTO" << endl;
	int cod;
	cout << "Elije producto a eliminar:"<<endl;
	for (int i = 0; i < productoVector.rows(); i++)
	{
		cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << "\n";
	}
	cout << "Ingresar el codigo del producto a modificar:";
	cin >> cod;
	cout << " " << endl;

	Producto objAModificar = productoVector.buscarPorCodigo(cod);
	system("cls");
	system("pause");
	cout << "Registro Encontrado\n";
	cout << "Codigo: " << objAModificar.getCodigo() << endl;
	cout << "Nombre: " << objAModificar.getNombre() << endl;
	cout << "Marca: " << objAModificar.getMarca() << endl;
	cout << "Tipo: " << objAModificar.getTipo() << endl;
	cout << "SubTipo: " << objAModificar.getSubtipo() << endl;
	cout << "Precio: S/." << objAModificar.getPrecio() << endl;
	cin.ignore();
	cout << " " << endl;
	system("pause");
	system("cls");
	float preModificado;
	cout << "    MODIFICAR CAMPOS" << endl;
	cout << "Precio a modificar: S/.";
	cin >> preModificado;

	bool estado = productoVector.modificarPrecio(objAModificar, preModificado);
	if (estado = true)
	{
		cout << "Registro Modificado Correctamente\n";
		productoVector.grabarModificarEliminarArchivo();
		cout << " " << endl;
		system("cls");
		SistemaProducto();
	}
	else {
		cout << "No se Edito el registro!\n";
		system("pause");
		SistemaProducto();
	}
}

void Sistema2(string usr) {
	int cod,cant, codvendedor;
	float precio, acumulador = 0, igv, subtotal, total;//original aca tambien el igva pero solo
	float igva = 0.18;
	int codc;
	string nomp,nompro;
	string rpta, fecha;
	string estado = "completado";
	string tipodeventa;
	string tip;

	int codfactura = facturadetalleVector.getCorrelativo();
	//CORRECCIONNNNN

	gotoxy(46, 2); cout << "VENTA" << endl;

	gotoxy(43, 5); cout << "FECHA:";
	; cin >> fecha;cout << endl;
	//ingresamos el usuario por teclado
	gotoxy(43, 6); cout << "Usuario_Cajero: " << usr << endl << endl;
	//internamente se busca el vendedor
     Vendedor vendedor1 = vendedorVector.buscarPorUsuario(usr);
	codvendedor = vendedor1.getcodigo();
	/*para usar */
	gotoxy(43, 7); cout << "Ingrese Nombre_Cliente: ";
	//change
	cin >> nomp; cout << endl;
	//OBJETO CREADO PARA LLAMAR A BUSQUEDA NOMAPE QUE ESTA VENDEDOR VECTOR

	ClienteVector cliente0;
	
	 cliente0.busqueda_nomape(nomp);//BUSCA LAS COINCIDENCIA Y LAS IMPRIME
	
	 cout << "                                           " << endl;
                                 cout << "                                           " << "Ingrese el codigo del cliente requerido:";//DESPUES DE VER LAS COINCIDENCIAS ELIJES CUAL QUIERES
		cin >> codc;
		cout << "                                           " << endl;
		system("cls");
		Cliente clienteOficial = cliente0.buscarPorCodigo(codc);// se ccrea un obj para que reciba el cliente0
		if (clienteOficial.getcodigo() == 0) {
			gotoxy(43, 5); cout << "Codigo invalido" << endl;
			cout << "                                           " << system("pause");
			system("cls");
			Sistema2(usr);
		}
		//imprime el cliente que se busco cuando se elijio el codigo de las cioncidencias
		else 
		{
			gotoxy(43, 5); cout << "Datos del cliente elejido:" << endl;
			gotoxy(43, 6); cout << "codigo:"<<clienteOficial.getcodigo() << "-"<<"Nombre:"<< clienteOficial.getnomape() << "-"<<"DNI:" << clienteOficial.getdni() << endl;
			_getch();
		}
		gotoxy(43, 7); cout << endl;
		gotoxy(43, 8); cout << "Ingrese tipo de venta ( factura/boleta):";
		cin >> tip;
		if (tip == "factura" || tip=="Factura"|| tip==  "FACTURA") 
		{
			tipodeventa = "factura";
		}
		else {
			tipodeventa = "boleta";
		}
		gotoxy(43, 9); cout << endl;
		gotoxy(43, 10); cout << "El IGV de la Venta es : "<<igva<<endl;//muestra el igv que se usara
	_getch();
	//cin >> igva; cout << endl;
	system("cls");

	gotoxy(43, 7); cout << "Codigo_Factura: " << codfactura << endl << endl;
	_getch();

	do {
		
		//HACER LO MISMO QUE EN CLIENTE
		/*cout << " CATEGORIAS DE PRODUCTO : " << endl;
	cout << "[1]   electro" << endl;
	cout << "[2]   perecibles" << endl;
	cout << "[3]   bebidas" << endl;
	cout << "[4]   vestimenta" << endl;
	cout << "[5]   otros" << endl;
	cout << "Ingrese la categoria:";*/
		
		Busquedapaventa();
		system("cls");
		cout << endl;
			 //BUSQUEDA POR TIPO DE PRODUCTO
		/* {
			int opcion;
			cout << "	Busqueda por tipo de productos" << endl;
			cout << "[1]   electro" << endl;
			cout << "[2]   perecibles" << endl;
			cout << "[3]   bebidas" << endl;
			cout << "[4]   vestimenta" << endl;
			cout << "[5]   otros" << endl;
			cout << "[6]   salir" << endl;
			cout << "Ingrese una opcion valida (1-5): ";
			cin >> opcion;

			//SEGUN EL SWITCH ELIGE UN NUMERO 
			switch (opcion)
			{
			case 1:system("cls"); busqueda1(); break;
			case 2:system("cls"); busqueda2(); break;
			case 3:system("cls"); busqueda3(); break;
			case 4:system("cls"); busqueda4(); break;
			case 5:system("cls"); busqueda5(); break;
			case 6:system("cls"); InterfazPrincipal(); break;
			}

		}*/
		cout << "                                           "<< "Codigo_Producto: ";
		cin >> cod; 
		cout << "                                           "<< endl;



		Producto producto1 = productoVector.buscarPorCodigo(cod);
		//FacturaDetalle facturadetalle1;
		if (producto1.getCodigo() == cod) {

			precio = producto1.getPrecio();

			cout << "                                           "<< "Nombre	  Marca	   Tipo	  Precio Unitario" << endl;
			cout << "                                           " << producto1.getNombre() << "   " << producto1.getMarca() << "   " << producto1.getTipo() << "      " << producto1.getPrecio() << endl << endl;
			//cout << "Precio_Producto:" << precio << endl << endl;//

			cout << "                                           " << "Cantidad(unidades): ";
			cin >> cant; 
			cout << "                                           " << endl;

			//cout << "SubTotal:" << precio * cant << endl << endl;

			acumulador += precio * cant;
			//un if()
			//si guardar y no no guardar
			FacturaDetalle facturadetalle1;//llena el vector 
			//Entonces en facturadetalle "el vector", ya tendra llenado todo
			facturadetalle1.setcodFactura(codfactura);
			facturadetalle1.setcodProducto(cod);
			facturadetalle1.setcantidad(cant);
			facturadetalle1.setprecioVenta(precio);
			facturadetalle1.setimporte(precio * cant);

			facturadetalleVector.agregar(facturadetalle1);
			//facturadetalleVector.grabarEnArchivo(facturadetalle1);

			cout << "                                           " << "Seguir comprando (si o no):";
			cin >> rpta;
			cout << "                                           " << endl;
		}
		else {
			cout << "                                           " << "No se encontro registro del producto" << endl;
			cout << "                                           " << "Seguir comprando (si o no):";
			cin >> rpta;
			cout << "                                           " << endl;
		}
	} while (rpta == "si");

	igv = (igva / 100) * acumulador;//original: igv = (igva / 100) * acumulador;
	subtotal = acumulador - igv;
	total = acumulador;

	Factura factura1;
	factura1.setcodigo(codfactura);
	factura1.setfecha(fecha);
	factura1.setsubtotal(subtotal);
	factura1.setigvfactura(igva);
	factura1.setigv(igv);
	factura1.settotal(total);
	factura1.setestado(estado);
	//sigue con lo de busqueda
	//factura1.setnomp(nomp);//se guarda el nombre
	factura1.setcodCliente(clienteOficial.getcodigo());
	factura1.setcodVendedor(codvendedor);
	factura1.settipoVenta(tipodeventa);

	facturaVector.agregar(factura1);
	//facturaVector.grabarEnArchivo(factura1);

	_getch();
	system("cls");

	cout << "    DETALLES DE LA VENTA" << endl << endl;

	cout << "Productos adquiridos: " << endl;

	for (int i = 0; i < facturadetalleVector.rows(); i++) {

		if (facturadetalleVector.get(i).getcodFactura() == codfactura) {

			int codpr = facturadetalleVector.get(i).getcodProducto();
			//
			Producto prodt = productoVector.buscarPorCodigo(codpr);
			
			cout << "El producto es: " << prodt.getNombre() << endl;
			cout << "La cantidad adquirida es:" << facturadetalleVector.get(i).getcantidad() << endl;
			cout << "El precio unitario del producto es: " << facturadetalleVector.get(i).getprecioVenta() << endl;
			cout << "El subtotal por este producto es: " << facturadetalleVector.get(i).getimporte() << endl;
			cout << endl;
		}
		else {
		}

	}

	cout << "SubTotal: " << factura1.getsubtotal() << endl;
	cout << "IGV: " << factura1.getigv() << endl;
	cout << "Total_Pagar: " << factura1.gettotal() << endl;
	cout << endl;
	system("cls");
	int op;
	cout << " Opciones de venta:" << endl;
	cout << "[1] Elimnar venta" << endl;
	cout << "[2] Eliminar producto" <<endl;
	cout << "[3] guardar la venta" << endl;
	cin >> op;
	switch (op)
	{
	case 1: system("cls"); SistemaVentas(); break;
	case 2:int codigo;
		cout << "Ingrese el codigo del producto:";
		cin >> codigo;

		facturadetalleVector.remove(facturadetalleVector.buscarPorCod(codigo));//eliminar producto por codigo

		cout << "    DETALLES DE LA VENTA" << endl << endl;

		cout << "Productos adquiridos: " << endl;

		for (int i = 0; i < facturadetalleVector.rows(); i++) //recorre el tamaño del arreglo
		{

			if (facturadetalleVector.get(i).getcodFactura() == codfactura)// si solo si el codigo de la factura es el correcto
			{

				int codpr = facturadetalleVector.get(i).getcodProducto();
				//
				Producto prodt = productoVector.buscarPorCodigo(codpr);

				cout << "El producto es: " << prodt.getNombre() << endl;
				cout << "La cantidad adquirida es:" << facturadetalleVector.get(i).getcantidad() << endl;
				cout << "El precio unitario del producto es: " << facturadetalleVector.get(i).getprecioVenta() << endl;
				cout << "El subtotal por este producto es: " << facturadetalleVector.get(i).getimporte() << endl;
				cout << endl;
			}
			else {
			}

		}
        
	case 3: facturaVector.grabarEnArchivo(factura1);
		//
		for (FacturaDetalle x : facturadetalleVector.vectorfacdet())
		{
			facturadetalleVector.grabarEnArchivo(x);
		}
		 break;
	}
	

	system("pause");
	system("cls");
	SistemaVentas();
}

void Busquedapaventa()//BUSQUEDA POR TIPO DE PRODUCTO
{
	int opcion;
	cout << "                                           " << "CATEGORIA DE PRODUCTOS" << endl;
	cout << "                                           " << "[1]   electro" << endl;
	cout << "                                           " << "[2]   perecibles" << endl;
	cout << "                                           " << "[3]   bebidas" << endl;
	cout << "                                           " << "[4]   vestimenta" << endl;
	cout << "                                           " << "[5]   otros" << endl;
	cout << "                                           " << "[6]   seguir con la venta:" << endl;
	cout << "                                           " << "Ingrese una opcion de la categoria a revisar (1-5): ";
	cin >> opcion;

	//SEGUN EL SWITCH ELIGE UN NUMERO 
	switch (opcion)
	{
	case 1:system("cls"); busqueda11();  break;
	case 2: system("cls"); busqueda22();  break;
	case 3: system("cls"); busqueda33();  break;
	case 4: system("cls"); busqueda44(); break;
	case 5: system("cls"); busqueda55(); break;
	case 7: system("cls"); break;
	}

}
void busqueda11()//SI ELIJES ELECTTRO COMPARA Y BOTA TODOS LOS DE ELECTRO
{
	for (int i = 0; i < productoVector.rows(); i++)
		//getline(cin.tipo)
	{
		if (productoVector.get(i).getTipo() == "electro")
		{
			cout << "                                           " << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	_getch();
	//system("cls");
	Busquedapaventa();
}

void busqueda22()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "perecibles")
		{
			cout << "                                           " << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	_getch();
	//system("cls");
	Busquedapaventa();
}

void busqueda33()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "bebidas")
		{
			cout << "                                           " << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	_getch();
	//system("cls");
	Busquedapaventa();
}

void busqueda44()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "vestimenta")
		{
			cout << "                                           " << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	_getch();
	//system("cls");
	Busquedapaventa();
}

void busqueda55()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "otros")
		{
			cout << "                                           " << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	_getch();
	//system("cls");
	Busquedapaventa();
}
void Ventas1() //buscar factura boleta
{
	int cod;
	//hacer la misma busqueda que se hiso con cliente
	cout << "    BUSCAR FACTURA/BOLETA" << endl;
	cout << "Ingresar codigo de la factura/boleta: ";
	cin >> cod; cout << endl;

	Factura facturav = facturaVector.buscarPorCodigo(cod);

	if (facturav.getcodigo() == cod) {

		cout << "    DETALLES DE LA VENTA" << endl;
		cout << "Codigo de Factura/Boleta:     " << facturav.getcodigo() << endl;
		cout << "PRODUCTOS ADQUIRIDOS:" << endl;

		for (int i = 0; i < facturadetalleVector.rows(); i++) {
			if (facturadetalleVector.get(i).getcodFactura() == cod) {

				int codpr = facturadetalleVector.get(i).getcodProducto();

				Producto prodt = productoVector.buscarPorCodigo(codpr);

				cout << endl << "El producto es: " << prodt.getNombre() << endl;
				cout << "La cantidad adquirida es:" << facturadetalleVector.get(i).getcantidad() << endl;
				cout << "El precio unitario del producto es: " << facturadetalleVector.get(i).getprecioVenta() << endl;
				cout << "El subtotal por este producto es: " << facturadetalleVector.get(i).getimporte() << endl;
				cout << endl;
			}
			else {
			}
		}

		cout << endl << "Codigo_Vendedor:              " << facturav.getcodVendedor() << endl;
		cout << "Codigo_Cliente:               " << facturav.getcodCliente() << endl;
		//cout << "Nombre_Cliente:				   " << clienteVector.buscarPorCodigo(facturav.getcodCliente()).getnomape() << endl;
		cout << "Fecha_Venta:                  " << facturav.getfecha() << endl;
		cout << "Tipo de venta:                " << facturav.gettipoVenta() << endl;
		cout << "Estado de venta:              " << facturav.getestado() << endl;
		cout << "IGV Factura(porcentaje):      " << facturav.getigvFactura() << endl << endl;
		cout << "Subtotal:                     " << facturav.getsubtotal() << endl;
		cout << "IGV Venta:                    " << facturav.getigv() << endl;
		cout << "Total a pagar:                " << facturav.gettotal() << endl;
	}
	else {
		cout << "No tenemos registrada una factura/boleta con el codigo ingresado" << endl;
	}
	system("pause");
	system("cls");
	SistemaVentas();
}

void ModificarEstado()//COMPLETO O IMCOMPLETO
{
	cout << "			MODIFICAR ESTADO " << endl;
	int cod;
	cout << "Codigo de Factura a modificar:";
	cin >> cod;
	cout << " " << endl;

	Factura objFacAModificar = facturaVector.buscarPorCodigo(cod);

	cout << "Factura encontrada\n";
	cout << "Codigo_Factura: " << objFacAModificar.getcodigo() << endl;
	cout << "Fecha: " << objFacAModificar.getfecha() << endl;
	cout << "SubTotal: " << objFacAModificar.getsubtotal() << endl;
	cout << "IGV_Factura: " << objFacAModificar.getigvFactura() << endl;
	cout << "IGV: " << objFacAModificar.getigv() << endl;
	cout << "Total_Pagar: " << objFacAModificar.gettotal() << endl;
	cout << "Estado: " << objFacAModificar.getestado() << endl;
	cout << "Codigo_Cliente: " << objFacAModificar.getcodCliente() << endl;
	cout << "Codigo_Vendedor: " << objFacAModificar.getcodVendedor() << endl;
	cout << "Tipo_Comprobante: " << objFacAModificar.gettipoVenta() << endl;

	cin.ignore();
	cout << " " << endl;

	string estadoModificado;
	cout << "     MODIFICAR ESTADO DE FACTURA" << endl;
	cout << "Estado: "; getline(cin, estadoModificado);

	bool estado = facturaVector.modificarEstado(objFacAModificar, estadoModificado);

	if (estado = true)
	{
		cout << "Registro Modificado Correctamente\n";
		facturaVector.grabarModificarEliminarArchivo();
		system("pause");
		system("cls");
		SistemaVentas();
	}
}


void Ventas3() {//LISTAR FACTURAS
	cout << "    FACTURAS/BOLETAS EMITIDAS" << endl;
	for (int i = 0; i < facturaVector.rows(); i++) {
		cout << "Codigo de la factura/boleta:	" << facturaVector.get(i).getcodigo() << endl;
		cout << "Codigo del vendedor:		" << facturaVector.get(i).getcodVendedor() << endl;
		//el get se va donde el getcodcliente y saca que i osea la posciion requeridad
		cout << "Codigo del cliente:		" << facturaVector.get(i).getcodCliente() << endl;
		//cliente vector es para usar los metodos del archivo cliente vector
		cout << "Nombre_Cliente:		    " << clienteVector.buscarPorCodigo(facturaVector.get(i).getcodCliente()).getnomape() << endl;
		cout << "Fecha de la venta:		" << facturaVector.get(i).getfecha() << endl;
		cout << "Tipo de venta:			" << facturaVector.get(i).gettipoVenta() << endl;
		cout << "Estado de la venta:	        " << facturaVector.get(i).getestado() << endl;
		cout << "Igv(%) cobrado en esta venta:   " << facturaVector.get(i).getigvFactura() << endl << endl;
		cout << "Subtotal de la venta:	        " << facturaVector.get(i).getsubtotal() << endl;
		cout << "Igv de la venta:		" << facturaVector.get(i).getigv() << endl;
		cout << "Total de la venta:		" << facturaVector.get(i).gettotal() << endl << endl;

		cout << "*************************************************" << endl << endl;
	}
	system("pause");
	system("cls");
	SistemaVentas();
}

void Sistema3() {//AGREGAR PRODUCTO
	int cod;
	string nombre, marca, tipo, subtipo;
	float price;

	cod = productoVector.getCorrelativo();
	cout << "			AGREGAR PRODUCTO" << endl;
	cout << "Codigo: " << cod << endl;
	cin.ignore();
	cout << "Nombre del producto: ";
	//cin.ignore();
	getline(cin, nombre);

	cout << "Marca del producto: ";
	//cin.ignore();
	getline(cin, marca);
	int opc;
	cout << " CATEGORIAS DE PRODUCTO : " << endl;
	cout << "[1]   electro" << endl;
	cout << "[2]   perecibles" << endl;
	cout << "[3]   bebidas" << endl;
	cout << "[4]   vestimenta" << endl;
	cout << "[5]   otros" << endl;
	cout << "Ingrese la categoria:";

	cin >> opc;
	switch (opc)
	{
	case 1: tipo = "electro"; cin.ignore(); break;
	case 2: tipo = "precibles"; cin.ignore(); break;
	case 3: tipo = "bebidas"; cin.ignore(); break;
	case 4: tipo = "vestimenta"; cin.ignore(); break;
	case 5: tipo = "otros"; cin.ignore(); break;
	
	}
	//guardado
	//cin.ignore();
	//getline(cin, tipo);
	//categorias de productos

	cout << "Subtipo del producto: ";
	//cin.ignore();
	getline(cin, subtipo);

	cout << "Precio del producto: ";
	cin >> price;
	cout << endl;

	Producto producto1;
	producto1.setCodigo(cod);
	producto1.setNombre(nombre);
	producto1.setMarca(marca);
	producto1.setTipo(tipo);
	producto1.setSubtipo(subtipo);
	producto1.setPrecio(price);

	//aca todos los obj de producto 1 se van para agregar
	productoVector.agregar(producto1);
	//y aca lo mismo solo que para grabar archivo
	productoVector.grabarEnArchivo(producto1);

	system("cls");

	SistemaGeneral();
}

void Sistema4()//ELIMINAR PRODUCTO
{
	int cod;
	cout << "Elija el producto a eliminar:" << endl;
	for (int i = 0; i < productoVector.rows(); i++)
	{
		cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << "\n";
	}

	cout << "Codigo de producto a eliminar:";
	cin >> cod;
	Producto objAEliminar = productoVector.buscarPorCodigo(cod);
	if (objAEliminar.getCodigo() != 0)
	{
		productoVector.remove(objAEliminar);
		productoVector.grabarModificarEliminarArchivo();
		cout << "Registro Eliminado Satisfactoriamente" << endl;

	}
	else {
		cout << "El codigo del producto ingresado no existe." << endl;
	}
	system("pause");
	system("cls");
	SistemaProducto();
}

void Sistema5() {//BUSCAR PRODUCTO POR CODIGO

	int code = 0;

	cout << "			BUSCAR POR CODIGO" << endl;
	cout << "Codigo: ";
	cin >> code;
	cout << endl;

	Producto objproducto = productoVector.buscarPorCodigo(code);

	if (code == objproducto.getCodigo()) {
		cout << "Nombre: " << objproducto.getNombre() << endl;
		cout << "Marca: " << objproducto.getMarca() << endl;
		cout << "Tipo: " << objproducto.getTipo() << endl;
		cout << "Subtipo: " << objproducto.getSubtipo() << endl;
		cout << "Precio: S/." << objproducto.getPrecio() << endl;
		system("pause");
		system("cls");
		SistemaProducto();
	}
	else {
		cout << "No existe un producto con el codigo ingresado" << endl;
		system("pause");
		system("cls");
		SistemaProducto();
	}
}
//listar productos
void Sistema6()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << "\n";
	}
	system("pause");
	system("cls");
	SistemaProducto();
}
//problema

//CLIENTEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

void Busqueda_tipo()//BUSQUEDA POR TIPO DE PRODUCTO
{
	int opcion;
	cout << "			Busqueda por tipo de productos" << endl;
	cout << "[1]   electro" << endl;
	cout << "[2]   perecibles" << endl;
	cout << "[3]   bebidas" << endl;
	cout << "[4]   vestimenta" << endl;
	cout << "[5]   otros" << endl;
	cout << "[6]   salir" << endl;
	cout << "Ingrese una opcion valida (1-5): ";
	cin >> opcion;

	//SEGUN EL SWITCH ELIGE UN NUMERO 
	switch (opcion)
	{
	case 1:system("cls"); busqueda1(); break;
	case 2:system("cls"); busqueda2(); break;
	case 3:system("cls"); busqueda3(); break;
	case 4:system("cls"); busqueda4(); break;
	case 5:system("cls"); busqueda5(); break;
	case 6:system("cls"); SistemaProducto(); break;//a sistema producto
	}

}
//modificamos avance
void busqueda1()//SI ELIJES ELECTTRO COMPARA Y BOTA TODOS LOS DE ELECTRO
{
	for (int i = 0; i < productoVector.rows(); i++)
		//getline(cin.tipo)
	{
		if (productoVector.get(i).getTipo() == "electro")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void busqueda2()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "perecibles")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void busqueda3()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "bebidas")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void busqueda4()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "vestimenta")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void busqueda5()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "otros")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}
//SISTEMA CLIENTEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

void SistemaCliente()//INTERFAZ CLIENTE
{
	int opt;
	recuadro(44, 1, 66, 3);//cuadro de bievenido
	recuadro(40, 4, 73, 13);//cuadro menu
	gotoxy(46, 2); cout << "SISTEMA DE CLIENTE" << endl;
	gotoxy(43, 5); cout << "[1]  Buscar cliente" << endl;
	gotoxy(43, 6); cout << "[2]  Crear un nuevo cliente" << endl;
	gotoxy(43, 7); cout << "[3]  Eliminar cliente" << endl;
	gotoxy(43, 8); cout << "[4]  Listar clientes" << endl;
	gotoxy(43, 9); cout << "[5]  Salir" << endl;
	gotoxy(43, 10); cout << "Ingrese la opcion que desee: ";
	cin >> opt;

	switch (opt)
	{
	case 1:system("cls"); Cliente1(); break;
	case 2:system("cls"); Cliente2(); break;
	case 3:system("cls"); Cliente3(); break;
	case 4:system("cls"); Cliente4(); break;
	case 5:system("cls"); SistemaGeneral(); break;
	}
}

void Cliente1()//BUSCA CLIENTE 
{
	int cod = 0;
	cout << "    Buscar Cliente" << endl;
	cout << "Ingrese el codigo del cliente: ";
	cin >> cod;
	cout << endl;

	Cliente clientes1 = clienteVector.buscarPorCodigo(cod);

	if (clientes1.getcodigo() == cod)
	{
		cout << "Codigo: " << clientes1.getcodigo() << endl;
		cout << "Nombre y apellidos: " << clientes1.getnomape() << endl;
		cout << "Dni: " << clientes1.getdni() << endl;
		cout << "Ruc: " << clientes1.getruc() << endl;
		cout << "Direccion: " << clientes1.getdirec() << endl;

		system("pause");
		system("cls");
		SistemaCliente();
	}
	else
	{
		cout << "No se encontro un cliente registrado con el codigo ingresado" << endl;
		system("pause");
		system("cls");
		SistemaCliente();
	}

}

void Cliente2()//NUEVO CLIENTE
{
	int cod, ni, ru;
	string rp, nape, dir;

	Cliente cliente1;

	cout << "			Creacion de un nuevo cliente			" << endl;

	cod = clienteVector.getCorrelativo();

	cout << "El codigo del cliente es: " << cod << endl << endl;

	cout << "Nombres del cliente: ";
	cin.ignore();
	getline(cin, nape);
	cout << endl;
	//cout << "Apellido del cliente: ";
	//getline(cin, ap);
	cout << endl;


	cout << "Ingrese que documento ingresara DNI o RUC: ";
	cin >> rp;
	cout << endl;

	if (rp == "DNI") {
		cout << "Ingrese el numero de DNI: ";
		cin >> ni;
		cout << endl;
		cliente1.setdni(ni);
		cliente1.setruc(00000000000);
	}
	else if (rp == "RUC") {
		cout << "Ingrese el RUC: ";
		cin >> ru;
		cout << endl;
		cliente1.setruc(ru);
		cliente1.setdni(00000000);
	}
	else {
		cout << "Ingresar una opcion valida (DNI o RUC)." << endl;
		system("pause");
		system("cls");
		SistemaCliente();
	}

	cliente1.setcodigo(cod);
	cliente1.setnomape(nape);
	//cliente1.setape(ap);

	cout << "Ingrese su direccion: ";
	cin.ignore();
	getline(cin, dir);
	cliente1.setdirec(dir);

	clienteVector.agregar(cliente1);
	clienteVector.grabarEnArchivo(cliente1);

	system("pause");
	system("cls");
	SistemaCliente();
}

void Cliente3()//ELIMINA CLIENTE
{
	int cod;

	cout << "    Eliminar cliente" << endl;
	cout << "Ingresar codigo del cliente: ";
	cin >> cod;
	cout << endl;

	Cliente objeliminar = clienteVector.buscarPorCodigo(cod);

	if (objeliminar.getcodigo() != 0)
	{
		clienteVector.remove(objeliminar);
		clienteVector.grabarModificarEliminarArchivo();
		cout << "Registro Eliminado Satisfactoriamente!" << endl;
		system("pause");
		system("cls");
		SistemaCliente();
	}
	else
	{
		cout << " No se encontro el registro!" << endl;
		system("pause");
		system("cls");
		SistemaCliente();
	}
}

void Cliente4()//LISTA CLIENTE
{
	for (int i = 0; i < clienteVector.rows(); i++)
	{
		cout << clienteVector.get(i).getcodigo() << "-" << clienteVector.get(i).getnomape() << "-" << clienteVector.get(i).getdni() << "-" << clienteVector.get(i).getruc() << "-" << clienteVector.get(i).getdirec() << endl;
	}
	system("pause");
	system("cls");
	SistemaCliente();
}

void Ordenamiento_Precio()
{
	int p, j;
	float aux;
	float m, n;
	for (p = 1; p < productoVector.rows(); p++)
	{
		aux = productoVector.get(p).getPrecio();
		j = p - 1;

		while ((j >= 0) && (aux < productoVector.get(j).getPrecio())) {
			m = productoVector.get(j + 1).getPrecio();
			n = productoVector.get(j).getPrecio();
			m = n;
			j--;
		}
		m = aux;
	}
}
