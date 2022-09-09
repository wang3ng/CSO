/**
 * @brief translated from .o files
 * @file foo.c
 * @author William Wang (xw2559@nyu.ed)
 * @param b 
 * @param a 
 * @return long 
 * 
 */
long foo(long b,long a)
{
    long x = 52*b;
    long y = 93*a;
    x = x+y;
    a = a-b;
    y = 95*a;
    return x+y;
}