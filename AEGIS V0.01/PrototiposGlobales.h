#ifndef PROTOTIPOSGLOBALES_H_INCLUDED
#define PROTOTIPOSGLOBALES_H_INCLUDED
#pragma once

class Fecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha(int d=0,int m=0,int a=0);
    int getDia()
    {
        return dia;
    }
    int getMes()
    {
        return mes;
    }
    int getAnio()
    {
        return anio;
    }
    void setDia(int d)
    {
        dia=d;
    }
    void setMes(int m)
    {
        mes=m;
    };
    void setAnio(int a)
    {
        anio=a;
    }

};


int ValidarTexto(const char *cad );





void ListarClientes();
void listarProductos();



#endif // PROTOTIPOSGLOBALES_H_INCLUDED
