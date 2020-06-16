#include <iostream>
#include <cstring>
using namespace std;
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
    cout<<" "<<endl;
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
        cin.getline(Documento,10);

        ///error=(ValidarDocumento(getndoc()
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
    for (int i=0; i<3; i++)
    {
        cout<<"Ingrese Correo Electronico :"<<endl;
        cout<<"EMAIL :";
        cin.getline(Mail,50);
        error=ValidarMail(getEmail());
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
    for(i=0; i<3; i++)
    {
        cout<<"Y Para completar la parte uno del ingreso de datos, Ingrese su Numero de Teléfono"<<endl;
        cout<<"Teléfono :";
        cin.getline(nTelefono,10);
        ///error=ValidarTeléfono(getnTelefono);
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


}









int Persona:: ValidarMail(const char *Mail)
{
    int tam=strlen(Mail), pos;
    char *poschar;
    if(Mail[0]=='@'||Mail[0]=='.')
    {
        return -3;   ///Que no empiece ni con arroba ni con punto
    }
    poschar=strchr(Mail,'@');
    if(poschar==NULL)
    {
        return-3;   ///que tenga un arroba
    }
    if(strrchr(Mail,'@')!=poschar)
    {
        return -3;   ///que solo tenga UN arroba
    }
    pos=poschar-Mail;
    if((isalnum(Mail[pos+1]!=0))&&(isalnum(Mail[pos-1]!=0)))
    {
        return-3;   ///Que tenga chares alfanumericos al rededor de arroba.
    }
    poschar=strchr(Mail,'.');          ///Que tenga un punto
    if(poschar==NULL)
    {
        return -3;
    }
    pos=Mail-poschar;
    if(Mail[pos+1]=='.')
    {
        return-3;   ///Que no tenga dos seguidos
    }

    if(Mail[tam-1]=='.')
    {
        return-3;   ///que no termine en punto.
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
            if( Anio % 4 == 0 && Anio % 100 != 0 || Anio % 400 == 0 )
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

/*char Nombre[20];
  char Apellido[20];
  int Dia, Mes, Anio;
  char Documento[10];
  char Mail[50];
  bool Estado;
  char Ndoc[8];
  char nTelefono[10];*/

