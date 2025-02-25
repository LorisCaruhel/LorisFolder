#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid_chrono; // PID du processus chrono
    int choix;

    // Demander à l'utilisateur d'entrer le PID du processus chrono
    printf("Entrez le PID du processus chrono: ");
    scanf("%d", &pid_chrono);

    // Vérification du PID
    if (pid_chrono <= 0) {
        fprintf(stderr, "PID invalide.\n");
        return 1;
    }

    // Menu principal en boucle
    while (1) {
        // Affichage du menu
        printf("\nMenu:\n");
        printf("1) Départ\n");
        printf("2) Signaler un passage\n");
        printf("3) Quitter la course\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Envoi du signal SIGUSR1 pour démarrer
                if (kill(pid_chrono, SIGUSR1) == -1) {
                    perror("Erreur lors de l'envoi du signal SIGUSR1");
                } else {
                    printf("Signal SIGUSR1 envoyé au processus chrono (PID: %d)\n", pid_chrono);
                }
                break;

            case 2:
                // Envoi du signal SIGUSR2 pour signaler un passage
                if (kill(pid_chrono, SIGUSR2) == -1) {
                    perror("Erreur lors de l'envoi du signal SIGUSR2");
                } else {
                    printf("Signal SIGUSR2 envoyé au processus chrono (PID: %d)\n", pid_chrono);
                }
                break;

            case 3:
                // Quitter le programme
                printf("Quitter la course.\n");
                exit(0);

            default:
                printf("Choix invalide. Veuillez choisir entre 1 et 3.\n");
                break;
        }
    }

    return 0;
}
