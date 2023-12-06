#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genCalif(float calif[][23]);
void mostrarMat(float calif[][23]);
void promEst(float calif[][23]);
void promGrupo(float calif[][23]);
int mejorEst(float calif[][23]);

int main() {
    float calif[3][23];

    genCalif(calif);
    
    printf("Matriz de Calificaciones:\n");
    mostrarMat(calif);

    printf("\nPromedio de cada estudiante por progreso:\n");
    promEst(calif);

    printf("\nNota promedio del grupo por progreso:\n");
    promGrupo(calif);

    int mejor = mejorEst(calif);
    printf("\nEl estudiante con el mejor promedio global es: %d\n", mejor + 1);

    return 0;
}

// Aqui vamos a generar numeros aleatorios que seran vistos como las calificaciones de los estudiantes, entre el 0 al 10

void genCalif(float calif[][23]) {
    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 23; j++) {
            calif[i][j] = (rand() % 101) / 10.0;
        }
    }
}

void mostrarMat(float calif[][23]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 23; j++) {
            printf("%.2f\t", calif[i][j]);
        }
        printf("\n");
    }
}

// Aqui vamos a calcular el promedio de cada alumno por progreso

void promEst(float calif[][23]) {
    for (int i = 0; i < 23; i++) {
        float suma = 0;

        for (int j = 0; j < 3; j++) {
            suma += calif[j][i];
        }

        printf("Estudiante %d: %.2f\n", i + 1, suma / 3);
    }
}

// Aqui vamos a calcular el promedio grupal por cada progreso

void promGrupo(float calif[][23]) {
    for (int i = 0; i < 3; i++) {
        float suma = 0;

        for (int j = 0; j < 23; j++) {
            suma += calif[i][j];
        }

        printf("Progreso %d: %.2f\n", i + 1, suma / 23);
    }
}

// Aqui vamos a buscar cual fue el estudiante con mejor puntaje del semestre

int mejorEst(float calif[][23]) {
    float mejorPromedio = 0;
    int mejorAlumno = 0;

    for (int i = 0; i < 23; i++) {
        float promedio = 0;

        for (int j = 0; j < 3; j++) {
            promedio += calif[j][i];
        }

        promedio /= 3;

        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            mejorAlumno = i;
        }
    }
    return mejorAlumno;
}
