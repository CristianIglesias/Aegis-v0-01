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

    while(fread(&aux,sizeof(Producto),1,p)==1)
    {
        if(getCodigoProducto()==aux.getCodigoProducto())
        {
            return -1;
        }
    }
    return 0;
}

void Producto::cargar()
{

    int i;
///funcion buscar: arreglar, para que me permita ingresar primero

    cout<<"CODIGO DEL PRODUCTO:"<<endl;
    cin.ignore();
    cin.getline(CodigoProducto,10);
    i=buscarcodigo(CodigoProducto);
    if(i==0)
    {
        cout<<i<<endl;
        cout<<"PRODUCTO CARGADO CON EXITO!"<<endl;

    }
    if(i==-1)
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

    cout<<"PRECIO DE VENTA:"<<endl;
    cin>>PreciodeVenta;
    if(PreciodeVenta<=0)
    {
        cout<<"ERROR! el precio de venta no puede ser menor a 0"<<endl;
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

///¿como pasar el producto que cargue anteriormente?
bool Producto::guardarProducto()
{
    ///Producto aux=this;
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

///leer lee en el archivo para luego mostrar todos los productos.
///TERMINAR.
void Producto::leerProductos()
{

    FILE *p;
    p=fopen("Productos.dat","rb");
    if(p==NULL)
    {

        return ;
    }
    fread(this,sizeof(Producto),1,p);
    fclose(p);
    return ;

}

void Producto::mostrar()
{
    cout<<""<<endl;
    cout<<"CODIGO DE PRODUCTO:"<<CodigoProducto<<endl;
    cout<<"NOMBRE:"<<NombreItem<<endl;
    cout<<"CODIGO PROVEEDOR:"<<CodigoProveedor<<endl;
    cout<<"COSTO:"<<CostodeCompra<<endl;
    cout<<"% RENTABILIDAD:"<<PorcentajeRentabilidad<<endl;
    cout<<"PRECIO VENTA:"<<PreciodeVenta<<endl;
    cout<<"STOCK MINIMO:"<<StockMin<<endl;
    cout<<"STOCK ACTUAL:"<<StockActual<<endl;

}

void Producto::listarProductos()
{
    int cant=cantidad_productos();
    cout<<"_________LISTADO DE PRODUCTOS____________"<<endl;
    for(int i=0; i<cant; i++)
    {
        leerProductos();
        mostrar();
        cout<<endl;
    }

}

int Producto::cantidad_productos()//Cuenta la cantidad de productos para luego listarlos.
{
    int bytes,cr;
    FILE *p;
    p=fopen("Producto.dat","rb");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    cr=bytes/sizeof(this);
    fclose(p);
    return cr;
}


