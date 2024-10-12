#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float fcalcul(int v1, int v2);
void test();

int main()
{
    int v1 = 0;
    int v2 = 0;

    printf("Entrez le premier nombre :\n");
    scanf("%d", &v1);
    printf("Entrez le deuxième nombre :\n");
    scanf("%d", &v2);
    
    test();

    printf("%.2f\n", fcalcul(v1, v2));

   return EXIT_SUCCESS;
}

float fcalcul(int v1, int v2)
{
    int v12 = 0;

    v12 = (v1 * v1) + (v2 * v2);


    return sqrtf(v12);
}

void test()
{
    printf("valeur attendue : %.3f valeur obtenue : %.3f\n",5.0,fcalcul(3,4));
    printf("valeur attendue : %.3f valeur obtenue : %.3f\n",1.414,fcalcul(1,1));
    printf("valeur attendue : %.3f valeur obtenue : %.3f\n",0.0,fcalcul(0,0));
    printf("valeur attendue : %.3f valeur obtenue : %.3f\n",3.606,fcalcul(2,3));
    printf("valeur attendue : %.3f valeur obtenue : %.3f\n",10.630,fcalcul(7,8));
}