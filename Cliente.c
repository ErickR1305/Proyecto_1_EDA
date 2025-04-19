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
    Articulo *unArticulo;
    char NombreCliente[10][30] = {"Maria", "Carlos", "Enrique", "Ricardo", "Erick", "Lucy", "Marcos", "Karol", "Daniel", "Diego"};
    strcpy(unCliente->Nombre_Cliente,NombreCliente[rand()%10]);
    unCliente->Productos=rand()%5+1;
    unCliente->pila=crearPila(unCliente->Productos);
    for(int i=0;i<unCliente->Productos;i++){
    if(!ValidarEspacio(*unCliente->pila)){
        unArticulo=CrearArticulo();
        CapturarArticulo(unArticulo,arreglo,num);
        push(*unArticulo,unCliente->pila);
        free(unArticulo);
        }else{
            printf("El carrito esta vacio...");

        }
    }

}



void ListarCliente(Cliente unCliente){
    printf("\nEl nombre del cliente es: %s",unCliente.Nombre_Cliente);
    if(unCliente.pila->tope!=-1){
    printf("\n ------Carrito------\n");
    }
    Listar(*unCliente.pila);
    printf("\n\n");
    //printf("\nEl total es:%.2f\n ",unCliente.Total);
}

void LiberarCliente(Cliente *unCliente) {
    // Liberar artículos en la pila
        Liberar(unCliente->pila);
        free(unCliente->Nombre_Cliente);
}

void AtendiendoCliente(Cliente *unCliente){
        int NumTarjeta[16];
        Articulo aux;
        int option;
        for(int i=unCliente->Productos-1;i>=0;i--){
        unCliente->Total+=unCliente->pila->ArrPila[i].info.precio;
        printf("Cobrando producto:%s---%.2f   %.2f\n",unCliente->pila->ArrPila[i].info.nombre,
               unCliente->pila->ArrPila[i].info.precio,unCliente->Total);
        aux=pop(unCliente->pila);
        sleep(1);
        }
               printf("\nTu total es: %.2f \n",unCliente->Total);
               printf("Desea pagar en efectivo o en tarjeta?\n");
               option=rand()%2+1;
               switch(option){
                case 1://En efectivo
                    printf("\n-----Pago en efectivo----\n");
                    do{
                        unCliente->Pago=rand()%90+50;
                        if(unCliente->Pago<unCliente->Total){
                            printf("\nRecibo %.2f ",unCliente->Pago);
                            printf("\nTe hace falta %.2f\n ",unCliente->Total-unCliente->Pago);
                        }else
                            printf("\n Recibo %.2f, tu cambio es %.2f\n",unCliente->Pago,unCliente->Pago-unCliente->Total);
                    }while(unCliente->Pago<unCliente->Total);

               break;
                case 2://Tarjeta
                    printf("\n-----Pago con tarjeta-----\n");
                    printf("Numero de tarjeta: ");
                    for (int i = 0; i < 16; i++) {
                        int digito = rand() % 10;
                        printf("%d", digito);
                        NumTarjeta[i]=digito;
                        }
                        printf("\nPagando...\n");
                        sleep(2);
                        printf("Has pagado %.2f  con ",unCliente->Total);
                        for (int i = 0; i < 16; i++)
                            printf("%d",NumTarjeta[i]);
                            printf("\n");

}

        }
