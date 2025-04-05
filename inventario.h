#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

typedef struct{
    int codigo;
    float precio;
    int inventario;
    char *nombre;
}Articulo;

typedef struct{
    char departamento[30];
    Articulo *articulos;
}Arreglo_articulos;

Arreglo_articulos *crearArreglo(int max);
void insertarArticulo(int indice,int max,Arreglo_articulos*unArreglo);
void listarArticulos(int indice,Arreglo_articulos unArreglo);

void LeerArticulos(Arreglo_articulos *arreglo,int *indice);//Lee productos iniciasles con archivos
#endif // INVENTARIO_H_INCLUDED
