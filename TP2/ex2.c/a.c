#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "../utils_v1.h" 
#define MAX 20
int main(){
    write(1,"Entrez un nom de ficher (20 caract max) : ", 41);
    char file[MAX+1];
    ssize_t n;
    n = read(0, &file, MAX+1);
    if(n == -1){
        exit(1);
    }
    if (file[n - 1] == '\n') {
        file[n - 1] = '\0';
    }
    int file1 = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0700);
    if(file1 == -1){
        exit(1);
    }
    pid_t pid = fork();

    if (pid == -1) {
        exit(1);
    }

    if (pid == 0) {
        execlp("ls", "ls", "-l", file, (char *)NULL);
        exit(1);
    } else {
        wait(NULL);
    }

    const char *content = "#!/bin/bash\n";
    write(file1, content, strlen(content));
    write(1, "Entrez le contenu du script (ligne vide pour terminer) :\n", 57);
    char buffer[240];
    while(n >1 ){
        n = read(0, buffer, 240);
        write(file1, buffer, n);
    }

    write(1, "Voici le contenu du fichier : \n\n", 32);
    pid_t pid2 = fork();

    if (pid2 == 0) {
        execlp("cat", "cat", file, (char *)NULL);
        exit(1);
    } else {
        wait(NULL);
    }

    close(file1);

    write(1, "Exécution du fichier : \n\n", 26);
    pid_t pid3 = fork();
    if (pid3 == 0) {
        execl(file, file, (char *)NULL); 
        exit(1);
    } else {
        wait(NULL);
    }

    return 0;

}