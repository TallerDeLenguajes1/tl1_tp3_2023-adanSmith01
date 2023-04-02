#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Eligiendo la cantidad de nombres a ingresar

int main() {
    int cantNombres;
    printf("Cantidad de nombres: ");
    scanf("%d", &cantNombres);
    char **V = (char **)malloc(sizeof(char *) * cantNombres);

    //Se guardan los nombres ingresados
    for(int i = 0; i < cantNombres; i++) {
        fflush(stdin);
        printf("Nombre %d: ", i + 1);
        V[i] = (char *)malloc(41);
        fgets(V[i], 41, stdin); //Esta función permite que se lean cadenas con espacios en blanco o con caracteres especiales
        V[i][strlen(V[i]) - 1] = '\0'; 
        //La última línea de este bucle es para reemplazar la marca final de esta cadena que tiene por defecto la secuencia de escape '\n'
        /*Al reemplazarlo por el caracter nulo, estoy asegurando que al determinar la longitud de la cadena con la funcion strlen() 
        no se considere al caracter nulo en el resultado de la operación*/
    }
    
    //Se muestran los nombres que fueron ingresados y se borran de la memoria después
    puts("\n====LISTA DE NOMBRES INGRESADOS====\n");
    for (int i = 0; i < cantNombres; i++) {
        printf("- %s\n", V[i]);
        free(V[i]);
    }
    free(V);

    return 0;
}