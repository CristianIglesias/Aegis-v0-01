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
    void setNombre(const char *n)
    {
        strcpy(Nombre,n);
    }
    void setApellido(const char *a)
    {
        strcpy(Apellido,a);
    }
    void  setFecha(Fecha aux)
    {
        FechaNacimiento=aux;
    }
    void setTelefono(const char * tel)
    {
        strcpy(nTelefono,tel);
    }
    void setEmail   (const char * email)
    {
        strcpy(Mail,email);
    }
    void setnDoc    (const char * ndoc)
    {
        strcpy(Documento,ndoc);
    }

    void setEstado(bool nuevoestado )
    {
        Estado=nuevoestado;
    };
};

Persona MenuModificarPersona();///eso, te permite modificar a la persona.




#endif // PERSONA_H_INCLUDED
