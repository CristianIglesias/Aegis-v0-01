#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <clocale>
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"
#include "Clientes.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Menus.h"

///fuck

///probando una cosa

int main()
{
    setlocale(LC_ALL,"spanish");
    int op=-1;
    while(op!=0)

    {
        system("cls");
        cout<<"                            *********                        "<<endl;
        cout<<"                             *AEGIS*                         "<<endl;
        cout<<"                            *********                        "<<endl;
        cout<<"-->Presione la tecla enter para ingresar al menu de Principal"<<endl;
        cin.get();
        cls();
        menuPrincipal();

        cin>>op;
        cin.ignore();
        cls();
        switch(op)
        {

        case 1:
        {
            menuVentas();
        }
        break;

        case 2:
        {
            menuABM();
        }
        break;

        case 3:
        {
            cout<<"~~~~~LISTADOS~~~~~"<<endl;

        }
        break;

        case 4:
        {
            cout<<"~~~~~COMPRAS~~~~~"<<endl;
        }
        break;

        case 5:
        {
            cout<<"~~~~~CONFIGURACION~~~~~"<<endl;
        }
        break;
        case 0:
        {
            cout<<"  SESION FINALIZADA."<<endl;


        }
        break;

        default:
        {
            cout<<"OPCION NO VALIDA, POR FAVOR INGRESE UNA OPCION DEL MENU."<<endl;
        }



        }///Termina el switch
        cin.get();
    }///Termina el while

    return 0;
}///Termina el Main
