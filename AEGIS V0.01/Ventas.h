#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#pragma once
#include "PrototiposClases.h"
#include "Operacion.h"
#include "Vendedor.h"
#include "Clientes.h"
#include "Producto.h"
#include "DetalleVenta.h"
class Venta :public Operacion
{
public:
    void Mostrar();
    void MostrarTabla();
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

void ListarTodasVentas();
int ContarVentas();
int CargarVentas(Venta *VecDin,int CantRegs);
int MostrarVentas(Venta *VecDin,int CantRegs);


void ListadoVentasxFechas();
int ContarVentasxFechas(Fecha Fech1,Fecha Fech2);
int CargarVecVentasxFecha(Venta *Vec,int CantVentas,Fecha Fech1,Fecha Fech2);
void ListadoVentasxVendedor();

void ListadoVentasxImporteMax();

void ListadoVentasxCliente();


#endif // VENTAS_H_INCLUDED
