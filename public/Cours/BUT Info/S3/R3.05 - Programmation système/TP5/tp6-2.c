#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <signal.h>
#include <math.h>
#include <stdbool.h>

pid_t pid;

bool fini; // globale
void do_job_pere() {
    double pi, res;
    long loop;
    pi = 0;
    fini = false;
    loop = 1;

    while (!fini && loop <= 20) {
        pi = pi + 1.0/(double)pow(loop, 2);
        loop++;
    }

    res = sqrt(pi * 6);
    printf("PI = %.18f (précision : %e) en %ld itérations\n", res, (res - 3.141592653589793238462643383279502884197), loop);
}

void do_job_fils() {
    double pi, res;
    long loop;
    pi = 0;
    loop = 1;

    while (!fini && loop <= 20) {
        pi = pi + 1.0 / (double)pow(loop, 4);
        loop++;
    }

    res = pow(pi * 90, 0.25);
    printf("PI = %.18f (précision : %e) en %ld itérations\n", res, (res - 3.141592653589793238462643383279502884197), loop);
}

int main(int argc, char *argv[]) {
    char buf[21]; 
    int nbr_car = 1; 
    int nb_lu, nb_w; 
    int fd[2];
    int compteurFils = 1, compteurPere = 0;
    int ret = pipe(fd);

    struct sigaction act;
    memset(&act, '\0', sizeof(act));

    pid = fork();
    if (pid == 0) {   
        close(fd[1]);

        act.sa_sigaction = do_job_fils;
        act.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &act, NULL);

        while(1) {
            nb_lu = read(fd[0], buf, nbr_car);
            if(strcmp(buf, "*") == 0) {
                printf("Fils : %d\n", compteurFils);
                compteurFils += 2;
            }
        }
    } else {
        close(fd[0]);

        act.sa_sigaction = do_job_pere;
        act.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &act, NULL);

        while(1) {
            printf("Père : %d\n", compteurPere);
            compteurPere += 2;
            nb_w = write(fd[1], "*", sizeof("*")-1);
            sleep(1);
        }
    }

    return 0;
}
