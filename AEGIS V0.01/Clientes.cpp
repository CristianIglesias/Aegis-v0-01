#include <iostream>
#include <cstdio>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Clientes.h"
#include <iomanip>

const char *ArchivoClientes ="Clientes.dat";
/// A SABER
/// ERROR==0-TA TODO PIOLA, SIGUE ADELANTE
/// ERROR==1-SALIDA VOLUNTARIA, CLAVA RETURN PERRI
/// ERROR<=0-SIGUE INTENTANDO, TRANK PALANK

///TODO EMBELLEZER FUNCIONES CLIENTE.
void  Cliente:: cargar()///Carga Cliente.
{
    int error=0;
    Persona::Cargar();

    if(Estado==false)
        return;

    idCliente=GenerarIdCliente();
    if(idCliente<0)
    {
        cout<<"Hubo un error en la generación de ID Cliente, Intente Nuevamente"<<endl;
        return;
    }
    cout<<"ID Cliente: "<<idCliente<<endl;
    error = SetTipoPago();
    if(error!=0)
    {
        return;
    }
    error=SetPrefFact();
    if (error!=0)
    {
        if(error==1)
        {
            return;
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
    if(Estado==true)
    {
        cout<<endl;
        cout<<left;
        setColor(LIGHTBLUE);
        cout<< setw(3)<<idCliente ;
        setColor(YELLOW);
        Persona::Mostrar();
        cout<<TipodePago<<"/";
        cout<<PrefFactura<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;

        if(GetDeuda()<0)
        {
            setColor(RED);
            cout<<"El Cliente Posee una deuda de "<<GetDeuda()<<endl;
            setColor(WHITE);
        }
    }
    else
    {
        setColor(RED);
        cout<<"Registro no disponible------------------------------------------------------------*."<<endl;
        setColor(WHITE);
    }
};

int Cliente:: LeerxPos(int id)
{
    if(id==-999)
        return 1;
    if(id>=1)
    {
        id--;
    }
    bool leyo=false;
    FILE *P;
    P=fopen(ArchivoClientes,"rb");
    if(P==NULL)
    {
        return false;
    }
    fseek(P,sizeof(Cliente)*id,SEEK_SET);
    leyo=fread(this,sizeof(Cliente),1,P);
    if(leyo)
    {
        fclose (P);
        return 0;
    }
    else
        return -1;
}

int Cliente:: mostrarxID ()///Muestra Por ID -
{
    int funco=-1;
    int aux,i=1;
    while(funco<0)
    {

        cout<<"Ingrese el ID Del cliente Con el que quiere trabajar,"<<endl;
        cout<<"para que se muestre por pantalla."<<endl;
        cin>>aux;
        funco=LeerxPos(aux);
        if(funco!=-1)
        {
            cout<<"*      ________________________________________________________________________________________________*"<<endl;
            cout<<"*      ______________________________________LISTADO DE CLIENTES______________________________________*"<<endl;
            cout<<"        -------------------------------------------------------------------------------------------------"<<endl;
            cout<<left;
            cout<<"ID "<<"" ;
            cout<< "Apellido "<<"\t" ;
            cout<<"Nombre "<<"\t"<<"\t";
            cout<<"Nacimiento"<<"\t";
            cout<<"DNI:"<<"\t      " ;
            cout<<"Telefono "<<"\t"<<"\t";
            cout<<"Email "<<"\t"<<"\t";
            cout<<"Tipo de Pago/factura "<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            mostrar();
        }
        else
        {
            error_msj(-5,i++);
        }
    }
    return funco;///Pos.
}

int GenerarIdCliente()///
{
    int cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoClientes,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Cliente);
    fclose(p);
    return cantRegistros+1;
}

int Cliente :: GuardarClienteEnDisco()///al final, tranqui para agregar clientes
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
int Cliente :: GuardarClienteEnDisco(int ID)///Buscar posición y sobreescribir.
{
    FILE *P;
    if(ID>1)
    {
        ID--;
    }
    P=fopen(ArchivoClientes,"rb+");
    if(P==NULL)
    {
        return -1;
    }
    fseek(P,sizeof(Cliente)*ID,SEEK_SET);
    if(fwrite(this,sizeof(Cliente),1,P)==1)
    {
        fclose (P);
        return 0;
    }
    fclose(P);
    return -1;
}


void ModificarCliente()
{
    int pos;
    Cliente Cli;
    Cli.mostrarxID();
    anykey();
    menuModificarCliente(&Cli,pos);

};


void menuModificarCliente(Cliente *Cli, int pos)
{
    int op,error=-1;
    bool salir=false;

    while(!salir)
    {
        Persona aux;
        int error;
        setColor(GREEN);
        system("cls");
        cout<<"                Qué Campo desea Modificar del Cliente?"<<endl;
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
            int Cambios[5]= {0};
            aux=MenuModificarPersona(Cambios);
            Cli->SetPersona(Cambios, aux);
            error=Cli->GuardarClienteEnDisco(Cli->GetidCliente());
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
            error=Cli->SetTipoPago();
            if(error==1)
                return;
            else
                error=Cli->GuardarClienteEnDisco(Cli->GetidCliente());
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
            error=Cli->SetPrefFact();
            if(error==1)
                return;
            else
                error =Cli->GuardarClienteEnDisco(Cli->GetidCliente());
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
void Cliente :: EliminarCliente()
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
        error=GuardarClienteEnDisco(GetidCliente());
        if(error!=0)
        {
            cout<<"Hubo un error Guardando el Cliente en el Archivo."<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
        else
        {
            cout<<"Cliente Eliminado del Archivo con Exito!"<<endl;
            cout<<"Ingrese cualquier tecla para continuar"<<endl;
            anykey();
        }
    }
};

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
            error_msj(error,i);
        }
        if(error<0)
        {
            i++;
            error_msj(-4,i);

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
    if(TipodePago==-999)///Salida Voluntaria
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
    if (error==0)
        return error;
    if(error==1)
    {
        return error;
    }
    if(error<0)
    {
        i++;
        error_msj(-4,i);

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
void ListarClientes()
{
    Cliente Cli;
    int i=1;
    cls();
    LineasSuperior();
    cout<<"*      ________________________________________________________________________________________________*"<<endl;
    cout<<"*      ______________________________________LISTADO DE CLIENTES______________________________________*"<<endl;
    cout<<"        -------------------------------------------------------------------------------------------------"<<endl;
    cout<<left;
    cout<<"ID "<<"" ;
    cout<< "Apellido "<<"\t" ;
    cout<<"Nombre "<<"\t"<<"\t";
    cout<<"Nacimiento"<<"\t";
    cout<<"DNI:"<<"\t      " ;
    cout<<"Telefono "<<"\t"<<"\t";
    cout<<"Email "<<"\t"<<"\t";
    cout<<"Tipo de Pago/factura "<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    while(Cli.LeerxPos(i)==0)
    {
         msleep(85);
        Cli.mostrar();
        cout<<endl;
        i++;
    }
    cout<<"\t"<<"(Tipo de pago 1=Efectivo / 2=Debito / 3=Credito )"<<endl;
    cout<<"\t"<<"(Preferencia de factura 1=Factura B / 2=Factura A)"<<endl;
    LineasInferior2();
    cin.ignore();
    anykey();
}
