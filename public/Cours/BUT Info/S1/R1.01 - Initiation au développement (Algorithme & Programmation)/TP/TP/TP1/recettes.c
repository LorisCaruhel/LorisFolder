#include <stdio.h>
#include <stdlib.h>

int main(){
// variables contenant les quantités
float pruneaux, farine, sucre, lait;
int oeufs;
int nbpers = 0;
// initialisation des quantités
pruneaux = 250.0;
farine = 200.0;
sucre = 150.0;
oeufs = 4;
lait = 0.75;
// affichage des quantités
printf("Pour combien de personnes voulez-vous faire le far breton : ");
scanf("%d", &nbpers);
printf("Pour préparer un Far Breton pour %d personnes, il faut :\n", nbpers);
printf(" %f grammes de pruneaux\n", pruneaux*nbpers/8);
printf(" %f grammes de farine\n", farine*nbpers/8);
printf(" %f grammes de sucre\n", sucre*nbpers/8);
printf(" %d oeufs\n", oeufs*nbpers/8);
printf(" %f litre(s) de lait\n", lait*nbpers/8);
return EXIT_SUCCESS;
}