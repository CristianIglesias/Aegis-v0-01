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
    if(Estado==true)
    {
        cout<< Apellido<<", "<<Nombre<<" Cumple años el "<<GetFechaNac().getDia()<<" del "<<GetFechaNac().getMes()<<endl;
        cout<<"Numero de documento:" <<Documento<<endl;
        cout<<"Numero de telefono :"<<nTelefono<<endl;
        cout<<"Email :"<<Mail<<endl;
    }
    else
    {
        setColor(RED);
        cout<<"El Registro no está activo."<<endl;
        setColor(YELLOW);
    }

}
void Persona :: SetPersona(int *Cambios, Persona Per)///TODO CHEQUEAR SetPersona(Persona Per);
{
    if(Cambios[0]!=0)
        this-> setNombre  (Per.getNombre());
    if(Cambios[1]!=0)
        this-> setApellido(Per.getApellido());
    if(Cambios[2]!=0)
        this-> setFecha   (Per.GetFechaNac());
    if(Cambios[3]!=0)
        this-> setTelefono(Per.getTelefono());
    if(Cambios[4]!=0)
        this-> setEmail   (Per.getEmail());
    if(Cambios[5]!=0)
        this-> setnDoc    (Per.getDocumento());
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
    int error=0,i=0,aux;
    while (error!=0||error!=1)
    {
        cout<<"Ingrese la Fecha de Nacimiento"<<endl;
        cout<<"Fecha de nacimiento (d/m/a):"<<endl;
        cin>>aux;
        FechaNacimiento.setDia(aux);
        cout<<"/";
        cin>>aux;
        FechaNacimiento.setMes(aux);
        cout<<"/";
        cin>>aux;
        FechaNacimiento.setAnio(aux);
        error=FechaNacimiento.ValidarFecha(GetFechaNac());
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
        error=ValidarEnteros(getDocumento());
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
        error = ValidarEnteros(getTelefono());
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


Persona MenuModificarPersona(int *Cambios)
{
    Persona Per;
    int op;
    bool salir=false;

    while(!salir)
    {
        int error=-1;
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
            error= Per.setNombre();
            if(error==1)
                return Per;
            Cambios[op-1]=1;
        }
        break;

        case 2:
        {
            error=Per.setApellido();
            if(error==1)
                return Per;
            Cambios[op-1]=1;

        }
        break;
        case 3:
        {
            error=Per.setFecha();
            if(error==1)
                return Per;
            Cambios[op-1]=1;
        }
        break;
        case 4:
        {
            error=Per.setnDoc();
            if(error==1)
                return Per;
            Cambios[op-1]=1;
        }
        break;
        case 5:
        {
            error=Per.setTelefono();
            if(error==1)
                return Per;
            Cambios[op-1]=1;
        }
        break;
        case 6:
        {
            error=Per.setEmail();
            if (error==1)
                return Per;
            Cambios[op-1]=1;
        }
        break;
        case 0:
        {
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
    return Per;
}
