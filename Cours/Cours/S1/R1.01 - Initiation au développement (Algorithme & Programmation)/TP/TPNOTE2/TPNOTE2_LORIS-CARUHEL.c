#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAILLE_MAX 15

const char MARQUEUR = '*';

typedef char tmot[TAILLE_MAX + 1];

void init(tmot initTab);
void lireMot(tmot lireTab);
void affiche(tmot afficheTab);
int longueur(tmot longueurTab);
void testLongueur();
bool estDans(tmot presentTab, char caracRecherche);
bool compare(tmot m1, tmot m2);
bool sequence(tmot m, char c1, char c2);

int main()
{
    testLongueur();

    tmot mot1, mot2, mot3;

    init(mot1);
    init(mot2);
    init(mot3);

    //Mot 1
    printf("\nEntrez le mot 1 :\n");
    lireMot(mot1);

    printf("\nMot 1 : ");
    affiche(mot1);
    printf("La longueur du %s est de %d\n", "mot1", longueur(mot1));

    //Mot 2
    printf("\nEntrez le mot 2 :\n");
    lireMot(mot2);

    printf("Mot 2 : ");
    affiche(mot2);
    printf("La longueur du %s est de %d\n", "mot2", longueur(mot2));

    //Mot 1
    printf("\nEntrez le mot 3 :\n");
    lireMot(mot3);

    printf("Mot 3 : ");
    affiche(mot3);
    printf("La longueur du %s est de %d\n", "mot3", longueur(mot3));


    if(estDans(mot1, 'S') == true)
    {
        printf("\nLe caractère %c est présent dans le mot %s\n", 'S', "mot1");
    }
    else
    {
        printf("\nLe caractère %c est absent dans le mot %s\n", 'S', "mot1");
    }


    if(sequence(mot3, 'L', 'A') == true)
    {
        printf("La séquence %s est présente dans le %s\n", "LA", "mot3");
    }
    else
    {
        printf("La séquence %s est absente dans le %s\n", "LA", "mot3");
    }

   return EXIT_SUCCESS;
}


void init(tmot initTab)//Initialise le tableau de caractère passé en paramètre.
{
    for(int i = 0; i < (TAILLE_MAX + 1); i++)
    {
        initTab[i] = MARQUEUR;
    }
}


void lireMot(tmot lireTab)//Lis des caractères qui rentre dans le tableau mis en paramètre jusqu'à que le MARQUEUR (*) soit 
                        //rentré ou que le tableau est plein
{
    char caractere, poubelle;
    int iTab = 0;

    printf("Entrez un caractère pour votre mot :\n");
    scanf("%c%c", &caractere, &poubelle);

    while(iTab < TAILLE_MAX && caractere != MARQUEUR)
    {
        lireTab[iTab] = caractere;

        printf("Entrez un caractère pour votre mot :\n");
        scanf("%c%c", &caractere, &poubelle);
        iTab++;
    }
}


void affiche(tmot afficheTab)//Affiche le tableau passé en entré.
{
    int iTab = 0;

    while(iTab < TAILLE_MAX && afficheTab[iTab] != MARQUEUR)
    {
        printf("%c", afficheTab[iTab]);
        iTab++;
    }
    printf("\n");
}


int longueur(tmot longueurTab)//Affiche la longueur du mot qui est dans le tableaux passé en paramètre sans compter le caractère *.
{
    int nbCaracteres = 0;

    while(nbCaracteres < TAILLE_MAX && longueurTab[nbCaracteres] != MARQUEUR)
    {
        nbCaracteres++;
    }

    return nbCaracteres;
}


void testLongueur()//Fonction de test pour la fonction longueur.
{
    tmot m1 = {'*'};
    tmot m2 = {'C', 'H', 'I', 'E', 'N', '*'};
    tmot m3 = {'B', 'O', 'A', '*'};
    tmot m4 = {'B', 'O', 'A', ' ', 'C', 'O', 'N', 'S', 'T', 'R', 'I', 'C', 'T', 'O', 'R', '*'};

    printf("Valeur attendu : %d         Valeur obtenus : %d\n", 0, longueur(m1));
    printf("Valeur attendu : %d         Valeur obtenus : %d\n", 5, longueur(m2));
    printf("Valeur attendu : %d         Valeur obtenus : %d\n", 3, longueur(m3));
    printf("Valeur attendu : %d         Valeur obtenus : %d\n", 15, longueur(m4));
}


bool estDans(tmot presentTab, char caracRecherche)//Cherche la présence d'un caractère passé en paramètre.
{
    int iTab = 0;
    bool present = false;

    while(iTab < TAILLE_MAX && !present && presentTab[iTab] != MARQUEUR)
    {
        if(presentTab[iTab] == caracRecherche)
        {
            present = true;
        }
        else
        {
            iTab++;
        }
    }

    return present;
}


bool compare(tmot m1, tmot m2)//Compare 2 mots et retourne true si ils sont égaux sinon false.
{
    int iTab = 0;
    int caractereIden = 0;
    bool identique = false;

    if(longueur(m1) == longueur(m2))
    {
        while(iTab < TAILLE_MAX && ( m1[iTab] != MARQUEUR && m2[iTab] != MARQUEUR ))
        {
            if(m1[iTab] == m2[iTab])
            {
                caractereIden++;
                iTab++;
            }
            else
            {
                iTab++;
            }
        }
    }
    else 
    {
        return identique;
    }

    if(caractereIden == longueur(m1) && caractereIden == longueur(m2))
    {
        identique = true;
    }
    else
    {
        identique = false;
    }
    
    return identique;
}


bool sequence(tmot m, char c1, char c2)//Cherche la présence d'une séquence de 2 caractères à la suite et rien d'autre.
{
    bool sequence = false;
    int iTab = 0;

    while(iTab < TAILLE_MAX && !sequence && m[iTab] != MARQUEUR)
    {
        if(m[iTab] == c1 && m[iTab + 1] == c2)
        {
            sequence = true;
        }
        else
        {
            iTab++;
        }
    }

    return sequence;
}