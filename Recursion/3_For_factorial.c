#include <stdio.h>
//阶乘

int main(void)
{
    int val;
    int mult=1;
    printf("please type a number: ");
    printf("val = ");
    scanf("%d",&val);

    for (int i = 1; i <=val; ++i)
        mult = mult*i;
    printf("%d factorial is :%d\n",val,mult);
    
    return 0;
}