#include <stdio.h>
#include <stdlib.h>
/*
线性表--链式存储--链表--单链表
尝试默写
*/
typedef struct SingleLinkList{
    int data;
    struct SingleLinkList *next;
}SList;

SList * Init_List(){
    SList *h = (SList *)malloc(sizeof(SList));
    h->next=NULL;
    return h;
}

void HeadInsert_ele(SList *s,int k){
    if(s==NULL) return;
    SList * p = (SList *)malloc(sizeof(SList));
    p->data = k;
    p->next = s->next;
    s->next = p;
    return ;
}

void delete_ele(SList *s,int i){
    
    return;
}

void display(SList *s){
    SList *p = s;
    while(s){
        printf("%d  ",s->next->data);
        s = s -> next;
    }
    return;
}

int main(){
    SList * H= Init_List();
    HeadInsert_ele(H,3);
    HeadInsert_ele(H,6);
    display(H);
    return 0;
}