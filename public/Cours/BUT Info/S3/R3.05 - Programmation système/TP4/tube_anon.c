#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <string.h> 

pid_t pid;

int main(int argc, char *argv[]) {
    int fd[2];
    int ret;
    char buf[21]; 
    int nbr_car = 20; 
    int nb_lu, nb_wr; 
    char c[21];

    ret = pipe(fd);
    if(ret == -1) {
        perror("Error sur l'ouverture d'un pipe");
    }
    pid = fork(); 

    if (pid == 0) { // Fils 
        close(fd[1]);

        nb_lu = read(fd[0], buf, nbr_car);
        if (nb_lu == -1) {
            perror("Erreur de lecture du fichier");
            close(fd[0]);
            return 1;
        }
        printf("%s\n", buf);
    } else { // Pere 
        close(fd[0]);

        nb_wr = write(fd[1], argv[1], strlen(argv[1]));
        if (nb_wr == 0) {
            perror("Erreur d'écriture du fichier");
            close(fd[1]);
            return 1;
        }
    }

    close(fd[0]);
    close(fd[1]);

    return 0;
}
