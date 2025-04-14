#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){ 
    char chaine1[]= "trois .. deux .. un .. " ;
    printf(chaine1);
    fflush(stdout);
    // ici pas besoin de \n car on vide le buffer grace à fflush(stdout);

    pid_t childID = fork();

    if(childID==0){
        char chaine2[]= "partez !\n" ;
        printf(chaine2);
    }

    exit(0);
}

//en gros ,write n'utilise pas de buffer, il affiche asimplement
//alors que printf utilise un buffer qui se vide si on fait \n