#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/** @def : Définie le N majuscule par 9 pour la taille de la grille*/
#define N 3

/**
 * 
 * @typedef : Définit le type de la grille du sudoku comme un type.
 * @param tgrille : Définit un nouveau type qui se nomme tgrille comme un tableau de 9 par 9. 
 * 
*/
typedef int tgrille[N*N][N*N]; 



void chargerGrille(tgrille *g);

void affichageGrille();

void saisir(int *testValeur);

bool possible(tgrille testSaisieGrille, int numLigne, int numColonne, int valeur);


tgrille grilleSudoku;

int main()
{
    int ligne = 0;
    int colonne = 0;
    int numero = 0;

    system("clear");

    chargerGrille(&grilleSudoku);

    while(1)
    {
        system("clear");

        affichageGrille(grilleSudoku);

        printf("Indice de la case ? (entier de 1 à 9) :\n");
        saisir(&ligne);
        saisir(&colonne);

        if(grilleSudoku[ligne][colonne] != 0)
        {
            printf("ici3");
            printf("IMPOSSIBLE, la case n'est pas libre.\n");
        }
        else
        {
            printf("ici4");
            printf("Valeur à insérer ? (entier de 1 à 9\n");
            saisir(&numero);

            if(possible(grilleSudoku, ligne, colonne, numero) == 1)
            {
                grilleSudoku[ligne][colonne] = numero;
            }
        }
    }
    printf("Grille pleine, fin de partie, Bravo !");

    return EXIT_SUCCESS;
}



/**
 * 
 * @brief : Fonction qui scan l'entrer de l'utilisateur pour saisir une valeur et qui redemande si ce n'est pas un 
 *          entier entre 1 et 9 en signalant erreur dans TOUS les autres cas.
 * @param testValeur : Valeur à tester
 * 
*/

void saisir(int *testValeur)
{
    bool verif = false;
    int x;
    char ch[20];

    while(verif != true)
    {
        scanf("%s", ch);

        if(sscanf(ch, "%d", &x) != 0)
        {
            printf("ici\n");
            if (x > 0 && x <= 9)
            {
                *testValeur = x;
                verif = true;
                printf("ici2\n");
            } 
            else 
            {
                printf("Erreur, valeur saisie erronée. Réessayé (entrez un entier de 1 à 9) : \n");
                    
            }
        } 
        else 
        {
            printf("Erreur, valeur saisie erronée. Réessayé (entrez un entier de 1 à 9) : \n");
                
        }
    }
}


/**
 * 
 * @brief : Fonction qui réalise des tests pour savoir si le numéro saisie par l'utilisateur peut être entré et qu'il n'est déjà pas
 *          présent dans le ligne, ni  dans la colonne et ni dans son carré 3x3 et qui l'insert dans la matrice à la place 
 *          ligne colonne que l'utilisateur à choisis et affiche la grille avec le changement.
 * @param ligne : pointeur pour récupérer la valeur de ligne dans une variable atteignable dans le main.
 * @param colonne : Même chose que ligne mais pour la colonne.
 * @param numero : Même chose que ligne et colonne mais pour le chiffre que l'utilisateur veut mettre dans le grille.
 * @param matriceG : matrice initialiser dans le main (grille de 9 par 9).
 * @param nb : Pour savoir la taille de la grille (9).
 * 
*/

bool possible(tgrille testSaisieGrille, int numLigne, int numColonne, int valeur)
{
    bool possible = false;

    bool fin = false;
    
    while(fin != true)
    {
        int i = 0;
        if(testSaisieGrille[numLigne][i] == valeur)
        {
            if(testSaisieGrille[numLigne][numColonne] != valeur)
            {
                printf("\nNombre déjà saisie dans la ligne\n");
                fin = true;
            }
        }
            
        else if(testSaisieGrille[i][numColonne] == valeur)
        {
            if(testSaisieGrille[numLigne][numColonne] != valeur)
            {
                printf("\nNombre déjà saisie dans la colonne\n");
                fin = true;
            }
        }
        i++;
    }
    return possible;
}


/**
 * 
 * @brief : Fonction qui scan l'entrer de l'utilisateur pour les ligne et colonne et qui redemande si ce n'est pas un 
 *          entier entre 1 et 9 en signalant erreur dans TOUS les autres cas.
 * @param ligne : pointeur pour récupérer la valeur de ligne dans une variable atteignable dans le main.
 * @param colonne : Même chose que ligne mais pour la colonne.
 * @param numero : Numéro saisie par l'utilisateur pour le placer dans la grille.
 * 
*/

void chargerGrille(tgrille *g)
{
    char nomFichier[30];
    FILE * f;

    printf("Nom du fichier ? (Grille[1-10].sud)\n");
    scanf("%s", nomFichier);

    f = fopen(nomFichier, "rb");
    if (f==NULL)
    {
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
    } 
    else 
    {
        fread(g, sizeof(int), 9*9, f);
    }
    fclose(f);
}


/**
 * 
 * @brief : Fonction assez explicite dans le nom qui permet d'afficher la grille.
 *
*/
void affichageGrille(tgrille testSaisieGrille)
{
    int compteur = 0;

    printf("     ");
    for(int i = 1; i <= (N*N); i++)
    {
        if(i == 4 || i == 7)
        {
            printf("  ");
            printf("%d ", i);
        }
        else
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    for (int l = 0 ; l < (N*N); l++)
    {
        if(l == 0 || l == 3 || l == 6)
        {
            printf("   ");
            for(int p = 0; p < 3; p++)
            {
                printf("+-------");  
            }
            printf("+");
            printf("\n");
            printf("%d  ", l+1);
        }
        else
        {
            printf("%d  ", l+1);
        }
        
        for (int c = 0 ; c < (N*N); c++)
        {
            if(c == 0 || c == 3 || c == 6)
            {
                printf("| ");
            }
            printf("%d ", testSaisieGrille[l][c]);
        }
        printf("| ");
        printf("\n");
        compteur++;
    }
    if(compteur == 9)
    {
        printf("   ");
        for(int p = 0; p < 3; p++)
        {
            printf("+-------");  
        }
        printf("+");
        printf("\n");
    }
}