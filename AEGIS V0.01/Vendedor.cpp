#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Persona.h"
#include "Vendedor.h"
#include "PrototiposGlobales.h"
const char *ArchivoVendedor ="Vendedor.dat";

void Vendedor::cargar()
{

    int error=0;
    Persona::Cargar();

    error=setPorcentajeComision();
    if(error==1)
        return;

    error= setVentaDiaria();
    if(error==1)
        return;

    error=setLegajo();
    if(error==1)
        return;

};


int Vendedor::setPorcentajeComision()
{
    cin.ignore();

    int i=0, error=-1;
    while (error<0)
    {
        cout<<"Ingrese el % de comision del vendedor: ";
        cin>>PorcentajeComision;
        error=ValidarFloats(PorcentajeComision);
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(error,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
}

int Vendedor::setVentaDiaria()
{
    cin.ignore();

    int i=0, error=-1;
    while (error<0)
    {
        cout<<"Ingrese el monto de la venta diaria : ";
        cin>>VentaDiaria;
        error=ValidarFloats(VentaDiaria);
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-4,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
}

int Vendedor::setLegajo()
{
    cin.ignore();

    int i=0, error=-5;
    while (error<0)
    {
        cout<<"Ingrese el legajo del vendedor : ";
        cin>>legajo;
        ///error=ValidarEnteros();
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-4,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
}

int Vendedor::guardar()
{
    FILE *p;
    p=fopen(ArchivoVendedor,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Vendedor),1,p)!=1);
    {
        fclose(p);
        return -1;
    }
    fclose(p);
    return 0;
}

int Vendedor :: GuardarVendedorEnDisco(int ID)///Buscar posición y sobreescribir.
{
    FILE *P;
    if(ID>1)
    {
        ID--;
    }
    P=fopen(ArchivoVendedor,"rb+");
    if(P==NULL)
    {
        return -1;
    }
    fseek(P,sizeof(Vendedor)*ID,SEEK_SET);
    if(fwrite(this,sizeof(Vendedor),1,P)==1)
    {
        fclose (P);
        return 0;
    }
    fclose(P);
    return -1;
}

void Vendedor::mostrar()
{
    Persona::Mostrar();
    cout<<"Legajo: " <<legajo<<endl;
    cout<<"Venta diaria: "<<VentaDiaria<<endl;
    cout<<"% Comision: "<< PorcentajeComision<<endl;
}

bool Vendedor::leerVendedor(int pos)
{
    bool leyo=false;
    FILE *p;
    p=fopen(ArchivoVendedor,"rb");
    if(p==NULL)
    {

        return false;
    }
    if(pos>0)
    {
        fseek(p,pos * sizeof(Vendedor),0);
        leyo=fread(this,sizeof(Vendedor),1,p);
    }
    else
    {
        leyo=fread(this,sizeof(Vendedor),1,p);
    }
    fclose(p);
    return leyo;

}

bool Vendedor:: LeerxID(int id)
{
    if(id>=1)
    {
        id--;
    }
    bool leyo=false;
    FILE *P;
    P=fopen(ArchivoVendedor,"rb");
    if(P==NULL)
    {
        return false;
    }
    fseek(P,sizeof(Vendedor)*id,0);
    leyo=fread(this,sizeof(Vendedor),1,P)==1;
    fclose (P);
    return leyo;
}

void Vendedor:: mostrarxID ()///Muestra Por ID -
{
    bool funco=false;
    int aux,i=1;
    while(!funco)
    {

        cout<<"Ingrese el Legajo Del Vendedor Con el que quiere trabajar,"<<endl;
        cout<<"para que se muestre por pantalla."<<endl;
        cin>>aux;
        funco=LeerxID(aux);
        if(funco)
        {
            mostrar();
        }
        else
        {
            error_msj(-5,i++);
        }
    }
}

void Vendedor::Modificar()
{
    mostrarxID();
    anykey();
    menuModificarVendedor();

};

void Vendedor:: menuModificarVendedor()
{
    int op,error=-1;
    bool salir=false;

    while(!salir)
    {
        int error;
        setColor(GREEN);
        system("cls");
        cout<<"                Qué Campo desea Modificar del Vendedor?"<<endl;
        cout<<"                  _________________________________ "<<endl;
        cout<<"                 |-1-->Campos Base.               -|"<<endl;
        cout<<"                 |-2-->.% Comision            -|"<<endl;
        cout<<"                 |-3-->.Venta diaria    -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                  -------Ingrese una opcion-------- "<<endl;
        cin>>op;
        system("cls");

        switch(op)
        {
        case 1:
        {
            Persona::MenuModificarPersona();
            error=GuardarVendedorEnDisco(getlegajo());
            if(error!=0)
            {
                cout<<"Hubo un error Guardando el Cliente en el Archivo."<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }
            else
            {
                cout<<"Cliente Guardado en el Archivo con Exito!"<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }

        }
        break;

        case 2:
        {
            error=setPorcentajeComision();
            if(error==1)
                return;
            else
                error=GuardarVendedorEnDisco(getPorcentajeComision());
            if(error!=0)
            {
                cout<<"Hubo un error Guardando el Cliente en el Archivo."<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }
            else
            {
                cout<<"Cliente Guardado en el Archivo con Exito!"<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }
        }
        break;
        case 3:
        {
            error=setVentaDiaria();
            if(error==1)
                return;
            else
                error =GuardarVendedorEnDisco(getVentaDiaria());
            if(error!=0)
            {
                cout<<"Hubo un error Guardando el Cliente en el Archivo."<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }
            else
            {
                cout<<"Cliente Guardado en el Archivo con Exito!"<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }
        }
        break;
        case 0:
            system("cls");
            cout<<"TOQUE PARA VOLVER AL MENU ANTERIOR."<<endl;
            salir=true;

            break;
        default:
        {
            system("cls");
            cout<<"OPCION NO VALIDA, POR FAVOR INGRESE UNA OPCION DEL MENU"<<endl;

        }
        break;

        }

    }///Cierre de while
    anykey();

}

void Vendedor :: EliminarVendedor()
{
    int Confirmacion, error;
    mostrarxID();
    cout<<"Está Seguro que querés eliminar el registro?"<<endl;
    cout<<"Si está Seguro, Ingrese 1111"<<endl;
    cin>>Confirmacion;
    if(Confirmacion==1111)
    {
        cout<<"Eliminando..."<<endl;
        this->Estado=false;
        error=GuardarVendedorEnDisco(getlegajo());
        if(error!=0)
        {
            cout<<"Hubo un error Guardando el Vendedor en el Archivo."<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
        else
        {
            cout<<"Vendedor Eliminado del Archivo con Exito!"<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
    }
};
