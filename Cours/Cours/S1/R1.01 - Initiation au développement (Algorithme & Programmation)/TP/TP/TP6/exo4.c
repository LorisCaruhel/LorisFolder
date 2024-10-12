#include <stdlib.h>
#include <stdio.h>

float addition(float a, float b);
float soustraction(float a, float b);
float division(float a, float b);
float multiplication(float a, float b);

int main(){
   //déclaration des variables
    float nb1 = 0;
    float nb2 = 0;

   // saisie des données
    printf("Entrez le premier nombre :\n");
    scanf("%f", &nb1);
    printf("Entrez le deuxième nombre :\n");
    scanf("%f", &nb2);

   // traitement des données
    printf("%.2f\n", addition(nb1, nb2));
    printf("%.2f\n", soustraction(nb1, nb2));
    printf("%.2f\n", division(nb1, nb2));
    printf("%.2f\n", multiplication(nb1, nb2));

   // affichage des résultats

    float Resultat = soustraction(addition(multiplication(addition(division(addition(4.5, 1.3), 2.0), 1.1), 5.3), 4.2), 1.0);

    //((4.2 + (5.3 * ( ( (4.5 + 1.3) / 2.0) + 1.1) ) ) - 1.0 )

    printf("%.2f\n", Resultat);

   return EXIT_SUCCESS;
}


float addition(float a, float b)
{
    return a + b;
}


float soustraction(float a, float b)
{
    return a - b;
}


float division(float a, float b)
{
    float res = 0;

    if(b != 0)
    {
        res = a / b;
    }
    else
    {
        res = -1;
    }

    return res;
}


float multiplication(float a, float b)
{
    return a*b;
}

