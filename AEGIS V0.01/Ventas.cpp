#include <iostream>
#include <iomanip>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "Ventas.h"
#include "PrototiposGlobales.h"

const char *ArchivoVentas ="Ventas.dat";


/// A SABER
/// ERROR=0-TA TODO PIOLA, SIGUE ADELANTE
/// ERROR=1-SALIDA VOLUNTARIA, CLAVA RETURN PERRI
/// ERROR<0-SIGUE INTENTANDO, TRANK PALANK


void Venta:: GenerarVenta()
{
    int error=-1;
    SetID(GenerarIdVenta());
    cout<<"ID de venta : "<<getID()<<endl;
    error=SetIdVendedor();
    if(error!=0)
        return;
    error=SetIdCliente();
    if(error==1)
        return;
    DetalleVenta Det;
    while(error==0)
    {
        error=Det.CargarDetalle(this);
        setImporteTotal(Det.getImporteTotal());
    }
    cout<<"El Importe final de la Operación es: "<<getImporteTotal()<<endl;
    error=GuardarVenta();
    if(error!=0)
    {
        cout<<"Hubo un error Guardando la Venta en el Archivo."<<endl;
        cout<<"Ingrese cualquier tecla para continuar"<<endl;
        anykey();
    }
    else
    {
    cout<<"Venta Guardada en el Archivo con Exito!"<<endl;
    cout<<endl;
    MostrarDetalle();
    }

};
void Venta:: Mostrar()
{
    int error=-1;
    cout<<left;
    cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(3)<<ID<<"\t"<<"\t"<<"\t";
    cout<<fechaOperacion.getDia()<<"/"<<fechaOperacion.getMes()<<"/"<<fechaOperacion.getAnio()<<"\t"<<"\t"<<" ";
    cout<<setw(5)<<IdVendedor<<"\t"<<"\t";
    cout<<left;
    cout<<setw(10)<<getIdCliente()<<"\t"<<"    ";
    cout<<"$"<< ImporteTotal<<"\t"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
}

