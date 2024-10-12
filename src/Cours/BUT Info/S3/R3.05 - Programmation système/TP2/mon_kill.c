#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int PID, testPID;
    
    if(argc == 2) {
        PID = atoi(argv[1]);
        testPID = kill(PID, 0);

        if(testPID != -1) {
            kill(PID, SIGKILL);
        }else {
            perror("Problème sur kill");
        }
    }else {
        printf("Syntaxe: %s <PID>\n", argv[0]);
        exit(1);
    }
}