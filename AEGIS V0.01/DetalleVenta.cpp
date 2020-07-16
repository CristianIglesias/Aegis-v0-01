#include <iostream>
#include <iomanip>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "DetalleVenta.h"
#include "Fecha.h"

const char *ArchivoDetalle ="DetalleVenta.dat";

int DetalleVenta:: CargarDetalle(Venta *obj)
{
    int error=-1,op;
    idVenta=obj->getID();
    error=setIdProducto();
    if(error==-2)
        return 1;
    error=setCantidad();
    if(error==-1)
        return 1;
    error=GuardarDetalle(this);
    if(error!=0)
    {
        cout<<"Hubo un error Guardando el Detalle en el Archivo."<<endl;
        cout<<"Ingrese cualquier tecla para continuar"<<endl;
        anykey();
    }
    else
    {
        cout<<"Detalle Guardado en el Archivo con Exito!"<<endl;
        cout<<"Desea agregar mas items a la venta? "<<endl;
        cout<<"SI :1             NO:0"<<endl;
        cin>>op;

        switch(op)
        {
        case 1:
            return 0;
            break;
        case 0:
            error=-2;
            return error;
            break;
        }
    }

    return error;
}

DetalleVenta::DetalleVenta()
{
    idVenta=0;
    PrecioUnidad=0;
    Cantidad=0;
    PrecioTotal=0;
};
int DetalleVenta::setIdProducto()
{
    char Cod[10];
    int  i=0,error,op;
    Producto Reg;
    while(error!=0)
    {
        cls();
        cout<<" Ingrese el ID del Producto a Vender."<<endl;
        cout<<"ID PRODUCTO: ";
        ///cin.ignore();
        cin.getline(Cod,10);
        error=Reg.LeerxID(Cod);
        if(error==4)
            return 1;
        if(error==false)
            error=-1;
        if(error==-1)
        {
            i++;
            error_msj(-5,i);
        }
        if(error==true)
        {

            cout<<"El Producto deseado es : " << Reg.getNombreItem()<<"?"<<endl;
            cout<<"El Precio del Producto es de :$ " << Reg.getPrecioVenta()<<endl;
            setPrecioUnidad(Reg.getPrecioVenta());
            cout<<"SI :1             NO:0"<<endl;
            cin>>op;
            switch(op)
            {
            case 1:
                strcpy(this->idProducto,Reg.getCodigoProducto());
                return error;
                break;
            case 0:
                error=-2;
                break;
            }

            return 0;
        }

    }
};
int DetalleVenta :: setCantidad()
{
    int error=-1,i=0;
    while (error<0)
    {
        cout<<"Ingrese la Cantidad de Unidades del Producto que va a Comprar"<<endl;
        cin>>Cantidad;
        error=ValidarEntero(Cantidad);
        if(error==1)
            return -1;
        if(error==-1)
        {
            i++;
            error_msj(-4,i);
        }
        if (error==0)
        {
            error=setPrecioTotal();
        }

    }
    return error;
};
int DetalleVenta::setPrecioTotal()
{
    int op;
    cout<<"Quedaría un total de :$"<<getImporteTotal();
    cout<<" ¿Desea Modificar la cantidad?"<<endl;
    cout<<"SI: 1              NO: 0"<<endl;
    cin>>op;
    switch(op)
    {
    case 1:
    {
        return -2;
    }
    case 0:
    {
        return 2;
    }

    }
};
int GuardarDetalle(DetalleVenta *Obj)
{
    FILE *p;
    p=fopen(ArchivoDetalle,"ab");
    if(p==NULL)
    {
        return -1;
    }
    if(fwrite(Obj,sizeof(DetalleVenta),1, p)!=1)
    {
        fclose(p);
        return -1;
    }
    fclose (p);
    return 0;
}


int  MostrarDetalles(Venta *Reg)
{
    int error=0, CantRegs=0;
    DetalleVenta *VecDin;
    CantRegs=ContarDetallesXID(Reg->getID());
    if(CantRegs<0)
        error_msj(-6,0);
    VecDin=new DetalleVenta[CantRegs];
    if(VecDin==NULL)
        error_msj(-7,0);
    error=CargarDetallesVenta(VecDin,CantRegs,Reg->getID());
    if(error<0)
        error_msj(-6,0);
    MostrarDetallesTABLA(VecDin,CantRegs);
    free(VecDin);
    return 0;
};

int ContarDetallesXID(int ID)
{
    DetalleVenta Aux;
    int cont=0;
    FILE *P;
    P=fopen(ArchivoDetalle,"rb");
    if(P==NULL)
    {
        fclose(P);
        return -1;
    }
    while(fread(&Aux,sizeof(DetalleVenta),1,P)==1)
    {
        if(Aux.getIdVenta()==ID)
            cont++;
    }
    fclose(P);
    return cont;
}

int CargarDetallesVenta(DetalleVenta *Vec, int Cant, int ID)
{
    FILE *P;
    int i=0;
    P=fopen(ArchivoDetalle,"rb");
    if(P==NULL)
    {
        fclose(P);
        return -1;
    }
    while(fread(&Vec[i],sizeof(DetalleVenta),1,P)==1)
    {
        if(Vec[i].getIdVenta()==ID)
            i++;
    }
    ///Creo que haría falta alguna validación de que i==Cant, para corroborar que se cargó el vector entero :/
    fclose(P);
    return 0;
}

int MostrarDetallesTABLA(DetalleVenta *Vec, int Cant)
{
    int i=0;
    setColor(LIGHTBLUE);
    cout<<endl;
    DetalleDeVentaTabla();

    cout<<endl;
    while(i<Cant)
        {Vec[i].Mostrar();}
    setColor(WHITE);
}

void DetalleVenta :: Mostrar()
{
    Producto Aux;
    Aux.LeerxID(this->idProducto);
    setColor(WHITE);
    cout<< left;
    cout<<setw(5)<<getIdProducto()<<"\t"<<endl;;
    cout << right;
    cout<<setw(10)<<Aux.getNombreItem()<<endl;
    cout<< left;
    cout<<setw(5)<<"$"<<getPrecioUnidad()<<"\t    "<<endl;
    cout<<setw(5)<<getCantidad()<<"\t"<<endl;
    cout<<setw(5)<<getImporteTotal()<<"\t"<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
}

