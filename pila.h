
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "inventario.h"

typedef struct{
    Articulo *ArrPila;
    int MAX;
    int tope;
}Pila;

Pila *crearPila(int n);
int ValidarEspacio(Pila pila);
void push(Articulo dato,Pila *pila);
Articulo pop(Pila *pila);
void Listar(Pila pila,int *j);
void Liberar(Pila *pila);

#endif // PILA_H_INCLUDED
