#ifndef PROTOTIPOSGLOBALES_H_INCLUDED
#define PROTOTIPOSGLOBALES_H_INCLUDED
#pragma once
#include "PrototiposClases.h"
#include "Fecha.h"
#


void error_msj(int cod,int i);

int ValidarTexto(const char *cad );

int ValidarEnteros( const char *Telefono);

int ValidarFloats(float);

int ValidarEntero(int c);


void ListarClientes();
void listarProductos();
void listarProveedores();
void ListarVendedores();
///void listadoDeVentas();
void mostrarCadenas(const char *cad);

void LineasSuperior();
void LineasInferior();
void LineasInferior2();
void LineasInferior3();



#endif // PROTOTIPOSGLOBALES_H_INCLUDED
