#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 198 // 22 équipes de 9 coureurs = 198 coureurs
#define MARQUEUR -1

typedef struct{
    int c_numero;
    int c_temps;
}t_concurrent;
typedef t_concurrent t_tabconc[MAX];

void insere(t_concurrent c, t_tabconc tc, int *n);
void permuter(t_concurrent* c1, t_concurrent* c2);
void affiche_classement(t_tabconc tc, int n);

int main()
{
    int numC, temps, n = 0;
    t_concurrent c;
    t_tabconc tabConc;

    printf("Entrez le numéro du concurent :\n");
    scanf("%d", &numC);
    while(numC != -1)
    {
        printf("Entrez le temps du concurent :\n");
        scanf("%d", &temps);

        c.c_numero = numC;
        c.c_temps = temps;
        insere(c, tabConc, &n);

        printf("Entrez le numéro du concurent :\n");
        scanf("%d", &numC);
    }
    affiche_classement(tabConc, n);
}

void affiche_classement(t_tabconc tc, int n)
{
    int i = 0;

    printf("\n--------- Classement ---------\n");
    while(i < n)
    {
        printf("Concurrent %d : num:%d      temps:%d\n", i, tc[i].c_numero, tc[i].c_temps);
        i++;
    }
}

void insere(t_concurrent c, t_tabconc tc, int *n)
{   
    tc[*n] = c;
    int i = *n;

    while(i > 0 && tc[i-1].c_temps > tc[i].c_temps)
    {
        permuter(&tc[i-1], &tc[i]);
        i--;
    }
    (*n)++;
}

void permuter(t_concurrent *c1, t_concurrent *c2)
{   
    t_concurrent temp;

    temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}