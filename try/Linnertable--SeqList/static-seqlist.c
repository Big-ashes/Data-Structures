#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define ElemType int
/*
线性表--顺序存储--顺序表--静态
相当于数组，最大的元素数量也已经写死了
实现并不完全，暂时还没有考虑边界条件
主要函数是插入和删除
*/
typedef struct SeqList{
    ElemType data[MAXSIZE];
    int length;   //有效数据的个数
}Seq;

//void init_seq(Seq *s);  //初始化静态顺序表
void Length_seq(Seq *s); //返回静态顺序表长度
void locateelem_seq(Seq *s ,int k);  //查找给定静态顺序表元素 返回下标
void getelem_seq(Seq *s,int k); //按位查找元素，返回元素值
void insert_seq(Seq *s ,int i ,int k); //静态顺序表插入元素
void delete_seq(Seq *s , int i); //删除静态表中的元素
void show_seq(Seq *s); //遍历静态顺序表元素

int main(void){
   
    Seq s ={.data={1,2,3,4,5,6},.length =6};
    // init_seq(&s);
    show_seq(&s);
    Length_seq(&s);
    printf(" \n");
    insert_seq(&s,2,7);  //第二个位置插入7
    show_seq(&s);
    Length_seq(&s);
    printf("\n");
    locateelem_seq(&s,7);  //返回元素7的数组下标
    delete_seq(&s,2);      //删除下标为2的元素
    show_seq(&s);
    Length_seq(&s);
    /* 
       insert_seq(&s,7,9);
       insert_seq(&s,8,0);
       insert_seq(&s,9,10);
       insert_seq(&s,10,11);
       show_seq(&s);
    */
    return 0;
}

void init_seq(Seq *s){
    for (int i = 0; i =6; i++) 
    {
        s->data[i]=i;
        s->length++;
    }      
}

void insert_seq(Seq *s ,int i ,int k){
    for (int j = s->length; j>=i ; j--)
    {
        s->data[j] = s->data[j-1];
    }
    s->data[i-1] = k;
    s->length+=1;
    return ;
}

void locateelem_seq(Seq *s,int k){
    for (int i = 0; i < s->length; i++)
        if (s->data[i]==k)
            printf("%d --- %d \n",k ,i);  
}

void show_seq(Seq *s){
    for (int i = 0; i < s->length; i++)
        printf("%d ",s->data[i]); 
}

void delete_seq(Seq *s , int i){
    for (int j = i; j < s->length; j++)
        s->data[j] = s->data[j+1];  
    s->length--;
}

void Length_seq(Seq *s){
    printf("\n");
    printf("SeqList length is : %d ",s->length);
}