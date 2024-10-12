#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void attrape_sig(int sig, siginfo_t *siginfo, void *contexte) {
    printf("Signal reçu %d, de %d, PID %d\n", sig, siginfo->si_pid, getpid());
}

int main(int argc, char* argv[]) {
    struct sigaction act;
    int loop;

    memset (&act, '\0', sizeof(act));
    act.sa_sigaction = attrape_sig;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGTSTP, &act, NULL);

    for (loop = 0; loop < 600; loop++) {
        printf("PID %d - UID %d - Passage %d\n", getpid(), getuid(), loop);
        sleep(5);
    }
    return 0;
}