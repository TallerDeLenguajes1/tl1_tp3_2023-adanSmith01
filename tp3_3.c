#include <stdio.h>
#include <stdlib.h>

int main() {
    char **V = (char **)malloc(sizeof(char *)*5);

    //Se guardan los nombres ingresados
    puts("Debe ingresar 5 nombres");
    for(int i = 0; i < 5; i++) {
        printf("Nombre %d: ", i + 1);
        V[i] = (char *)malloc(41);
        fgets(V[i], 41, stdin);
    }
    
    //Se muestran los nombres que fueron ingresados y se borran de la memoria después
    puts("\n====LISTA DE NOMBRES INGRESADOS====\n");
    for (int i = 0; i < 5; i++) {
        printf("- %s\n", V[i]);
        free(V[i]);
    }
    free(V);

    return 0;
}