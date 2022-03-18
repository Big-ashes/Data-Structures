#include <stdio.h>

void f(int i) //形参
{
    i = 100;
    
}

int main(void)
{
    int i = 9; //实参
    f(i);
    printf("i = %d\n",i);//这里的值是9，实参和形参并不在一个内存中
    return 0;
}
