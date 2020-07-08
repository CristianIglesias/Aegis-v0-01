#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Persona.h"
#include "Vendedor.h"
#include "PrototiposGlobales.h"
const char *ArchivoVendedor ="Vendedor.dat";

void Vendedor::cargar()
{

    int error=0;
    Persona::Cargar();

    error=setPorcentajeComision();
    if(error==1)
        return;

    error= setVentaDiaria();
    if(error==1)
        return;

    error=setLegajo();
    if(error==1)
        return;

};


int Vendedor::setPorcentajeComision()
{
    cin.ignore();

    int i=0, error=-1;
    while (error<0)
    {
        cout<<"Ingrese el % de comision del vendedor: ";
        cin>>PorcentajeComision;
        error=validarfloat();
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(error,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
}

int Vendedor::setVentaDiaria()
{
    cin.ignore();

    int i=0, error=-1;
    while (error<0)
    {
        cout<<"Ingrese el monto de la venta diaria : ";
        cin>>VentaDiaria;
        error=validarfloat();
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-4,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
}

int Vendedor::setLegajo()
{
    cin.ignore();

    int i=0, error=-5;
    while (error<0)
    {
        cout<<"Ingrese el legajo del vendedor : ";
        cin>>legajo;
        ///error=ValidarEnteros();
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-4,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
}

int Vendedor::guardar()
{
    FILE *p;
    p=fopen(ArchivoVendedor,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Vendedor),1,p)!=1);
    {
        fclose(p);
        return -1;
    }
    fclose(p);
    return 0;
}
