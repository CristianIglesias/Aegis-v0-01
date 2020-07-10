#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED
#include "Producto.h"
#include "PrototiposGlobales.h"

class Operacion
{
public:
    Operacion();
    Fecha getFechaOperacion()
    {
        return fechaOperacion;
    }
    float getImporteTotal()
    {
        return ImporteTotal;
    }
    float setImporteTotal();
protected:
    int ID;
    Fecha fechaOperacion;
    float ImporteTotal;
    int setFechaActual();
};


#endif // OPERACION_H_INCLUDED
