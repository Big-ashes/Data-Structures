#include <stdio.h>
#include <malloc.h> //包含了malloc函数
#include <stdlib.h> //包含了exit函数

//定义了一个数据类型，该数据类型叫做struct Arr，该类型中有三个成员
struct Arr
{
    int *pBase; //数组第一个元素的地址
    int len;    //数组能容纳的最大元素的个数
    int cnt;    //当前数组有效元素的个数
    // int increment; //自动增长因子  内存的扩充是一个不太好办的事情  allocate（）
};

void init_arr(struct Arr *Arr, int length);
_Bool append_arr(struct Arr *pArr, int val);          //追加元素 _Bool返回真假值
_Bool insert_arr(struct Arr *pArr, int pos, int val); // pos位置的设定
_Bool delete_arr(struct Arr *pArr, int pos, int *pVal);
_Bool get(struct Arr *pArr,int pos,int *pVal);
_Bool is_empty(struct Arr *pArr);
_Bool is_full(struct Arr *pArr);
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void reverse_arr(struct Arr *pArr); // 倒置数组

int main(void)
{

    int val;

    init_arr(&arr, 6);
    show_arr(&arr);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    show_arr(&arr);
    insert_arr(&arr, 5, 666);
    show_arr(&arr);
    // delete_arr(&arr,4,&val);
    if (delete_arr(&arr, 4, &val))
    {
        printf("delete success %d\n", val);
    }
    else
    {
        printf("fail");
    }
    show_arr(&arr);
    reverse_arr(&arr);
    get(&arr,2,&val);
    show_arr(&arr);
    sort_arr(&arr);
    show_arr(&arr);
    // printf("%d\n",arr.len);
    return 0;
}

void init_arr(struct Arr *pArr, int length)
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if (NULL == pArr->pBase)
    {
        printf("malloc fail\n");
        exit(-1); //终止整个程序
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
}

_Bool is_empty(struct Arr *pArr)
{
    if (pArr->cnt == 0)
        return 1; // return true
    else
        return 0; // return false
}

_Bool is_full(struct Arr *pArr)
{
    if (pArr->cnt == pArr->len)
        return 1;
    else
        return 0;
}

void show_arr(struct Arr *pArr)
{
    if (is_empty(pArr))
    {
        printf("Array is empty\n");
    }
    else
    {
        for (int i = 0; i < pArr->cnt; i++)
            printf("%d  ", pArr->pBase[i]); // int *
        printf("\n");
    }
}

_Bool append_arr(struct Arr *pArr, int val)
{
    //满时返回flase
    if (is_full(pArr))
        return 0;
    //不满时追加
    pArr->pBase[pArr->cnt] = val;
    (pArr->cnt)++;
    return 1;
}

_Bool insert_arr(struct Arr *pArr, int pos, int val)
{
    if (is_full(pArr))
        return 0;
    if (pos < 1 || pos > pArr->cnt + 1)
        return 0;
    for (int i = pArr->cnt - 1; i >= pos - 1; --i)
    {
        pArr->pBase[i + 1] = pArr->pBase[i];
    }
    pArr->pBase[pos - 1] = val;
    pArr->cnt++;
    return 1;
}

_Bool delete_arr(struct Arr *pArr, int pos, int *pVal)
{
    if (is_empty(pArr))
        return 0;
    if (pos < 1 || pos > pArr->cnt)
        return 0;
    *pVal = pArr->pBase[pos - 1];
    for (int i = pos; i < pArr->cnt; ++i)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return 1;
}

_Bool get(struct Arr *pArr,int pos,int *pVal)
{
    int val;
    if(pos<1 || pos>=pArr->cnt)
        return 0;
    *pVal = pArr->pBase[pos-1];
    printf(" %d %d\n",pos,val);
}

void reverse_arr(struct Arr *pArr)
{
    int i = 0;
    int j = pArr->cnt - 1;
    int t;
    while (i < j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }return;
}

void sort_arr(struct Arr *pArr)
{
    int i, j, t;
    for (i = 0; i < pArr->cnt; ++i)
    {
        for (j = i + 1; j < pArr->cnt; ++j)
        {
            t = pArr->pBase[i];
            pArr->pBase[i] = pArr->pBase[j];
            pArr->pBase[j] = t;
        }
    }
}