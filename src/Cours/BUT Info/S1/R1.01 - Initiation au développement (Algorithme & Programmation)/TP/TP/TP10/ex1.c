#include <stdio.h>
#include <stdlib.h>

#define MAX_CAR 20

typedef char chaine[MAX_CAR + 1];
typedef struct
{
    chaine nom;
    chaine prenom;
    int age;
}etudiant;

void afficheEtudiant(etudiant e1);
void saisieEtudiant(etudiant *e1);
int compare(etudiant e1, etudiant e2);

int main()
{   
    etudiant etu1;
    etudiant etu2;

    saisieEtudiant(&etu1);
    saisieEtudiant(&etu2);

    afficheEtudiant(etu1);
    afficheEtudiant(etu2);

    compare(etu1, etu2);
}

int compare(etudiant e1, etudiant e2)
{
    int x = 0;

    if(e1.age > e2.age)
    {
        x = 1;
    }
    else
    {
        x = -1;
    }

    return x;
}

void saisieEtudiant(etudiant *etu)
{
    printf("Entrez le nom et prénom de l'étudiant(dans cet ordre) : ");
    scanf("%s %s", etu->nom, etu->prenom);

    printf("Son âge ? ");
    scanf("%d", &etu->age);
}

void afficheEtudiant(etudiant e1)
{
    printf("Etudiant : %s %s, %d ans\n", e1.nom, e1.prenom, e1.age);
}