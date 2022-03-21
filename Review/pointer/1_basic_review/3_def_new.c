#include <stdio.h>

void f(int *p) //不是定义了一个叫*p的形参，而是一个类型是int *的指针变量形参p
{
    *p = 100;
    
}

int main(void)
{
    int i = 9; //实参
    f(&i);
    printf("i = %d\n",i);//这里的值是100,
    return 0;
}
