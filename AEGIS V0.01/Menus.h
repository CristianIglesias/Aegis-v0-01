#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#pragma once
#include <conio.h>
#include "PrototiposClases.h"
#include "PrototiposGlobales.h"
#include "Clientes.h"
#include "Ventas.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Vendedor.h"

///Prototipos de los Menus.
void menuVentas();
void menuPrincipal();
void menuABM();
void abmClientes();
void abmProducto();
void abmProveedor();
void abmVendedor();
void menuListados();
void menuReportes();
void menuConfiguracion();

///Menus Completos
void menuPrincipal()
{
    int x;
    for(x=1; x<118; x++)
    {
        gotoxy(x,1);
        cout<<"="<<endl;
        if(x<=20)
        {
            gotoxy(1,x);
            cout<<"||"<<endl;

        }

    }

    setColor(LIGHTMAGENTA);
    cout<<endl;
    cout<<endl;
    cout<<" \t" "                                          MENU PRINCIPAL                        "<<endl;
    setColor(YELLOW);
    cout<<" \t" "                               ___________________________________ "<<endl;
    cout<<" \t" "                              ||1-->VENTAS                       ||"<<endl;
    cout<<" \t" "                              ||2-->COMPRAS                      ||"<<endl;
    cout<<" \t" "                              ||3-->ABM                          ||"<<endl;
    cout<<" \t" "                              ||4-->LISTADOS                     ||"<<endl;
    cout<<" \t" "                              ||5-->REPORTES                     ||"<<endl;
    cout<<" \t" "                              ||6-->CONFIGURACION                ||"<<endl;
    cout<<" \t" "                              ||0-->SALIR                        ||"<<endl;
    cout<<" \t" "                              ||_________________________________||"<<endl;

    cout<<" \t" "                                -------Ingrese una opcion--------   "<<endl;

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
};

