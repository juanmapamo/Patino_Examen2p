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


