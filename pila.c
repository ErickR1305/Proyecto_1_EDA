#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "inventario.h"
#include "Carrito.h"

Pila *crearPila(int n){
    Pila *nuevaPila;
    nuevaPila=(Pila *)malloc(1*sizeof(Pila));
    nuevaPila->ArrPila=(Articulo *)calloc(n,sizeof(Articulo));
    nuevaPila->MAX=n;
    nuevaPila->tope=-1;
    return nuevaPila;
}

int ValidarEspacio(Pila pila){
    return(pila.tope>=pila.MAX-1);

}

void push(Articulo dato,Pila *pila){
    pila->tope++;
    pila->ArrPila[pila->tope]=dato;

}

int PilaVacia(Pila pila){
    return(pila.tope==-1);
}

Articulo pop(Pila *pila){
    Articulo aux;
    aux=pila->ArrPila[pila->tope];
    pila->tope--;
    return aux;
}

void Listar(Pila pila){
    for(int i=pila.tope;i>=0;i--){
        ListarArticulo(pila.ArrPila[i]);
    }
}

void Liberar(Pila *pila){
    printf("Liberando memoria...");
    free(pila->ArrPila);
    free(pila);
    pila=NULL;

}
