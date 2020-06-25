#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"
#include "Clientes.h"
#include "Producto.h"



void ListarClientes()///TODO CHEQUEAR QUE FUNCA LEER
{
    Cliente Cli;
    int i=0;
    cls();
    cout<<"Listado De Clientes "<<endl;
    cout<<"--------------------"<<endl;
    while(Cli.LeerDeDisco(i))
    {
        Cli.mostrar();
        cout<<endl;
        i++;
    }
    cin.ignore();
    anykey();
}

void listarProductos()
{
    Producto reg;
    int i=0;
    cls();
    cout<<"________LISTADO DE PRODUCTOS__________"<<endl;
    while(reg.leerProductos(i))
    {
        reg.mostrar();
        cout<<endl;
        i++;
    }
}
