#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#pragma once
#include "Persona.h"
class Cliente: public Persona
{
public:

    void cargar();///carga
    void mostrar();///Muestra el que la llama
    bool LeerxID(int id);
    void mostrarxID ();///Muestra Por ID -
    void Generarid();
    int  GuardarClienteEnDisco();///Agrega Clientes al final del archivo.
    int  GuardarClienteEnDisco(int ID);///Sobreescribe Clientes X id
    void Modificar();
    void menuModificarCliente();
    void EliminarCliente();

    int SetTipoPago();
    int ValidarTipoPago();
    int SetPrefFact();
    int ValidarPrefFact();
    void SetDeuda();
    int GetidCliente();
    int GetTipoPago();
    int GetTipoFactura();
    float GetDeuda();


protected:
    int idCliente;
    int TipodePago;
    int PrefFactura;
    float Deuda;
};


#endif // CLIENTES_H_INCLUDED
