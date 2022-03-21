#include <stdio.h>

int main(void)
{
    int * p; //p是一个指针变量名称，int*表示p只能存储int类型的地址
    printf("%p\n",p);
    printf("%p\n",*p);
    printf("%p\n",&p);
    int i =10; //假设地址2000H
    int j;

    p = &i; //&是c语言中的取址运算符， p就是i的地址2000H，*p就是i变量  *p = i;
    // j = *p; //j就等价于i
    // *p = i;
    // printf("%d \n",j);

    printf("i = %d ,j= %d *p = %d\n" ,i,j,*p);
    return 0;
} 