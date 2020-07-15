#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED
#pragma once
#include "PrototiposClases.h"
#include "PrototiposGlobales.h"
#include "Operacion.h"
#include "Producto.h"

class Compra :public Operacion
{

public:



protected:

    char CodigoProveedor[10];
    int IdCliente;


};

int GenerarIdCompra();
#endif // COMPRAS_H_INCLUDED
