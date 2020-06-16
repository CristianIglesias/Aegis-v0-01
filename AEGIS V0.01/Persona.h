#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <cstring>

#pragma once
class Persona
{
protected:
    char Nombre[20];
    char Apellido[20];
    int Dia, Mes, Anio;
    char Documento[10];
    char Mail[50];
    bool Estado;
    char Ndoc[8];
    char nTelefono[10];
public:
    void Cargar();
    void Mostrar();
    int ValidarMail(const char *Mail);
    int ValidarFecha(int Dia,int Mes,int Anio);




    const char * getNdoc()
    {
        return Ndoc;
    }
    const char * getNombre()
    {
        return Nombre;
    }
    const char * getApellido()
    {
        return Apellido;
    }
    int getDia()
    {
        return Dia;
    }
    int getMes()
    {
        return Mes;
    }
    int getAnio()
    {
        return Anio;
    }
    const char * getTelefono()
    {
        return nTelefono;
    }
    const char * getEmail()
    {
        return Mail;
    }
    void setNdoc(char *n)
    {
        strcpy(Ndoc,n);
    }
    void setNombre(char *n)
    {
        strcpy(Nombre,n);
    }
    void setApellido(char *a)
    {
        strcpy(Apellido,a);
    }
    void setDia(int d)
    {
        Dia=d;
    }
    void setMes(int m)
    {
        Mes=m;
    }
    void setAnio(int a)
    {
        Anio=a;
    }
    void setTelefono(char *tel)
    {
        strcpy(nTelefono,tel);
    }
    void setEmail(char *e)
    {
        strcpy(Mail,e);
    }
    void setEstado(bool nuevoestado )
    {
        Estado=nuevoestado;
    };
};

#endif // PERSONA_H_INCLUDED
