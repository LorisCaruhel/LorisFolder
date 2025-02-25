#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 5

typedef char chaine20[21];
typedef chaine20 tabnoms[N];

void affiche(tabnoms t, int n); 
void maintientTrie(tabnoms t, int i);
void triParInsertion(tabnoms t, int n);

int main(){
   //déclaration des variables
    tabnoms tNoms = {"toto","zozo","loto","momo","tutu"};

    printf("Non trié :\n");
    affiche(tNoms, N);

    triParInsertion(tNoms, N);

    printf("\nTrié :\n");
    affiche(tNoms, N);

   return EXIT_SUCCESS;
}

void affiche(tabnoms t, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", t[i]);
    }
}

void maintientTrie(tabnoms t, int i)
{
    chaine20 temp;

    while(i != 0 && strcmp(t[i], t[i-1]) < 0)
    {
        strcpy(temp, t[i-1]);
        strcpy(t[i-1], t[i]);
        strcpy(t[i], temp);

        i--;
    }
}

void triParInsertion(tabnoms t, int n)
{
    int j = 1;

    while(j < n)
    {
        maintientTrie(t, j);

        j++;
    }
}

//zozo tutu toto momo loto