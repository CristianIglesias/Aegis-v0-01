#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED
#pragma once
#include "PrototiposClases.h"
#include "PrototiposGlobales.h"
#include "Producto.h"
#include "Vendedor.h"
#include "Clientes.h"
#include "Ventas.h"
class DetalleVenta
{
public:
    DetalleVenta();
    int CargarDetalle(Venta *obj);
    int setIdProducto();
    int setCantidad();
    int setPrecioTotal();
    void Mostrar();///Muestra detalles en formato tabla (sin cabecera)



    ///Sets Especificos, sin validaciones ni cosas raras.
    void setPrecioUnidad(float Precio)
    {
        PrecioUnidad=Precio;
    };

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


int GuardarDetalle(DetalleVenta *Obj);
int AgregaraVenta(Venta Obj);///Agrega un detalle a una venta, el tema es definir las "reglas" de como va a funcionar esto."

int MostrarDetalles(Venta *Reg);

int ContarDetallesXID(int ID);

int CargarDetallesVenta(DetalleVenta *Vec, int Cant, int ID);

int MostrarDetallesTABLA(DetalleVenta *Vec, int Cant);








#endif // DETALLEVENTA_H_INCLUDED
