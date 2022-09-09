#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <sys/wait.h>
#include <stdlib.h> 
#include<signal.h> 
int secs=0;
int resets=0;

int main(int argc, char **argv)
{

 printf("\n");
  while(secs<10) {
     printf("Time:%i\n",secs);
     fflush(0);
     sleep(1);
     secs++;
      printf("\r\b\r");
  }

  return 0;
}
 
