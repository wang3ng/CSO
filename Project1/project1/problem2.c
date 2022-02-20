/**
 * @file problem2.c
 * @author William Wang (xw2559@nyu.ed)
 * @brief this program would output binary translation of color input.
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
int main(){
    int length,i;
    int red, green, blue;
    //Read how many dates need to be scaned
    scanf("%d",&length);
    for (i=0;i<length;i++){
        // Read the inputs
        scanf("%d, %d, %d",&red,&green,&blue);
        // Check if the numbers are inbound and print them in hex.
        if(red<256 && green<256 && blue<256){
            printf("#%02x",red);
            printf("%02x",green);
            printf("%02x\n",blue);
        }
        else{
            printf("INVALID\n");
        }
        
    }
    return 0;
}