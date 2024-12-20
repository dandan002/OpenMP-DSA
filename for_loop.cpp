#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdint.h>

static void array_multiply(int a, int b) {
    // num = bytes of a / bytes of int
    int num = sizeof(a) / sizeof(a[0]);

    #pragma omp parallel 
    {
        #pragma omp for schedule(static)
        for (int i = 0; i < num; i++) 
        {
            a[i] = a[i] * b[i];
        }
    }
    for (int i = 0; i < 10; i++) 
    {
        std::cout << a[i] << std::endl;
    }
}

void main() {
    int a[10] = {0, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int b[10] = {0, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    array_multiply(a, b);
}