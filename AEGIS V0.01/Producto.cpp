#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Producto.h"
const char *ArchivoProducto ="Producto.dat";

///juan.agustin.gonzalez99@gmail.com


int Producto:: buscarcodigo(char *codigo)
{
    Producto aux;
    FILE *p;
    p=fopen(ArchivoProducto,"rb");
    if(p==NULL)

        return 1;

    while(fread(&aux,sizeof(Producto),1,p))
    {
        if(strcmp(getCodigoProducto(),aux.getCodigoProducto())==0)
        {
            fclose(p);
            return -1;
        }

    }
    fclose(p);
    return 0;


}

void Producto::cargar()
{

     int i,total;
     ///funcion buscar: arreglar detalles.
    cout<<"CODIGO DEL PRODUCTO:"<<endl;
    cin.ignore();
    cin.getline(CodigoProducto,10);

    i=buscarcodigo(CodigoProducto);

    if(i==0)
    {
        cout<<i<<endl;
        cout<<"CODIGO DE PRODUCTO CARGADO CON EXITO!"<<endl;

    }

    if(i==-1)
    {
        cout<<i<<endl;
        cout<<"ERROR!, CODIGO EXISTENTE"<<endl;
        return;
    }
    if(i==1){
        cout<<"ERROR EN LA APERTURA DEL ARCHIVO"<<endl;
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
int Producto::guardarProducto()
{

    FILE *p;
    p=fopen(ArchivoProducto,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Producto),1,p)!=1);
    {
         fclose(p);
         return -1;
    }
    fclose(p);
    return 0;

}

///LEER EN DISCO
bool Producto::leerProductos(int pos)
{
    bool leyo=false;
    FILE *p;
    p=fopen(ArchivoProducto,"rb");
    if(p==NULL)
    {

        return false;
    }
    if(pos>0)
        {
    fseek(p,pos * sizeof(Producto),0);
    leyo=fread(this,sizeof(Producto),1,p);
        }
    else{leyo=fread(this,sizeof(Producto),1,p);}
    fclose(p);
    return leyo;

}






