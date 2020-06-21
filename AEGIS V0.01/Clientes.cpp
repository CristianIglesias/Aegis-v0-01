#include <iostream>
#include <cstdio>
using namespace std;
#include "Clientes.h"
#include "PrototiposGlobales.h"
const char *ArchivoClientes ="Clientes.dat";
/// A SABER
/// ERROR=0-TA TODO PIOLA, SIGUE ADELANTE
/// ERROR=1-SALIDA VOLUNTARIA, CLAVA RETURN PERRI
/// ERROR<0-SIGUE INTENTANDO, TRANK PALANK
void  Cliente:: cargar()///Carga Cliente.
{
    Persona::Cargar();
    Generarid();
    if(idCliente<0)
    {
        cout<<"Hubo un error en la generación de ID Cliente, Intente Nuevamente"<<endl;
        return;
    }
    cout<<"ID Cliente: "<<idCliente;
    cout<<"Tipo De Pago Preferido: ";
    SetTipoPago();
    ///TODO COMPLETAR CARGA CLIENTA
};

void  Cliente:: mostrar()
{
    Persona::Mostrar();


};

int  Cliente:: SetTipoPago()
{
    int error=0,i=0;
    while(error<0)
        cin>>TipodePago;
    error=ValidarTipoPago();
    if(error==1)
    {
        return 1;
    }

    if(error<0)
    {
        i++;
        cout<<"Error Validando Tipo Pago -Nro "<<error<<" Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"/3"<<endl;
        if(i>=3)
        {
            cout<<"Si querés salir, ingresá 99"<<endl;
        }
    }

};

int Cliente :: ValidarTipoPago()
{
    int error;
    if(TipodePago>1&&TipodePago%1!=0)
    {
        error=0;
        return error;
    }
    if(TipodePago==99)
    {
        error=1;
        return error;
    }

    else
    {
        error=-1;
        return error;
    }
}

int Cliente :: SetPrefFact()
{
///TODO INGRESO Y VALIDACIÓN, CON SALIDA A VOLUNTAD.
};

int Cliente :: ValidarPrefFact()
{
    int error;
    return error;
};


void Cliente :: SetDeuda()
{
///TODO INGRESO Y VALIDACIÓN, CON SALIDA A VOLUNTAD.
};
void Cliente::Generarid()
{
    int id=0,cantRegistros=0;
    FILE *p;
    Cliente aux;
    p=fopen(ArchivoClientes,"wb");
    if(p==NULL)
        idCliente=-1;
    return;
    fseek(p,0,2);
    cantRegistros=ftell(p)/sizeof(Cliente);

    id=cantRegistros+1;
    fclose(p);
    idCliente=id;
    return;
}
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
    return deuda;
};
