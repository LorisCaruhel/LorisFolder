#include <stdio.h>
#include <stdlib.h>

int main()
{ // Declaration des variables
char nom[10];
char groupe;
// Saisie des donnees
printf("Nom ? ");
scanf("%s", nom);
printf("Groupe ? ");
scanf("%c", &groupe);
// Affichage
printf("Nom=%s\n",nom);
printf("Groupe=%c\n",groupe);
return EXIT_SUCCESS;
}