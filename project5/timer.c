#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
int secs=0;
void timerEnder(){
    printf("Time Spent=%d",secs);
    return secs;
    exit(0);
}
int main(int argc, char **argv)
{
    printf("a\n");
    sleep(1);
    signal(SIGKILL, timerEnder);
    secs = 0;
    while(1) {   
        fflush(0);        
        sleep(1);
        secs++;      
    } 
    return 0;
}