/**
 * 
 * $auteur <nom de l'auteur>
 * $brevedesc Code qui demande un nom, un prénom, un âge et les notes d'un étudiant.
 * $version v1.0
 * $date 23/11/23
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAJORITE 18 /** $def Age de la majorité.*/
#define TAILLE 30/** $def Taille max pour le nom et le prenom.*/


typedef struct 
{
    char nom[TAILLE]; /** $argstruc Nom de l'utilisateur. */
    char prenom[TAILLE]; /** $argstruc Prénom de l'utilisateur. */
    float moy; /** $argstruc Adresse de l'utilisateur. */
    int age; /** $argstruc Age de l'utilisateur. */
}str_etudiant; /** $nomstruc Structure d'un utilisateur. */

typedef struct 
{
    char nom[TAILLE]; /** $argstruc Nom de l'équipe. */
    char matiere[TAILLE]; /** $argstruc Nombre d'utilisateur dans l'équipe. */
}str_classe; /** $nomstruc Nom du nouveau type structure. */

void afficherUtilisateur(str_etudiant s_etudiant, str_classe equipe1);/** $enteteFonc Entete de la fonction afficheUtilisatauer pour que le main sache qu'elle paramètre elle attend.*/
void saisirUtilisateur(str_etudiant *s_etudiant, str_classe *s_promo);/** $enteteFonc Entete de la fonction saisirUtilisateur pour que le main sache qu'elle paramètre elle attend.*/


int main()
{
    str_etudiant s_etudiant;
    str_classe s_promo;

    saisirUtilisateur(&s_etudiant, &s_promo);
    afficherUtilisateur(s_etudiant, s_promo);
}

/**
* $brevedesc Affiche les caractéristique de l'utilisateur 1.
* $detail Afficher un détail plus précis si nécssesaire.
*
* $return Ici ne retourne rien car cela est une procédure.
*
* $param s_utilisateur1 Structure représentant l'utilisateur 1.
* $param s_equipe1 Structure représentant l'équipe 1.
*
*/

void afficherUtilisateur(str_etudiant s_etudiant, str_classe s_promo) 
{
    printf("\nInformations de l'utilisateur :\n");
    printf("Nom : %s\n", s_etudiant.nom);
    printf("Prénom : %s\n", s_etudiant.prenom);
    if(s_etudiant.age == MAJORITE)
    {
        printf("L'étudiant est majeur !\n");
    }
    else
    {
        printf("Âge : %d", s_etudiant.age);
    }
    printf("Moyenne : %.2f\n", s_etudiant.moy);
    printf("Fait partis de la promo %s\n", s_promo.nom);
}


/**
* $brevedesc Saisie les caractéristique de l'utilisateur 1.
* $detail Afficher un détail plus précis si nécssesaire.
*
* $return Ici ne retourne rien car cela est une procédure.
*
* $param s_utilisateur1 Structure représentant l'utilisateur 1.
* $param s_equipe1 Structure représentant l'équipe 1.
*
*/

void saisirUtilisateur(str_etudiant *s_etudiant, str_classe *s_promo) 
{
    printf("Entrez le nom de l'étudiant :\n");
    scanf("%s", (*s_etudiant).nom);

    printf("Entrez le prénom de l'étudiant :\n");
    scanf("%s", (*s_etudiant).prenom);

    printf("Entrez la moyenne de l'étudiant :\n");
    scanf("%f", &(*s_etudiant).moy);

    printf("Entrez l'âge de l'étudiant :\n");
    scanf("%d", &(*s_etudiant).age);

    printf("Dans quelle promo êtes-vous ?\n");
    scanf("%s", (*s_promo).nom);

    if(strcmp((*s_promo).nom, "Lesbarbus\0") == 0)
    {
        printf("La meilleur promo de l'IUT bon choix !\n");
    }
    else
    {
        printf("Pas mal mais y'a mieux comme promo...\n");
    }
}
