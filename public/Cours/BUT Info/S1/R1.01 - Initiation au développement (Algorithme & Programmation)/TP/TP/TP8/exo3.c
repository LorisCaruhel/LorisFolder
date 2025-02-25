#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define N 10
typedef int tabEntiers[N];

int recherche_dicho_recursif(int valeur, tabEntiers tablo, int debut, int fin);

int main()
{
    int valeur;
    tabEntiers tab = {13, 24, 35, 42, 53, 68, 77, 83, 88, 91};

    int iMax, iMin;
    iMax = N-1;
    iMin = 0;

    printf("Valeur à chercher :\n");
    scanf("%d", &valeur);

    int trouve = recherche_dicho_recursif(valeur, tab, iMin, iMax);

    if(trouve == -1)
    {
        printf("La valeur est introuvable.\n"); 
    }
    else
    {
        printf("L'indice de la valeur dans le tableau est %d\n", trouve);
    }recherche_dicho_recursif(valeur, tablo, debut, fin);

   return EXIT_SUCCESS;
}


int recherche_dicho_recursif(int valeur, tabEntiers tablo, int debut, int fin)
{
    int result = -1;
    int iMilieu;

    iMilieu = (fin + debut)/2;

    if(fin < debut)
    {
        return result;
    }
    else if(tablo[iMilieu] == valeur)
    {
        result = iMilieu;
    }
    else if(tablo[iMilieu] > valeur)
    {
        fin = iMilieu - 1;
        return recherche_dicho_recursif(valeur, tablo, debut, fin);
    }
    else if(tablo[iMilieu] < valeur)
    {
        debut = iMilieu + 1;
        return recherche_dicho_recursif(valeur, tablo, debut, fin);
    }

    return result;
    }


