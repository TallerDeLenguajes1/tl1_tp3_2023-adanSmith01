#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANIOS 5
#define MESES 12

int main ()
{
    int produccion[ANIOS][MESES], mesVM = 0, anioVM = 0, mesVm = 0, anioVm = 0;
    srand(time(NULL));

    //Se cargan y muestran los valores generados de forma aleatoria
    //También muestra la ganancia promedio por año

    printf("\n======PRODUCCI%cN DENTRO DE 5 A%cOS======\n", 224, 165);
    for(int i = 0; i < ANIOS; i++){
        float gananciaProm = 0.0;
        for(int j = 0; j < MESES; j++){
            produccion[i][j] = 10000 + rand() % 41000;
            printf("A%co: %2d; Mes: %2d; Producci%cn: %2d\n", 164, i+1, j+1, 162, produccion[i][j]);
            gananciaProm = produccion[i][j] + gananciaProm;
        }
        puts("\n");
        gananciaProm /= MESES;
        printf("Ganancia promedio en el a%co: %.2f", 164, gananciaProm);
        puts("\n");

    }

    //Se muestra el valor máximo y mínimo, con el año y el mes correspondientes
    for(int i = 0; i < ANIOS; i++) {
        for (int j = 0; j < MESES; j++) {
            if (produccion[i][j] >= produccion[anioVM][mesVM]) {
                anioVM = i;
                mesVM = j;
            } else {
                if (produccion[anioVm][mesVm] >= produccion[i][j]) {
                    anioVm = i;
                    mesVm = j;
                }
            }

        }
    }

    anioVM++;
    mesVM++;
    anioVm++;
    mesVm++;

    printf("Valor m%cximo: %d ; Mes: %d ; A%co: %d\n", 160, produccion[anioVM - 1][mesVM - 1], mesVM, 164, anioVM);
    printf("Valor m%cnimo: %d ; Mes: %d ; A%co: %d\n", 161, produccion[anioVm - 1][mesVm - 1], mesVm, 164, anioVm);
    
    return 0;
}