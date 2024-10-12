#include <stdlib.h>
#include <stdio.h>

#define N 21

typedef int unTableau[N];

void iniTab(unTableau Tab);
void ocuNote(unTableau Tab);
void afficherOcu(unTableau Tab);


int main()
{
    unTableau Tab;

    printf("Entrez les valeur des notes :\n");
    iniTab(Tab);

    ocuNote(Tab);

    afficherOcu(Tab);

   return EXIT_SUCCESS;
}

void iniTab(unTableau Tab)
{
    for(int i = 0; i < N; i++)
    {
        Tab[i] = 0;
    }
}

void ocuNote(unTableau Tab)
{
    int val = 0;

    printf("Entrez une valeur entière :\n");
    scanf("%d", &val);

    while(val != -1)
    {
       while(val < 0 || val > 20)
        {
            printf("Entrez une valeur de 0 à 20 ! Réessayer :\n");
            scanf("%d", &val);
        }
        Tab[val]++;
        printf("Entrez une valeur entière :\n");
        scanf("%d", &val);
    }
}

void afficherOcu(unTableau Tab)
{
    for(int i = 0; i < N; i++)
    {
        if(Tab[i] != 0)
        {
            printf("Le nombre d'occurences de %d est %d\n", i, Tab[i]);
        }
    }
}


