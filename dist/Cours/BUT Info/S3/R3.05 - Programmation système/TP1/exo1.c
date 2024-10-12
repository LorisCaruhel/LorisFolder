#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFSIZE 512 

int main(int argc, char *argv[]) {
    char buf[BUFSIZE];
    int ouvertureORIG, ouvertureOLD, lecture, ecriture;

    ouvertureOLD = open("OLD.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if (ouvertureOLD == -1) {
        perror("Pb ouverture OLD");
        exit(-1);
    }
    ouvertureORIG = open("ORIG.txt", O_RDONLY, 0644);
    if (ouvertureORIG == -1) {
        perror("Pb ouverture ORIG");
        exit(-1);
    }

    lecture = read(ouvertureORIG, buf, BUFSIZE);
    while (lecture != 0) {
        if(lecture == -1) {
            perror("Erreur sur la lecture du fichier.");
            exit(-1);
        }

        ecriture = write(ouvertureOLD, buf, lecture);
        if (ecriture == -1) {
            perror("Erreur sur l'ecriture du fichier.");
            exit(-1);
        }

        lecture = read(ouvertureORIG, buf, BUFSIZE);
    }

    close(ouvertureOLD);
    close(ouvertureORIG);

    return 0;
}