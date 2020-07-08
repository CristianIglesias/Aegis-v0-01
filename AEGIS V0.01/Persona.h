#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "PrototiposGlobales.h"
#pragma once
class Persona
{
protected:
    char Nombre[50];
    char Apellido[50];
    Fecha FechaNacimiento;
    char Documento[9];
    char Mail[75];
    bool Estado;
    char nTelefono[11];
public:
    void Cargar();///CARGA PERSONA
    void Mostrar();///MUESTRA PERSONA
    void MenuModificarPersona();///eso, te permite modificar a la persona.

    int setNombre();
    int setApellido();

    int setFecha();
    int ValidarFecha(Fecha FechaNacimiento);
    int setTelefono();
    int setEmail();
    int ValidarMail( char *Mail);
    int setnDoc();



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

    const char * getTelefono()
    {
        return nTelefono;
    }
    const char * getEmail()
    {
        return Mail;
    }
    Fecha GetFechaNac()
    {
        return FechaNacimiento;
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
