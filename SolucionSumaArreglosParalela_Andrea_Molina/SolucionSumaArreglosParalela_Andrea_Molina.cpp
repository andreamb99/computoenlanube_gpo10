// SolucionSumaArreglosParalela_Andrea_Molina.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <ctime>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    
    srand(time(0));

    // Inicialización de los arreglos
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 1000; //Genera numeros aleatorios entre 0 y 1000
        b[i] = rand() % 1000;
    }

    int pedazos = chunk;

    // Paralelización con OpenMP
    #pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    for (int i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    // Imprimir resultados
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

    return 0;
}

// Función para imprimir los primeros valores del arreglo
void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}
