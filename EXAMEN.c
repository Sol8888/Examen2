
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define NUM_A 26
#define NUM_PROGRESOS 3

void Menu(int *flag, int NOTAS[NUM_A][NUM_PROGRESOS]);
void ImprimirMatriz(int NOTAS[NUM_A][NUM_PROGRESOS]);
void Opcion1(int NOTAS[NUM_A][NUM_PROGRESOS]);
void Opcion2(int NOTAS[NUM_A][NUM_PROGRESOS]);
void Opcion3(int NOTAS[NUM_A][NUM_PROGRESOS]);

int main() {
    setlocale(LC_ALL, "");
    int flag = 1;
    int NOTAS[NUM_A][NUM_PROGRESOS];

    srand(time(NULL));

    // Generar valores aleatorios para las notas de los alumnos.
    for (int i = 0; i < NUM_A; i++) {
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            NOTAS[i][j] = rand() % 11;
        }
    }

    ImprimirMatriz(NOTAS);

    while (flag) {
        Menu(&flag, NOTAS);
    }

    return 0;
}


void Menu(int *flag, int NOTAS[NUM_A][NUM_PROGRESOS]) {
    int menu, resultado;

    printf("Programa:\n");
    printf("Por favor, seleccione una opción:\n 1. Promedio de notas de cada estudiante.\n 2. Promedio de notas de cada semestre.\n 3. Alumno con la nota mas alta.\n 4. Salir.\n");
    resultado = scanf("%d", &menu);

    while (resultado != 1) {
        while (getchar() != '\n'); // Limpiar el buffer de entrada

        printf("\nNo ha ingresado una opción válida. Por favor, intente de nuevo: ");
        resultado = scanf("%d", &menu);
    }

    switch (menu) {
        case 1:
            Opcion1(NOTAS);
            break;
        case 2:
            Opcion2(NOTAS);
            break;
        case 3:
            Opcion3(NOTAS);
            break;
        case 4:
            *flag = 0;
            break;
        default:
            printf("\nNo ha ingresado una opción válida. Por favor, intente de nuevo.\n");
            break;
    }
}

void ImprimirMatriz(int NOTAS[NUM_A][NUM_PROGRESOS]) {
    printf("Matriz de notas de los alumnos:\n");
    for (int i = 0; i < NUM_A; i++) {
        printf("A%d:\n", i + 1);
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            printf("%s: ", j + 1);
        }
        printf("\n");
    }
    printf("\n");
}

void Opcion1(int NOTAS[NUM_A][NUM_PROGRESOS]) {
    int PromedioE;
    
    for (int i = 0; i < NUM_A; i++) {
        for (int j = 0; j < NUM_PROGRESOS; j++) {
           PromedioE=  
      
        }
    }

    printf("El A en el que se recibió la mayor cantidad de alumnos fue el %d, con %d alumnos.\n\n", maxA + 1, maxAlumnos);
}
