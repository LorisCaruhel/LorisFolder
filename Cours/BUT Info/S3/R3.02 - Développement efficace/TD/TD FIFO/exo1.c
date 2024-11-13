#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[50];
    int age;
} tpersonne;

typedef struct elem {
    tpersonne pers;
    struct elem* svt;
} telement;

typedef struct {
    telement* queue;
    telement* tete;
} tfile;

typedef struct elem2{
    tfile urgent;
    tfile important;
    tfile standard;
}tfilePrio;

void initFile(tfile* f);
int estVide(tfile f);
tpersonne teteFile(tfile f);
void ajoutDansFile(tfile* f, tpersonne p);
void suppersionTeteFile(tfile* f);
void afficherFile(tfile f);

void initPrio(tfilePrio* fp);
void ajoutePrio(tfilePrio *fp, tpersonne p, int priorite);
void suppressionPrio(tfilePrio* fp);
void afficherPrio(tfilePrio fp);

int main() {
    //////////// Q1 ////////////
    // tfile f;

    tpersonne p;
    strcpy(p.nom, "Loris");
    p.age = 18;

    tpersonne p2;
    strcpy(p2.nom, "Mega chevalier");
    p2.age = 30;

    // initFile(&f);
    // printf("Est vide: %d\n", estVide(f));

    // ajoutDansFile(&f, p);
    // afficherFile(f);

    // suppersionTeteFile(&f);
    // afficherFile(f);


    //////////// Q2 ////////////
    tfilePrio fp;

    initPrio(&fp);
    ajoutePrio(&fp, p, 1);
    ajoutePrio(&fp, p, 2);
    ajoutePrio(&fp, p, 3);
    ajoutePrio(&fp, p2, 1);
    ajoutePrio(&fp, p2, 2);
    ajoutePrio(&fp, p2, 3);
    afficherPrio(fp);
    printf("%s", "\n");
    suppressionPrio(&fp);
    suppressionPrio(&fp);
    suppressionPrio(&fp);
    printf("%s", "\n");
    afficherPrio(fp);

    return 0;
}

void afficherPrio(tfilePrio fp) {
    if (!estVide(fp.urgent)) {
        printf("Personnes urgentes : \n");
        afficherFile(fp.urgent);
    } else {
        printf("Aucune personne urgente.\n");
    }

    if (!estVide(fp.important)) {
        printf("Personnes importantes : \n");
        afficherFile(fp.important);
    } else {
        printf("Aucune personne importante.\n");
    }

    if (!estVide(fp.standard)) {
        printf("Personnes standards : \n");
        afficherFile(fp.standard);
    } else {
        printf("Aucune personne standard.\n\n");
    }
}

void ajoutePrio(tfilePrio* fp, tpersonne p, int priorite) {
    if(priorite == 1) {
        ajoutDansFile(&(fp->urgent), p);
        printf("%s", "Ajout d'une personne urgente.\n");
    }else if(priorite == 2) {
        ajoutDansFile(&(fp->important), p);
        printf("%s", "Ajout d'une personne importante.\n");
    }else if(priorite == 3) {
        ajoutDansFile(&(fp->standard), p);
        printf("%s", "Ajout d'une personne standard.\n");
    }else {
        printf("%s", "Priorité non valide.\n\n");
    }
}

void initPrio(tfilePrio* fp) {
    initFile(&(fp->urgent));
    initFile(&(fp->important));
    initFile(&(fp->standard));
}
 
void initFile(tfile* f) {
    f->queue = NULL;
    f->tete = NULL;
}

int estVide(tfile f) {
    if(f.tete == NULL && f.queue == NULL) {
        return 1;
    }
    return 0;
}

void afficherFile(tfile f) {
    telement* current = f.tete;

    if(estVide(f)) {
        printf("%s", "File vide\n\n");
    } else {
        printf("File :\n");
        while (current != NULL) {
            printf("Nom personne : %s\n", current->pers.nom);
            printf("Age personne : %d\n\n", current->pers.age);
            current = current->svt; 
        }
    }
}

tpersonne teteFile(tfile f) {
    return f.tete->pers;
}

void ajoutDansFile(tfile* f, tpersonne p) {
    telement* e = (telement*)malloc(sizeof(telement));
    e->pers = p;
    e->svt = NULL;

    if (f->tete == NULL) {
        f->tete = e;
        f->queue = e;
    } else {
        f->queue->svt = e;
        f->queue = e;
    }
}

void suppressionPrio(tfilePrio* fp) {
    if(!estVide(fp->urgent)) {
        printf("%s", "Personne urgentes passée.\n");
        suppersionTeteFile(&(fp->urgent));
    } else if (!estVide(fp->important)) {
        printf("%s", "Personne important passée.\n");
        suppersionTeteFile(&(fp->important));
    } else if (!estVide(fp->standard)) {
        printf("%s", "Personne standard passée.\n");
        suppersionTeteFile(&(fp->standard));
    } else {
        printf("%s", "Aucune personne dans les files.\n");        
    }
}

void suppersionTeteFile(tfile* f) {
    telement *p;

    if (f->tete==f->queue){
        p=f->tete;
        f->tete=NULL;
        f->queue=NULL;
        free(p);
    }else{
        p=f->tete;
        f->tete=f->tete->svt;
        free(p);
    }
}
