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

Operacion::Operacion()
{
    setFechaOp();

}

int Operacion:: setFechaActual()
{
    time_t t;
    t=time(NULL);
    struct tm *fecha;
    fecha= localtime(&t);
    fechaOperacion.setAnio (fecha->tm_year+1900);
    fechaOperacion.setDia  (fecha->tm_mday);
    fechaOperacion.setMes  (fecha->tm_mon+1);

};

int Operacion:: setLegajoVend()
{

};

int Operacion:: setIdCliente()
{

};

int Operacion:: setNumeroOp()
{
    switch(TipoOperacion)
    {

    case 1:GenerarIdVenta();
        break;
    case 2:GenerarIdCompra();
        break;
    case 3:GenerarIdNotaCred();
        break;
    default: cout<<"Error Valor de constante no reconocido. Retornando..."<<endl; return-1;
    }
}
