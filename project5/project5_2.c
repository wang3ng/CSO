/**
 * @file project5_2.c
 * @author William Wang (xw2559@nyu.edu)
 * @brief This program would provide a math game for the user.
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int wrongs=0;
pid_t answerPid;
/**
 * @brief Would handle the signal of timeout.
 * 
 */
void handling(){
    printf("Times Up\n");
    wrongs+=1;
    kill(answerPid,SIGKILL);
}
int main(){
    int questions,i,answer,input;    
    scanf("%d",&questions);
    for(i=0;i<questions;i++){
        pid_t timerPid;
        // A timer fork
        timerPid=fork();
        if(timerPid == 0){
            int secs = 0;
            while(secs<5) {
            printf("Times Left:%i\n", 5-secs);
            fflush(0);
            sleep(1);
            secs++;
            printf("\r\b\r");
            }
            pid_t ppid = getppid();
            // Send signal to parent when time runs out.
            kill(ppid,SIGINT);
            exit(0);
        }
        // Fork a answersing process
        answerPid = fork();
        if(answerPid==0){
            srand((unsigned)time(NULL));
            // Generate the numbers
            int a = rand() % 10;
            int b = rand() % 10;
            int c = rand() % 3;
            // Calculate the answer
            if(c==0){
                printf("%d+%d=\n\n",a,b);
                answer = a+b;
            }
            else if(c==1){
                printf("%d-%d=\n\n",a,b);
                answer=a-b;
            }
            else if(c==2){
                printf("%d*%d=\n\n",a,b);
                answer=a*b;
            }
            input=100;
            // Get the input and check it.
            do{
                scanf("%d",&input);
                if(input==answer){
                    // Kill the timer if answer is correct
                    kill(timerPid,SIGKILL);
                    printf("Great Job!\n");
                    exit(0);
                }
                else{
                    printf("Incorrect,Try angain.\n");
                }
            } while(input!=answer);
        }
        else signal(SIGINT,handling);
        // Wait for the fork to end.
        wait(answerPid);
        wait(timerPid);
    } 
    printf("correct:%d\nWrong:%d\n",questions-wrongs,wrongs);   
}