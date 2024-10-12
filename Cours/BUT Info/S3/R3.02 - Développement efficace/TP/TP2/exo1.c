#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine20[21];

typedef struct {
    chaine20 nom;
    int age;
}t_personne;

typedef struct elem{
    t_personne p;
    struct elem* svt;
}t_elem;

typedef t_elem* t_liste;

const char STOP[] = "-1";

void init_liste(t_liste* l);
void ajouterPersonneTete (t_liste* l, t_personne p);
void afficherPersonne(t_personne p);
void afficherListe(t_liste l);
t_elem* rechercher(t_liste l, char n[]);
void supprimerTete(t_liste* l);
int nombrePersonne(t_liste l, char n[]);
t_elem* trouverIElement(t_liste l, int k);
void ajouterFinListe(t_liste* l, char n[], int age);
void ajouterKListe(t_liste* l, int k, char n[], int age);

int main() {
    t_liste listeP;

    init_liste(&listeP);
    
    t_personne p1;
    printf("Entrez un nom : ");
    scanf("%s", p1.nom);

    while(strcmp(p1.nom, STOP) != 0) {
        printf("Entrez un âge : ");
        scanf("%d", &(p1.age));

        ajouterPersonneTete(&listeP, p1);

        printf("Entrez un nom : ");
        scanf("%s", p1.nom);
    }

    ajouterKListe(&listeP, 2, "test", 18);
    afficherListe(listeP);

    return 0;
}

void init_liste(t_liste* l) {
    *l = NULL;
}

void ajouterKListe(t_liste* l, int k, char n[], int age) { 
    t_elem* courant = trouverIElement(*l, k);

    if (courant==NULL) {
        printf("pas de place %d\n",k);
    }else{
        t_personne* nouvellePersonne = (t_personne*)malloc(sizeof(t_personne));
        strcpy(nouvellePersonne->nom, n); 
        nouvellePersonne->age = age;       

        t_elem* nouvelElement = (t_elem*)malloc(sizeof(t_elem));
        nouvelElement->p = *nouvellePersonne;
        nouvelElement->svt = courant->svt;
        courant->svt = nouvelElement;
    }
}

void ajouterFinListe(t_liste* l, char n[], int age) {
    t_personne* nouvellePersonne = (t_personne*)malloc(sizeof(t_personne));
    strcpy(nouvellePersonne->nom, n); 
    nouvellePersonne->age = age;       

    t_elem* nouvelElement = (t_elem*)malloc(sizeof(t_elem));
    nouvelElement->p = *nouvellePersonne;
    nouvelElement->svt = NULL;           

    if (*l == NULL) {
        *l = nouvelElement;
    } else {
        t_elem* courant = *l;
        while (courant->svt != NULL) {
            courant = courant->svt;
        }
        
        courant->svt = nouvelElement;
    }
}

t_elem* trouverIElement(t_liste l, int k) {
    int i = 0;

    t_elem* courant = (t_elem*)malloc(sizeof(t_elem));
    courant = l;

    while((courant != NULL) && (i != k)) {
        i++;
        courant = courant->svt;
    }

    if(courant == NULL) {
        return NULL;
    }else {
        return courant;
    }
}

void ajouterPersonneTete(t_liste* l, t_personne p) {
    t_elem* nouvel_elem = (t_elem*)malloc(sizeof(t_elem));
    nouvel_elem->p = p;
    nouvel_elem->svt = NULL;

    if(*l == NULL) {
        *l = nouvel_elem;
    } else {
        nouvel_elem->svt = *l;
        *l = nouvel_elem;
    }
    printf("%s", "Personne ajouté !\n");
}

t_elem* rechercher(t_liste l, char n[]) {
    t_elem* courant = (t_elem*)malloc(sizeof(t_elem));
    courant = l;

    while((courant != NULL) && strcmp(courant->p.nom, n)) {
        courant = courant->svt;
    }

    if(courant == NULL) {  
        printf("%s", "Pas trouvé\n");
        return NULL;
    }else {
        printf("%s", "Trouvé\n");
        return courant;
    }
}

int nombrePersonne(t_liste l, char n[]) {
    int i = 0;

    t_elem* courant = (t_elem*)malloc(sizeof(t_elem));
    courant = l;

    while((courant != NULL)) {
        if(strcmp(courant->p.nom, n)) {
            i++;
        }
        courant = courant->svt;
    }
    return i;
}

void supprimerTete(t_liste* l) {
    if(*l != NULL) {
        *l = (*l)->svt;
    }
    printf("%s", "Tête supprimé !\n");
}

void afficherPersonne(t_personne p) {
    printf("Nom: %s, Age: %d\n", p.nom, p.age);
}

void afficherListe(t_liste l) {
    t_elem* currentE = l;  

    while (currentE != NULL) {  
        afficherPersonne(currentE->p);  
        currentE = currentE->svt;
    }
}