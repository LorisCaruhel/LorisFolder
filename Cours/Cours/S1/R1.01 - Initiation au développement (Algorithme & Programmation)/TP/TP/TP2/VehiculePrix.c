#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
const float DISTANCE_ESSENCE = 1.2;
const float DISTANCE_DIESEL = 1.0;
const int PRIX_ESSENCE = 10;
const int PRIX_DIESEL = 15;

int main(){
   //déclaration des variables
    float disanceParcouru = 0.0;
    int jourLocation = 0.0;
    float prixTotalEssence = 0.0;
    float prixTotalDiesel = 0.0;

   // saisie des données
    printf("Quel distance avez-vous parcourus ?\n");
    scanf("%f", &disanceParcouru);
    printf("Durant combien de jour ?\n");
    scanf("%d", &jourLocation);

   // traitement des données
    prixTotalDiesel = (disanceParcouru * DISTANCE_DIESEL) + (jourLocation * PRIX_DIESEL);
    prixTotalEssence = (disanceParcouru * DISTANCE_ESSENCE) + (jourLocation * PRIX_ESSENCE);

   // affichage des résultats
    if(prixTotalDiesel < prixTotalEssence)
    {
        printf("Véhicule diesel moins coûteux\n");
        printf("Le prix sera de %.2f\n", prixTotalDiesel);
    }
    else if(prixTotalDiesel > prixTotalEssence)
    {
        printf("Véhicule essence moins cher\n");
        printf("Le prix sera de %.2f\n", prixTotalEssence);
    }
    else
    {
        printf("Les deux véhicules on le mêmes prix\n");
    }

   return EXIT_SUCCESS;
}