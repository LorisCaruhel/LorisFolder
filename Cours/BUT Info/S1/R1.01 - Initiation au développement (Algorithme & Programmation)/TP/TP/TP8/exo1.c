#include <stdlib.h>
#include <stdio.h>

#define N 10
typedef int tabEntiers[N+1];

int recherche_sequentielle(int valeur, tabEntiers tablo);

int main()
{
    int valeur;
    tabEntiers tab = {23, 54, 65, 12, 43, 78, 68, 93, 18, 31};

    printf("Valeur à chercher :\n");
    scanf("%d", &valeur);

    int trouve = recherche_sequentielle(valeur, tab);

    if(trouve == -1)
    {
        printf("La valeur est introuvable.\n"); 
    }
    else
    {
        printf("L'indice de la valeur dans le tableau est %d\n", trouve);
    }

   return EXIT_SUCCESS;
}


int recherche_sequentielle(int valeur, tabEntiers tablo )
{
    int result = -1;
    int i = 0;

    while(i < N && tablo[i] != valeur)
    {
        i++;
    }
    if(valeur == tablo[i])
    {
        result = i;
    }
    
    return result;
}