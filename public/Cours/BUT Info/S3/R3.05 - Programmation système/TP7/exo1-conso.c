#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <signal.h>
#include <fcntl.h> 
#include <errno.h>


int main() {
    key_t key;
    int semid;

    // Génération de la clé unique
    if ((key = ftok(".", 0)) == -1) {
        perror("ftok");
        exit(1);
    }

    // Ouverture du sémaphore existant
    if ((semid = semget(key, 1, 0640)) == -1) {
        perror("semget");
        exit(1);
    }

    struct sembuf sops; // Structure pour définir les opérations sur le sémaphore

    while (1) {
        printf("Avant conso\n");

        // Consommer une quantité de 1 sur le sémaphore
        sops.sem_num = 0;  // Numéro du sémaphore (dans notre cas, il n'y en a qu'un)
        sops.sem_op = -1;  // Décrémenter de 1
        sops.sem_flg = 0;  // Opération bloquante

        if (semop(semid, &sops, 1) == -1) {
            perror("semop (consommation)");
            exit(1);
        }
        printf("Après conso\n");

        printf("Prêt à libérer ? ");
        getchar();  // Attente d'une entrée clavier

        printf("Avant libération\n");

        // Libérer une quantité de 1 sur le sémaphore
        sops.sem_op = 1;  // Incrémenter de 1

        if (semop(semid, &sops, 1) == -1) {
            perror("semop (libération)");
            exit(1);
        }
        printf("Après libération\n");
    }

    return 0;
}