#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buffer[11];   
    ssize_t size;      

    while (1) {
        printf("Entrez une chaîne : \n");
        // On lit 10 caract
        size = read(0, buffer, 10);
    
        //si Ctrl-D on break
        if (size == 0 ) break;

        // traitement 1
        //if(buffer[nbytes-1] != '\n') exit(0);

        //traitement 2
        if(buffer[size-1] != '\n'){
            printf("chaine trop longue, essayez avec une plus petite chaine \n");
            // pr vider le reste du buffer
            char tmp;
            while (read(0, &tmp, 1)> 0 && tmp != '\n');
            //on repart au début du while
            continue;
        }

        printf("Le mot lu est : \n");
        write(1, buffer, size);
    }

    exit(0);

}
