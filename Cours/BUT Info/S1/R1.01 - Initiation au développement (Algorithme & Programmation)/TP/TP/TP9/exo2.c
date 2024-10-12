#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Pour le cyclisme : 90 % continuent, 3 % passent au foot, 2 % passent à la voile, 5 % arrêtent le sport
Pour le foot : 6 % passent au cyclisme, 80 % continuent, 3% passent à la voile, 11 % arrêtent le sport
Pour la voile : 8 % passent au cyclisme,2 % passent au foot, 75 % continuent, 15 % arrêtent le sport
Pour les inactifs : 5 % passent au cyclisme, 3 % passent au foot, 4 % passent à la voile, 88 % restent inactifs.

Pour les cyclistes = 0.9 * 35 + 0.06 * 25 + 0.08 * 20 + 0.05 * 20 = 31.5 + 1.5 + 1.6 + 1 = 35.6

Pour le foot  = 0.03 * 35 + 0.8 * 25 + 0.02 * 20 + 0.03 * 20 = 1.05 + 20 +  0.4 + 0.6 = 22.05

Pour la voile = 0.02 * 35 + 0.03 * 25 + 0.75 * 20 + 0.04 * 20 = 0.7 + 0.75 + 15 +  0.8 = 17.25

Pour les inactifs = 0.05 * 35 + 0.11 * 25 + 0.88 * 20 + 0.15 * 20 = 1.75 + 2.75 + 17.6 + 3 = 25.1
*/
#define MAX 10

typedef float t_vecteur[MAX];
typedef float t_matrice[MAX][MAX];

const int NB_SPORT = 4;

void afficheVecteur(t_vecteur vect);
void afficheMatrice(t_matrice mEvolution);
void produitVectMat(t_vecteur vInitial, t_matrice mEvolution, t_vecteur vResultat);
void copiervecteur(t_vecteur vInitial, t_vecteur vResultat);


int main()
{
    t_vecteur vect;
    t_matrice mEvolution;
    t_vecteur vResultat;

    vect[0] = 35;
    vect[1] = 25;
    vect[2] = 20;
    vect[3] = 20;

    mEvolution[0][0] = 0.9;
    mEvolution[0][1] = 0.06;
    mEvolution[0][2] = 0.08;
    mEvolution[0][3] = 0.05;
    
    mEvolution[1][0] = 0.03;
    mEvolution[1][1] = 0.8;
    mEvolution[1][2] = 0.02;
    mEvolution[1][3] = 0.03;

    mEvolution[2][0] = 0.02;
    mEvolution[2][1] = 0.03;
    mEvolution[2][2] = 0.75;
    mEvolution[2][3] = 0.04;

    mEvolution[3][0] = 0.05;
    mEvolution[3][1] = 0.11;
    mEvolution[3][2] = 0.15;
    mEvolution[3][3] = 0.88;

    afficheVecteur(vect);
    afficheMatrice(mEvolution);

    for(int i = 0; i < 30; i++)
    {
        produitVectMat(vect, mEvolution, vResultat);
        copiervecteur(vect, vResultat);
    }

    afficheVecteur(vResultat);
}

void afficheVecteur(t_vecteur vect)
{
    for(int i = 0; i < NB_SPORT; i++)
    {
        printf("%.2f ", vect[i]);
        printf("\n");
    }
}

void afficheMatrice(t_matrice mEvolution)
{
    for(int lig = 0; lig < NB_SPORT; lig++)
    {
        for(int col = 0; col < NB_SPORT; col++) 
        {
            printf("%.2f ", mEvolution[lig][col]);
        }  
        printf("\n");
    }
}

void produitVectMat(t_vecteur vInitial, t_matrice mEvolution, t_vecteur vResultat)
{
    for(int lig = 0; lig < NB_SPORT; lig++)
    {
        vResultat[lig] = 0;
        for(int col = 0; col < NB_SPORT; col++) 
        {
            vResultat[lig] = vResultat[lig] + (vInitial[col] * mEvolution[lig][col]);
        }
    }
}

void copiervecteur(t_vecteur vInitial, t_vecteur vResultat)
{
    for(int i = 0; i < NB_SPORT; i++)
    {
        vInitial[i] = vResultat[i];
    }
}