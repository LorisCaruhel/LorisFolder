#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFSIZE 512 

int main(int argc, char *argv[]) {
    struct stat sb;
    int st = stat("ORIG.txt", &sb);

    printf("I-node number: %ld\n", sb.st_ino);
    printf("Droit du ficher: %o\n", sb.st_mode);
    printf("UID number: %d\n", sb.st_uid);
    printf("GID number: %d\n", sb.st_gid);
    printf("Size of file: %ld\n", sb.st_size);


    return 0;
}