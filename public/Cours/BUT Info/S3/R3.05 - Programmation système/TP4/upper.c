#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 

int main() {
    int fd;
    char buf[21]; 
    int nbr_car = 20; 
    int nb_lu; 
    char c[21];

    fd = open("mon_tube", O_RDONLY);
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

    for (int i = 0; i < nb_lu; i++) {
        if (buf[i] >= 'a' && buf[i] <= 'z') {
            c[i] = buf[i] - 'a' + 'A'; 
        } else {
            c[i] = buf[i];
        }
    }

    c[nb_lu] = '\0';

    printf("Valeur lue : %s\n", c);

    close(fd);

    return 0;
}
