#ifndef PROTOTIPOSGLOBALES_H_INCLUDED
#define PROTOTIPOSGLOBALES_H_INCLUDED
#pragma once
class Fecha
{
protected:
    int dia;
    int mes;
    int anio;
public:
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

int ValidarFloats(float);


void ListarClientes();
void listarProductos();
void listarProveedores();
void ListarVendedores();


#endif // PROTOTIPOSGLOBALES_H_INCLUDED
