#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

struct Coureur {
    pid_t pid;
    int nbTour;
    time_t debut;
    time_t fin;
};
typedef struct Coureur listeCoureur[50];

listeCoureur l1;

void newCoureur(int sig, siginfo_t *siginfo, void *contexte) {
    bool dejaPresent = false;
    int i = 0;

    while (!dejaPresent && i < 50) {
        if (l1[i].pid == siginfo->si_pid) {
            dejaPresent = true;
        }
        i++;
    }

    if (!dejaPresent) {
        struct Coureur c;
        c.pid = siginfo->si_pid;
        c.debut = time(NULL);
        c.nbTour = 0;
        l1[i - 1] = c;
        printf("Coureur ajouté: PID %d\n", siginfo->si_pid);
    }
}

void newTour(int sig, siginfo_t *siginfo, void *contexte) {
    bool dejaPresent = false;
    int i = 0;

    while (i < 50 && !dejaPresent) {
        if (l1[i].pid == siginfo->si_pid) {
            dejaPresent = true;
        }
        i++;
    }

    if (dejaPresent) {
        l1[i - 1].nbTour += 1;
        l1[i - 1].fin = time(NULL);

        int temps = (int)(l1[i - 1].fin - l1[i - 1].debut);

        printf("Coureur PID: %d | Tour n°%d | Temps : %d secondes\n", siginfo->si_pid, l1[i - 1].nbTour, temps);
    }
}

void end(int sig, siginfo_t *siginfo, void *contexte) {
    printf("Course terminée, récapitulatif des coureurs :\n");
    for (int i = 0; i < 50; i++) {
        if (l1[i].pid != 0) {
            printf("Numéro : %d | Nombre de tours : %d\n", l1[i].pid, l1[i].nbTour);
        }
    }
    exit(0); 
}

int main() {
    struct sigaction sa_newCoureur;
    memset(&sa_newCoureur, '\0', sizeof(sa_newCoureur));
    sa_newCoureur.sa_sigaction = newCoureur;
    sa_newCoureur.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa_newCoureur, NULL);

    struct sigaction sa_newTour;
    memset(&sa_newTour, '\0', sizeof(sa_newTour));
    sa_newTour.sa_sigaction = newTour;
    sa_newTour.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa_newTour, NULL);

    struct sigaction sa_end;
    memset(&sa_end, '\0', sizeof(sa_end));
    sa_end.sa_sigaction = end;
    sa_end.sa_flags = SA_SIGINFO;
    sigaction(SIGTERM, &sa_end, NULL);

    while (1) {
        printf("En attente d'un coureur...\n");
        sleep(1); 
    }

    return EXIT_SUCCESS;
}
