/**
 * @file problem1.c
 * @author William Wang (xw2559@nyu.ed)
 * @brief This program would return a binary translated from a date
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
/**
 * @brief This function would output interger with a providing character
 * 
 * @param input a character of number from 0~9 
 * @return int a one degit interger
 */
int con(char input){return (int)(input)-48;}
/**
 * @brief This function would check if the input is valid
 * 
 * @param input1 month and date
 * @param input2 hour, minutes, and seconds
 * @return int 0 if the input is valid, 1 if the input is invalid
 */
int check(char input1[], char input2[]){
    //Check if numbers are out of range
    if(con(input1[0]) < 2
        && (con(input1[0]) < 1 || con(input1[1]) < 3) 
        && con(input1[3]) < 4 
        && con(input2[0]) < 3
        && con(input2[3]) < 6
        && con(input2[6]) < 6) return 0;
    else{
        // Print the output as invalid
        printf("INVALID\n");
        return 1;
    }
}

int main(){
    int Length,i;
    char input1[5],input2[8];
    int output;
    //Read how many dates need to be scaned
    scanf("%d",&Length);
    for(i=0;i<Length;i++){
        // Read the inputs
        scanf("%s %s",&input1,&input2);  
        if(check(input1,input2)) continue;
        // Shifting the data
        output = con(input1[0]) << 30 
        | con(input1[1]) << 26 
        | con(input1[3]) << 24 
        | con(input1[4]) << 20
        | con(input2[0]) << 18
        | con(input2[1]) << 14
        | con(input2[3]) << 11
        | con(input2[4]) << 7
        | con(input2[6]) << 4
        | con(input2[7]);
        printf("%d\n", output);
    }
    return 0;
}
