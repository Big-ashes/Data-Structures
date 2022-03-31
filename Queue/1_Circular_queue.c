#include <stdio.h>
#include <malloc.h>

typedef struct Queue
{
    int *pBase; //pBase就是一个数组
    int frout; //头
    int rear; //尾部后一个
} QUEUE;

void init(QUEUE*);
_Bool enter_queue(QUEUE * ,int val); //入队
void traverse_queue(QUEUE *);
_Bool full_queue(QUEUE *);
_Bool out_queue(QUEUE * ,int *pVal); //出队，指针记录值
_Bool empty_queue(QUEUE *pQ);

int main(void)
{
    QUEUE Q;// Q变量中有三个成员
    int val;

    init(&Q);
    enter_queue(&Q,1);
    enter_queue(&Q,2);
    enter_queue(&Q,4);
    enter_queue(&Q,7);
    traverse_queue(&Q);

    if (out_queue(&Q,&val))
    {
        printf("out queue success val = %d\n",val);
    }
    else
    {
        printf("out queue fail \n");
    };

    traverse_queue(&Q);
    return 0;
}

void init(QUEUE *pQ)
{
    pQ->pBase = (int*)malloc(sizeof(int)*6);
    pQ->frout=0;
    pQ->rear=0;
}

_Bool enter_queue(QUEUE * pQ ,int val)
{
    if (full_queue(pQ))
    {
        return 0;
    }
    else
    {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear+1)%6;
        return 1;
    }
}
_Bool full_queue(QUEUE *pQ)
{
    if((pQ->rear+1)%6==pQ->frout)
        return 1;
    else
        return 0;

}

void traverse_queue(QUEUE *pQ)
{
    int i =pQ->frout;
    while(i != pQ->rear)
    {
        printf("%d ",pQ->pBase[i]);
        i = (i+1)%6;
    }
    printf("\n");
    return;
}

_Bool empty_queue(QUEUE *pQ){
    if(pQ->frout ==pQ->rear)
        return 1;
    else
        return 0;
}

_Bool out_queue(QUEUE * pQ, int *pVal)
{
    if(empty_queue(pQ))
        return 0;
    else
        *pVal = pQ->pBase[pQ->frout];
        pQ->frout = (pQ->frout+1) % 6;
        return 1;
}