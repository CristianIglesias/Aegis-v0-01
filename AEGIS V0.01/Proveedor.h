#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#pragma once
#include "Persona.h"

class Proveedor:public Persona
{
protected:
    float PorcentajeRentabilidad;
    float EstadoCuenta;
    char CodigoProveedor[10];

public:
    void cargar();
    void mostrar();
    int guardarProveedor();
    bool leerProveedor(int pos);
    int buscarcodigoproveedor(const char *codigo);
    int validarFloat(float c);
    bool LeerxID(char *id);
    void mostrarxID ();
    void Modificar();
    void menuModificarProveedor();
    void EliminarProveedor();

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
        return CodigoProveedor;
    }

    int  setPorcentajeRentabiliad();

    int setEstadoCuenta();

    int setCodigoProveedor();

};



#endif // PROVEEDOR_H_INCLUDED
