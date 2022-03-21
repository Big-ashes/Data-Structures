#include <stdio.h>

void f(int *p); //增加一个前置申明

int main(void)
{
    int i = 10;
    f(&i);
    printf("i = %d\n",i);
    return 0;
}

void f(int * p)
{
    *p = 99;
}