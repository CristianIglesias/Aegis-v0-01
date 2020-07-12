#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Vendedor.h"
#include "Clientes.h"
#include "Ventas.h"
#include "DetalleVenta.h"

int DetalleVenta:: CargarDetalle(Venta *obj)
{
    int error=-1;
    idVenta=obj->getID();
    error=setIdProducto();
    if(error==1)
        return 1;
    error=setCantidad();
    if(error==1)
        return 1;

}

int DetalleVenta::setIdProducto()
{
    char Cod[11];
    int aux, i=0,error;
    Producto Reg;
    while(error!=0)
    {
        cout<<" Ingrese el ID del Producto a Vender."<<endl;
        cout<<"ID PRODUCTO: ";
        cin.ignore();
        cin.getline(Cod,10);
        error=Reg.buscarcodigo(getIdProducto());
        if(error==1)
            return 1;


    }
};
int DetalleVenta :: setCantidad()
{
    int cantidad;
    cout<<"
};
