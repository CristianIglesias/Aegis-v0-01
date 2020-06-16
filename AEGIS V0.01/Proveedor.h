#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#pragma once
class Proveedor:public Persona
{
protected:
    int NumeroProveedor;
    float PorcentajeRentabilidad;
    float EstadoCuenta;

public:
    //metodos;
    void cargar();
    void mostrar();
};




#endif // PROVEEDOR_H_INCLUDED
