#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char jouer();
char coupOrdi(int nbAleatoire);
int genere(int borne);
char compare(char action1, char action2);

int main()
{   
    srand(time(NULL));

    jouer();

   return EXIT_SUCCESS;
}   

int genere(int borne)
//génère un nombre aléatoire
{
    int nb = rand() % borne;
    return nb;
}

char coupOrdi(int nbAleatoire)
//Change le nombre généré aléatoirement en vrai "coup" pour l'ordinateur(P, C, F)
{
    char coupOrdiV;//Variable pour le coup de l'ordinateur convertis en caractère

    if(nbAleatoire == 0)
    {
        coupOrdiV = 'P';
    }
    else if (nbAleatoire == 1)
    {
        coupOrdiV = 'F';
    }
    else if (nbAleatoire == 2)
    {
        coupOrdiV = 'C';
    }
    else
    {
        printf("Erreur de nombre aléatoire.\n");
    }

    return coupOrdiV;
}

char compare(char action1, char action2)
//Compare le coup fait par l'utilisateur et par l'ordinateur et augmente leur compteur de points dans le cas gagnant pour eux
{
    char result; 

    if (action1 == 'P' && action2 == 'C')
    {
        result = 'G';
    }
    else
    {
        result = 'P';
    }

    if (action1 == 'P' && action2 == 'F')
    {
        result = 'P';
    }
    else 
    {
        result = 'G';
    }

    if (action1 == 'F' && action2 == 'C')
    {
        result = 'P';
    }
    else
    {
        result = 'G';
    }

    if (action1 == 'C' && action2 == 'P')
    {
        result = 'P';
    }
    else
    {
        result = 'G';
    }

    if (action1 == 'C' && action2 == 'F')
    {
        result = 'G';
    }
    else
    {
        result = 'P';
    }

    if(action1 == action2)
    {
        result = 'N';
    }

    return result;
}

char jouer()
//Permet de demander à l'utilisateur de saisir un coup et le programme le compare au coup généré aléatoirement 
//Et continue jusqu'à ce que un des deux score n'a pas atteint 3
//Et enfin compare le le score pour retourné si c'est l'ordinateur ou l'utilisateur qui a gagné
{
    char gagnant;
    char coupUtili;
    int compteurP1 = 0; //Score ordinateur
    int compteurP2 = 0; //Score Joueur
    char poubelle;

    int coupOrdiNB = genere(3);
    char action1 = coupOrdi(coupOrdiNB);
    printf("Le coup de l'ordinateur est %c :\n", action1);

    while(compteurP1 != 3 && compteurP2 != 3)
    {
        printf("Entrez un coup (P, F, C) :\n");
        scanf("%c%c", &coupUtili, &poubelle);

        char win = compare(action1, coupUtili);

        if(win == 'G')
        {
            compteurP1++;
            printf("Ordinateur gagnant !       Joueur = %d    Ordinateur = %d\n\n", compteurP2, compteurP1);
        }
        else if(win == 'P')
        {
            compteurP2++;
            printf("Joueur Gagnant !      Joueur = %d    Ordinateur = %d\n\n", compteurP2, compteurP1);
        }
        else
        {
            printf("Egalité ! Rejouer       Joueur = %d    Ordinateur = %d\n\n", compteurP2, compteurP1);
        }

        int coupOrdiNB = genere(3);
        action1 = coupOrdi(coupOrdiNB);
        printf("Le coup de l'ordinateur est %c :\n", action1);
    }

    if(compteurP1 == 3)
    {
        gagnant = 'O';
        printf("\nLe gagnant est l'ordinateur !\n");
        printf("Avec un score de %d et %d pour le joueur\n", compteurP1, compteurP2);
    }
    else
    {
        gagnant = 'H';
        printf("\nLe gagnant est le joueur !\n");
        printf("Avec un score de %d et %d pour l'ordinateur\n", compteurP2, compteurP1);
    }

    return gagnant;
}

