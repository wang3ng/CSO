/**
 * @file project5_1.c
 * @author William Wang (xw2559u@nyu.edu)
 * @brief  This program would find unique prime numbers using fork and not using fork. It would output the time used for the process. 
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
#include <string.h>

int addUpDigit(int num);

void outPutting(int num);

void outPutting2(int num, int i);

int main(){
    // Creating the timer
    time_t ts,te;
    time(&ts);
    int i,j,sig = 1,x;
    // Finding the numbers.
    for (i=2;i<=100000;i++){
        sig = 1;
        for(j=2;j<i;j++){
            if(i%j==0){
                sig = 0;
                j=i;
            }
        }
        if(sig&&addUpDigit(i)==11) outPutting(i);
    }
    //Timer ends
    time(&te);
    printf("Times for single thread:%.2lf\n",difftime(te,ts));

    //Timer startes
    time(&ts);
    for(i=0;i<10;i++){
        // Create a fork ten times spliting the numbers
        pid_t pid;
        pid = fork();
        if(pid == 0){
            // Find the numbers
            for(j=i*10000+1;j<=(i+1)*10000;j++){
                if(j!=1) {
                    sig = 1;
                    for(x=2;x<j;x++){
                        if(j%x==0){
                            sig=0;
                            x=j;
                        }
                    }
                    if(sig&&addUpDigit(j)==11) outPutting2(j,i);
                }
                
            }
            exit(0);
        }
    }
    // Wait for the childrens to end.
    for(i=0;i<10;i++){
        wait(0);
    }
    // Read the files created by children and output them.
    FILE *outputf = fopen("Project5Output2.text","w");
    for(i=0;i<10;i++){
        char address[20];
        sprintf(address, "%2d.txt", i);
        char ch[10]="";
        FILE *inputf=fopen(address,"r");
        while(fgets(ch,5,inputf)!=NULL) {
            fprintf(outputf,"%s\n",ch);}             
        fclose(inputf);
    }
    fclose(outputf);
    time(&te);
    printf("Times for multi thread:%f\n",difftime(te,ts));
}

/**
 * @brief Add the digits up for a provided integer.
 * 
 * @param num 
 * @return sum of the digit
 */
int addUpDigit(int num){
    int out=0;
    while(num>0){
        out+=num%10;
        num=num/10;
    }
    return out;
}
/**
 * @brief output number to Project5Output.txt
 * 
 * @param num 
 */
void outPutting(int num){
    FILE *outputf=fopen("Project5Output.txt","a");
    fprintf(outputf, "%d\n",num);
    fclose(outputf);
}
/**
 * @brief output number to i.txt
 * 
 * @param num 
 * @param i 
 */
void outPutting2(int num, int i){
    char address[20];
    sprintf(address, "%2d.txt", i);
    FILE *outputf=fopen(address,"a");
    fprintf(outputf, "%d\n",num);
    fclose(outputf); 
}