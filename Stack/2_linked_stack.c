#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE,*PNODE;

typedef struct Stack
{
    PNODE pTop;   //弹夹顶部
    PNODE pBottom; //弹夹底部的一个元素(头节点)
}STACK,*PSTACK;  //PSTACK 等价于 struct STACK *

void init(PSTACK); //创造空栈
void push(PSTACK pS,int val);//压入元素
void traverse(PSTACK); //遍历元素
_Bool empty(PSTACK pS);
_Bool pop(PSTACK,int *);
void clear(PSTACK);

int main(void)
{
    STACK S; //等价于 struct Stack  S
    int val;

    init(&S);
    push(&S,1);
    push(&S,2);
    push(&S,43);
    push(&S,-7);
    push(&S,666);
    traverse(&S);

    // clear(&S);
    // traverse(&S);  //清空栈

    if(pop(&S,&val))
    {
        printf("pop success! val = %d\n",val);
    }
    else
    {
        printf("pop fail!\n");
    };
    traverse(&S);

    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (NULL == pS->pTop)
    {
        printf("init malloc fail\n");
        exit(-1);
    }
    else
    {
        pS->pBottom=pS->pTop;
        pS->pTop->pNext =NULL; //pS->pBottom->pNext =NULL
    }
}

void push(PSTACK pS ,int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE)); //创造新节点
    pNew->data=val;                            //新节点数据域赋值
    pNew->pNext=pS->pTop;                       //新节点指针域赋值（指向之前的Top）
    pS->pTop = pNew;                            //top指向新元素

    return;
}

void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;
    while(p != pS->pBottom)
    {
        printf("%d ",p->data);
        p= p->pNext;
    }
    printf("\n");
    return;
}

_Bool empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}


//把pS所指的元素出栈，并把元素值存储到pVal形参所指的变量中
_Bool pop(PSTACK pS,int *pVal)
{
    if(empty(pS)) //pS本身存放的就是S的地址
    {
        return 0;
    }
    else
    {
        PNODE r =pS->pTop;
        *pVal = r->data;
        pS->pTop=r->pNext;
        free(r);
        r=NULL;

        return 1;
    }
}

//清空
void clear(PSTACK pS)
{
    if(empty(pS))
    {
        return;
    }
    else{
        PNODE p = pS->pTop;
        PNODE q = p->pNext;

        while (p!=pS->pBottom)
        {
            q=p->pNext;
            free(p);
            p=q;
        }
        pS->pTop = pS->pBottom;
    }
}