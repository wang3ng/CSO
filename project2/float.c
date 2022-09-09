#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"


int is_special ( float f ) {
    if(f!=f ||
        f==INFINITY ||
        f==-INFINITY) return 1;
    return 0;

}


float get_M  ( float f ) {
    if(is_special(f)==1) {
        if(f!=f) return 0.5;
        else return 0.0;
    }
    if(get_E(f)<=-126){
        int i;
        for (i=1;i<=126;i++){
            f=f*2;
        }
        return f*get_s(f);
    }
    while (f*get_s(f)>=2)
    {
        f = f/2;
    }
    while (f*get_s(f)<1)
    {
        f=f*2;
    }
    
    return f*get_s(f); 
}


int get_s ( float f ) {
	if(signbit(f)) return -1;
    else return 1;
}



int get_E ( float f ) {
	if(is_special(f)==1) return 255;
    int i = 0;
    while (f*get_s(f)>=2)
    {
        f = f/2;
        i+=1;
    }
    while (f*get_s(f)<1)
    {
        f=f*2;
        i=i-1;
    }
    if(i<=-126) return -126;
    return i;
}