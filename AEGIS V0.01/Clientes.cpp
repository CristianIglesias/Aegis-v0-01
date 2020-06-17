#include <iostream>
#include <cstdio>
using namespace std;
#include "Clientes.h"
#include "PrototiposGlobales.h"
const char *ArchivoClientes ="Clientes.dat";

void  Cliente:: cargar()
{
    Persona::Cargar();
    this->Generarid();
    if(idCliente<0)
    {
        cout<<"Hubo un error en la generación de ID Cliente, Intente Nuevamente"<<endl;
        return;
    }
    cout<<"ID Cliente: "<<idCliente;
    cout<<"Tipo De Pago Preferido: ";


    ///sacando que faltan cosas

};

void  Cliente:: mostrar()
{
    Persona::Mostrar();
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
    return deuda;
};
void  Cliente:: SetTipoPago(int NuevoTipoP)
{

};
void Cliente :: SetPrefFact(int NuevoPrefFact)
{

};
void Cliente :: SetDeuda(float NuevaDeuda)
{

};
void Cliente::Generarid()
{
    int id,cantRegistros=0;
    FILE *p;
    Cliente aux;
    p=fopen(ArchivoClientes,"wb");
    if(p==NULL)
        idCliente=-1;
    return;
    while(fread(&aux,sizeof(Cliente),1,p)==1)
    {
        cantRegistros++;
    }
    id=cantRegistros+1;
    fclose(p);
    idCliente=id;
    return;
}
