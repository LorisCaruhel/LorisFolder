#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ELTS 20

typedef char chaine10[26];
typedef struct
{
    chaine10 reference;
    int dateEntStock;
} produit;

typedef struct
{
    produit tabElt[MAX_ELTS];
    int nb;
}t_file;

const produit PRODUIT_VIDE = {"---- PRODUIT VIDE ----", -1};

void saisir(produit *adr_prod, int dateJ);
void afficher(produit prod);
void modifdate(int* adr_datej);
void afficheTous(t_file F);

// Fonction primitive.
bool estVide(t_file F);
bool estPleine(t_file F);
t_file initialiser();
produit defiler(t_file *adrF);
void enfiler(t_file *adrF, produit elt);
produit tete(t_file F);
void vider(t_file *adrF);


int main()
{
    int choix = -1;
    int dateJ = 0;
    produit prod;
    t_file frigo;
    
    frigo = initialiser();

    while(choix != 0){
            printf("---------------------------------------------------------------------\n");
            printf("1 : Entrée d'un produit dans le stock \n");
            printf("2 : Vente d'un produit sorti du stock \n");
            printf("3 : Le temps passe \n");
            printf("0 : Quitter \n");
            printf("Votre choix : ");
            scanf("%d", &choix);
            switch(choix){
                case 0: break;
                case 1: 
                    printf("Date de mise en stock ? ");
                    scanf("%d", &dateJ);
                    saisir(&prod, dateJ);
                    entree(&frigo, prod);
                    break;
                case 2:
                    sortie(&frigo, dateJ);
                    break;
                case 3: 
                    modifdate(&dateJ);
                    break;
                default: printf("Erreur de choix\n");
            }
        }

    return EXIT_SUCCESS;
}

produit tete(t_file F)
{
    produit elt;

    elt = F.tabElt[(F.nb)-1];

    return elt;
}

void enfiler(t_file *adrF, produit elt)
{
    if(!estPleine(*adrF))
    {
        adrF->tabElt[adrF->nb] = elt;
        (adrF->nb)++;
    }
    else
    {
        printf("Pile pleine\n");
    }
}

produit defiler(t_file *adrF)
{
    produit elt;

    if(!estVide(*adrF))
    {
        elt = adrF->tabElt[0];

        for(int i = 0; i < ((adrF->nb) - 1); i++)
        {
            adrF->tabElt[i] = adrF->tabElt[i + 1];
        }
        adrF->tabElt[(adrF->nb)-1] = PRODUIT_VIDE;
        (adrF->nb)--;
    }
    else
    {
        printf("... Perdu ...\n");
        elt = PRODUIT_VIDE;
    }

    return elt;
}

void afficheTous(t_file F)
{
    for(int i = 0; i < MAX_ELTS; i++)
    {
        printf("%s %d\n", F.tabElt[i].reference, F.tabElt[i].dateEntStock);
    }
}

t_file initialiser()
{
    t_file F;

    F.nb = 0;

    for(int i = 0; i < MAX_ELTS; i++)
    {
        F.tabElt[i] = PRODUIT_VIDE;
    }

    return F;
}

bool estVide(t_file F)
{
    bool estVide = false;

    if(F.nb == 0)
    {
        estVide = true;
    }

    return estVide;
}

bool estPleine(t_file F)
{
    bool estPleine = false;

    if(F.nb == MAX_ELTS)
    {
        estPleine = true;
    }

    return estPleine;
}

void vider(t_file *adrF)
{
    while(!estVide(*adrF))
    {
        defiler(adrF);
    }
}