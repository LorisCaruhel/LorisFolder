#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void attrape_sig(int sig, siginfo_t *siginfo, void *contexte) {
    static int i = 0;

    printf("%d", sig);
    if(sig == SIGINT) {
        if(i > 4) {
            exit(1);
        }
        printf("Reçu un Ctrl+C.\nPour arrêter le programme il faut taper 5 fois Ctrl+C.\nIl manque encore %d\n", 5-i);
        i++;
    } else if (sig == SIGTSTP) {
        printf("Reçu un Ctrl+Z.\nRemise à zéro du compteur des Ctrl+C.\n");
        i = 0;
    }

}

int main(int argc, char* argv[]) {
    struct sigaction act;
    int loop;

    memset (&act, '\0', sizeof(act));
    act.sa_sigaction = attrape_sig;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGTSTP, &act, NULL);

    for (loop = 0; loop < 600; loop++) {
        printf("PID %d - UID %d - Passage %d\n", getpid(), getuid(), loop);
        sleep(1);
    }
    return 0;
}