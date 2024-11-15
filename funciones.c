#include <stdio.h>
#include <math.h>
#include "funciones.h"

float ingresarComponente(char comp, int i) {
    float c;
    printf("Ingrese la componente %c del punto %d: ", comp, i);
    scanf("%f", &c);
    return c;
}

// Calcular las distancias entre los puntos de la base en 3D
void distancias(float *a, float *b, float *c, float p[3][3]) {
    *a = sqrt(pow(p[0][0] - p[1][0], 2) + pow(p[0][1] - p[1][1], 2) + pow(p[0][2] - p[1][2], 2));
    *b = sqrt(pow(p[0][0] - p[2][0], 2) + pow(p[0][1] - p[2][1], 2) + pow(p[0][2] - p[2][2], 2));
    *c = sqrt(pow(p[1][0] - p[2][0], 2) + pow(p[1][1] - p[2][1], 2) + pow(p[1][2] - p[2][2], 2));
}

void perimetro(float *p, float *s, float a, float b, float c) {
    *p = a + b + c;
    *s = *p / 2;
}

float area(float s, float a, float b, float c) {
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Calcula el área de la superficie lateral de la pirámide con las tres caras triangulares
float area_superficie_lateral(float a, float b, float c, float h[3], float base[3][3]) {
    float areaTotal = 0;
    float ladoA, ladoB, s;

    // Cálculo del área de cada cara lateral de la pirámide
    ladoA = sqrt(pow(base[0][0] - h[0], 2) + pow(base[0][1] - h[1], 2) + pow(base[0][2] - h[2], 2));
    s = (a + ladoA + c) / 2;
    areaTotal += area(s, a, ladoA, c);

    ladoB = sqrt(pow(base[1][0] - h[0], 2) + pow(base[1][1] - h[1], 2) + pow(base[1][2] - h[2], 2));
    s = (a + b + ladoB) / 2;
    areaTotal += area(s, a, b, ladoB);

    ladoA = sqrt(pow(base[2][0] - h[0], 2) + pow(base[2][1] - h[1], 2) + pow(base[2][2] - h[2], 2));
    s = (b + c + ladoA) / 2;
    areaTotal += area(s, b, c, ladoA);

    return areaTotal;
}
