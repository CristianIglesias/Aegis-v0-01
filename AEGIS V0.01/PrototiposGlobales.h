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

void error_msj(int cod,int i);

int ValidarTexto(const char *cad );

int ValidarEnteros( const char *Telefono);



void ListarClientes();
void listarProductos();
void listarProveedores();


#endif // PROTOTIPOSGLOBALES_H_INCLUDED
