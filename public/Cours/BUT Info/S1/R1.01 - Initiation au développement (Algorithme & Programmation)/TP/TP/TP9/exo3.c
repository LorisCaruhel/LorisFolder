#include <stdio.h>
#include <stdlib.h>

const char MARQUEUR = '*';
const int MAX = 30;

typedef float t_stat[MAX][MAX];

void saisir(int *cat, int *trAge, int *nbFilms, t_stat stat);
void moyenne(t_stat stat, t_stat nbSpec, t_stat moyenne);

int main()
{
    int cat, trAge, nbFilms;

    t_stat stat;
    t_stat nbSpec;
    t_stat moyennes;

    saisir(&cat, &trAge, &nbFilms, stat, nbSpec);
    moyenne(stat, nbSpec, moyenne);

    afficheTab(moyennes);
}

t_stat moyenne(t_stat stat, t_stat nbSpec, t_stat moyenn)
{
    for(int lig = 0; lig < MAX; lig++)
    {
        for(int col = 0; col < MAX; col++)
        {
            if(stat[lig][col] != 0)
            {
                moyenne[lig][col] = nbSpec[lig][col] / stat[lig][col];  
            }
        }
    }
}

void saisir(int *cat, int *trAge, int *nbFilms, t_stat stat)
{
    t_stat nbSpec;
    char nom[MAX];

    printf("Nom ? ");
    scanf("%s", nom); 

    while(nom != MARQUEUR)
    {      
        printf("Catégorie ? ");
        scanf("%d", cat);

        printf("Tranche d'âge ? ");
        scanf("%d", trAge);

        printf("Nombre de film vu ? ");
        scanf("%d", nbFilms);

        stat[*cat][*trAge] = stat[*cat][*trAge] + *nbFilms;
        nbSpec[*cat][*trAge] = nbSpec[*cat][*trAge]++;

        printf("Nom ? ");
        scanf("%d", cat); 
    }

    return nbSpec;
}


void afficheTab(t_stat affiche)
{
    for(int lig = 0; lig < MAX; lig++)
    {
        for(int col = 0; col < MAX; col++)
        {
            printf("%.2f | ", affiche[lig][col]);
        }
    }
}