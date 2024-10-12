#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int aleaInfBorne(int borne);

int main()
{
    printf("%d\n", aleaInfBorne(1000000));

   return EXIT_SUCCESS;
}   

int aleaInfBorne(int borne)
{
    srand(time(NULL));
    return rand() % borne;
}