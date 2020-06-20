#include <iostream>
#include <cstring>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"
#include "Persona.h"

void Persona::Cargar()
{
    int error,i=0;
    cout<<"Nombre  : ";
    cin.ignore();
    cin.getline(Nombre,20);
    if(Nombre);
    cout<<"Apellido :";
    cin.getline(Apellido,20);
    cout<<""<<endl;
    for (i=0; i<3; i++)
    {
        cout<<"Fecha de nacimiento (d/m/a) "<<endl;
        cin>>Dia;
        cout<<"/";
        cin>>Mes;
        cout<<"/";
        cin>>Anio;

        error=ValidarFecha(getDia(),getMes(),getAnio());
        if(error<0)
        {
            cout<<"Error Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i<<"/3"<<endl;
            if(i==3)
            {
                return;
            }
        }
        else
            break;
    }
    cin.ignore();
    for(i=0; i<3; i++)
    {
        cout<<"Ingrese Numero de Documento : ";
        cin.getline(Documento,8);
        ///error=ValidarDocumento(getDocumento());
       if(error<0)
        {
            cout<<"Error Validando Documento -Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i+1<<"/3"<<endl;
            if(i==3)
            return;
        }
        else
            break;
    }
    for (i=0; i<3; i++)
    {
        cout<<"Ingrese Correo Electronico :"<<endl;
        cout<<"EMAIL :";
        cin.getline(Mail,50);
        error=ValidarMail(Mail);
        if(error<0)
        {
            cout<<"Error Validando Mail -Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i+1<<"/3"<<endl;
            if(i==3)
            {
                return;
            }
        }

        else
            break;
    }
    for(i=0; i<3; i++)
    {
        cout<<"Y Para completar la parte uno del ingreso de datos, Ingrese su Numero de Teléfono"<<endl;
        cout<<"Teléfono :";
        cin.getline(nTelefono,10);
        ///ValidarTelefono(getTelefono);
        if(error<0)
        {
            cout<<"Error Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i<<"/3"<<endl;
            if(i==3)
                return;
        }

        else
            break;

    }
    Estado=true;

}


void Persona :: Mostrar()
{
    cout<< Apellido<<", "<<Nombre<<" Cumple años el "<<Dia<<" del "<<Mes<<endl;
    cout<<"Su Número de Documento es:" <<Documento<<endl;
    cout<<"Su Número de Teléfono es :"<<nTelefono<<endl;
    cout<<"Su Email es :"<<Mail<<endl;
}


int Persona :: ValidarDocumento( char *Ndoc)
{
    int i;
    bool flag=true;
    for (i=0; i<8; i++)
    {
        if (Ndoc[i]-48>=0&&Ndoc[i]-48<=9)
        {
            flag=false;
            return -1;
        }
    }///valida que acepte solo numeros
   return 1;
};
int Persona :: ValidarTelefono( char *Telefono)
{
    int i;
    bool flag=true;
    for (i=0; i<10; i++)
    {
        if (Telefono[i]-48>=0&&Telefono[i]-48<=9)
        {
            flag=false;
            return -1;
        }
    }
    return 1;

};


int Persona:: ValidarMail( char *Mail)
{
    int tam=strlen(Mail), pos;
    char *poschar;
    if(Mail[0]=='@'||Mail[0]=='.')
    {
        return -1;   ///Que no empiece ni con arroba ni con punto
    }
    poschar=strchr(Mail,'@');
    if(poschar==NULL)
    {
        return-2;   ///que tenga un arroba
    }
    if(strrchr(Mail,'@')!=poschar)
    {
        return -3;   ///que solo tenga UN arroba
    }
    pos=poschar-Mail;
    if((isalnum(Mail[pos+1]!=0))&&(isalnum(Mail[pos-1]!=0)))
    {
        return-4;   ///Que tenga chares alfanumericos al rededor de arroba.
    }
    poschar=strchr(Mail,'.');          ///Que tenga un punto
    if(poschar==NULL)
    {
        return -5;
    }
    pos=Mail-poschar;
    if(Mail[pos+1]=='.')
    {
        return-6;   ///Que no tenga dos seguidos
    }

    if(Mail[tam-1]=='.')
    {
        return-7;   ///que no termine en punto.
    }
    return 1;
}

int Persona :: ValidarFecha(int Dia,int Mes, int Anio)
{
    if((Mes>0&&Mes<13)&&(Anio>1920&&Anio<=2020))
    {
        switch(Mes)
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( Dia >= 1 && Dia <= 31 )
            {
                return 1;
            }
            else
            {
                return -1;
            }
        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( (Dia >= 1) && (Dia <= 30) )
            {

                return 1;
            }
            else
                return -1;
        case  2 :
            if( (Anio % 4 == 0 && Anio % 100 != 0 )|| (Anio % 400 == 0 ))
                if ( Dia >= 1 && Dia <= 29 )
                {

                    return 1 ;
                }
                else
                {
                    return -1;
                }
            else if ( Dia >= 1 && Dia <= 28 )
            {
                return 1;
            }
            else
            {
                return -1;
            }

        }
    }
    else
    {

        return -1;
    }
    return -1;
};
