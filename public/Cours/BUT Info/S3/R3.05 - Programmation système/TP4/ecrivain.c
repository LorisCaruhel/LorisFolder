#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <signal.h>

void attrape_sig(int sig, siginfo_t *siginfo, void *contexte) {
    printf("Error : Reçu SIGPIPE\n");
}

int main(int argc, char *argv[]) {
    int fd;
    int nbr_car = 20; 
    int nb_wr; 
    char c[21];

    // Attrappé le SIGPIPE
    struct sigaction act;

    memset(&act, '\0', sizeof(act));
    act.sa_sigaction = attrape_sig;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGPIPE, &act, NULL);

    fd = open("mon_tube", O_WRONLY);
    if (fd == -1) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }
    sleep(1);

    nb_wr = write(fd, argv[1], strlen(argv[1]));
    if (nb_wr == 0) {
        perror("Erreur d'écriture du fichier");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
