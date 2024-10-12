#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef char t_chaine50[51];
typedef char t_chaine10[11];

typedef struct
{
    t_chaine50 c_nom; // nom de l’abonné
    t_chaine10 c_num; // numéro de cet abonné
    int c_duree; // durée pour laquelle il est abonné
}t_abonne;

typedef t_abonne t_tabAbo[MAX];

const t_abonne ELT_VIDE = {"toto", "000", 0};
const char MARQUEUR[2] = "*";

void lister(char nomFic[]);
void initAbonne(char nomFic[]);
void creerAbonnes(char nomFic[]);
void ajouterAbonnes(char nomFic[]);
void tri(char nomFic[]);
void afficheNum(char nomFichier[]);
void prolongeAbonnement(char nomFichier[]);
void prolongeAbonnementUnAbo(char nomFichier[]);

int main()
{
    int choix = -1;
    char nomFic[30] = "ABONNES.DATA";

    while(choix != 0){
        printf("---------------------------------------------------------------------\n");
        printf("0 : Arrêter le programme \n");
        printf("1 : Créer un fichier et entrer des abonnés \n");
        printf("2 : Afficher les abonnés \n");
        printf("3 : Ajout d'un nouveau abonné \n");
        printf("4 : Init abonnnés \n");
        printf("5 : Trier le tableau \n");
        printf("6 : Chercher le numéro d'un abinné \n");
        printf("7 : Prolongement d'abonnement \n");
        printf("8 : Prolongement d'un abonnement \n");
        printf("votre choix : ");
        scanf("%d", &choix);
        switch(choix){
            case 0: break;
            case 1: 
                    creerAbonnes(nomFic);
                    break;
            case 2: 
                    lister(nomFic);
                    break;
            case 3: 
                    ajouterAbonnes(nomFic);
                    break;
            case 4: 
                    initAbonne(nomFic);
                    break;
            case 5: 
                    tri(nomFic);
                    break;
            case 6:
                    afficheNum(nomFic);
                    break;
            case 7:
                    prolongeAbonnement(nomFic);
                    break;
            default: printf("erreur de choix\n");
        }
    }
    return EXIT_SUCCESS;
}

void prolongeAbonnementUnAbo(char nomFichier[])
{
    FILE *f;
    t_abonne a;
    t_tabAbo t_abo;

    f = fopen(nomFichier, "rb");
    int i = 0;
    int prolongement;

    //copierFichierDansTableau
    fread(&a, sizeof(a), 1, f);
    while(!feof(f) && i < MAX)
    {
        t_abo[i] = a;
        i++;
        fread(&a, sizeof(a), 1, f);
    }   

    int nbElt = i;


    printf("De combien voulez-vous prolongé l'abonnement ?\n");
    scanf("%d", &prolongement);

    t_abo[i].c_duree = t_abo[i].c_duree + prolongement;

    fclose(f);

    //copierDansFichier
    f = fopen(nomFichier, "wb");

    fwrite(&t_abo[i], sizeof(a), 1, f);

    fclose(f);
}

void prolongeAbonnement(char nomFichier[])
{
    FILE *f;
    t_abonne a;
    t_tabAbo t_abo;

    f = fopen(nomFichier, "rb");
    int i = 0;
    int prolongement;

    //copierFichierDansTableau
    fread(&a, sizeof(a), 1, f);
    while(!feof(f) && i < MAX)
    {
        t_abo[i] = a;
        i++;
        fread(&a, sizeof(a), 1, f);
    }   

    int nbElt = i;

    printf("De combien voulez-vous prolongé l'abonnement ?\n");
    scanf("%d", &prolongement);

    for(int i = 0; i < nbElt; i++)
    {
        t_abo[i].c_duree = t_abo[i].c_duree + prolongement;
    }

    fclose(f);

    //copierTableauDansFichier
    f = fopen(nomFichier, "wb");

    for(int i = 0; i < nbElt; i++)
    {
        fwrite(&t_abo[i], sizeof(a), 1, f);
    }

    fclose(f);
}

