#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#pragma once
class Proveedor:public Persona
{
protected:
    float PorcentajeRentabilidad;
    float EstadoCuenta;
    char  CodigoProveedor[10];

public:
    //metodos;
    void cargar();
    void mostrar();
};




#endif // PROVEEDOR_H_INCLUDED
