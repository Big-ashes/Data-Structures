#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[200];
    int age;
}; 

void g2(struct Student *pst);
void g(struct Student st);
void f(struct Student *pst); //前置声明

int main(void)
{
    struct Student st;  
    f(&st);
    g(st); //结构体相互赋值 ,浪费空间，并没有指针来的好，
    g2(&st);
    // printf("%d %s %d\n",st.sid,st.name,st.age);
    return 0;
}

void g(struct Student st)
{
    printf("%d %s %d\n",st.sid,st.name,st.age); //这里最少208个字节
}

void g2(struct Student *pst)
{
    printf("%d %s %d\n",pst->sid,pst->name,pst->age); //这里四个字节
}

void f(struct Student *pst)
{
    (*pst).sid = 99;
    strcpy(pst->name,"Big-ashes");
    pst->age = 99;
}