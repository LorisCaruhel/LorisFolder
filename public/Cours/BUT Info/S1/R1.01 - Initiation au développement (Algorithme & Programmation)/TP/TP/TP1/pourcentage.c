#include <stdio.h>
#include <stdlib.h>

int main()
{ // Declaration des variables
float prix1 = 0;
float prix2 = 0;
float resultat = 0;
// Saisie des donnees
printf("Donner le premier prix :");
scanf("%f", &prix1);
printf("Donner le deuxième prix :");
scanf("%f", &prix2);
resultat = prix2 * prix1 / 100;

if(resultat >= 100)
{
    resultat = resultat - 100;
    printf("C'est une augmentation de %.2f pourcent\n", resultat);
}
else
{
    resultat = 100 - resultat;
    printf("C'est une diminution de %.2f pourcent\n", resultat);
}

return EXIT_SUCCESS;
}