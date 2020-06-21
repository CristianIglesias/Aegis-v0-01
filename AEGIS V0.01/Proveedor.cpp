#include <iostream>
#include <cstring>
using namespace std;

#include "Persona.h"
#include "Proveedor.h"
const char *ArchivoProveedor ="Proveedor.dat";

///falta agregar validaciones de id.
void  Proveedor:: cargar()///Carga Proveedor.
{
    Persona::Cargar();

    cout<<"INGRESE EL ID DE PROVEEDOR:"<<endl;
    cin.getline(CodigoProveedor,10);

    cout<<"INGRESE % RENTABILIDAD:"<<endl;
    cin>>PorcentajeRentabilidad;
    if(PorcentajeRentabilidad<0)
    {
        cout<<"ERROR! el porcentaje no puede ser menor a 0"<<endl;
        return;
    }

    cout<<"INGRESE ESTADO DE CUENTA:"<<endl;
    cin>>EstadoCuenta;


};
