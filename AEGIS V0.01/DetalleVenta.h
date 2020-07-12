#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED
#pragma once

class DetalleVenta
{
public:
    int CargarDetalle(Venta *obj);
    int setIdProducto();
    int setCantidad();




    ///Gets----
    int getIdVenta()
    {
        return idVenta;
    }
    const char * getIdProducto()
    {
        return idProducto;
    }
    float getPrecioUnidad()
    {
        return PrecioUnidad;
    }
    int getCantidad()
    {
        return Cantidad;
    }
    float  getImporteTotal()
    {
        PrecioTotal=PrecioUnidad*Cantidad;
        return PrecioTotal;
    }
protected:
    int idVenta;
    char idProducto [10];
    float PrecioUnidad;
    int   Cantidad;
    float PrecioTotal;
};
///si queda igual el detalle venta como el detalle compra usar detalle operación


int GuardarDetalle();
int AgregaraVenta(Venta Obj);///Agrega un detalle a una venta, el tema es definir las "reglas" de como va a funcionar esto."









#endif // DETALLEVENTA_H_INCLUDED
