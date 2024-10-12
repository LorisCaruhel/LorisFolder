#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX1 10
#define MAX2 20

typedef int t_tab2dim[MAX1][MAX1];

void init(t_tab2dim t2d);
void affiche(t_tab2dim t2d);
bool existe(t_tab2dim t2d, int val);

int main()
{
    t_tab2dim le_Tablo;
    int val;

    init(le_Tablo);

    affiche(le_Tablo);

    printf("Quel valeur voulez-vous chercher ? ");
    scanf("%d", &val);

    if(existe(le_Tablo, val))
    {
        printf("Présent !\n");
    }
    else
    {
        printf("Non présent !\n");
    }

    return EXIT_SUCCESS;
}

void init(t_tab2dim t2d)
{
    int s = 0;

    for(int i = 0; i < MAX1; i++)
    {
        for(int j = 0; j < MAX1; j++)
        {
            s = s + (i + j);
        } 
    }

    for(int lig = 0; lig < MAX1; lig++)
    {
        for(int col = 0; col < MAX1; col++)
        {
            t2d[lig][col] = s;
        } 
    }
}

void affiche(t_tab2dim t2d)
{
    for(int lig = 0; lig < MAX1; lig++)
    {
        printf("| ");
        for(int col = 0; col < MAX1; col++)
        {
            printf("%d ", t2d[lig][col]);
        } 
        printf("|\n");
    }
}

bool existe(t_tab2dim t2d, int val)
{
    bool trouver = false;
    int lig = 0, col = 0;

    while(!trouver && lig < MAX1)
    {
        col = 0;
        while(col < MAX2 && col < MAX1)
        {
            if(t2d[lig][col] == val)
            {
                trouver = true;
            }
            col++;
        } 
        lig++;
    }

    return trouver;
}
