#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE_TAB 10

typedef struct elem {
    int val;
    struct elem* svt;
}telement;

typedef telement *ensemble;
typedef int tab10[TAILLE_TAB];

void initialiserElement(ensemble* l);
bool appartientAElement(ensemble l, int n);
void ajouterAElement(ensemble* l, int a);
void afficherElement(telement e);
int cardinal(ensemble l);


int main() {
    telement e;

    initialiserElement(&e);
    afficherElement(e);

    return 0;
}


void initialiserElement(ensemble* l) {
    *l = NULL;
}

bool appartientAElement(ensemble l, int n) {
    int res = 0;
    telement* t = l;

    while((l != NULL) && (res == 0)) {
        if((l->val) == n) {
            res = 1;
        }
        l = l->svt;
    }
}

void ajouterAElement(ensemble* l, int a) {
    if(appartientAelement(*l, a) == 0) {
        telement *e = (telement*)malloc(sizeof(telement));
        e->val = a;
        e->svt = *l;
        *l = e;
    }
}

void afficherElement(telement e) {
    while (e.svt != NULL) {
        printf("%d", e.val);
        afficherelement(e.svt);
    }
}

int cardinal(ensemble l) {
    int res = 0;
    telement* parcours = l;

    while(parcours != NULL) {
        res++;
        parcours = parcours->svt;
    }

    return res;
}

void ajouter_tab(ensemble* l, tab10 tab) {
    for(int i = 0; i < TAILLE_TAB; i++){
        ajouter(l, tab[i]);
    }
}

void union_ens(ensemble l1, ensemble l2, ensemble* res) {
    telement* parcours;
    initialiserElement(res);
    parcours = l1;

    while(parcours != NULL) {
        ajouter(res, parcours->val);
        parcours = parcours->svt;
    }

    parcours = l2;
    while(parcours != NULL) {
        ajouter(res, parcours->svt);
        parcours = parcours->svt;
    }
}

void inter_ens(ensemble l1, ensemble l2, ensemble* res) {
    telement* parcours;
    initialiserElement(res);
    parcours = l1;

    while(parcours != NULL) {
        if(appartientAElement(l2, parcours->val) != 0) {
            ajouter(res, parcours->val);
        }
        parcours = parcours->svt;
    }
}