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

    error=setFecha();///TODO Salida voluntaria de usuario
    if(error==1)
        {return;}

    error=setnDoc();
    if(error==1)
    {
        return;
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
        cout<<"Y Para completar la parte uno del ingreso de datos, Ingrese su Numero de Tel�fono"<<endl;
        cout<<"Tel�fono :";
        cin.getline(nTelefono,10);
///TODO        ValidarTelefono(getTelefono);
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
    cout<< Apellido<<", "<<Nombre<<" Cumple a�os el "<<Dia<<" del "<<Mes<<endl;
    cout<<"Su N�mero de Documento es:" <<Documento<<endl;
    cout<<"Su N�mero de Tel�fono es :"<<nTelefono<<endl;
    cout<<"Su Email es :"<<Mail<<endl;
}
int Persona :: setFecha()
{   int error=0,i=0;
    while (error!=1)
    {
        cout<<"Ingrese la Fecha de Nacimiento"<<endl;
        cout<<"Fecha de nacimiento (d/m/a):"<<endl;
        cin>>Dia;
        cout<<"/";
        cin>>Mes;
        cout<<"/";
        cin>>Anio;

        error=ValidarFecha(getDia(),getMes(),getAnio());
        if (error<0)
        {   i++;
            cout<<"Error Nro:"<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i<<"."<<endl;
            if(i>3)
            {
                cout<<"Si no pod�s y quer�s salir, ingres� 0-0-0"<<endl;
            }
            anykey();
            cls();
        }
        else
            break;
    }
    return error;
}
int Persona :: setnDoc()
{
    int error=0,i=0;
    while(error!=1)
    {
        cout<<"Ingrese Numero de Documento : ";
        cin.getline(Documento,9);
        error=ValidarDocumento(getDocumento());
        if(error<0)
        {   i++;
            cout<<"Error Validando Documento -Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i<<"/3"<<endl;
            if(i==3)
            {
                cout<<"Si no pod�s y quer�s salir, ingres� 0"<<endl;
            }
        }
        else
                        break;
    }
}
int Persona :: setTelefono(){};
int Persona :: setEmail(){};



int Persona :: ValidarDocumento( const char *Ndoc)///valida que acepte solo numeros
{
    int i,cont=0;
    bool flag=true;
    for (i=1; i<9 ; i++)
    {
        if (Ndoc[i-1]>47&&Ndoc[i-1]-48<=9)
        {
            flag=false;
            return -1;
        }
    }
    for (i=1;i<9;i++)
    {
        if(Ndoc[i-1]=='0')
        {

        }
    }
    return 1;
};
int Persona :: ValidarTelefono( const char *Telefono)///valida que acepte solo numeros
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
int Persona:: ValidarMail( char *Mail)///valida una banda de cosas.
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

int Persona :: ValidarFecha(int Dia,int Mes, int Anio)///todo lo que una vez no quise hacer y copie de internet xD
{
    if(Mes==0&&Dia==0&&Anio==0)
        return 1;
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

