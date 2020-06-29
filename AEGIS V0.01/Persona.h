#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <cstring>

#pragma once
class Persona
{
protected:
    char Nombre[50];
    char Apellido[50];
    int Dia, Mes, Anio;
    char Documento[9];
    char Mail[75];
    bool Estado;
    char nTelefono[11];
public:
    void Cargar();///CARGA PERSONA
    void Mostrar();///MUESTRA PERSONA


    int setNombre();///TODO Sets Nombre-Apellido y Validación de texto en ambas!
    int setApellido();

    int setFecha();
    int ValidarFecha(int Dia,int Mes,int Anio);
    int setTelefono();
    int ValidarTelefono(const char *);
    int setEmail();
    int ValidarMail( char *Mail);
    int setnDoc();
    int ValidarDocumento(const char *);



    const char * getDocumento()
    {
        return Documento;
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
    void setNombre(char *n)
    {
        strcpy(Nombre,n);
    }
    void setApellido(char *a)
    {
        strcpy(Apellido,a);
    }

    void setEstado(bool nuevoestado )
    {
        Estado=nuevoestado;
    };
};
#endif // PERSONA_H_INCLUDED
