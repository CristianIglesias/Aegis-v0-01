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

void Venta:: GenerarVenta()
{
    GenerarIdVenta();
    SetIdVendedor();
    SetIdCliente();
    DetalleVenta  Det;

};

int Venta:: SetIdVendedor()
{

};

int Venta:: SetIdCliente()
{

};

int Venta:: GetIdVendedor()
{

};

int Venta:: GetIdCliente()


{};



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




















//    cout<<"LEGAJO DE VENDEDOR QUE REALIZARA LA VENTA:"<<endl;
///    cin>>Vendedor->legajo;





///TODO DALE MAN MEDIA PILA.

/// -ingresa legajo de vendedor, reconoce que vendedor del archivo es, muestra solo nombre y apellido.
/// -fecha de venta se ingresa///LA SACA DEL SISTEMA. habr�a que usar ctime.
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
