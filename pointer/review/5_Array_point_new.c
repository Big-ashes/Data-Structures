#include <stdio.h>

void Show_Array(int * p ,int len )
{
    int i = 0;

    // p[0] = -1;  //等价于 *(a+0) 也就是*a
    for ( i = 0; i < len; ++i)
    {
        printf("%d\n",p[i]);
    }
    
}

int main(void)
{
    int a[5] = {7,2,5,88,6};  
    Show_Array(a,5); // a是第一个元素的地址，5是长度  a等价于&a[0], &a[0] 本身就是int * 类型
    // printf("%d\n",a[0]);
    return 0;
}