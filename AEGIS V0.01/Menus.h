#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#pragma once
#include "Ventas.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Vendedor.h"
#include "PrototiposGlobales.h"


///Prototipos de los Menus.


void menuVentas();
void menuPrincipal();
void menuABM();
void abmClientes();
void abmProducto();
void abmProveedor();
void abmVendedor();



///Menus Completos
void menuPrincipal()
{
    setColor(WHITE);
    cout<<"                           MENU PRINCIPAL             "<<endl;
    cout<<"                  ___________________________________ "<<endl;
    cout<<"                 |-1-->     VENTAS- HACERLO.        -|"<<endl;
    cout<<"                 |-2-->     COMPRAS                 -|"<<endl;
    cout<<"                 |-3-->ABM                          -|"<<endl;
    cout<<"                 |-4-->LISTADOS -ARMAR REPORTE VENTA-|"<<endl;
    cout<<"                 |-5-->CONFIGURACION                -|"<<endl;
    cout<<"                 |-0-->SALIR                        -|"<<endl;
    cout<<"                 |___________________________________|"<<endl;
    cout<<"                  -------Ingrese una opcion--------   "<<endl;
};
void menuVentas()
{
    int op, Tipo=1;
    bool salir=false;
    system("cls");

    while(!salir)
    {
        setColor(YELLOW);
        system("cls");
        cout<<"                           VENTAS                   "<<endl;
        cout<<"                  _________________________________ "<<endl;
        cout<<"                 |-1 -->Nueva Venta.               -|"<<endl;
        cout<<"                 |-2 -->Nota de Cr�dito.           -|"<<endl;
        cout<<"                 |-3 -->Presupuestos.              -|"<<endl;
        cout<<"                 |.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                      -|"<<endl;
        cout<<"                 |__________________________________|"<<endl;
        cout<<"                  -------Ingrese una opcion-------- "<<endl;
        cin>>op;

        switch(op)
        {
        case 1:
        {
            system("cls");
            cout<<"                   ~NUEVA VENTA~        "<<endl;
            ///cargar venta- detalles y eso.
        }
        break;
        case 2:
        {
            system("cls");
            cout<<"                 ~Nota de Cr�dito~                "<<endl;
            Tipo=3;
            ///
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
void menuABM()
{
    int op;
    bool salir=false;

    while(!salir)
    {
        setColor(GREEN);
        system("cls");
        cout<<"                                ABM                 "<<endl;
        cout<<"                  _________________________________ "<<endl;
        cout<<"                 |-1-->Clientes                   -|"<<endl;
        cout<<"                 |-2-->Productos                  -|"<<endl;
        cout<<"                 |-3-->Proveedores                -|"<<endl;
        cout<<"                 |-4-->Vendedores                 -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                 |_________________________________|"<<endl;
        cout<<"                  -------Ingrese una opcion-------- "<<endl;
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
        setColor(GREEN);
        system("cls");
        cout<<"                             ABM Clientes           "<<endl;
        cout<<"                  _________________________________ "<<endl;
        cout<<"                 |-1-->Nuevo Cliente.             -|"<<endl;
        cout<<"                 |-2-->Modificar Cliente.         -|"<<endl;
        cout<<"                 |-3-->Mostrar Cliente.           -|"<<endl;
        cout<<"                 |-4-->Mostrar Todos los Clientes.-|"<<endl;
        cout<<"                 |-5-->Eliminar Cliente.          -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                 |_________________________________|"<<endl;
        cout<<"                  -------Ingrese una opcion-------- "<<endl;
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
            Modificar();
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
        case 99:
        {
            FILE *p;
            p=fopen("Clientes.dat","wb");
            fclose(p);
        }
        break;

        }///Cierra el switch

    }///Cierra el while
};

///abm producto:
void abmProducto()
{
    Producto pro;
    int op;
    bool salir=false;

    while(!salir)
    {
        setColor(GREEN);
        system("cls");
        cout<<"                             ABM Producto          "<<endl;
        cout<<"                  _________________________________"<<endl;
        cout<<"                 |-1-->Nuevo Producto.             -|"<<endl;
        cout<<"                 |-2-->Modificar Producto.         -|"<<endl;
        cout<<"                 |-3-->Mostrar Producto.           -|"<<endl;
        cout<<"                 |-4-->Mostrar Todos los Productos.-|"<<endl;
        cout<<"                 |-5-->Eliminar Producto.          -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                 |_________________________________|"<<endl;
        cout<<"                  -------Ingrese una opcion--------"<<endl;
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
        {


            cout<<"            ~ Nuevo Producto ~          "<<endl;

            pro.cargar();
            pro.guardarNuevoProducto();
            anykey();

        }
        break;

        case 2:
        {
            cout<<"                      ~MODIFICAR PRODUCTOS~               "<<endl;

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

            /// pro.Eliminar();
            anykey();
        }
        break;

        case 0:
        {
            salir=true;
        }
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
        setColor(GREEN);
        system("cls");
        cout<<"                             ABM Proveedor          "<<endl;
        cout<<"                  _________________________________"<<endl;
        cout<<"                 |-1-->Nuevo Proveedor.             -|"<<endl;
        cout<<"                 |-2-->Modificar Proveedor.         -|"<<endl;
        cout<<"                 |-3-->Mostrar Proveedor.           -|"<<endl;
        cout<<"                 |-4-->Mostrar Todos los Proveedores.-|"<<endl;
        cout<<"                 |-5-->Eliminar Proveedor.          -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                 |_________________________________|"<<endl;
        cout<<"                  -------Ingrese una opcion--------"<<endl;
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
            prove.Modificar();
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
        }
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
        setColor(GREEN);
        system("cls");
        cout<<"                             ABM Vendedor          "<<endl;
        cout<<"                  _________________________________"<<endl;
        cout<<"                 |-1-->Nuevo Vendedor.             -|"<<endl;
        cout<<"                 |-2-->Modificar Vendedor.         -|"<<endl;
        cout<<"                 |-3-->Mostrar Vendedor.           -|"<<endl;
        cout<<"                 |-4-->Mostrar Todos los Vendedores.-|"<<endl;
        cout<<"                 |-5-->Eliminar Vendedor.          -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                 |_________________________________|"<<endl;
        cout<<"                  -------Ingrese una opcion--------"<<endl;
        cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
        {


            cout<<"            ~ Nuevo Vendedor ~          "<<endl;

            ven.cargar();
            ven.guardar();
            anykey();
        }
        break;

        case 2:
        {
            cout<<"            ~Modificar Vendedor.  ~          "<<endl;
            ven.Modificar();
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
        }

    }
};


#endif // MENUS_H_INCLUDED
