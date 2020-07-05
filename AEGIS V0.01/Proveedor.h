#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#pragma once
#include "Persona.h"
class Proveedor:public Persona
{
protected:
    float PorcentajeRentabilidad;
    float EstadoCuenta;
    const char  *CodigoProveedor[10];

public:
    void cargar();
    void mostrar();
    int guardarProveedor();
    bool leerProveedor(int pos);
    /// int buscarcodigoproveedor(const char *codigo);///busca en el archivo si el codigo de proveedor existe




    float getPorcentajeRentabiliad()
    {
        return PorcentajeRentabilidad;
    }
    float getEstadoCuenta()
    {
        return EstadoCuenta;
    }
    const char *getCodigoProveedor()
    {
        return *CodigoProveedor;
    }

    int  setPorcentajeRentabiliad();

    int setEstadoCuenta();

    int setCodigoProveedor();

};



#endif // PROVEEDOR_H_INCLUDED
