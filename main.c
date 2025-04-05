#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"
#include "menu.h"

int main(){
int opcion,opc2,opc3,opc4;
int num_articulos=0;

Inventario *arreglo;

arreglo=crearArreglo();

    do {
        printf("\n");
        opcion = desplegarMenu("\n1)Organizar inventario \n2)Atender a un cliente \n3)Estadisticas \n4)Salir\nOpcion: ",4);
        switch (opcion){
            case 1:
            do{
                
            opc2=desplegarMenu("\n1)Insertar art. \n2)Listar articulos. \n3)Borrar art. \n4)Actualizar info. \n5)Buscar por codigo. \n6)Gestionar inventario \n7)Salir  ",7);
            switch (opc2){
                case 1:
                if(arreglo->num_departamentos==0){
                    crearDepartamento(arreglo);
                    insertarArticulo(0,arreglo->departamentos[0].num_articulos,arreglo);
                }else{
                    printf("\n Seleccione el departamento en el cual se agregara el articulo");
                    for(int i=0;i<arreglo->num_departamentos;i++){
                        printf("Dep.[%d]:%s\n",i,arreglo->departamentos[i].nombre_departamento);
                    }
                    scanf("%d",&opc3);
                    insertarArticulo(opc3,arreglo->departamentos[opc3].num_articulos,arreglo);
                    
                }
                break;
            
            case 2:
            if(arreglo->num_departamentos==0){
                printf("\n ERROR: no hay departamentos registrados...");
            }else{
                printf("\n Seleccione el departamento del cual se listaran los articulos");
                for(int i=0;i<arreglo->num_departamentos;i++){
                        printf("Dep.[%d]:%s\n",i,arreglo->departamentos[i].nombre_departamento);
                    }
                scanf("%d",&opc4);
                listarArticulos(opc4,arreglo->departamentos[opc4].num_articulos,arreglo);
            }
            break;
            
            }
            }while(opc2 !=7);
                break;

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
