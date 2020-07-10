#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#pragma once
#include "Operacion.h"
#include "Producto.h"
#include "PrototiposGlobales.h"
class Venta :public Operacion
{

public:



protected:

    int IdVendedor;
    int IdCliente;


};

int GenerarIdVenta();


#endif // VENTAS_H_INCLUDED
