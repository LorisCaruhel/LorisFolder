#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 

int main() {
    int fd;
    char buf[21]; 
    int nbr_car = 20; 
    int nb_lu; 
    char etage[5];

    printf("On va à l'étage ?\n");
    scanf("%s", etage);
    while(strcmp(etage, '*') != 0) {
        // Lecture de l'étage
        fd = open("call2lift", O_RDONLY);
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
        printf("On va à l'étage : %s\n", buf);

        // Écriture de #
        fd = open("lift2call", O_WRONLY);
        if (fd == -1) {
            perror("Erreur d'ouverture du fichier");
            return 1;
        }
        sleep(1);

        nb_wr = write(fd, '#', strlen('#'));
        if (nb_wr == 0) {
            perror("Erreur d'écriture du fichier");
            close(fd);
            return 1;
        }

        printf("On va à l'étage ?\n");
        scranf("%s", etage);
    }
    close(fd);

    return 0;
}
