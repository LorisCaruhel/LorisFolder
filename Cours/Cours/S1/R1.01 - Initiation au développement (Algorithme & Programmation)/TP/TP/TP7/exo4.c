#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 10

const char MARQUEUR = '*';

typedef int unTableau[N];

void iniTab(unTableau total);
void decompoTotal(char nom[20], int val, unTableau total);


int main()
{
    unTableau total;
    unTableau valeur = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    iniTab(total);

    char nom[20];
    int somme;

    printf("Nom ? : ");
    scanf("%s", nom);

    while(strcmp(nom, MARQUEUR) != 0)
    {
        printf("Somme , : ");
        scanf("%d", &somme);

        decompoTotal(nom, somme, total);

        printf("Nom ? : ");
        scanf("%s", nom);
    }


    affichageClient();

   return EXIT_SUCCESS;
}

void iniTab(unTableau total)
{
    for(int i = 0; i < N; i++)
    {
        total[i] = 0;
    }
}

void decompoTotal(char nom[20], int val, unTableau total, unTableau valeur)
{   
    int nbBillet = 0;
    int somme = 0;

    while(somme != 0)
    {
        for(int i = 0; i < N; i++)
        {
            nbBillet = val/valeur[i];
            somme = somme % valeur[i];

            printf("%s :\n", nom);
            printf("%d x %d\n", nbBillet, valeur[i]);
        }
    }
}

void affichageClient(int nb)
{

}