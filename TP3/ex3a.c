#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 30
int main(){ 
    int filedes[2];
    pipe(filedes);

    pid_t childID = fork();
    if(childID==-1){
        exit(1);
    }

    if(childID==0){
        close(filedes[1]);
        char buffer[BUF_SIZE];
        int n;

        while((n=read(filedes[0],buffer,BUF_SIZE))>0){
            for(int i=0;i<n;i++){
                buffer[i]=toupper(buffer[i]);
            }
            write(1,buffer,n);
            printf("\nVeuillez entrer une phrase:\n");
        }
        close(filedes[0]);
    }else{
        close(filedes[0]);
        char buffer[BUF_SIZE];
        printf("Veuillez entrer une phrase:\n");
        while(fgets(buffer,BUF_SIZE,stdin)!=NULL){
            printf("En majuscule : \n");
            write(filedes[1],buffer,strlen(buffer));
        }
        close(filedes[1]);
    }
    exit(0);
}