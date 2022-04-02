#include <stdio.h>

//递归实现阶乘
long f(long n)
{
    if (1==n)
        return 1;
    else
        return f(n-1)*n;
}

int main (void)
{
    printf("%ld\n",f(5));
    
    return 0;
}