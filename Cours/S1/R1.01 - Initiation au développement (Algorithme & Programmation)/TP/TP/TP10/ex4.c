#include <stdio.h>
#include <stdlib.h>

#define MAX_CAR 20

typedef char chaine[MAX_CAR + 1];
typedef struct {
    int jour;
    int mois;
    int annee;
} date;
typedef struct
{
    chaine nom;
    chaine prenom;
    int age;
    date dateNaissance;
}etudiant;

const date date1 = {18, 12, 2005};
const date date2 = {29, 11, 2005};

void afficheEtudiant(etudiant e1);
void saisieEtudiant(etudiant *e1);
int compare(etudiant e1, etudiant e2);
void afficherAnnee(etudiant e);

int main()
{   
    etudiant etu1 =  {"Toto", "Tutu", 18, {29, 11, 2005}};
    etudiant etu2 = {"Loris", "Caruhel", 17, {18, 12, 2005}};


    afficherAnnee(etu1);
    afficherAnnee(etu2);

    if(compare(etu1, etu2) == 1)
    {   
        printf("etu1 est plus vieux\n");
    }
    else if(compare(etu1, etu2) == -1)
    {
        printf("etu2 est plus vieux\n");
    }
    else
    {   
        printf("etu2 et etu1 ont le même âge\n");
    }
}

void afficherAnnee(etudiant e)
{
    printf("L'année de naissance de l'étudiant %s %s est en %d\n", e.nom, e.prenom, (e.dateNaissance).annee);
}

int compare(etudiant e1, etudiant e2)
{
    int x = 444;

    if((e1.dateNaissance).annee > (e2.dateNaissance).annee)
    {
        x = 1;
    }
    else if((e1.dateNaissance).annee < (e2.dateNaissance).annee)
    {
        x = -1;
    }
    else if((e1.dateNaissance).annee == (e2.dateNaissance).annee)
    {
        if((e1.dateNaissance).mois > (e2.dateNaissance).mois)
        {
            x = 1;
        }
        else if((e1.dateNaissance).mois < (e2.dateNaissance).mois)
        {
            x = -1;
        }
        else if((e1.dateNaissance).mois == (e2.dateNaissance).mois)
        {
            if((e1.dateNaissance).jour > (e2.dateNaissance).jour)
            {
                x = 1;
            }
            else if((e1.dateNaissance).jour < (e2.dateNaissance).jour)
            {
                x = -1;
            }
            else
            {
                x = 0;
            }
        }
    }

    return x;
}

void saisieEtudiant(etudiant *etu)
{
    printf("Entrez le nom et prénom de l'étudiant(dans cet ordre) : ");
    scanf("%s %s", etu->nom, etu->prenom);

    printf("Son âge ? ");
    scanf("%d", &etu->age);

    printf("Jour de naissance de l'étudiant :\n");
    scanf("%d", &(etu->dateNaissance).jour);

    printf("Mois de naissance de l'étudiant :\n");
    scanf("%d", &(etu->dateNaissance).mois);

    printf("Année de naissance de l'étudiant :\n");
    scanf("%d", &(etu->dateNaissance).annee);
}

void afficheEtudiant(etudiant e1)
{
    printf("Etudiant : %s %s, %d ans\n", e1.nom, e1.prenom, e1.age);
}