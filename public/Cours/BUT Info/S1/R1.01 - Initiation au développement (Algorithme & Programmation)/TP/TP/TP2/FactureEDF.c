#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
const int LOCATION_COMPTEUR = 1500;
const float TVA = 0.2;
const float PRIX_10 = 10.0;
const float PRIX_15 = 15.0;
const float PRIX_20 = 20.0;

int main(){
   //déclaration des variables
    float quantiteConsomme = 0.0;
    float prixTTC = 0.0;

   // saisie des données
    printf("Entrez votre quantité d'électricité consommé (en kWh) : ");
    scanf("%f", &quantiteConsomme);

   // traitement des données
    if(quantiteConsomme <= 100.0)
    {
        prixTTC = (quantiteConsomme * PRIX_10);
    }
    else if(100.0 < quantiteConsomme && quantiteConsomme <= 150.0)   
    {
        prixTTC = 100.0 * PRIX_10;
        quantiteConsomme = quantiteConsomme - 100.0;
        prixTTC = prixTTC + (quantiteConsomme * PRIX_15);
    }
    else if(quantiteConsomme > 150.0)
    {
        prixTTC = 100.0 * PRIX_10;
        quantiteConsomme = quantiteConsomme - 100.0;
        prixTTC = prixTTC + (50.0 * PRIX_15);
        quantiteConsomme = quantiteConsomme - 50.0;
        prixTTC = prixTTC + (quantiteConsomme * PRIX_20);
    }

prixTTC = (prixTTC + LOCATION_COMPTEUR )* (1.0 + TVA);
prixTTC = prixTTC / 100.0;

   // affichage des résultats
    printf("Le prix TTC de vos consommation électrique est de : %.2f euro\n", prixTTC);

   return EXIT_SUCCESS;
}