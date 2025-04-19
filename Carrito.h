#ifndef CARRITO_H_INCLUDED
#define CARRITO_H_INCLUDED
#include "inventario.h"

Articulo *CrearArticulo();
void CapturarArticulo(Articulo *unArticulo,Articulo *Arreglo,int num);
void ListarArticulo(Articulo unArticulo);
void LiberarArticulo(Articulo *unArticulo);

#endif // CARRITO_H_INCLUDED
