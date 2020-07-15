#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED
#pragma once
#include "PrototiposClases.h"
#include "PrototiposGlobales.h"
#include "Fecha.h"
#include "Producto.h"

class Operacion
{
protected:
    int ID;
    Fecha fechaOperacion;
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
