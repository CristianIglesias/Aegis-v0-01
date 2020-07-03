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


void error_msj(int cod, int i)/// A COMPLETAR, CADA UNO AGREGA ERRORES QUE NECESITE, SOLO SER�A AGREGAR CASES AL SWITCH.
/// ES UTIL PARA SIMPLIFICAR EL C�DIGO.
{
    switch(cod)
    {
    case -1:
        cout<<"Error Nro:"<<cod<<" Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -2:
        cout<<"Error Validando, Fecha Invalida. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -3:
        cout<<"Error Validando, . Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -4:
        cout<<"Error Validando, . Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -5:
        cout<<"Error Validando, ID INEXISTENTE. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -6:
        cout<<"Error Validando, . Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    }
}


void ListarClientes()
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
    if(cad[0]=='\0')
    {
        return -1;
    }
    if(cad[0]=='0')
    {
        return 1;
    }
    for (i=1; i<tam; i++)
    {:
        if(cad[i-1]<='a'||cad[i-1]>='z'||cad[i-1]<='A'||cad[i-1]>='Z')///TODO REPLANTEAR EL IF.
        {
            flag=false;
            return -1;
        }

    }
    if(flag)
        return 0;
    else return -1;
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
