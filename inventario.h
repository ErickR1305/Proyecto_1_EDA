#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED
typedef struct{
    int codigo;
    float precio;
    int inventario;
    char *nombre;
    char *Nom_departamento;
}Info;

typedef struct{
    char *Nombre;
    char *Apellido;
}Proveedor;

typedef struct{
    Info info;
    Proveedor *proveedor;
}Articulo;


Articulo *crearArreglo(int max);
void insertarArticulo(int indice,int max,Articulo *unArreglo);
//void listarArticulos(int indice,Arreglo_articulos unArreglo);

//void LeerArticulos(Arreglo_articulos *arreglo,int *indice);//Lee productos iniciasles con archivos
#endif // INVENTARIO_H_INCLUDED

