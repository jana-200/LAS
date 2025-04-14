#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
 // dans la pipe , 0 pr lire, 1 pr écrire.
int main(){ 
    int pipeParentFils[2];
    int pipeFilsParent[2];
    pipe(pipeParentFils);
    pipe(pipeFilsParent);

    pid_t childID = fork();
    if(childID==-1){
        exit(1);
    }
    
    if(childID==0){
        close(pipeParentFils[1]);
        close(pipeFilsParent[0]);

        int n=0;
        int somme=0;
        int count=0;
        double moyenne=0.0;
        while(read(pipeParentFils[0],&n,sizeof(int))>0){
            somme+=n;
            count++;
            write(pipeFilsParent[1],&somme,sizeof(int));
        }
        if(count>0){ 
            moyenne = (double)somme/count;
        }
        write(pipeFilsParent[1],&moyenne,sizeof(double));
        
        close(pipeParentFils[0]);
        close(pipeFilsParent[1]);
        exit(0);
    }else{
        close(pipeParentFils[0]);
        close(pipeFilsParent[1]);
        int n;
        int somme;
        double moyenne;
        printf("Entrez des entiers (Ctrl+D pour finir) :\n");
        while(scanf("%d",&n)==1){
            write(pipeParentFils[1],&n,sizeof(int));
            read(pipeFilsParent[0],&somme,sizeof(int));
            printf("Somme : %d\n",somme);
        }
    
        close(pipeParentFils[1]);

        read(pipeFilsParent[0],&moyenne,sizeof(double));
        printf("Moyenne des valeurs : %.2f\n", moyenne);
        close(pipeFilsParent[0]);


    }
    exit(0);
} 
