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
const char *ArchivoVentas ="Ventas.dat";


/// A SABER
/// ERROR=0-TA TODO PIOLA, SIGUE ADELANTE
/// ERROR=1-SALIDA VOLUNTARIA, CLAVA RETURN PERRI
/// ERROR<0-SIGUE INTENTANDO, TRANK PALANK


void Venta:: GenerarVenta()
{
    int error=-1;
    SetID(GenerarIdVenta());
    cout<<"ID de venta : "<<getID()<<endl;
    error=SetIdVendedor();
    if(error!=0)
        return;
    error=SetIdCliente();
    if(error==1)
        return;
    DetalleVenta Det;
    while(error==0)
    {
        error=Det.CargarDetalle(this);
        setImporteTotal(Det.getImporteTotal());
    }
    cout<<"El Importe final de la Operación es: "<<getImporteTotal()<<endl;
    error=GuardarVenta();
    if(error!=0)
    {
        cout<<"Hubo un error Guardando la Venta en el Archivo."<<endl;
        cout<<"Ingrese cualquier tecla para continuar"<<endl;
        anykey();
    }
    else
    {
        cout<<"Venta Guardada en el Archivo con Exito!"<<endl;
    }


};
void Venta:: Mostrar()
{
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Venta nro: "<<ID<<"."<<endl;
    cout<<"Fecha de venta: "<<fechaOperacion.getDia()<<"/"<<fechaOperacion.getMes()<<"/"<<fechaOperacion.getAnio()<<endl;
    cout<<"Vendedor nro: "<<IdVendedor<<endl;
    cout<<"Cliente nro "<<getIdCliente()<<endl;
    cout<<"Importe final  $ : "<< ImporteTotal<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;

}
int Venta:: SetIdVendedor()
{
    Vendedor Vend;
    int error=-1,i=0,op;
    while(error!=0)
    {
        cout<<"Ingrese el ID del vendedor a cargo de esta venta:"<<endl;
        cout<<"ID VENDEDOR: ";
        cin>>IdVendedor;
        error=Vend.leerVendedor(IdVendedor);
        if(error==0)
            return -1;
        if(error==-1)
        {
            i++;
            error_msj(-5,i);
        }
        if(error==1)///funcion confirmar elección.
        {
            cout<<"El Vendedor deseado es : "<<Vend.getNombre()<<" ?"<<endl;
            cout<<"SI :1             NO:0"<<endl;
            cin>>op;
            switch(op)
            {
            case 1:
                return 0;
                break;
            case 0:
                error=-2;
                break;
            }
        }

    }///Cierra while
    return error;
};

int Venta:: SetIdCliente()
{
    Cliente Cli;
    int error=-1,i=0,op;
    while(error<0)
    {
        cout<<"Ingrese el ID del Cliente  que realiza la compra:"<<endl;
        cout<<"ID Cliente: ";
        cin>>op;
        error=Cli.LeerxPos(op);
        if(error==1)
            return 1;
        if(error==0)
        {
            cout<<"El Cliente deseado es : "<<Cli.getNombre()<<" ?"<<endl;
            cout<<"SI :1             NO:0"<<endl;
            cin>>op;
            switch(op)
            {
            case 1:
                SetIdCliente(Cli.GetidCliente());
                return error;
                break;
            case 0:
                error=-2;
                break;
            }

        }
        if(error==-1)
            i++;
        error_msj(-5,i);
    }///Cierra while;
    return error;
};

int GenerarIdVenta()
{
    int id, cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoVentas,"rb");
    if(p==NULL)
    {
        return-1;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Venta);

    id=cantRegistros+1;
    fclose(p);
    return id;
};
void Venta :: setImporteTotal(float ImporteDetalle)
{
    ImporteTotal+=ImporteDetalle;
}

int Venta:: GuardarVenta()
{
    FILE *p;
    p=fopen(ArchivoVentas,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Venta),1, p)!=1)
    {
        fclose(p);
        return -1;
    }
    fclose (p);
    return 0;
};

















//    cout<<"LEGAJO DE VENDEDOR QUE REALIZARA LA VENTA:"<<endl;

///_________________________________________________________________//POSIBLE FORMATO\\_____________________________
///                               NUMEOR DE LA VENTA:(XXX)                           FECHA(XX/XX/XXXX)
///                               LEGAJOVENDEDOR: xxxx                                  IDCLIENTE: xxxx
///
///                               -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T
///                               -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T
///                               -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T
///                               -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T
///                               -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T
///                               TIPO DE PAGO: x / TIPO DE FACTURA: x
///                                                                                 IMPORTE TOTTAL
///                                                                                %DESCUENTO
///                                                                                 TOTAL $: xxxx,xx
///----------------------------------------------------------------------------------------
