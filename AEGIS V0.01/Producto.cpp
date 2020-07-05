#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "Producto.h"
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
    return;


    error=setStockMin();
    if(error==1)
        return;


    error=setStockActual();
    if(error==1)
        return;

    Estado=true;
}

int Producto::buscarproveedor(const char *codigo)
{
    Producto aux;
    FILE *p;
    p=fopen(ArchivoProducto,"rb");
    if(p==NULL)

        return 1;

    while(fread(&aux,sizeof(Producto),1,p))
    {
        if(strcmp(getCodigoProveedor(),aux.getCodigoProveedor())==0)
        {
            fclose(p);
            return -1;
        }

    }
    fclose(p);
    return 0;

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
int Producto::validarEntero(float c)
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
    while (error<0)
    {
        cout<<"Ingrese codigo de proveedor: ";
        cin.getline(CodigoProveedor,10);
        error=buscarproveedor(this->getCodigoProveedor());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-4,i);
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
    venta=porcentaje/100*costo;
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
    else
    {
        leyo=fread(this,sizeof(Producto),1,p);
    }
    fclose(p);
    return leyo;

}

bool Producto::sobrescribir(int pos)///Funcion que abre el archivo para escribir los nuevos datos modificados;
{

    bool escribio;
    FILE *p;
    p = fopen(ArchivoProducto, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, pos * sizeof(Producto), SEEK_SET);
    escribio = fwrite(this, sizeof(Producto), 1, p);
    fclose(p);
    return escribio;
}


void Producto::modificar_producto()///arreglar solo modifica el primer producto;
{
    cout<<"ENTRO"<<endl;
    char id_buscado[20];
    int pos;
    cout << "ID a modificar: ";
    cin.ignore();
    cin.getline(id_buscado,20);
    pos =buscarcodigo(id_buscado);
    if (pos >= 0)
    {

        pos=leerProductos(pos);
        cout << endl;
        Producto::mostrar();
        cout << endl << "Ingrese el nuevo costo: ";
        cin >> CostodeCompra;
        cout<<"Ingrese el stock actual: ";
        cin>>StockActual;

        if (sobrescribir(pos))
        {
            cout << "Producto modificado."<<endl;
        }
        else
        {
            cout << "No se modificó el producto.";
        }
    }
    else
    {
        cout << "No existe el producto.";
    }
}




