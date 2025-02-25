#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>

int main() {
    key_t cle;
    cle = ftok(".", 0);

    int handler;
    handler = semget(cle, 1, IPC_CREAT | 0640);

    int ret;
    struct sembuf arr_sop[2];

    arr_sop[0].sem_num = 0;
    arr_sop[0].sem_op = -1; // On consomme une qté de 1 sur sémaphore 0
    arr_sop[0].sem_flg = 0;

    arr_sop[1].sem_num = 1;
    arr_sop[1].sem_op = -2; // On consomme une qté de 2 sur sémaphore 1
    arr_sop[1].sem_flg = 0;

    ret = semop(handler, arr_sop, 2);

    printf("%x\n", ret);
}