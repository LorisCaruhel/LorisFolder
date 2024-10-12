#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ECRIVAINS 20

// Définissions des nouveau types.
typedef struct{
    int jour;
    int mois;
    int an;
}date;
typedef char chaine20[21];
typedef struct{
    chaine20 nom;
    chaine20 prenom;
    date naissance;
    date mort;
}ecrivain;

// Prototypes de fonction
void affichageDate(date d);
void lireDate(date *d);
int compare(date d1, date d2);
void lister(char nomFic[]);
bool existe(char nomFic[], chaine20 nom);
void ajouter(char nomFic[]);
bool comtemporaint(ecrivain e1, ecrivain e2);
void copierDansTableau(char nomFic[], ecrivain t[], int *nb);
void affcherMatrice(ecrivain t[], int nb);

// Fonction principale.
int main()
{
    // Appeler les différentes fonctions.
    int nb;
    ecrivain t[MAX_ECRIVAINS];
    copierDansTableau("Ecrivains.data", t, &nb);
    for (int i = 0 ; i<nb ; i++){
        printf("%s\n", t[i].nom);
    }

    return EXIT_SUCCESS;
}

void affichageDate(date d)
{
    if(d.jour > 0 && d.mois > 0 && d.an > 0)
    {
        printf("%d/%d/%d", d.jour, d.mois, d.an);
    }
    else
    {
        printf("--/--/----");
    }
}

void lireDate(date *d)
{
    printf("Jour ? ");
    scanf("%d", &d->jour);
    printf("Mois ? ");
    scanf("%d", &d->mois);
    printf("Année ? ");
    scanf("%d", &d->an);
    while((d->jour < 0) || (d->mois) < 0 || (d->an < 0))
    {
        printf("Erreur de saisie, Réessayer.\n");
        printf("Jour ? ");
        scanf("%d", &d->jour);
        printf("Mois ? ");
        scanf("%d", &d->mois);
        printf("Année ? ");
        scanf("%d", &d->an);
    }
}

int compare(date d1, date d2)
{   
    int plusGrand;

    if((d1.jour > 0 && d1.mois > 0 && d1.an > 0) &&
       (d2.jour > 0 && d2.mois > 0 && d2.an > 0))
    {
        if(d1.an == d2.an)
        {
            if(d1.mois > d2.mois)
            {
                plusGrand = 1;
            }
            else if(d1.mois < d2.mois)
            {
                plusGrand = -1;
            }
            else if(d1.mois == d2.mois)
            {
                if(d1.jour > d2.jour)
                {
                    plusGrand = 1;
                }
                else if(d1.jour < d2.jour)
                {
                    plusGrand = -1;
                }
                else
                {
                    plusGrand = 0;
                }
            }
        }
        else if(d1.an > d2.an)
        {
            plusGrand = 1;
        }
        else if(d1.an < d2.an)
        {
            plusGrand = -1;
        }
    }
    else if(d1.jour == 0 && d1.mois == 0 && d1.an == 0)
    {
        plusGrand = -1;
    }
    else if(d2.jour == 0 && d2.mois == 0 && d2.an == 0)
    {
        plusGrand = 1;
    }

    return plusGrand;
}

void lister(char nomFic[])
{
    FILE *f;
    ecrivain e1;
    
    f = fopen(nomFic, "rb");

    fread(&e1, sizeof(ecrivain), 1, f);
    while(!feof(f))
    {
        printf("%s %s (", e1.prenom, e1.nom);
        affichageDate(e1.naissance);
        printf(", ");
        affichageDate(e1.mort);
        printf(")\n");
        fread(&e1, sizeof(ecrivain), 1, f);
    }

    fclose(f);
}

bool existe(char nomFic[], chaine20 nom)
{
    bool present = false;
    FILE *f;
    ecrivain e1;
    
    f = fopen(nomFic, "rb");

    fread(&e1, sizeof(ecrivain), 1, f);
    while(!feof(f) && !present)
    {
        if(strcmp(e1.nom, nom) == 0)
        {
            present = true;
        }
        else
        {
            fread(&e1, sizeof(ecrivain), 1, f);
        }   
    }

    fclose(f);

    return present;
}

void ajouter(char nomFic[])
{
    FILE *f;
    ecrivain e1;
    
    f = fopen(nomFic, "ab");

    printf("Nom ? ");
    scanf("%s", e1.nom);
    printf("Prenom ? ");
    scanf("%s", e1.prenom);
    printf("Date de naissance ?\n");
    lireDate(&e1.naissance);
    printf("Date de mort ? (Mettre de 0 partout si il est vivant)\n");
    lireDate(&e1.mort);

    if(existe(nomFic, e1.nom))
    {
        printf("Écrivain déjà présent !\n");
    }
    else if (compare(e1.naissance, e1.mort) == -1)
    {
        printf("Il ne peut pas être mort avant sa naissance !\n");
    }
    else
    {
        fwrite(&e1, sizeof(ecrivain), 1, f);
    }

    fclose(f);
}

bool comtemporaint(ecrivain e1, ecrivain e2)
{
    bool comtemporain = false;

    if(compare(e1.naissance, e2.mort) == 1)
    {
        comtemporain = true;
    }

    return comtemporain;
}

void copierDansTableau(char nomFic[], ecrivain t[], int *nb)
{
    FILE *f;
    ecrivain e1;
    int nbEcrivains = 0;
    
    f = fopen(nomFic, "rb");

    fread(&e1, sizeof(ecrivain), 1, f);
    while(!feof(f) && nbEcrivains < MAX_ECRIVAINS)
    {
        t[nbEcrivains] = e1;
        nbEcrivains++;
        fread(&e1, sizeof(ecrivain), 1, f);
    }

    fclose(f);
}

void affcherMatrice(ecrivain t[], int nb)
{
    for(int i = 0; i < nb; i++)
    {
        printf("\t\t\t\t%d ", i);
    }

    printf("\n");

    for(int i = 0; i < nb; i++)
    {
        printf("%d-%-18s", i, t[i].prenom);

        for(int j = 0; j < MAX_ECRIVAINS; j++)
        {
            if(comtemporaint(t[i], t[j]))
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }
    }
}