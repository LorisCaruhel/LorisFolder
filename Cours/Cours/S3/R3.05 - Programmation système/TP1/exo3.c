#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFSIZE 512 

int main(int argc, char *argv[]) {
    int unL = unlink("ORIG.txt");

    if(unL == -1) {
        perror("Erreur sur la suppression");
        exit(-1);
    }

    return 0;
}