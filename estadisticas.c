#include <stdio.h>
#include "estadisticas.h"

// 1. Departamento con menor inventario disponible
int departamentoMenorInventario(Articulo *arreglo, int num_articulos) {
    int inventario[10] = {0}; // Suponiendo 10 departamentos
    for (int i = 0; i < num_articulos; i++) {
        inventario[arreglo[i].info.departamento] += arreglo[i].info.inventario;
    }
    int minDept = 0;
    for (int i = 1; i < 10; i++) {
        if (inventario[i] < inventario[minDept]) {
            minDept = i;
        }
    }
    return minDept;
}

// 2. Departamento con mayor venta total
int departamentoMayorVenta(Articulo *arreglo, int num_articulos) {
    float ventas[10] = {0}; 
    for (int i = 0; i < num_articulos; i++) {
        ventas[arreglo[i].info.departamento] += arreglo[i].info.cantidad_vendida * arreglo[i].info.precio;
    }
    int maxDept = 0;
    for (int i = 1; i < 10; i++) {
        if (ventas[i] > ventas[maxDept]) {
            maxDept = i;
        }
    }
    return maxDept;
}

// 3. Artículo más caro
Articulo articuloMasCaro(Articulo *arreglo, int num_articulos) {
    Articulo masCaro = arreglo[0];
    for (int i = 1; i < num_articulos; i++) {
        if (arreglo[i].info.precio > masCaro.info.precio) {
            masCaro = arreglo[i];
        }
    }
    return masCaro;
}

// 4. Total de ventas por departamento
void totalVentasPorDepartamento(Articulo *arreglo, int num_articulos) {
    float ventas[10] = {0}; // Suponiendo 10 departamentos
    for (int i = 0; i < num_articulos; i++) {
        ventas[arreglo[i].info.departamento] += arreglo[i].info.cantidad_vendida * arreglo[i].info.precio;
    }
    printf("\nTotal de ventas por departamento:\n");
    for (int i = 0; i < 10; i++) {
        printf("Departamento %d: %.2f\n", i, ventas[i]);
    }
}

// 5. Producto más vendido (por cantidad)
Articulo productoMasVendido(Articulo *arreglo, int num_articulos) {
    Articulo masVendido = arreglo[0];
    for (int i = 1; i < num_articulos; i++) {
        if (arreglo[i].info.cantidad_vendida > masVendido.info.cantidad_vendida) {
            masVendido = arreglo[i];
        }
    }
    return masVendido;
}

// 6. Porcentaje de inventario vendido en cada departamento
void porcentajeInventarioVendido(Articulo *arreglo, int num_articulos) {
    int inventarioTotal[10] = {0};
    int vendidoTotal[10] = {0};
    for (int i = 0; i < num_articulos; i++) {
        int dept = arreglo[i].info.departamento;
        inventarioTotal[dept] += arreglo[i].info.inventario + arreglo[i].info.cantidad_vendida;
        vendidoTotal[dept] += arreglo[i].info.cantidad_vendida;
    }
    printf("\nPorcentaje de inventario vendido por departamento:\n");
    for (int i = 0; i < 10; i++) {
        if (inventarioTotal[i] > 0) {
            float porcentaje = (vendidoTotal[i] / (float)inventarioTotal[i]) * 100;
            printf("Departamento %d: %.2f%%\n", i, porcentaje);
        }
    }
}

// 7. Promedio de precio de todos los productos
float promedioPrecio(Articulo *arreglo, int num_articulos) {
    float sumaPrecios = 0.0;
    for (int i = 0; i < num_articulos; i++) {
        sumaPrecios += arreglo[i].info.precio;
    }
    return sumaPrecios / num_articulos;
}

// 8. Listar productos de mayor precio a menor
void listarProductosPorPrecio(Articulo *arreglo, int num_articulos) {
    // Ordenar por precio (burbuja simple)
    for (int i = 0; i < num_articulos - 1; i++) {
        for (int j = 0; j < num_articulos - i - 1; j++) {
            if (arreglo[j].info.precio < arreglo[j + 1].info.precio) {
                Articulo temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
    printf("\nProductos ordenados por precio (de mayor a menor):\n");
    for (int i = 0; i < num_articulos; i++) {
        printf("Producto: %s, Precio: %.2f\n", arreglo[i].info.nombre, arreglo[i].info.precio);
    }
}

// 9. Total de inventario disponible
int totalInventarioDisponible(Articulo *arreglo, int num_articulos) {
    int total = 0;
    for (int i = 0; i < num_articulos; i++) {
        total += arreglo[i].info.inventario;
    }
    return total;
}

// 10. Producto con menor cantidad en inventario
Articulo productoMenorInventario(Articulo *arreglo, int num_articulos) {
    Articulo menorInventario = arreglo[0];
    for (int i = 1; i < num_articulos; i++) {
        if (arreglo[i].info.inventario < menorInventario.info.inventario) {
            menorInventario = arreglo[i];
        }
    }
    return menorInventario;
}

// Función principal para mostrar estadísticas
void mostrarEstadisticas(ColaCircular *cola, Articulo *arreglo, int num_articulos) {
    printf("\n**** Estadísticas ****\n");
    printf("Departamento con menor inventario: %d\n", departamentoMenorInventario(arreglo, num_articulos));
    printf("Departamento con mayor venta total: %d\n", departamentoMayorVenta(arreglo, num_articulos));
    printf("Artículo más caro: %s\n", articuloMasCaro(arreglo, num_articulos).info.nombre);
    printf("Producto más vendido: %s\n", productoMasVendido(arreglo, num_articulos).info.nombre);
    printf("Promedio de precio: %.2f\n", promedioPrecio(arreglo, num_articulos));
    totalVentasPorDepartamento(arreglo, num_articulos);
    porcentajeInventarioVendido(arreglo, num_articulos);
    listarProductosPorPrecio(arreglo, num_articulos);
    printf("Total de inventario disponible: %d\n", totalInventarioDisponible(arreglo, num_articulos));
    printf("Producto con menor inventario: %s\n", productoMenorInventario(arreglo, num_articulos).info.nombre);
    printf("************************\n");
}
