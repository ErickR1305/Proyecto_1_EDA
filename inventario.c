#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"
#include <string.h>

Articulo *crearArreglo(int max) {
    Articulo *nuevoArreglo = (Articulo *)malloc(max * sizeof(Articulo));
    if (nuevoArreglo == NULL) {
        printf("No se pudo asignar memoria para el arreglo de artículos.\n");
        exit(1);
    }

    for (int i = 0; i < max; i++) {
        nuevoArreglo[i].info.nombre = (char *)malloc(30 * sizeof(char));
        if (nuevoArreglo[i].info.nombre == NULL) {
            printf("No se pudo asignar memoria para el nombre del artículo.\n");
            exit(1);
        }

        nuevoArreglo[i].info.Nom_departamento = (char *)malloc(30 * sizeof(char));
        if (nuevoArreglo[i].info.Nom_departamento == NULL) {
            printf("No se pudo asignar memoria para el nombre del departamento.\n");
            exit(1);
        }

        nuevoArreglo[i].proveedor = (Proveedor *)malloc(2 * sizeof(Proveedor));
        if (nuevoArreglo[i].proveedor == NULL) {
            printf("No se pudo asignar memoria para los proveedores.\n");
            exit(1);
        }

        for (int j = 0; j < 2; j++) {
            nuevoArreglo[i].proveedor[j].Nombre = (char *)malloc(30 * sizeof(char));
            if (nuevoArreglo[i].proveedor[j].Nombre == NULL) {
                printf("No se pudo asignar memoria para el nombre del proveedor.\n");
                exit(1);
            }

            nuevoArreglo[i].proveedor[j].Apellido = (char *)malloc(30 * sizeof(char));
            if (nuevoArreglo[i].proveedor[j].Apellido == NULL) {
                printf("No se pudo asignar memoria para el apellido del proveedor.\n");
                exit(1);
            }
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

void listarArticulos(int *i ,Articulo *unArreglo){
        printf("\n Nombre del articulo: %s",unArreglo[*i].info.nombre);
        printf("\n Codigo del articulo: %d",unArreglo[*i].info.codigo);
        printf("\n Precio del articulo: %.2f",unArreglo[*i].info.precio);
        printf("\n Inventario del articulo: %d",unArreglo[*i].info.inventario);
        printf("\n Departamento del articulo: %s num:%d",unArreglo[*i].info.Nom_departamento,
               unArreglo[*i].info.num_dept);
        for (int p=0;p<2;p++){
            printf("\n Proveedor [%d]:%s %s",p+1,unArreglo[*i].proveedor[p].Nombre,
                                            unArreglo[*i].proveedor[p].Apellido);
        }
        (*i)++;
        printf("\n\n");
    }


void listarUnArticulo(int indice,Articulo *unArreglo){
    printf("\n ====ARTICULO REGISTRADO====");
    printf("\n Nombre del articulo: %s",unArreglo[indice].info.nombre);
    printf("\n Codigo del articulo: %d",unArreglo[indice].info.codigo);
    printf("\n Precio del articulo: %.2f",unArreglo[indice].info.precio);
    printf("\n Inventario del articulo: %d",unArreglo[indice].info.inventario);
    printf("\n Departamento del articulo: %s  num:%d",unArreglo[indice].info.Nom_departamento,
           unArreglo[indice].info.num_dept);
    for (int p=0;p<2;p++){
        printf("\n Proveedor [%d]:%s %s",p+1,unArreglo[indice].proveedor[p].Nombre,
                                         unArreglo[indice].proveedor[p].Apellido);
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
    int j=0;
    if (*indice <= 0) {  // Verificar si hay elementos
        printf("\nNo hay artículos para eliminar.");
        return;
    }

    for (int i = 0; i < *indice; i++) {
        if (unArreglo[i].info.codigo == codigo) {
            printf("\nSe eliminará el siguiente artículo:");
            listarUnArticulo(i, unArreglo);

            // Reemplazar el artículo a borrar con el último (si no es el mismo)
            if (i != (*indice - 1)) {
            unArreglo[i].info.codigo=unArreglo[*indice-1].info.codigo;
            unArreglo[i].info.precio=unArreglo[*indice-1].info.precio;
            unArreglo[i].info.inventario=unArreglo[*indice-1].info.inventario;
            strcpy(unArreglo[i].info.nombre,unArreglo[*indice-1].info.nombre);
            strcpy(unArreglo[i].info.Nom_departamento,unArreglo[*indice-1].info.Nom_departamento);

            for(int p = 0; p < 2; p++) {
                strcpy(unArreglo[i].proveedor[p].Nombre, unArreglo[*indice-1].proveedor[p].Nombre);
                strcpy(unArreglo[i].proveedor[p].Apellido, unArreglo[*indice-1].proveedor[p].Apellido);
            }  // Copia directa de la estructura
            }

            (*indice)--;  // Reducir el contador

            printf("\nArticulo eliminado. Articulos restantes:");
            while(j<(*indice)){
                listarArticulos(&j,unArreglo);
            }
            return;
        }
    }
    printf("\nArtículo con código %d no encontrado.", codigo);
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

//función para leer archivos
void LeerArticulos(Articulo *arreglo, int *num_articulos) {
    FILE *dulce = fopen("Dulces.txt", "r");
    if (dulce == NULL) {
        printf("No se pudo acceder al archivo\n");
        return;
    }

    while (*num_articulos < 30 &&
           fscanf(dulce, "%29s %d %f %d %29s %d %29s %29s %29s %29s",
                  arreglo[*num_articulos].info.nombre,
                  &arreglo[*num_articulos].info.codigo,
                  &arreglo[*num_articulos].info.precio,
                  &arreglo[*num_articulos].info.inventario,
                  arreglo[*num_articulos].info.Nom_departamento,
                  &arreglo[*num_articulos].info.num_dept,
                  arreglo[*num_articulos].proveedor[0].Nombre,
                  arreglo[*num_articulos].proveedor[0].Apellido,
                  arreglo[*num_articulos].proveedor[1].Nombre,
                  arreglo[*num_articulos].proveedor[1].Apellido)== 10) {
        (*num_articulos)++;
    }

    fclose(dulce);
}

void LiberarArreglo(Articulo *unArreglo, int max) {
    for(int q = 0; q < max; q++) {
        free(unArreglo[q].info.nombre);
        free(unArreglo[q].info.Nom_departamento);
        for(int i = 0; i < 2; i++) {
            free(unArreglo[q].proveedor[i].Nombre);
            free(unArreglo[q].proveedor[i].Apellido);
        }
        free(unArreglo[q].proveedor);
    }
    free(unArreglo);
}
