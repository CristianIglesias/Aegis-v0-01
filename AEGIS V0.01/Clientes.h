#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#pragma once
#include "Persona.h"
class Cliente:public Persona
{
public:

    void cargar();
    void mostrar();
    int GetidCliente();
    int GetTipoPago();
    int GetTipoFactura();
    float GetDeuda();
    void SetTipoPago(int);
    void SetPrefFact(int);
    void SetDeuda(float);
    void Generarid();


protected:
    int idCliente;
    int TipodePago;
    int PrefFactura;
    float deuda;



};

#endif // CLIENTES_H_INCLUDED
