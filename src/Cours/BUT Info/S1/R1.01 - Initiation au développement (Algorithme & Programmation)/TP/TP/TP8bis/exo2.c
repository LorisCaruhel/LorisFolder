#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 10

typedef int tab[N];

void affiche(tab t, int n); 
void Trie(tab t);

int main(){
   //déclaration des variables
    tab t = {4, 1, 5, 9, 10, 11, 7, 3, 8, 6};

    printf("Non trié :\n");
    affiche(t, N);
    printf("\n");

    Trie(t);

    printf("\nTrié :\n");
    affiche(t, N);
    printf("\n");

   return EXIT_SUCCESS;
}

void affiche(tab t, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", t[i]);
        printf("  ");
    }
}

void Trie(tab t)
{
    int iMin, temp;

    for(int i = 0; i < N - 1; i++)
    {
        iMin = i;
        for(int j = i + 1; j < N; j++)
        {
            if(t[iMin] > t[j])
            {
                iMin = j;
            }
        }
        temp = t[iMin];
        t[iMin] = t[i];
        t[i] = temp;
    }
}
