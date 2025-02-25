#include <stdlib.h>
#include <stdio.h>

// déclaration des constantes
const int FIN = 0;

void plusGetP(int *plusG, int *plusP);

int main()
{
    // déclaration des variables
    int plusG = 0;
    int plusP = 0;

    plusGetP(&plusG, &plusP);

    // affichage des résultats
    if (plusG == -1 && plusP == -1)
    {
        printf("La suite est vide ! %d %d \n", plusG, plusP);
    }
    else
    {
        printf("Le plus grand nombre est %d et le plus petit %d\n", plusG, plusP);
    }

    return EXIT_SUCCESS;
}

void plusGetP(int *plusG, int *plusP)
{
    int nb;

    printf("Entrez un nombre : \n");
    scanf("%d", &nb);

    if (nb == FIN)
    {
        *plusG = -1;
        *plusP = -1;
    }
    else
    {
        *plusG = nb;
        *plusP = nb;

        while (nb != FIN)
        {
            if (nb > *plusG)
            {
                *plusG = nb;
            }

            if (nb < *plusP)
            {
                *plusP = nb;
            }

            printf("Entrez un nombre : \n");
            scanf("%d", &nb);
        }
    }
}