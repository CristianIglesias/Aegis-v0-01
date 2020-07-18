#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Vendedor.h"
#include "Operacion.h"
#include "Compras.h"
const char *ArchivoCompras ="Compras.dat";

int GenerarIdCompra()
{
    int cantRegistros=0, id;
    FILE *p;
    p=fopen(ArchivoCompras,"rb");
    if(p==NULL)
    {fclose(p);
        return-1;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Compra);
    id=cantRegistros+1;
    fclose(p);
    return 0;
};
