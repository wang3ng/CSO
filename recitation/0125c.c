#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i,j,a=0;
    scanf("%d",&j);
    for(i = 1; i<=j;i++){
        a = a+i;
    }
    printf("%d/n",a);
    return 0;
}
