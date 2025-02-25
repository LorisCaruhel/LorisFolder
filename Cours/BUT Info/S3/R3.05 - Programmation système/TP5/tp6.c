#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <signal.h>

pid_t pid;

int main(int argc, char *argv[]) {
    char buf[21]; 
    int nbr_car = 1; 
    int nb_lu, nb_w; 
    int fd[2];
    int compteurFils = 1, compteurPere = 0;
    int ret = pipe(fd);

    pid = fork();
    if (pid == 0) {
        close(fd[1]);

        while(1) {
            nb_lu = read(fd[0], buf, nbr_car);
            if(strcmp(buf, "*") == 0) {
                printf("Fils : %d\n", compteurFils);
                compteurFils += 2;
            }
        }
    } else {
        close(fd[0]);

        while(1) {
            printf("Père : %d\n", compteurPere);
            compteurPere += 2;
            nb_w = write(fd[1], "*", sizeof("*")-1);
            sleep(1);
        }
    }

    return 0;
}
