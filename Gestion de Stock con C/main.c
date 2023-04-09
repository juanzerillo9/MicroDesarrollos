#include <stdio.h>
#include <stdlib.h>

struct products{
    int id;
    int stock;
    float precio;
    char descripcion[50];
};

void carga(struct products *producto, int n){
    for(int i = 0 ; i < n ; i++){
        printf("------------------------------------------------------\n");
        producto[i].id = i+1;
        printf("Producto ID %d\n", producto[i].id);
        printf("------------------------------------------------------\n");

        printf("Cuanto stock hay disponible: ");
        scanf("%d", &producto[i].stock);

        printf("Ingrese el Precio: ");
        scanf("%f", &producto[i].precio);

        printf("Descripcion del Producto: ");
        scanf("%s", &producto[i].descripcion);
    };
}

void muestra(struct products *producto, int n){
    for(int j = 0 ; j < n ; j++){
        printf("------------------------------------------------------\n");
        printf("Producto ID %d\n", producto[j].id);
        printf("------------------------------------------------------\n");

        printf("id: %d \n", producto[j].id);

        printf("Producto: %s \n", producto[j].descripcion);

        printf("Precio: %.2f \n", producto[j].precio);

        printf("Stock: %d \n", producto[j].stock);

    };
    int back;
    printf("Ingrese 0 para volver al menu principal! \n");
    scanf("%d", &back);
    if(back == 0){
            menu(producto, n);
        }else{
            printf("Fin del programa!");
    }
}

void busqueda(struct products *producto, int n){
    int busca;

    printf("Id del producto que busca: ");
    scanf("%d", &busca);
    printf("%d\n", busca);

    int indice = busca + 1;

    printf("------------------------------------------------------\n");
    printf("Producto ID %d\n", producto[indice].id);
    printf("------------------------------------------------------\n");

    printf("id: %d \n", producto[indice].id);

    printf("Producto: %s \n", producto[indice].descripcion);

    printf("Precio: %.2f \n", producto[indice].precio);

    printf("Stock: %d \n", producto[indice].stock);

    int back;
    printf("Ingrese 0 para volver al menu principal! \n");
    scanf("%d", &back);
    if(back == 0){
            menu(producto, n);
        }else{
            printf("Fin del programa!");
    }
}

void seleccion(struct products *producto, int n){
    int opcion = 0;

    if(opcion == 0){
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
                muestra(producto, n);

            break;
        case 2:
                busqueda(producto, n);
             break;
        case 3:
             exit(-1);
             break;
        default:
            printf("Esa opcion no esta en la lista!\n");
            menu(producto, n);
            break;
        }
    }

}

int menu(struct products *producto, int n){
    printf("------------------------------------------------------\n");
    printf("----------         Menu Principal               ------\n");
    printf("------------------------------------------------------\n");

    printf(" Ingrese la opcion que desee: \n");
    printf(" -> 1. Mostrar Listado de productos.\n");
    printf(" -> 2. Buscar un producto en especifico.\n");
    printf(" -> 3. Exit.\n");

    seleccion(producto, n);
}


void main(){
    int n;
    printf("------------------------------------------------------\n");
    printf("Ingrese Cantidad de Productos a cargar en el sistema: ");
    scanf("%d", &n);

    struct products producto[n];

    carga(producto, n);
    menu(producto, n);
};
