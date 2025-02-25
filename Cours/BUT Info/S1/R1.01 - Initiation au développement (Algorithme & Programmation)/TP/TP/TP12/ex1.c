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
    produit tabElts[MAX_ELTS];
    int nbElts;
}t_pile;

const produit PRODUIT_VIDE = {"---- PRODUIT VIDE ----", -1};

void saisir(produit *adr_prod, int dateJ);
void afficher(produit prod);
void modifdate(int* adr_datej);

// Fonction primitive.
bool estVide(t_pile p);
bool estPleine(t_pile p);
t_pile initialiser();
produit depiler(t_pile *adrPile);
void empiler(t_pile *adrPile, produit elt);
produit sommet(t_pile p) ;
void vider(t_pile *adrPile);
void entree(t_pile *frigo, produit p);
void sortie(t_pile *frigo, int dateJ);


int main()
{
    int choix = -1;
    int dateJ = 0;
    produit prod;
    t_pile frigo;
    
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

void sortie(t_pile *frigo, int dateJ)
{
    if(estVide(*frigo))
    {
        printf("Erreur pile vide.\n");
    }
    else
    {
        if((dateJ - frigo->tabElts[frigo->nbElts].dateEntStock) > 3)
        {
            printf("Tout est périmé !\n");
            vider(frigo);
        } 
        else
        {
            depiler(frigo); 
        }
    }
}

void entree(t_pile *frigo, produit p)
{
    if(estPleine(*frigo))
    {
        printf("Erreur pile pleine.");
    }
    else
    {
        empiler(frigo, p);
    }   
}

produit sommet(t_pile p) 
{ 
    // la pile est un paramètre d’entrée
    produit elt;

    if (!(estVide(p))) 
    {
        // le sommet de la pile est à l’indice p.nbElts - 1
        elt = p.tabElts[p.nbElts-1];
    }
    else
    {
        elt = PRODUIT_VIDE;
    }

    return elt;
}

void empiler(t_pile *adrPile, produit elt)
{
    if (!(estPleine(*adrPile))) 
    {
        adrPile->tabElts[adrPile->nbElts]=elt ;
        adrPile->nbElts=adrPile->nbElts+1;
        // Attention aux indices du tableau
    }
    else
    {
        printf("La pile est pleine");
    }
}

produit depiler(t_pile *adrPile)
{
    produit elt;

    if (!(estVide(*adrPile))) 
    {
        elt =adrPile-> tabElts[adrPile-> nbElts-1] ;
        (adrPile-> nbElts)--;
        // nettoyage de la pile
        adrPile->tabElts[adrPile-> nbElts] = PRODUIT_VIDE;
    }
    else
    {
        elt = PRODUIT_VIDE;
    }

    return elt;
}

t_pile initialiser() 
{
    t_pile p;

    for (int i = 0; i < MAX_ELTS; i++)
    {
        p.tabElts[i] = PRODUIT_VIDE; // tous les éléments de la pile sont initialisés
        p.nbElts = 0;
    }

    return p;
}

void vider(t_pile *adrPile)
{
    for(int i = adrPile->nbElts -1; i >= 0; i--)
    {
        adrPile-> tabElts[i] = PRODUIT_VIDE;
    }
    adrPile-> nbElts = 0;
}

bool estPleine(t_pile p)
{
    return (p.nbElts == MAX_ELTS);
}

bool estVide(t_pile p)
{
    return (p.nbElts == 0);
}

void saisir(produit *adr_prod, int dateJ)
{
    // Met dans *adr_prod un produit saisi au clavier à la date dateJ
    printf("Référence ? ");
    scanf("%s", adr_prod->reference);
    adr_prod->dateEntStock = dateJ;
}

void afficher(produit prod)
{
    // Affiche à l'écran le produit prod
    printf("%s %d\n",prod.reference, prod.dateEntStock);
}

void modifdate(int* adr_datej)
{
    //tourne la page de l'éphéméride
    (*adr_datej)++;
}