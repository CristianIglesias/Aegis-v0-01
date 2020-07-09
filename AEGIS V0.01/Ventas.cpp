#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include <ctime>
#include "PrototiposGlobales.h"
#include "Ventas.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Vendedor.h"
#include "Clientes.h"

const char *ArchivoVentas ="Ventas.dat";
const char *ArchivoCompras ="Compras.dat";
const char *ArchivoNotasCred ="NotasCred.dat";


void Operacion ::GenerarIdVenta()
{
    int cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoVentas,"rb");
    if(p==NULL)
    {
        numeroOperacion=-1;
        return;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Operacion);

    numeroOperacion=cantRegistros+1;
    fclose(p);
    return;
};

void Operacion ::GenerarIdCompra()
{
    int cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoCompras,"rb");
    if(p==NULL)
    {
        numeroOperacion=-1;
        return;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Operacion);

    numeroOperacion=cantRegistros+1;
    fclose(p);
    return;};

void Operacion ::GenerarIdNotaCred()
{
    int cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoNotasCred,"rb");
    if(p==NULL)
    {
        numeroOperacion=-1;
        return;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Operacion);

    numeroOperacion=cantRegistros+1;
    fclose(p);
    return;};






















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
