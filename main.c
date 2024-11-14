#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    float p_base, s_base, a_base; //perimetro y area
    float p_total;
    float area_total;
    float a, b, c;  //lados
    float areas[4];  //areas de los cuatro triangulos
    float puntos[4][3]; //base y vértice superior

    puntos[0][0] = ingresarComponente('X', 1);
    puntos[0][1] = ingresarComponente('Y', 1);
    puntos[0][2] = ingresarComponente('Z', 1);
    puntos[1][0] = ingresarComponente('X', 2);
    puntos[1][1] = ingresarComponente('Y', 2);
    puntos[1][2] = ingresarComponente('Z', 2);
    puntos[2][0] = ingresarComponente('X', 3);
    puntos[2][1] = ingresarComponente('Y', 3);
    puntos[2][2] = ingresarComponente('Z', 3);

    //entrada de las coordenadas del vertice superior
    puntos[3][0] = ingresarComponente('X', 4); //nuevo punto 4
    puntos[3][1] = ingresarComponente('Y', 4);
    puntos[3][2] = ingresarComponente('Z', 4);

   
    distancias(&a, &b, &c, puntos);  //calcula las distancias de la base
    perimetro(&p_base, &s_base, a, b, c);  //perímetro y el semiperímetro
    areas[0] = area(s_base, a, b, c);
    p_total = p_base;  

    //areas de las tres caras laterales
    for (int i = 1; i <= 3; i++) {  //bucle para cada cara lateral
        distancias(&a, &b, &c, (float[3][3]){  // calcula usabdo un punto superior y nos inferiores
            {puntos[i % 3][0], puntos[i % 3][1], puntos[i % 3][2]},
            {puntos[(i + 1) % 3][0], puntos[(i + 1) % 3][1], puntos[(i + 1) % 3][2]},
            {puntos[3][0], puntos[3][1], puntos[3][2]}
        });
        perimetro(&p_base, &s_base, a, b, c);  //semiperímetro
        areas[i] = area(s_base, a, b, c);
    }

    // area total de la superficie
    area_total = areas[0] + areas[1] + areas[2] + areas[3];

    printf("El perimetro de la base = %f\n", p_total); 
    printf("El area de la base = %f\n", areas[0]);
    printf("El area total de la superficie de la piramide = %f\n", area_total);

    return 0;
}


//    gcc *.c -o main
//    .\main.exe