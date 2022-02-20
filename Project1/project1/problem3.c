/**
 * @file problem3.c
 * @author William Wang (xw2559@nyu.ed)
 * @brief This program will devide a number using some binary operation
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
int main(){
    int in,i;
    int a,b;
    // at is a switch to monitor if a or b should take the input
    int at;
    while(1){
        a=0,b=0,at=0;
        scanf("%d",&in);
        // Break the loop if input is 0
        if(in <= 0) break;
        // Breaking apart the input in binary, asigning each ones to a and b alternatively
        for(i=0;i<31;i++){
            if(in & 0b00000000000000000000000000000001 == 1) 
            {at = !at;
            if(at==1) a = a|(1<<i);
            else b = b|(1<<i); }
            in = in>>1;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}