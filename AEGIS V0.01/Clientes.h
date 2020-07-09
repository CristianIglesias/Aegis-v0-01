#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#pragma once
#include "Persona.h"
class Cliente: public Persona
{
public:

    void cargar();                     ///                ///carga
    void mostrar();                    ///                ///Muestra el que la llama
    bool LeerxID(int id);              ///   Leer por posición-(solo cambiart nombre)
    void mostrarxID ();                ///                ///Muestra Por posicion-
    void Generarid();                  ///  NO ES METODO.
    int  GuardarClienteEnDisco();      ///                ///Agrega Clientes al final del archivo.
    int  GuardarClienteEnDisco(int POS); ///                ///Sobreescribe Clientes X id
    void Modificar();                  ///  NO ES METODO.
    void menuModificarCliente();       ///  NO ES METODO.
    void EliminarCliente();            ///  NO ES METODO. ONDA SI, PERO NO ESTÁ BIEN ARMADO. (set estado false, guardar por pos

    int SetTipoPago();                 ///
    int ValidarTipoPago();             ///
    int SetPrefFact();                 ///
    int ValidarPrefFact();             ///
    void SetDeuda();///
    int GetidCliente();                ///
    int GetTipoPago();                 ///
    int GetTipoFactura();              ///
    float GetDeuda();                  ///


protected:
    int idCliente;
    int TipodePago;
    int PrefFactura;
    float Deuda;
};


#endif // CLIENTES_H_INCLUDED
