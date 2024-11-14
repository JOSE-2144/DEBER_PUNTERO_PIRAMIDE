#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    float p1, s1, a1, a, b, c;  // Variables para perímetro y área de la base
    float puntos[3][2];         // Coordenadas de los tres puntos de la base
    float altura[2];            // Coordenadas del vértice de la pirámide

    // Ingresar las coordenadas de la base
    puntos[0][0] = ingresarComponente('X', 1);
    puntos[0][1] = ingresarComponente('Y', 1);
    puntos[1][0] = ingresarComponente('X', 2);
    puntos[1][1] = ingresarComponente('Y', 2);
    puntos[2][0] = ingresarComponente('X', 3);
    puntos[2][1] = ingresarComponente('Y', 3);

    // Ingresar las coordenadas del vértice de la pirámide
    altura[0] = ingresarComponente('X', 4);
    altura[1] = ingresarComponente('Y', 4);

    // Calcular distancias entre los puntos de la base
    distancias(&a, &b, &c, puntos);
    perimetro(&p1, &s1, a, b, c); // Perímetro y semi-perímetro de la base
    a1 = area(s1, a, b, c);       // Área de la base

    // Calcular el área de las caras laterales
    float areaLateral = area_superficie_lateral(a, b, c, altura, puntos);

    // Mostrar los resultados
    printf("El perimetro de la base es: %f\n", p1);
    printf("El area de la base es: %f\n", a1);
    printf("El area total de la superficie de la piramide es: %f\n", a1 + areaLateral);

    return 0;
}


//    gcc *.c -o main
//    .\main.exe