#include "menuG.h"
#include "menuCrud.h"
#include "menuInfo.h"
#include "usuario.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

    string id,nombre,precio,nit,telefono,direccion,correo,status;
    menuCrud acceso2(id,nombre,precio,nit,telefono,direccion,correo,status);

    menuInfo acceso3(id,nombre,precio,nit,telefono,direccion,correo,status);

    string user,contrasena;
    usuario acceso4(user,contrasena);

menuG::menuG(string id, string nombre, string precio, string cantidad)
{
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

string menuG::setId( string id)
{
    this-> id=id;
}
string menuG::getId()
{
    return this -> id;
}

string menuG::setNombre(string nombre)
{
    this->nombre=nombre;
}

string menuG::getNombre()
{
    return this->nombre;
}

string menuG::setPrecio(string precio)
{
    this->precio=precio;
}

string menuG::getPrecio()
{
    return this->precio;
}

string menuG::setCantidad(string cantidad)
{
    this->cantidad=cantidad;
}

string menuG::getCantidad()
{
    return this->cantidad;
}

void menuG::menuPrincipal()
{
        bool salir = false;
    int opcion;
	do
    {
	system("cls");

    cout <<"\t\t\t---------------------------------------"<<endl;
    cout <<"\t\t\t|            MENU GENERAL             |"<<endl;
    cout <<"\t\t\t|Nombre: Carlos David Calderon Ramirez|"<<endl;
    cout <<"\t\t\t|          Carne: 9959-23-848         |"<<endl;
    cout <<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t 1. Menu Usuarios"<<endl;
	cout<<"\t\t\t 2. Catalogos"<<endl;
	cout<<"\t\t\t 3. Informes"<<endl;
	cout<<"\t\t\t 4. Salir del Sistema"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        acceso4.MenuUser();
		break;
    case 2:
        acceso2.menuCr();
		break;
	case 3:
        acceso3.Mostrar();
		system("pause");
        system ("cls");
		break;
	case 4:
	    salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
    }while(opcion!= 4);
}



