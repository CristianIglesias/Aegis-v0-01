#include <iostream>
#include <cstring>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"
#include "Persona.h"
///IOMANIP ///setw();
/// A SABER
/// ERROR=0-TA TODO PIOLA, SIGUE ADELANTE
/// ERROR=1-SALIDA VOLUNTARIA, CLAVA RETURN PERRI
/// ERROR<0-SIGUE INTENTANDO, TRANK PALANK

void Persona::Cargar()
{
    Estado=false;
    int error;

    error=setApellido();
    if(error==1)
        return;
    error= setNombre();
    if(error==1)
        return;
    error=setFecha();
    if(error==1)
        return;
    error=setnDoc();
    if(error==1)
        return;
    error=setTelefono();
    if(error==1)
        return;
    error=setEmail();
    if (error==1)
        return;
    Estado=true;
}


void Persona :: Mostrar()
{
    cout<< Apellido<<", "<<Nombre<<" Cumple años el "<<Dia<<" del "<<Mes<<endl;
    cout<<"Su Número de Documento es:" <<Documento<<endl;
    cout<<"Su Número de Teléfono es :"<<nTelefono<<endl;
    cout<<"Su Email es :"<<Mail<<endl;
}
void Persona :: MenuModificarPersona()
{
    int op;
    bool salir=false;

    while(!salir)
    {   int error=-1;
        setColor(GREEN);
        system("cls");
        cout<<"              Qué Campo desea Modificar de la Persona?"<<endl;
        cout<<"                  _________________________________   "<<endl;
        cout<<"                 |-1-->Nombre.                    -|  "<<endl;
        cout<<"                 |-2-->Apellido.                  -|  "<<endl;
        cout<<"                 |-3-->Fecha Nacimiento.          -|  "<<endl;
        cout<<"                 |-4-->Número Documento.          -|  "<<endl;
        cout<<"                 |-5-->Número Teléfono.           -|  "<<endl;
        cout<<"                 |-6-->Email.                     -|  "<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|  "<<endl;
        cout<<"                 |-0-->VOLVER                     -|  "<<endl;
        cout<<"                  -------Ingrese una opcion--------   "<<endl;
        cin>>op;
        system("cls");

        switch(op)
        {
        case 1:
        {
            error= setNombre();
            if(error==1)
                return;
        }
        break;

        case 2:
        {
            error=setApellido();
            if(error==1)
                return;
        }
        break;
        case 3:
        {
            error=setFecha();
            if(error==1)
                return;
        }
        break;
        case 4:
        {
            error=setnDoc();
            if(error==1)
                return;
        }
        break;
        case 5:
        {
            error=setTelefono();
            if(error==1)
                return;
        }
        break;
        case 6:
        {
            error=setEmail();
            if (error==1)
                return;
        }
        break;
        case 0:{
        system("cls");
        cout<<"TOQUE PARA VOLVER AL MENU ANTERIOR."<<endl;
        salir=true;
        }
        break;
    default:
        {
            system("cls");
            cout<<"OPCION NO VALIDA, POR FAVOR INGRESE UNA OPCION DEL MENU"<<endl;
        }
        break;

    }

}///cierre de while
}


