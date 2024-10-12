#include <stdlib.h>
#include <stdio.h>

const float TAUX = 0.2;

void traiterUnEmploye(char nom, float salaireB, float *salaireT);

int main()
{
    char nom[20];
    float salaireT = 0;
    float salaireB = 0;
    int nbEmployes = 0;

    printf("Entrez votre nom : \n");
    scanf("%s", &nom);

    while (strcmp(nom, "*") != 0)
    {
        printf("Entrez votre salaire brut : \n");
        scanf("%f", &salaireB);

        while (salaireB < 0)
        {
            printf("Entrez votre salaire brut : \n");
            scanf("%f", &salaireB);
        }

        traiterUnEmploye(nom, salaireB, &salaireT);

        printf("Entrez votre nom : \n");
        scanf("%s", &nom);

        nbEmployes++;
    }

    afficherMoyenne(salaireT, nbEmployes);

    return EXIT_SUCCESS;
}

void traiterUnEmploye(char nom, float salaireB, float *salaireT)
{
    int salaireN = 0;

    salaireN = salaireB - (salaireB * TAUX);

    printf("%s votre salaire net est de %f euros\n", nom, salaireN);

    salaireT = salaireT + salaireN;
}

void afficherMoyenne(int salaireT, int nbEmployes)
{
    int moy = 0;

    if (salaireT != 0)
    {
        moy = salaireT / nbEmployes;
    }

    printf("Le salaire net moyen est de %f \ns", moy);
}
