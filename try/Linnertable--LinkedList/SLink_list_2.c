#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
线性表--链式存储--链表--单链表
这个程序中采用两个结构体，分别定义节点和链表属性
*/

typedef struct SLinkNode{
    int data;
    struct SLinkNode * next;
} SNode;


typedef struct SLinkList{
    struct SLinkList * head;    //虚拟头节点
    int length; 
} SList;

SNode * InitLinkNode(int n);
SList * InitLinkList();
void clear_linklist(SList *h);
int insert(SList *h, int i,int k);
int delete(SList *h, int i);
void output(SList *h);

#define OP 30
int main(){
    srand(time(0));
    SList *h = InitLinkList();
    for (int i = 0; i < OP; i++){
        int op = rand() %3;
        int i = rand() % (h->length+1);
        int k = rand() %100;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("insert %d at %d to Linklist = %d\n",
                k , i, insert(h,i,k));    
            }break;
            case 3:{
                printf("delete ele at %d from LinkList =%d\n",
                i, delete(h,i));
            }break;
        }
        output(h);
        printf("\n");
    }
    
    return 0;
}

SNode * InitLinkNode(int n){
    SNode *p = (SNode *)malloc(sizeof(SNode));
    p->data = n;
    p->next = NULL;
    return p;
}

SList * InitLinkList(){
    SList *h = (SList *)malloc(sizeof(SList));
    h->head.next = NULL;
    h->length = 0;
    return h;
}

void clear_linknode(SNode  *node){
    if(node == NULL) return;
    free(node);
    return ;
}

void clear_linklist(SList *h){
    if(h == NULL) return;
    SNode *p = h->head.next, *q;  //指向真正链表的第一个节点，head是一个虚拟头节点
    while(q){
        q = p->next;
        clear_linknode(p);
        p = q;
    }
    free(h);
    return;
}

int insert(SList *h, int i,int k){
    if(h == NULL) return 0;
    if(i < 0 || i>h->length) return 0;
    SNode *p = &(h->head), *node =InitLinkNode(k);
    while(i--){
        p = p->next;
    }
    node->next = p->next;
    p->next =node;
    h->length +=1;
    return 1;
}

int delete(SList *h, int i){
    if(h == NULL) return 0;
    if(i < 0 || i>=h->length) return 0;
    SNode *p = h->head,*q;
    while(i--){
        p = p->next;
    }
    q = p->next->next;
    clear_linknode(p->next);
    p->next = q;
    h->length -=1;
    return 1;
}

void output(SList *h){
    printf("LinkList(%d) :",h->length);
    for (SNode *p = h->head.next; p; p=p->next){
        printf("%d -> ",p->data);
    }
    printf("NULL \n");
    return ;
}