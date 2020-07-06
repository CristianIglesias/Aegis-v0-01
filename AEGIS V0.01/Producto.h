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
    int buscarcodigo(const char *codigo);///funcion para validar ingreso de id igual, arreglar
    int guardarProducto();///guardar en disco
    int guardarProducto(const char *Codigo);
    bool leerProductos(int pos);///leer en disco
    bool sobrescribir(int);
    void modificar_producto();
    int validarEntero(int c);
    bool  LeerxID(char *id);
    void mostrarxID ();
    void Eliminar();



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


    ///sets de producto;



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
