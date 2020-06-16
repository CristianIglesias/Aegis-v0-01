#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#pragma once
#include "Producto.h"
#include "PrototiposGlobales.h"
class Venta
{
private:
    int numeroventa;
    Fecha fechaVenta;
    int TipoPago;
    int TipoFactura;
    Producto item;
    int legajoVendedor;
    int idCliente;
    char CodigoProducto[10];
    int cant;
    int TipodeEntrega;
    int PorcentajeDesc;
    float ImporteTotal;
    float ImporteUnidad;
public:

    void cargar();
    void mostrar();

};



#endif // VENTAS_H_INCLUDED
