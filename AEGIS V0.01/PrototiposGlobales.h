#ifndef PROTOTIPOSGLOBALES_H_INCLUDED
#define PROTOTIPOSGLOBALES_H_INCLUDED
#pragma once
#include "PrototiposClases.h"
#include "Fecha.h"



void error_msj(int cod,int i);

int ValidarTexto(const char *cad );

int ValidarEnteros( const char *Telefono);

int ValidarFloats(float);

int ValidarEntero(int c);

///LISTADOS ABM
void ListarClientes();
void listarProductos();
void listarProveedores();
void ListarVendedores();
void mostrarCadenas(const char *cad);

///LINEAS GOTOXY
void LineasSuperior();
void LineasInferior();
void LineasInferior2();
void LineasInferior3();

///HEADERS VENTAS
void HeaderListadoDeVentas1();
void HeaderListadoDeVentas2();
void HeaderMostrarVentasXID();
void MostrarDetalle();
void DetalleDeVentaTabla();

///HEADERS CLIENTE
void HeaderListadoClientes();

///HEADER PRODUCTO
void HeaderProductos();

///HEADER PROVEEDOR
void HeaderProveedor();

///HEADER VENDEDOR
void HeaderVendedor();
#endif // PROTOTIPOSGLOBALES_H_INCLUDED
