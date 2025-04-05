#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"
#include "menu.h"

int main(){
int opcion,max_articulos,opc2;
int num_articulos=0;


Arreglo_articulos *arreglo;

printf("\n Introduzca el numero maximo de articulos a manejar:");
scanf("%d",&max_articulos);

arreglo=crearArreglo(max_articulos);
LeerArticulos(arreglo,&num_articulos);

    do {
        printf("\n");
        opcion = desplegarMenu("\n1)Organizar inventario \n2)Atender a un cliente \n3)Estadisticas \n4)Salir\nOpcion: ",4);
        switch (opcion){
            case 1:
            do{

            opc2=desplegarMenu("\n1)Insertar art. \n2)Listar articulos. \n3)Buscar por codigo \n4)Actualizar info. \n5)Borrar art. \n6)Gestionar inventario \n7)Salir  ",7);
            switch (opc2){
                case 1:
                insertarArticulo(num_articulos,max_articulos,arreglo);
                num_articulos++;
                break;
                case 2:
                listarArticulos(num_articulos,*arreglo);
                break;
            }
            }while(opc2 !=7);
                break;

            case 2:

                    break;

            case 3:
                break;
        }

    } while (opcion !=4);
}

/*Insertar un artículo nuevo

Eliminar un artículo

Buscar un artículo por su código

Actualizar información de un artículo

Listar todos los artículos

Gestionar inventarios (aumentar o disminuir inventario)*/
