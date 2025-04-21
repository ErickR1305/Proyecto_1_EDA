#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"
#include "menu.h"
#include "colaCircular.h"
#include <time.h>
#include "pila.h"
#include <unistd.h>
#include "estadisticas.h"
#include "Cliente.h"

int main(){
int opcion,opc2,opc3,opc4;
int num_articulos; //indice
int max_articulos; //max-1, para que no se pase de lo asignado por malloc
int codigo,i,nuevo;
srand(time(NULL));
//prueba cola

    ColaCircular *colaCircular;
    int max;
    Cliente *unCliente;
    printf("Tamanio del arreglo cola:");
    scanf("%i",&max);
    colaCircular = crearColaCircular(max);


Articulo *arreglo;
printf("\n Ingrese la cantidad maxima de articulos a manejar:");
scanf("%d",&max_articulos);

arreglo=crearArreglo(max_articulos);
num_articulos=0;

LeerArticulos(arreglo,&num_articulos);
    do {
        printf("\n");
        opcion = desplegarMenu("\n1)Organizar inventario \n2)Atender a un cliente \n3)Estadisticas \n4)Salir\nOpcion: ",4);
        switch (opcion){
            case 1:
            do{

            opc2=desplegarMenu("\n1)Insertar art. \n2)Listar articulos \n3)Buscar articulos \n4)Borrar art. \n5)Actualizar info. \n6)Salir ",6);
            switch (opc2){
                case 1:
                insertarArticulo(&num_articulos,max_articulos,arreglo);
                break;

            case 2:
            if(num_articulos==0){
                printf("\n ERROR: no hay articulos registrados...");
            }else{
                i=0;//se reinicia para que liste todos
                printf("\n ====ARTICULOS REGISTRADOS====");
                while(i<num_articulos)
                listarArticulos(&i,arreglo);

            }
            break;

            case 3:
            if(num_articulos==0){
                printf("\n ERROR: no hay articulos registrados...");
            }else{
                printf("Introduzca el codigo del producto a buscar: ");
                scanf("%d",&codigo);
                buscarArticulos(codigo,arreglo,num_articulos);
            }
            break;

            case 4:
            if(num_articulos==0){
                printf("\n ERROR: no hay articulos registrados...");
            }else{
                printf("Introduzca el codigo del producto a eliminar: ");
                scanf("%d",&codigo);
            borrarArticulo(codigo,arreglo,&num_articulos);
            }
            break;

            case 5:
            if(num_articulos==0){
                printf("\n ERROR: no hay articulos registrados...");
            }else{
                printf("Introduzca el codigo del producto a actualizar");
                scanf("%d",&codigo);
                actualizarArticulo(codigo,arreglo,num_articulos);
            }
            break;

            case 6:
            printf("Saliendo del menu:Organizar inventario... Volviendo al menu principal");

            }
            }while(opc2 !=6);
                break;
        case 2://Simulación de atención a clientes
            printf("\nBienvenido a nuestra tienda...\n");
            for(i=0;i<3;i++){
                if (validarEspacio(*colaCircular)){
                    unCliente=CrearCliente();
                    CapturarCliente(unCliente,num_articulos,arreglo);
                    insertar(colaCircular,*unCliente);
                }
            }
            listar(*colaCircular);

                do{
                int q=colaCircular->h;
                AtendiendoCliente(&colaCircular->arrCola[q]);
                *unCliente=borrar(colaCircular);
                printf("Cliente atentido.\n");
                LiberarCliente(unCliente);
                sleep(3);
                nuevo=rand()%10+1;
                if(nuevo>=7){
                    if (validarEspacio(*colaCircular)){
                        printf("\nSe formo otra persona mas en la fila...\n");
                        sleep(2);
                        unCliente=CrearCliente();
                        CapturarCliente(unCliente,num_articulos,arreglo);
                        insertar(colaCircular,*unCliente);
                        }else
                            printf("\nUna persona se quiso formar pero no habia espacio...\n");
                }
                listar(*colaCircular);
                }while(!validarVacio(*colaCircular));

                break;


            case 3:
            mostrarEstadisticas(colaCircular, arreglo, num_articulos);
            break;
        }
    } while (opcion !=4);
    liberarMemoria(colaCircular);
    LiberarArreglo(arreglo,max_articulos);
}
