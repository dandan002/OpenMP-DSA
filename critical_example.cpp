#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdint.h>

static void critical_example(int v) {
    // shared variables
    int a = 0;
    int b = v;

    #pragma omp parallel 
    {
        int c;
        c = b;
        c = c * 10;

        #pragma omp critical 
        {
            a = a + c;
        }
    }
    std::cout << a << std::end1;
}

void main() {
    critical_example(1);
}