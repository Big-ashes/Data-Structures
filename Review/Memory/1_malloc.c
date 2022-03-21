#include <stdio.h>
#include <malloc.h>

int main()
{
    int a[5] = {4, 10, 2, 8, 6}; // 静态数组
    int len;
    printf("please type length: len = ");
    scanf("%d",&len);
    int * pArr = (int*)malloc(sizeof(int) * len); //只返回第一个地址
    // *pArr = 4; //类似于a[0] =4
    // pArr[1] = 10; //类似于a[1] =10
    // printf("%d %d \n",*pArr,pArr[1]);

    for (int i = 0; i < len ; ++i)
        scanf("%d",&pArr[i]);

    for (int i = 0; i < len; ++i)
        printf("%d\n",*(pArr+i));

    free(pArr); // 把pArr所代表的动态分配的20个字节的内存释放

    return 0;
}
