#include <iostream>
#include <cstdio>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Clientes.h"
#include "PrototiposGlobales.h"
const char *ArchivoClientes ="Clientes.dat";
/// A SABER
/// ERROR==0-TA TODO PIOLA, SIGUE ADELANTE
/// ERROR==1-SALIDA VOLUNTARIA, CLAVA RETURN PERRI
/// ERROR<=0-SIGUE INTENTANDO, TRANK PALANK
void  Cliente:: cargar()///Carga Cliente.
{
    int error=0;
    Persona::Cargar();
    Generarid();
    if(idCliente<0)
    {
        cout<<"Hubo un error en la generación de ID Cliente, Intente Nuevamente"<<endl;
        return;
    }
    cout<<"ID Cliente: "<<idCliente<<endl;
    error = SetTipoPago();

    if(error>0)
    {
        cout<<"Operación Cancelada."<<endl;
        cout<<"Ingrese cualquier tecla para continuar"<<endl;
        anykey();
    }

    error=SetPrefFact();
    if(error>0)
    {
        cout<<"Operación Cancelada."<<endl;
        cout<<"Ingrese cualquier tecla para continuar"<<endl;
        anykey();
    }
    Deuda=0;

    error=GuardarClienteEnDisco();
    if(error!=0)
    {
        cout<<"Hubo un error Guardando el Cliente en el Archivo."<<endl;
        cout<<"Ingrese cualquier tecla para continuar"<<endl;
        anykey();
    }


};

void  Cliente:: mostrar()
{   cout <<"El Cliente "<<endl;
    Persona::Mostrar();
    cout<<"Prefiere Pago con ";
    cout<<"Y Tipo de Factura ";

    if(GetDeuda()<0)
    {   setColor(RED);
        cout<<"El Cliente Posee una deuda de "<<GetDeuda()<<endl;
        setColor(WHITE);
    }

};
void Cliente::Generarid()
{
    int cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoClientes,"rb");
    if(p==NULL)
    {
        idCliente=-1;
        return;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Cliente);

    idCliente=cantRegistros+1;
    fclose(p);
    return;
}


int Cliente :: GuardarClienteEnDisco()
{   FILE *p;
    p=fopen(ArchivoClientes,"ab");
    if(p==NULL)
    {
            return -1;
    }
    if(fwrite(this,sizeof(Cliente),1, p)!=1)
    {fclose(p);
        return -1;
    }
    fclose (p);
    return 0;
    };





int Cliente:: SetTipoPago()
{
    cout<<"Tipo De Pago Preferido: ";
    int error=0,i=0;
    while(error<0)
    {   cout<<"Recuerde: 1=Efectivo."<<endl;
        cout<<"           2=Tarjeta Débito."<<endl;
        cout<<"           3=Tarjeta Crédito."<<endl;
        cin>>TipodePago;
        error=ValidarTipoPago();
        if(error==1)
        {
            return error;
        }
        if(error<0)
        {
            i++;
            cout<<"Error Validando Tipo Pago.  -Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i<<"/3"<<endl;
            if(i>=3)
            {
                cout<<"Si querés salir, cancelando la carga ingresá 99"<<endl;
            }
        }
    }///Cierra el While
return error;
};

int Cliente :: ValidarTipoPago()
{
    int error=0;
    if(TipodePago>1&&TipodePago%1!=0)///Valida entero y positivo.
    {
        error=0;
        return error;
    }
    if(TipodePago==99)///Salida Voluntaria
    {
        error=1;
        return error;
    }

    if(TipodePago<1||TipodePago>3)///Valida Tipos permitidos
    {
        error=-1;
        return error;
    }
return error;
}

int Cliente :: SetPrefFact()
{

    int error,i=0;
    cout<<"Ingrese Preferencia de Factura."<<endl;
    cout<<"Recuerde: 1=Factura B."<<endl;
    cout<<"          2=Factura A."<<endl;
    cin>>PrefFactura;
    error=ValidarPrefFact();
    if(error==1)
    {
        return error ;
    }
    if(error<0)
    {
        i++;
        cout<<"Error Validando Tipo Pago.  -Nro "<<error<<" Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"/3"<<endl;
        if(i>=3)
        {
            cout<<"Si querés salir, cancelando la carga ingresá 99"<<endl;
        }
    }
return error;
};

int Cliente :: ValidarPrefFact()
{
    int error=0;
    if(PrefFactura<1&&PrefFactura%1!=0)
    {
        error=-1;
        cout<<"Ingrese un Numero entero y Positivo."<<endl;
        return error;
    }
    if(PrefFactura==99)
    {
        error=1;
        return error;
    }

    if(PrefFactura>2||PrefFactura<1)
    {
        error=-2;

        return error;
    }
    return error;
};


void Cliente :: SetDeuda()
{
///TODO INGRESO Y VALIDACIÓN, CON SALIDA A VOLUNTAD(SetDeuda).
};

int   Cliente:: GetidCliente()
{
    return idCliente;
};
int   Cliente:: GetTipoPago()
{
    return TipodePago;
};
int   Cliente:: GetTipoFactura()
{
    return PrefFactura;
};
float Cliente:: GetDeuda()
{
    return Deuda;
};
