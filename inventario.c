#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"
#include <string.h>

Articulo *crearArreglo(int max){
    Articulo *nuevoArreglo;
    nuevoArreglo=(Articulo *)malloc(max*sizeof(Articulo));
    if(nuevoArreglo==NULL){
        printf("\nNo se pudo asignar memoria...\n");
    }
    for(int q=0;q<max;q++){
    nuevoArreglo[q].proveedor=(Proveedor *)malloc(2*sizeof(Proveedor));
        if(nuevoArreglo[q].proveedor==NULL){
            printf("\nNo se pudo asignar memoria...\n");
            }
    for(int i=0;i<2;i++){
        nuevoArreglo[q].proveedor[i].Nombre=(char *)malloc(30*sizeof(char));
            if(nuevoArreglo[q].proveedor[i].Nombre==NULL){
                printf("\nNo se pudo asignar memoria...\n");
                }
        nuevoArreglo[q].proveedor[i].Apellido=(char *)malloc(30*sizeof(char));
            if(nuevoArreglo[q].proveedor[i].Apellido==NULL){
                printf("\nNo se pudo asignar memoria...\n");
                }
    }
    nuevoArreglo[q].info.nombre=(char *)malloc(30*sizeof(char));
        if(nuevoArreglo[q].info.nombre==NULL){
            printf("\nNo se pudo asignar memoria...\n");
        }
    nuevoArreglo[q].info.Nom_departamento=(char *)calloc(30,sizeof(char));
        if(nuevoArreglo[q].info.Nom_departamento==NULL){
            printf("\nNo se pudo asignar memoria...\n");
        }
    }

    return nuevoArreglo;
}

void insertarArticulo(int *indice,int max,Articulo *unArreglo){
    if(*indice>=max){
        printf("\n ERROR: se ha alcanzado el limite de articulos");
    }else{
        printf("\n Ingrese el nombre del articulo:");
        scanf("%s",unArreglo[*indice].info.nombre);
        getchar();
        printf("\n Ingrese el codigo del articulo:");
        scanf("%d",&unArreglo[*indice].info.codigo);
        printf("\n Ingrese el precio del articulo:");
        scanf("%f",&unArreglo[*indice].info.precio);
        printf("\n Ingrese el inventario del articulo:");
        scanf("%d",&unArreglo[*indice].info.inventario);
        printf("\n Ingrese el departamento:");
        scanf("%s",unArreglo[*indice].info.Nom_departamento);
        getchar();
        for(int i=0;i<2;i++){
        printf("\n Ingrese el proveedor:\n Nombre[%d]:",i+1);
        scanf("%s",unArreglo[*indice].proveedor[i].Nombre);
        getchar();
        printf("Apellido:");
        scanf("%s",unArreglo[*indice].proveedor[i].Apellido);
        getchar();
        }
        (*indice)++;

    }
}

void listarArticulos(int indice,Articulo *unArreglo){
    printf("\n ====ARTICULOS REGISTRADOS====");
    for(int i=0;i<indice;i++){
        printf("\n Nombre del articulo: %s",unArreglo[i].info.nombre);
        printf("\n Codigo del articulo: %d",unArreglo[i].info.codigo);
        printf("\n Precio del articulo: %.2f",unArreglo[i].info.precio);
        printf("\n Inventario del articulo: %d",unArreglo[i].info.inventario);
        printf("\n Departamento del articulo: %s",unArreglo[i].info.Nom_departamento);
        for (int p=0;p<2;p++){
            printf("\n Nombre del proveedor [%d]:%s",p+1,unArreglo[i].proveedor[p].Nombre);
            printf("\n Apellido del proveedor [%d]:%s",p+1,unArreglo[i].proveedor[p].Apellido);
        }
        printf("\n\n");
    }
}

