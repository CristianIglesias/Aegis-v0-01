#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#pragma once
#include "Producto.h"
#include "PrototiposGlobales.h"
class Venta
{
public:
    void cargar();
    void mostrar();

protected:

    int numeroventa;///se genera solo?
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

};

///CALCULO DE LA VENTA:  TOTAL=Producto item * cantidad
///POSIBLE FORMATO:
///                               NUMEOR DE LA VENTA(XXX)                           FECHA(XX/XX/XXXX)
///                               LEGAJOVENDEDOR
///                               IDCLIENTE
///                               TIPO DE PAGO / TIPO DE FACTURA / TIPO DE ENTREGA
///                                ITEM(SUS DATOS//CODIGOPORDUCTO) + IMPORTEUNIDAD
///                                                                     IMPORTE TOTTAL
///                                                                     %DESCUENTO
///                                                                     TOTAL $:


#endif // VENTAS_H_INCLUDED
