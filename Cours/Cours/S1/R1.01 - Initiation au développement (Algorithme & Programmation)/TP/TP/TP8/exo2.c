#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define N 10
typedef int tabEntiers[N];

int recherche_dicho_iteratif(int valeur, tabEntiers tablo);

int main()
{
    int valeur;
    tabEntiers tab = {13, 24, 35, 42, 53, 68, 77, 83, 88, 91};

    printf("Valeur à chercher :\n");
    scanf("%d", &valeur);

    int trouve = recherche_dicho_iteratif(valeur, tab);

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


int recherche_dicho_iteratif(int valeur, tabEntiers tablo)
{
    int result = -1;
    bool trouve = false;
    int iMax, iMin, iMilieu;

    iMax = N-1;
    iMin = 0;
    iMilieu = (iMax + iMin)/2;

    while(iMax >= iMin && trouve != true)
    {
        if(tablo[iMilieu] == valeur)
        {
            result = iMilieu;
            trouve = true;
        }
        else if(tablo[iMilieu] > valeur)
        {
            iMax = iMilieu - 1;
            iMilieu = (iMax + iMin)/2;
        }
        else if(tablo[iMilieu] < valeur)
        {
            iMin = iMilieu + 1;
            iMilieu = (iMax + iMin)/2;
        }
    }

    return result;
}
