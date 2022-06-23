#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
栈--只有一个top指针
*/

typedef struct Stack{
    int *data;
    int Top , size;
} Sta;

Sta * Init(int n){
    Sta * s = (Sta *)malloc(sizeof(Sta));
    s->data = (int *)malloc(sizeof(int)*n);
    s->size = n;
    s->Top = -1;
    return s;
}

int empty(Sta *s){
    return s->Top == -1;
}

int top(Sta *s){
    if(empty(s)) return 0;
    return s->data[s->Top];
}

int push(Sta *s,int k){
    if(s==NULL) return 0;
    if(s->Top+1 ==s->size) return 0;
    s->Top +=1;
    s->data[s->Top] = k;
    return 1;
}

int pop(Sta *s){
    if(s==NULL) return 0; 
    if(empty(s)) return 0;
    s->Top -=1;
    return 1;
}

void clear(Sta *s){
    if(s==NULL) return;
    free(s->data);
    free(s);
    return;
}

void output(Sta *s){
    printf("stack(%d) = [",s->Top+1);
    for (int i = s->Top; i >= 0; i--)
    {
        printf(" %d",s->data[i]);
    }
    printf("] \n");
    return;
}

int main(){
    srand(time(0));
    #define MAX_OP 20
    Sta *s = Init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++)
    {
        int op = rand() % 2, k=rand() % 100;
        switch (op)
        {
        case 0:{
            printf("push %d to stack = %d \n", k , push(s,k));
        }break;
        case 1:{
            printf("pop %d from stack = %d \n", top(s), pop(s));
        }break;
        }
        output(s);
    }
    
    return 0;
}