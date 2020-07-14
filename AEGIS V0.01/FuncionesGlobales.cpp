#include <iostream>
#include <iomanip>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"
#include "Clientes.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Vendedor.h"


void error_msj(int cod, int i)/// A COMPLETAR, CADA UNO AGREGA ERRORES QUE NECESITE, SOLO SER A AGREGAR CASES AL SWITCH.
/// ES UTIL PARA SIMPLIFICAR EL C DIGO.
{
    switch(cod)
    {


    case 1:
        cout<<"Salida Voluntaria!."<<endl;
        cout<<"Operacion Cancelada. Presione cualquier Tecla para continuar."<<endl;
        anykey();
        break;

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
        cout<<"Error Validando, Ese codigo ya existe. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -4:
        cout<<"Error Validando, Este campo solo permite Números Enteros. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""-999""."<<endl;
        }
        break;
    case -5:
        cout<<"Error Validando, ID INEXISTENTE. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""-999""."<<endl;
        }
        break;
    case -6:
        cout<<"Error Validando,///.No puede ser menor a 0. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    }
}




int ValidarEnteros( const char *Telefono)///valida cadenas de enteros
{
    int i, TAM;
    bool flag=true;
    TAM =strlen(Telefono);
    for (i=0; i<TAM; i++)

    {
        if (Telefono[i-1]<'0'&&Telefono[i-1]>'9')
        {
            flag=false;
            break;
        }
        if(Telefono[0]=='0')
        {
            return 1;///Valida Salida Voluntaria.
        }
    }
    if(flag)
        return 0;
    else
        return -1;
};

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
        if(isalpha(cad[i])==0)
        {
            flag=false;
            return -1;
        }

    }
    if(flag)
        return 0;
};

int ValidarFloats(float var)
{
    if(var>0)
        return 0;
    else
        return -4;
}
int ValidarEntero(int c)
{
    if(c==-999)
        return 1;
    if(c>0&&c%1==0)
        return 0;
    else
        return -4;
}

void ListarClientes()
{
    Cliente Cli;
    int i=1;
    cls();
   cout<<"*________________________________________________________________________________________________*"<<endl;
    cout<<"*______________________________________LISTADO DE CLIENTES______________________________________*"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    while(Cli.LeerxPos(i)==0)
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
    setColor(LIGHTBLUE);
    cout<<"*________________________________________________________________________________________________*"<<endl;
    cout<<"*______________________________________LISTADO DE PRODUCTOS______________________________________*"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<< left;
    cout<<setw(3)<<"CODIGO-"<<" ";
    cout<<setw(10)<<"NOMBRE-"<<"  ";
    cout<<setw(3)<<"PROVEEDOR-"<<"  ";
    cout<<setw(5)<<"COSTO-"<<"  ";
    cout<<setw(5)<<"% RENTABILIDAD-"<<"  ";
    cout<<setw(5)<<"$ VENTA-"<<"  ";
    cout<<setw(5)<<"STOCK MINIMO-"<<"  ";
    cout<<setw(5)<<"STOCK ACTUAL"<<"  "<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    setColor(WHITE);
    while(reg.leerProductos(i)==1)
    {
        reg.mostrar();
        cout<<endl;
        i++;
    }
    cin.ignore();
    anykey();
}

void ListarVendedores()
{
    Vendedor ven;
    int i=0;
    cls();
   cout<<"*________________________________________________________________________________________________*"<<endl;
    cout<<"*______________________________________LISTADO DE VENDEDORES______________________________________*"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    while(ven.LeerxID(i)==1)
    {
        ven.mostrar();
        cout<<endl;
        i++;
    }
    cin.ignore();
    anykey();
}

void listarProveedores()
{
    Proveedor prov;
    int i=1;
    cls();
cout<<"*________________________________________________________________________________________________*"<<endl;
    cout<<"*______________________________________LISTADO DE PROVEEDORES______________________________________*"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    while(prov.leerProveedor(i)==1)
    {
        prov.mostrar();
        cout<<endl;
        i++;
    }
    cin.ignore();
    anykey();
}

/*void listadoDeVentas()
{
    cout<<"*________________________________________________________________________________________________*"<<endl;
    cout<<"*______________________________________LISTADO DE VENTAS______________________________________*"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;

    while(ventas.leerVentas(i)==1)
    {
        ventas.mostrar();
        cout<<endl;
        i++;
    }
    cin.ignore();
    anykey();
}
*/
