#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../utils_v2.h"

void handler (int sig) {
    char message[]="signal SIGUSR1 reçu !\n";
    write(1, message, strlen(message)); 
}
int main(){ 
    int nbrSignaux = 0; 
    struct sigaction action = {0};
    action.sa_handler = handler;
    int ret = sigaction(SIGUSR1, &action, NULL);
    checkNeg(ret, "erreur sigaction 1");
    
    pid_t pid = sfork();

    if (pid == 0) {
       
        while (1) {
            sleep(1); 
        }
    } else {
        printf("Père terminé, pid=%d, fils=%d\n", getpid(), pid);
        while(1){ 
            kill(pid, SIGUSR1);
            nbrSignaux++;
        }
        wait(NULL);
        printf("Nombre de signaux envoyés : %d\n", nbrSignaux);
        exit(0);
    }

    return 0;
}