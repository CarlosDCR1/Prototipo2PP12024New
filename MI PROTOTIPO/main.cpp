#include <iostream>
#include<fstream>
#include <usuario.h>
#include<menuG.h>
#include "menuInfo.h"
#include "menuCrud.h"
using namespace std;

int main()
{
    using namespace std;
    //variables de user y contraseñan
    string user,contrasena;
    //llmamos al objeto e ingresamos los parametros
    usuario ingreso(user,contrasena);

    string id,nombre,precio,cantidad;
    menuG acceso(id,nombre,precio,cantidad);

    //creamos un bool  que verifique y despliegue el metodo verificarUsuario
    bool UsuarioCorrecto=ingreso.VerificarUsuario();


    //luego de ingresar con usuario y contraseña se nos desplega otro menu
    if(UsuarioCorrecto)
    {
        	system("cls");
            acceso.menuPrincipal();
    }
    return 0;
}
