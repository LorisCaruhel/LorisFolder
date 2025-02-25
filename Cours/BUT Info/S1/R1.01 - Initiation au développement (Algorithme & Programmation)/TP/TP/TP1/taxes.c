#include <stdio.h>
#include <stdlib.h>

int main()
{ // Declaration des variables
float TTC = 0;
float pourcentage = 0;
float htaxe = 0;
// Saisie des donnees
printf("Donner votre prix hors taxes :");
scanf("%f", &htaxe);
printf("Donner votre pourcentage de taxes :");
scanf("%f", &pourcentage);
TTC = htaxe + (htaxe * pourcentage / 100.0);
// Affichage
printf("Le prix TTC est de %.2f", TTC);
return EXIT_SUCCESS;
}