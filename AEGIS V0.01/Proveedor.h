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
    int GuardarProveedorEnDisco(int ID);
    bool leerProveedor(int pos);
    int buscarcodigoproveedor(char *codigo);
    int validarFloat(float c);
    bool LeerxID(char *id);
    void mostrarxID ();
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
void ModificarProveedor();
void menuModificarProveedor(Proveedor *pro, int pos);


#endif // PROVEEDOR_H_INCLUDED
