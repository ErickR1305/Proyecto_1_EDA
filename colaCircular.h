#ifndef COLACIRCULAR_H_INCLUDED
#define COLACIRCULAR_H_INCLUDED
#include "Cliente.h"
typedef struct {
    int max; // tama�o de la cola
    int h;
    int t;
    Cliente *arrCola; //arreglo cola
} ColaCircular;

//OPERACIONES DEL TAD COLA
void insertar(ColaCircular *colaC, Cliente dato) ;
Cliente borrar(ColaCircular *colaC);

//OPERACIONES AUXILIARES
ColaCircular *crearColaCircular(int max);
int validarEspacio(ColaCircular colaC);
int validarVacio(ColaCircular colaC);
void listar(ColaCircular colaC);
void liberarMemoria(ColaCircular *colaC);

#endif // COLACIRCULAR_H_INCLUDED
