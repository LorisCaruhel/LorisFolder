#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void attrape_sig(int sig, siginfo_t *siginfo, void *contexte) {
    printf("Reçu SIGUSR1\n");
}

int main(int argc, char* argv[]) {
    unsigned int temps = 60;
    struct sigaction act;

    memset (&act, '\0', sizeof(act));
    act.sa_sigaction = attrape_sig;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);

    printf("PID %d - UID %d\n", getpid(), getuid());

    while (temps > 0) {
        temps = sleep(temps);
    }
    exit(0);

    return 0;
}