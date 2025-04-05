#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

Arreglo_articulos *crearArreglo(int max){
    Arreglo_articulos*nuevoArreglo;
    nuevoArreglo=(Arreglo_articulos*)malloc(sizeof(Arreglo_articulos));
    nuevoArreglo->articulos=(Articulo*)calloc(max,sizeof(Articulo));
    for(int i=0;i<max;i++){
        nuevoArreglo->articulos[i].nombre=(char*)calloc(30,sizeof(char));
    }
    return nuevoArreglo;
}

void insertarArticulo(int indice,int max,Arreglo_articulos *unArreglo){
    if(indice>=max){
        printf("\n ERROR: se ha alcanzado el limite de articulos");
    }else{
        printf("\n Ingrese el codigo del articulo");
        scanf("%d",&unArreglo->articulos[indice].codigo);
        printf("\n Ingrese el precio del articulo");
        scanf("%f",&unArreglo->articulos[indice].precio);
        printf("\n Ingrese el inventario del articulo");
        scanf("%d",unArreglo->articulos[indice].inventario);
        printf("\n Ingrese el nombre del articulo");
        scanf("%s",unArreglo->articulos[indice].nombre);
        getchar();

    }
}

void listarArticulos(int indice, Arreglo_articulos unArreglo) {
    printf("\n ====ARTICULOS====");
    for (int i = 0; i < indice; i++) {
        printf("\n Codigo del articulo: %d", unArreglo.articulos[i].codigo);
        printf("\n Nombre del articulo: %s", unArreglo.articulos[i].nombre);
        printf("\n Precio del articulo: %.2f", unArreglo.articulos[i].precio);
        printf("\n Inventario del articulo: %d",unArreglo.articulos[i].inventario);
        printf("\n\n");
    }
}
//función para leer archivos
void LeerArticulos(Arreglo_articulos *arreglo, int *num_articulos) {
    FILE *dulce = fopen("Dulces.txt", "r");
    if (dulce == NULL) {
        printf("No se pudo acceder al archivo\n");
        return;
    }

    while (*num_articulos < 30 &&
           fscanf(dulce, "%29s %d %d %f",
                  arreglo->articulos[*num_articulos].nombre,
                  &arreglo->articulos[*num_articulos].inventario,
                  &arreglo->articulos[*num_articulos].codigo,
                  &arreglo->articulos[*num_articulos].precio) == 4) {
        (*num_articulos)++;
    }

    fclose(dulce);
}


/*
codigo;
    float precio;
    int *inventario;
    char *nombre[30];*/
