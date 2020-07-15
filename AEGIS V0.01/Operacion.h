#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED
#pragma once
#include "PrototiposGlobales.h"
#include "Producto.h"

class Operacion
{
protected:
    int ID;
    class Fecha fechaOperacion;
    float ImporteTotal;
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
};


#endif // OPERACION_H_INCLUDED
