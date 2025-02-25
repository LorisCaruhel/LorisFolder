#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <signal.h>
#include <fcntl.h> 
#include <errno.h>


int main() {
    key_t cle;
    cle = ftok(".", 0);

    int handler = semget(cle, 1, IPC_CREAT|0640);
    int ret = semctl(handler, 0, SETVAL, 1);
}