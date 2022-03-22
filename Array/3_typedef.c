#include <stdio.h>

typedef struct Student
{
    int sid;
    char name[100];
    char sex;
}* PST,ST; //其含义是： ST代表了struct Student,  PST代表了struct Student *

int main(void)
{
    ST st; //struct Student st;
    PST ps = &st; //struct Student * ps = &st;
    ps->sid=99;
    printf("%d\n",ps->sid);

    return 0;
}