#include <stdio.h>
#include <malloc.h>
//这些 m, q, i p  (局部变量) 都是栈分配的，在栈区，用的时候压栈或者出栈
//这些 malloc后面的(成员变量) 是堆分配
void f(int k)
{
    int m;
    double * q =(double*)malloc(200);
}

int main(void)
{
    int i =10;
    int *p =(int*)malloc(100);

    return0;
}