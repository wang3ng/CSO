#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 
pid_t pid;

int main(int argc, char **argv)
{
  int child_status;
  int thispid;
  int i;
    pid = fork();
   if (pid == 0) {
    pid= execve("ProcessFinal",NULL, NULL);
     }
   int num;
 printf("What is 2 + 2" );
  while (num != 4) {
   scanf("%d", &num); 
   if (num==4) {
           printf("You win                    \n" );    
           kill(pid, SIGKILL);
                  
  } else if (num==-1) {
                kill(pid, SIGKILL);
               printf("%i game over               \n",num);          
               break;
          }  else {
                   printf("%i incorrect - try again ",num);   
                   printf("\r\b\r");
              }
      
   }
   return(0);
   }

  
