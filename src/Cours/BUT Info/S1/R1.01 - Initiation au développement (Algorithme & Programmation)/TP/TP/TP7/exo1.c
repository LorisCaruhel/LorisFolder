#include <stdlib.h>
#include <stdio.h>

#define N 5

typedef int unTableau[N];

int somme(unTableau Tab);

int main(){
   //déclaration des variables
    unTableau monTab = {5, 12, 15, 10, 10};

    printf("Valeur attendu : %d         Valeur obtenus : %d\n", 52, somme(monTab));

   return EXIT_SUCCESS;
}

int somme(unTableau Tab)
{
    int somme = 0;

    for(int i = 0; i < N; i++)
    {
        somme = somme + Tab[i];
    }

    return somme;
}