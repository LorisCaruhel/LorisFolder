#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes
const int MOY_10 = 10;
const int MOY_8 = 8;

int main(){
   //déclaration des variables
   float moyUE1 = 0.0;
   float moyUE2 = 0.0;
   float moyG = 0.0;

   // saisie des données
    printf("Entrez votre moyenne de votre UE1 : ");
    scanf("%f", &moyUE1);
    printf("Entrez votre moyenne de votre UE2 : ");
    scanf("%f", &moyUE2);

   // traitement des données
    moyG = (moyUE1 + moyUE2)/2.0;

   // affichage des résultats
    if(moyG < 10.0)
    {
        printf("Jury souverain\n");
    }
    else if(moyG >= 10)
    {
        if(moyUE1 < 8)
        {
            printf("Redoublement\n");
        }
        else if(moyUE2 < 8)
        {
            printf("Redoublement\n");
        }
        else if(moyUE1 >= 8 && moyUE2 >= 8)
        {
            printf("Semestre validée bravo !\n");
        }
    }

   return EXIT_SUCCESS;
}