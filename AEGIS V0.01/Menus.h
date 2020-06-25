#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#pragma once

///Prototipos de los Menus.


void menuVentas();
void menuPrincipal();
void menuABM();
void abmClientes();
void abmProducto();
void abmProveedor();



///Menus Completos
void menuPrincipal()
{
    setColor(WHITE);
    cout<<"                           MENU PRINCIPAL"          <<endl;
    cout<<"                  _________________________________"<<endl;
    cout<<"                 |-1-->VENTAS                     -|"<<endl;
    cout<<"                 |-2-->ABM                        -|"<<endl;
    cout<<"                 |-3-->LISTADOS                   -|"<<endl;
    cout<<"                 |-4-->COMPRAS                    -|"<<endl;
    cout<<"                 |-5-->CONFIGURACION              -|"<<endl;
    cout<<"                 |-0-->SALIR                      -|"<<endl;
    cout<<"                 |_________________________________|"<<endl;
    cout<<"                  -------Ingrese una opcion--------"<<endl;
}
void menuVentas()
{

    int op;
    bool salir=false;
    system("cls");

    while(!salir)
    {
        setColor(YELLOW);
        system("cls");
        cout<<"                           VENTAS"          <<endl;
        cout<<"                  _________________________________"<<endl;
        cout<<"                 |-1-->Nueva Venta                -|"<<endl;
        cout<<"                 |-2-->Nota de Crédito            -|"<<endl;
        cout<<"                 |-3-->Presupuestos               -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                 |_________________________________|"<<endl;
        cout<<"                  -------Ingrese una opcion--------"<<endl;
        cin>>op;

        switch(op)
        {
        case 1:
        {

            system("cls");
            cout<<"                   ~NUEVA VENTA~        "<<endl;


        }
        break;
        case 2:
        {
            system("cls");
            cout<<"                 ~Nota de Crédito~                "<<endl;

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
        cout<<"                                ABM                "<<endl;
        cout<<"                  _________________________________"<<endl;
        cout<<"                 |-1-->Clientes                   -|"<<endl;
        cout<<"                 |-2-->Productos                  -|"<<endl;
        cout<<"                 |-3-->Proveedores                -|"<<endl;
        cout<<"                 |-4-->Vendedores                 -|"<<endl;
        cout<<"                 |-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-|"<<endl;
        cout<<"                 |-0-->VOLVER                     -|"<<endl;
        cout<<"                 |_________________________________|"<<endl;
        cout<<"                  -------Ingrese una opcion--------"<<endl;
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
            cout<<"                 ~~               "<<endl;
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
        cout<<"                             ABM Clientes          "<<endl;
        cout<<"                  _________________________________"<<endl;
        cout<<"                 |-1-->Nuevo Cliente.             -|"<<endl;
        cout<<"                 |-2-->Modificar Cliente.         -|"<<endl;
        cout<<"                 |-3-->Mostrar Cliente.           -|"<<endl;
        cout<<"                 |-4-->Mostrar Todos los Clientes.-|"<<endl;
        cout<<"                 |-5-->Eliminar Cliente.          -|"<<endl;
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


            cout<<"            ~ Nuevo Cliente ~          "<<endl;
            Cliente cli;
            cli.cargar();
            anykey();
        }
        break;

        case 2:
        {

        }
        break;

        case 0:
        {
            salir=true;
        }
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
            pro.guardarProducto();
            anykey();

        }
        break;

        case 2:
        {///MODIFICAR POR ID /HACER

        }
        break;
        case 3:
        {///MOSTRAR POR ID /HACER
          pro.mostrar();
        }
        break;
         case 4:
        {
           pro.listarProductos();
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
            Proveedor prove;
            prove.cargar();
            anykey();
        }
        break;

        case 2:
        {

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
