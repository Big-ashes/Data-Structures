#include <stdio.h>

//快速排序(升序)
//  9,0,8,10,-5,2,13,7
//  |                |
//  \/               \/
//   l               h          第一个元素val=9
// l和h向数组中间移动，[h]找到比(val:9)小的就把值赋给l，[l]找到比(val:9)大的值，再把这个值赋给h，
//直到[l][h]重合，赋值val，然后再依此递归
//先把第一个元素的准确位置找到，分成两半后再递归排序分开的两半（并不是均分）


void Quicksort(int *a, int low, int high);
int FindPos(int *a, int low, int high);

int main(void)
{
    int b[8] = {9, 0, 8, 10, -5, 2, 13, 7};
    Quicksort(b, 0, 7); //把b数组下标1到下标8的数字排序
    for (int i = 0; i < 8; ++i)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}

void Quicksort(int *a, int low, int high) 
{
    int pos;
    if (low < high)
    {
        pos = FindPos(a, low, high);
        Quicksort(a, low, pos - 1);
        Quicksort(a, pos + 1, high);
    }
    // return 0;
}

int FindPos(int *a, int low, int high)
{
    int val = a[low];
    while ((low < high))
    {
        while (low < high && a[high] >= val)
            --high;
        a[low] = a[high];

        while (low < high && a[low] <= val)
            ++low;
        a[high] = a[low];
    } //终止while循环之后，low，high一定是相等的

    a[low] = val;
    return high;//low和high都可以
    
}