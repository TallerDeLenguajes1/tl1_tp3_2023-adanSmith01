#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_NOMBRES 5

int main() {
    char **V = (char **)malloc(sizeof(char *) * CANT_NOMBRES);
    char *buffer;

    //Se guardan los nombres ingresados
    puts("Debe ingresar 5 nombres\n");
    for(int i = 0; i < CANT_NOMBRES; i++) {
        buffer = (char*)malloc(71);
        printf("Nombre %d: ", i + 1);
        fgets(buffer, 71, stdin); //Esta función permite que se lean cadenas con espacios en blanco o con caracteres especiales
        V[i] = (char *)malloc(strlen(buffer));
        strcpy(V[i], buffer);
        V[i][strlen(V[i]) - 1] = '\0'; 
        //La última línea de este bucle es para reemplazar la marca final de esta cadena que tiene por defecto la secuencia de escape '\n'
        /*Al reemplazarlo por el caracter nulo, estoy asegurando que al determinar la longitud de la cadena con la funcion strlen() 
        no se considere al caracter nulo en el resultado de la operación*/
        free(buffer);
    }
    
    //Se muestran los nombres que fueron ingresados y se borran de la memoria después
    puts("\n====LISTA DE NOMBRES INGRESADOS====\n");
    for (int i = 0; i < CANT_NOMBRES; i++) {
        printf("- %s\n", V[i]);
        free(V[i]);
    }
    free(V);
    return 0;
}