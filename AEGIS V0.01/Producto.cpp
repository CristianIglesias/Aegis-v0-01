#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "Producto.h"
const char *ArchivoProducto ="Producto.dat";


int Producto:: buscarcodigo(char *codigo)
{
    Producto aux;
    FILE *p;
    p=fopen(ArchivoProducto,"rb");
    if(p==NULL)
        return 1;

    while(fread(&aux,sizeof(Producto),1,p))
    {
        if(getCodigoProducto()==aux.getCodigoProducto())
        {
            return -1;
            fclose(p);
        }

    }

    fclose(p);

}

void Producto::cargar()
{

    int i,total;
///funcion buscar: arreglar, para que me permita ingresar primero
    cout<<"CODIGO DEL PRODUCTO:"<<endl;
    cout<<i<<endl;
    cin.ignore();
    cin.getline(CodigoProducto,10);
    i=buscarcodigo(CodigoProducto);
    if(i==0)
    {
        cout<<i<<endl;
        cout<<"PRODUCTO CARGADO CON EXITO!"<<endl;

    }
    else if(i<0)
    {
        cout<<i<<endl;
        cout<<"ERROR, CODIGO EXISTENTE"<<endl;
        return;
    }

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
total=CostodeCompra*(PorcentajeRentabilidad/100)+CostodeCompra;
PreciodeVenta=total;
    cout<<"PRECIO DE VENTA:"<<PreciodeVenta<<endl;



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

    guardarProducto();

}

void Producto::mostrar()
{
    cout<<"CODIGO DE PRODUCTO:"<<CodigoProducto<<endl;
    cout<<"NOMBRE:"<<NombreItem<<endl;
    cout<<"CODIGO PROVEEDOR:"<<CodigoProveedor<<endl;
    cout<<"COSTO:"<<CostodeCompra<<endl;
    cout<<"% RENTABILIDAD:"<<PorcentajeRentabilidad<<endl;
    cout<<"PRECIO VENTA:"<<PreciodeVenta<<endl;
    cout<<"STOCK MINIMO:"<<StockMin<<endl;
    cout<<"STOCK ACTUAL:"<<StockActual<<endl;
}

///GUARDAR EN DISCO
bool Producto::guardarProducto()
{
    bool escribio;
    FILE *p;
    p=fopen("Producto.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    escribio=fwrite(this,sizeof(Producto),1,p);
    fclose(p);
    return escribio;
}

///LEER EN DISCO
bool Producto::leerProductos(int pos)
{

    bool leyo;
    FILE *p;
    p=fopen("Productos.dat","rb");
    if(p==NULL)
    {

        return false;
    }
    fseek(p,pos * sizeof(Producto),0);
    leyo=fread(this,sizeof(Producto),1,p);
    fclose(p);
    return leyo;

}








