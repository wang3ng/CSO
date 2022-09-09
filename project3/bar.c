/**
 * @brief translated from .o files
 * @file bar.c
 * @author William Wang (xw2559@nyu.ed)
 * @param b 
 * @param a 
 * @return long 
 * 
 */
long bar(long a,long b)
{
    long count = 0;
    long x = a;
    long y = 11*a;
    a = b * 16;
    y = y+2*b-a+1;
    while(x<=b){
        x+=1;
        count+=y;
    }
    return count;
}