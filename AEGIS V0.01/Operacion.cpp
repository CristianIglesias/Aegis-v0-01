#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include <ctime>
#include "Operacion.h"
Operacion::Operacion()
{
    setFechaActual();
    ImporteTotal=0;
    ID=0;
}
void Operacion::SetID(int id)
{
    ID=id;
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



