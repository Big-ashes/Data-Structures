#include <stdio.h>
#include <malloc.h>

// 链式二叉树 
typedef struct BTNode
{
    int data;
    struct BTNode *pLchild;
    struct BTNode *pRchild;
} BTNode; //左右孩子和数据域

BTNode *CreateBTree(void);//需要动态分配的空间，静态分配的会随着函数结束而回收
void PreTraverseBTree(BTNode *pT);
void InTraverseBTree(BTNode *pT);
void PostTraverseBTree(BTNode *pT);

int main(void)
{
    BTNode * pT = CreateBTree();
    printf("PreTraverse: ");
    PreTraverseBTree(pT); //先序
    printf("\n");
    printf("InTraverse: ");
    InTraverseBTree(pT); //中序
    printf("\n");
    printf("PostTraverse: ");
    PostTraverseBTree(pT); //后序
    printf("\n");

    return 0;
}

void PreTraverseBTree(BTNode *pT)//根左右--递归
{
    if(pT != NULL) //递归条件
    {
        printf("%c  ",pT->data);
        if(NULL != pT->pLchild)
        {
            PreTraverseBTree(pT->pLchild);
        }
        if (NULL != pT->pRchild)
        {
            PreTraverseBTree(pT->pRchild);
        }
    }
}

void InTraverseBTree(BTNode *pT)//左根右--递归
{
    if(pT != NULL) //递归条件
    {
        if(NULL != pT->pLchild)
        {
            InTraverseBTree(pT->pLchild);
        }
        printf("%c  ",pT->data);
        if (NULL != pT->pRchild)
        {
            InTraverseBTree(pT->pRchild);
        }
    }
}

void PostTraverseBTree(BTNode *pT)//左右根--递归
{
    if(pT != NULL) //递归条件
    {
        if(NULL != pT->pLchild)
        {
            PostTraverseBTree(pT->pLchild);
        }
        if (NULL != pT->pRchild)
        {
            PostTraverseBTree(pT->pRchild);
        }
        printf("%c  ",pT->data);
    }
}

BTNode * CreateBTree(void)
{
    BTNode * pA = (BTNode*)malloc(sizeof(BTNode));
    BTNode * pB = (BTNode*)malloc(sizeof(BTNode));
    BTNode * pC = (BTNode*)malloc(sizeof(BTNode));
    BTNode * pD = (BTNode*)malloc(sizeof(BTNode));
    BTNode * pE = (BTNode*)malloc(sizeof(BTNode));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';

    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild = NULL;
    pD->pLchild = NULL;
    pD->pRchild = pE;
    pE->pLchild = pE->pRchild = NULL;

    return pA;
}