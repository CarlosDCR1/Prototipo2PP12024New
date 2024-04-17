#include "menuCrud.h"
#include "menuInfo.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;


menuCrud::menuCrud(string id, string nombre, string precio,string nit, string telefono, string direccion, string correo, string status)
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

string menuCrud::setId( string id)
{
    this-> id=id;
}
string menuCrud::getId()
{
    return this -> id;
}

string menuCrud::setNombre(string nombre)
{
    this->nombre=nombre;
}

string menuCrud::getNombre()
{
    return this->nombre;
}

string menuCrud::setPrecio(string precio)
{
    this->precio=precio;
}

string menuCrud::getPrecio()
{
    return this->precio;
}




string menuCrud::setnit(string nit)
{
    this->nit=nit;
}

string menuCrud::getnit()
{
    return this->nit;
}


string menuCrud::settelefono(string telefono)
{
    this->telefono=telefono;
}

string menuCrud::gettelefono()
{
    return this->telefono;
}

string menuCrud::setdireccion(string direccion)
{
    this->direccion=direccion;
}

string menuCrud::getdireccion()
{
    return this->direccion;
}

string menuCrud::setcorreo(string correo)
{
    this->correo=correo;
}

string menuCrud::getcorreo()
{
    return this->correo;
}
string menuCrud::setstatus(string status)
{
    this->status=status;
}

string menuCrud::getstatus()
{
    return this->status;
}






void menuCrud::menuCr()
{
    bool salir = false;
    int opcion;
	do
    {
	system("cls");

    cout <<"\t\t\t---------------------------------------"<<endl;
    cout <<"\t\t\t|            MENU Catalogo            |"<<endl;
    cout <<"\t\t\t|Nombre: Carlos David Calderon Ramirez|"<<endl;
    cout <<"\t\t\t|Carnet: 9959-23-848                  |"<<endl;
    cout <<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Cliente"<<endl;
	cout<<"\t\t\t 2. Borrar Cliente"<<endl;
	cout<<"\t\t\t 3. Modificar Cliente"<<endl;
	cout<<"\t\t\t 4. Desplegar Clientes"<<endl;
	cout<<"\t\t\t 5. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        insertar();
		break;
	case 2:

		borrar();
		system("pause");
        system ("cls");
		break;
    case 3:
        modificar();
		break;
    case 4:
        desplegar();
        system("pause");
        system ("cls");
		break;
	case 5:
	    salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
    }while(opcion!= 5);
}



void menuCrud::desplegar()
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
        cout<<"\t\t\t Nit: "<<nit<<endl<<endl<<endl;
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

void menuCrud::insertar()
{
    system("cls");
    string id,nombre,precio,nit,telefono,direccion,correo,status;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Cliente--------------------------------------------"<<endl;
    cout << "\t\t\t\nIngrese id:         ";
    cin >> id;
      cout << "\t\t\t\nIngrese el nombre :         ";
    cin >> nombre;
      cout << "\t\t\t\nIngrese el apellido:         ";
    cin >> precio;
      cout << "\t\t\t\nIngrese la Nit:         ";
    cin >> nit;
    cout << "\t\t\t\nIngrese la telefono:         ";
    cin >> telefono;
    cout << "\t\t\t\nIngrese la direccion:         ";
    cin >> direccion;
    cout << "\t\t\t\nIngrese correo:         ";
    cin >> correo;
    cout << "\t\t\t\nIngrese Estatus:         ";
    cin >> status;

    // Abre el archivo "" en modo de apendizaje y escritura
    fstream fileIngresar;
    fileIngresar.open("catalogos.txt",ios::app| ios:: out);

    // Escribe en el archivo los datos del usuario ingresados por el usuario
    fileIngresar<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< precio<<std::left <<std::setw(15)<< nit<<std::setw(15)<< telefono<<std::setw(15)<< direccion<<std::setw(15)<< correo<<std::setw(15)<< status<<"\n";

    //cierre del archivo
    fileIngresar.close();
    //mensaje de exito

    cout << "\t\t\t\nregistrado exitosamente."<<endl;


}

