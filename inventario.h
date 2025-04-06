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

//PROTOTIPOS ARREGLOS
Articulo *crearArreglo(int max);
void insertarArticulo(int *indice,int max,Articulo *unArreglo);
void listarArticulos(int *i,Articulo *unArreglo);
void buscarArticulos(int codigo,Articulo *unArreglo,int indice);
void listarUnArticulo(int indice,Articulo *unArreglo);
void borrarArticulo(int codigo,Articulo *unArreglo,int *indice);
void actualizarArticulo(int codigo,Articulo *unArreglo,int indice);
void LeerArticulos(Articulo *arreglo,int *indice);//Lee productos iniciasles con archivos
#endif// INVENTARIO_H_INCLUDED
