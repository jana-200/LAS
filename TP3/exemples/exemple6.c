/* Exemple d'utilisation d'un pipe pour la communication d'un processus fils
   vers son père */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils_v2.h"

int main(int argc, char **argv)
{
  // 1/ Création du pipe
  int pipefd[2];
  int ret = pipe(pipefd);
  checkNeg(ret, "pipe error");

  // 2/ Création de l'enfant
  int childId = sfork();

  // PARENT
  if (childId > 0)
  {
    // 3/ Clôture du descripteur pour la lecture sur le pipe
    ret = close(pipefd[0]);
    checkNeg(ret, "close error");

    // 4/ On écrit un entier pour le fils
    int intVal = 7;
    int nbChar = write(pipefd[1], &intVal, sizeof(int));
    checkCond(nbChar != sizeof(int), "write error");

    // 5/ On clôture le côté écriture du pipe
    ret = close(pipefd[1]);
    checkNeg(ret, "close error");
  }
  // FILS
  else
  {
    // 3/ Clôture du descripteur d'écriture sur le pipe
    ret = close(pipefd[1]);
    checkNeg(ret, "close error");

    // 4/ On attend un entier de la part du père
    int intVal;
    int nbChar = read(pipefd[0], &intVal, sizeof(int));
    checkCond(nbChar != sizeof(int), "read error");

    printf("entier envoye par mon pere: %i\n", intVal);

    // 5/ On clôture le côté lecture du pipe
    ret = close(pipefd[0]);
    checkNeg(ret, "close error");
  }
}
