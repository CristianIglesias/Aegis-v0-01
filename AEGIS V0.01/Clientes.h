#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#pragma once
#include "PrototiposClases.h"
#include "PrototiposGlobales.h"
#include "Persona.h"

class Cliente: public Persona
{
public:

    void cargar();                       ///                ///carga
    void mostrar();                      ///                ///Muestra el que la llama
    int LeerxPos(int id);                ///   Leer por posición-(solo cambiart nombre)
    int mostrarxID ();                   ///                ///Muestra Por posicion-
    int  GuardarClienteEnDisco();        ///                ///Agrega Clientes al final del archivo.
    int  GuardarClienteEnDisco(int POS); ///                ///Sobreescribe Clientes X id

    void EliminarCliente();            ///  NO ES METODO. ONDA SI, PERO NO ESTÁ BIEN ARMADO. (set estado false, guardar por pos)

    int SetTipoPago();                 ///
    int ValidarTipoPago();             ///
    int SetPrefFact();                 ///
    int ValidarPrefFact();             ///


    void SetDeuda();///
    int GetidCliente();                ///
    int GetTipoPago();                 ///
    int GetTipoFactura();              ///
    float GetDeuda();                  ///
    void SetIdCliente(int id)
    {
        idCliente=id;
    }

protected:
    int idCliente;
    int TipodePago;
    int PrefFactura;
    float Deuda;
};
void ModificarCliente();
void menuModificarCliente(Cliente *Cli, int pos);
int GenerarIdCliente();

#endif // CLIENTES_H_INCLUDED
