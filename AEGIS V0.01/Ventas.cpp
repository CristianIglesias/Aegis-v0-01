#include <iostream>
using namespace std;
#include "FuncionesGlobales.h"
#include "Ventas.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Vendedor.h"
#include "Clientes.h"

const char *ArchivoVenta ="Ventas.dat";

void Venta::cargar()
{
    cout<<"LEGAJO DE VENDEDOR QUE REALIZARA LA VENTA:"<<endl;
///    cin>>Vendedor->legajo;



}

///TODO DALE MAN MEDIA PILA.

/// -ingresa legajo de vendedor, reconoce que vendedor del archivo es, muestra solo nombre y apellido.
/// -fecha de venta se ingresa.
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
