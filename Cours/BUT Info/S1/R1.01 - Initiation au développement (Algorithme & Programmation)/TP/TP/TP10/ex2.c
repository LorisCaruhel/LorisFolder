#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Defines
#define NM 12
#define MAX_CAR 10

//Types
typedef char t_chaine9[MAX_CAR];
typedef struct{
    t_chaine9 c_nom;
    int c_nbJours;
}t_mois;
typedef t_mois t_tabMois[NM];

//Fonctions
void afficheMois31();
int nbJours(t_chaine9 nomMois);

//Constantes
const t_tabMois tMois = 
{ 
    {"janvier",31},
    {"fevrier",28},
    {"mars",31},
    {"avril",30},
    {"mai",30},
    {"juin",30},
    {"juillet",30},
    {"aout",30},
    {"septembre",30},
    {"octobre",30},
    {"novembre",30},
    {"decembre", 31}
};

int main()
{
    t_chaine9 nom;

    printf("Donner un nom de mois :\n");
    scanf("%s", nom);

    printf("Le nombre de jour dans le mois %s est de %d\n", nom, nbJours(nom));
}

int nbJours(t_chaine9 nomMois)
{
    int nbJours = -1, i = 0;
    bool trouver = false;

    while(!trouver && i < NM)
    {
        if(strcmp(nomMois, tMois[i].c_nom) == 0)
        {
            nbJours = tMois[i].c_nbJours;
            trouver = true;
        }
        else
        {
            i++;
        }
    }

    return nbJours;
}

void afficheMois31()
{
    for(int i = 0; i < NM; i++)
    {
        if(tMois[i].c_nbJours == 31)
        {
            printf("%s %d\n", tMois[i].c_nom, tMois[i].c_nbJours);
        }
    }
}