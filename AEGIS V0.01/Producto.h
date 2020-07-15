#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#pragma once
#include "PrototiposClases.h"
#include "PrototiposGlobales.h"
#include "Proveedor.h"

class Producto
{
private:
    char  CodigoProducto[10];
    char  CodigoProveedor[10];
    char  NombreItem[30];
    float CostodeCompra;
    float PorcentajeRentabilidad;
    float PreciodeVenta;
    int StockMin;
    int StockActual;
    bool Estado;
public:

    ///METDOOS;
    void cargar();
    void mostrar();
    int buscarcodigo(const char *codigo);///funcion para validar ingreso de id que no sea igual; arreglar
    int guardarNuevoProducto();///guardar en disco
    int guardarProducto();
    int ObtenerPosicionProducto(char *codigo);
    bool leerProductos(int pos);///leer en disco
    void modificar_producto();
    bool  LeerxID(char *id);
    void mostrarxID ();
    void Eliminar();


    ///gets;
    const char * getCodigoProducto()
    {
        return CodigoProducto;
    }
    char * getCodigoProveedor()
    {
        return CodigoProveedor;
    }
    const char * getNombreItem()
    {
        return NombreItem;
    }
    float getCostodeCompra()
    {
        return CostodeCompra;
    }
    float getPorcentajeRentabilidad()
    {
        return PorcentajeRentabilidad;
    }
    float getPrecioVenta()
    {
        return PreciodeVenta;
    }
    int getStockMin()
    {
        return StockMin;
    }
    int getStockActual()
    {
        return StockActual;
    }
    ///sets;
    int setCodigoproducto();
    int setCodigoProveedor();
    int setNombreItem();
    int setCostoCompra();
    int setPorcentajeRentabilidad();
    int setPrecioVenta(float costo, int porcentaje);
    int setStockMin();
    int setStockActual();

};







#endif // PRODUCTO_H_INCLUDED
