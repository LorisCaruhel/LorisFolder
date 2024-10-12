#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int main () 
{
    clock_t begin = clock();

    for (int i=0 ; i<100000 ; i++)
    {
        for (int j=0 ; j<100000 ; j++)
        {
        }
    }
    sleep(3);

    clock_t end = clock();
    double tmpsCPU = (end - begin)*1.0 / CLOCKS_PER_SEC;

    printf( "Temps CPU = %.3f secondes\n",tmpsCPU);

    return EXIT_SUCCESS;
}