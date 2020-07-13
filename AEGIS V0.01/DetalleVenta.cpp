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
        if(error==0)
        {

            cout<<"El Producto deseado es : "<<Reg.getNombreItem()<<" ?"<<endl;
            cout<<"El Precio del Producto es de :$"<<Reg.getPrecioVenta();
            setPrecioUnidad(Reg.getPrecioVenta());

            cout<<"SI :1             NO:0"<<endl;
            cin>>op;
            switch(op)
            {
            case 1:
                return error;
                break;
            case 0:
                error=-2;
                break;
            }

            return 0;
        }
        if(error==-1)
        {   i++;
            error_msj(-5,i)
        }
    }
};
int DetalleVenta :: setCantidad()
{
    int cantidad,error=-1,i=0;
    while (error<0)
    {
        cout<<"Ingrese la Cantidad de Unidades del Producto que va a Comprar"<<endl;
        cin>>cantidad;
        error=ValidarEntero(cantidad);
        if(error==1)
            return error;
        if (error==0)
        {
            error=setPrecioTotal();

        }
        if(error==-1)
        {
            i++;
            error_msj(-4,i);
        }
    }
    return error;
};
int DetalleVenta::setPrecioTotal()
{
    int op;
    cout<<"Quedaría un total de :$"<<getImporteTotal();
    cout<<"Desea Modificar la cantidad?"<<endl;
    cout<<"SI: 1              NO: 0"<<endl;
    cin>>op;
    switch(op)
    {
    case 1:
    {
        return -2;
    }
    case 0:
    {
        return 0;
    }

    }
};
