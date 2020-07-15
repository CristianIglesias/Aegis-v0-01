#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#pragma once
#include "Operacion.h"
#include "Producto.h"
#include "PrototiposGlobales.h"
class Venta :public Operacion
{

public:
    void Mostrar();
    void GenerarVenta();
    int SetIdVendedor();
    int SetIdCliente();
    void SetIdCliente(int aux)
    {
        IdCliente=aux;
    }
    int getIdVendedor()
    {
        return IdVendedor;
    };
    int getIdCliente()
    {
        return IdCliente;
    };
    void setImporteTotal(float ImporteDetalle);
    int GuardarVenta();///Agregado al archivo, tranqui.
protected:

    int IdVendedor;
    int IdCliente;


};

int GenerarIdVenta();


#endif // VENTAS_H_INCLUDED
