#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "Persona.h"
#include "Proveedor.h"
#include "PrototiposGlobales.h"
#include "rlutil.h"
using namespace rlutil;
const char *ArchivoProveedor ="Proveedor.dat";

int Proveedor::buscarcodigoproveedor(const char *codigo)
{
    Proveedor aux;
    FILE *p;
    p=fopen(ArchivoProveedor,"rb");
    if(p==NULL)
    {
        return 1;
    }
    while(fread(&aux,sizeof(Proveedor),1,p))
    {
        if(strcmp(getCodigoProveedor(),aux.getCodigoProveedor())==0)
        {
            fclose(p);
            return -1;
        }

    }
    fclose(p);
    return 0;

}

void  Proveedor:: cargar()
{
    int error=0;
    Persona::Cargar();

    error=setPorcentajeRentabiliad();
    if(error==1)
        return;

    error= setEstadoCuenta();
    if(error==1)
        return;

    error=setCodigoProveedor();
    if(error==1)
        return;

};

int Proveedor::validarFloat(float c)
{

    if(c<=0)
    {

        return 1;
    }
}



int Proveedor::setPorcentajeRentabiliad()
{
    cin.ignore();

    int i=0, error=-6;
    while (error<0)
    {
        cout<<"Ingrese el porcentaje de rentabilidad del proveedor: ";
        cin>>PorcentajeRentabilidad;
        error=validarFloat(PorcentajeRentabilidad);
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-6,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};

int Proveedor::setEstadoCuenta()
{
    cin.ignore();

    int i=0, error=-6;
    while (error<0)
    {
        cout<<"Ingrese el estado de cuenta del proveedor: ";
        cin>>EstadoCuenta;
        error=validarFloat(EstadoCuenta);
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-6,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};

int Proveedor::setCodigoProveedor()
{
    cin.ignore();

    int i=0, error=-5;
    while (error<0)
    {
        cout<<"Ingrese el codigo de proveedor: ";
        gets(CodigoProveedor);
        error=buscarcodigoproveedor(this->getCodigoProveedor());
        if (error!=0)
        {
            if (error==1)
                return error;
            if(error<0)
            {
                i++;
                error_msj(-5,i);
                anykey();
                cls();
            }
        }
    }///cierra while
    return error;
};




int Proveedor::guardarProveedor()
{

    FILE *p;
    p=fopen(ArchivoProveedor,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Proveedor),1,p)!=1);
    {
        fclose(p);
        return -1;
    }
    fclose(p);
    return 0;

}
void Proveedor::mostrar()
{
    Persona::Mostrar();
    cout<<"CODIGO: " <<CodigoProveedor<<endl;
    cout<<"ESTADO DE CUENTA: "<<EstadoCuenta<<endl;
    cout<<"% RENTABILIDAD: "<< PorcentajeRentabilidad<<endl;
}

bool Proveedor::leerProveedor(int pos)
{
    bool leyo=false;
    FILE *p;
    p=fopen(ArchivoProveedor,"rb");
    if(p==NULL)
    {

        return false;
    }
    if(pos>0)
    {
        fseek(p,pos * sizeof(Proveedor),0);
        leyo=fread(this,sizeof(Proveedor),1,p);
    }
    else
    {
        leyo=fread(this,sizeof(Proveedor),1,p);
    }
    fclose(p);
    return leyo;

}

bool Proveedor:: LeerxID(char *id)
{


    FILE *P;
    P=fopen(ArchivoProveedor,"rb");
    if(P==NULL)
    {
        return false;
    }

    while(fread(this,sizeof(Proveedor),1,P)==1)
    {
        if(strcmp(id,CodigoProveedor)==0)
        {
            fclose (P);
            return true;
        }

    }

    fclose (P);
    return false;
}


void Proveedor:: mostrarxID ()///Muestra Por ID -
{
    bool funco=false;
    char aux[20];
    int i=1;
    gets(aux);
    while(!funco)
    {

        cout<<"Ingrese el ID Del proveedor Con el que quiere trabajar,"<<endl;
        cout<<"para que se muestre por pantalla."<<endl;
        gets (aux);
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

void Proveedor::Modificar()
{
    mostrarxID();
    anykey();
    menuModificarProveedor();

};

void Proveedor :: menuModificarProveedor()
{
    int op,error=-1;
    bool salir=false;

    while(!salir)
    {
        int error;
        setColor(GREEN);
        system("cls");
        cout<<"                Qué Campo desea Modificar del Proveedor?"<<endl;
        cout<<"                  _________________________________ "<<endl;
        cout<<"                 |-1-->Campos Base.               -|"<<endl;
        cout<<"                 |-2-->Tipo De Pago.              -|"<<endl;
        cout<<"                 |-3-->Preferencia de Factura.    -|"<<endl;
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
            error=guardarProveedor();
            if(error!=0)
            {
                cout<<"Hubo un error Guardando el Proveedor en el Archivo."<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }
            else
            {
                cout<<"Proveedor Guardado en el Archivo con Exito!"<<endl;
                cout<<"Ingrese cualquier tecla para continuar"<<endl;
                anykey();
            }

        }
        break;

        case 2:
        {
            error=setPorcentajeRentabiliad();
            if(error==1)
                return;
            else
                error=guardarProveedor();
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
            error=setEstadoCuenta();
            if(error==1)
                return;
            else
                error=guardarProveedor();
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
void Proveedor :: EliminarProveedor()
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
        error=guardarProveedor();
        if(error!=0)
        {
            cout<<"Hubo un error Guardando el Proveedor en el Archivo."<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
        else
        {
            cout<<"Proveedor Eliminado del Archivo con Exito!"<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
    }
};

