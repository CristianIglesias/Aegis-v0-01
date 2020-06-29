#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"
#include "Clientes.h"
#include "Producto.h"
#include "Proveedor.h"


void error_msj(int cod, int i)
{
    switch(cod)
    {
    case -1:
       /// cout<<"Error Nro:"<<error<<" Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -2:
        break;
    case -3:
        break;
    case -4:
        break;
    case -5:
        break;
    case -6:
        break;
    }
}


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

void listarProveedores()
{
    Proveedor prov;
    int i=0;
    cls();
    cout<<"________LISTADO DE PROVEEDORES__________"<<endl;
    cout<<endl;
    while(prov.leerProveedor(i))
    {

        prov.mostrar();
        cout<<endl;
        i++;
    }
    cin.ignore();
    anykey();
}
