#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

Articulo *crearArreglo(int max){
    Articulo *nuevoArreglo;
    nuevoArreglo=(Articulo *)malloc(max*sizeof(Articulo));
    if(nuevoArreglo==NULL){
        printf("\nNo se pudo asignar memoria...\n");
    }
    nuevoArreglo->proveedor=(Proveedor *)malloc(2*sizeof(Proveedor));
        if(nuevoArreglo->proveedor==NULL){
            printf("\nNo se pudo asignar memoria...\n");
            }
    for(int i=0;i<2;i++){
        nuevoArreglo->proveedor[i].Nombre=(char *)malloc(30*sizeof(char));
            if(nuevoArreglo->proveedor[i].Nombre==NULL){
                printf("\nNo se pudo asignar memoria...\n");
                }
        nuevoArreglo->proveedor[i].Apellido=(char *)malloc(30*sizeof(char));
            if(nuevoArreglo->proveedor[i].Apellido==NULL){
                printf("\nNo se pudo asignar memoria...\n");
                }
    }
    nuevoArreglo->info.nombre=(char *)malloc(30*sizeof(char));
        if(nuevoArreglo->info.nombre==NULL){
            printf("\nNo se pudo asignar memoria...\n");
        }
    nuevoArreglo->info.Nom_departamento=(char *)calloc(30,sizeof(char));
        if(nuevoArreglo->info.Nom_departamento==NULL){
            printf("\nNo se pudo asignar memoria...\n");
        }

    return nuevoArreglo;
}

void insertarArticulo(int indice,int max,Articulo *unArreglo){
    if(indice>=max){
        printf("\n ERROR: se ha alcanzado el limite de articulos");
    }else{
        printf("\n Ingrese el nombre del articulo:");
        scanf("%s",unArreglo[indice].info.nombre);
        printf("\n Ingrese el codigo del articulo:");
        scanf("%d",&unArreglo[indice].info.codigo);
        printf("\n Ingrese el precio del articulo:");
        scanf("%f",&unArreglo[indice].info.precio);
        printf("\n Ingrese el inventario del articulo:");
        scanf("%d",unArreglo[indice].info.inventario);
        printf("\n Ingrese el departamento:");
        scanf("%s",unArreglo[indice].info.Nom_departamento);
        for(int i=0;i<2;i++){
        printf("\n Ingrese el proveedor:\n Nombre[%d]:",i+1);
        scanf("%s",unArreglo[indice].proveedor[i].Nombre);
        printf("Apellido:");
        scanf("%s",unArreglo[indice].proveedor[i].Apellido);
        }
        getchar();

    }
}


/*
codigo;
    float precio;
    int *inventario;
    char *nombre[30];*/
