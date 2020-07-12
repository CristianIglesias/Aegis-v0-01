#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED
#include "Producto.h"
#include "PrototiposGlobales.h"

class Operacion
{
public:
    Operacion();
    void SetID(int id);
    Fecha getFechaOperacion()
    {
        return fechaOperacion;
    }
    float getImporteTotal()
    {
        return ImporteTotal;
    }
    float setImporteTotal();
    int setFechaActual();
    int getID()
    {
        return ID;
    };
protected:
    int ID;
    Fecha fechaOperacion;
    float ImporteTotal;

};


#endif // OPERACION_H_INCLUDED
