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
const char *ArchivoDetalle ="DetalleVenta.dat";

int DetalleVenta:: CargarDetalle(Venta *obj)
{
    int error=-1,op;
    idVenta=obj->getID();
    error=setIdProducto();
    if(error==-2)
        return 1;
    error=setCantidad();
    if(error==-1)
        return 1;
    error=GuardarDetalle(this);
    if(error!=0)
    {
        cout<<"Hubo un error Guardando el Detalle en el Archivo."<<endl;
        cout<<"Ingrese cualquier tecla para continuar"<<endl;
        anykey();
    }
    else
    {
        cout<<"Detalle Guardado en el Archivo con Exito!"<<endl;
        cout<<"Desea agregar mas items a la venta? "<<endl;
        cout<<"SI :1             NO:0"<<endl;
        cin>>op;
        cls();
        switch(op)
        {
        case 1:
            return 0;
            break;
        case 0:
            error=-2;
            return error;
            break;
        }
    }

}


int DetalleVenta::setIdProducto()
{
    char Cod[10];
    int aux, i=0,error,op;
    Producto Reg;
    while(error!=0)
    {
        cout<<" Ingrese el ID del Producto a Vender."<<endl;
        cout<<"ID PRODUCTO: ";
        cin.ignore();
        cin.getline(Cod,10);
        error=Reg.LeerxID(Cod);
        if(error==false)
            error=-1;
        if(error==-1)
        {
            i++;
            error_msj(-5,i);
        }
        if(error==true)
        {
            cout<<"El Producto deseado es : " << Reg.getNombreItem()<<"?"<<endl;
            cout<<"El Precio del Producto es de :$ " << Reg.getPrecioVenta()<<endl;
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

    }
};
int DetalleVenta :: setCantidad()
{
    int error=-1,i=0;
    while (error<0)
    {
        cout<<"Ingrese la Cantidad de Unidades del Producto que va a Comprar"<<endl;
        cin>>Cantidad;
        error=ValidarEntero(Cantidad);
        if(error==1)
            return -1;
        if(error==-1)
        {
            i++;
            error_msj(-4,i);
        }
        if (error==0)
        {
            error=setPrecioTotal();
        }

    }
    return error;
};
int DetalleVenta::setPrecioTotal()
{
    int op;
    cout<<"Quedaría un total de :$"<<getImporteTotal();
    cout<<" ¿Desea Modificar la cantidad?"<<endl;
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
        return 2;
    }

    }
};
int GuardarDetalle(DetalleVenta *Obj)
{
    FILE *p;
    p=fopen(ArchivoDetalle,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(Obj,sizeof(DetalleVenta),1, p)!=1)
    {
        fclose(p);
        return -1;
    }
    fclose (p);
    return 0;
}
DetalleVenta::DetalleVenta()
{
     idVenta=0;
     PrecioUnidad=0;
     Cantidad=0;
     PrecioTotal=0;
};