void menuVentas()
{
    Venta V;
    int op;
    bool salir=false;
    system("cls");

    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<endl;

        cout<<"   \t""                                           VENTAS                   "<<endl;
        setColor(YELLOW);
        cout<<"   \t""                              ___________________________________ "<<endl;
        cout<<"   \t""                             ||-1 -->Nueva Venta.               -||"<<endl;
        cout<<"   \t""                             ||-2 -->Acceso rapido a Listados   -||"<<endl;
        cout<<"   \t""                             ||-2 -->Nota de Cr�dito.           -||"<<endl;
        cout<<"   \t""                             ||-3 -->Presupuestos.              -||"<<endl;
        cout<<"   \t""                             ||.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-||"<<endl;
        cout<<"   \t""                             ||-0-->VOLVER                      -||"<<endl;
        cout<<"   \t""                             ||__________________________________||"<<endl;
        cout<<"   \t""                              -------Ingrese una opcion-------- "<<endl;
        LineasInferior();
        cin>>op;

        switch(op)
        {
        case 1:
        {
            system("cls");
            cout<<"                   ~NUEVA VENTA~        "<<endl;
            V.GenerarVenta();
            V.Mostrar();
            MostrarDetalles(&V);
        }
        break;
        case 2:
        {
            system("cls");

            menuListados();
        }
        break;
        case 3:
        {
            system("cls");
            cout<<"                 ~Nuevo Presupuesto~               "<<endl;

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
        system("pause");

    }

}
void menuConfiguracion()
{
     int opcion;
    bool salir=false;

    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");

        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<endl;

        cout<<"  \t""                                              CONFIGURACION                "<<endl;
        setColor(YELLOW);
        cout<<"  \t""                                     ___________________________________"<<endl;
        cout<<"  \t""                                    ||-99-->ELIMINAR TODOS LOS REGISTROS ||"<<endl;
         cout<<" \t""                                    ||-1-->Eliminar registro Clientes  ||"<<endl;
         cout<<" \t""                                    ||-2-->Eliminar registro Productos ||"<<endl;
         cout<<" \t""                                    ||-3-->Eliminar registro Proveedores  ||"<<endl;
         cout<<" \t""                                    ||-4-->Eliminar registro Vendedores  ||"<<endl;
         cout<<" \t""                                    ||-5-->Eliminar registro Ventas  ||"<<endl;
         cout<<" \t""                                    ||-6-->Eliminar registro Detalles  ||"<<endl;
        cout<<"  \t""                                    ||-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.||"<<endl;
        cout<<"  \t""                                    ||-0-->VOLVER                       ||"<<endl;
        cout<<"  \t""                                    ||__________________________________||"<<endl;
        cout<<"  \t""                                     -------Ingrese una opcion-------- "<<endl;
        LineasInferior();
        cin>>opcion;

        switch(opcion)
        {
        case 99:
        {
            int opc;
            system("cls");
            cout<<"            ~ ELIMINAR TODOS LOS REGISTROS~          "<<endl;
            cout<<"�Esta seguro que quiere eliminar todos los registros?"<<endl;
            cout<<"9-->SI"<<endl;
            cout<<"2-->NO"<<endl;
            cin>>opc;
            switch(opc)
            {
                case 9:
                    {
                        cout<<"Registros eliminados"<<endl;
            FILE *a;
            a=fopen("Clientes.dat","wb");
            fclose(a);

             FILE *b;
            b=fopen("Vendedor.dat","wb");
            fclose(b);

             FILE *c;
            c=fopen("Proveedor.dat","wb");
            fclose(c);

             FILE *d;
            d=fopen("Producto.dat","wb");
            fclose(d);

            FILE *v;
            v=fopen("Ventas.dat","wb");
            fclose(v);

             FILE *dv;
            dv=fopen("DetalleVenta.dat","wb");
            fclose(dv);

                    }break;
                case 2:
                    {
                        cls();
                        cout<<"VOLVIENDO AL MENU ANTERIOR"<<endl;
                        salir=true;
                        anykey();
                    }break;
            }
        }
        break;
         case 1:
        {
           cout<<" Eliminar registro clientes  "<<endl;
            FILE *a;
            a=fopen("Clientes.dat","wb");
            fclose(a);

        }break;
          case 2:
        {
           cout<<" Eliminar registro Productos  "<<endl;

             FILE *d;
            d=fopen("Producto.dat","wb");
            fclose(d);

        }break;
          case 3:
        {
           cout<<" Eliminar registro Proveedores  "<<endl;

             FILE *c;
            c=fopen("Proveedor.dat","wb");
            fclose(c);

        }break;
        case 4:
        {
           cout<<" Eliminar registro Vendedores  "<<endl;
           FILE *b;
            b=fopen("Vendedor.dat","wb");
            fclose(b);

        }break;
         case 5:
        {
           cout<<" Eliminar registro Ventas  "<<endl;
            FILE *v;
            v=fopen("Ventas.dat","wb");
            fclose(v);

        }break;
        case 6:
        {
           cout<<" Eliminar registro Detalles  "<<endl;

             FILE *dv;
            dv=fopen("DetalleVenta.dat","wb");
            fclose(dv);

        }break;
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
        system("pause");

    }
}
void menuABM()
{
    int op;
    bool salir=false;

    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");

        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<endl;

        cout<<"  \t""                                                    ABM                 "<<endl;
        setColor(YELLOW);
        cout<<"  \t""                                     _________________________________ "<<endl;
        cout<<"  \t""                                    ||-1-->Clientes                   ||"<<endl;
        cout<<"  \t""                                    ||-2-->Productos                  ||"<<endl;
        cout<<"  \t""                                    ||-3-->Proveedores                ||"<<endl;
        cout<<"  \t""                                    ||-4-->Vendedores                 ||"<<endl;
        cout<<"  \t""                                    ||-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.||"<<endl;
        cout<<"  \t""                                    ||-0-->VOLVER                     ||"<<endl;
        cout<<"  \t""                                    ||________________________________||"<<endl;
        cout<<"  \t""                                     -------Ingrese una opcion-------- "<<endl;
        LineasInferior();
        cin>>op;

        switch(op)
        {
        case 1:
        {

            system("cls");
            cout<<"            ~ ABM CLIENTES ~          "<<endl;
            abmClientes();

        }
        break;
        case 2:
        {
            system("cls");
            cout<<"               ~ABM PRODUCTOS~                "<<endl;
            abmProducto();
        }
        break;
        case 3:
        {
            system("cls");
            cout<<"                 ~ABM PROVEEDORES~               "<<endl;
            abmProveedor();
        }
        break;
        case 4:
        {
            system("cls");
            cout<<"                 ~ABM VENDEDORES~               "<<endl;
            abmVendedor();
        }
        break;

        case 5:
        {
            system("cls");
            cout<<"                 ~~          "<<endl;

        }
        break;
        case 6:
        {
            system("cls");
            cout<<"                  ~~               "<<endl;
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
        system("pause");

    }

}
void abmClientes()
{

    int op;
    bool salir=false;

    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<endl;

        cout<<"                                                      ABM Clientes           "<<endl;
        setColor(YELLOW);
        cout<<"                                            _________________________________ "<<endl;
        cout<<"                                           ||-1-->Nuevo Cliente.             ||"<<endl;
        cout<<"                                           ||-2-->Modificar Cliente.         ||"<<endl;
        cout<<"                                           ||-3-->Mostrar Cliente.           ||"<<endl;
        cout<<"                                           ||-4-->Mostrar Todos los Clientes.||"<<endl;
        cout<<"                                           ||-5-->Eliminar Cliente.          ||"<<endl;
        cout<<"                                           ||-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.||"<<endl;
        cout<<"                                           ||-0-->VOLVER                     ||"<<endl;
        cout<<"                                           ||________________________________||"<<endl;
        cout<<"                                            -------Ingrese una opcion-------- "<<endl;
        LineasInferior();
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
        {

            cout<<"            ~ Nuevo Cliente ~          "<<endl;
            Cliente cli;
            cli.cargar();
            anykey();
        }
        break;
        case 2:
        {
            cout<<"            ~Modificar Cliente ~          "<<endl;
            ModificarCliente();
        }
        break;
        case 3:
        {
            cout<<"            ~ Mostrar Cliente ~          "<<endl;
            Cliente Cli;
            Cli.mostrarxID();
            anykey();
        }
        break;

        case 4:
        {
            cout<<"            ~ Mostrar Clientes ~          "<<endl;

            ListarClientes();
            anykey();
        }
        break;
        case 5:
        {
            cout<<"            ~ Eliminar Cliente ~          "<<endl;
            Cliente Reg;
            Reg.EliminarCliente();


        }
        break;
        case 0:
        {
            salir=true;
        }
        break;


        }///Cierra el switch

    }///Cierra el while
};