void menuCrud::modificar()
{

	system("cls");
    fstream fileOri, fileModif;  // Se crean dos objetos de archivo para leer y escribir en archivos de texto
    string productoModificar;  // Se define una cadena para almacenar el nombre del usuario a modificar

    int contador=0;  // Se define una variable para contar si se encuentra el usuario en el archivo
    cout<<"\n-------------------------Modificacion de cliente-------------------------"<<endl;  // Muestra un mensaje en pantalla
    fileOri.open("catalogos.txt",ios::in);  // Abre el archivo de texto en modo lectura

    if(!fileOri)  // Si el archivo no se pudo abrir
    {
        cout<<"\n\t\t\tNo hay informacion..,";  // Muestra un mensaje en pantalla
        fileOri.close();  // Cierra el archivo
    }
    else  // Si el archivo se pudo abrir
    {
        cout<<"\n Ingrese el nombre del producto que quiere modificar: ";  // Muestra un mensaje en pantalla para ingresar el usuario a modificar
        cin>>productoModificar;  // Lee el nombre del usuario a modificar
        fileModif.open("record2.txt",ios::app | ios::out);  // Abre otro archivo de texto en modo escritura y agrega el contenido al final del archivo
        fileOri >> id>> nombre>>precio>>nit>>telefono>>direccion>>correo>>status;  // Lee el primer usuario y contraseña del archivo

        while(!fileOri.eof())  // Mientras no se llegue al final del archivo
        {
            if(productoModificar!=nombre)  // Si el usuario no es el que se quiere modificar
                {
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< nit<<std::setw(15)<< telefono<<std::setw(15)<< direccion<<std::setw(15)<< correo<<std::setw(15)<< status<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar


                }

            else  // Si se encuentra el usuario a modificar
                {
                cout << "\t\t\t\nIngrese el nuevo id del producto:         ";
                cin >> id;
                cout << "\t\t\t\nIngrese el nuevo nombre del producto:         ";
                cin >> nombre;
                cout << "\t\t\t\nIngrese el apellido:         ";
                cin >> precio;
                cout << "\t\t\t\nIngrese la Nit:         ";
                cin >> nit;
                cout << "\t\t\t\nIngrese la telefono:         ";
                cin >> telefono;
                cout << "\t\t\t\nIngrese la direccion:         ";
                cin >> direccion;
                cout << "\t\t\t\nIngrese correo:         ";
                cin >> correo;
                cout << "\t\t\t\nIngrese Estatus:         ";
                cin >> status;
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< nit<<std::setw(15)<< telefono<<std::setw(15)<< direccion<<std::setw(15)<< correo<<std::setw(15)<< status<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar
                contador++;  // Incrementa el contador de usuarios modificados
                cout << "\t\t\t\Producto Modificado exitosamente.\n";
                }

                    fileOri >> id>> nombre>>precio>>nit>>telefono>>direccion>>correo>>status; // Lee el siguiente usuario y contraseña del archivo
        }

        fileModif.close();  // Cierra el archivo temporal
        fileOri.close();  // Cierra el archivo original

        remove("catalogos.txt");  // Elimina el archivo original
        rename("record2.txt","catalogos.txt");  // Renombra el archivo temporal con el nombre del archivo original
         //cout << "\t\t\t\nUsuario no encontrado.";
          // Muestra un mensaje en pantalla
    }
}

void menuCrud::borrar()
{
   	system("cls");

	// Declarar dos objetos de la clase fstream para manejar los archivos
	fstream file, file1;

	// Declarar una variable para almacenar el nombre del usuario a borrar
	string partcipante;

	// Declarar una variable para indicar si se encontró al usuario a borrar
	int encontrados= 0;

	// Mostrar un mensaje para indicar que se va a borrar un usuario
	cout << "\n-------------------------Cliente a Borrar-------------------------" << endl;

	// Abrir el archivo "Usuarios1.txt" en modo lectura
	file.open("catalogos.txt", ios::in);

	// Verificar si el archivo se pudo abrir
	if (!file)
	{
		cout << "\n\t\t\tNo hay informacion...";

		// Cerrar el archivo
		file.close();
	}
	else
	{
		// Pedir al usuario que ingrese el nombre del usuario a borrar
		cout << "\n Ingrese el nombre del producto que quiere Borrar: ";
		cin >> partcipante;

		// Abrir el archivo "Record.txt
		file1.open("record2.txt", ios::app | ios::out);

		// Leer el nombre de usuario y contraseña del archivo "Usuario y contraseñas.txt"
		file >> id>> nombre>>precio>>nit>>telefono>>direccion>>correo>>status;

		// Mientras no se llegue al final del archivo "Usuarios1.txt"
		while (!file.eof())
		{
			// Verificar si el nombre de usuario leído es diferente al nombre del usuario a borrar
			if (partcipante != nombre)
			{
				// Escribir el nombre de usuario y contraseña en el archivo "Record.txt"
                file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< nit<<std::setw(15)<< telefono<<std::setw(15)<< direccion<<std::setw(15)<< correo<<std::setw(15)<< status<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar
			}
			else
			{
				// Incrementar el contador de usuarios encontrados
				encontrados++;

				// Mostrar un mensaje indicando que se borró al usuario exitosamente
				cout << "\n\t\t\tBorrado de informacion exitoso.\n";
			}

			// Leer el siguiente nombre de usuario y contraseña del archivo "Usuarios1.txt"
                file >> id>> nombre>>precio>>nit>>telefono>>direccion>>correo>>status;

		}

		// Verificar si no se encontró al usuario a borrar
		if (encontrados == 0)
		{
			cout << "\n\t\t\t Nombre del producto no encontrado...";
		}

		// Cerrar los archivos
		file1.close();
		file.close();

		// Borrar el archivo "Usuarios1.txt"
		remove("catalogos.txt");

		// Renombrar el archivo "Record.txt" como "Usuarios1.txt"
		rename("record2.txt", "catalogos.txt");
	}
}
