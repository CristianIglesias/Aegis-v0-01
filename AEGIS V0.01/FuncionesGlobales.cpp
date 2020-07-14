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
#include "Ventas.h"
#include "DetalleVenta.h"

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
void ListadoVentasxFechas()
{
    int error=-1,CantVentas;
    Fecha Fech1,Fech2;
    cout<<"Ingrese las fechas entre las que quiere que se filtre el Listado"<<endl;
    error=Fech1.CargarFecha();
    if(error==1)
        return;
    error=Fech2.CargarFecha();
    if(error==1)
        return;
    AsignarOrdenaFechas(&Fech1,&Fech2);
    CantVentas=ContarRegistrosxFechas(Fech1,Fech2);



};

void AsignarOrdenaFechas(Fecha *reg1,Fecha *reg2)
{
    Fecha Aux;
    if(reg1->getDia()<=reg2->getDia()&&reg1->getMes()<=reg2->getMes()&&reg1->getAnio()<=reg2->getAnio())
        return;
    if(reg1->getAnio()>reg2->getAnio()||reg1->getMes()>reg2->getMes()||(reg1->getMes()==reg2->getMes()&&reg1->getDia()>reg2->getDia()))
    {
    Aux.setFecha(reg1);
    reg1->setFecha(reg2);
    reg2->setFecha(aux);
    return;
    }
///TODO SET FECHA!
};

int ContarRegistrosxFechas(Fecha Fech1,Fecha Fech2)
{       Venta Aux;
        int cont;
        FILE *P;
        P=fopen(ArchivoVentas,"rb");
        while(fread(&Aux,sizeof(Venta),1,P)==1)
        {
            if(Venta.getFechaOperacion()>=Fech1||Venta.getFechaOperacion()<=Fech2);

        }
}


void ListadoVentasxVendedor()
{

};

void ListadoVentasxImporteMax()
{

};

void ListadoVentasxCliente()
{

};




int Fecha::CargarFecha()
{
    int error=0,i=0,aux;
    while (error!=0||error!=1)
    {
        cout<<"Ingrese Fecha "<<endl;
        cout<<"Fecha a Buscar (d/m/a):"<<endl;
        cin>>aux;
        setDia(aux);
        cout<<"/";
        cin>>aux;
        setMes(aux);
        cout<<"/";
        cin>>aux;
        setAnio(aux);
        error=ValidarFecha(GetFecha());
        if (error==-1)
        {
            i++;
            error_msj(-2,i);
            anykey();
            cls();
        }
        else
            break;
    }
    return error;

};
int Fecha :: ValidarFecha(Fecha FechaNac)
{
    if(FechaNac.getMes()==0&&FechaNac.getDia()==0&&FechaNac.getAnio()==0)
        return 1;
    if((FechaNac.getMes()>0&&FechaNac.getMes()<13)&&(FechaNac.getAnio()>1910&&FechaNac.getAnio()<=2020))
    {
        switch(FechaNac.getMes())
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( FechaNac.getDia() >= 1 && FechaNac.getDia() <= 31 )
            {
                return 0;
            }
            else
            {
                return -1;
            }
        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( (FechaNac.getDia() >= 1) && (FechaNac.getDia() <= 30) )
            {

                return 0;
            }
            else
                return -1;
        case  2 :
            if( (FechaNac.getAnio() % 4 == 0 && FechaNac.getAnio() % 100 != 0 )|| (FechaNac.getAnio() % 400 == 0 ))
                if ( FechaNac.getDia() >= 1 && FechaNac.getDia() <= 29 )
                {

                    return 0 ;
                }
                else
                {
                    return -1;
                }
            else if ( FechaNac.getDia() >= 1 && FechaNac.getDia() <= 28 )
            {
                return 0;
            }
            else
            {
                return -1;
            }

        }
    }
    else
    {

        return -1;
    }
    return-1;
};
