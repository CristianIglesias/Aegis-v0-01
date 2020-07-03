#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "Persona.h"
#include "Proveedor.h"
#include "PrototiposGlobales.h"
#include "rlutil.h"
using namespace rlutil;
const char *ArchivoProveedor ="Proveedor.dat";

/*
int Producto:: buscarcodigoproveedor(const char *codigo)
{
    Producto aux;
    FILE *p;
    p=fopen(ArchivoProveedor,"rb");
    if(p==NULL)

        return 1;

    while(fread(&aux,sizeof(Proveedor),1,p))
    {
        if(strcmp(getCodigoProveedor(),aux.getCodigoProveedor())==1)
        {
            fclose(p);
            return -1;
        }

    }
    fclose(p);
    return 0;

}
*/

void  Proveedor:: cargar()
{
    int error=0;
    Persona::Cargar();

    error=setPorcentajeRentabiliad();
    if(error==1)
        return;

    error= setEstadoCuenta();
    if(error==1)
        return;

    error=setCodigoProveedor();
    if(error==1)
        return;

};

int Proveedor::setPorcentajeRentabiliad()
{
    cin.ignore();

    int i=0, error=-6;
    while (error<0)
    {
        cout<<"Ingrese el porcentaje de rentabilidad del proveedor: ";
        cin>>PorcentajeRentabilidad;
        ///error=validarFloat();
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-6,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};

int Proveedor::setEstadoCuenta()
{
    cin.ignore();

    int i=0, error=-6;
    while (error<0)
    {
        cout<<"Ingrese el estado de cuenta del proveedor: ";
        cin>>EstadoCuenta;
        ///error=validarFloat();
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-6,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};

int Proveedor::setCodigoProveedor()
{
    cin.ignore();

    int i=0, error=-5;
    while (error<0)
    {
        cout<<"Ingrese el codigo de proveedor: ";
        ///cin.getline(CodigoProveedor,10);
        ///error=buscarcodigoproveedor(this->getCodigoProveedor());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-5,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
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
