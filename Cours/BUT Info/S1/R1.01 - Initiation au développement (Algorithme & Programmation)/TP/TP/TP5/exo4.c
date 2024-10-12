#include <stdlib.h>
#include <stdio.h>

// déclaration des constantes
const int SCORE_G = 20;

void faireJouer(char nomJ1[20], char nomJ2[20], int *scoreJ1, int *scoreJ2);
void afficherResultat(char nomJ1[20], char nomJ2[20], int scoreJ1, int scoreJ2);

int main()
{
    // déclaration des variables
    char nomJ1[20];
    char nomJ2[20];
    int scoreJ1 = 0;
    int scoreJ2 = 0;

    printf("Quel est votre nom ? (J1)\n");
    scanf("%s", nomJ1);

    printf("Quel est votre nom ? (J2)\n");
    scanf("%s", nomJ2);

    faireJouer(nomJ1, nomJ2, &scoreJ1, &scoreJ2);
    afficherResultat(nomJ1, nomJ2, scoreJ1, scoreJ2);

    return EXIT_SUCCESS;
}

void faireJouer(char nomJ1[20], char nomJ2[20], int *scoreJ1, int *scoreJ2)
{
    int sommeJ1 = 0;
    int sommeJ2 = 0;

    while ((sommeJ1 < SCORE_G) && (sommeJ2 < SCORE_G))
    {
        printf("Entrez le score (%s) :\n", nomJ1);
        scanf("%d", scoreJ1);
        sommeJ1 = sommeJ1 +*scoreJ1;

        while (*scoreJ1 < 1 || *scoreJ1 > 6)
        {
            printf("Entrez un score entre 1 et 6 (%s) :\n", nomJ1);
            scanf("%d", scoreJ1);
        }

        while(*scoreJ1 == 6)
        {
            printf("Entrez le score (%s) :\n", nomJ1);
            scanf("%d", scoreJ1);
            sommeJ1 = sommeJ1 +*scoreJ1;

            while (*scoreJ1 < 1 || *scoreJ1 > 6)
            {
                printf("Entrez un score entre 1 et 6 (%s) :\n", nomJ1);
                scanf("%d", scoreJ1);
            }
        }


        if(sommeJ1 < SCORE_G)
        {
            printf("Entrez le score (%s) :\n", nomJ2);
            scanf("%d", scoreJ2);
            sommeJ2 = sommeJ2 + *scoreJ2;

            while (*scoreJ2 < 1 || *scoreJ2 > 6)
            {
                printf("Entrez un score entre 1 et 6 (%s) :\n", nomJ2);
                scanf("%d", scoreJ2);
            }

            while(*scoreJ2 == 6)
            {
                printf("Entrez le score (%s) :\n", nomJ2);
                scanf("%d", scoreJ2);
                sommeJ2 = sommeJ2 + *scoreJ2;

                while (*scoreJ2 < 1 || *scoreJ2 > 6)
                {
                    printf("Entrez un score entre 1 et 6 (%s) :\n", nomJ2);
                    scanf("%d", scoreJ2);
                }
            }
        }
    }
    *scoreJ1 = sommeJ1;
    *scoreJ2 = sommeJ2;
}

void afficherResultat(char nomJ1[20], char nomJ2[20], int scoreJ1, int scoreJ2)
{
    if(scoreJ1 >= SCORE_G)
    {
        printf("Le gagnant est %s\n", nomJ1);
        printf("Le score du gagnant est %d !\n", scoreJ1);
        printf("Le score du perdant est %d\n", scoreJ2);
    }
    else if (scoreJ2 >= SCORE_G)
    {
        printf("Le gagnant est %s\n", nomJ2);
        printf("Le score du gagnant est %d !\n", scoreJ2);
        printf("Le score du perdant est %d\n", scoreJ1);
    }
}