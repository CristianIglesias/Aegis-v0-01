#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#include "Persona.h"
#include "Proveedor.h"
const char *ArchivoProveedor ="Proveedor.dat";

///falta agregar validaciones de id.
void  Proveedor:: cargar()///Carga Proveedor.
{
    Persona::Cargar();

    cout<<"INGRESE EL ID DE PROVEEDOR:"<<endl;
    cin.getline(CodigoProveedor,10);

    cout<<"INGRESE % RENTABILIDAD:"<<endl;
    cin>>PorcentajeRentabilidad;
    if(PorcentajeRentabilidad<0)
    {
        cout<<"ERROR! el porcentaje no puede ser menor a 0"<<endl;
        return;
    }

    cout<<"INGRESE ESTADO DE CUENTA:"<<endl;
    cin>>EstadoCuenta;

    guardarProveedor();

};

int Proveedor::guardarProveedor()
{

    FILE *p;
    p=fopen(ArchivoProveedor,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Proveedor),1,p)!=1);
    {
        fclose(p);
        return -1;
    }
    fclose(p);
    return 0;

}
void Proveedor::mostrar()
{
    Persona::Mostrar();///como pongo lo que me falta? :(;
    cout<<"CODIGO: " <<CodigoProveedor<<endl;
    cout<<"ESTADO DE CUENTA: "<<EstadoCuenta<<endl;
    cout<<"% RENTABILIDAD: "<< PorcentajeRentabilidad<<endl;
}

bool Proveedor::leerProveedor(int pos)
{
    bool leyo=false;
    FILE *p;
    p=fopen(ArchivoProveedor,"rb");
    if(p==NULL)
    {

        return false;
    }
    if(pos>0)
    {
        fseek(p,pos * sizeof(Proveedor),0);
        leyo=fread(this,sizeof(Proveedor),1,p);
    }
    else
    {
        leyo=fread(this,sizeof(Proveedor),1,p);
    }
    fclose(p);
    return leyo;

}