void listarUnArticulo(int indice,Articulo*unArreglo){
    printf("\n ====ARTICULO REGISTRADO====");
    printf("\n Nombre del articulo: %s",unArreglo[indice].info.nombre);
    printf("\n Codigo del articulo: %d",unArreglo[indice].info.codigo);
    printf("\n Precio del articulo: %.2f",unArreglo[indice].info.precio);
    printf("\n Inventario del articulo: %d",unArreglo[indice].info.inventario);
    printf("\n Departamento del articulo: %s",unArreglo[indice].info.Nom_departamento);
    for (int i=0;i<2;i++){
        printf("\n Nombre del proveedor [%d]:%s",i+1,unArreglo[indice].proveedor[i].Nombre);
        printf("\n Apellido del proveedor [%d]:%s",i+1,unArreglo[indice].proveedor[i].Apellido);
        }
        printf("\n\n");
    }


void buscarArticulos(int codigo,Articulo*unArreglo,int indice){
    for(int i=0;i<indice;i++){
        if(unArreglo[i].info.codigo==codigo){
            printf("\n El articulo con el codigo %d SI existe, y esta es su info. :",codigo);
            listarUnArticulo(i,unArreglo);
            return;
        }
        }
        printf("\n El articulo con el codigo %d NO existe",codigo);
}

void borrarArticulo(int codigo, Articulo* unArreglo, int* indice) {
    for(int i = 0; i < *indice; i++) {
        if(unArreglo[i].info.codigo == codigo) {
            printf("\n Se eliminara el siguiente articulo con la siguiente info.");
            listarUnArticulo(i, unArreglo);
            
            // Liberar memoria del artículo a eliminar
            free(unArreglo[i].info.nombre);
            free(unArreglo[i].info.Nom_departamento);
            for(int p = 0; p < 2; p++) {
                free(unArreglo[i].proveedor[p].Nombre);
                free(unArreglo[i].proveedor[p].Apellido);
            }
            
            // Si no es el último elemento, copiar el último elemento a esta posición
            if(i != *indice - 1) {
                // Copiar la estructura info
                unArreglo[i].info = unArreglo[*indice-1].info;
                
                // Asignar nuevos punteros para los strings
                unArreglo[i].info.nombre = strdup(unArreglo[*indice-1].info.nombre);
                unArreglo[i].info.Nom_departamento = strdup(unArreglo[*indice-1].info.Nom_departamento);
                
                // Copiar proveedores
                for(int p = 0; p < 2; p++) {
                    unArreglo[i].proveedor[p].Nombre = strdup(unArreglo[*indice-1].proveedor[p].Nombre);
                    unArreglo[i].proveedor[p].Apellido = strdup(unArreglo[*indice-1].proveedor[p].Apellido);
                }
            }
            
            (*indice)--;
            printf("\n Articulo eliminado exitosamente:");
            listarArticulos(*indice, unArreglo);
            return;
        }
    }
    printf("\n El articulo con el codigo %d NO existe", codigo);
}

void actualizarArticulo(int codigo,Articulo*unArreglo,int indice){
    for(int i=0;i<indice;i++){
    if(unArreglo[i].info.codigo==codigo){
        printf("\n Se actualizara el siguiente articulo con la siguiente info.");
        listarUnArticulo(i,unArreglo);
        printf("\n Ingrese el nombre del articulo:");
        scanf("%s",unArreglo[i].info.nombre);
        getchar();
        printf("\n Ingrese el codigo del articulo:");
        scanf("%d",&unArreglo[i].info.codigo);
        printf("\n Ingrese el precio del articulo:");
        scanf("%f",&unArreglo[i].info.precio);
        printf("\n Ingrese el inventario del articulo:");
        scanf("%d",&unArreglo[i].info.inventario);
        printf("\n Ingrese el departamento:");
        scanf("%s",unArreglo[i].info.Nom_departamento);
        getchar();
        for(int p=0;p<2;p++){
        printf("\n Ingrese el proveedor:\n Nombre[%d]:",i+1);
        scanf("%s",unArreglo[i].proveedor[p].Nombre);
        getchar();
        printf("Apellido:");
        scanf("%s",unArreglo[i].proveedor[p].Apellido);
        getchar();
        }
        return;
    }
}
printf("\n El articulo con el codigo %d NO existe",codigo);
}
