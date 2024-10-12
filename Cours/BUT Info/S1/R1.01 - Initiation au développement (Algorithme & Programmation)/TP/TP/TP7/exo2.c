#include <stdlib.h>
#include <stdio.h>

#define N 5

typedef int vecteur[N] ;

void remplirVecteur (vecteur v);
void afficherVecteur (vecteur v);
void sommeVecteur (vecteur v1, vecteur v2, vecteur vSomme);

int main(){
   //déclaration des variables
    vecteur v1;
    vecteur v2;
    vecteur Vsomme;

    printf("Entrez les valeurs de v1 :\n");
    remplirVecteur(v1);

    printf("Entrez les valeurs de v2 :\n");
    remplirVecteur(v2);

    sommeVecteur(v1, v2, Vsomme);

    afficherVecteur(Vsomme);

   return EXIT_SUCCESS;
}

void remplirVecteur (vecteur v)
{
    int i = 0;

    while(i !=  N)
    {
        printf("Entrez une valeur entière :\n");
        scanf("%d", &v[i]);
        i++;
    }
}

void afficherVecteur (vecteur v)
{
    int i = 0;

    while(i != N)
    {
        printf("Valeur de la %dème valeur =  %d\n", i, v[i]);
        i++;
    }
}

void sommeVecteur (vecteur v1, vecteur v2, vecteur vSomme)
{
    int i = 0;

    while(i != N)
    {
        vSomme[i] = v1[i] + v2[i];
        i++;
    }
}