#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){ 
    int sz;
    char chaine1[]= "trois .. deux .. un ..\n" ;
    sz=strlen(chaine1);
    write(1,chaine1,sz);

    pid_t childID = fork();

    if(childID==0){
        char chaine2[]= "partez !\n" ;
        sz=strlen(chaine2);
        write(1,chaine2,sz);
    }
    // ici le \n en change rien à part faire des sauts à la ligne
    // car le write ne met pas la chaine dans un buffer il l'écrit directement
    exit(0);
}