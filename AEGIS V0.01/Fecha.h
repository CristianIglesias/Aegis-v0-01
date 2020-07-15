#ifndef FECHA_H
#define FECHA_H
#include <iostream>
class Fecha
{
protected:
    int dia;
    int mes;
    int anio;
public:
    Fecha();
    ///  int ValidarFecha(Fecha FechaAux);
    int CargarFecha();
    int ValidarFecha();
    void setFecha(Fecha reg);
    int getDia()
    {
        return dia;
    };
    int getMes()
    {
        return mes;
    };
    int getAnio()
    {
        return anio;
    };

    void setDia(int d)
    {
        dia=d;
    };
    void setMes(int m)
    {
        mes=m;
    };
    void setAnio(int a)
    {
        anio=a;
    };
};
void AsignarOrdenaFechas(Fecha *reg1,Fecha *reg2);



#endif // FECHA_H
