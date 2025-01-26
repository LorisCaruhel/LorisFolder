#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int val = 10;

    printf("Avant fork(), je suis PID %d", getpid());
    printf(" et val = %d\n", val);

    pid = fork();

    if (pid == -1) { // Erreur lors du fork
        perror("Erreur lors de la création du processus");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Processus fils
        printf("Je suis le fils, mon PID est %d et mon père a le PID %d\n", getpid(), getppid());
        printf("Chez le fils, val = %d\n", val);
        val = 20; // Modification de la valeur dans le processus fils
    } else { // Processus parent
        printf("Je suis le père, mon PID est %d et je viens de créer un fils de PID %d\n", getpid(), pid);
        printf("Chez le père, val = %d\n", val);

        // Ajout de wait() pour attendre la fin du processus fils
        printf("Le père attend la fin de son fils...\n");
        if (wait(NULL) == -1) { // Attente de la fin d'un processus enfant
            perror("Erreur lors de l'attente du processus fils");
            exit(EXIT_FAILURE);
        }
        printf("Le fils est terminé, le père continue...\n");
    }

    printf("Je suis PID %d et val = %d\n", getpid(), val);
    return EXIT_SUCCESS;
}