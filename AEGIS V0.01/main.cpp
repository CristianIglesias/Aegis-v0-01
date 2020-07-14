#include <iostream>
#include <conio.h>
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

int main()
{
    int x;
    setlocale(LC_ALL,"spanish");
    for(x=1; x<118; x++)
    {
        gotoxy(x,1);
        cout<<"="<<endl;
    }
    int op=-1;
    while(op!=0)

    {

        setColor(YELLOW);
        cout<<endl;
        cout<<endl;
        cout<<"                                       _______  _______  _______  ___   _______               "<<endl;
        cout<<"                                      |   _   ||       ||       ||   | |       |              "<<endl;
        cout<<"                                      |  |_|  ||    ___||    ___||   | |  _____|              "<<endl;
        cout<<"                                      |       ||   |___ |   | __ |   | | |_____               "<<endl;
        cout<<"                                      |       ||    ___||   ||  ||   | |_____  |              "<<endl;
        cout<<"                                      |   _   ||   |___ |   |_| ||   |  _____| |              "<<endl;
        cout<<"                                      |__| |__||_______||_______||___| |_______|              "<<endl;
        cout<<"                                      ------------------------------------------              "<<endl;
        setColor(LIGHTMAGENTA);
        cout<<"                                       --PROGRAMA DE GESTION DE LOCAL DE ROPA--"<<endl;
        setColor(YELLOW);
        cout<<"                                      -------------------------------------------"<<endl;



        cout<<"                           -->Presione la tecla enter para ingresar al menu de Principal"<<endl;

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
            cout<<"~~~~~COMPRAS~~~~~"<<endl;

        }
        break;

        case 3:
        {
            menuABM();


        }
        break;

        case 4:
        {
            cout<<"~~~~~LISTADOS~~~~~"<<endl;

        }
        break;

        case 5:
        {
            cout<<"~~~~~CONFIGURACION~~~~~"<<endl;
        }
        break;
        case 0:
        {
            cout<<"                                         FIN DE LA SESION, HASTA LUEGO!."<<endl;


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
