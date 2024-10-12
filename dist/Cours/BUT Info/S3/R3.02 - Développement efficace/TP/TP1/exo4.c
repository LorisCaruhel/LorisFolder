#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine20[21];

typedef struct {
    chaine20 nom;
    int population;
    int superficie;
} t_capitale;

typedef struct {
    chaine20 nom;
    t_capitale* capitale;
} t_pays;

void init_pays(t_pays* t);
void afficher_pays(t_pays t);

int main() {
    t_pays* pt_pays;
    pt_pays = (t_pays*)malloc(sizeof(t_pays));
    pt_pays->capitale = (t_capitale*)malloc(sizeof(t_capitale));

    init_pays(pt_pays);
    afficher_pays(*pt_pays);

    return 0;
}

void init_pays(t_pays* t) {
    strcpy(t->nom, "pas de pays");
    strcpy(t->capitale->nom, "pas de capitale");
    t->capitale->population = -1;
    t->capitale->superficie = -1;
}

void afficher_pays(t_pays t) {
    printf("Nom du pays : %s\n", t.nom);
    printf("Nom de la capitale : %s\n", t.capitale->nom);
    printf("Population : %d\n", t.capitale->population);
    printf("Superficie : %d\n", t.capitale->superficie);
}