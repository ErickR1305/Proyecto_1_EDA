#include <stdio.h>
#include <stdlib.h>
#include "colaCircular.h"

ColaCircular *crearColaCircular(int max) {
    ColaCircular *nuevaCola;
    //crear la cola y el arreglo
    nuevaCola = malloc(1 * sizeof(ColaCircular));
    nuevaCola->arrCola = (Cliente *) calloc(max,sizeof(Cliente));
    //INICIALIZAR
    nuevaCola->max = max;
    nuevaCola->h = nuevaCola->t= -1;
    return nuevaCola;
}

int validarEspacio(ColaCircular colaC){
    if ((colaC.h == 0 && colaC.t == colaC.max-1)
        || (colaC.t == colaC.h-1)){
        printf("\nNo hay espacio...\n");
        return 0;
    }
    return 1;
}

void insertar(ColaCircular *colaC, Cliente dato) {
    if (colaC->h == -1) //cola vacia
        colaC->h= 0;//INICIO DE LA FILA
    if (colaC->t == colaC->max-1)
        colaC->t = -1;

    colaC->t++;

    //INSERTA EL DATO EN LA FILA
    colaC->arrCola[colaC->t]=dato;
}

void listar(ColaCircular colaC){
   int i;
   printf("\n\tCOLA:");
   if (!validarVacio(colaC)){
        if (colaC.h<= colaC.t){
           for (i=colaC.h; i<=colaC.t ; i++)
                ListarCliente(colaC.arrCola[i]);
        }
        else {
            for (i=colaC.h; i<colaC.max; i++)
                ListarCliente(colaC.arrCola[i]);
            for (i=0; i<=colaC.t; i++)
                ListarCliente(colaC.arrCola[i]);
        }
   }
   else
        printf("  No hay clientes...");
}
int validarVacio(ColaCircular colaC){
    return colaC.h == -1;
}


Cliente borrar(ColaCircular *colaC){
    Cliente aux= colaC->arrCola[colaC->h];
    if (colaC->h == colaC->t)
        colaC->h = colaC->t = -1;
    else if (colaC->h == colaC->max-1)
        colaC->h = 0;
    else
        colaC->h++;
    return aux;
}


void liberarMemoria(ColaCircular *colaC){
    free(colaC->arrCola);
    free(colaC);
    colaC = NULL;
}
