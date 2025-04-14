#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){ 
    int a=5;
    pid_t childID = fork();

    if(childID==0){ 
        int b=a*2;
        printf("ID Enfant : %d \n", childID);
        printf("Enfant : a = %d, b = %d \n", a,b);
    }else{ 
        int b=a*5;
        printf("ID parent : %d \n", childID);
        printf("Parent : a = %d, b = %d \n", a,b);
    }

    exit(0);

}