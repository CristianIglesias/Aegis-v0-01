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
        cout<<"Error Validando, Este Campo SOLO permite Letras, Intente Nuevamente."<<endl;
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
<<<<<<< HEAD
        cout<<"Error Validando, . Codigo existente."<<endl;
        cout<<"Intente nuevamente :"<<endl;
=======
        cout<<"Error Validando, /// . Intente Nuevamente."<<endl;
>>>>>>> 8d316c1ec657b628d2f88a088f615e85bf19bb38
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podas y queras salir, ingresa ""000""."<<endl;
        }
        break;
    case -4:
<<<<<<< HEAD
        cout<<"Error Validando, .Codigo de Proveedor no existente."<<endl;
         cout<<"Intente nuevamente :"<<endl;
=======
        cout<<"Error Validando,///. Intente Nuevamente."<<endl;
>>>>>>> 8d316c1ec657b628d2f88a088f615e85bf19bb38
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podas y queras salir, ingresa ""000""."<<endl;
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
<<<<<<< HEAD
        cout<<"Error Validando, .No puede ser menor ni igual a 0. Intente Nuevamente."<<endl;
=======
        cout<<"Error Validando,///. Intente Nuevamente."<<endl;
>>>>>>> 8d316c1ec657b628d2f88a088f615e85bf19bb38
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
    {
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
