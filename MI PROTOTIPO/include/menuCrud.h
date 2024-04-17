#ifndef MENUCRUD_H
#define MENUCRUD_H

#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

class menuCrud
{
     public:
        menuCrud(string id, string nombre, string precio,string nit, string telefono, string direccion, string correo, string status);
        string setId(string id);
        string getId();

        string setNombre(string nombre);
        string getNombre();

        string setPrecio(string precio);
        string getPrecio();



        string setnit(string nit);
        string getnit();

        string settelefono(string telefono);
        string gettelefono();

        string setdireccion(string direccion);
        string getdireccion();

        string setcorreo(string correo);
        string getcorreo();

        string setstatus(string status);
        string getstatus();
//metodos

    void menuCr();
    void insertar();
    void desplegar();
    void modificar();
    void buscar();
    void borrar();

    protected:

    private:
    string id,nombre,precio,nit,telefono,direccion,correo,status;
};

#endif // MENUCRUD_H
