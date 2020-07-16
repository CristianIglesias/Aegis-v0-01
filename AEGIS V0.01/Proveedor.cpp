#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Proveedor.h"

const char *ArchivoProveedor ="Proveedor.dat";

int Proveedor::buscarcodigoproveedor(char *codigo)///ARREGLAR
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

    Estado=true;

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
        error=buscarcodigoproveedor(CodigoProveedor);
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

int Proveedor :: GuardarProveedorEnDisco(int ID)///Buscar posición y sobreescribir.
{
    FILE *P;
    if(ID>1)
    {
        ID--;
    }
    P=fopen(ArchivoProveedor,"rb+");
    if(P==NULL)
    {
        return -1;
    }
    fseek(P,sizeof(Proveedor)*ID,SEEK_SET);
    if(fwrite(this,sizeof(Proveedor),1,P)==1)
    {
        fclose (P);
        return 0;
    }
    fclose(P);
    return -1;
}
void Proveedor::mostrar()
{
    if(Estado==true)
    {
        cout<<left;
        setColor(LIGHTBLUE);
        cout<<CodigoProveedor<<" ";
        setColor(YELLOW);
        Persona::Mostrar();
        cout<<EstadoCuenta<<"/";
        cout<< PorcentajeRentabilidad<<"%"<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
    }
    else
    {
        setColor(RED);
        cout<<"REGISTRO NO DISPONIBLE-------------------------------------------*"<<endl;
        setColor(GREEN);
    }
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
            cout<<"*________________________________________________________________________________________________*"<<endl;
            cout<<"*______________________________________LISTADO DE PROVEEDORES______________________________________*"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
            cout<<left;
            cout<<"ID "<<" " ;
            cout<< "Apellido "<<"\t" ;
            cout<<"Nombre "<<"\t";
            cout<<"Nacimiento"<<"\t";
            cout<<"DNI:"<<"\t      " ;
            cout<<"Telefono "<<"\t      ";
            cout<<"Email :"<<"\t    ";
            cout<<"Estado de cuenta/% Rentabilidad "<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            mostrar();
        }
        else
        {
            error_msj(-5,i++);
        }
    }
}

void ModificarProveedor()
{
    int pos;
    Proveedor pro;
    pro.mostrarxID();
    anykey();
    menuModificarProveedor(&pro,pos);

};

void menuModificarProveedor(Proveedor *prov, int pos)
{
    int op,error=-1,Cambios[5]= {0};
    bool salir=false;

    while(!salir)
    {
        int Cambios[5]= {0};
        Persona aux;
        int error;
        setColor(GREEN);
        system("cls");
        cout<<"                Qué Campo desea Modificar del Proveedor?"<<endl;
        cout<<"                  _________________________________ "<<endl;
        cout<<"                 |-1-->Campos Base.               -|"<<endl;
        cout<<"                 |-2-->.% Rentabilidad                -|"<<endl;
        cout<<"                 |-3-->.Estado de cuenta              -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                  -------Ingrese una opcion-------- "<<endl;
        cin>>op;
        system("cls");

        switch(op)
        {
        case 1:
        {
            MenuModificarPersona(Cambios);
            prov->SetPersona(Cambios,aux);
            /// error=prov->GuardarProveedorEnDisco(prov->getCodigoProveedor());
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
            error=prov->setPorcentajeRentabiliad();
            if(error==1)
                return;
            else
                error=prov->GuardarProveedorEnDisco(prov->getPorcentajeRentabiliad());
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
        case 3:
        {
            error=prov->setEstadoCuenta();
            if(error==1)
                return;
            else
                error =prov->GuardarProveedorEnDisco(prov->getEstadoCuenta());
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

void listarProveedores()
{
    Proveedor prov;
    int i=0;
    cls();
    LineasSuperior();
    cout<<"*________________________________________________________________________________________________*"<<endl;
    cout<<"*______________________________________LISTADO DE PROVEEDORES______________________________________*"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<left;
    cout<<"ID "<<" " ;
    cout<< "Apellido "<<"\t" ;
    cout<<"Nombre "<<"\t";
    cout<<"Nacimiento"<<"\t";
    cout<<"DNI:"<<"\t      " ;
    cout<<"Telefono "<<"\t      ";
    cout<<"Email :"<<"\t    ";
    cout<<"Estado de cuenta/% Rentabilidad "<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;

    while(prov.leerProveedor(i)==1)
    {
        prov.mostrar();
        cout<<endl;
        i++;
    }
    LineasInferior2();
    cin.ignore();
    anykey();
}

