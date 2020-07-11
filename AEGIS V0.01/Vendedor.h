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
    bool leerVendedor(int pos);
    bool  LeerxID(int id);
    void  mostrarxID ();
    int  GuardarVendedorEnDisco(int ID);
    void EliminarVendedor();


    void SetPersona(Persona Per);
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
    int setLegajo();


};

  void ModificarVendedor();
  void menuModificarVendedor(Vendedor *ven,int pos);


#endif // VENDEDOR_H_INCLUDED