void afficheNum(char nomFichier[])
{
    FILE * f;
    t_abonne a;
    t_tabAbo abo;
    bool trouver = false;
    int i = 0;

    t_chaine50 nom;
    printf("Donner un nom :");
    scanf("%s", nom);

    f = fopen(nomFichier, "rb");

    //copierFichierDansTableau
    fread(&a, sizeof(a), 1, f);
    while(!feof(f) && i < MAX)
    {
        abo[i] = a;
        i++;
        fread(&a, sizeof(a), 1, f);
    }   


    while(i > 0 && !trouver)
    {
        if(strcmp(abo[i].c_nom, nom) == 0)
        {
            a = abo[i];
            trouver = true;
        }
        else
        {
            i--;
        }
    }

    printf("Le numéro de l'abonné %s est %s\n", nom, a.c_num);
}

void tri(char nomFic[])
{
    FILE * f;
    f = fopen(nomFic, "rb");
    t_abonne a;
    t_tabAbo abo;
    t_abonne temp;
    int i = 0;
    int nbElt = 0;

    //copierFichierDansTableau
    fread(&a, sizeof(a), 1, f);
    while(!feof(f) && i < MAX)
    {
        abo[i] = a;
        i++;
        fread(&a, sizeof(a), 1, f);
    }

    fclose(f);

    //maintientTrie
    nbElt = i;
    for(int j = 1; j < nbElt; j++)
    {
        i = j;
        while(i > 0 && strcmp(abo[i].c_nom, abo[i - 1].c_nom) < 0)
        {
            temp = abo[i];
            abo[i] = abo[i - 1];
            abo[i - 1] = temp;

            i--;
        }
    }

    //copierTableauDansFichier
    f = fopen(nomFic, "wb");

    for(int i = 0; i < nbElt; i++)
    {
        fwrite(&abo[i], sizeof(a), 1, f);
    }

    fclose(f);
}

void creerAbonnes(char nomFic[])
{
    FILE * f;
    f = fopen(nomFic, "wb");
    t_abonne a;

    printf("Entrez un nom (* pour stopper la saisie) :\n");
    scanf("%s", a.c_nom);
    while(strcmp(a.c_nom, MARQUEUR) != 0)
    {   
        printf("Entrez un numéro :\n");
        scanf("%s", a.c_num);
        printf("Durée d'abonnement :\n");
        scanf("%d", &a.c_duree);

        fwrite(&a, sizeof(a), 1, f);

        printf("Entrez un nom (* pour stopper la saisie) :\n");
        scanf("%s", a.c_nom);
    }

    fclose(f);
}

void ajouterAbonnes(char nomFic[])
{
    FILE * f;
    f = fopen(nomFic, "ab");
    t_abonne a;

    printf("Entrez un nom (* pour stopper la saisie) :\n");
    scanf("%s", a.c_nom);
    while(strcmp(a.c_nom, MARQUEUR) != 0)
    {   
        printf("Entrez un numéro :\n");
        scanf("%s", a.c_num);
        printf("Durée d'abonnement :\n");
        scanf("%d", &a.c_duree);

        fwrite(&a, sizeof(a), 1, f);

        printf("Entrez un nom (* pour stopper la saisie) :\n");
        scanf("%s", a.c_nom);
    }

    fclose(f);
}

void initAbonne(char nomFic[])
{
    FILE * f;

    f = fopen(nomFic, "wb");

    for(int i = 0; i < 20; i++)
    {
        fwrite(&ELT_VIDE, sizeof(t_abonne), 1, f);
    }

    fclose(f);
}

void lister(char nomFic[]) 
{
    FILE * f;
    t_abonne a;

    f = fopen(nomFic, "rb");

    fread(&a, sizeof(a), 1, f);
    while(!feof(f))
    {
        printf("%s %s %d\n", a.c_nom, a.c_num, a.c_duree);
        fread(&a, sizeof(a), 1, f);
    }

    fclose(f);
}

