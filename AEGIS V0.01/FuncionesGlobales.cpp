#include <iostream>
#include <iomanip>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "rlutil.h"
using namespace rlutil;
#include "PrototiposGlobales.h"

void error_msj(int cod, int i)/// A COMPLETAR, CADA UNO AGREGA ERRORES QUE NECESITE, SOLO SER A AGREGAR CASES AL SWITCH.
/// ES UTIL PARA SIMPLIFICAR EL C DIGO.
{
    switch(cod)
    {


    case 1:
        cout<<"Salida Voluntaria!."<<endl;
        cout<<"Operacion Cancelada. Presione cualquier Tecla para continuar."<<endl;
        anykey();
        break;

    case -1:
        cout<<"Error Validando, Este Campo SOLO permite Letras, Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -2:
        cout<<"Error Validando, Fecha Invalida. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -3:
        cout<<"Error Validando, Ese codigo ya existe. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""000""."<<endl;
        }
        break;
    case -4:
        cout<<"Error Validando, Este campo solo permite Números Enteros. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""-999""."<<endl;
        }
        break;
    case -5:
        cout<<"Error Validando, ID INEXISTENTE. Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"."<<endl;
        if(i>3)
        {
            cout<<"Si no podés y querés salir, ingresá ""-999""."<<endl;
        }
        break;
    case -6:
        cout<<"Error. No se pudo acceder al archivo."<<endl;
        break;
    }
}




int ValidarEnteros( const char *Telefono)///valida cadenas de enteros
{
    int i, TAM;
    bool flag=true;
    TAM =strlen(Telefono);
    for (i=0; i<TAM; i++)

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

int ValidarTexto(const char *cad)
{
    int tam,i=0;
    bool flag=true;
    tam=strlen(cad);
    if(cad[0]=='\0')
    {
        return -1;
    }
    if(cad[0]=='0')
    {
        return 1;
    }
    for (i=1; i<tam; i++)
    {
        if(isalpha(cad[i])==0)
        {
            flag=false;
            return -1;
        }

    }
    if(flag)
        return 0;
};

int ValidarFloats(float var)
{
    if(var>0)
        return 0;
    else
        return -4;
}
int ValidarEntero(int c)
{
    if(c==-999)
        return 1;
    if(c>0&&c%1==0)
        return 0;
    else
        return -4;
}

void LineasSuperior()
{
    int x;
    for(x=1; x<118; x++)
    {
        gotoxy(x,1);
        cout<<"="<<endl;
        if(x<=20)
        {
            gotoxy(1,x);
            cout<<""<<endl;
        }
    }
}
void LineasInferior()
{
    int x;
    for(x=1; x<118; x++)
    {
        gotoxy(x,20);
        cout<<"="<<endl;
        if(x<=20)
        {
            gotoxy(1,x);
            cout<<"||"<<endl;
            gotoxy(118,x);
            cout<<"||"<<endl;


        }

    }
}

void LineasInferior2()
{
    int x;
    for(x=1; x<118; x++)
    {
        gotoxy(x,45);
        cout<<"="<<endl;
        if(x<=45)
        {
            gotoxy(1,x);
            cout<<"||"<<endl;
            gotoxy(118,x);
            cout<<"||"<<endl;


        }

    }
}
void LineasInferior3()
{
    int x;
    for(x=1; x<118; x++)
    {
        gotoxy(x,15);
        cout<<"="<<endl;
        if(x<=15)
        {
            gotoxy(1,x);
            cout<<"||"<<endl;
            gotoxy(118,x);
            cout<<"||"<<endl;


        }

    }
}
/*void listadoDeVentas()
{
    cout<<"*________________________________________________________________________________________________*"<<endl;
    cout<<"*______________________________________LISTADO DE VENTAS______________________________________*"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;

    while(ventas.leerVentas(i)==1)
    {
        ventas.mostrar();
        cout<<endl;
        i++;
    }
    cin.ignore();
    anykey();
}
*/

