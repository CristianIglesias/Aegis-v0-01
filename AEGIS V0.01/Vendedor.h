#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#pragma once

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
    void Modificar();
    void menuModificarVendedor();
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

    int setLegajo();


};



#endif // VENDEDOR_H_INCLUDED
