#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 81

int main(int argc, char *argv[]){
    if(argc!=3) exit(1);
    char buffer[BUFFER_SIZE];
    ssize_t size;

    int file1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int file2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file1 == -1 || file2 == -1) exit(1);

    while(1){
        printf("Entrez une chaîne : \n");
        size = read(0, buffer, 80);
        if (size == -1) exit(1);
        if (size == 0) exit(0);

        if(buffer[size-1]!='\n'){
            printf("chaine trop longue, vous devez avoir maximum 80 caractères \n");
                char tmp;
                while (read(0, &tmp, 1)> 0 && tmp != '\n');
                continue;
        }
        if (!isalpha(buffer[0])){
            char tmp;
                while (read(0, &tmp, 1)> 0 && tmp != '\n');
                continue;
        }

        
        if(isupper(buffer[0])){
            write(file1, buffer, size);
        }
        else write(file2, buffer, size);
    }
    close(file1);
    close(file2);
    exit(0);
}

   