void abmProducto()
{
    Producto pro;
    int op;
    bool salir=false;

    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<endl;
        cout<<"                                                     ABM Producto          "<<endl;
        setColor(YELLOW);
        cout<<"                                          _________________________________"<<endl;
        cout<<"                                         ||-1-->Nuevo Producto.            ||"<<endl;
        cout<<"                                         ||-2-->Modificar Producto.        ||"<<endl;
        cout<<"                                         ||-3-->Mostrar Producto.          ||"<<endl;
        cout<<"                                         ||-4-->Mostrar Todos los Productos||"<<endl;
        cout<<"                                         ||-5-->Eliminar Producto.         ||"<<endl;
        cout<<"                                         ||-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- ||"<<endl;
        cout<<"                                         ||-0-->VOLVER                     ||"<<endl;
        cout<<"                                         ||________________________________||"<<endl;
        cout<<"                                          -------Ingrese una opcion--------"<<endl;
        LineasInferior();
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
        {


            cout<<"                     ~ Nuevo Producto ~          "<<endl;

            pro.cargar();
            anykey();

        }
        break;

        case 2:
        {
            cout<<endl;
            cout<<endl;
            cout<<"                                                        ~MODIFICAR PRODUCTOS~               "<<endl;

            pro.modificar_producto() ;
            anykey();
        }
        break;
        case 3:
        {
            cout<<"                      ~LISTAR PRODUCTOS X ID~               "<<endl;

            pro.mostrarxID();
            anykey();
        }
        break;
        case 4:
        {
            cout<<"                      ~LISTAR PRODUCTOS~               "<<endl;
            listarProductos();
            anykey();
        }
        break;
        case 5:
        {
            cout<<"                      ~ELIMINAR PRODUCTOS~               "<<endl;

            pro.Eliminar();
            anykey();
        }
        break;

        case 0:
        {
            salir=true;


        }break;


        }///Cierra el switch

    }///Cierra el while
};

