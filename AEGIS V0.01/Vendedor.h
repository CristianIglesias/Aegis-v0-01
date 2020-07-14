#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#pragma once
#include "Persona.h"
class Vendedor:public Persona
{
protected:
    float PorcentajeComision;
    float VentaDiaria;
    int legajo;

public:
    void cargar();
    void mostrar();
    int guardar();
    int leerVendedor(int pos);
    int  LeerxID(int id);
    void  mostrarxID ();
    int  GuardarVendedorEnDisco(int ID);
    void EliminarVendedor();
    float getPorcentajeComision()
    {
        return PorcentajeComision;
    }
    float getVentaDiaria()
    {
        return VentaDiaria;
    }
    int getlegajo()
    {
        return  legajo;
    }
    int  setPorcentajeComision();
    int setVentaDiaria();
    int setLegajo(int );
};

void ModificarVendedor();
void menuModificarVendedor(Vendedor *ven,int pos);
int GenerarIdVendedor();


#endif // VENDEDOR_H_INCLUDED
