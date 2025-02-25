#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char chaine20[21];
typedef struct noeud *arbre;
typedef struct noeud {
    chaine20 val;
    arbre gauche;
    arbre droit;
} Pnoeud;

const chaine20 STOP = "*";

void init(arbre *a);
void creerArbre(arbre *a);

bool rechercher(arbre a, chaine20 v);

void ajouter(arbre *a, chaine20 v);
void supprimer(arbre *a, chaine20 v);

void afficherValeur(chaine20 v);
void affichageInfixe(arbre a);
void affichagePrefixe(arbre a);
void affichageSuffixe(arbre a);
void afficher_arbre_styler(arbre a, int niveau, int espace);


int main() {
    arbre a;

    init(&a);
    creerArbre(&a);

    printf("\n");
    affichagePrefixe(a);
    printf("\n");

    chaine20 sup = "15";
    supprimer(&a, sup);
    
    affichagePrefixe(a);
    printf("\n");
}

void init(arbre *a) {
    *a = NULL;
}

void afficher_arbre_styler(arbre a, int niveau, int espace) {
    if (a == NULL) return;

    int espace_increment = 5;
    espace += espace_increment;

    afficher_arbre_styler(a->droit, niveau + 1, espace);

    printf("\n");
    for (int i = espace_increment; i < espace; i++) {
        printf(" ");
    }
    printf("%s\n", a->val);

    afficher_arbre_styler(a->gauche, niveau + 1, espace);
}

void creerArbre(arbre *a) {
    chaine20 val;

    printf("Valeur à ajouter : ");
    scanf("%s", val);

    while(strcmp(val, STOP) != 0) {
        ajouter(a, val);
        printf("Valeur à ajouter : ");
        scanf("%s", val);
    }
}

void afficherValeur(chaine20 v) {
    printf("%s ", v);
}

void affichageInfixe(arbre a) {
    if(a != NULL) {
        affichageInfixe(a->gauche);
        afficherValeur(a->val);
        affichageInfixe(a->droit);
    }
}

void affichagePrefixe(arbre a) {
    if(a != NULL) {
        afficherValeur(a->val);
        affichagePrefixe(a->gauche);
        affichagePrefixe(a->droit);
    }
}

void affichageSuffixe(arbre a) {
    if(a != NULL) {
        affichageSuffixe(a->gauche);
        affichageSuffixe(a->droit);
        afficherValeur(a->val);
    }
}

bool rechercher(arbre a, chaine20 v) {
    if(strcmp(a->val, v) == 0) {
        return true;
    }else {
        rechercher(a->droit, v);
        rechercher(a->gauche, v);
        return false;
    }
}

void ajouter(arbre *a, chaine20 v) {
    if (*a == NULL) {
        *a = (arbre)malloc(sizeof(Pnoeud));
        if (*a == NULL) {
            printf("Problème dans l'allocation mémoire.\n");
            exit(1); 
        }
        strcpy((*a)->val, v);
        (*a)->gauche = NULL;
        (*a)->droit = NULL;
    } else if (strcmp(v, (*a)->val) < 0) {
        ajouter(&((*a)->gauche), v);
    } else if (strcmp(v, (*a)->val) > 0) {
        ajouter(&((*a)->droit), v);
    } else {
        printf("Valeur déjà présente.\n");
    }
}

void supprimer(arbre *a, chaine20 v) {
    arbre *prece = (arbre*)malloc(sizeof(arbre));

    if(rechercher(*a, v)) {
        if(strcmp((*a)->val, v) == 0) {
            *prece = *a;
        } else if (strcmp(v, (*a)->val) < 0) {
            *prece = *a;
            supprimer(&((*a)->gauche), v);
        } else if (strcmp(v, (*a)->val) > 0) {
            *prece = *a;
            supprimer(&((*a)->droit), v);
        }
    } else {
        printf("Valeur pas présente dans l'abre.");
    }
}