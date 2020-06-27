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
int ValidarTexto(const char *cad)
{
    int tam,i=0;
    bool flag=true;
    tam=strlen(cad);
    if(cad[i]=='\0')
    {
        return -1;
    }

    for (i=1; i<tam; i++)
    {
        if(cad[i-1]<=97&&cad[i-1]>=122||cad[i-1]<=65&&cad[i-1]>=90)
        {
            flag=false;
        }

    }
    if(flag)
        return 0;
    };

void listarProductos()
{
    Producto reg;
    int i=0;
    cls();
    cout<<"________LISTADO DE PRODUCTOS__________"<<endl;
    cout<<endl;
    while(reg.leerProductos(i))
    {
        reg.mostrar();
        cout<<endl;
        i++;
    }
    cin.ignore();
    anykey();
}
