#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include "colaCircular.h"
#include "inventario.h"

// Prototipos de funciones
void departamentoMenorInventario(Articulo *arreglo, int num_articulos);
void departamentoMayorVenta(Articulo *arreglo, int num_articulos);
Articulo articuloMasCaro(Articulo *arreglo, int num_articulos);
void totalVentasPorDepartamento(Articulo *arreglo, int num_articulos);
Articulo productoMasVendido(Articulo *arreglo, int num_articulos);
void porcentajeInventarioVendido(Articulo *arreglo, int num_articulos);
float promedioPrecio(Articulo *arreglo, int num_articulos);
void listarProductosPorPrecio(Articulo *arreglo, int num_articulos);
int totalInventarioDisponible(Articulo *arreglo, int num_articulos);
Articulo productoMenorInventario(Articulo *arreglo, int num_articulos);
void mostrarEstadisticas(ColaCircular *cola, Articulo *arreglo, int num_articulos);

#endif

