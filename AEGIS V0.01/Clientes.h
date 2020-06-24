#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#pragma once
#include "Persona.h"
class Cliente: public Persona
{
public:

    void cargar();
    void mostrar();
    void Generarid();

    int GetidCliente();
    int GetTipoPago();
    int GetTipoFactura();
    float GetDeuda();
    int SetTipoPago();
    int ValidarTipoPago();
    int SetPrefFact();
    int ValidarPrefFact();
    void SetDeuda();

protected:
    int idCliente;
    int TipodePago;
    int PrefFactura;
    float Deuda;



};

#endif // CLIENTES_H_INCLUDED
