#include <stdio.h>

int main(void)
{
    int a[5] = {7,2,5,88,6};  //一维数组名是一个指针常量，存放的是一维数组第一个元素的地址
    printf("%p\n",a);
    printf("%p\n",*a);
    printf("%p\n",*a+3);   // *a+3  等价于  a[0]+3= 7+3
    //这里数字增加1时一定指向下一个元素，其内部原理是：[a地址+3*a所占字节数]
    printf("%p\n",*(a+3));   // *(a+3)  等价于  a+3= a后面的第三个地址 *(a+3) 表示顺序存储下数组a的第三个元素88
    printf("%p\n",a[3]);
    printf("%p\n",3[a]);
    return 0;
}