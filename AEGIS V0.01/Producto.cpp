#include <iostream>
#include <cstring>
using namespace std;
#include "Producto.h"
#include <cstdio>

/*int buscarcodigo(char *codigo)
{
    char aux[10]
    FILE *p;
    p=fopen("Productos.dat",wb)
    if(p==NULL) return;

    while(fread((&aux,sizeof(Producto),1,p)==1))
    {
        if(codigo==aux)
        {
            return -1;
        }

    }
    return 0;
}
*/

const char *ArchivoProducto ="Producto.dat";

void Producto::cargar()
{
   int i;
    cout<<"CODIGO DEL PRODUCTO:"<<endl;

     cin.getline(CodigoProducto,10);
/*  i=buscarcodigo(CodigoProducto)
       if(i==-1)
       {
        cout<<"ERROR, CODIGO EXISTENTE"<<endl;
        return;
        }
        else if(i==0)
        {
        cout<<"PRODUCTO CARGADO CON EXITO!"<<endl;
        }
*/

    cout<<"CODIGO DE PROVEEDOR:"<<endl;
    cin.getline(CodigoProveedor,10);

    cout<<"NOMBRE DEL PRODUCTO:"<<endl;
    cin.getline(NombreItem,30);

    cout<<"COSTO DE COMPRA:"<<endl;
    cin>>CostodeCompra;
    if(CostodeCompra<=0)
    {
        cout<<"ERROR!, el costo no puede ser menor a 0"<<endl;
        return;
    }

    cout<<"% RENTABILIDAD:"<<endl;
    cin>>PorcentajeRentabilidad;
     if(PorcentajeRentabilidad<=0)
    {
        cout<<"ERROR!, el porcentaje de retabilidad no puede ser menor a 0"<<endl;
        return;
    }

    cout<<"PRECIO DE VENTA:"<<endl;
    cin>>PreciodeVenta;
    if(PreciodeVenta<=0)
    {
        cout<<"ERROR!, el precio de venta no puede ser menor a 0"<<endl;
        return;
    }

    cout<<"STOCK MINIMO:"<<endl;
    cin>>StockMin;
    if(StockMin<=0)
    {
        cout<<"ERROR!, el stock minimo no puede ser menor a 0"<<endl;
        return;
    }

    cout<<"STOCK ACTUAL:"<<endl;
    cin>>StockActual;
    if(StockActual<=0)
    {
        cout<<"ERROR!, el stock actual no puede ser menor a 0"<<endl;
        return;
    }

    Estado=true;
}



