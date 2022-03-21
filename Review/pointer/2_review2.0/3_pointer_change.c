#include <stdio.h> //这个程序内存方面有些问题，不安全，但是为了便于理解，暂时先不做改动

void f(int **q);  //指针的指针

int main (void)
{ 
    int i = 9;
    int *p = &i;   //也可以写成int *p;  p = &i;
    printf("%p\n",p);
    f(&p);

    printf("%p\n",p);
    return 0;
}

void f(int **q)
{
    *q=(int *)0xFFFFFFFF; //这里如果不进行强转，则q是一个十六进制数字
}