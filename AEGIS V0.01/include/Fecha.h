#ifndef FECHA_H
#define FECHA_H


class Fecha
{
protected:
    int dia;
    int mes;
    int anio;
public:
  ///  int ValidarFecha(Fecha FechaAux);
    int CargarFecha();
    int ValidarFecha(Fecha FechaNac);
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
    ///Fecha  getFecha();

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

#endif // FECHA_H
