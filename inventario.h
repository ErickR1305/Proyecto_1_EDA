#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

typedef struct{
    int codigo;
    float precio;
    int *inventario;
    char *nombre;
}Articulo;

typedef struct {
    char *nombre_departamento;
    Articulo* articulos;
    int num_articulos;
    int max_articulos;
} Departamento;

typedef struct {
    Departamento* departamentos;
    int num_departamentos;
} Inventario;


Inventario *crearArreglo();
void crearDepartamento(Inventario*unInventario);
void insertarArticulo(int indice,int indice_dep,Inventario*unInventario);
void listarArticulos(int indice,int indice_dep,Inventario*unInventario);
#endif // INVENTARIO_H_INCLUDED
