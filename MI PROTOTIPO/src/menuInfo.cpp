#include "menuCrud.h"
#include "menuInfo.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;


menuInfo::menuInfo(string id, string nombre, string precio,string nit, string telefono, string direccion, string correo, string status)
{
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->nit = nit;
    this->telefono = telefono;
    this->direccion = direccion;
    this->correo = correo;
    this->status = status;
}
void menuInfo::Mostrar()
{
   system("cls");
int total=0;

//imprimir encabezado
cout<<"\n-------------------------Tabla de Registrados-------------------------"<<endl;
fstream fileDesplegar;
fileDesplegar.open("catalogos.txt",ios::in);
//condicion si el archivo no se puede abrir
if(!fileDesplegar)
    {
    cout<<"\n\t\t\tNo hay información..."; // muestra un mensaje de error
		fileDesplegar.close(); // cierra el archivo
    }
else
    {
        fileDesplegar >> id>> nombre>>precio>>nit>>telefono>>direccion>>correo>>status;//lee el primer registro del archivo
        //condicion de seguir leyendo registrso hasta llegar al final del registro
        while(!fileDesplegar.eof())
        {
         total++;//contado de usuarios
         cout<<"\t\t\t ID "<<id<<endl; // muestra el nombre del usuario
         cout<<"\t\t\t NOMBRE: "<<nombre<<endl;
         cout<<"\t\t\t Apellido: "<<precio<<endl;
        cout<<"\t\t\t NIt: "<<nit<<endl<<endl<<endl;
        cout<<"\t\t\t Telefono: "<<telefono<<endl<<endl<<endl;
        cout<<"\t\t\t Direccion: "<<direccion<<endl<<endl<<endl;
        cout<<"\t\t\t Correo: "<<correo<<endl<<endl<<endl;
        cout<<"\t\t\t Estatus: "<<status<<endl<<endl<<endl;
        fileDesplegar >> id>> nombre>>precio>>nit>>telefono>>direccion>>correo>>status;//leera el siguiente registro del archivo
        }

        if(total==0)//si no llegara a encontrar ningun registro en el archivo
        {
            cout<<"\n\t\t\tNo hay informacion..."; // muestra un mensaje de error
        }
    }
    fileDesplegar.close();
}


