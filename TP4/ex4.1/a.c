#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../utils_v2.h"

int main(){ 
    pid_t pid = sfork();

    if (pid == 0) {
        while (1) {
            sleep(1); 
        }
    } else {
        printf("Père terminé, pid=%d, fils=%d\n", getpid(), pid);
        exit(0);  
    }

    return 0;
}