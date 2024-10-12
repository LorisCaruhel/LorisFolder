#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int genere(int borne);  
int compare(int nbAleatoire, int nbSaisie);
int jeu(int nbAleatoire, int nbSaisie);
void afficheGagne();

int main()
{   
    srand(time(NULL));
    int nbSasie = 0;

    int nbAleatoire = genere(1000);

    jeu(nbAleatoire, nbSasie);

   return EXIT_SUCCESS;
}   

int genere(int borne)
{
    int nb = rand() % borne;
    return nb;
}

int compare(int aleatoire, int saisie)
{
    int res = 0;

    if(saisie > aleatoire)
    {
        res = 1;
        printf("Nombre saisie superieur !\n");
        printf("\nEntrez un nombre inferieur\n\n");
    }
    else if(saisie < aleatoire)
    {
        res = -1;
        printf("Nombre saisie inférieur !");
        printf("\nEntrez un nombre superieur\n\n");
    }

    return res; 
}

int jeu(int aleatoire, int saisie)
{
    int nbEssaie = 0;

    printf("Entrez un nombre :\n");
    scanf("%d", &saisie);

    while(saisie != aleatoire)
    {
        nbEssaie++;
        compare(aleatoire, saisie);

        printf("Entrez un nombre :\n");
        scanf("%d", &saisie);
    }

    afficheGagne(nbEssaie);

    return nbEssaie;
}

void afficheGagne(int essaie)
{
    printf("Nombre saisie égale ! Bien joué !\n");
    printf("Le nombre d'essais est de : %d\n", essaie);
}