
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define NUM_A 26
#define NUM_PROGRESOS 3

const char *A[NUM_A] = {
    "Alumno1",
    "Alumno2",
    "Alumno3",
    "Alumno4",
    "Alumno5",
    "Alumno6",
    "Alumno7",
    "Alumno8",
    "Alumno9",
    "Alumno10",
    "Alumno11",
    "Alumno12",
    "Alumno13",
    "Alumno14",
    "Alumno15",
    "Alumno16",
    "Alumno17",
    "Alumno18",
    "Alumno19",
    "Alumno20",
    "Alumno21",
    "Alumno22",
    "Alumno23",
    "Alumno24",
    "Alumno25",
    "Alumno26"
};

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
        printf("%s: ", A[i]);
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            printf("%d ", NOTAS[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Opcion1(int NOTAS[NUM_A][NUM_PROGRESOS]) {
    int suma;
    for (int i = 0; i < NUM_A; i++) {
        suma = 0;
        for (int j = 0; j < NUM_PROGRESOS; j++) {
           suma += NOTAS[i][j]; 
        }
        printf("El promedio de notas del %s es %f.\n", A[i], (double)suma/NUM_PROGRESOS);
    }
}

void Opcion2(int NOTAS[NUM_A][NUM_PROGRESOS]) {
    int suma;
    for (int j = 0; j < NUM_PROGRESOS; j++) {
        suma = 0;
        for (int i = 0; i < NUM_A; i++) {
           suma += NOTAS[i][j]; 
        }
        printf("El promedio de notas del progreso %d es %f.\n", j+1, (double)suma/NUM_A);
    }
}

void Opcion3(int NOTAS[NUM_A][NUM_PROGRESOS]) {
    int maxNota = -1;
    int maxAlumno = -1;
    for (int i = 0; i < NUM_A; i++) {
        for (int j = 0; j < NUM_PROGRESOS; j++) {
           if(NOTAS[i][j] > maxNota) {
               maxNota = NOTAS[i][j];
               maxAlumno = i;
           }
        }
    }
    printf("El alumno con la nota más alta es %s con una nota de %d.\n", A[maxAlumno], maxNota);
}
