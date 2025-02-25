#include <stdlib.h>
#include <stdio.h>

//déclaration des constantes

void divisionE(int a, int b, int *quo, int *reste);

int main(){
   //déclaration des variables
    int a = 0;
    int b = 0;
    int quo = 0;
    int reste = 0;

   // saisie des données
    printf("Entrez deux nombres :\n");
    scanf("%d %d", &a, &b); 

    while(b == 0)
    {
        printf("Division par 0 impossible ! Resaisissez deux nombres : \n");
        scanf("%d %d", &a, &b);
    }

   // traitement des données
    divisionE(a, b, &quo, &reste);

   // affichage des résultats
    printf("Le division de %d par %d donne : quotien = %d et reste = %d", a, b, quo, reste);


   return EXIT_SUCCESS;
}

void divisionE(int a, int b, int *quo, int *reste)
{
    *quo = a/b;
    *reste = a%b;
}