void abmProveedor()
{

    int op;
    bool salir=false;
    Proveedor prove;
    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<endl;

        cout<<"                                                         ABM Proveedor          "<<endl;
        setColor(YELLOW);
        cout<<"                                             ____________________________________"<<endl;
        cout<<"                                            ||-1-->Nuevo Proveedor.              ||"<<endl;
        cout<<"                                            ||-2-->Modificar Proveedor.          ||"<<endl;
        cout<<"                                            ||-3-->Mostrar Proveedor.            ||"<<endl;
        cout<<"                                            ||-4-->Mostrar Todos los Proveedores.||"<<endl;
        cout<<"                                            ||-5-->Eliminar Proveedor.           ||"<<endl;
        cout<<"                                            ||-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-||"<<endl;
        cout<<"                                            ||-0-->VOLVER                        ||"<<endl;
        cout<<"                                            ||___________________________________||"<<endl;
        cout<<"                                             -------Ingrese una opcion--------"<<endl;
        LineasInferior();
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
        {


            cout<<"            ~ Nuevo Proveedor ~          "<<endl;

            prove.cargar();
            prove.guardarProveedor();
            anykey();
        }
        break;

        case 2:
        {
            cout<<"            ~ Modificar Proveedor ~          "<<endl;
            ModificarProveedor();
            anykey();

        }
        break;

        case 3:
        {
            cout<<"            ~ Mostrar Proveedor ~          "<<endl;
            prove.mostrarxID();
            anykey();
        }
        break;

        case 4:
        {
            cout<<"            ~ Mostrar todos los Proveedores ~          "<<endl;
            listarProveedores() ;
            anykey();
        }
        break;
        case 5:
        {
            cout<<"            ~ ELIMINAR ~          "<<endl;
            prove.EliminarProveedor();
            anykey();
        }
        break;

        case 0:
        {
            salir=true;

        }break;



        }
    }
};

void abmVendedor()
{

    int op;
    bool salir=false;
    Vendedor ven;
    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<endl;

        cout<<"                                                        ABM Vendedor          "<<endl;
        setColor(YELLOW);
        cout<<"                                             __________________________________"<<endl;
        cout<<"                                            ||1-->Nuevo Vendedor.              ||"<<endl;
        cout<<"                                            ||2-->Modificar Vendedor.          ||"<<endl;
        cout<<"                                            ||3-->Mostrar Vendedor.            ||"<<endl;
        cout<<"                                            ||4-->Mostrar Todos los Vendedores.||"<<endl;
        cout<<"                                            ||5-->Eliminar Vendedor.           ||"<<endl;
        cout<<"                                            ||-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-||"<<endl;
        cout<<"                                            ||0-->VOLVER                       ||"<<endl;
        cout<<"                                            ||_________________________________||"<<endl;
        cout<<"                                             -------Ingrese una opcion--------"<<endl;
        LineasInferior();
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
        {


            cout<<"            ~ Nuevo Vendedor ~          "<<endl;

            ven.cargar();
            anykey();
        }
        break;

        case 2:
        {
            cout<<"            ~Modificar Vendedor.  ~          "<<endl;
            ModificarVendedor();
            anykey();
        }
        break;

        case 3:
        {
            cout<<"            ~ Mostrar Vendedor.  ~          "<<endl;
            ven.mostrarxID();
            anykey();
        }
        break;

        case 4:
        {
            cout<<"            ~ Mostrar Todos los Vendedores ~          "<<endl;
            ListarVendedores();
            anykey();
        }
        break;
        case 5:
        {
            cout<<"            ~ Eliminar Vendedor ~          "<<endl;
            ven.EliminarVendedor();
            anykey();
        }
        break;

        case 0:
        {
            salir=true;
        }
        break;

        }

    }
};

void menuListados()
{


    int op;
    bool salir=false;
    while(!salir)
    {
        setColor(LIGHTMAGENTA);
        system("cls");
        LineasSuperior();
        cout<<endl;
        cout<<endl;

        cout<<"                                                      Listados.                         "<<endl;
        setColor(YELLOW);
        cout<<"                                             __________________________________________"<<endl;
        cout<<"                                            ||1--> Mostrar Todas Las Ventas.           ||"<<endl;
        cout<<"                                            ||2--> Ventas Por fecha.(entre una y otra) ||"<<endl;
        cout<<"                                            ||3--> Ventas Por Vendedor.                ||"<<endl;
        cout<<"                                            ||4--> Ventas Por Importe Max.             ||"<<endl;
        cout<<"                                            ||5--> Ventas Por Cliente.                 ||"<<endl;
        cout<<"                                            ||-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-||"<<endl;
        cout<<"                                            ||6--> Mostrar detalles de Venta x ID      ||"<<endl;
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
            ListarTodasVentas();
        }
        break;

        case 2:
        {
            ListadoVentasxFechas();
        }
        break;
        case 3:
        {
            ListadoVentasxVendedor();
        }
        break;
        case 4:
        {
            ListarTodasVentas();
        }
        break;
        case 5:
        {
            ListadoVentasxCliente();
        }
        break;

        case 6:
            {
                MostrarDetallesDeVentaxID();
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
        system("pause");
    }

};



#endif // MENUS_H_INCLUDED
