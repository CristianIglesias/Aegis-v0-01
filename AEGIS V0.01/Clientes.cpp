#include <iostream>
#include <cstdio>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Clientes.h"
#include "PrototiposGlobales.h"
const char *ArchivoClientes ="Clientes.dat";
/// A SABER
/// ERROR==0-TA TODO PIOLA, SIGUE ADELANTE
/// ERROR==1-SALIDA VOLUNTARIA, CLAVA RETURN PERRI
/// ERROR<=0-SIGUE INTENTANDO, TRANK PALANK


void  Cliente:: cargar()///Carga Cliente.
{
    int error=0;
    Persona::Cargar();

    if(Estado==false)
        return;
    Generarid();
    if(idCliente<0)
    {
        cout<<"Hubo un error en la generación de ID Cliente, Intente Nuevamente"<<endl;
        return;
    }
    cout<<"ID Cliente: "<<idCliente<<endl;
    error = SetTipoPago();
    if(error!=0)
    {
        if(error==1)
        {
            cout<<"Operación Cancelada."<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
    }
    error=SetPrefFact();
    if (error!=0)
    {
        if(error==1)
        {
            cout<<"Operación Cancelada."<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
    }
    Deuda=0;
    error=GuardarClienteEnDisco();
    if(error!=0)
    {
        cout<<"Hubo un error Guardando el Cliente en el Archivo."<<endl;
        cout<<"Ingrese cualquier tecla para continuar"<<endl;
        anykey();
    }
    else
    {
        cout<<"Cliente Guardado en el Archivo con Exito!"<<endl;
    }

};

void  Cliente:: mostrar()
{
    cout <<"El Cliente Numero "<<idCliente<<" se llama "<<endl;
    Persona::Mostrar();
    cout<<"Prefiere Pago con ";
    cout<<"Y Tipo de Factura ";
    cout<<endl;

    if(GetDeuda()<0)
    {
        setColor(RED);
        cout<<"El Cliente Posee una deuda de "<<GetDeuda()<<endl;
        setColor(WHITE);
    }

};

void Cliente:: mostrarxID ()///Muestra Por ID -
{
    bool funco=false;
    int aux,i=1;
    while(!funco)
    {

        cout<<"Ingrese el ID Del cliente Con el que quiere trabajar,"<<endl;
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


bool Cliente:: LeerxID(int id)
{
    FILE *P;
    P=fopen(ArchivoClientes,"rb");
    if(P==NULL)
    {
        return false;
    }
    while(fread(this,sizeof(Cliente),1,P)==1)
    {
        if(this->idCliente==id&&this->Estado==true)
            fclose(P);
        return true;
    }
    fclose (P);
    return false;
};
void Cliente::Modificar()
{
    mostrarxID();
    menuModificarCliente();

};

void Cliente:: mostrar(int pos)
{
///Veremos si hace falta
}
bool Cliente:: LeerDeDisco(int i)///TODO (LEERCLIENTEDISCO) LOGRAR QUE ESTA WEA FUNQUE
{
    bool leyo=false;
    FILE *P;
    P=fopen(ArchivoClientes,"rb");
    if(P==NULL)
    {
        return false;
    }
    if(i>0)
    {
        fseek(P,sizeof(Cliente)*i,0);
        leyo= fread(this,sizeof(Cliente),1,P);
    }
    else
    {
        leyo=fread(this,sizeof(Cliente),1,P);
    }
    fclose (P);
    return leyo;
}

void Cliente::Generarid()
{
    int cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoClientes,"rb");
    if(p==NULL)
    {
        idCliente=-1;
        return;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Cliente);

    idCliente=cantRegistros+1;
    fclose(p);
    return;
}


int Cliente :: GuardarClienteEnDisco()
{
    FILE *p;
    p=fopen(ArchivoClientes,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Cliente),1, p)!=1)
    {
        fclose(p);
        return -1;
    }
    fclose (p);
    return 0;
};


void Cliente :: menuModificarCliente()
{
    int op;
    bool salir=false;

    while(!salir)
    {
        setColor(GREEN);
        system("cls");
        cout<<"                Qué Campo desea Modificar del Cliente?"<<endl;
        cout<<"                  _________________________________ "<<endl;
        cout<<"                 |-1-->Campos Persona.            -|"<<endl;
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
        }
        break;

        case 2:
        {
            SetTipoPago();
        }
        break;
        case 3:
        {
            SetPrefFact();
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

    }

}

int Cliente:: SetTipoPago()
{
    cout<<"Tipo De Pago Preferido: ";
    int error=-1, i=0;
    while(error<0)
    {
        cout<<"Recuerde:  1=Efectivo."<<endl;
        cout<<"           2=Tarjeta Débito."<<endl;
        cout<<"           3=Tarjeta Crédito."<<endl;
        cin>>TipodePago;
        error=ValidarTipoPago();
        if(error==1)
        {
            return error;
        }
        if(error<0)
        {
            i++;
            cout<<"Error Validando Tipo Pago.  -Nro "<<error<<" Intente Nuevamente."<<endl;
            cout<<"Intento Numero "<<i<<"/3"<<endl;
            if(i>=3)
            {
                cout<<"Si querés salir, cancelando la carga ingresá 99"<<endl;
            }
        }
    }///Cierra el While
    return error;
};

int Cliente :: ValidarTipoPago()
{
    int error=0;
    if(TipodePago>1&&TipodePago%1!=0)///Valida entero y positivo.
    {
        error=0;
        return error;
    }
    if(TipodePago==99)///Salida Voluntaria
    {
        error=1;
        return error;
    }

    if(TipodePago<1||TipodePago>3)///Valida Tipos permitidos
    {
        error=-1;
        return error;
    }
    return error;
}

int Cliente :: SetPrefFact()
{

    int error,i=0;
    cout<<"Ingrese Preferencia de Factura."<<endl;
    cout<<"Recuerde: 1=Factura B."<<endl;
    cout<<"          2=Factura A."<<endl;
    cin>>PrefFactura;
    error=ValidarPrefFact();
    if (error=0)
        return error;
    if(error==1)
    {
        return error;
    }
    if(error<0)
    {
        i++;
        cout<<"Error Validando Tipo Pago.  -Nro "<<error<<" Intente Nuevamente."<<endl;
        cout<<"Intento Numero "<<i<<"/3"<<endl;
        if(i>=3)
        {
            cout<<"Si querés salir, cancelando la carga ingresá 99"<<endl;
        }
    }
};

int Cliente :: ValidarPrefFact()
{
    if(PrefFactura<1&&PrefFactura%1!=0)
    {

        cout<<"Ingrese un Numero entero y Positivo."<<endl;
        return -1;
    }
    if(PrefFactura==1||PrefFactura==2)
    {
        return 0;
    }
    if(PrefFactura==99)
    {

        return 1;
    }

    if(PrefFactura>2||PrefFactura<1)
    {

        return -2;
    }
};

void Cliente :: SetDeuda()
{
///TODO INGRESO Y VALIDACIÓN, CON SALIDA A VOLUNTAD(SetDeuda).
};

int   Cliente:: GetidCliente()
{
    return idCliente;
};
int   Cliente:: GetTipoPago()
{
    return TipodePago;
};
int   Cliente:: GetTipoFactura()
{
    return PrefFactura;
};
float Cliente:: GetDeuda()
{
    return Deuda;
};
