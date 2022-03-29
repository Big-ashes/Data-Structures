#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    int data;           //数据域
    struct Node *pNext; //指针域
} NODE, *PNODE;         // NODE 等价于struct Node , PNODE等价于struct Node *

//函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead); //遍历链表
bool is_empty(PNODE pHead);
int legth_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE pHead, int pos, int *pVal);
void sort_list(PNODE pHead);

int main(void)
{
    //跨函数使用分配过的内存
    PNODE pHead = NULL; //等价于 struct Node *pHead = NULL
    int val; //删除后保存的值

    pHead = create_list(); //创建一个非循环单链表
    traverse_list(pHead);  //遍历链表
    // if(is_empty(pHead))
    //     printf("linked List is empty");
    // return 0;
    // int len = legth_list(pHead);
    // printf("legth is %d \n", len);

    sort_list(pHead);
    traverse_list(pHead);

    // insert_list(pHead,3,33);
    // traverse_list(pHead);//判断可以再写if

    if(delete_list(pHead,1,&val))
    {
        printf("delete success : %d\n",val);
    }
    else
    {
        printf("delete fail\n");
    }
    traverse_list(pHead);
}   

PNODE create_list(void)
{
    int len; // 有效节点的个数
    int val; //临时存放用户输入节点的值

    //分配了一个不存放有效数据的头节点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
    {
        printf("malloc phead fail\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("type linkednode num:len = ");
    scanf("%d", &len);

    for (int i = 0; i < len; ++i)
    {
        printf("type node %d val:", i + 1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("malloc pnew fail\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        printf("%d  ", p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}

bool is_empty(PNODE pHead)
{
    if (NULL == pHead->pNext)
        return 1;
    else
        return 0;
}

int legth_list(PNODE pHead)
{
    int len;
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        ++len;
        p = p->pNext;
    }
    return len;
}

void sort_list(PNODE pHead)
{
    int i,j,t;
    int len = legth_list(pHead);
    PNODE p,q;

    for (i = 0, p=pHead->pNext; i < len - 1; ++i, p = p->pNext)
    {
        for (j = i + 1, q = p->pNext; j < len; ++j, q = q->pNext)
        {
            if (p->data > q->data)
            {                      //类似于数组中的：a[i] >a[j]
                t = p->data;       //类似于数组中的：t = a[i];
                p->data = q->data; //类似于数组中的a[i] = a[j];
                q->data = t;       //类似于数组中的[j] = t;
            }
        }
    }
    return;
}

//在pHead所指链表的第pos个节点前面插入一个新的节点，值是val
bool insert_list(PNODE pHead, int pos, int val) //pos不可以超过当前len+1
{
    int i =0;
    PNODE p =pHead;
    while (NULL!=p && i<pos-1) //与  这一步主要是吧p移动到pos-1的位置for也可以
    {
        p = p->pNext;
        ++i;
    }
    if (i>pos-1 || NULL ==p) //或
        return 0;

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("insert malloc fail!\n");
        exit(-1);
    }
    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext=pNew;
    pNew->pNext=q;

    return 1;
    
}

bool delete_list(PNODE pHead, int pos, int *pVal)
{
    int i =0;
    PNODE p =pHead;
    while (NULL!=p->pNext && i<pos-1) //与  
    {
        p = p->pNext;
        ++i;
    }
    if (i>pos-1 || NULL ==p->pNext) //或
        return 0;

    PNODE q= p->pNext;
    *pVal = q->data;

    //删除p节点后的节点
    p->pNext =p->pNext->pNext;
    free(q);
    q=NULL;

    return 1;
}