#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
const int A_ENFANT = 7;
const int A_ADULTE = 12;

const int B_ENFANT = 8;
const int B_ADULTE = 14;

const int C_ENFANT = 9;
const int C_ADULTE = 16;

const int D_ENFANT = 10;
const int D_ADULTE = 18;

int main(){
   //déclaration des variables
    char periode;
    int nbAdulte = 0;
    int nbEnfant = 0;
    int prixTotal = 0;

   // saisie des données
    printf("Quel période choisissez vous ?\n");
    scanf("%c", &periode);
    printf("Combien d'adulte êtes-vous ?\n");
    scanf("%d", &nbAdulte);
    printf("Combien d'enfant êtes-vous ?\n");
    scanf("%d", &nbEnfant);

   // traitement et affichage des données
    switch (periode)
    {
    case 'A':
        prixTotal = (nbAdulte * A_ADULTE) + (nbEnfant * A_ENFANT);
        printf("Le prix total à payer pour la periode A avec %d enfants et %d adultes est %d", nbEnfant, nbAdulte, prixTotal);
        break;
    case 'B':
        prixTotal = (nbAdulte * B_ADULTE) + (nbEnfant * B_ENFANT);
        printf("Le prix total à payer pour la periode B avec %d enfants et %d adultes est %d", nbEnfant, nbAdulte, prixTotal);
    case 'C':
        prixTotal = (nbAdulte * C_ADULTE) + (nbEnfant * C_ENFANT);
        printf("Le prix total à payer pour la periode C avec %d enfants et %d adultes est %d", nbEnfant, nbAdulte, prixTotal);
    case 'D':
        prixTotal = (nbAdulte * D_ADULTE) + (nbEnfant * D_ENFANT);
        printf("Le prix total à payer pour la periode D avec %d enfants et %d adultes est %d", nbEnfant, nbAdulte, prixTotal);
    default:
        printf("Erreur de saisie, entrez une periode valide");
        break;
    }

   return EXIT_SUCCESS;
}