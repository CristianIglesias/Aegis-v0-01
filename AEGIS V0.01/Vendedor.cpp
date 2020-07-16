#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Vendedor.h"


const char *ArchivoVendedor ="Vendedor.dat";
void Vendedor::cargar()
{
    int error=0,Leg;
    Leg=GenerarIdVendedor();
    setLegajo(Leg);
    cout<<"Legajo Vendedor: "<<Leg<<endl;
    Persona::Cargar();
    if(Estado)
    {
        error=setPorcentajeComision();
        if(error==1)
            return;
        error= setVentaDiaria();///TODO CHEQUEAR VENTADIARIA.
        if(error==1)
            return;
        error=guardar();
        if(error!=0)
        {
            cout<<"Hubo un error Guardando el Vendedor en el Archivo."<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
        else
        {
            cout<<"Vendedor Guardado en el Archivo con Exito!"<<endl;
        }
    }
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

int Vendedor::setLegajo(int Leg)///TODO CHEQUEAR SI HACE FALTA BORRAR.
{
    legajo=Leg;
}
int Vendedor::guardar()
{
    FILE *p;
    p=fopen(ArchivoVendedor,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Vendedor),1,p)!=1)
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
    if(Estado==true)
    {
        setColor(LIGHTBLUE);
        cout<<setw(3)<<legajo<<" ";
        setColor(YELLOW);
        Persona::Mostrar();
        cout<<"$"<<VentaDiaria<<"/"<<"%";
        cout<< PorcentajeComision<<"$"<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
    }
    else
    {
        setColor(RED);
        cout<<"Registros Inactivos.---------------------------------------------------------------------------------------"<<endl;
        setColor(WHITE);
        cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
        anykey();
    }

}

int Vendedor::leerVendedor(int pos)
{
    if(pos==-999)
        return 1;
    pos-- ;       ///polemica
    bool leyo=false;
    FILE *p;
    p=fopen(ArchivoVendedor,"rb");
    if(p==NULL)
    {

        return -1;
    }
    fseek(p,pos * sizeof(Vendedor),0);
    leyo=fread(this,sizeof(Vendedor),1,p);
    if(this->getlegajo()==pos)
    {
        fclose(p);
        return 0;
    }
    fclose(p);
    return 1;
}

int Vendedor:: LeerxID(int id)
{
    if(id==-999)
        return 0;
    int leyo=-1;
    FILE *P;
    P=fopen(ArchivoVendedor,"rb");
    if(P==NULL)
    {
        return -1;
    }
    fseek(P,sizeof(Vendedor)*id,0);
    leyo=fread(this,sizeof(Vendedor),1,P);
    fclose (P);
    if(leyo)
    {
        return leyo;
    }
    else
        return -1;
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
            HeaderVendedor();

            mostrar();
        }
        else
        {
            error_msj(-5,i++);
        }
    }
}

void ModificarVendedor()
{
    int pos;
    Vendedor ven;
    ven.mostrarxID();
    anykey();
    menuModificarVendedor(&ven,pos);

};

void menuModificarVendedor(Vendedor *ven, int pos)
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
        cout<<"                Qué Campo desea Modificar del Vendedor?"<<endl;
        cout<<"                  _________________________________ "<<endl;
        cout<<"                 |-1-->Campos Base.               -|"<<endl;
        cout<<"                 |-2-->.% Comision                -|"<<endl;
        cout<<"                 |-3-->.Venta diaria              -|"<<endl;
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
            ven->SetPersona(Cambios,aux);
            error=ven->GuardarVendedorEnDisco(ven->getlegajo());
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
            error=ven->setPorcentajeComision();
            if(error==1)
                return;
            else
                error=ven->GuardarVendedorEnDisco(ven->getPorcentajeComision());
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
            error=ven->setVentaDiaria();
            if(error==1)
                return;
            else
                error =ven->GuardarVendedorEnDisco(ven->getVentaDiaria());
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
int GenerarIdVendedor()
{
    int cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoVendedor,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Vendedor);
    fclose(p);
    return cantRegistros+1;
}


void ListarVendedores()
{
    Vendedor ven;
    int i=0;
    cls();
    LineasSuperior();
    cout<<endl;

    HeaderVendedor();
    cout<<endl;

    while(ven.LeerxID(i)==1)
    {
        msleep(85);
        ven.mostrar();
        cout<<endl;

        i++;
    }
    LineasInferior2();
    cin.ignore();
    anykey();
}