int Persona :: setApellido()
{
    cin.ignore();

    int i=0, error=-1;
    while (error<0)
    {
        cout<<"Ingrese Apellido: ";
        cin.getline(Apellido,50);
        error=ValidarTexto(this->getApellido());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-1,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};

int Persona :: setNombre()
{
    ///acá no tiene el cin.ignore porque creo que lo rompe, pero puede necesitarse.
    int i=0, error=-1;
    while (error<0)
    {

        cout<<"Ingrese Nombre: ";
        cin.getline(Nombre,50);
        error=ValidarTexto(this->getNombre());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-1,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;

};


int Persona :: setFecha()
{
    int error=0,i=0;
    while (error!=0||error!=1)
    {
        cout<<"Ingrese la Fecha de Nacimiento"<<endl;
        cout<<"Fecha de nacimiento (d/m/a):"<<endl;
        cin>>Dia;
        cout<<"/";
        cin>>Mes;
        cout<<"/";
        cin>>Anio;

        error=ValidarFecha(getDia(),getMes(),getAnio());
        if (error==-1)
        {
            i++;
            error_msj(-2,i);
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
    cin.ignore();
    int error=0,i=0;
    while(error!=1)
    {
        cout<<"Ingrese Numero de Documento : ";
        cin.getline(Documento,9);
        error=ValidarDocumento(getDocumento());
        if(error==0)
            return error;
        if (error==1)
            return error;
        if(error<0)
        {
            i++;
            cout<<"Error Validando Documento -Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i<<"/3"<<endl;
            if(i>3)
            {
                cout<<"Si no podés y querés salir, ingresá 0"<<endl;
            }
        }
    }
    return error;
}

int Persona :: setTelefono()
{
    cin.ignore();
    int error=-1,i=1;
    while (error!=0||error!=1)
    {
        cout<<"Ingrese su Numero de Teléfono."<<endl;
        cout<<"Teléfono :";
        cin.getline(nTelefono,11);
        error = ValidarTelefono(getTelefono());
        if(error==0)
            return error;
        if (error==1)
            return error;
        if(error<0)
        {
            cout<<"Error Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i++<<endl;
            if(i>3)
            {
                cout<<"Si no podés y querés salir, ingresá 0."<<endl;
            }
        }
    }///salida while
    return error;
};

int Persona :: setEmail()
{
    int error=-1,i=0;
    while(error!=0||error!=1)
    {
        cout<<"Ingrese Correo Electronico :"<<endl;
        cout<<"EMAIL :";
        cin.getline(Mail,50);
        error=ValidarMail(Mail);
        if(error==0)
            return error;
        if (error==1)
            return error;
        if(error<0)
        {
            cout<<"Error Validando Mail -Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i+1<<"/3"<<endl;
            if(i>3)
            {
                cout<<"Si no podés y querés salir, ingresá 0."<<endl;
            }

        }
    }///salida while
    return error;
};

int Persona :: ValidarDocumento( const char *Ndoc)///valida que acepte solo numeros///TODO VALIDAR DOCUMENTO NO FUNCA
{
    int i;
    bool flag=true;
    for (i=1; i<9 ; i++)
    {
        if (Ndoc[i-1]<'0'||Ndoc[i-1]>'9')
        {
            flag=false;
            break;
            ///valida que sean solo numeros
        }
    }

    if(Ndoc[0]=='0')
    {
        return 1;///Valida Salida Voluntaria.
    }

    if(flag)
        return 0;
    else
        return -1;
};
int Persona :: ValidarTelefono( const char *Telefono)///valida que acepte solo numeros///TODO VALIDAR TELEFONO NO FUNCA
{
    int i;
    bool flag=true;
    for (i=0; i<11; i++)

    {
        if (Telefono[i-1]<'0'&&Telefono[i-1]>'9')
        {
            flag=false;
            break;
        }
        if(Telefono[0]=='0')
        {
            return 1;///Valida Salida Voluntaria.
        }
    }
    if(flag)
        return 0;
    else
        return -1;
};
int Persona:: ValidarMail( char *Mail)///valida un Montón de cosas, listadas abajo.
{
    int tam=strlen(Mail), pos=0,i=1;
    char *poschar;

    for (i=0; i<3; i++)
    {
        if(Mail[i-1]=='0')
        {
            pos++;
            if(pos==3)
            {
                return 1;
            }
        }
    }///validación de salida usuario

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
    poschar=strchr(Mail,'.');
    if(poschar==NULL)
    {
        return -5;  ///Que tenga un punto
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
    return 0;
}
int Persona :: ValidarFecha(int Dia,int Mes, int Anio)
{
    if(Mes==0&&Dia==0&&Anio==0)
        return 1;
    if((Mes>0&&Mes<13)&&(Anio>1910&&Anio<=2020))
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
                return 0;
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

                return 0;
            }
            else
                return -1;
        case  2 :
            if( (Anio % 4 == 0 && Anio % 100 != 0 )|| (Anio % 400 == 0 ))
                if ( Dia >= 1 && Dia <= 29 )
                {

                    return 0 ;
                }
                else
                {
                    return -1;
                }
            else if ( Dia >= 1 && Dia <= 28 )
            {
                return 0;
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
    return-1;
};

