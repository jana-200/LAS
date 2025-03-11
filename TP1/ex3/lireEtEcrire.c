#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 81

int main(int argc, char *argv[]){
    if(argc<3) exit(1);
    char buffer[BUFFER_SIZE];

    int file1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int file2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file1 == -1 || file2 == -1) exit(1);

    while(1){
        if (isatty(0)) {
            printf("Entrez une chaîne : \n"); 
        }

        int i = 0;
        char c;
        while (i<BUFFER_SIZE-1 && read(0, &c, 1) > 0) {
            buffer[i++] = c;
            if(c=='\n')break;
        }

        if(i == 0) exit(0);
        
        if(i>BUFFER_SIZE-1){ 
            printf("Erreur: la chaîne est trop longue\n");
            while (read(0, &c, 1)> 0 && c != '\n');
            continue;
        }

        
        if (!isalpha(buffer[0])){
            while (read(0, &c, 1)> 0 && c != '\n');
            continue;
        }
        
        if(isupper(buffer[0])) write(file1, buffer, i);
        else write(file2, buffer, i);
        
    }
    close(file1);
    close(file2);
    exit(0);
}

   


