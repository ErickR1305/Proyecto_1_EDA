#include <stdio.h>
#include "Carrito.h"
#include "inventario.h"

Articulo *CrearArticulo(){
    Articulo *nuevoArticulo;
    nuevoArticulo=(Articulo *)malloc(1*sizeof(Articulo));
    if(nuevoArticulo==NULL){
        printf("No se pudo asignar memoria...");
        exit(1);
    }
    nuevoArticulo->info.nombre=(char *)malloc(30*sizeof(char));
        if(nuevoArticulo->info.nombre==NULL){
            printf("No se logró asignar memoria correctamente...");
            exit(1);
        }
    return nuevoArticulo;

}
void CapturarArticulo(Articulo *unArticulo,Articulo *Arreglo,int num,float *cont){
    int indice;
    do{
    indice=rand()%num;
    unArticulo->info.nombre=Arreglo[indice].info.nombre;
    unArticulo->info.precio=Arreglo[indice].info.precio;
    }while(Arreglo[indice].info.inventario==0);
    Arreglo[indice].info.inventario--;
    (*cont)+=Arreglo[indice].info.precio;
}



void ListarArticulo(Articulo unArticulo){
    printf("\nArticulo: %s\n",unArticulo.info.nombre);
    printf("Precio: %.2f\n",unArticulo.info.precio);

}
void LiberarArticulo(Articulo *unArticulo){
    free(unArticulo->info.nombre);
    free(unArticulo);
    unArticulo=NULL;
}
