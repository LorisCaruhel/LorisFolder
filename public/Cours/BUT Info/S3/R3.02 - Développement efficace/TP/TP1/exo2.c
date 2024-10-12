#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine20[21];

typedef struct {
    chaine20 nom;
    int population;
    chaine20 capitale;
} t_region;

int main() {
    //////// QUESTION 1 ////////

    // t_region reg;

    // printf("Donnez un nom : ");
    // scanf("%s", reg.nom);
    // printf("Nombre de personne : ");
    // scanf("%d", &reg.population);
    // printf("Donnez une capitale : ");
    // scanf("%s", reg.capitale);

    // printf("Nom : %s\n", reg.nom);
    // printf("Population : %d\n", reg.population);
    // printf("Capitale : %s\n", reg.capitale);


    //////// QUESTION 2 ////////

    // t_region* pt_region;
    // pt_region = (t_region*)malloc(sizeof(t_region));

    // strcpy(pt_region->nom, "Bretagne");
    // pt_region->population = 600000;
    // strcpy(pt_region->capitale, "Rennes");

    // printf("Nom : %s\n", pt_region->nom);
    // printf("Population : %d\n", pt_region->population);
    // printf("Capitale : %s\n", pt_region->capitale);


    //////// QUESTION 3 ////////

    t_region* pt_region;
    pt_region = (t_region*)malloc(sizeof(t_region));

    printf("Donnez un nom : ");
    scanf("%s", pt_region->nom);
    printf("Nombre de personne : ");
    scanf("%d", &pt_region->population);
    printf("Donnez une capitale : ");
    scanf("%s", pt_region->capitale);

    printf("Nom : %s\n", pt_region->nom);
    printf("Population : %d\n", pt_region->population);
    printf("Capitale : %s\n", pt_region->capitale);

    return 0;
}