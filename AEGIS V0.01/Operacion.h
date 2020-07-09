#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED
#include "Producto.h"
#include "PrototiposGlobales.h"

class Operacion
{
public:
    Operacion();
    int setFechaActual();
   /// void get
   /// void get

protected:
    int ID;                  ///se genera solo. Buscando en base a Tipo Operacion
    Fecha fechaOperacion;
    float ImporteTotal;

};


#endif // OPERACION_H_INCLUDED
