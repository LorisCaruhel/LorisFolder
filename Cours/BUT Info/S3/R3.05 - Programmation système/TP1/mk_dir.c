#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int ret;
    ret = mkdir("D1", 0777);
    if (ret == -1) { 
        if (errno == EEXIST) { 
            printf("D1 existe déjà !\n");
        } else { 
            perror("Erreur inconnue"); 
        }
        return EXIT_FAILURE;
    } else { 
        printf("D1 créer\n");
    }
    return EXIT_SUCCESS;
}