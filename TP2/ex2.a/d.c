#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){ 
    char chaine1[]= "trois .. deux .. un ..\n" ;
    printf(chaine1);

    pid_t childID = fork();

    if(childID==0){
        char chaine2[]= "partez !\n" ;
        printf(chaine2);
    }

    // si on met pas le \n, chaine1 s'affiche 2 fois et si on le met il ne s'affiche qu'une fois
    // le printf mets d'abord le chaine dans un buffer, le buffer est vidé si y'a \n
    // en gros on a un buffer stdout dans le quel on stock tout ce qui doit être affiché et là comme on créer un fils aprés, il hérite le buffer de son pére donc on affiche encore ce qu'il y'a dedans

    exit(0);
}