#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#pragma once
#include "Persona.h"
class Cliente: public Persona
{
public:

    void cargar();///carga
    void mostrar();///Muestra el que la llama
    bool LeerDeDisco(int i);///Lee La pos que se le manda.
    void mostrar(int pos);///Muestra por Posición de ID
    void Generarid();
    int  GuardarClienteEnDisco();



    float GetDeuda();
    int SetTipoPago();
    int ValidarTipoPago();
    int SetPrefFact();
    int ValidarPrefFact();
    void SetDeuda();
    int GetidCliente();
    int GetTipoPago();
    int GetTipoFactura();


protected:
    int idCliente;
    int TipodePago;
    int PrefFactura;
    float Deuda;



};

#endif // CLIENTES_H_INCLUDED
