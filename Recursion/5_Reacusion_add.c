#include <stdio.h>
//递归1+...+100
long add(int n)
{
    if (1==n)
        return 1;
    else
        return add(n-1)+n; //直接调用，
}

int main(void)
{
    printf("%ld\n",add(100));
    return 0;
}