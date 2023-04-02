#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

//Estructura de cada producto
typedef struct Producto {
    int ProductoID;
    int Cantidad;
    char* TipoProducto;
    float PrecioUnitario;
}Producto;

//Estructura del cliente
struct Cliente{
    int ClienteID;
    char* NombreCliente;
    int CantidadProductosAPedir;
    Producto* Productos;
};

float costoTotalProd(Producto prod);
void mostrarDatosClientes(struct Cliente** clientes, int cant);

int main() {
    int cant;
    struct Cliente** registroClientes;
    srand(time(NULL));
    puts("====BIENVENIDO/A====");
    do {
        printf("\nDetermina la cantidad de clientes que quieres registrar (maximo 5 clientes): ");
        scanf("%d", &cant);
        if (cant > 5) puts("ERROR: cantidad de clientes invalida.\n");
    }while(cant > 5);
    
    registroClientes = (struct Cliente**)malloc(sizeof(struct Cliente*)*cant);

    //Se cargan los datos de los clientes
    puts("\n======CLIENTES=======\n");
    for(int i = 0; i < cant; i++) {
        fflush(stdin);
        registroClientes[i] = (struct Cliente*)malloc(sizeof(struct Cliente));
        registroClientes[i]->ClienteID = i;
        printf("Nombre del cliente: ");
        registroClientes[i]->NombreCliente = (char*)malloc(51);
        fgets(registroClientes[i]->NombreCliente, 51, stdin);
        registroClientes[i]->NombreCliente[strlen(registroClientes[i]->NombreCliente) - 1] = '\0';
        registroClientes[i]->CantidadProductosAPedir = 3;
        registroClientes[i]->Productos = (Producto*)malloc(sizeof(Producto) * registroClientes[i]->CantidadProductosAPedir);
    }

    //Se cargan los valores para los productos del cada cliente
    for(int i = 0; i < cant; i++) {
        for(int j = 0; j < 3; j++) {
            registroClientes[i]->Productos[j].ProductoID = j;
            registroClientes[i]->Productos[j].Cantidad = 1 + rand() % 10;
            registroClientes[i]->Productos[j].TipoProducto = TiposProductos[rand() % 5];
            registroClientes[i]->Productos[j].PrecioUnitario =  (float)(100 + rand() % 901)/10;
        }
    }

    mostrarDatosClientes(registroClientes, cant);

    //Liberar de memoria
    for (int i = 0; i < cant; i++){
        for(int j = 0; j < registroClientes[i]->CantidadProductosAPedir; j++){
            free(registroClientes[i]->Productos);
        }
        free(registroClientes[i]);
    }

    free(registroClientes);

    return 0;
}

//FUNCIONES

//Función que calcula el costo total de cada producto respecto al precio unitario y la cantidad
float costoTotalProd(Producto prod) {
    return (prod.Cantidad*prod.PrecioUnitario);
}

//Función que muestra los datos de los clientes con sus respectivos totales a pagar
void mostrarDatosClientes(struct Cliente** clientes, int cant) {
    for (int i = 0; i < cant; i++){
        float total = 0;
        printf("\n==========DATOS DEL CLIENTE %d==========\n", clientes[i]->ClienteID);
        printf("\nID: %d\n", clientes[i]->ClienteID);
        printf("Nombre: %s\n", clientes[i]->NombreCliente);
        printf("Cantidad de productos pedida: %d\n", clientes[i]->CantidadProductosAPedir);

        puts("\n******PRODUCTOS A COMPRAR******\n");
        for (int j = 0; j < clientes[i]->CantidadProductosAPedir; j++) {
            printf("ID: %d", clientes[i]->Productos[j].ProductoID);
            printf("  Tipo de producto: %s", clientes[i]->Productos[j].TipoProducto);
            printf("   Cantidad: %d", clientes[i]->Productos[j].Cantidad);
            printf("    Precio Unitario: %.2f", clientes[i]->Productos[j].PrecioUnitario);
            printf("    Subtotal: %.2f\n", costoTotalProd(clientes[i]->Productos[j]));
            total += costoTotalProd(clientes[i]->Productos[j]);
        }
        printf("\nTOTAL A PAGAR: %.2f\n", total);
    }
}
