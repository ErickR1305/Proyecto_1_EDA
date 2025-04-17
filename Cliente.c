#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "inventario.h"
#include "Carrito.h"
#include "colaCircular.h"

Cliente *CrearCliente(){
    Cliente *nuevoCliente;
    nuevoCliente=(Cliente *)malloc(1*sizeof(Cliente));
    if(nuevoCliente==NULL){
        printf("No se pudo asignar memoria correctamente...");
        exit(1);
    }
    nuevoCliente->Nombre_Cliente=(char *)malloc(30*sizeof(char));
        if(nuevoCliente->Nombre_Cliente==NULL){
        printf("No se pudo asignar memoria correctamente...");
        exit(1);
        }
    nuevoCliente->pila=(Pila *)malloc(1*sizeof(Pila));
        if(nuevoCliente->pila==NULL){
            printf("No se pudo asignar memoria correctamente...");
            exit(1);
        }

    return nuevoCliente;
}

void CapturarCliente(Cliente *unCliente,int num,Articulo *arreglo){
    float cont=0;
    Articulo *unArticulo;
    char NombreCliente[10][30] = {"Maria", "Carlos", "Enrique", "Ricardo", "Erick", "Lucy", "Marcos", "Karol", "Daniel", "Diego"};
    strcpy(unCliente->Nombre_Cliente,NombreCliente[rand()%10]);
    unCliente->Productos=rand()%5+1;
    unCliente->pila=crearPila(unCliente->Productos);
    for(int i=0;i<unCliente->Productos;i++){
    if(!ValidarEspacio(*unCliente->pila)){
        unArticulo=CrearArticulo();
        CapturarArticulo(unArticulo,arreglo,num,&cont);
        push(*unArticulo,unCliente->pila);
        }else{
            printf("El carrito esta vacio...");

        }
    }
    unCliente->Total=cont;
  /*  do{
        unCliente->Pago=rand()%90+50;
        if(unCliente->Pago<unCliente->Total){
            printf("Te hace falta más dinero (%f)\n",unCliente->Total-unCliente->Pago);
        }
    }while(unCliente->Pago<unCliente->Total);
    printf("\nRecibo %.2f, el total fue de %.2f, tu cambio es %.2f\n",unCliente->Pago,unCliente->Total,unCliente->Total-unCliente->Pago);
                ListarCliente(*unCliente);*/
}



void ListarCliente(Cliente unCliente){
    printf("\nEl nombre del cliente es: %s",unCliente.Nombre_Cliente);
    printf("\n ------Carrito------\n");
    Listar(*unCliente.pila);
    printf("\nEl total es:%.2f\n ",unCliente.Total);
}

void LiberarCliente(Cliente *unCliente){
    free(unCliente->Nombre_Cliente);
    free(unCliente);
    unCliente=NULL;
}

void AtendiendoCliente(Cliente *unCliente){
        for(int i=unCliente->Productos-1;i>=0;i--){
        printf("Cobrando producto:%s \n",unCliente->pila->ArrPila[i]);
        sleep(1);
        }
}
