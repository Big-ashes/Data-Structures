#include <stdio.h>

int main (void)
{
    double * p;
    double x = 66.6;

    p = &x; //x占8个字节，一个字节是8位 ，一个字节是一个地址，

    double arr[3] = {1.1,2.2,3.3};
    double *q;

    q = &arr[0];
    printf("%p\n",q);
    q = &arr[1];
    printf("%p\n",q); //中间的距离相差8字节
    
    return 0;
}