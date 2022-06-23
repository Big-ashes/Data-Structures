#include <stdio.h>
#include <stdlib.h>

/*
线性表--链式存储--链表--单链表
还有一种写法是两个结构体，分别定义节点和链表属性
*/

typedef struct SLink_List
{
    int data;
    struct SLink_List *next;
} SNode; // SNode 趋向于描述单个节点   *SList 趋向于描述整个链表

SNode *Init_seq();
void Headinsert(SNode *H, int k);
void Tailinsert(SNode *H, int k);
void Display(SNode *H);
void Length(SNode *H);
void Delete_ele_i(SNode *H , int i);
void Delete_ele_v(SNode *H , int k);

int main(){
    SNode * H = Init_seq();
    Headinsert(H , 6);
    Headinsert(H , 7);
    Headinsert(H , 0);
    Headinsert(H , 1);
    Tailinsert(H , 45);
    Delete_ele_i(H , 0);
    Display(H);
    Display(H);
    Headinsert(H , 99);
    Display(H);
    printf("-----");
    return 0;
}

SNode *Init_seq(){
    SNode *H = (SNode *)malloc(sizeof(SNode));
    // H->data=0;
    H->next = NULL;
    return H;
}

void Display(SNode *H){
    SNode * p = H;
    while (p != NULL){
        printf("%d  ", p->next->data);
        p = p -> next;
    }
    printf("\n ");
    return ;
}

void Length(SNode *H){
    int len=0;
    while (H->next){
        len++;
    }
    printf("length is %d ",len);
}

void Headinsert(SNode *H, int k){           //头插法
    SNode * node = (SNode *)malloc(sizeof(SNode));
    node->data=k;
    node->next=H->next;
    H->next = node;
    // H->data++;
}

void Tailinsert(SNode *H , int k){          //尾插法
    SNode * p = H;
    SNode * tail = (SNode *)malloc(sizeof(SNode));
    tail->data = k;
    tail->next =NULL;
    while(p->next){                         //while (H->next != NULL)
        p = p->next;
    }
    p->next = tail;
}

void Delete_ele_i(SNode *H , int i){
    SNode * p = H;
    SNode * q = H -> next;
    for (int j = 0; j < i; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}

void Delete_ele_v(SNode *H , int k){
    SNode * p = H->next;
    SNode * q = p->next;
    while(q){
        if(q -> data == k )
            p -> next = q -> next;
            free(q);
            break;
    }
   
}