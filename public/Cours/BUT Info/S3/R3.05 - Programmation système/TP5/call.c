#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <signal.h>

int main(int argc, char *argv[]) {
    int fd;
    int nbr_car = 20; 
    int nb_wr; 
    char c[21];

    // Écriture étage
    fd = open("call2lift", O_WRONLY);
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

    // Lecture de #
    fd = open("lift2call", O_RDONLY);
    if (fd == -1) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    nb_lu = read(fd, buf, nbr_car);
    if (nb_lu == -1) {
        perror("Erreur de lecture du fichier");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
