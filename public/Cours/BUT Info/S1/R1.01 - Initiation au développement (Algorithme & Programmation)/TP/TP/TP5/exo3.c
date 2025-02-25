#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const float TAUX = 0.2;

void traiterUnEmploye(char nom[20], float salaireB, float *salaireT);
void afficherMoyenne(int salaireT, int nbEmployes);

int main()
{
    char nom[20];
    float salaireT = 0;
    float salaireB = 0;
    int nbEmployes = 0;

    printf("Entrez votre nom : \n");
    scanf("%s", nom);

    while (strcmp(nom, "*") != 0)
    {
        printf("\nEntrez votre salaire brut : \n");
        scanf("%f", &salaireB);

        while (salaireB < 0)
        {
            printf("Entrez votre salaire brut : \n");
            scanf("%f", &salaireB);
        }

        traiterUnEmploye(nom, salaireB, &salaireT);

        printf("Entrez votre nom : \n");
        scanf("%s", nom);

        nbEmployes++;
    }
    
    if(nbEmployes != 0)
    {
        afficherMoyenne(salaireT, nbEmployes);
    }


    return EXIT_SUCCESS;
}

void traiterUnEmploye(char nom[20], float salaireB, float *salaireT)
{
    float salaireN = 0;

    salaireN = salaireB - (salaireB * TAUX);

    printf("%s votre salaire net est de %.2f euros\n", nom, salaireN);

    *salaireT = *salaireT + salaireN;
}

void afficherMoyenne(int salaireT, int nbEmployes)
{
    float moy = 0;

    if (nbEmployes != 0)
    {
        moy = salaireT / nbEmployes;
    }

    printf("Le salaire net moyen est de %.2f euros \n", moy);
}
