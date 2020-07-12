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
    error=SetIdVendedor();
    if(error==1)
        return;
    error=SetIdCliente();
    if(error==1)
        return;
    DetalleVenta Det;
    while(Det.CargarDetalle(this)==0)
    {
    setImporteTotal(Det.getImporteTotal)
    }

};
void Venta:: Mostrar()
{
    cout<<"Venta nro : "<<ID<<"."<<endl;
    cout<<"Fecha de venta : "<<fechaOperacion.getDia()<<"/"<<fechaOperacion.getMes()<<"/"<<fechaOperacion.getAnio()<<endl;
    cout<<"Realizada por el Vendedor nro: "<<IdVendedor;
    cout<<" al Cliente "<<IdCliente<<endl;

}
int Venta:: SetIdVendedor()
{
    Vendedor Vend;
    int error=-1,i=0;
    while(error<0)
    {
        cout<<"Ingrese el ID del vendedor a cargo de esta venta:"<<endl;
        cout<<"ID VENDEDOR: ";
        cin>>IdVendedor;
        error=Vend.LeerxID(getIdVendedor());
        if(error==1)
            return 1;
        if(error==0)
            return 0;
        if(error<0)
            i++;
        error_msj(-5,i);
    }///Cierra while;
    return error;
};

int Venta:: SetIdCliente()
{
    Cliente Cli;
    int error=-1,i=0;
    while(error<0)
    {
        cout<<"Ingrese el ID del Cliente  que quiere comprar:"<<endl;
        cout<<"ID Cliente: ";
        cin>>IdCliente;
        error=Cli.LeerxPos(getIdCliente());
        if(error==1)
            return 1;
        if(error==0)
            return 0;
        if(error<0)
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
    return 0;
};
int Venta :: setImporteTotal(float ImporteDetalle)
{
     ImporteTotal+=ImporteDetalle;
}


















//    cout<<"LEGAJO DE VENDEDOR QUE REALIZARA LA VENTA:"<<endl;
///    cin>>Vendedor->legajo;





///TODO DALE MAN MEDIA PILA.

/// -ingresa legajo de vendedor, reconoce que vendedor del archivo es, muestra solo nombre y apellido.
/// -fecha de venta se ingresa///LA SACA DEL SISTEMA. habría que usar ctime.
/// - pide id del cliente, sino existe sugiere crear o agregar cliente?
/// -ingresar codigo de producto, muestra el producto y pide atributos de (Venta), cantidad etc.
/// -calculo del total con porcentaje de descuento etc..
/// -listado de factura final.

///______________________//POSIBLE FORMATO\\_____________________________
///CALCULO DE LA VENTA:  TOTAL=Producto item * cantidad
///                               NUMEOR DE LA VENTA:(XXX)                           FECHA(XX/XX/XXXX)
///                               LEGAJOVENDEDOR: xxxx
///                               IDCLIENTE: xxxx
///                               TIPO DE PAGO / TIPO DE FACTURA / TIPO DE ENTREGA
///                                ITEM(SUS DATOS//CODIGOPRODUCTO) + IMPORTEUNIDAD
///                                                                                                           IMPORTE TOTTAL
///                                                                                                          %DESCUENTO
///                                                                                                           TOTAL $: xxxx,xx
///----------------------------------------------------------------------------------------
