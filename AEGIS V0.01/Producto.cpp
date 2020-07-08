#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "Producto.h"
#include "Proveedor.h"
#include "PrototiposGlobales.h"
#include "rlutil.h"
using namespace rlutil;
const char *ArchivoProducto ="Producto.dat";

///juan.agustin.gonzalez99@gmail.com

void Producto::cargar()
{
    Estado=false;
    int error;

    error=setCodigoproducto();
    if(error==1)
        return;


    error=setCodigoProveedor();
    if(error==1)
        return;


    error=setNombreItem();
    if(error==1)
        return;


    error=setCostoCompra();
    if(error==1)
        return;



    error=setPorcentajeRentabilidad();
    if(error==1)
        return;


    setPrecioVenta(CostodeCompra,PorcentajeRentabilidad);
    if(error==1)
    return;


    error=setStockMin();
    if(error==1)
        return;


    error=setStockActual();
    if(error==1)
        return;

    Estado=true;
}

int Producto:: buscarcodigo(const char *codigo)
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
int Producto::validarEntero(int c)
{

    if(c<=0)
    {

        return 1;
    }
}

int Producto::setCodigoproducto()
{
    cin.ignore();

    int i=0, error=-3;
    while (error<0)
    {
        cout<<"Ingrese codigo de producto: ";
        cin.getline(CodigoProducto,10);
        error=buscarcodigo(this->getCodigoProducto());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-3,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};

int Producto::setCodigoProveedor()
{
    cin.ignore();
    int i=0, error=-3;
    Proveedor p;
    while (error<0)
    {
        cout<<"Ingrese codigo de proveedor: ";
        cin.getline(CodigoProveedor,10);
        ///error=p.buscarproveedor(this->getCodigoProveedor());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-3,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};


int Producto::setNombreItem()
{
    cin.ignore();

    int i=0, error=-1;
    while (error<0)
    {
        cout<<"Ingrese nombre del producto: ";
        cin.getline(NombreItem,30);
        error=ValidarTexto(this->getNombreItem());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-1,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};


int Producto::setCostoCompra()
{
    cin.ignore();

    int i=0, error=-6;
    while (error<0)
    {
        cout<<"Ingrese el costo de compra: ";
        cin>>CostodeCompra;
        error=validarEntero(getCostodeCompra());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-6,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};

int Producto::setPorcentajeRentabilidad()
{
    cin.ignore();

    int i=0, error=-6;
    while (error<0)
    {
        cout<<"Ingrese el porcentaje de rentabilidad: ";
        cin>>PorcentajeRentabilidad;
        error=validarEntero(getPorcentajeRentabilidad());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-6,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};


int Producto::setPrecioVenta(float costo, int porcentaje)
{
    float venta;
    cin.ignore();
    cout<<"PRECIO DE VENTA: ";
    venta=(costo*porcentaje/100)+costo;
    cout<<venta<<endl;

};

int Producto::setStockMin()
{
    cin.ignore();

    int i=0, error=-6;
    while (error<0)
    {
        cout<<"Ingrese el stock minimo: ";
        cin>>StockMin;
        error=validarEntero(getStockMin());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-6,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};

int Producto::setStockActual()
{
    cin.ignore();

    int i=0, error=-6;
    while (error<0)
    {
        cout<<"Ingrese el stock actual: ";
        cin>>CostodeCompra;
        error=validarEntero(getStockActual());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-6,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};


void Producto::mostrar()
{
    cout<<"-------------------------------"<<endl;
    cout<<"CODIGO DE PRODUCTO:"<<CodigoProducto<<endl;
    cout<<"NOMBRE:"<<NombreItem<<endl;
    cout<<"CODIGO PROVEEDOR:"<<CodigoProveedor<<endl;
    cout<<"COSTO:"<<CostodeCompra<<endl;
    cout<<"% RENTABILIDAD:"<<PorcentajeRentabilidad<<endl;
    cout<<"PRECIO VENTA:"<<PreciodeVenta<<endl;
    cout<<"STOCK MINIMO:"<<StockMin<<endl;
    cout<<"STOCK ACTUAL:"<<StockActual<<endl;
    cout<<"-------------------------------"<<endl;
}

///GUARDAR EN DISCO
int Producto::guardarNuevoProducto()
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

int Producto::ObtenerPosicionProducto(char *codigo)
{
    int c=0;
    Producto aux;
    FILE *p;
    p=fopen(ArchivoProducto,"rb+");
    if(p==NULL)
    {
        return -1;
    }
    while(fread(&aux,sizeof(Producto),1,p))
    {
        if(strcmp(aux.CodigoProducto,codigo)==0)
        {
            fclose(p);
            return c;
        }
        c++;
    }
    fclose(p);
    return -1;
}


int Producto::guardarProducto()
{
    int pos=0;
    pos=ObtenerPosicionProducto(this->CodigoProducto);
    if(pos<0)
    {
        return -1;
    }
    FILE *p;
    p=fopen(ArchivoProducto,"rb+");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,sizeof(Producto)*pos,SEEK_SET);
    fwrite(this,sizeof(Producto),1,p);
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
    else
    {
        leyo=fread(this,sizeof(Producto),1,p);
    }
    fclose(p);
    return leyo;

}

void Producto::modificar_producto()///arreglar solo modifica el primer producto;
{
    int op;
    int error=-1;
    Producto p;
    p.mostrarxID();
    anykey();
    cout<<"¿Que desea modificar:?"<<endl;
    cout<<"1--> Costo de compra"<<endl;
    cout<<"2--> Stock actual"<<endl;
    cout<<"3--> % de rentabilidad"<<endl;
    cout<<"9--> VOLVER"<<endl;
    cin>>op;
    switch(op)
    {
    case 1:

        {
            cls();
              error=setCostoCompra();
              if(error==1)
              {
                   return;
              }

              else

              {
                cout<<"entro"<<endl;
                guardarProducto();
              }


                 if(error==0)
              {
                cout<<"Hubo un error Guardando el Producto en el Archivo."<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
              }
            else
            {
                cout<<"Producto Guardado en el Archivo con Exito!"<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }


        }break;
         case 2:

        {
            cls();
              error=setStockActual();
              if(error==1)
              {
                   return;
              }
               else
              {
                cout<<"entro"<<endl;
                error=guardarProducto();
              }


                 if(error==0)
              {
                cout<<"Hubo un error Guardando el Producto en el Archivo."<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
              }
            else
            {
                cout<<"Producto Guardado en el Archivo con Exito!"<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }


        }break;
         case 3:

        {
            cls();
              error=setPorcentajeRentabilidad();
              if(error==1)
              {
                   return;
              }

              else

              {
                cout<<"entro"<<endl;
                error=guardarProducto();
              }


                 if(error==0)
              {
                cout<<"Hubo un error Guardando el Producto en el Archivo."<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
              }
            else
            {
                cout<<"Producto Guardado en el Archivo con Exito!"<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }


        }break;
        case 9:

        {
            return;
        }break;
    }

}

bool Producto:: LeerxID(char* id)
{

    FILE *P;
    P=fopen(ArchivoProducto,"rb");
    if(P==NULL)
    {
        return false;
    }

    while(fread(this,sizeof(Producto),1,P)==1)
    {
        if(strcmp(id,CodigoProducto)==0)
        {
            fclose (P);
            return true;
        }

    }

     fclose (P);
    return false;

}

void Producto:: mostrarxID()///Muestra Por ID -
{
    bool funco=false;
    char aux[20];
    int i=1;
    gets(aux);
    while(!funco)
    {

        cout<<"Ingrese el ID Del producto Con el que quiere trabajar,"<<endl;
        cout<<"para que se muestre por pantalla."<<endl;
        gets (aux);
        funco=LeerxID(aux);
        if(funco)
        {
            mostrar();
        }
        else
        {
            error_msj(-5,i++);
        }
    }
}


