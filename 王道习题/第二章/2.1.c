#include <stdio.h>
#include <stdlib.h>

void DelMin(int *arr, int len)
{
    if (!len)
    {
        printf("array is empty");
        return;
    }
    int min = *arr, minPos = 0;
    for (int i = 0; i < len; i++)
    {
        if (min > *(arr + i))
        {
            min = *(arr + i);
            minPos = i;
        }
    }
    *(arr + minPos) = *(arr + len - 1);
    *(arr + len - 1) = NULL;
}

int main(void)
{
    int n; //手动输入数组元素个数
    printf("type Array length :n=");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(n));
    printf("type Array element :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    DelMin(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}