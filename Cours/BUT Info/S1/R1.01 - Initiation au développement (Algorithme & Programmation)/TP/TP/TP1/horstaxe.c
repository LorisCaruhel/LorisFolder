#include <stdio.h>
#include <stdlib.h>

int main()
{ // Declaration des variables
float TTC = 0;
float pourcentage = 0;
float htaxe = 0;
// Saisie des donnees
printf("Donner votre prix avec taxes :");
scanf("%f", &TTC);
printf("Donner votre pourcentage de taxes :");
scanf("%f", &pourcentage);
htaxe = TTC - (TTC * pourcentage / 100.0);
// Affichage
printf("Le prix hors taxes est de %.2f\n", htaxe);
return EXIT_SUCCESS;
}