#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "pila.h"

typedef struct{
    char *Nombre_Cliente;
    Pila *pila;
    float Total;
    float Pago;
    int Productos;
}Cliente;

Cliente *CrearCliente();
void CapturarCliente(Cliente *unCliente,int num,Articulo *arreglo);
void ListarCliente(Cliente unCliente);
void LiberarCliente(Cliente *unCliente);
void AtendiendoCliente(Cliente *unCliente);



#endif // CLIENTE_H_INCLUDED
