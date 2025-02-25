#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

pid_t pid;

void attrape_sigchld(int sig, siginfo_t *siginfo, void *contexte) {
    printf("Signal reçu %d, de %d, PID %d\n", sig, siginfo->si_pid, getpid());

    if(sig == SIGINT) {
        _exit(getpid());
    } else if(sig == SIGCHLD) {
        kill(siginfo->si_pid, SIGKILL);
        pid = fork();
    }
}

int main() {
    int val = 10;
    struct sigaction act;
    int loop;   

    memset (&act, '\0', sizeof(act));
    act.sa_sigaction = attrape_sigchld;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGCHLD, &act, NULL);
    sigaction(SIGINT, &act, NULL);

    printf("Avant fork(), je suis PID %d", getpid()); 
    printf(" et val = %d\n", val); 
    pid = fork(); 

    if (pid == 0) { // Fils 
        // sleep(1);
        printf("Je suis le fils, mon PID est %d et mon pere a le PID %d\n", getpid(), getppid());
        printf("Chez le fils, val = %d\n", val);
        val = 20;
    } else { // Pere 
        printf("Je suis le pere, mon PID est %d et je viens de creer un fils de PID %d\n", getpid(), pid);
        for(int i = 0; i < 300; i++){
            printf("Passage %d\n", i);
            sleep(1);
        }
        printf("Chez le père, val = %d\n", val);
        // sleep(1);
    }
    printf("Je suis PID %d et val = %d\n", getpid(), val); 
    return EXIT_SUCCESS; 
}