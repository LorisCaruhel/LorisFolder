#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 

int main() {
    int fd;

    fd = open("mon_tube", O_RDONLY);
    close(fd);

    return 0;
}
