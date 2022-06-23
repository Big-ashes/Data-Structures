#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ElemType int
/*
线性表--顺序存储--顺序表--动态
测试数据采用了自动化配置
重点还是插入和删除部分
插入时，从后往前遍历，把元素后移
删除时，从前往后遍历，把元素前移
*/
typedef struct Seqlist
{
    ElemType *data;
    int size;
    int len;
} Seq;

Seq *init_seq(int n);    //初始化存储n个元素的动态顺序表
void length_seq(Seq *L); //返回动态顺序表长度
int insert_seq(Seq *L, int i, int k);
void display_seq(Seq *L);
void clear(Seq *L);
int delete_seq(Seq *L, int i);

int main()
{
    srand(time(0));
    Seq *L = init_seq(20);
    int op, ind, val;
    for (int i = 0; i < 20; i++){
        op = rand() % 2;
        ind = rand() % (L->len + 1);
        val = rand() % 100;
        switch (op){
            case 0:{
                printf("insert %d at %d to Seq\n", val, ind);
                insert_seq(L, ind, val);
            }break;
            case 1:{
                printf("delete ele at %d from Seq \n", ind);
                delete_seq(L, ind);
            }break;
        }
        display_seq(L);
    }
    return 0;
}

Seq *init_seq(int n)
{
    Seq *L = (Seq *)malloc(sizeof(Seq));                // malloc顺序表空间
    L->data = (ElemType *)malloc(sizeof(ElemType) * n); // malloc顺序表中的data空间
    L->size = n;
    L->len = 0;
    return L;
}

void length_seq(Seq *L)
{
    printf("%d \n", L->len);
}

int insert_seq(Seq *L, int i, int k)
{
    if (L == NULL)
        return 0;
    if (L->len == L->size)
        return 0;
    if (i < 0 || i > L->len)
        return 0;
    for (int j = L->len; j >= i; j--)
    {
        L->data[j + 1] = L->data[j];
    }
    L->data[i] = k;
    L->len += 1;
}

int delete_seq(Seq *L, int i)
{
    if (L == NULL)
        return 0;
    if (L->len == 0)
        return 0;
    if (i < 0 || i >= L->len)
        return 0;
    for (int j = i; j < L->len; j++)
    {
        L->data[j] = L->data[j+1];
    }
    L->len -= 1;
    return 1;
}

void clear(Seq *L)
{
    if (L == NULL)
        return;
    free(L->data);
    free(L);
    return;
}

void display_seq(Seq *L)
{
    printf("(%d) = [", L->len);
    for (int i = 0; i < L->len; ++i){
        if (i != 0) printf(", ");
        printf("%d", L->data[i]);
    }
    printf("] \n");
    return;
}