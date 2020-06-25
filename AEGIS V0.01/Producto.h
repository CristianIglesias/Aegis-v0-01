#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#pragma once
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

    void cargar();
    void mostrar();
    int buscarcodigo(char *codigo);///funcion para validar ingreso de id igual, arreglar
    bool guardarProducto();///guardar en disco
    bool leerProductos(int);///leer en disco



    const char * getCodigoProducto()
    {
        return CodigoProducto;
    }
    const char * getCodigoProveedor()
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
    void setCodigoproducto(char *cod)
    {
        strcpy(CodigoProducto,cod);
    }
    void setCodigoProveedor(char *cpro)
    {
        strcpy(CodigoProveedor,cpro);
    }
    void setNombreItem(char *item)
    {
        strcpy(NombreItem,item);
    }
    void setCostoCompra(float costo)
    {
        CostodeCompra=costo;
    }
    void setPorcentajeRentabilidad(float porcentaje)
    {
        PorcentajeRentabilidad=porcentaje;
    }
    void setPrecioVenta(float venta)
    {
        PreciodeVenta=venta;
    }
    void setStockMin(int stockm)
    {
        StockMin=stockm;
    }
    void setStockActual(int stocka)
    {
        StockActual=stocka;
    }



};







#endif // PRODUCTO_H_INCLUDED
