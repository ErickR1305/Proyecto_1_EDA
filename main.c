#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"
#include "menu.h"
#include "colaCircular.h"
#include <time.h>
#include "pila.h"

int main(){
int opcion,opc2,opc3,opc4;
int num_articulos; //indice
int max_articulos; //max-1, para que no se pase de lo asignado por malloc
int codigo,i;
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
                for(int i=0;i<=colaCircular->t;i++)
                AtendiendoCliente(&colaCircular->arrCola[i]);


                listar(*colaCircular);
            break;


            case 3:
                do {
            printf("\n\nEstructura Cola circular\n====================");
            opc3= desplegarMenu ("\n1)Insertar\n2)Borrar\n3)Listar\n4)Salir\nOpcion:",4);
            switch (opc3) {
                case 1://insertar
                if (validarEspacio(*colaCircular)){
                    unCliente=CrearCliente();
                    CapturarCliente(unCliente,num_articulos,arreglo);
                    insertar(colaCircular,*unCliente);
                }
                listar(*colaCircular);
                break;

                case 2: //borrar
                    if (!validarVacio(*colaCircular)){
                    *unCliente= borrar(colaCircular);
                    printf ("El dato borrado es: n");
                    ListarCliente(*unCliente);
                    listar(*colaCircular);
                }
                else
                    printf("\nNo hay clientes en la fila...\n");
            break;

        case 3: //listar
            listar(*colaCircular);
            break;
        }
    } while (opcion != 4);
                break;
        }
    } while (opcion !=4);
}