int Venta:: SetIdVendedor()
{
    Vendedor Vend;
    int error=-1,i=0,op;
    while(error!=0)
    {
        cout<<"Ingrese el ID del vendedor a cargo de esta venta:"<<endl;
        cout<<"ID VENDEDOR: ";
        cin>>IdVendedor;
        error=Vend.leerVendedor(IdVendedor);
        if(error==0)
            return -1;
        if(error==-1)
        {
            i++;
            error_msj(-5,i);
        }
        if(error==1)///funcion confirmar elección.
        {
            cout<<"El Vendedor deseado es : "<<Vend.getNombre()<<" ?"<<endl;
            cout<<"SI :1             NO:0"<<endl;
            cin>>op;
            switch(op)
            {
            case 1:
                IdVendedor=Vend.getlegajo();
                return 0;
                break;
            case 0:
                error=-2;
                break;
            }
        }

    }///Cierra while
    return error;
};
int Venta:: SetIdCliente()
{
    Cliente Cli;
    int error=-1,i=0,op;
    while(error<0)
    {
        cout<<"Ingrese el ID del Cliente  que realiza la compra:"<<endl;
        cout<<"ID Cliente: ";
        cin>>op;
        error=Cli.LeerxPos(op);
        if(error==1)
            return 1;
        if(error==0)
        {
            cout<<"El Cliente deseado es : "<<Cli.getNombre()<<" ?"<<endl;
            cout<<"SI :1             NO:0"<<endl;
            cin>>op;
            switch(op)
            {
            case 1:
                SetIdCliente(Cli.GetidCliente());
                return error;
                break;
            case 0:
                error=-2;
                break;
            }

        }
        if(error==-1)
            i++;
        error_msj(-5,i);
    }///Cierra while;
    return error;
};
int GenerarIdVenta()
{
    int id, cantRegistros=0;
    FILE *p;
    p=fopen(ArchivoVentas,"rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,SEEK_SET,SEEK_END);
    cantRegistros=ftell(p)/sizeof(Venta);

    id=cantRegistros+1;
    fclose(p);
    return id;
};
void Venta :: setImporteTotal(float ImporteDetalle)
{
    ImporteTotal+=ImporteDetalle;
}
int Venta:: GuardarVenta()
{
    FILE *p;
    p=fopen(ArchivoVentas,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(this,sizeof(Venta),1, p)!=1)
    {
        fclose(p);
        return -1;
    }
    fclose (p);
    return 0;
};
void ListarTodasVentas()
{
    int error=0, CantRegs=0;
    Venta *VecDin;
    CantRegs=ContarVentas();
    if(CantRegs<0)
        error_msj(-6,0);
    VecDin=new Venta[CantRegs];
    if(VecDin==NULL)
        error_msj(-7,0);
    error=CargarVentas(VecDin,CantRegs);
    if(error<0)
        error_msj(-6,0);
    while(error!=-1)
    {
        error=MenuOrdenarVentas(VecDin,CantRegs);
    }

    free(VecDin);
    return ;
};
int ContarVentas()
{
    int cant=0;
    FILE *P;
    P=fopen(ArchivoVentas,"rb");
    if(P==NULL)
    {
        fclose(P);
        return -1;
    }
    fseek(P,SEEK_SET,SEEK_END);
    cant=ftell(P)/sizeof(Venta);
    fclose(P);
    return cant;
};
int CargarVentas(Venta *Vec,int CantRegs)
{
    FILE *P;

    P=fopen(ArchivoVentas,"rb");
    if(P==NULL)
    {
        fclose(P);
        return -1;
    }
    if(fread(Vec,sizeof(Venta),CantRegs,P)==CantRegs)
    {
        fclose(P);
        return 0;
    }
    ///Creo que haría falta alguna validación de que i==Cant, para corroborar que se cargó el vector entero :/
    fclose(P);
    return -1;
};

void MostrarVentasXid(Venta *Vec,int Cant,int version)
{
    int i=0;

    setColor(LIGHTCYAN);
    cout<<endl;
   void HeaderMostrarVentasXID();
    cout<<endl;
    setColor(WHITE);
    switch(version)
    {
    case 1:
    {

        cls();
        HeaderListadoDeVentas1();
        cout<<endl;

        while(i<Cant)
        {
            msleep(5);
            Vec[i].Mostrar();

            i++;
        }
        cin.ignore();
        anykey();
    }
    break;
    case 2:
    {
        i=Cant;

        cls();
        cout<<endl;

        cout<<"          __________________________________LISTADO DE VENTAS(ascendente)_____________________________________"<<endl;
        cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Numero de venta "<<"    ";
        cout<<"Fecha de venta "<<"\t"<<" ";
        cout<<"Vendedor nro "<<"\t";
        cout<<"Cliente nro "<<"\t"<<"\t";
        cout<<"Importe final " <<"$"<<"\t"<<endl;
        cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
        while(i>=0)
        {
            msleep(5);
            Vec[i].Mostrar();

            i--;
        }
        cin.ignore();
        anykey();
    }
    break;

    }
};
void  MostrarVentasxImporte(Venta *Vec,int Cant,int version)
{
    int i=0;
    OrdenarVentasxImporte(Vec,Cant,version);
    setColor(LIGHTCYAN);
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<< left;
    cout<<setw(5)<<"ID VENTA-";
    cout<<setw(5)<<"FECHA";
    cout<< right;
    cout<<setw(10)<<"NOMBRE CLIENTE-";
    cout<<setw(5)<<"NOMBRE VENDEDOR-"<<endl;
    cout<<setw(5)<<"PRECIO FINAL"<<"  "<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    setColor(WHITE);
    switch(version)
    {
    case 1:
    {

        cls();
        cout<<endl;

        while(i<Cant)
        {
            msleep(5);
            Vec[i].Mostrar();

            i++;
        }
        cin.ignore();
        anykey();
    }
    break;
    case 2:
    {
        i=Cant;


cls();
HeaderListadoDeVentas2();
        cout<<endl;

        while(i>=0)
        {
            msleep(5);
            Vec[i].Mostrar();

            i--;
        }
        cin.ignore();
        anykey();
    }
    break;

    }
};
void OrdenarVentasxImporte(Venta *VecDin,int Cant,int version)
{
    switch(version)
    {
    case 1:
    {
        int i,j,pos;
        Venta aux;
        for(i=0; i<Cant-1; i++)
        {
            pos=i;
            for(j=i+1; j<Cant; j++)
            {
                if(VecDin[j].getImporteTotal()<VecDin[pos].getImporteTotal())
                {
                    pos=j;
                }

            }
            aux=VecDin[i];
            VecDin[i]=VecDin[pos];
            VecDin[pos]=aux;
        }
    }
    break;


    case 2:
    {
        int i,j,pos;
        Venta aux;
        for(i=0; i<Cant-1; i++)
        {
            pos=i;
            for(j=i+1; j<Cant; j++)
            {
                if(VecDin[j].getImporteTotal()>VecDin[pos].getImporteTotal())
                {
                    pos=j;
                }

            }
            aux=VecDin[i];
            VecDin[i]=VecDin[pos];
            VecDin[pos]=aux;
        }
    }
    break;
    }





};

int Venta:: LeerVentaxID(int id)
{
    if(id==-999)
        return 1;
    if(id>=1)
    {
        id--;
    }
    bool leyo=false;
    FILE *P;
    P=fopen(ArchivoVentas,"rb");
    if(P==NULL)
    {
        return -6;
    }
    fseek(P,sizeof(Venta)*id,SEEK_SET);
    leyo=fread(this,sizeof(Venta),1,P);
    if(leyo)
    {
        fclose (P);
        return 0;
    }
    else
        return -1;
};

void MostrarDetallesDeVentaxID()
{
    int ID,error=-1,i=0;
    Venta Aux;
    cout<<"Ingrese el ID De la venta que desea ver en detalle."<<endl;
    while(error<0)
    {cout<<"ID: ";
    cin>>ID;
    error=Aux.LeerVentaxID(ID);
    if(error<0)
    {   i++;
        error_msj(error,i);
    }
    error=MostrarDetalles(&Aux);
    if(error<0)
    {
        error_msj(-6,i);
    }

    }
}

void Venta ::MostrarTabla()
{
    Vendedor Aux;
    Cliente Reg;
    Aux.LeerxID(this->IdVendedor);
    Reg.LeerxPos(this->IdCliente);
    setColor(WHITE);
    cout<< left;
    cout<< setw(5)<<this->getID()<<"\t";
    cout << right;
    cout<<setw(5);
    getFechaOperacion().mostrar(); "\t";
    cout<< setw(10)<<Reg.getNombre();
    cout<< left;
    cout<<setw(5)<<Aux.getNombre()<<"\t    ";
    cout<<setw(5)<<getImporteTotal()<<"\t"<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;

};

void ListadoVentasxFechas()
{
    int error=-1,CantVentas;
    Fecha Fech1,Fech2;
    cout<<"Ingrese las fechas entre las que quiere que se filtre el Listado"<<endl;
    error=Fech1.CargarFecha();
    if(error==1)
        return;
    error=Fech2.CargarFecha();
    if(error==1)
        return;
    AsignarOrdenaFechas(&Fech1,&Fech2);
    CantVentas=ContarVentasxFechas(Fech1,Fech2);
    if(CantVentas==-1)
        error_msj(-6,1);
    Venta *VecDin;
    VecDin=new Venta[CantVentas];
    error=CargarVecVentasxFecha(VecDin,CantVentas,Fech1,Fech2);

};

int ContarVentasxFechas(Fecha Fech1,Fecha Fech2)
{
    Venta Aux;
    int cont=0;
    FILE *P;
    P=fopen("Ventas.dat","rb");
    if(P==NULL)
    {
        fclose(P);
        return -1;
    }
    while(fread(&Aux,sizeof(Venta),1,P)==1)
    {
        if((Aux.getFechaOperacion().getDia()>=Fech1.getDia()&&Aux.getFechaOperacion().getMes()>=Fech1.getMes())||(Aux.getFechaOperacion().getDia()<=Fech2.getDia()&&Aux.getFechaOperacion().getMes()<=Fech2.getMes()))
            cont++;
    }
    fclose(P);
    return cont;
}
int CargarVecVentasxFecha(Venta *Vec,int CantVentas,Fecha Fech1,Fecha Fech2)
{
    int Pos=0;
    FILE *P;
    P=fopen("Ventas.dat","rb");
    if(P==NULL)
    {
        fclose(P);
        return -1;
    }
    while(fread(&Vec[Pos],sizeof(Venta),1,P)==1)
    {
        if((Vec[Pos].getFechaOperacion().getDia()>=Fech1.getDia()&&Vec[Pos].getFechaOperacion().getMes()>=Fech1.getMes()) || (Vec[Pos].getFechaOperacion().getDia()<=Fech2.getDia() && Vec[Pos].getFechaOperacion().getMes()<=Fech2.getMes()));
        Pos++;
    }
    fclose(P);
    return 1 ;
}
void ListadoVentasxVendedor()
{
    int error=-1,CantVentas,i=0;
    int IdAux;
    Vendedor Reg;
    cout<<"Ingrese El Id/Legajo del vendedor que quiere filtrar."<<endl;
    cin>>IdAux;
    while(error!=1)
    {
        error=Reg.LeerxID(IdAux);
        if(error==0)
            i++;
        error_msj(-5,i);
        return;
    }
    CantVentas=ContarVentasxVendedor(Reg.getlegajo());
    if(CantVentas==-1)
        error_msj(-6,1);
    Venta *VecDin;
    VecDin=new Venta[CantVentas];
    error=CargarVecVentasxVendedor(VecDin,CantVentas,Reg.getlegajo());
    MenuOrdenarVentas(VecDin,CantVentas);
    free(VecDin);




};

int ContarVentasxVendedor(int Legajo)
{
    Venta Aux;
    int cont=0;
    FILE *P;
    P=fopen("Ventas.dat","rb");
    if(P==NULL)
    {
        fclose(P);
        return -1;
    }
    while(fread(&Aux,sizeof(Venta),1,P)==1)
    {
        if(Aux.getIdVendedor()==Legajo)
        {
            cont++;
        }
    }
    fclose(P);
    return cont;
}
int CargarVecVentasxVendedor(Venta *Vec,int Cant,int Legajo)
{
    int Pos=0;
    FILE *P;
    P=fopen("Ventas.dat","rb");
    if(P==NULL)
    {
        fclose(P);
        return -1;
    }
    while(fread(&Vec[Pos],sizeof(Venta),1,P)==1)
    {
        if(Vec->getIdVendedor()==Legajo)
        {
            Pos++;
        }
    }
    fclose(P);
    return 1 ;
}










void ListadoVentasxImporteMax()
{

};

void ListadoVentasxCliente()
{

};



///TODO funcion definir fechas mayor que otra~
///TODO y después por vendedor/cliente/importe max -  MOSTRAR VENTA - Algun tipo de reporte




int MenuOrdenarVentas(Venta *VecDin, int Cant)
{
    int op,x;
    bool salir=false;
    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<"                                                Listado Cargado! Cómo preferís verlo?"<<endl;

        cout<<endl;
        cout<<endl;
        cout<<"                                                      Ordenar Listado.                 "<<endl;
        setColor(YELLOW);
        cout<<"                                             __________________________________________"<<endl;
        cout<<"                                            ||1--> Por ID (Ascendente)                 ||"<<endl;
        cout<<"                                            ||2--> Por ID (Descendente)                ||"<<endl;
        cout<<"                                            ||3--> Por Importes (Ascendentes)          ||"<<endl;
        cout<<"                                            ||4--> Por Importes (Descendentes)         ||"<<endl;
        cout<<"                                            ||5--> Por Fechas   (Ascendentes)          ||"<<endl;
///     cout<<"                                            ||6--> Por Fechas   (Desscendentes)        ||"<<endl;
        cout<<"                                            ||-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-||"<<endl;
        cout<<"                                            ||0-->VOLVER                               ||"<<endl;
        cout<<"                                            ||_________________________________________||"<<endl;
        cout<<"                                             -------Ingrese una opcion--------"<<endl;
        LineasInferior();
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
        {
            MostrarVentasXid(VecDin,Cant,1);
        }
        break;

        case 2:
        {
            MostrarVentasXid(VecDin,Cant,2);
        }
        break;
        case 3:
        {
            MostrarVentasxImporte(VecDin,Cant,1);
        }
        break;
        case 4:
        {
            MostrarVentasxImporte(VecDin,Cant,2);

        }
        break;
        case 5:
        {
        }
        break;
        case 0:
        {
            system("cls");
            cout<<"TOQUE PARA VOLVER AL MENU ANTERIOR."<<endl;
            salir=true;
            return -1;
        }
        break;
        default:
        {
            system("cls");
            cout<<"OPCION NO VALIDA, POR FAVOR INGRESE UNA OPCION DEL MENU"<<endl;
        }
        break;

        }
        system("pause");
    }

    MostrarDetallesDeVentaxID();

};










//    cout<<"LEGAJO DE VENDEDOR QUE REALIZARA LA VENTA:"<<endl;

///______________________________________________//POSIBLE FORMATO\\_____________________________
///|           NUMEOR DE LA VENTA:(XXX)                           FECHA(XX/XX/XXXX)               |
///|           LEGAJOVENDEDOR: xxxx                                  IDCLIENTE: xxxx              |
///|                                                                                              |
///|           -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T                            |
///|           -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T                            |
///|           -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T                            |
///|           -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T                            |
///|           -IDP-      - NOMBRE PRODUCTO -     $PU     CANT    $P T                            |
///|           TIPO DE PAGO: x / TIPO DE FACTURA: x                                               |
///|                                                             IMPORTE TOTAL                    |
///|                                                            %DESCUENTO                        |
///|                                                             TOTAL $: xxxx,xx                 |
///------------------------------------------------------------------------------------------------
