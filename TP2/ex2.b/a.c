#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../utils_v1.h" 

void afficher_enfant(){
    char strEnfant[]="4 5 6\n";
    write(1,strEnfant,strlen(strEnfant));
}
 
int main(){ 
    int szPar;
    char strParent[]="1 2 3\n";
    
    fork_and_run0(afficher_enfant);
        
    szPar=strlen(strParent);
    write(1,strParent,szPar);

    exit(0);

}